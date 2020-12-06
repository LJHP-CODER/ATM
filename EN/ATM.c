#include "ATM.h"

char input_ID[20];
char input_PW[20];
char choice;

char filename[50] = "";

void Create_Cardname(){
	int i;

	for (i = 0; i < 5; i++){
		cm.card_name[i] = (rand() % 26 + 65);
	}
}

int main(){
	system("title ATM Machine");
	system("mode con: cols=63 lines=19");
	system("color 1F");

	m.save = 0;
	mm.Bank_cash = 0;

	srand(time(NULL));
	cm.c = 0; 
	

	while (1){
		draw_main();
		choice = _getch();
		//------------------------Login------------------------
		if (choice == 'l') {
			cls;
			login();
		}
		//------------------------Sign up------------------------
		else if (choice == 's') {
			cls;
			signup();
		}
		//------------------------Deposit------------------------
		else if (choice == 'd') {
			cls;
			deposit();
		}
		//------------------------Withdraw------------------------
		else if (choice == 'w') {
			cls;
			withdraw();
		}
		//------------------------ID_load------------------------
		else if (choice == 'i') {
			cls;
			ID_load();
		}
		//------------------------Add_cash------------------------
		else if (choice == 'a') {
			cls;
			add_cash();
		}
		//------------------------Remember_data------------------------
		else if (choice == 'r') {
			cls;
			Remember_data();
		}
		//------------------------Get_card------------------------
		else if (choice == 'g') {
			cls;
			Get_card();
		}
		//------------------------Put_card------------------------
		else if (choice == 'p') {
			cls;
			Put_card();
		}
		//------------------------all_reseT------------------------
		else if (choice == 't') {
			cls;
			reset();
		}
		//------------------------Check------------------------

		else if (choice == 'c') {
			cls;
			check();
		}
		//------------------------Exit------------------------
		else if (choice == 'e') {
			cls;
			break;
		}
		//------------------------Choice error------------------------
		else {
			cls;

			choice_error();
		}
	}
}
//------------------------Draw_main------------------------
void draw_main(){
	printf("\t\t\t[ ATM MACHINE ]\n\n");
	printf(" _____________________________________________________________ \n");
	printf("|_____________________________MENU____________________________|\n");
	printf("|                                                             |\n");
	printf("| (L) Login                                      (S) Sign up  |\n");
	printf("|                                                             |\n");
	printf("| (D) Deposit                                    (W) Withdraw |\n");
	printf("|                                                             |\n");
	printf("| (I) ID_load                                    (A) Add_cash |\n");
	printf("|                                                             |\n");
	printf("| (R) Remember_data                              (G) Get_card |\n");
	printf("|                                                             |\n");
	printf("| (P) Put_card                                   (T) all_resT |\n");
	printf("|                                                             |\n");
	printf("| (C) Check                                      (E) Exit     |\n");
	printf("|                                                             |\n");
	printf(" ------------------------------------------------------------- \n");
}
//------------------------Login------------------------
void login(){
	printf("\t\t       [ATM Login Page]\n");
	printf("\t\t          Input ID: ");
	scanf("%s", input_ID);

	printf("\t\t          Input PW: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){
		cls;
		printf("\t\t         [Success]\n");
		printf("\t\t (I) ID Save   (M) Main Menu");

		while (1) {
			if (_kbhit()) {
				m.saveID = _getch();

				switch (m.saveID) {

				case 'i':
					cls;

					m.save = 1;
					return;
				
				case 'm':
					cls;

					m.save = 0;
					return;
				}
			}
		}
	}

	else{
		cls;
		printf("\t\t          [Error]\n");
		printf("\t\t        Login Error");
		m.save = 0;

		pause;
		cls;
		return;
	}
}
//------------------------Sign Up------------------------
void signup(){
	printf("\t\t       [ATM Sign up Page]\n");
	printf("\t\t         Input Name: ");
	scanf("%s", m.name);

	cls;
	printf("\t\t       [ATM Sign up Page]\n");
	printf("\t\t         Input ID: ");
	scanf("%s", m.ID);
	printf("\t\t         Input PW: ");
	scanf("%s", m.PW);


	cls;
	printf("\t\t       [ATM Sign up Page]\n");
	printf("\t\t       Input Cash: ");
	scanf("%d", &m.cash);

	cls;
	if (m.name == "" || m.ID == "" || m.PW == ""){
		printf("\t\t          [Error]\n");
		printf("\t\t    Create Account Error");
		pause;
		cls;

		return;
	}

	printf("\t\t           [Success]\n");
	printf("\t\t     Create Account Success");
	pause;
	cls;

	return;
}
//------------------------Deposit------------------------
void deposit(){
	if (m.save == 1){
	plus:
		printf("\t\t       [Desposit Page]\n");
		printf("\t\t       Cash: %d\n", m.cash);
		printf("\t\t       Input Cash: ");
		scanf("%d", &mm.input_money);

		if (mm.input_money > m.cash){
			cls;

			printf("\t\t           [Error]\n");
			printf("\t\t       Not Enough Money");
			pause;
			cls;

			return;
		}

		m.cash -= mm.input_money; 
		mm.Bank_cash += mm.input_money; 

		cls;
		printf("\t\t       [Bank Money]: %lld\n", mm.Bank_cash); 
		pause;
		cls;

		return;
	}

	else{ 
		printf("\t\t       [Deposit Login Page]\n");
		printf("\t\t         Input ID: ");
		scanf("%s", input_ID);

		printf("\t\t         Input PW: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){
			goto plus;
		}

		else{
			printf("\t\t          [Error]\n");
			printf("\t\t        Login Error");
			pause;

			cls;
			return;
		}

	}
}

//------------------------Withdraw------------------------
void withdraw(){

	if (m.save == 1){
	minus:
		printf("\t\t       [Withdraw Page]\n");
		printf("\t\t       [Bank Money]: %lld\n", mm.Bank_cash);
		printf("\t\t       Input Bank Money: ");
		scanf("%d", &mm.input_money);

		cls;
		if (mm.input_money > mm.Bank_cash){
			printf("\t\t            [Error]\n");
			printf("\t\t     Not Enough Bank Money");
			pause;

			cls;
			return;
		}
		mm.Bank_cash -= mm.input_money;
		m.cash += mm.input_money; 

		printf("\t\t       [Your Cash]: %d\n", m.cash);
		pause;

		cls;

		return;
	}
	else{
		printf("\t\t     [Withdraw Login Page]\n");
		printf("\t\t       Input ID: ");
		scanf("%s", input_ID);

		printf("\t\t       Input PW: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){
			goto minus;
		}

		else{
			printf("\t\t            [Error]\n");
			printf("\t\t          Login Error");
			pause;

			cls;
			return;
		}

	}
}
//------------------------ID_load------------------------
void ID_load(){

	FILE * f;

	printf("\t\t       [ID Load Page]\n");
	printf("\t\t       Input File Name: ");
	scanf("%s", filename);

	if (!strcmp("", filename)){
		cls;
		printf("\t\t            [Error]\n");
		printf("\t\t        File Open Error");
		pause;

		cls;
		return;
	}

	else{

		f = fopen(filename, "r");

		if (f == NULL){
			cls;
			printf("\t\t          [Error]\n");
			printf("\t\t   [%s] File Does Not Exist",filename);

			pause;
			cls;
			return;
		}

		else{
			int tmp;
			fscanf(f, "%s %s %s %lld %d", m.name, m.ID, m.PW, &m.cash, &m.save);
			fclose(f);

			cls;
			printf("\t\t          [Auth ID]\n");
			printf("\t\t          Input PW: ");
			scanf("%s", input_PW);

			if (!strcmp(input_PW, m.PW)){
				cls;
				printf("\t\t          [Success]\n");
				printf("\t\t       Load ID Success");

				pause;
				cls;
				tmp = m.save;
				m.save = 1;
				check();

				m.save = tmp;
				return;
			}

			else{
				cls;
				printf("\t\t            [Error]\n");
				printf("\t\t           Auth Error");

				pause;
				m.name[20] = "";
				m.ID[20] = "";
				m.PW[20] = "";
				m.cash = 0;
				m.save = 0;
				mm.Bank_cash = 0;

				cls;
				return;
			}
		}
	}
}

//------------------------Remember_data------------------------
void Remember_data() {

	printf("\t\t  [Remember_data Login Page]\n");
	printf("\t\t         Input ID: ");
	scanf("%s", input_ID);

	printf("\t\t         Input PW: ");
	scanf("%s", input_PW);

	cls;
	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
		input_ID[20] = "";
		input_PW[20] = "";

		FILE *fp;

		fp = fopen(m.name, "wt");
		if (fp == NULL) {

			printf("\t\t           [Error]\n");
			printf("\t\t        Save Data Error");

			pause;
			cls;

			return;
		}


		fprintf(fp, "%s ", m.name);
		fprintf(fp, "%s ", m.ID);
		fprintf(fp, "%s ", m.PW);
		fprintf(fp, "%ld ", m.cash);
		fprintf(fp, "%d", m.save);

		fclose(fp);

		chmod(m.name, 000);

		printf("\t\t          [Save Data]\n");
		printf("\t\t       Save Data Success");

		pause;
		cls;

		return;
	}

	else {
		printf("\t\t            [Error]\n");
		printf("\t\t          Login Error");
		pause;

		cls;
		return;
	}
}
//------------------------Add_cash------------------------
void add_cash(){

	if (m.save == 1){
	add:
		printf("\t\t         [Add Cash]\n");
		printf("\t\t     Range: [0 ~ 1000000]\n");
		printf("\t\t     Input Cash: ");
		scanf("%d", &mm.input_add_cash);

		if (mm.input_add_cash > 1000000){
			cls;

			printf("\t\t          [Error]\n");
			printf("\t\t       Too Much Money");

			pause;
			cls;
			return;
		}
		m.cash += mm.input_add_cash;

		cls;
		printf("\t\t       [Your Cash]: %d", m.cash);

		pause;
		cls;
		return;
	}

	else{
		printf("\t\t     [Add Cash Login Page]\n");
		printf("\t\t         Input ID: ");
		scanf("%s", input_ID);

		printf("\t\t         Input PW: ");
		scanf("%s", input_PW);


		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){
			goto add;
		}

		else{
			printf("\t\t            [Error]\n");
			printf("\t\t          Login Error");
			pause;

			cls;
			return;
		}

	}
}

//------------------------Get_card------------------------
void Get_card(){
	cls;
	
	printf("\t\t       [Get Card Login]\n");
	printf("\t\t        Input ID: ");
	scanf("%s", input_ID);

	printf("\t\t        Input PW: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){

		input_ID[20] = "";
		input_PW[20] = "";
		Create_Cardname();
		cm.Card_num = rand() % 100000 + 1;

		FILE *Card;
		Card = fopen(cm.card_name, "wt");

		fprintf(Card, "%lld ", mm.Bank_cash);
		fprintf(Card, "%d", cm.Card_num);

		if (Card == NULL) {
			printf("\t\t          [Error]\n");
			printf("\t\t     Create Card Error");

			pause;

			cls;
			return;
		}

		printf("\t\t          [Success]\n");
		printf("\t\t     Create Card Success");

		fclose(Card);
		pause;

		cls;
		return;
	}
	
	else{
		cls;
		printf("\t\t            [Error]\n");
		printf("\t\t          Login Error");
		pause;

		cls;
		return;
	}
	

}

//------------------------Put_card------------------------
void Put_card(){
	cls;

	printf("\t\t     [Put Card Login Page]\n");
	printf("\t\t         Input ID: ");
	scanf("%s", input_ID);

	printf("\t\t         Input PW: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){

		input_ID[20] = "";
		input_PW[20] = "";

		cls;

	}

	else{
		cls;

		printf("\t\t            [Error]\n");
		printf("\t\t          Login Error");
		pause;

		cls;
		return;
	}

	printf("\t\t         Card Name: ");
	scanf("%s", cm.card_name);

	FILE *Card;

	Card = fopen(cm.card_name, "r");

	if (Card == NULL){
		cls;

		printf("\t\t          [Error]\n");
		printf("\t\t   [%s] Card Does Not Exist",cm.card_name);
		pause;

		cls;
		return;
	}

	fscanf(Card, "%ld %d", &mm.Bank_cash, &cm.Card_num);

	fclose(Card);
	cls;
	
	printf("\t\t          [Success]\n");
	printf("\t\t      Bring Info Success");
	pause;
	
	cls;

	while (1){
		if (_kbhit){
			printf("\t\t           [Choice]\n");
			printf("\t\t        Check Card Info\n");
			printf("\t\t       (Y) Yes   (N) No");
			cm.cc = _getch();

			switch (cm.cc){
			case 'y':
				cls;

				cm.cc = "";
				cm.c = 1;
				return;
			case 'n':
				cls;

				cm.cc = "";
				return;

			default:
				cls;
				cm.cc = "";

			}
		}
	}

	return;

}

//------------------------all_reseT--------------------
void reset(){
	cls;

	char ch = "";
	
	while (1){
		if (_kbhit){
			printf("\t\t          [WARNING]\n");
			printf("\t\t        Reset All Info\n");
			printf("\t\t       (Y) Yes   (N) No");
			ch = _getch();

			switch (ch){
			case 'y':
				cls;
				m.ID[20] = "";
				m.PW[20] = "";
				m.name[20] = "";
				m.save = "";
				m.saveID = 0;

				mm.Bank_cash = 0;
				mm.input_add_cash = 0;
				mm.input_money = 0;

				cm.c = 0;
				cm.card_name[10] = "";
				cm.Card_num = 0;
				m.cash = 0;
				cm.cc = "";

				return;

			case 'n':
				cls;

				return;

			default:
				cls;

			}
		}
	}
}

//------------------------Check------------------------
void check(){

	if (m.save == 0){
		printf("\t\t     [Check Login Page]\n");
		printf("\t\t        Input ID: ");
		scanf("%s", input_ID);

		printf("\t\t        Input PW: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){
			goto show;
		}

		else{
			printf("\t\t            [Error]\n");
			printf("\t\t          Login Error");
			pause;

			cls;
			return;
		}
	}
	else{
	show:
		if (cm.c == 0){
			printf("\t\t          [Result]\n");
			printf("\t\t         Name: %s\n", m.name);
			printf("\t\t         ID: %s\n", m.ID);
			printf("\t\t         PW: %s\n", m.PW);
			printf("\t\t         Your Cash: %ld", m.cash);
		}
		else if (cm.c == 1){
			printf("\t\t          [Result]\n");
			printf("\t\t         Name: %s\n", m.name);
			printf("\t\t         ID: %s\n", m.ID);
			printf("\t\t         PW: %s\n", m.PW);
			printf("\t\t         Card number: %d\n", cm.Card_num); 
			printf("\t\t         Your Cash: %ld\n", m.cash);
			printf("\t\t         Bank Money: %lld\n", mm.Bank_cash);
		}

		pause;
		cls;
		return;
	}
}

//------------------------Choice_error------------------------
void choice_error(){

	printf("\t\t          [Error]\n");
	printf("\t\t        Wrong Choice");
	pause;
	cls;
}