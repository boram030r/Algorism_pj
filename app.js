const express = require("express");
const app = express();
const bodyParser = require("body-parser");
const session = require("express-session");
const FileStore = require("session-file-store")(session);
const mysql = require("mysql");
const path = require("path");
const multer = require("multer");
const moment = require("moment");
const fs = require('fs');
const port = 3000;

// sharedDiaries.json 파일의 경로를 정의
const sharedDiariesFile = path.join(__dirname, 'sharedDiaries.json');

app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, "public")));
app.use(express.static(path.join(__dirname, "views")));

const connection = mysql.createConnection({
    host: "203.234.62.118",
    user: "travel",
    password: "Qkfwkrnrxla123!",
    database: "travel",
    dateStrings: "date"
});

connection.connect((err) => {
    if (err) {
        return console.error("Error connecting to MySQL: " + err.message);
    }
    console.log("Connected to the MySQL server.");
});

// 공유된 일기 목록 불러오기
function loadSharedDiaries() {
    try {
        const data = fs.readFileSync(sharedDiariesFile, 'utf8');
        return JSON.parse(data);
    } catch (error) {
        if (error.code === 'ENOENT') {
            // 파일이 없을 경우, 빈 배열을 반환하고 파일을 생성합니다.
            console.log('sharedDiaries.json 파일이 없어서 새로 생성합니다.');
            saveSharedDiaries([]);
            return [];
        } else {
            console.error("Could not read shared diaries from file:", error);
            return []; // 파일을 읽을 수 없는 경우 빈 배열 반환
        }
    }
}

// 공유된 일기 목록 저장하기
function saveSharedDiaries(sharedDiaries) {
    try {
        fs.writeFileSync(sharedDiariesFile, JSON.stringify(sharedDiaries, null, 2), 'utf8');
    } catch (error) {
        console.error("Could not save shared diaries to file:", error);
    }
}

// 서버 시작 시 공유된 일기 목록을 불러옵니다
let sharedDiaries = loadSharedDiaries();

app.use(
    session({
        secret: "secret key",
        resave: false,
        saveUninitialized: true,
        cookie: {
            maxAge: 24 * 60 * 60 * 1000,
            httpOnly: false,
            secure: false,
        },
        store: new FileStore({
            path: path.join(__dirname, 'sessions') // 세션 파일을 저장할 디렉터리 경로 설정
        })
    })
);

app.get("/", (req, res) => {
    // 공유된 일기 ID가 저장된 배열을 사용
    const sql = "SELECT diary_id, user_id, photo_url FROM diary WHERE diary_id IN (?) ORDER BY created_at DESC LIMIT 10";
    connection.query(sql, [sharedDiaries.length > 0 ? sharedDiaries : [0]], (err, results) => {
        if (err) {
            console.error("Error fetching shared diaries: " + err.message);
            return res.status(500).send("Error fetching shared diaries");
        }
        res.render("main", { session: req.session, sharedDiaries: results });
    });
});

app.get("/retouch", (req, res) => {
    res.sendFile(path.join(__dirname, "views", "retouch.html"));
});

const storage = multer.diskStorage({
    destination: function (req, file, cb) {
        cb(null, "uploads/");
    },
    filename: function (req, file, cb) {
        cb(null, Date.now() + "-" + file.originalname);
    },
});

const upload = multer({ storage: storage });

app.post('/share-diary', (req, res) => {
    const { diary_id } = req.body;
    if (!diary_id) {
        return res.status(400).send('Diary ID is required.');
    }
    if (!sharedDiaries.includes(diary_id)) {
        sharedDiaries.push(diary_id);
        saveSharedDiaries(sharedDiaries); // 변경사항을 파일에 저장
    }
    res.status(200).send('Diary has been successfully shared!');
});

app.get("/signup", (req, res) => {
    res.sendFile(path.join(__dirname, "views", "signup.html"));
});

app.get("/mypage", (req, res) => {
    res.sendFile(path.join(__dirname, "views", "mypage.html"));
});

app.post("/signup", (req, res) => {
    const data = {
        ID: req.body.id,
        USERNAME: req.body.username,
        PASSWORD: req.body.password,
        EMAIL: req.body.email,
    };

    connection.query("SELECT * FROM users WHERE ID = ?", [data.ID], (err, results) => {
        if (err) {
            return res.status(500).send("사용자 ID를 확인하는 도중 오류 발생: " + err.message);
        }
        if (results.length > 0) {
            return res.status(400).send("이미 존재하는 ID입니다. 다른 ID를 선택해 주세요.");
        } else {
            const sql = "INSERT INTO users (ID, USERNAME, PASSWORD, EMAIL) VALUES (?, ?, ?, ?)";
            connection.query(sql, [data.ID, data.USERNAME, data.PASSWORD, data.EMAIL], (error, results) => {
                if (error) {
                    return res.status(500).send("회원가입 중 오류 발생: " + error.message);
                }
                res.send("회원가입 완료!");
            });
        }
    });
});

app.get("/login", (req, res) => {
    res.sendFile(path.join(__dirname, "views", "login.html"));
});

app.post("/login", (req, res) => {
    const { id, password } = req.body;

    if (id && password) {
        connection.query("SELECT * FROM users WHERE ID = ? AND PASSWORD = ?", [id, password], (err, results) => {
            if (err) {
                return res.status(500).send("로그인 처리 중 오류 발생: " + err.message);
            }
            if (results.length > 0) {
                req.session.is_logined = true;
                req.session.user_id = req.body.id;
                req.session.username = results[0].USERNAME;
                req.session.save(function () {
                    res.redirect(`/`);
                });
            } else {
                res.send(`<script type="text/javascript">alert("로그인 정보가 일치하지 않습니다."); document.location.href="/login";</script>`);
            }
        });
    } else {
        res.send(`<script type="text/javascript">alert("아이디와 비밀번호를 입력하세요!"); document.location.href="/login";</script>`);
    }
});

app.get("/logout", (req, res) => {
    req.session.destroy(function (err) {
        res.redirect("/");
    });
});

app.get("/diary", (req, res) => {
    res.sendFile(path.join(__dirname, "views", "diary.html"));
});

app.post("/upload-diary", upload.single("photo"), (req, res) => {
    var today = new Date();
    const data = {
        user_id: req.session.user_id,
        title: req.body.title,
        content: req.body.content,
        photo_url: "/uploads/" + req.file.filename,
        created_at: moment(today).format("YYYY-MM-DD HH:mm:ss"),
    };
    const sql = "INSERT INTO diary (user_id, title, content, photo_url, created_at) VALUES (?, ?, ?, ?, ?)";
    connection.query(sql, [data.user_id, data.title, data.content, data.photo_url, data.created_at], (error, results) => {
        if (error) {
            return res.status(500).send("업로드 중 오류 발생: " + error.message);
        }
        res.redirect('/diary-list');
    });
});

app.get("/wishlist", (req, res) => {
    res.sendFile(path.join(__dirname, "views", "wishlist.html"));
});

app.get("/tour", (req, res) => {
    const sql = "SELECT id, subject, image FROM course LIMIT 10";
    connection.query(sql, (err, results) => {
        if (err) {
            console.error("Error fetching courses: " + err.message);
            return res.status(500).send("Error fetching courses");
        }
        res.render("tour", { courses: results });
    });
});

app.get("/api/more-courses", (req, res) => {
    const offset = parseInt(req.query.offset) || 0;
    const sql = "SELECT id, subject, image FROM course LIMIT 10 OFFSET ?";
    connection.query(sql, [offset], (err, results) => {
        if (err) {
            console.error("Error fetching more courses: " + err.message);
            return res.status(500).send("Error fetching more courses");
        }
        res.json(results);
    });
});

app.get("/tour/:id", (req, res) => {
    const tourId = req.params.id;
    const sql = "SELECT * FROM course WHERE id = ?";
    connection.query(sql, [tourId], (err, results) => {
        if (err) {
            console.error("Error fetching tour details: " + err.message);
            return res.status(500).send("Error fetching tour details");
        }
        if (results.length === 0) {
            return res.status(404).send("Tour not found");
        }
        res.render("tour-details", { course: results[0] });
    });
});

app.get("/course", (req, res) => {
    let page = parseInt(req.query.page) || 1;
    let offset = (page - 1) * 10;

    const sql = 'SELECT num, POI_NM, CL_NM, CONCAT(CTPRVN_NM, " ", SIGNGU_NM) AS 지역 FROM tour LIMIT 10 OFFSET ?';
    connection.query(sql, [offset], (err, results) => {
        if (err) {
            console.error("Error fetching tour data: " + err.message);
            return res.status(500).send("Error fetching tour data");
        }

        connection.query("SELECT COUNT(*) AS count FROM tour", (countErr, countResults) => {
            if (countErr) {
                console.error("Error fetching tour count: " + countErr.message);
                return res.status(500).send("Error fetching tour count");
            }

            let totalRecords = countResults[0].count;
            let totalPages = Math.ceil(totalRecords / 10);

            res.render("course", {
                tours: results,
                currentPage: page,
                totalPages: totalPages,
            });
        });
    });
});

app.get("/course/:num", (req, res) => {
    const tourNum = req.params.num;
    const sql = "SELECT * FROM tour WHERE num = ?";
    connection.query(sql, [tourNum], (err, result) => {
        if (err) {
            console.error("Error fetching tour details: " + err.message);
            return res.status(500).send("Error fetching tour details");
        }
        if (result.length === 0) {
            return res.status(404).send("Tour not found");
        }
        res.render("course-details", { tour: result[0] });
    });
});

app.get("/festival", (req, res) => {
    let page = parseInt(req.query.page) || 1;
    let offset = (page - 1) * 10;

    const sql = 'SELECT ID, FCLTY_NM, CONCAT(CTPRVN_NM, " ", SIGNGU_NM) AS 지역, OPMTN_PLACE_NM, FSTVL_BEGIN_DE, FSTVL_END_DE FROM festival LIMIT 10 OFFSET ?';
    connection.query(sql, [offset], (err, results) => {
        if (err) {
            console.error("Error fetching festival data: " + err.message);
            return res.status(500).send("Error fetching festival data");
        }

        connection.query("SELECT COUNT(*) AS count FROM festival", (countErr, countResults) => {
            if (countErr) {
                console.error("Error fetching festival count: " + countErr.message);
                return res.status(500).send("Error fetching festival count");
            }

            let totalRecords = countResults[0].count;
            let totalPages = Math.ceil(totalRecords / 10);

            res.render("festival", {
                festivals: results,
                currentPage: page,
                totalPages: totalPages,
            });
        });
    });
});

app.get("/festival/:id", (req, res) => {
    const festivalId = req.params.id;
    const sql = "SELECT * FROM festival WHERE ID = ?";
    connection.query(sql, [festivalId], (err, result) => {
        if (err) {
            console.error("Error fetching festival details: " + err.message);
            return res.status(500).send("Error fetching festival details");
        }
        if (result.length === 0) {
            return res.status(404).send("Festival not found");
        }
        res.render("festival-details", { festival: result[0] });
    });
});

app.get("/diary-list", (req, res) => {
    const sql = "SELECT diary_id, title, photo_url FROM diary where user_id = ? LIMIT 10";
    connection.query(sql, [req.session.user_id], (err, results) => {
        if (err) {
            console.error("Error fetching courses: " + err.message);
            return res.status(500).send("Error fetching courses");
        }
        res.render("diary-list", { list: results, id: req.session.user_id });
    });
});

app.get("/diary-list/:id", (req, res) => {
    const diaryId = req.params.id;
    const sql = "SELECT * FROM diary WHERE diary_id = ?";
    connection.query(sql, [diaryId], (err, results) => {
        if (err) {
            console.error("Error fetching tour details: " + err.message);
            return res.status(500).send("Error fetching tour details");
        }
        if (results.length === 0) {
            return res.status(404).send("Tour not found");
        }
        res.render("diary-details", { list: results[0] });
    });
});

app.get('/shared-diaries', (req, res) => {
    const sql = `SELECT diary_id, user_id, photo_url FROM diary ORDER BY created_at DESC LIMIT 10`;
    connection.query(sql, (err, results) => {
        if (err) {
            console.error('Error fetching shared diaries:', err);
            return res.status(500).send('공유된 다이어리 가져오는 중 오류가 발생했습니다.');
        }
        res.json(results);
    });
});

app.post('/share-diary', (req, res) => {
    const { diary_id } = req.body;
    if (!diary_id) {
        return res.status(400).send('다이어리 ID가 필요합니다.');
    }

    const sql = `UPDATE diary SET photo_url = photo_url WHERE diary_id = ?`;
    connection.query(sql, [diary_id], (err, result) => {
        if (err) {
            console.error('Error sharing diary:', err);
            return res.status(500).send('다이어리 공유 중 오류가 발생했습니다.');
        }
        if (!sharedDiaries.includes(diary_id)) {
            sharedDiaries.push(diary_id);
            saveSharedDiaries(sharedDiaries); // 변경사항을 파일에 저장
        }
        res.status(200).send('다이어리가 성공적으로 공유되었습니다!');
    });
});

let comments = {};

// 댓글 저장 함수
function saveComment(diaryId, userId, content) {
    if (!comments[diaryId]) {
        comments[diaryId] = [];
    }
    comments[diaryId].push({ userId: userId, content: content, timestamp: moment().format("YYYY-MM-DD HH:mm:ss") });
    saveCommentsToFile(); // 변경사항을 파일에 저장
}

// 댓글 불러오기 함수
function getComments(diaryId) {
    return comments[diaryId] || [];
}

// 서버 시작 시 댓글 파일을 불러옵니다
function loadCommentsFromFile() {
    try {
        const data = fs.readFileSync('comments.json', 'utf8');
        comments = JSON.parse(data);
    } catch (error) {
        if (error.code === 'ENOENT') {
            // 파일이 없을 경우, 빈 객체로 초기화합니다.
            comments = {};
        } else {
            console.error("Could not read comments from file:", error);
        }
    }
}

// 댓글 파일 저장하기
function saveCommentsToFile() {
    try {
        fs.writeFileSync('comments.json', JSON.stringify(comments, null, 2), 'utf8');
    } catch (error) {
        console.error("Could not save comments to file:", error);
    }
}

// 서버 시작 시 댓글 파일을 불러옵니다
loadCommentsFromFile();

// 댓글 저장 엔드포인트
app.post('/submit-comment', (req, res) => {
    const { diary_id, content } = req.body;
    const userId = req.session.user_id; // 현재 세션에 저장된 사용자 아이디를 가져옴
    saveComment(diary_id, userId, content); // 댓글 저장
    res.json({ success: true });
});

// 댓글 불러오기 엔드포인트
app.get('/comments/:diaryId', (req, res) => {
    const diaryId = req.params.diaryId;
    const diaryComments = getComments(diaryId); // 해당 다이어리의 댓글 불러오기
    res.json(diaryComments);
});

// 오류 이벤트 핸들러 추가
app.use((err, req, res, next) => {
    console.error('Unhandled error:', err);
    res.status(500).send('Something went wrong!');
});

app.listen(port, '0.0.0.0', () => {
    console.log(`Server is running on port ${port}`);
});
