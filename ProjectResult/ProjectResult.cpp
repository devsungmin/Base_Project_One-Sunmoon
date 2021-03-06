/* 기초 프로젝트I
프로젝트명 : 종합프로젝트
조 번호 : 5조
개발자 : 김성민, 이재문, 최준혁
개발 일자 : 18.04.10 ~ 18.04.11
프로그램 설명 : 데이터를 이용한 소수 판별,swap,데이터 저장후 max.min값 구하기, 데이터 저장후 평균과 표준 편차 구하기, *찍기
기능 구현
- 1,2번 : 최준혁
- 3,4번 : 이재문
- 5번, 콘솔 디자인 : 김성민
*/
#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "windows.h"
void gotoxy(int x, int y);
void prog(); //프로그램 초기 화면
void starm();//별찍기 메뉴 선택
void starlist(); //별찍기 리스트
void langt();//왼쪽 직각 삼격형 
void rangt();//오른쪽 직각 삼각형
void isot();//이등변 삼각형
void dia();//다이아 몬드
void pin();//바람개비
void sosu(); //소수 구별
void con(); //종료
void swapprogram(); //swap 메인 함수
void swap(int *a, int *b); //swap 포인터 함수
void sam(); //평균과 표준편차 메인 함수
void samyeon(int n); //평균값과 표준 편차 구하는 함수
void fouryeon(int n); //최댓값과 최솟값을 구하는 함수
void four(); // 최댓값과 최솟값 메인함수

/*메인 함수*/
int main()
{
	int num = 0;
	prog();
	system("pause");
	while (num != 6) {
		
		system("cls");
		printf("\t=======================================================\n");
		printf("\t1.소수 판별 하기\n\n");
		printf("\t2.데이터값 Swap하기\n\n");
		printf("\t3.n개의 데이터를 배열의 저장후 평균과 표준편차 구하기\n\n");
		printf("\t4.n개의 데이터를 배열에 저장후 최댓값과 최솟값 구하기\n\n");
		printf("\t5.입력한 수만큼 ☆로 트리 만들기\n\n");
		printf("\t6.프로그램 종료\n\n");
		printf("\t======================================================\n\n\t>");
		scanf_s("%d", &num);
		switch (num) {

		case 1:

			sosu();
			break;
		case 2:

			swapprogram();
			break;
		case 3:
			sam();
			break;
		case 4:

			four();
			break;
		case 5:
			system("cls");
			starm();
			printf("\t");
			
			system("cls");
			break;
		case 6:
			system("cls");
			printf("\n\t프로그램을 종료합니다.\n\n\t");
			break;
		}
	}

	return 0;
}

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

/*프로그램 초기 화면*/
void prog()
{
	int x = 36;
	int y = 2;
	gotoxy(20, 0);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	for (int i = 1; i < 33; i++) {
		gotoxy(20,i);
		printf("||");
		gotoxy(90, i);
		printf("||");
	}
	gotoxy(x, y);
	printf("〓〓〓〓〓프로젝트명: 종합프로젝트〓〓〓〓〓");
	gotoxy(x, 4);
	printf("조 번호 : 5조");
	gotoxy(x, 6);
	printf("개발자 : 김성민, 이재문, 최준혁");
	gotoxy(x, 8);
	printf("개발 일자 : 18.04.10 ~18.04.11");
	gotoxy(x, 10);
	printf("〓〓〓〓프로그램 설명〓〓〓〓");
	gotoxy(x, 12);
	printf("1. 데이터를 이용한 소수 판별");
	gotoxy(x, 14);
	printf("2. 입력 받은 두수의 출력값을 swap");
	gotoxy(x, 16);
	printf("3.데이터 저장후 max.min값 구하기");
	gotoxy(x, 18);
	printf("4.데이터 저장후 평균과 표준 편차 구하기");
	gotoxy(x, 20);
	printf("5.*찍기");
	gotoxy(x, 22);
	printf("〓〓〓〓〓기능 구현〓〓〓〓");
	gotoxy(x, 24);
	printf("- 1, 2번 : 최준혁");
	gotoxy(x, 26);
	printf("- 3, 4번 : 이재문");
	gotoxy(x, 28);
	printf("- 5번, 콘솔 디자인 : 김성민");
	gotoxy(x, 30);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(20, 32);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(x, 34);
}

/*소수 구별*/
void sosu() {
	int a, num = -1;
	while (num != 0) {
		system("cls");
		printf("\t===============================================\n\n");
		printf("\t선택하신 메뉴는 소수를 판별하는 프로그램입니다.\n\n");
		printf("\t==================메뉴=========================\n\n");
		printf("\t0.이전 메뉴로\n\n\t1.프로그램 실행\n\n\t===============================================\n\t>");
		scanf_s("%d", &num);
		if (num == 1) {
			printf("\t소수 판별할 숫자 입력 :");
			scanf_s("%d", &a);

			if (a != 1) {

				if (a == 2 || a == 3 || (a % 2 != 0 && a % 3 != 0))
				{

					printf("\n\t입력하신 숫자 : %d는 소수 입니다.\n", a);
				}
				else if (a % 2 == 0 || a % 3 == 0)
				{
					printf("\n\t입력하신 숫자 :%d는 소수가 아닙니다.\n", a);
				}
			}
			else {
				printf("\n\t입력하신 숫자 :%d는 소수가 아닙니다.\n", a);
			}
			printf("\n\t");
			//system("pause");
			con();
		}
		else if (num == 0) {
			system("cls");
			printf("\n\t초기메뉴로 돌아갑니다.\n\n\t");
			system("pause");
		}
		else
		{
			system("cls");
			printf("\n\n\t잘못된 입력입니다. 다시 입력해주세요.\n\n\t");
			system("pause");
		}
	}
}

/*swap 포인터*/
void swap(int *a, int *b) {

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

/*swap 메인 함수*/
void swapprogram() {
	int a, b,num=-1;
	while (num!=0) {
		system("cls");
		printf("\t====================================================\n\n");
		printf("\t이 프로그램은 데이터 값을 SWAP해주는 프로그램입니다.\n\n");
		printf("\t====================================================\n\n");
		printf("\t==================메뉴==================\n\n");
		printf("\t0.초기메뉴로\n\n\t1.프로그램 실행\n\n");
		printf("\t========================================\n\n\t>");
		scanf_s("%d", &num);
		if (num == 0) {
			system("cls");
			printf("\n\t초기메뉴로 돌아갑니다.\n\n\t");
			system("pause");
		}
		else if (num == 1) {
			system("cls");
			printf("\n\n\t스왑할 첫번째 정수 입력:");
			scanf_s("%d", &a);
			printf("\n");
			printf("\t스왑할 두번째 정수 입력:");
			scanf_s("%d", &b);
			printf("\n\t=================결과값================\n");
			printf("\n\t스왑전 a = %d\tb = %d\n\n", a, b);
			swap(&a, &b);
			printf("\t스왑후 a = %d\tb = %d\n\n", a, b);
			printf("\t========================================\n");
			con();
		}
		else
		{
			system("cls");
			printf("\n\n\t잘못된 입력입니다. 다시 입력해주세요.\n\n\t");
			system("pause");
		}
	}
}

/*종료*/
void con() {
	char a='0';
	while (a != NULL) {
		printf("\n\t종료 : Y 또는 y / 계속 : N 또는 n\n\n");
		printf("\t종료하시겠습니까?\n\t>");
		scanf_s(" %c", &a);

		if (a == 'y' || a == 'Y') {
			printf("\n\t프로그램을 종료합니다.\n\t\n");
			exit(0);
		}
		else if (a == 'N' || a == 'n') {
			system("cls");
			a = NULL;
			getchar();
		}
		else
		{
			system("cls");
			printf("\n\t잘못입력 하셨습니다.\n\n");
			


		}
	}
}

/*평균과 표준편차 메인 함수*/
void sam() {
	int n,num=-1;

	while (num!=0) {
		system("cls");
		printf("\t==========================================\n");
		printf("\t선택하신 메뉴는 n개의 데이터를\n\n\t입력받아 배열에 저장한 후\n\n\t평균과 표준편차를 구하는 프로그램입니다.\n");
		printf("\t==========================================\n\n");
		printf("\t==================메뉴==================\n\n");
		printf("\t0.초기메뉴로\n\n\t1.프로그램 실행\n\n");
		printf("\t========================================\n\n\t>");
		scanf_s("%d", &num);
		if (num == 0) {
			system("cls");
			printf("\n\t초기메뉴로 돌아갑니다.\n\n\t");
			system("pause");
		}
		else if (num == 1) {
			system("cls");
			printf("\n\n\t입력받을 데이터 수를 입력해주세요.\n\t>");
			scanf_s("%d", &n);
			samyeon(n);
		}
		else
		{
			system("cls");
			printf("\n\n\t잘못된 입력입니다. 다시 입력해주세요.\n\n\t");
			system("pause");
		}

	}
}

/*평균과 표준 편차 구하는 함수*/
void samyeon(int n) {
	int num[100], sum = 0;
	int i;
	double avg, p, v = 0, sum2;

	for (i = 0; i < n; i++) {
		printf("\t데이터 입력 :");
		scanf_s("%d", &num[i]);
	}

	for (i = 0; i < n; i++) {
		sum = sum + num[i];
	}
	avg = (double)sum / (double)n;
	for (i = 0; i < n; i++) {
		sum2 = ((double)num[i] - avg)*((double)num[i] - avg);       //표준편차 구하는 법
		v += (sum2) / n;
	}
	p = sqrt(v);
	printf("\n\t==================결과값====================\n");
	printf("\n\t입력하신 데이터의 평균 :%g\t표준편차 : %g\n", avg, p);
	printf("\n\t============================================\n\t");
	con();

}

/*최댓값과 최솟값 메인 함수*/
void four() {
	int n,num=-1;
	printf("");
	while (num!=0) {
		system("cls");
		printf("\t=======================================\n");
		printf("\t선택하신 메뉴는 n개의 데이터를\n\n\t입력받아 배열에 저장한 후\n\n\t최대값 최소값을 구하는 프로그램입니다.\n\n");
		printf("\t=======================================\n\n");
		printf("\t==================메뉴==================\n\n");
		printf("\t0.초기메뉴로\n\n\t1.프로그램 실행\n\n");
		printf("\t========================================\n\n\t>");
		scanf_s("%d", &num);
		if (num == 0) {
			system("cls");
			printf("\n\t초기메뉴로 돌아갑니다.\n\n\t");
			system("pause");
		}
		else if (num == 1) {
			system("cls");
			printf("\n\n\t입력받을 데이터 수를 입력해주세요.\n\t>");
			scanf_s("%d", &n);
			fouryeon(n);
		}
		else
		{
			system("cls");
			printf("\n\n\t잘못된 입력입니다. 다시 입력해주세요.\n\n\t");
			system("pause");
		}
	}

}

/*최댓값과 최솟값 구하는 함수*/
void fouryeon(int n) {
	int num[100], max, min, i;

	for (i = 0; i < n; i++) {
		printf("\t데이터 입력 :");
		scanf_s("%d", &num[i]);
	}
	min = num[0];
	max = num[0];
	for (i = 0; i < n; i++) {
		if (min > num[i]) {
			min = num[i];
		}
		if (max < num[i]) {
			max = num[i];
		}
	}
	printf("\n\t=====결과값=====\n");
	printf("\n\tMin = %d\t Max = %d\n", min, max);
	printf("\n\t================\n");
	con();
}

/*별찍기 메뉴 선택*/
void starm()
{
	int num = -1;
	while (num != 0) {
		starlist();
		printf("\t어떠한 종류의 별을 출력할까요? : ");
		scanf_s("%d", &num);
		printf("\n");
		switch (num)
		{
		case 0:
			system("cls");
			printf("\n\t초기 메뉴로 돌아갑니다.\n\n\t");
			system("pause");
			break;
		case 1:
			langt();
			system("pause");
			break;
		case 2:
			rangt();
			system("pause");
			break;
		case 3:
			isot();
			system("pause");
			break;
		case 4:
			dia();
			system("pause");
			break;
		case 5:
			pin();
			system("pause");
			break;
		
		}
		system("cls");
	}

}

/*별 리스트*/
void starlist()
{
	printf("\t========================================\n");
	printf("\t\t별찍기 프로그램\n");
	printf("\t========================================\n\n");
	printf("\t=======================================\n");
	printf("\t0.메인 메뉴로 돌아가기\n\n");
	printf("\t1.왼쪽 직각 삼각형 \n\n"); //mstar
	printf("\t2.오른쪽 직각 삼각형\n\n"); //mtstar
	printf("\t3.이등변 삼각형\n\n");
	printf("\t4.다이아 몬드\n\n");
	printf("\t5.바람개비\n\n");
	printf("\t=======================================\n\n");
}

/*왼쪽 직각 삼각형*/
void langt()
{
	int num = 0;
	int i = 0, j = 0;
	printf("\t마지막줄을 몇개를 출력할까요? : ");
	scanf_s("%d", &num);
	system("cls");
	printf("\n\t======결과값======\n");
	printf("\n");
	for (i = 0; i < num; i++)
	{
		printf("\t\t");
		for (j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	printf("\n\n\t");
}

/*오른쪽 이등변별찍기*/
void rangt()
{
	int num = 0;
	int i = 0, j = 0;
	printf("\t마지막줄을 몇개를 출력할까요? : ");
	scanf_s("%d", &num);
	system("cls");
	printf("\n\t======결과값======\n");
	printf("\n");
	for (i = 0; j < num; i++)
	{
		printf("\t\t");
		for (j = 0; j < num - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n\t");
}

/*이등변 삼각형*/
void isot()
{
	int num = 0;
	int i = 0, j = 0;
	printf("\t마지막줄을 몇개를 출력할까요? : ");
	scanf_s("%d", &num);
	system("cls");
	printf("\n\t\t======결과값======\n");
	printf("\n");
	for (i = 1; j < num; i++)
	{
		printf("\t\t");
		for (j = 1; j < num - i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n\t");
}

/*다이아 몬드*/
void dia()
{
	int i, j, k;
	int num = 0;
	printf("\t마지막줄을 몇개를 출력할까요? : ");
	scanf_s("%d", &num);
	system("cls");
	printf("\n\t======결과값======\n");
	printf("\n");

	for (i = 0; i < num; i++)
	{
		printf("\t");
		for (k = 0; k <(num - i - 1); k++)
			printf(" ");
		for (j = 0; j < (2 * i+1); j++)
			printf("*");

		printf("\n");
	}

	for (i = num - 2; i >= 0;i--)
	{
		printf("\t");
		for (k = 0; k < (num - i - 1); k++)
			printf(" ");
		for (j = 0; j < (2 * i + 1); j++)
			printf("*");

		printf("\n");
	}
	printf("\n\t");
}

/*바람개비*/
void pin()
{
	int i, j, k;
	int num = 0;
	printf("\t마지막줄을 몇개를 출력할까요? : ");
	scanf_s("%d", &num);
	system("cls");
	printf("\n\t======결과값======\n\n");

	for (i = 0; i < num; i++)
	{
		printf("\t");
		for (j = 0; j < i; j++)
			printf(" ");
		for (k = num; k > i; k--)
			printf("*");
		for (j = num; j > i; j--)
			printf(" ");
		for (k = 0; k <= i; k++)
			printf("*");

		printf("\n");
	}
	for (i = 0; i < num; i++)
	{
		printf("\t");
		for (j = num; j > i; j--)
			printf("*");
		for (k = 0; k <= i; k++)
			printf(" ");
		for (j = 0; j <= i; j++)
			printf("*");
		for (k = num; k > i; k--)
			printf(" ");

		printf("\n");
	}
	printf("\n\t");
}