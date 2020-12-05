#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define cls system("cls")
#define pause system("pause > nul")

struct money_manage { 
	int long long Bank_cash;
	int input_money;
	int input_add_cash;
};

struct member {
	char name[20];
	char ID[20];
	char PW[20];
	int input_cash;
	char saveID;
	int save;
};

struct card_manage {
	char card_name[10];
	int long cash;
	int Card_num;
	char cc;
	int c;
};


struct member m;
struct money_manage mm;
struct card_manage cm;

void draw_main();
void Create_Cardname();

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