#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define cls system("cls") // system�Լ��� �ϳ��ϳ��� ����ϱ� ����� ������ cls�� �� ���α׷� ��� �Լ������� ��� �����ϰ� ����� �ش�.
#define pause system("pause > nul") // ���� �� ���� ������ ���ش�.

struct money_manage { // ���࿡ �ִ� ���� �����ϴ� �������� ������ ����ü�̴�.
	int long long Bank_cash; // ���࿡ �ִ� ��ü�� �� 
	int input_money; // ���� ���࿡ �󸶳� ������ ������ �Է¹޴� �����̴�.
	int input_add_cash;
};

struct member { // member(ȸ��)�� �������� ��� ���� ����ü�̴�.
	char name[20]; // �̸�
	char ID[20]; // ���̵�
	char PW[20]; // �н�����
	int input_cash;
	char saveID; // ���̵� ������ ������ �������� ���Ѵ�.
	int save; // ���̵� ���� ������ (1)�� ���� (0)�� no ����
};

struct card_manage {
	char card_name[10]; // ���� �̸��� ������ ����
	int long cash; // ��� ������ �����ϴ� ����
	int Card_num; // ī�� ��ȣ
	char cc;
	int c;
};


struct member m; // ����ü member�� main�Լ����� ����Ҽ� �ֵ��� m�� �����.
struct money_manage mm; // ����ü money_manage�� main�Լ����� ����Ҽ� �ֵ��� mm�� �����.
struct card_manage cm;

void draw_main();
void ran();

void login();
void signup();
void deposit();
void withdraw();
void ID_load();
void Remember_data();
void save();
void add_cash();
void Get_card();
void Put_card();
void reset();
void check();
void choice_error();