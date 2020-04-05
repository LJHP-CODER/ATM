#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define cls system("cls") // system함수를 하나하나씩 사용하기 힘드니 간단히 cls로 이 프로그램 어느 함수에서나 사용 가능하게 만들어 준다.
#define pause system("pause > nul") // 위에 와 같이 선언을 해준다.

struct money_manage { // 은행에 있는 돈을 관리하는 변수들을 선언할 구조체이다.
	int long long Bank_cash; // 은행에 있는 전체의 돈 
	int input_money; // 돈을 은행에 얼마나 넣을지 뺄건지 입력받는 변수이다.
	int input_add_cash;
};

struct member { // member(회원)의 정보들을 모아 놓은 구조체이다.
	char name[20]; // 이름
	char ID[20]; // 아이디
	char PW[20]; // 패스워드
	int input_cash;
	char saveID; // 아이디를 저장할 것인지 말것인지 정한다.
	int save; // 아이디 저장 설정값 (1)은 저장 (0)은 no 저장
};

struct card_manage {
	char card_name[10]; // 랜덤 이름을 저장할 변수
	int long cash; // 모든 현금을 저장하는 공간
	int Card_num; // 카드 번호
	char cc;
	int c;
};


struct member m; // 구조체 member을 main함수에서 사용할수 있도록 m을 만든다.
struct money_manage mm; // 구조체 money_manage를 main함수에서 사용할수 있도록 mm을 만든다.
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