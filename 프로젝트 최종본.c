#include <stdio.h>
#include <windows.h>
#include <conio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define UP 0		// ��Ű
#define DOWN 1		// �Ʒ�Ű
#define SUBMIT 3	// �����̽���

void setting(); // �ʱ�ȭ �۾�
void gotoxy(int, int); // Ŀ�� ��ġ �̵�
int menudraw(); // menu ȭ�� �׸���
int keyControl(); // w�� sŰ�� �̵�, �����̽��� ����
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

		if (menuCode == 7) { // �⺻���� ���� �˰���
			int subMenuCode = basic(); // ���� �޴����� ������ �޴� �׸��� �޽��ϴ�.
			if (subMenuCode == 0) {
				// ���� ������ �����ϵ��� �ڵ� �ۼ�
				choice();
			}
			else if (subMenuCode == 3) {
				// ���� ������ �����ϵ��� �ڵ� �ۼ�
				bubble();
			}
			else if (subMenuCode == 6) {
				// ���� ������ �����ϵ��� �ڵ� �ۼ�
				sab();
			}
		}
		else if (menuCode == 10) { // ��� ���� �˰���
			int subMenuCode1 = luck();
			if (subMenuCode1 == 0) {
				// ���� ����
				bung();
			}
			else if (subMenuCode1 == 3) {
				// �� ����
				quick1();
			}
			else if (subMenuCode1 == 6) {
				// �� ���� 
				hib();
			}
		}
		else if (menuCode == 13) { // Ư�� ���� �˰���
			int subMenuCode2 = spe();
			if (subMenuCode2 == 0) {
				// ��� ���� 
				gisu();
			}
			else if (subMenuCode2 == 3) {
				// ��� ����
				gesu();
			}
		}
		else if (menuCode == 16) { // �׷��� �˰���
			int subMenuCode3 = choi();
			if (subMenuCode3 == 0) {
				// �ʺ� �켱 Ž��
				nu();
			}
			else if (subMenuCode3 == 3) {
				// ���� �켱 Ž��
				dep();
			}
			else if (subMenuCode3 == 6) {
				// ���� �˰���
				prim();
			}
			else if (subMenuCode3 == 9) {
				// ũ�罺Į �˰���
				cru();
			}
			else if (subMenuCode3 == 12) {
				// ���ͽ�Ʈ�� �ִ� ��� �˰���
				da();
			}
			else if (subMenuCode3 == 15) {
				// �÷��̵� �ִ� ��� �˰���
				pol();

			}
			else if (subMenuCode3 == 18) {
				// ���� ����
				topology();
			}
			else if (subMenuCode3 == 21) {
				// ��Ʈ��ŷ �� Ž�� �˰���
				back();
			}
			else if (subMenuCode3 == 24) {
				// A* �˰���
				astar();
			}
			else if (subMenuCode3 == 27) {
				// Ʈ�� ���� �˰���
				tree();
			}
			else if (subMenuCode3 == 30) {
				// ���� ���� Ʈ��
				state();
			}
		}

		else if (menuCode == 19) { // ������ �˰���
			genetic();
		}
		else if (menuCode == 22) { // ���ڿ� �˰���
			mon();
		}
		else if (menuCode == 25) { // �ؽ� ���̺�
			hash();
		}
		else if (menuCode == 28) { // ����
			break;
		}
		system("cls");
	}
	return 0;
}

// ���� �޴�
int menudraw() {
	printf("\n\n---------------------------- w�� sŰ�� �̵��ϰ� �����̽��� �����ϼ��� !! ---------------------------");
	int x = 40, y = 7;
	gotoxy(x - 2, y);
	printf("> �⺻���� ���� �˰���");
	gotoxy(x, y + 3);
	printf("��� ���� �˰���");
	gotoxy(x, y + 6);
	printf("Ư�� ���� �˰���");
	gotoxy(x, y + 9);
	printf("�׷��� �˰���");
	gotoxy(x, y + 12);
	printf("������ �˰���");
	gotoxy(x, y + 15);
	printf("���ڿ� �˰���");
	gotoxy(x, y + 18);
	printf("�ؽ� ���̺�");
	gotoxy(x, y + 21);
	printf("����");
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

// �ܼ�â ũ�� ����
void setting() {
	system("mode con:cols=100 lines=35");
}

// �⺻���� �˰���
int basic() {
	system("cls");
	int x = 45, y = 7;
	// �� �κп� ����, ����, ���� ������ �� �ֵ��� ��ġ ����
	gotoxy(x - 2, y);
	printf("> ���� ����");
	gotoxy(x, y + 3);
	printf("���� ����");
	gotoxy(x, y + 6);
	printf("���� ����");
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

// Ư������ �˰���
int luck() {
	system("cls");
	int x = 45, y = 7;
	gotoxy(x - 2, y);
	printf("> ���� ����");
	gotoxy(x, y + 3);
	printf("�� ����");
	gotoxy(x, y + 6);
	printf("�� ����");

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
	printf("> ��� ����");
	gotoxy(x, y + 3);
	printf("��� ����");
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
	printf("> �ʺ� �켱 Ž�� (BFS)");
	gotoxy(x, y + 3);
	printf("���� �켱 Ž�� (DFS)");
	gotoxy(x, y + 6);
	printf("���� �˰���");
	gotoxy(x, y + 9);
	printf("ũ�罺Į �˰���");
	gotoxy(x, y + 12);
	printf("���ͽ�Ʈ�� �ִ� ��� �˰���");
	gotoxy(x, y + 15);
	printf("�÷��̵� �ִ� ��� �˰���");
	gotoxy(x, y + 18);
	printf("���� ����");
	gotoxy(x, y + 21);
	printf("��Ʈ��ŷ �� Ž�� �˰���");
	gotoxy(x, y + 24);
	printf("A* �˰���");
	gotoxy(x, y + 27);
	printf("���� Ʈ��");
	gotoxy(x, y + 30);
	printf("���� ���� Ʈ��");
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
	printf("���������̶�? ù��° �ε������� ��� �ε����� �˻��Ͽ� �ּҰ��� ã�� �����ϴ� ���\n");
	gotoxy(20, 10);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);

	gotoxy(20, 12);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
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
		printf("%d�ܰ� : ", i + 1);
		for (t = 0; t < num; t++) {
			printf("%d ", number[t]);
		}
		y = y + 2;
		getchar();
	}
}

// ���� ����
void bubble() {
	system("cls");
	int y = 12;
	int num;
	int number[100];
	int i, j, t, temp;

	gotoxy(20, 5);
	printf("���������̶�? ���ʺ��� �̿��� ���� ���ϸ鼭\n");
	gotoxy(20, 6);
	printf("������ ����� �Ǿ� ���� ������ �ϳ��ϳ� �ٲٴ� ���Ĺ���̴�.\n");

	gotoxy(20, 8);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);

	gotoxy(20, 10);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	for (i = num - 1; i > 0; i--) {
		gotoxy(20, y);
		printf("%d�ܰ� \n", num - i);
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

//���� ����
void sab() {
	system("cls");
	int i, j, t, temp, num;
	int number[100];
	int y = 12;
	gotoxy(20, 5);
	printf("���� �����̶�? �� ��¥�� �迭���� �����Ͽ� �� ũ�⸦\n");
	gotoxy(20, 6);
	printf("�ϳ��� �ø��� ���Ĺ���̴�.\n");
	gotoxy(20, 8);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);
	gotoxy(20, 10);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
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
		printf("%d�ܰ� : ", i);
		for (t = 0; t < num; t++) {
			printf("%d ", number[t]);
		}
		y = y + 2;
		getchar();
	}
}

//���� ����
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
	printf("�������� : ");
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
	printf("���������̶�? �Է��� ������ ���� �� ���ݺο� �Ĺݺθ� ���� ���������� �����Ͽ� \n");
	gotoxy(15, 6);
	printf("���������� ���ĵ� �� �κ��� ���ļ� ���ĵ� �迭�� ��� ���Ĺ���̴�.\n");
	gotoxy(15, 8);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);
	gotoxy(15, 10);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	mergeSort(number, 0, num - 1);
}

int i = 0;
int z = 12;

// �� ����
int partition(int number[], int begin, int end, int num) {
	int pivot, L, R, t, temp;
	L = begin;
	R = end;
	pivot = (begin + end) / 2;

	gotoxy(25, z);
	printf("%d�ܰ� : pivot = %d", ++i, number[pivot]);

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
	printf("�� �����̶�? ���ؿ��Ҹ� �ϳ� �� �� �� ���ؿ��Ҹ� �߽����� \n");
	gotoxy(15, 6);
	printf("�� �۰ų� ���� ���� ��������, ū ���� ���������� ��ġ�Ͽ� �����ϴ� ����̴�.\n");
	gotoxy(15, 8);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);
	gotoxy(15, 10);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	quickSort(number, 0, num - 1, num);
}

//�� ����

void hib() {
	system("cls");
	int number[100];
	int y = 14;
	int num;
	int k, i;

	gotoxy(15, 5);
	printf("�� �����̶�? �ִ� �� Ʈ���� �ּ� �� Ʈ���� ������ �����ϴ� ����̴�.\n");
	gotoxy(20, 10);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);
	gotoxy(20, 12);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
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
		printf("���� �� �迭 : ");
		for (k = 0; k < 5; k++) {
			printf("%d ", number[k]);
		}
		y = y + 2;
		getchar();
	}
}

//��� ����

void gisu() {
	system("cls");
	int number[100];
	int num, k;
	gotoxy(20, 5);
	printf("��� �����̶�? ���� �ڸ������� ���Ͽ� ������ ���� ���� �˰���\n");
	gotoxy(20, 10);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);
	gotoxy(20, 12);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}
	int temp[10][10]; // 10���� ���ڸ� �����ϴ� �迭
	int max = number[0];
	for (k = 1; k < num; k++) {
		if (number[k] > max) {
			max = number[k];
		}
	}

	int maxDigit = 0; // �ִ� �ڸ��� ���
	while (max > 0) {
		max /= 10;
		maxDigit++;
	}

	int divisor = 1;
	for (int digit = 0; digit < maxDigit; digit++) {
		int count[10] = { 0 }; // �� �ڸ������� ī��Ʈ
		int output[100];      // ���ĵ� ����� ������ �迭

		// �� ���ڸ� �ش� �ڸ����� ���ڷ� ������ �迭�� ����
		for (k = 0; k < num; k++) {
			int currentDigit = (number[k] / divisor) % 10;
			temp[currentDigit][count[currentDigit]] = number[k];
			count[currentDigit]++;
		}

		int outputIndex = 0;

		// �� �н��� ��� ���
		gotoxy(20, 15);
		printf("�߰� ��� : ", digit + 1);
		for (k = 0; k < num; k++) {
			printf("%d ", number[k]);
		}

		// ī��Ʈ �迭�� �̿��� ���ĵ� ��� �迭�� ����ϴ�.
		for (int i = 0; i < 10; i++) {
			for (k = 0; k < count[i]; k++) {
				number[outputIndex] = temp[i][k];
				outputIndex++;
			}
		}

		divisor *= 10;
		getchar();
	}

	// ������ �н� ��� ���
	gotoxy(20, 19);
	printf("���� ���� ���: ");
	for (k = 0; k < num; k++) {
		printf("%d ", number[k]);
	}

	getchar();
}

//��� ����
void gesu() {
	system("cls");
	int number[100];
	int num;
	int k;
	gotoxy(15, 5);
	printf("��� �����̶�? �����͵��� ũ�⿡ ���� �������ִ� ���� �˰���\n");
	gotoxy(20, 10);
	printf("�Է��Ͻ� ������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);
	gotoxy(20, 12);
	printf("���� %d���� �Է��ϼ��� (����� �����մϴ�) : ", num);
	for (int k = 0; k < num; k++) {
		scanf_s("%d", &number[k]);
	}

	int max = number[0];
	for (k = 1; k < num; k++) {
		if (number[k] > max) {
			max = number[k];
		}
	}

	// �ִ� �� + 1 ũ���� ��� �迭�� �ʱ�ȭ
	int count[1001] = { 0 }; // �ִ� �� + 1�� ���� (����: �Է� ���ڰ� 1000 ����)

	// �Էµ� ������ �󵵼��� ��� �迭�� ���
	for (k = 0; k < num; k++) {
		count[number[k]]++;
	}

	int outputIndex = 0;

	// ��� �迭�� ������� ���ĵ� ����� ����
	for (k = 0; k <= max; k++) {
		while (count[k] > 0) {
			number[outputIndex] = k;
			outputIndex++;
			count[k]--;
		}
	}
	getchar();

	// ���� ���ĵ� ��� ���
	gotoxy(20, 15);
	printf("��� ���� ���: ");
	for (k = 0; k < num; k++) {
		printf("%d ", number[k]);
	}

	getchar(); // ��� Ȯ���� ���� ����� �Է� ���
}

//���ͽ�Ʈ�� �˰���
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

// �ּ� �Ÿ��� ���� ���� ������ ã�� ����
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

// �ִ� ��� ���ϴ� ������ ����ϴ� ����
int printStep(int step) {
	int i;
	printf("\n %3d�ܰ� : S = {", step);
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
	printf("*********** ����ġ ���� ��� ***********\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}
	printf("\n*********** ���ͽ�Ʈ�� �ִ� ��� ���ϱ� ***********\n");
	Dijkstra_shortestPath(0, MAX_VERTICES);
	getchar();
}

//���� �켱 Ž��
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

// ���� ������ ���� ��� ����ü
typedef struct stackNode {
	int data;
	struct stackNode* link;
} stackNode;

stackNode* top; // ���� ������ ������ top�� ����

// ������ ����ִ��� Ȯ���ϴ� ����
int isStackEmpty() {
	return top == NULL;
}

// ���ÿ� ���Ҹ� �߰��ϴ� ����
void push(int value) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = value;
	temp->link = top;
	top = temp;
}

// ���ÿ��� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
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

// ���� �׷����� �����ϴ� ����
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
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
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
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 'A');
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 'A');
			p = p->link;
		}
	}
}

// �׷��� g���� ���� v�� ���� ���� �켱 Ž�� ����
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL; // ���� �ʱ�ȭ
	push(v);
	g->visited[v] = TRUE;
	printf(" %c", v + 'A');
	// ������ ������ �ƴ� ���� ���� �켱 Ž�� �ݺ�
	while (!isStackEmpty()) {
		v = top->data;
		w = g->adjList_H[v];
		while (w) {
			if (!g->visited[w->vertex]) {
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 'A');
				break; // ���ÿ� ���ο� ������ push�ϰ� ��������Ƿ� �ݺ� �ߴ�
			}
			w = w->link;
		}
		if (w == NULL) {
			// ���� �������� �湮�� �� �ִ� ������ �� �̻� ������ pop
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
	printf("\n G9�� ���� ����Ʈ ");
	print_adjList(G9);
	printf("\n\n//////////////\n\n���� �켱 Ž�� >> ");
	DFS_adjList(G9, 0);
	getchar();
}

// �ʺ� �켱 Ž��
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
	printf("\n G9�� ���� ����Ʈ ");
	print_adjList(G9);
	printf("\n\n//////////////\n\n�ʺ� �켱 Ž�� >> ");
	BFS_adjList(G9, 0);
	getchar();
}

// �÷��̵� �ִ� ��� �˰���
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
	printf("\n *************** ����ġ ���� ��� ***************\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else
				printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}
	printf("\n *************** �÷��̵� �ִ� ��� ���ϱ� ***************\n\n");
	Floyd_shortestPath(MAX_VERTICES);
	getchar();
}

// ũ�罺Į �˰���
// ������ �θ� ã�� ���� �Լ�
int findParent(int parent[], int i) {
	if (parent[i] == -1)
		return i;
	return findParent(parent, parent[i]);
}

// �� ������ �ϳ��� ��ġ�� �Լ�
void unionVertices(int parent[], int x, int y) {
	int xSet = findParent(parent, x);
	int ySet = findParent(parent, y);
	parent[xSet] = ySet;
}

// ������ ��Ÿ���� ����ü
struct Edge {
	char src, dest;
	int weight;
};

// ������ ����ġ�� ���� ������������ �����ϴ� �� �Լ�
int compareEdges(const void* a, const void* b) {
	return ((struct Edge*)a)->weight < ((struct Edge*)b)->weight ? -1 : (((struct Edge*)a)->weight > ((struct Edge*)b)->weight);
}

// ũ�罺Į �˰��� �Լ�
void kruskal(struct Edge edges[], int V, int E) {
	// ������ ����ġ�� ���� ����
	qsort(edges, E, sizeof(edges[0]), compareEdges);

	// �θ� �迭 �ʱ�ȭ
	int* parent = (int*)malloc(V * sizeof(int));
	for (int i = 0; i < V; ++i)
		parent[i] = -1;

	// �� ������ ��Ʈ�� �����ϴ� �迭
	int* root = (int*)malloc(V * sizeof(int));
	for (int i = 0; i < V; ++i)
		root[i] = i;

	// �ּ� ��� ���� Ʈ���� ������ �迭
	struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
	int resultIndex = 0; // result �迭�� �߰��� ������ �ε���

	// ũ�罺Į �˰��� ����
	for (int i = 0; i < E; ++i) {
		struct Edge nextEdge = edges[i];

		int x = findParent(parent, nextEdge.src - 'A');
		int y = findParent(parent, nextEdge.dest - 'A');

		// ��Ʈ�� ������ ����Ŭ�� �����ǹǷ� ����
		if (root[x] != root[y]) {
			result[resultIndex] = nextEdge;
			unionVertices(parent, x, y);
			++resultIndex; // ��� �迭�� �ε��� ����
		}

	}

	// ��� ���
	printf("�ּ� ��� ���� Ʈ���� ����\n");
	for (int j = 0; j < resultIndex; ++j)
		printf("(%c, %c) ����ġ: %d\n", result[j].src, result[j].dest, result[j].weight);
	getchar();
	// �޸� ����
	free(parent);
	free(root);
	free(result);
}


void cru() {
	system("cls");
	// ������ ������ ������ ����
	int V = 7, E = 11;

	printf("\n");
	printf("ũ�罺Į �˰����̶� ��� ������ �ּ� �������\n");
	printf("�����Ͽ� �ּ� ���� Ʈ���� ���ϴ� �˰����̴�.\n\n");

	printf("|  ����ġ  |   ����  |\n");
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

	// �־��� ������ ����ġ
	struct Edge edges[] = {
		{'E', 'G', 2}, {'A', 'B', 3}, {'E', 'F', 4},
		{'B', 'D', 5}, {'A', 'D', 6}, {'C', 'F', 8},
		{'D', 'E', 9}, {'C', 'E', 10}, {'B', 'G', 12},
		{'F', 'G', 14}, {'A', 'C', 17}
	};

	// ũ�罺Į �˰��� ȣ��
	kruskal(edges, V, E);
	getchar();
}

// �����˰���
#define V 7

// �ּ� �Ÿ��� ã�� �Լ�
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

// �����˰��� ����
// �ּ� ��� ���� Ʈ���� �����ϴ� �Լ�
void primMST(struct Edge edges[], int E) {
	int parent[V];  // MST�� ���Ե� ������ �θ�
	int key[V];     // �ش� ���������� �ּ� �Ÿ�
	int mstSet[V];  // MST�� ���Ե� �������� ����

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

	// ��� ���
	printf("�ּ� ��� ���� Ʈ���� ����\n");
	for (int i = 1; i < V; i++)
		printf("(%c, %c) ����ġ: %d\n", parent[i] + 'A', i + 'A', key[i]);
	getchar();
}

// ������ ��Ÿ���� ����ü
struct Edge1 {
	char src, dest;
	int weight;
};

void prim() {
	system("cls");

	printf("\n");
	printf("���� �˰����� ũ�罺Į �˰���ó�� �̸� ������ �������� �ʰ� \n");
	printf("�ϳ��� �������� �����Ͽ� Ʈ���� Ȯ���� ������ ����̴�.\n\n");

	printf("|  ����ġ  |   ����  |\n");
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

// ���� ����

#define MAX_NODES 6

// �׷����� ��� ����ü
typedef struct Node {
	int value;
	struct Node* next;
} Node;

// �׷����� ���� ����ü
typedef struct {
	int inDegree;   // ���� ����
	Node* head;     // ���� ����Ʈ�� ���
} Vertex;

// ���� ����
Vertex graph[MAX_NODES];
char tasks[][20] = { "���� �� �ױ�", "��ȭ", "������ ���", "��� �ֱ�", "���� �ֱ�", "��� Ǯ��ֱ�" };
char result[MAX_NODES][20];
int resultIndex = 0;

// ������ �׷����� �߰��ϴ� �Լ�
void addEdge(int from, int to) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = to;
	newNode->next = graph[from].head;
	graph[from].head = newNode;
	graph[to].inDegree++;
}

// ���� ���� �˰���
// �׷��� ���� ��� �Լ�
void printGraphState(int numNodes) {
	printf("�׷��� ����\n\n");
	for (int i = 0; i < numNodes; ++i) {
		printf("%d. %s (���� ����: %d)\n", i + 1, tasks[i], graph[i].inDegree);
	}
	printf("\n");
}

// ���� ���� �˰���
void topologicalSort(int numNodes) {
	int queue[MAX_NODES];
	int front = 0, rear = -1;

	// ���� ������ 0�� ������ ť�� ����
	for (int i = 0; i < numNodes; ++i) {
		if (graph[i].inDegree == 0) {
			queue[++rear] = i;
		}
	}

	// ť���� ������ �����鼭 ���� ���� ����
	while (front <= rear) {
		int current = queue[front++];

		// ��� �迭�� �߰�
		for (int i = 0; tasks[current][i] != '\0'; ++i) {
			result[resultIndex][i] = tasks[current][i];
		}
		result[resultIndex++][strlen(tasks[current])] = '\0';

		// ����� �������� ���� ���� ����
		Node* temp = graph[current].head;
		while (temp != NULL) {
			int neighbor = temp->value;
			graph[neighbor].inDegree--;

			// ���� ������ 0�� �Ǹ� ť�� ����
			if (graph[neighbor].inDegree == 0) {
				queue[++rear] = neighbor;
			}

			temp = temp->next;
		}
	}

	// ��� ���
	printf("���� ����\n\n");
	for (int i = 0; i < numNodes; ++i) {
		printf("%d. %s\n", i + 1, result[i]);
	}
	getchar();
	printf("\n");
}

void topology() {
	system("cls");

	printf("\n");
	printf("���� ������ ������ �������ִ� �۾��� ���ʴ�� \n");
	printf("�����ؾ� �� �� �� ������ �������ֱ� ���� ����ϴ� �˰����̴�.\n\n");

	// �׷��� �ʱ�ȭ
	int numNodes = 6;
	for (int i = 0; i < numNodes; ++i) {
		graph[i].inDegree = 0;
		graph[i].head = NULL;
	}


	// ���� �߰�
	addEdge(2, 0);
	addEdge(0, 1);
	addEdge(2, 3);
	addEdge(1, 4);
	addEdge(3, 4);
	addEdge(4, 5);

	// �׷��� ���� ���
	printGraphState(numNodes);

	// ���� ���� ����
	topologicalSort(numNodes);
}

// A* �˰���
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
			printf("�����: (%d, %d)\n", startCoord.x, startCoord.y);
			printf("������: (%d, %d)\n", goalCoord.x, goalCoord.y);
			printf("����:\n");
			printMapWithPoints(currentNode);
			printf("\n������ ���: ");
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
	printf("A*�˰����̶� ����ڰ� ������ ������� �������� �����ϴ� ��� ��\n");
	printf("���� ������ ��θ� ã���ִ� �˰����̴�.\n\n");
	runAStar();
	getchar();
}

// �ؽ� ���̺�
#define TABLE_SIZE 100

// �ؽ� ��� ����ü ����
typedef struct hashNode {
	char key[50];
	int value;
	struct hashNode* next;
} hashNode;

// �ؽ� ���̺� ����ü ����
typedef struct HashTable {
	hashNode* table[TABLE_SIZE];
} HashTable;

// ���ڿ� �ؽ� �Լ�
int hashFunction(const char* key) {
	int hash = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		hash = (hash * 31 + key[i]) % TABLE_SIZE;
	}
	return hash;
}

// ���ڿ� ���� �Լ�
void custom_strcpy(char* destination, const char* source) {
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

// �ؽ� ���̺� �ʱ�ȭ
void initHashTable(HashTable* ht) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		ht->table[i] = NULL;
	}
}

// �ؽ� ���̺� Ű-�� �� �߰�
void insert(HashTable* ht, const char* key, int value) {
	int index = hashFunction(key);

	// ���ο� ��� ����
	hashNode* newNode = (hashNode*)malloc(sizeof(hashNode));
	custom_strcpy(newNode->key, key);
	newNode->value = value;
	newNode->next = NULL;

	// ü�̴��� �̿��Ͽ� ��� �߰�
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

// �ؽ� ���̺��� Ű�� �����ϴ� �� ã��
int search(HashTable* ht, const char* key) {
	int index = hashFunction(key);
	hashNode* current = ht->table[index];

	// ü�̴��� ���� ����� ������ Ž��
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return current->value;
		}
		current = current->next;
	}

	// �ش� Ű�� ���� ���� ���� ���
	return -1;
}

void hash() {
	system("cls");
	printf("\n");
	printf("�ؽ� ���̺��̶� �ؽ��Լ��� ����Ͽ� ��ȯ�� ���� �ε����� ���\n");
	printf("Ű�� �����͸� �����ϴ� �ڷᱸ���� ���Ѵ�.\n\n");

	HashTable ht;
	initHashTable(&ht);

	insert(&ht, "apple", 5);
	insert(&ht, "banana", 8);
	insert(&ht, "orange", 3);

	printf("Ű 'apple'�� ���� ��: %d\n", search(&ht, "apple"));
	printf("Ű 'banana'�� ���� ��: %d\n", search(&ht, "banana"));
	printf("Ű 'orange'�� ���� ��: %d\n", search(&ht, "orange"));
	printf("Ű 'grape'�� ���� ��: %d\n", search(&ht, "grape"));
	getchar();
}

// ��Ʈ��ŷ ��Ž�� �˰���
#define N 8

void printSolution(int board[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%2d ", board[i][j]);
		printf("\n");
	}
	printf("\n����Ű�� ��������.\n");
	getchar(); // ����� �Է� ���
}

bool isSafe(int board[N][N], int row, int col) {
	// ���� �࿡ ���� �ִ��� �˻�
	for (int i = 0; i < col; i++)
		if (board[row][i])
			return false;

	// ���� �� �밢���� ���� �ִ��� �˻�
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// ���� �Ʒ� �밢���� ���� �ִ��� �˻�
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

			board[i][col] = 0; // ��Ʈ��ŷ
		}
	}

	return false;
}

void solveNQueens() {
	int board[N][N] = { 0 };

	if (!solveNQueensUtil(board, 0)) {
		printf("�� ����\n");
		return;
	}

	printSolution(board);
}

void back() {
	system("cls");
	printf("\n");
	printf("��Ʈ��ŷ�̶� �ظ� ã�� ���� ������ ���� �ܰ�� �ǵ��ư���\n");
	printf("�ٽ� �ظ� ã�ư��� ����� ���Ѵ�.\n\n");
	int initialBoard[N][N] = { 0 };
	printf("�ʱ������ ����\n\n");
	printSolution(initialBoard);  // �ʱ� ������ ���� ���
	solveNQueens();
}

// Ʈ�� ���� �˰���

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
	printf("\n ã�� Ű�� �����ϴ�!");
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
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

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
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
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
	printf("\n������ ���� : ");
	for (i = 0; i < size; i++) printf("%3d", list[i]);
	printf("\n <<<<< Ʈ�� ���� ���� >>>>> \n\n");
	treeSort(list, size);
	getchar();
}

// ������ �˰���
#define POPULATION_SIZE 10
#define GENE_LENGTH 8
#define MUTATION_RATE 0.1

// ��ü ����ü ����
typedef struct {
	int genes[GENE_LENGTH];
	int fitness;
} Individual;

// �ʱ� ��ü ����
void initializePopulation(Individual population[]) {
	for (int i = 0; i < POPULATION_SIZE; ++i) {
		for (int j = 0; j < GENE_LENGTH; ++j) {
			population[i].genes[j] = rand() % 2; // 0 �Ǵ� 1�� ������ �ʱ� ������
		}
	}
}

// ���յ� �� �Լ� (����: ��Ʈ�� 1�� ����)
void calculateFitness(Individual* individual) {
	individual->fitness = 0;
	for (int i = 0; i < GENE_LENGTH; ++i) {
		if (individual->genes[i] == 1) {
			individual->fitness++;
		}
	}
}

// ���� �Լ� (�귿 �� ����)
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

	return 0; // ���� �߻� �� �⺻��
}

// ���� �Լ� (�� ���� ����)
void crossover(Individual* parent1, Individual* parent2, Individual* child) {
	int crossoverPoint = rand() % GENE_LENGTH;

	for (int i = 0; i < crossoverPoint; ++i) {
		child->genes[i] = parent1->genes[i];
	}

	for (int i = crossoverPoint; i < GENE_LENGTH; ++i) {
		child->genes[i] = parent2->genes[i];
	}
}

// �������� �Լ�
void mutate(Individual* child) {
	for (int i = 0; i < GENE_LENGTH; ++i) {
		if ((double)rand() / RAND_MAX < MUTATION_RATE) {
			child->genes[i] = !child->genes[i]; // 0�� 1��, 1�� 0���� ��ȯ
		}
	}
}

void genetic() {
	system("cls");
	printf("\n");
	printf("������ �˰����̶� ����ü�� ȯ�濡 �����ϸ鼭 ��ȭ�س����� �����\n");
	printf("����Ͽ� �����ظ� ã�Ƴ��� �˻� ����̴�.\n\n");

	printf("����Ű�� �������� ! \n\n");

	srand(time(NULL));

	Individual population[POPULATION_SIZE];
	Individual newPopulation[POPULATION_SIZE];

	initializePopulation(population);

	// ���� �˰��� �ݺ� ����
	for (int generation = 0; generation < 100; ++generation) {
		// �� ��ü�� ���յ� ��
		for (int i = 0; i < POPULATION_SIZE; ++i) {
			calculateFitness(&population[i]);
		}

		// ���ο� ���� ����
		for (int i = 0; i < POPULATION_SIZE; ++i) {
			// �θ� ����
			int parent1Index = selectParent(population);
			int parent2Index = selectParent(population);

			// ����
			crossover(&population[parent1Index], &population[parent2Index], &newPopulation[i]);

			// ��������
			mutate(&newPopulation[i]);
		}

		// ���ο� ���븦 ���� ����� ��ü
		for (int i = 0; i < POPULATION_SIZE; ++i) {
			population[i] = newPopulation[i];
		}

		// ���� ���� ���ݸ��� ��� ���
		if (generation % 10 == 0) {
			// ���� ������ ������ ���
			int maxFitness = 0;
			for (int i = 1; i < POPULATION_SIZE; ++i) {
				if (population[i].fitness > population[maxFitness].fitness) {
					maxFitness = i;
				}
			}

			printf("����: %d, ������: ", generation);
			for (int i = 0; i < GENE_LENGTH; ++i) {
				printf("%d", population[maxFitness].genes[i]);
			}
			printf(", ���յ�: %d\n", population[maxFitness].fitness);

			getchar(); // ����� �Է� ���
		}
	}
}
// ���� ���� Ʈ��
// ������ ���� ���� ���� ���� ��� ����ü
typedef struct StateNode {
	int value;
	struct StateNode* left;
	struct StateNode* right;
} StateNode;

// ���ο� ���� ��� ����
StateNode* createStateNode(int value) {
	StateNode* newNode = (StateNode*)malloc(sizeof(StateNode));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// ���� ���� Ʈ�� ��� (���� ��ȸ)
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
	printf("���� ���� Ʈ���� ������ �ذ��ϱ� ���� ��� ���µ���\n");
	printf("��Ÿ���� Ʈ��������\n\n");

	StateNode* root = createStateNode(1);
	root->left = createStateNode(2);
	root->right = createStateNode(3);
	root->left->left = createStateNode(4);
	root->left->right = createStateNode(5);
	root->right->left = createStateNode(6);

	// ���� ���� Ʈ�� ��� (�ʱⰪ)
	printf("�ʱ� ���� ���� Ʈ��: ");
	printStateSpaceTree(root);
	printf("\n\n");

	// ���� ���� Ʈ�� ��� (���� ��ȸ)
	printf("���� ��ȸ ���: ");
	printStateSpaceTree(root);
	printf("\n");

	// �޸� ����
	free(root->left->left);
	free(root->left->right);
	free(root->right->left);
	free(root->left);
	free(root->right);
	free(root);

	getchar(); // ���α׷��� ������� �ʵ��� getchar() �߰�
}

// ���ڿ� �˰���
// �ִ� ���ڿ� ����
#define MAX_LENGTH 100

// �ִ� �Լ� ����
#define max(a, b) ((a) > (b) ? (a) : (b))

// ���� ���� �κ� ���ڿ� ã�� �Լ�
void longestCommonSubstring(char str1[], char str2[]) {
	int m = strlen(str1);
	int n = strlen(str2);

	// dp �迭 �ʱ�ȭ
	int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];
	int result = 0;  // ���� ���� �κ� ���ڿ��� ����
	int endIdx = 0;  // ���� ���� �κ� ���ڿ��� �� �ε���

	// dp �迭 ���
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

	// ��� ���
	printf("���� ���� �κ� ���ڿ�: ");
	for (int i = endIdx - result + 1; i <= endIdx; i++)
		printf("%c", str1[i]);
	printf("\n");
	getchar();
}

void mon() {
	system("cls");
	printf("\n");
	printf("���ڿ� �˰����̶� �� ���ڿ��� �־����� �� \n");
	printf("���� ���� �κ� ���ڿ��� ã�� �˰����̴�.\n\n");

	// �� ���ڿ� �Է�
	char str1[MAX_LENGTH], str2[MAX_LENGTH];
	printf("ù ��° ���ڿ� �Է�: ");
	scanf_s("%s", str1, sizeof(str1));
	printf("\n");
	printf("�� ��° ���ڿ� �Է�: ");
	scanf_s("%s", str2, sizeof(str2));
	printf("\n");


	// ���� ���� �κ� ���ڿ� ã��
	longestCommonSubstring(str1, str2);
	getchar(); // ���α׷��� �ٷ� ������� �ʵ��� getchar() �߰�
}

// w Ű�� ������ UP, s Ű�� ������ DOWN, ����Ű�� ������ SUBMIT
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
