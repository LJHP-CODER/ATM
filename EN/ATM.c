#include "ATM.h" //위에 추가해야할 변수나 해더파일을 추가한 "ATM.h" 헤더파일을 코드에 포함한다.

char input_ID[20]; //ID값을 임시 입력받는 변수
char input_PW[20]; //PW값을 임시 입력받는 변수
char choice; //메인 메뉴에 있는 명령선택 변수

char filename[50] = ""; //파일 입출력에 필요한 파일이름 변수

void Create_Cardname(){ //카드이름을 랜덤으로 단어를 뽑아서 설정해준다.
	int i;

	for (i = 0; i < 5; i++){
		cm.card_name[i] = (rand() % 26 + 65);
	}
}

int main(){
	system("title ATM Machine"); //제목을 ATM Machine로 설정한다.
	system("mode con: cols=63 lines=19"); //cols(가로)를 47, lines(세로)를 12로 설정한다.
	system("color 1F"); //색깔을 1F로 설정한다.

	m.save = 0; //m(member 구조체)에 있는 save변수(아이디 저장 설정값)을 0(저장하지 않는다)로 설정한다.
	mm.Bank_cash = 0; //mm(money_manage 구조체)에 있는 Bank_cash변수(은행에 있는 돈)을 0으로 초기화한다.

	srand(time(NULL)); //시드값은 time(현재 시간)을 갖고 어느 수식을 통해 매시간마다 바뀌는 난수를 뽑게한다.
	cm.Card_num = abs(rand() * 1000000); //절댓값으로 0부터 1000000중에서 랜덤 숫자를 뽑아 카드번호로 설정한다.
	cm.c = 0; //카드정보(카드번호, 캐시)를 보여줄지 정하는 변수를 0(보여주지 않는다)로 초기화한다.
	Create_Cardname();

	while (1){
		draw_main();
		choice = _getch(); //어느 명령을 실행 할건지 정한다.
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
			break;
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

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){ //입력 받은 모든 값들을 m구조체에 있는 (ID, PW)와 비교 한다.
		cls;
		printf("\t\t         [Success]\n");
		printf("\t\t (I) ID Save   (M) Main Menu");

		while (1) {
			if (_kbhit()) { //키보드 입력 감지
				m.saveID = _getch(); //m구조체에 있는 saveID변수로 아이디를 저장할 것인지 아닌지 결정한다.

				switch (m.saveID) {

				case 'i':  //i키를 눌렀을때
					cls;

					m.save = 1; //save를 1로 바꿔 아이디를 저장한다.
					return;
				
				case 'm': //m키를 눌렀을때
					cls;

					m.save = 0; //save를 0로 넣어 저장하지 않는다.
					return;
				}
			}
		}
	}

	else{
		cls;
		printf("\t\t      [Error]\n");
		printf("\t\t    Login Error");
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
	scanf("%d", &m.input_cash);

	cm.cash = m.input_cash;

	cls;
	if (m.name == "" || m.ID == "" || m.PW == ""){ //입력한 값이 하나라도 없으면 회원 가입을 못하게 한다.
		printf("\t\t          [Error]\n");
		printf("\t\t    Create Account Error");
		pause;
		cls;

		return;
	}
	//아니면 회원 가입을 성공 시킨다.

	printf("\t\t           [Success]\n");
	printf("\t\t     Create Account Success");
	pause;
	cls;

	return;
}
//------------------------Deposit------------------------
void deposit(){
	if (m.save == 1){ //save변수 1(아이디저장)일때 저절로 입금 화면을 보여준다.
	plus:
		printf("\t\t       [Desposit Page]\n");
		printf("\t\t       Cash: %d\n", m.input_cash);
		printf("\t\t       Input Cash: ");
		scanf("%d", &mm.input_money);

		if (mm.input_money > m.input_cash){ //만약 입력한 돈이 현금보다 클때 돈이 충분하지 않다고 말해준다.
			cls;

			printf("\t\t         [Error]\n");
			printf("\t\t     Not Enough Money");
			pause;
			cls;

			return;
		}

		m.input_cash -= mm.input_money; //현금에서 입력한 값을 빼고
		mm.Bank_cash += mm.input_money; //그 뺀값을 은행돈에 더한다.

		cls;
		printf("\t\t       [Bank Money]: %lld\n", mm.Bank_cash); //그리고 그 더한값을 출력한다.
		pause;
		cls;

		return;
	}

	else{ //아이디 저장이 아닐때
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

	if (m.save == 1){ //m에 save변수가 1(아이디 저장)일때 저절로 출금 화면을 보여 준다.
	minus:
		printf("\t\t       [Withdraw Page]\n");
		printf("\t\t       [Bank Money]: %lld\n", mm.Bank_cash);
		printf("\t\t       Input Bank Money: ");
		scanf("%d", &mm.input_money);

		cls;
		if (mm.input_money > mm.Bank_cash){ //만약 입력한 값이 은행에 있는돈 보다 크면 은행에 돈이 충분하지 않다고 말해준다.
			printf("\t\t          [Error]\n");
			printf("\t\t   Not Enough Bank Money");
			pause;

			cls;
			return;
		}
		mm.Bank_cash -= mm.input_money; //은행에 있는돈 에서 입력받은 값을 뺀다.
		m.input_cash += mm.input_money; //그리고 현금에 입력받은 값을 더한다.

		printf("\t\t       [Your Cash]: %d\n", m.input_cash);
		pause;

		cls;

		return;
	}
	//m에 save변수가 0(아이디 저장 하지않는다)일때
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
			printf("\t\t          [Error]\n");
			printf("\t\t        Login Error");
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
		printf("\t\t          [Error]\n");
		printf("\t\t      File Open Error");
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
			fscanf(f, "%s %s %s %lld %d", m.name, m.ID, m.PW, &mm.Bank_cash, &m.saveID);
			fclose(f);

			cls;
			printf("\t\t         [Auth ID]\n");
			printf("\t\t         Input PW: ");
			scanf("%s", input_PW);

			if (!strcmp(input_PW, m.PW)){
				cls;
				printf("\t\t         [Success]\n");
				printf("\t\t      Load ID Success");

				pause;
				cls;
				printf("\t\t          [Result]\n");
				printf("\t\t         Name: %s\n", m.name);
				printf("\t\t         ID: %s\n", m.ID);
				printf("\t\t         PW: %s\n", m.PW);
				printf("\t\t         Bank Money: %lld\n", mm.Bank_cash);


				pause;
				cls;

				return;
			}

			else{
				cls;
				printf("\t\t          [Error]\n");
				printf("\t\t         Auth Error");

				pause;
				m.name[20] = "";
				m.ID[20] = "";
				m.PW[20] = "";
				m.input_cash = 0;
				m.save = 0;
				mm.Bank_cash = 0;

				cls;
				return;
			}
		}
	}
}

//------------------------Remember_data------------------------
void Remember_data(){

		printf("\t\t  [Remember_data Login Page]\n");
		printf("\t\t         Input ID: ");
		scanf("%s", input_ID);

		printf("\t\t         Input PW: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)){
			save();
		}

		else{
			printf("\t\t          [Error]\n");
			printf("\t\t        Login Error");
			pause;

			cls;
			return;
		}
}
//------------------------Save------------------------
void save(){
	FILE *fp;

	fp = fopen(m.name, "wt");
	if (fp == NULL){

		printf("\t\t          [Error]\n");
		printf("\t\t       Save Data Error");

		pause;
		cls;

		return;
	}


	fprintf(fp, "%s ", m.name);
	fprintf(fp, "%s ", m.ID);
	fprintf(fp, "%s ", m.PW);
	fprintf(fp, "%lld ", mm.Bank_cash);
	fprintf(fp, "%d", m.saveID);

	fclose(fp);

	chmod(m.name, 000);

	printf("\t\t        [Save Data]\n");
	printf("\t\t     Save Data Success");

	pause;
	cls;

	return;
}

//------------------------Add_cash------------------------
void add_cash(){

	if (m.save == 1){
	add:
		printf("\t\t       [Add Cash]\n");
		printf("\t\t   Range: [0 ~ 1000000]\n");
		printf("\t\t   Input Cash: ");
		scanf("%d", &mm.input_add_cash);

		if (mm.input_add_cash > 1000000){
			cls;

			printf("\t\t          [Error]\n");
			printf("\t\t       Too Much Money");

			pause;
			cls;
			return;
		}
		cm.cash = mm.input_add_cash;

		cls;
		printf("\t\t       [Your Cash]: %d", m.input_cash);

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
			printf("\t\t          [Error]\n");
			printf("\t\t        Login Error");
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

		cls;
	}
	
	else{
		cls;
		printf("\t\t          [Error]\n");
		printf("\t\t        Login Error");
		pause;

		cls;
		return;
	}

	FILE *Card;
	Card = fopen(cm.card_name, "wt");

	fprintf(Card, "%ld ", cm.cash);
	fprintf(Card, "%d", cm.Card_num);

	if (Card == NULL){
		printf("\t\t          [Error]\n");
		printf("\t\t     Create Card Error");

		pause;

		cls;
		return;
	}

	printf("\t\t        [Success]\n");
	printf("\t\t   Create Card Success");
	
	fclose(Card);
	pause;

	cls;
	return;

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

		printf("\t\t          [Error]\n");
		printf("\t\t        Login Error");
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

	fscanf(Card, "%ld %d", &cm.cash, &cm.Card_num);

	fclose(Card);
	cls;
	
	printf("\t\t       [Success]\n");
	printf("\t\t   Bring Info Success");
	pause;
	
	cls;

	while (1){
		if (_kbhit){
			printf("\t\t       [Choice]\n");
			printf("\t\t    Check Card Info\n");
			printf("\t\t   (Y) Yes   (N) No");
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
			printf("\t\t       [WARNING]\n");
			printf("\t\t    Reset All Info\n");
			printf("\t\t   (Y) Yes   (N) No");
			ch = _getch();

			switch (ch){
			case 'y':
				cls;
				m.ID[20] = "";
				m.PW[20] = "";
				m.name[20] = "";
				m.save = "";
				m.saveID = 0;
				m.input_cash = "";

				mm.Bank_cash = 0;
				mm.input_add_cash = 0;
				mm.input_money = 0;

				cm.c = 0;
				cm.card_name[10] = "";
				cm.Card_num = 0;
				cm.cash = 0;
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

	if (m.save == 0){ //아이디를 저장하지 않았을때 
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
			printf("\t\t          [Error]\n");
			printf("\t\t        Login Error");
			pause;

			cls;
			return;
		}
	}
	else{ //아이디를 저장했을때 
	show:
		if (cm.c == 0){
			printf("\t\t          [Result]\n");
			printf("\t\t         Name: %s\n", m.name);
			printf("\t\t         ID: %s\n", m.ID);
			printf("\t\t         PW: %s\n", m.PW);
			printf("\t\t         Bank Money: %lld\n", mm.Bank_cash);
		}
		else if (cm.c == 1){
			printf("\t\t          [Result]\n");
			printf("\t\t         Name: %s\n", m.name);
			printf("\t\t         ID: %s\n", m.ID);
			printf("\t\t         PW: %s\n", m.PW);
			printf("\t\t         Card number: %d\n", cm.Card_num); 
			printf("\t\t         Bank Money: %lld\n", mm.Bank_cash);
			printf("\t\t         Your Cash: %ld", cm.cash);
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