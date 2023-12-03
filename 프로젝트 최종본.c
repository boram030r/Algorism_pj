#include <stdio.h>
#include <windows.h>
#include <conio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define UP 0		// 위키
#define DOWN 1		// 아래키
#define SUBMIT 3	// 스페이스바

void setting(); // 초기화 작업
void gotoxy(int, int); // 커서 위치 이동
int menudraw(); // menu 화면 그리기
int keyControl(); // w와 s키로 이동, 스페이스로 선택
int basic();
int luck();
void choice();
void bubble();
void sab();
void bung();
void quick1();
void hib();
int spe();
int choi();
void gisu();
void gesu();
void da();
void dep();
void nu();
void pol();
void cru();
void prim();
void topology();
void astar();
void hash();
void back();
void tree();
void genetic();
void state();
void mon();

int main() {
	setting();

	while (1) {
		int menuCode = menudraw();

		if (menuCode == 7) { // 기본적인 정렬 알고리즘
			int subMenuCode = basic(); // 서브 메뉴에서 선택한 메뉴 항목을 받습니다.
			if (subMenuCode == 0) {
				// 선택 정렬을 실행하도록 코드 작성
				choice();
			}
			else if (subMenuCode == 3) {
				// 버블 정렬을 실행하도록 코드 작성
				bubble();
			}
			else if (subMenuCode == 6) {
				// 삽입 정렬을 실행하도록 코드 작성
				sab();
			}
		}
		else if (menuCode == 10) { // 고급 정렬 알고리즘
			int subMenuCode1 = luck();
			if (subMenuCode1 == 0) {
				// 병합 정렬
				bung();
			}
			else if (subMenuCode1 == 3) {
				// 퀵 정렬
				quick1();
			}
			else if (subMenuCode1 == 6) {
				// 힙 정렬 
				hib();
			}
		}
		else if (menuCode == 13) { // 특수 정렬 알고리즘
			int subMenuCode2 = spe();
			if (subMenuCode2 == 0) {
				// 기수 정렬 
				gisu();
			}
			else if (subMenuCode2 == 3) {
				// 계수 정렬
				gesu();
			}
		}
		else if (menuCode == 16) { // 그래프 알고리즘
			int subMenuCode3 = choi();
			if (subMenuCode3 == 0) {
				// 너비 우선 탐색
				nu();
			}
			else if (subMenuCode3 == 3) {
				// 깊이 우선 탐색
				dep();
			}
			else if (subMenuCode3 == 6) {
				// 프림 알고리즘
				prim();
			}
			else if (subMenuCode3 == 9) {
				// 크루스칼 알고리즘
				cru();
			}
			else if (subMenuCode3 == 12) {
				// 다익스트라 최단 경로 알고리즘
				da();
			}
			else if (subMenuCode3 == 15) {
				// 플로이드 최단 경로 알고리즘
				pol();

			}
			else if (subMenuCode3 == 18) {
				// 위상 정럴
				topology();
			}
			else if (subMenuCode3 == 21) {
				// 백트래킹 해 탐색 알고리즘
				back();
			}
			else if (subMenuCode3 == 24) {
				// A* 알고리즘
				astar();
			}
			else if (subMenuCode3 == 27) {
				// 트리 정렬 알고리즘
				tree();
			}
			else if (subMenuCode3 == 30) {
				// 상태 공간 트리
				state();
			}
		}

		else if (menuCode == 19) { // 유전자 알고리즘
			genetic();
		}
		else if (menuCode == 22) { // 문자열 알고리즘
			mon();
		}
		else if (menuCode == 25) { // 해시 테이블
			hash();
		}
		else if (menuCode == 28) { // 종료
			break;
		}
		system("cls");
	}
	return 0;
}

// 메인 메뉴
int menudraw() {
	printf("\n\n---------------------------- w와 s키로 이동하고 스페이스로 선택하세요 !! ---------------------------");
	int x = 40, y = 7;
	gotoxy(x - 2, y);
	printf("> 기본적인 정렬 알고리즘");
	gotoxy(x, y + 3);
	printf("고급 정렬 알고리즘");
	gotoxy(x, y + 6);
	printf("특수 정렬 알고리즘");
	gotoxy(x, y + 9);
	printf("그래프 알고리즘");
	gotoxy(x, y + 12);
	printf("유전자 알고리즘");
	gotoxy(x, y + 15);
	printf("문자열 알고리즘");
	gotoxy(x, y + 18);
	printf("해시 테이블");
	gotoxy(x, y + 21);
	printf("종료");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 7) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y - 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 28) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y + 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y;
		}
		}
	}
}

// 콘솔창 크기 세팅
void setting() {
	system("mode con:cols=100 lines=35");
}

// 기본정렬 알고리즘
int basic() {
	system("cls");
	int x = 45, y = 7;
	// 이 부분에 선택, 버블, 삽입 선택할 수 있도록 위치 지정
	gotoxy(x - 2, y);
	printf("> 선택 정렬");
	gotoxy(x, y + 3);
	printf("버블 정렬");
	gotoxy(x, y + 6);
	printf("삽입 정렬");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 7) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y - 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 13) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y + 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			int selectedMenu = y - 7;
			return selectedMenu;
		}
		}
	}
}

// 특수정렬 알고리즘
int luck() {
	system("cls");
	int x = 45, y = 7;
	gotoxy(x - 2, y);
	printf("> 병합 정렬");
	gotoxy(x, y + 3);
	printf("퀵 정렬");
	gotoxy(x, y + 6);
	printf("힙 정렬");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 7) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y - 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 13) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y + 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			int selectedMenu = y - 7;
			return selectedMenu;
		}
		}
	}
}

int spe() {
	system("cls");
	int x = 45, y = 7;
	gotoxy(x - 2, y);
	printf("> 기수 정렬");
	gotoxy(x, y + 3);
	printf("계수 정렬");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 7) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y - 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 10) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y + 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			int selectedMenu = y - 7; // 0, 3
			return selectedMenu;
		}
		}
	}
}

int choi() {
	system("cls");
	int x = 20, y = 2;
	gotoxy(x - 2, y);
	printf("> 너비 우선 탐색 (BFS)");
	gotoxy(x, y + 3);
	printf("깊이 우선 탐색 (DFS)");
	gotoxy(x, y + 6);
	printf("프림 알고리즘");
	gotoxy(x, y + 9);
	printf("크루스칼 알고리즘");
	gotoxy(x, y + 12);
	printf("다익스트라 최단 경로 알고리즘");
	gotoxy(x, y + 15);
	printf("플로이드 최단 경로 알고리즘");
	gotoxy(x, y + 18);
	printf("위상 정렬");
	gotoxy(x, y + 21);
	printf("백트래킹 해 탐색 알고리즘");
	gotoxy(x, y + 24);
	printf("A* 알고리즘");
	gotoxy(x, y + 27);
	printf("이진 트리");
	gotoxy(x, y + 30);
	printf("상태 공간 트리");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 2) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y - 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 32) {
				gotoxy(x - 2, y);
				printf(" ");
				y = y + 3;
				gotoxy(x - 2, y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			int selectedMenu = y - 2; // 0, 3, 6, 9, 12, 15, 18
			return selectedMenu;
		}
		}
	}
}

void choice() {
	system("cls");
	int y = 15;
	int num;
	int number[100];
	int min, temp, i, j, t;

	gotoxy(10, 5);
	printf("선택정렬이란? 첫번째 인덱스부터 모든 인덱스를 검사하여 최소값을 찾아 정렬하는 방식\n");
	gotoxy(20, 10);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);

	gotoxy(20, 12);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}

	for (i = 0; i < num - 1; i++) {
		min = i;
		for (j = i + 1; j < num; j++) {
			if (number[j] < number[min]) {
				min = j;
			}
		}

		temp = number[i];
		number[i] = number[min];
		number[min] = temp;

		gotoxy(38, y);
		printf("%d단계 : ", i + 1);
		for (t = 0; t < num; t++) {
			printf("%d ", number[t]);
		}
		y = y + 2;
		getchar();
	}
}

// 버블 정렬
void bubble() {
	system("cls");
	int y = 12;
	int num;
	int number[100];
	int i, j, t, temp;

	gotoxy(20, 5);
	printf("버블정렬이란? 왼쪽부터 이웃한 수를 비교하면서\n");
	gotoxy(20, 6);
	printf("순서가 제대로 되어 있지 않으면 하나하나 바꾸는 정렬방법이다.\n");

	gotoxy(20, 8);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);

	gotoxy(20, 10);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	for (i = num - 1; i > 0; i--) {
		gotoxy(20, y);
		printf("%d단계 \n", num - i);
		for (j = 0; j < i; j++) {
			y = y + 1;
			if (number[j] > number[j + 1]) {
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
			gotoxy(25, y);
			for (t = 0; t < num; t++) {
				printf("%d ", number[t]);
			}
			printf("\n");
		}
		y = y + 2;
		getchar();
	}
}

//삽입 정렬
void sab() {
	system("cls");
	int i, j, t, temp, num;
	int number[100];
	int y = 12;
	gotoxy(20, 5);
	printf("삽입 정렬이란? 한 개짜리 배열에서 시작하여 그 크기를\n");
	gotoxy(20, 6);
	printf("하나씩 늘리는 정렬방법이다.\n");
	gotoxy(20, 8);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);
	gotoxy(20, 10);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	for (i = 1; i < num; i++) {
		temp = number[i];
		j = i;
		while ((j > 0) && (number[j - 1] > temp)) {
			number[j] = number[j - 1];
			j = j - 1;
		}
		number[j] = temp;
		gotoxy(20, y);
		printf("%d단계 : ", i);
		for (t = 0; t < num; t++) {
			printf("%d ", number[t]);
		}
		y = y + 2;
		getchar();
	}
}

//병합 정렬
#define MAX 30
extern int num;
int sorted[MAX];
int y = 12;
void merge(int number[], int m, int middle, int n) {
	int i, j, k, t;
	i = m;
	j = middle + 1;
	k = m;
	while (i <= middle && j <= n) {
		if (number[i] <= number[j]) {
			sorted[k++] = number[i++];
		}
		else {
			sorted[k++] = number[j++];
		}
	}
	if (i > middle) {
		for (t = j; t <= n; t++, k++) {
			sorted[k] = number[t];
		}
	}
	else {
		for (t = i; t <= middle; t++, k++) {
			sorted[k] = number[t];
		}
	}
	for (t = m; t <= n; t++) {
		number[t] = sorted[t];
	}
	gotoxy(15, y);
	printf("병합정렬 : ");
	for (t = m; t <= n; t++) {
		printf("%d ", number[t]);
	}
	y = y + 2;
	getchar();

}

void mergeSort(int number[], int m, int n) {
	int middle;
	if (m < n) {
		middle = (m + n) / 2;
		mergeSort(number, m, middle);
		mergeSort(number, middle + 1, n);
		merge(number, m, middle, n);
	}
}

void bung() {
	system("cls");
	int num;
	int number[100];
	gotoxy(15, 5);
	printf("병합정렬이란? 입력을 반으로 나눈 뒤 전반부와 후반부를 각각 독립적으로 정렬하여 \n");
	gotoxy(15, 6);
	printf("마지막으로 정렬된 두 부분을 합쳐서 정렬된 배열을 얻는 정렬방법이다.\n");
	gotoxy(15, 8);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);
	gotoxy(15, 10);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	mergeSort(number, 0, num - 1);
}

int i = 0;
int z = 12;

// 퀵 정렬
int partition(int number[], int begin, int end, int num) {
	int pivot, L, R, t, temp;
	L = begin;
	R = end;
	pivot = (begin + end) / 2;

	gotoxy(25, z);
	printf("%d단계 : pivot = %d", ++i, number[pivot]);

	while (L < R) {
		while ((number[L] < number[pivot]) && (L < R)) {
			L++;
		}
		while ((number[R] >= number[pivot]) && (L < R)) {
			R--;
		}
		if (L < R) {
			temp = number[L];
			number[L] = number[R];
			number[R] = temp;

			if (L == pivot) {
				pivot = R;
			}
			temp = number[pivot];
			number[pivot] = number[R];
			number[R] = temp;
		}
	}

	gotoxy(25, z + 1);
	for (t = 0; t < num; t++) {
		printf("%d ", number[t]);
	}
	z += 3;
	getchar();
	return R;
}

void quickSort(int number[], int begin, int end, int num) {
	int p;
	if (begin < end) {
		p = partition(number, begin, end, num);
		quickSort(number, begin, p - 1, num);
		quickSort(number, p + 1, end, num);
	}
}

void quick1() {
	system("cls");
	int number[100];
	int num;
	gotoxy(15, 5);
	printf("퀵 정렬이란? 기준원소를 하나 고른 뒤 이 기준원소를 중심으로 \n");
	gotoxy(15, 6);
	printf("더 작거나 같은 수는 왼쪽으로, 큰 수는 오른쪽으로 배치하여 정렬하는 방법이다.\n");
	gotoxy(15, 8);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);
	gotoxy(15, 10);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	quickSort(number, 0, num - 1, num);
}

//힙 정렬

void hib() {
	system("cls");
	int number[100];
	int y = 14;
	int num;
	int k, i;

	gotoxy(15, 5);
	printf("힙 정렬이란? 최대 힙 트리나 최소 힙 트리를 구성해 정렬하는 방법이다.\n");
	gotoxy(20, 10);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);
	gotoxy(20, 12);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}


	for (i = num / 2 - 1; i >= 0; i--) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < num && number[left] > number[largest])
			largest = left;

		if (right < num && number[right] > number[largest])
			largest = right;

		if (largest != i) {
			int temp = number[i];
			number[i] = number[largest];
			number[largest] = temp;
		}
	}

	for (i = num - 1; i > 0; i--) {
		int temp = number[0];
		number[0] = number[i];
		number[i] = temp;

		int j = 0;
		int largest = 0;
		int flag = 0;

		while (flag != 1) {
			largest = 2 * j + 1;

			if ((largest < i - 1) && (number[largest] < number[largest + 1]))
				largest = largest + 1;

			if (largest < i && (number[j] < number[largest])) {
				temp = number[j];
				number[j] = number[largest];
				number[largest] = temp;
				j = largest;
			}
			else {
				flag = 1;
			}
		}
		gotoxy(20, y);
		printf("정렬 한 배열 : ");
		for (k = 0; k < 5; k++) {
			printf("%d ", number[k]);
		}
		y = y + 2;
		getchar();
	}
}

//기수 정렬

void gisu() {
	system("cls");
	int number[100];
	int num, k;
	gotoxy(20, 5);
	printf("기수 정렬이란? 낮은 자리수부터 비교하여 정렬해 가는 정렬 알고리즘\n");
	gotoxy(20, 10);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);
	gotoxy(20, 12);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	int temp[10][10]; // 10진수 숫자를 저장하는 배열
	int max = number[0];
	for (k = 1; k < num; k++) {
		if (number[k] > max) {
			max = number[k];
		}
	}

	int maxDigit = 0; // 최대 자릿수 계산
	while (max > 0) {
		max /= 10;
		maxDigit++;
	}

	int divisor = 1;
	for (int digit = 0; digit < maxDigit; digit++) {
		int count[10] = { 0 }; // 각 자릿수별로 카운트
		int output[100];      // 정렬된 결과를 저장할 배열

		// 각 숫자를 해당 자릿수의 숫자로 나누어 배열에 저장
		for (k = 0; k < num; k++) {
			int currentDigit = (number[k] / divisor) % 10;
			temp[currentDigit][count[currentDigit]] = number[k];
			count[currentDigit]++;
		}

		int outputIndex = 0;

		// 각 패스의 결과 출력
		gotoxy(20, 15);
		printf("중간 결과 : ", digit + 1);
		for (k = 0; k < num; k++) {
			printf("%d ", number[k]);
		}

		// 카운트 배열을 이용해 정렬된 결과 배열을 만듭니다.
		for (int i = 0; i < 10; i++) {
			for (k = 0; k < count[i]; k++) {
				number[outputIndex] = temp[i][k];
				outputIndex++;
			}
		}

		divisor *= 10;
		getchar();
	}

	// 마지막 패스 결과 출력
	gotoxy(20, 19);
	printf("최종 정렬 결과: ");
	for (k = 0; k < num; k++) {
		printf("%d ", number[k]);
	}

	getchar();
}

//계수 정렬
void gesu() {
	system("cls");
	int number[100];
	int num;
	int k;
	gotoxy(15, 5);
	printf("계수 정렬이란? 데이터들의 크기에 따라 정렬해주는 정렬 알고리즘\n");
	gotoxy(20, 10);
	printf("입력하실 숫자의 개수를 입력하세요 : ");
	scanf_s("%d", &num);
	gotoxy(20, 12);
	printf("숫자 %d개를 입력하세요 (띄어쓰기로 구분합니다) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}

	int max = number[0];
	for (k = 1; k < num; k++) {
		if (number[k] > max) {
			max = number[k];
		}
	}

	// 최대 값 + 1 크기의 계수 배열을 초기화
	int count[1001] = { 0 }; // 최대 값 + 1로 설정 (가정: 입력 숫자가 1000 이하)

	// 입력된 숫자의 빈도수를 계수 배열에 기록
	for (k = 0; k < num; k++) {
		count[number[k]]++;
	}

	int outputIndex = 0;

	// 계수 배열을 기반으로 정렬된 결과를 생성
	for (k = 0; k <= max; k++) {
		while (count[k] > 0) {
			number[outputIndex] = k;
			outputIndex++;
			count[k]--;
		}
	}
	getchar();

	// 최종 정렬된 결과 출력
	gotoxy(20, 15);
	printf("계수 정렬 결과: ");
	for (k = 0; k < num; k++) {
		printf("%d ", number[k]);
	}

	getchar(); // 결과 확인을 위한 사용자 입력 대기
}

//다익스트라 알고리즘
#pragma once
#define TRUE 1
#define FALSE 0
#define INF 10000
#define MAX_VERTICES 5

int distance[MAX_VERTICES];
int S[MAX_VERTICES];

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0, 10, 5, INF, INF},
	{INF, 0, 2, 1, INF},
	{INF, 3, 0, 9, 2},
	{INF, INF, INF, 0, 4},
	{7, INF, INF, 6, 0},
};

int nextVertex(int n);
int printStep(int step);
void Dijkstra_shortestPath(int start, int n);

// 최소 거리를 갖는 다음 정점을 찾는 연산
int nextVertex(int n) {
	int i, min, minPos;
	min = INF;
	minPos = -1;
	for (i = 0; i < n; i++) {
		if ((distance[i] < min) && !S[i]) {
			min = distance[i];
			minPos = i;
		}
	}
	return minPos;
}

// 최단 경로 구하는 과정을 출력하는 연산
int printStep(int step) {
	int i;
	printf("\n %3d단계 : S = {", step);
	for (i = 0; i < MAX_VERTICES; i++) {
		if (S[i] == TRUE) {
			printf("%d", i);
			if (i < MAX_VERTICES - 1 && S[i + 1] == TRUE) {
				printf(", ");
			}
		}
	}

	if (step < 1)
		printf(" } \t\t\t");
	else if (step < 4)
		printf(" } \t\t");
	else
		printf(" } \t");
	printf(" distance :[");
	for (i = 0; i < MAX_VERTICES; i++)
		if (distance[i] == INF)
			printf("%4c", '*');
		else
			printf("%4d", distance[i]);

	printf("%4c", ']');
	printf("\n");
	return step + 1;
}

void Dijkstra_shortestPath(int start, int n) {
	int i, u, w, step = 0;
	for (i = 0; i < n; i++) {
		distance[i] = weight[start][i];
		S[i] = FALSE;
	}
	S[start] = TRUE;
	distance[start] = 0;
	step = printStep(0);
	for (i = 0; i < n - 1; i++) {
		u = nextVertex(n);
		S[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!S[w])
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];
		step = printStep(step);
	}
}

void da() {
	system("cls");
	int i, j;
	printf("*********** 가중치 인접 행렬 ***********\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}
	printf("\n*********** 다익스트라 최단 경로 구하기 ***********\n");
	Dijkstra_shortestPath(0, MAX_VERTICES);
	getchar();
}

//깊이 우선 탐색
#define MAX_VERTEX 30
#define FALSE 0
#define TRUE 1

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX];
} graphType;

// 스택 구현을 위한 노드 구조체
typedef struct stackNode {
	int data;
	struct stackNode* link;
} stackNode;

stackNode* top; // 전역 변수로 스택의 top을 관리

// 스택이 비어있는지 확인하는 연산
int isStackEmpty() {
	return top == NULL;
}

// 스택에 원소를 추가하는 연산
void push(int value) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = value;
	temp->link = top;
	top = temp;
}

// 스택에서 원소를 제거하고 반환하는 연산
int pop() {
	if (isStackEmpty()) {
		printf("\n Stack Underflow!\n");
		exit(EXIT_FAILURE);
	}
	int value = top->data;
	stackNode* temp = top;
	top = top->link;
	free(temp);
	return value;
}

// 공백 그래프를 생성하는 연산
void createGraph(graphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;
		g->visited[v] = FALSE;
	}
}

void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 'A');
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 'A');
			p = p->link;
		}
	}
}

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL; // 스택 초기화
	push(v);
	g->visited[v] = TRUE;
	printf(" %c", v + 'A');
	// 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
	while (!isStackEmpty()) {
		v = top->data;
		w = g->adjList_H[v];
		while (w) {
			if (!g->visited[w->vertex]) {
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 'A');
				break; // 스택에 새로운 정점을 push하고 출력했으므로 반복 중단
			}
			w = w->link;
		}
		if (w == NULL) {
			// 현재 정점에서 방문할 수 있는 정점이 더 이상 없으면 pop
			pop();
		}
	}
}

void dep() {
	system("cls");
	int i;
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));
	createGraph(G9);
	for (i = 0; i < 7; i++)
		insertVertex(G9, i);
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6);
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4);
	insertEdge(G9, 6, 3);
	printf("\n G9의 인접 리스트 ");
	print_adjList(G9);
	printf("\n\n//////////////\n\n깊이 우선 탐색 >> ");
	DFS_adjList(G9, 0);
	getchar();
}

// 너비 우선 탐색
typedef int element;
typedef struct QNode {
	element data;
	struct QNode* link;
} QNode;

typedef struct {
	QNode* front, * rear;
} LQueueType;

LQueueType* createLinkedQueue(void);
int isLQEmpty(LQueueType* LQ);
void enLQueue(LQueueType* LQ, element item);
element deLQueue(LQueueType* LQ);
element peekLQ(LQueueType* LQ);
void printLQ(LQueueType* LQ);

LQueueType* createLinkedQueue(void) {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isLQEmpty(LQueueType* LQ) {
	return LQ->front == NULL;
}

void enLQueue(LQueueType* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

element deLQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	element item;
	if (isLQEmpty(LQ)) {
		printf("\n Queue Underflow!\n");
		exit(EXIT_FAILURE);
	}
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

element peekLQ(LQueueType* LQ) {
	element item;
	if (isLQEmpty(LQ)) {
		printf("\n Queue is Empty!\n");
		exit(EXIT_FAILURE);
	}
	else {
		item = LQ->front->data;
		return item;
	}
}

void printLQ(LQueueType* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3d", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE;
	printf(" %c", v + 65);
	enLQueue(Q, v);
	while (!isLQEmpty(Q)) {
		v = deLQueue(Q);
		for (w = g->adjList_H[v]; w; w = w->link) {
			if (!g->visited[w->vertex]) {
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				enLQueue(Q, w->vertex);
			}
		}
	}
}

void nu() {
	system("cls");
	int i;
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));
	createGraph(G9);
	for (i = 0; i < 7; i++)
		insertVertex(G9, i);
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6);
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4);
	insertEdge(G9, 6, 3);
	printf("\n G9의 인접 리스트 ");
	print_adjList(G9);
	printf("\n\n//////////////\n\n너비 우선 탐색 >> ");
	BFS_adjList(G9, 0);
	getchar();
}

// 플로이드 최단 경로 알고리즘
#define INF 10000
#define MAX_VERTICES 5


int A[MAX_VERTICES][MAX_VERTICES];

void printStep_po(int step) {
	int i, j;
	printf("\n A%d : ", step);
	for (i = 0; i < MAX_VERTICES; i++) {
		printf("\t");
		for (j = 0; j < MAX_VERTICES; j++) {
			if (A[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", A[i][j]);
		}
		getchar();
		printf("\n\n");
	}
}

void Floyd_shortestPath(int n) {
	int v, w, k, step = -1;

	for (v = 0; v < n; v++)
		for (w = 0; w < n; w++)
			A[v][w] = weight[v][w];

	printStep_po(step);

	for (k = 0; k < n; k++) {
		for (v = 0; v < n; v++)
			for (w = 0; w < n; w++)
				if (A[v][k] + A[k][w] < A[v][w])
					A[v][w] = A[v][k] + A[k][w];

		printStep_po(++step);
	}
}

void pol() {
	system("cls");
	int i, j;
	extern int weight[MAX_VERTICES][MAX_VERTICES];
	printf("\n *************** 가중치 인접 행렬 ***************\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}
	printf("\n *************** 플로이드 최단 경로 구하기 ***************\n\n");
	Floyd_shortestPath(MAX_VERTICES);
	getchar();
}

// 크루스칼 알고리즘
// 정점의 부모를 찾기 위한 함수
int findParent(int parent[], int i) {
	if (parent[i] == -1)
		return i;
	return findParent(parent, parent[i]);
}

// 두 정점을 하나로 합치는 함수
void unionVertices(int parent[], int x, int y) {
	int xSet = findParent(parent, x);
	int ySet = findParent(parent, y);
	parent[xSet] = ySet;
}

// 간선을 나타내는 구조체
struct Edge {
	char src, dest;
	int weight;
};

// 간선을 가중치에 따라 오름차순으로 정렬하는 비교 함수
int compareEdges(const void* a, const void* b) {
	return ((struct Edge*)a)->weight < ((struct Edge*)b)->weight ? -1 : (((struct Edge*)a)->weight > ((struct Edge*)b)->weight);
}

// 크루스칼 알고리즘 함수
void kruskal(struct Edge edges[], int V, int E) {
	// 간선을 가중치에 따라 정렬
	qsort(edges, E, sizeof(edges[0]), compareEdges);

	// 부모 배열 초기화
	int* parent = (int*)malloc(V * sizeof(int));
	for (int i = 0; i < V; ++i)
		parent[i] = -1;

	// 각 정점의 루트를 저장하는 배열
	int* root = (int*)malloc(V * sizeof(int));
	for (int i = 0; i < V; ++i)
		root[i] = i;

	// 최소 비용 신장 트리를 저장할 배열
	struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
	int resultIndex = 0; // result 배열에 추가된 간선의 인덱스

	// 크루스칼 알고리즘 수행
	for (int i = 0; i < E; ++i) {
		struct Edge nextEdge = edges[i];

		int x = findParent(parent, nextEdge.src - 'A');
		int y = findParent(parent, nextEdge.dest - 'A');

		// 루트가 같으면 사이클이 형성되므로 무시
		if (root[x] != root[y]) {
			result[resultIndex] = nextEdge;
			unionVertices(parent, x, y);
			++resultIndex; // 결과 배열의 인덱스 증가
		}

	}

	// 결과 출력
	printf("최소 비용 신장 트리의 간선\n");
	for (int j = 0; j < resultIndex; ++j)
		printf("(%c, %c) 가중치: %d\n", result[j].src, result[j].dest, result[j].weight);
	getchar();
	// 메모리 해제
	free(parent);
	free(root);
	free(result);
}


void cru() {
	system("cls");
	// 정점의 개수와 간선의 개수
	int V = 7, E = 11;

	printf("\n");
	printf("크루스칼 알고리즘이란 모든 정점을 최소 비용으로\n");
	printf("연결하여 최소 신장 트리를 구하는 알고리즘이다.\n\n");

	printf("|  가중치  |   간선  |\n");
	printf("|     2    |  (E, G) |\n");
	printf("|     3    |  (A, B) |\n");
	printf("|     4    |  (E, F) |\n");
	printf("|     5    |  (B, D) |\n");
	printf("|     6    |  (A, D) |\n");
	printf("|     8    |  (C, F) |\n");
	printf("|     9    |  (D, E) |\n");
	printf("|    10    |  (C, E) |\n");
	printf("|    12    |  (B, G) |\n");
	printf("|    14    |  (F, G) |\n");
	printf("|    17    |  (A, C) |\n\n");

	// 주어진 간선과 가중치
	struct Edge edges[] = {
		{'E', 'G', 2}, {'A', 'B', 3}, {'E', 'F', 4},
		{'B', 'D', 5}, {'A', 'D', 6}, {'C', 'F', 8},
		{'D', 'E', 9}, {'C', 'E', 10}, {'B', 'G', 12},
		{'F', 'G', 14}, {'A', 'C', 17}
	};

	// 크루스칼 알고리즘 호출
	kruskal(edges, V, E);
	getchar();
}

// 프림알고리즘
#define V 7

// 최소 거리를 찾는 함수
int minKey(int key[], int mstSet[]) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++) {
		if (mstSet[v] == 0 && key[v] < min) {
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

// 프림알고리즘 구현
// 최소 비용 신장 트리를 생성하는 함수
void primMST(struct Edge edges[], int E) {
	int parent[V];  // MST에 포함된 정점의 부모
	int key[V];     // 해당 정점까지의 최소 거리
	int mstSet[V];  // MST에 포함된 정점인지 여부

	for (int i = 0; i < V; i++) {
		key[i] = INT_MAX;
		mstSet[i] = 0;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = 1;

		for (int v = 0; v < V; v++) {
			for (int e = 0; e < E; e++) {
				if ((edges[e].src - 'A' == u || edges[e].dest - 'A' == u) &&
					(edges[e].src - 'A' != v && edges[e].dest - 'A' != v))
					continue;

				if (edges[e].src - 'A' == u || edges[e].dest - 'A' == u) {
					if (mstSet[v] == 0 && edges[e].weight < key[v]) {
						parent[v] = u;
						key[v] = edges[e].weight;
					}
				}
			}
		}
	}

	// 결과 출력
	printf("최소 비용 신장 트리의 간선\n");
	for (int i = 1; i < V; i++)
		printf("(%c, %c) 가중치: %d\n", parent[i] + 'A', i + 'A', key[i]);
	getchar();
}

// 간선을 나타내는 구조체
struct Edge1 {
	char src, dest;
	int weight;
};

void prim() {
	system("cls");

	printf("\n");
	printf("프림 알고리즘은 크루스칼 알고리즘처럼 미리 간선을 정렬하지 않고 \n");
	printf("하나의 정점에서 시작하여 트리를 확장해 나가는 방법이다.\n\n");

	printf("|  가중치  |   간선  |\n");
	printf("|     2    |  (E, G) |\n");
	printf("|     3    |  (A, B) |\n");
	printf("|     4    |  (E, F) |\n");
	printf("|     5    |  (B, D) |\n");
	printf("|     6    |  (A, D) |\n");
	printf("|     8    |  (C, F) |\n");
	printf("|     9    |  (D, E) |\n");
	printf("|    10    |  (C, E) |\n");
	printf("|    12    |  (B, G) |\n");
	printf("|    14    |  (F, G) |\n");
	printf("|    17    |  (A, C) |\n\n");

	struct Edge edges[] = {
		{'E', 'G', 2}, {'A', 'B', 3}, {'E', 'F', 4},
		{'B', 'D', 5}, {'A', 'D', 6}, {'C', 'F', 8},
		{'D', 'E', 9}, {'C', 'E', 10}, {'B', 'G', 12},
		{'F', 'G', 14}, {'A', 'C', 17}
	};

	int E = sizeof(edges) / sizeof(edges[0]);

	primMST(edges, E);
	getchar();
}

// 위상 정렬

#define MAX_NODES 6

// 그래프의 노드 구조체
typedef struct Node {
	int value;
	struct Node* next;
} Node;

// 그래프의 정점 구조체
typedef struct {
	int inDegree;   // 진입 차수
	Node* head;     // 연결 리스트의 헤드
} Vertex;

// 전역 변수
Vertex graph[MAX_NODES];
char tasks[][20] = { "냄비에 물 붓기", "점화", "라면봉지 뜯기", "라면 넣기", "수프 넣기", "계란 풀어넣기" };
char result[MAX_NODES][20];
int resultIndex = 0;

// 정점을 그래프에 추가하는 함수
void addEdge(int from, int to) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = to;
	newNode->next = graph[from].head;
	graph[from].head = newNode;
	graph[to].inDegree++;
}

// 위상 정렬 알고리즘
// 그래프 상태 출력 함수
void printGraphState(int numNodes) {
	printf("그래프 상태\n\n");
	for (int i = 0; i < numNodes; ++i) {
		printf("%d. %s (진입 차수: %d)\n", i + 1, tasks[i], graph[i].inDegree);
	}
	printf("\n");
}

// 위상 정렬 알고리즘
void topologicalSort(int numNodes) {
	int queue[MAX_NODES];
	int front = 0, rear = -1;

	// 진입 차수가 0인 정점을 큐에 삽입
	for (int i = 0; i < numNodes; ++i) {
		if (graph[i].inDegree == 0) {
			queue[++rear] = i;
		}
	}

	// 큐에서 정점을 꺼내면서 위상 정렬 수행
	while (front <= rear) {
		int current = queue[front++];

		// 결과 배열에 추가
		for (int i = 0; tasks[current][i] != '\0'; ++i) {
			result[resultIndex][i] = tasks[current][i];
		}
		result[resultIndex++][strlen(tasks[current])] = '\0';

		// 연결된 정점들의 진입 차수 감소
		Node* temp = graph[current].head;
		while (temp != NULL) {
			int neighbor = temp->value;
			graph[neighbor].inDegree--;

			// 진입 차수가 0이 되면 큐에 삽입
			if (graph[neighbor].inDegree == 0) {
				queue[++rear] = neighbor;
			}

			temp = temp->next;
		}
	}

	// 결과 출력
	printf("위상 정렬\n\n");
	for (int i = 0; i < numNodes; ++i) {
		printf("%d. %s\n", i + 1, result[i]);
	}
	getchar();
	printf("\n");
}

void topology() {
	system("cls");

	printf("\n");
	printf("위상 정렬은 순서가 정해져있는 작업을 차례대로 \n");
	printf("수행해야 할 때 그 순서를 결정해주기 위해 사용하는 알고리즘이다.\n\n");

	// 그래프 초기화
	int numNodes = 6;
	for (int i = 0; i < numNodes; ++i) {
		graph[i].inDegree = 0;
		graph[i].head = NULL;
	}


	// 간선 추가
	addEdge(2, 0);
	addEdge(0, 1);
	addEdge(2, 3);
	addEdge(1, 4);
	addEdge(3, 4);
	addEdge(4, 5);

	// 그래프 상태 출력
	printGraphState(numNodes);

	// 위상 정렬 수행
	topologicalSort(numNodes);
}

// A* 알고리즘
#define ROWS 5
#define COLS 5

struct Coord {
	int x, y;
};

struct PathNode {
	struct Coord pos;
	int g, h, f;
	struct PathNode* parent;
};

int map[ROWS][COLS] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0},
	{0, 0, 0, 0, 0}
};

struct Coord startCoord = { 0, 0 };
struct Coord goalCoord = { 4, 4 };

bool isCoordinateValid(int x, int y) {
	return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

int calculateHeuristic(struct Coord current) {
	return abs(current.x - goalCoord.x) + abs(current.y - goalCoord.y);
}

void printMapWithPoints(struct PathNode* resultNode) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (i == startCoord.x && j == startCoord.y) {
				printf("S ");
			}
			else if (i == goalCoord.x && j == goalCoord.y) {
				printf("G ");
			}
			else if (map[i][j] == 1) {
				printf("1 ");
			}
			else {
				bool inPath = false;
				struct PathNode* currentNode = resultNode;
				while (currentNode != NULL) {
					if (currentNode->pos.x == i && currentNode->pos.y == j) {
						inPath = true;
						break;
					}
					currentNode = currentNode->parent;
				}

				if (inPath) {
					printf("* ");
				}
				else {
					printf("0 ");
				}
			}
		}
		printf("\n");
	}
}

void printResultPath(struct PathNode* node) {
	if (node != NULL) {
		printResultPath(node->parent);
		printf("(%d, %d) ", node->pos.x, node->pos.y);
	}
}

void runAStar() {
	struct PathNode* startNode = (struct PathNode*)malloc(sizeof(struct PathNode));
	startNode->pos = startCoord;
	startNode->g = startNode->h = startNode->f = 0;
	startNode->parent = NULL;

	struct PathNode* openNodes[ROWS * COLS];
	struct PathNode* closedNodes[ROWS * COLS];
	int openCount = 0;
	int closedCount = 0;

	openNodes[openCount++] = startNode;

	while (openCount > 0) {
		int currentIdx = 0;
		for (int i = 1; i < openCount; ++i) {
			if (openNodes[i]->f < openNodes[currentIdx]->f) {
				currentIdx = i;
			}
		}

		struct PathNode* currentNode = openNodes[currentIdx];
		openNodes[currentIdx] = openNodes[--openCount];
		closedNodes[closedCount++] = currentNode;

		struct Coord neighbors[] = {
			{currentNode->pos.x - 1, currentNode->pos.y},
			{currentNode->pos.x + 1, currentNode->pos.y},
			{currentNode->pos.x, currentNode->pos.y - 1},
			{currentNode->pos.x, currentNode->pos.y + 1}
		};

		for (int i = 0; i < 4; ++i) {
			int newX = neighbors[i].x;
			int newY = neighbors[i].y;

			if (isCoordinateValid(newX, newY) && map[newX][newY] != 1) {
				struct PathNode* neighborNode = (struct PathNode*)malloc(sizeof(struct PathNode));
				neighborNode->pos.x = newX;
				neighborNode->pos.y = newY;

				neighborNode->g = currentNode->g + 1;
				neighborNode->h = calculateHeuristic(neighborNode->pos);
				neighborNode->f = neighborNode->g + neighborNode->h;
				neighborNode->parent = currentNode;

				bool inOpenList = false;
				for (int j = 0; j < openCount; ++j) {
					if (openNodes[j]->pos.x == neighborNode->pos.x && openNodes[j]->pos.y == neighborNode->pos.y) {
						inOpenList = true;
						if (neighborNode->f < openNodes[j]->f) {
							openNodes[j]->g = neighborNode->g;
							openNodes[j]->h = neighborNode->h;
							openNodes[j]->f = neighborNode->f;
							openNodes[j]->parent = neighborNode->parent;
						}
						break;
					}
				}

				if (!inOpenList) {
					bool inClosedList = false;
					for (int j = 0; j < closedCount; ++j) {
						if (closedNodes[j]->pos.x == neighborNode->pos.x && closedNodes[j]->pos.y == neighborNode->pos.y) {
							inClosedList = true;
							if (neighborNode->f < closedNodes[j]->f) {
								closedNodes[j]->g = neighborNode->g;
								closedNodes[j]->h = neighborNode->h;
								closedNodes[j]->f = neighborNode->f;
								closedNodes[j]->parent = neighborNode->parent;
								openNodes[openCount++] = closedNodes[j];
								closedNodes[j] = closedNodes[--closedCount];
							}
							break;
						}
					}

					if (!inOpenList && !inClosedList) {
						openNodes[openCount++] = neighborNode;
					}
				}
			}
		}

		if (currentNode->pos.x == goalCoord.x && currentNode->pos.y == goalCoord.y) {
			printf("출발점: (%d, %d)\n", startCoord.x, startCoord.y);
			printf("종료점: (%d, %d)\n", goalCoord.x, goalCoord.y);
			printf("지도:\n");
			printMapWithPoints(currentNode);
			printf("\n최적의 경로: ");
			printResultPath(currentNode);
			printf("\n");
			break;
		}
	}

	for (int i = 0; i < openCount; ++i) {
		free(openNodes[i]);
	}
	for (int i = 0; i < closedCount; ++i) {
		free(closedNodes[i]);
	}
}

void astar() {
	system("cls");

	printf("\n");
	printf("A*알고리즘이란 사용자가 지정한 출발점과 종료점을 수헝하는 경로 중\n");
	printf("가장 최적의 경로를 찾아주는 알고리즘이다.\n\n");
	runAStar();
	getchar();
}

// 해시 테이블
#define TABLE_SIZE 100

// 해시 노드 구조체 정의
typedef struct hashNode {
	char key[50];
	int value;
	struct hashNode* next;
} hashNode;

// 해시 테이블 구조체 정의
typedef struct HashTable {
	hashNode* table[TABLE_SIZE];
} HashTable;

// 문자열 해시 함수
int hashFunction(const char* key) {
	int hash = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		hash = (hash * 31 + key[i]) % TABLE_SIZE;
	}
	return hash;
}

// 문자열 복사 함수
void custom_strcpy(char* destination, const char* source) {
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

// 해시 테이블 초기화
void initHashTable(HashTable* ht) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		ht->table[i] = NULL;
	}
}

// 해시 테이블에 키-값 쌍 추가
void insert(HashTable* ht, const char* key, int value) {
	int index = hashFunction(key);

	// 새로운 노드 생성
	hashNode* newNode = (hashNode*)malloc(sizeof(hashNode));
	custom_strcpy(newNode->key, key);
	newNode->value = value;
	newNode->next = NULL;

	// 체이닝을 이용하여 노드 추가
	if (ht->table[index] == NULL) {
		ht->table[index] = newNode;
	}
	else {
		hashNode* current = ht->table[index];
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

// 해시 테이블에서 키에 대응하는 값 찾기
int search(HashTable* ht, const char* key) {
	int index = hashFunction(key);
	hashNode* current = ht->table[index];

	// 체이닝을 통해 연결된 노드들을 탐색
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return current->value;
		}
		current = current->next;
	}

	// 해당 키에 대한 값이 없을 경우
	return -1;
}

void hash() {
	system("cls");
	printf("\n");
	printf("해시 테이블이란 해시함수를 사용하여 변환한 값을 인덱스로 삼아\n");
	printf("키와 데이터를 저장하는 자료구조를 말한다.\n\n");

	HashTable ht;
	initHashTable(&ht);

	insert(&ht, "apple", 5);
	insert(&ht, "banana", 8);
	insert(&ht, "orange", 3);

	printf("키 'apple'에 대한 값: %d\n", search(&ht, "apple"));
	printf("키 'banana'에 대한 값: %d\n", search(&ht, "banana"));
	printf("키 'orange'에 대한 값: %d\n", search(&ht, "orange"));
	printf("키 'grape'에 대한 값: %d\n", search(&ht, "grape"));
	getchar();
}

// 백트래킹 해탐색 알고리즘
#define N 8

void printSolution(int board[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%2d ", board[i][j]);
		printf("\n");
	}
	printf("\n엔터키를 누르세요.\n");
	getchar(); // 사용자 입력 대기
}

bool isSafe(int board[N][N], int row, int col) {
	// 같은 행에 퀸이 있는지 검사
	for (int i = 0; i < col; i++)
		if (board[row][i])
			return false;

	// 왼쪽 위 대각선에 퀸이 있는지 검사
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// 왼쪽 아래 대각선에 퀸이 있는지 검사
	for (int i = row, j = col; i < N && j >= 0; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;

			if (solveNQueensUtil(board, col + 1))
				return true;

			board[i][col] = 0; // 백트래킹
		}
	}

	return false;
}

void solveNQueens() {
	int board[N][N] = { 0 };

	if (!solveNQueensUtil(board, 0)) {
		printf("해 없음\n");
		return;
	}

	printSolution(board);
}

void back() {
	system("cls");
	printf("\n");
	printf("백트래킹이란 해를 찾는 도중 막히면 이전 단계로 되돌아가서\n");
	printf("다시 해를 찾아가는 기법을 말한다.\n\n");
	int initialBoard[N][N] = { 0 };
	printf("초기상태의 보드\n\n");
	printSolution(initialBoard);  // 초기 상태의 보드 출력
	solveNQueens();
}

// 트리 정렬 알고리즘

#pragma once

typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("%d ", root->key);
		displayInorder(root->right);
	}
}

treeNode* searchBST(treeNode* root, element x);
treeNode* insertBSTNode(treeNode* p, element x);
void deleteBSTNode(treeNode* root, element key);

treeNode* searchBST(treeNode* root, element x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n 찾는 키가 없습니다!");
	return p;
}
treeNode* insertBSTNode(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertBSTNode(p->left, x);
	else if (x > p->key) p->right = insertBSTNode(p->right, x);
	else printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

void deleteBSTNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!!");
		return;
	}
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;
		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

void treeSort(int a[], int n) {
	treeNode* root = NULL;
	root = insertBSTNode(root, a[0]);
	for (int i = 1; i < n; i++)
		insertBSTNode(root, a[i]);

	displayInorder(root);
	printf("\n");
}

void treeSort(int a[], int n);
void tree() {
	system("cls");
	int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = sizeof(list) / sizeof(list[0]);
	printf("\n정렬할 원소 : ");
	for (i = 0; i < size; i++) printf("%3d", list[i]);
	printf("\n <<<<< 트리 정렬 수행 >>>>> \n\n");
	treeSort(list, size);
	getchar();
}

// 유전자 알고리즘
#define POPULATION_SIZE 10
#define GENE_LENGTH 8
#define MUTATION_RATE 0.1

// 개체 구조체 정의
typedef struct {
	int genes[GENE_LENGTH];
	int fitness;
} Individual;

// 초기 개체 생성
void initializePopulation(Individual population[]) {
	for (int i = 0; i < POPULATION_SIZE; ++i) {
		for (int j = 0; j < GENE_LENGTH; ++j) {
			population[i].genes[j] = rand() % 2; // 0 또는 1의 무작위 초기 유전자
		}
	}
}

// 적합도 평가 함수 (예시: 비트의 1의 개수)
void calculateFitness(Individual* individual) {
	individual->fitness = 0;
	for (int i = 0; i < GENE_LENGTH; ++i) {
		if (individual->genes[i] == 1) {
			individual->fitness++;
		}
	}
}

// 선택 함수 (룰렛 휠 선택)
int selectParent(Individual population[]) {
	int totalFitness = 0;
	for (int i = 0; i < POPULATION_SIZE; ++i) {
		totalFitness += population[i].fitness;
	}

	int randomValue = rand() % totalFitness;
	int cumulativeFitness = 0;

	for (int i = 0; i < POPULATION_SIZE; ++i) {
		cumulativeFitness += population[i].fitness;
		if (cumulativeFitness >= randomValue) {
			return i;
		}
	}

	return 0; // 에러 발생 시 기본값
}

// 교차 함수 (한 지점 교차)
void crossover(Individual* parent1, Individual* parent2, Individual* child) {
	int crossoverPoint = rand() % GENE_LENGTH;

	for (int i = 0; i < crossoverPoint; ++i) {
		child->genes[i] = parent1->genes[i];
	}

	for (int i = crossoverPoint; i < GENE_LENGTH; ++i) {
		child->genes[i] = parent2->genes[i];
	}
}

// 돌연변이 함수
void mutate(Individual* child) {
	for (int i = 0; i < GENE_LENGTH; ++i) {
		if ((double)rand() / RAND_MAX < MUTATION_RATE) {
			child->genes[i] = !child->genes[i]; // 0을 1로, 1을 0으로 변환
		}
	}
}

void genetic() {
	system("cls");
	printf("\n");
	printf("유전자 알고리즘이란 생물체가 환경에 적응하면서 진화해나가는 모습을\n");
	printf("모방하여 최적해를 찾아내는 검색 방법이다.\n\n");

	printf("엔터키를 누르세요 ! \n\n");

	srand(time(NULL));

	Individual population[POPULATION_SIZE];
	Individual newPopulation[POPULATION_SIZE];

	initializePopulation(population);

	// 유전 알고리즘 반복 세대
	for (int generation = 0; generation < 100; ++generation) {
		// 각 개체의 적합도 평가
		for (int i = 0; i < POPULATION_SIZE; ++i) {
			calculateFitness(&population[i]);
		}

		// 새로운 세대 생성
		for (int i = 0; i < POPULATION_SIZE; ++i) {
			// 부모 선택
			int parent1Index = selectParent(population);
			int parent2Index = selectParent(population);

			// 교차
			crossover(&population[parent1Index], &population[parent2Index], &newPopulation[i]);

			// 돌연변이
			mutate(&newPopulation[i]);
		}

		// 새로운 세대를 현재 세대로 대체
		for (int i = 0; i < POPULATION_SIZE; ++i) {
			population[i] = newPopulation[i];
		}

		// 일정 세대 간격마다 결과 출력
		if (generation % 10 == 0) {
			// 현재 세대의 최적해 출력
			int maxFitness = 0;
			for (int i = 1; i < POPULATION_SIZE; ++i) {
				if (population[i].fitness > population[maxFitness].fitness) {
					maxFitness = i;
				}
			}

			printf("세대: %d, 최적해: ", generation);
			for (int i = 0; i < GENE_LENGTH; ++i) {
				printf("%d", population[maxFitness].genes[i]);
			}
			printf(", 적합도: %d\n", population[maxFitness].fitness);

			getchar(); // 사용자 입력 대기
		}
	}
}
// 상태 공간 트리
// 간단한 정수 값을 가진 상태 노드 구조체
typedef struct StateNode {
	int value;
	struct StateNode* left;
	struct StateNode* right;
} StateNode;

// 새로운 상태 노드 생성
StateNode* createStateNode(int value) {
	StateNode* newNode = (StateNode*)malloc(sizeof(StateNode));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// 상태 공간 트리 출력 (전위 순회)
void printStateSpaceTree(StateNode* root) {
	if (root != NULL) {
		printf("%d ", root->value);
		printStateSpaceTree(root->left);
		printStateSpaceTree(root->right);
	}
}

void state() {
	system("cls");
	printf("\n");
	printf("상태 공간 트리란 문제를 해결하기 위해 모든 상태들을\n");
	printf("나타내는 트리구조다\n\n");

	StateNode* root = createStateNode(1);
	root->left = createStateNode(2);
	root->right = createStateNode(3);
	root->left->left = createStateNode(4);
	root->left->right = createStateNode(5);
	root->right->left = createStateNode(6);

	// 상태 공간 트리 출력 (초기값)
	printf("초기 상태 공간 트리: ");
	printStateSpaceTree(root);
	printf("\n\n");

	// 상태 공간 트리 출력 (전위 순회)
	printf("전위 순회 결과: ");
	printStateSpaceTree(root);
	printf("\n");

	// 메모리 해제
	free(root->left->left);
	free(root->left->right);
	free(root->right->left);
	free(root->left);
	free(root->right);
	free(root);

	getchar(); // 프로그램이 종료되지 않도록 getchar() 추가
}

// 문자열 알고리즘
// 최대 문자열 길이
#define MAX_LENGTH 100

// 최대 함수 정의
#define max(a, b) ((a) > (b) ? (a) : (b))

// 최장 공통 부분 문자열 찾는 함수
void longestCommonSubstring(char str1[], char str2[]) {
	int m = strlen(str1);
	int n = strlen(str2);

	// dp 배열 초기화
	int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];
	int result = 0;  // 최장 공통 부분 문자열의 길이
	int endIdx = 0;  // 최장 공통 부분 문자열의 끝 인덱스

	// dp 배열 계산
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > result) {
					result = dp[i][j];
					endIdx = i - 1;
				}
			}
			else
				dp[i][j] = 0;
		}
	}

	// 결과 출력
	printf("최장 공통 부분 문자열: ");
	for (int i = endIdx - result + 1; i <= endIdx; i++)
		printf("%c", str1[i]);
	printf("\n");
	getchar();
}

void mon() {
	system("cls");
	printf("\n");
	printf("문자열 알고리즘이란 두 문자열이 주어졌을 때 \n");
	printf("최장 공통 부분 문자열을 찾는 알고리즘이다.\n\n");

	// 두 문자열 입력
	char str1[MAX_LENGTH], str2[MAX_LENGTH];
	printf("첫 번째 문자열 입력: ");
	scanf_s("%s", str1, sizeof(str1));
	printf("\n");
	printf("두 번째 문자열 입력: ");
	scanf_s("%s", str2, sizeof(str2));
	printf("\n");


	// 최장 공통 부분 문자열 찾기
	longestCommonSubstring(str1, str2);
	getchar(); // 프로그램이 바로 종료되지 않도록 getchar() 추가
}

// w 키를 누르면 UP, s 키를 누르면 DOWN, 엔터키를 누르면 SUBMIT
int keyControl() {
	char temp = _getch();
	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}

}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
