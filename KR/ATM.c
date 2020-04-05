#include "ATM.h" // 위에 추가해야할 변수나 해더파일을 추가한 부분이 있는 ATM.h을 코드에 포함한다.

char input_ID[20]; // ID값을 입력받는 변수
char input_PW[20]; // PW값을 입력받는 변수
char choice; // 메인 메뉴에 있는 명령을 선택한는 변수

char filename[50] = "";


void draw_main() {
	printf("\t\t\t[ ATM기 기계 ]\n\n");
	printf(" _____________________________________________________________ \n");
	printf("|_____________________________메뉴____________________________|\n");
	printf("|                                                             |\n");
	printf("| (L) 로그인                                     (S) 회원가입 |\n");
	printf("|                                                             |\n");
	printf("| (D) 입금				         (W) 출금     |\n");
	printf("|                                                             |\n");
	printf("| (I) 이어하기                                   (A) 현금 추가|\n");
	printf("|                                                             |\n");
	printf("| (R) 저장하기                                   (G) 카드받기 |\n");
	printf("|                                                             |\n");
	printf("| (P) 카드 넣기                                  (T) 초기화   |\n");
	printf("|                                                             |\n");
	printf("| (C) 확인하기                                   (E) 종료     |\n");
	printf("|                                                             |\n");
	printf(" ------------------------------------------------------------- \n");
}

void ran() {
	int i;

	for (i = 0; i < 10; i++) {
		cm.card_name[i] = (rand() % 26 + 65);
	}
}

int main(void) {
	system("title ATM Machine"); // 제목을 ATM Machine로 설정한다.
	system("mode con: cols=63 lines=19"); // cols(가로)를 47, lines(세로)를 12로 설정한다.
	system("color 1F"); // 색깔을 a 즉, cmd(명령 프롬프트) 명령어에 처보면 알것이다.

	m.save = 0; // m(member 구조체)에 있는 save변수(아이디 저장 설정값)을 0(저장하지 않는다)로 설정한다.
	mm.Bank_cash = 0; // mm(money_manage 구조체)에 있는 Bank_cash변수(은행에 있는 돈)을 0으로 초기화를 시킨다.

	srand(time(NULL));

	cm.Card_num = abs(rand() * 1000000);
	
	cm.c = 0;

	while (1) {
				ran();
				draw_main();
				choice = _getch(); // choice로 어느 명령을 실행 할건지 정한다.

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

					return 0;
				}
				//------------------------Choice  error------------------------
				else {
					cls;

					choice_error();

					break;


				}
	}
}

//------------------------Login------------------------
void login() {

	printf("\t\t\t[로그인 페이지]\n\n");
	printf("\t\t\t아이디 입력: ");
	scanf("%s", input_ID);

	printf("\t\t\t비밀번호 입력: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) { // 입력 받은 모든 값들을 m에 있는 값들과 비교 한다.
		cls;

			printf("\t\t\t*로그인 성공*\n");
			printf("\t\t(I) 아이디 저장하기    (M) 메인메뉴");

			while (1) {
				if (_kbhit()) {
					m.saveID = _getch(); // m에 saveID변수로 아이디를 저장할 것인지, 아닌지 결정한다.

					switch (m.saveID) {

					case 'i': { // i을 선택했을 때
						cls;

						m.save = 1; // m에 save변수를 1(아이디저장)으로 설정한다.
						return;
					}

					case 'm': // m을 선택했을 떄
						cls;

						m.save = 0; // m에 save변수를 0(아이디저장 하지 않음)으로 설정한다.
						return;

					}
				}
			}
	}

	else {
		cls;

		printf("\t\t\t  !!에러!!\n");
		printf("\t\t  잘못된 값을 넣었습니다!");

		m.save = 0;
		pause;

		cls;
		return;
	}
}

//------------------------Sign Up------------------------
void signup() {

	printf("\t\t\t[회원가입 페이지]\n\n");

	printf("\t\t\t이름 입력: ");
	scanf("%s", m.name);

	cls;
	printf("\t\t\t[회원가입 페이지]\n\n");

	printf("\t\t\t아이디를 입력해주세요.\n");
	printf("\t\t\t아이디 입력: ");
	scanf("%s", m.ID);

	cls;
	printf("\t\t\t[회원가입 페이지]\n\n");

	printf("\t\t\t비밀번호를 입력해주세요.\n");
	printf("\t\t\t비밀번호 입력: ");
	scanf("%s", m.PW);


	cls;

	printf("\t\t\t[회원가입 페이지]\n\n");
	printf("\t\t\t현금 입력: ");
	scanf("%d", &m.input_cash);

	cm.cash = m.input_cash;

	cls;

	if (m.name == "" || m.ID == "" || m.PW == "") { // 입력한 모든값이 NULL이면 회원 가입을 못하게 한다.
		printf("\t\t\t!!에러!!\n");
		printf("\t\t죄송하지만, 당신은 가입할 수 없습니다!");

		pause;
		cls;
		return;
	}
	// 아니면 회원 가입을 성공 시킨다.

	printf("\t\t\t  *성공*\n");
	printf("\t\t  회원가입에 성공했습니다!");
	pause;

	cls;
	return;
}

//------------------------Deposit------------------------
void deposit() {

	if (m.save == 1) { // m에 save변수가 1(아이디저장)일때 저절로 입금 화면을 보여준다.
	plus:

		printf("\t\t\t당신의 현금: %d\n", m.input_cash);
		printf("\t\t\t통장에 넣을 금액: ");
		scanf("%d", &mm.input_money);

		if (mm.input_money > m.input_cash) { // 만약 입력한 돈이 현금보다 클때 돈이 충분하지 않다고 말해준다.
			cls;

			printf("\t\t  당신은 충분한 금액이 없습니다!\n");
			pause;

			cls;
			return;
		}

		m.input_cash -= mm.input_money; // 현금에서 입력한 값을 빼고
		mm.Bank_cash += mm.input_money; // 그 뺀값을 은행돈에 더한다.

		cls;
		printf("\t\t통장 잔액은 %lld 입니다\n", mm.Bank_cash); // 그리고 그 더한값을 출력한다.
		pause;

		cls;
		return;
	}

	else { // 아이디 저장이 아닐때
		printf("\t\t\t[입금 로그인 페이지]\n\n");
		printf("\t\t\t아이디 입력: ");
		scanf("%s", input_ID);

		printf("\t\t\t비밀번호 입력: ");
		scanf("%s", input_PW);

		cls;

		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto plus;
		}

		else {
			printf("\t\t\t  !!에러!!\n");
			printf("\t\t  아이디나 비밀번호가 틀렸습니다!\n");
			pause;

			cls;
			return;
		}

	}
}

//------------------------Withdraw------------------------
void withdraw() {

	if (m.save == 1) { // m에 save변수가 1(아이디 저장)일때 저절로 출금 화면을 보여 준다.
	minus:

		printf("\t\t\t통장 잔액: %lld\n", mm.Bank_cash);
		printf("\t\t\t출금할 금액 입력: ");
		scanf("%d", &mm.input_money);

		cls;
		if (mm.input_money > mm.Bank_cash) { // 만약 입력한 값이 은행에 있는돈 보다 크면 은행에 돈이 충분하지 않다고 말해준다.
			printf("\t\t통장에 충분한 금액이 없습니다!\n");
			pause;

			cls;
			return;
		}
		mm.Bank_cash -= mm.input_money; // 은행에 있는돈 에서 입력받은 값을 뺀다.
		m.input_cash += mm.input_money; // 그리고 현금에 입력받은 값을 더한다.

		printf("\t\t\t당신의 현금: %d\n", m.input_cash);
		pause;

		cls;

		return;
	}
	// m에 save변수가 0(아이디 저장 하지않는다)일때
	else {
		printf("\t\t\t[출금 로그인 페이지]\n\n");
		printf("\t\t\t아이디 입력: ");
		scanf("%s", input_ID);

		printf("\t\t\t비밀번호 입력: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto minus;
		}

		else {
			printf("\t\t\t  !!에러!!\n");
			printf("\t\t  아이디나 비밀번호가 틀렸습니다!\n");
			pause;

			cls;
			return;
		}

	}
}

//------------------------ID_load------------------------
void ID_load() {

	FILE * f;

	printf("\t\t\t[이어하기 로그인 페이지]\n");
	printf("\t\t 파일 이름 입력: ");
	scanf("%s", filename);

	if (!strcmp("", filename)) {
		cls;
		printf("\t\t\t  !!에러!!\n");
		printf("\t\t 아무런 값을 받지 못했습니다!\n");
		pause;

		cls;
		return;
	}

	else {

		f = fopen(filename, "r");

		if (f == NULL) {
			cls;
			printf("\t\t\t  !!에러!!\n");
			printf("\t\t \'%s\'라는 파일이 존재하지 않습니다!\n", filename);

			pause;
			cls;
			return;
		}

		else {
			fscanf(f, "%s %s %s %lld %d", m.name, m.ID, m.PW, &mm.Bank_cash, &m.saveID);
			fclose(f);

			cls;

			printf("\t\t\t [아이디 인증]\n");
			printf("\t\t  비밀번호 입력: ");
			scanf("%s", input_PW);

			if (!strcmp(input_PW, m.PW)) {
				cls;

				printf("\t\t\t  *성공*\n");
				printf("\t\t  이어하기에 성공하였습니다!");
				pause;

				cls;

				printf("\t\t\t  < 결과 >\n\n");
				printf("\t\t이름: %s  아이디: %s  비밀번호: %s\n", m.name, m.ID, m.PW);
				printf("\t\t통장 잔액: %lld",mm.Bank_cash);


				pause;
				cls;

				return;
			}

			else {
				cls;
				printf("\t\t\t  !!에러!!\n");
				printf("\t\t 비밀번호가 틀렸습니다!\n");

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
void Remember_data() {

		printf("\t\t[파일저장 로그인 페이지]\n\n");
		printf("\t\t\t아이디 입력: ");
		scanf("%s", input_ID);

		printf("\t\t\t비밀번호 입력: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			save();
		}

		else {
			printf("\t\t\t  !!에러!!\n");
			printf("\t\t  아이디나 비밀번호가 틀렸습니다!\n");
			pause;

			cls;
			return;
		}
}
//------------------------Save------------------------
void save() {
	FILE *fp;

	fp = fopen(m.name, "wt");
	if (fp == NULL) {

		printf("\t\t\t  !!에러!!\n");
		printf("\t\t  저장하는 동안 에러가 났습니다!");

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

	printf("\t\t\t  < 파일저장 >\n\n");
	printf("\t\t  결과: 파일저장 성공!!\n");

	pause;
	cls;

	return;
}

//------------------------Add_cash------------------------
void add_cash() {

	if (m.save == 1) {
	add:

		printf("\t\t\t[ 현금 추가 ]\n\t\t범위(0 ~ 1000000)\n\n");
		printf("\t\t\t추가할 금액 입력: ");
		scanf("%d", &mm.input_add_cash);

		if (mm.input_add_cash > 1000000) {
			cls;

			printf("\t\t\t  !!에러!!\n");
			printf("\t\t  너무 많은 값을 추가 할수 없습니다!\n");

			pause;
			cls;
			return;

		}

		cm.cash = mm.input_add_cash;

		cls;
		printf("\t\t\t당신의 현금: %d", m.input_cash);

		pause;
		cls;
		return;

	}

	else {
		printf("\t\t\t[ 현금추가 로그인 페이지 ]\n\n");
		printf("\t\t\t아이디 입력: ");
		scanf("%s", input_ID);

		printf("\t\t\t비밀번호 입력: ");
		scanf("%s", input_PW);


		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto add;
		}

		else {
			printf("\t\t\t  !!에러!!\n");
			printf("\t\t  아이디나 비밀번호가 틀렸습니다!\n");
			pause;

			cls;
			return;
		}

	}
}

//------------------------Get_card------------------------
void Get_card() {
	cls;
	
	printf("\t\t\t[카드 받기 로그인 페이지]\n");
	printf("\t\t\t아이디 입력: ");
	scanf("%s", input_ID);

	printf("\t\t\t비밀번호 입력: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {

		input_ID[20] = "";
		input_PW[20] = "";

		cls;
	}
	
	else {
		cls;
		printf("\t\t\t!!에러!!\n");
		printf("\t\t아이디나 비밀번호가 틀렸습니다!\n");
		pause;

		cls;
		return;
	}

	FILE *Card;
	Card = fopen(cm.card_name, "wt");

	fprintf(Card, "%ld ", cm.cash);
	fprintf(Card, "%d", cm.Card_num);

	if (Card == NULL) {
		printf("\t\t\t  !!에러!!\n");
		printf("\t\t  카드를 만드는 동안 에러가 났습니다!\n");

		pause;

		cls;
		return;
	}

	printf("\t\t\t  *성공*\n");
	printf("\t\t  카드받기 성공!\n");
	
	fclose(Card);
	pause;

	cls;
	return;

}

//------------------------Put_card------------------------
void Put_card() {
	cls;

	printf("\t\t\t[카드 넣기 로그인 페이지]\n\n");
	printf("\t\t\t아이디 입력: ");
	scanf("%s", input_ID);

	printf("\t\t\t비밀번호 입력: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {

		input_ID[20] = "";
		input_PW[20] = "";

		cls;

	}

	else {
		cls;

		printf("\t\t\t!!에러!!\n");
		printf("\t\t아이디나 비밀번호가 틀렸습니다!\n");
		pause;

		cls;
		return;
	}

	printf("\t\t카드 이름 입력: ");
	scanf("%s", cm.card_name);

	FILE *Card;

	Card = fopen(cm.card_name, "r");

	if (Card == NULL) {
		cls;

		printf("\t\t\t!!에러!!\n");
		printf("\t\t\'%s\'라는 카드는 존재하지 않습니다!\n", cm.card_name);
		pause;

		cls;
		return;
	}

	fscanf(Card, "%ld %d", &cm.cash, &cm.Card_num);

	fclose(Card);
	cls;
	
	printf("\t\t\t*성공*\n");
	printf("\t\t카드 값 가져오기 성공했습니다!\n");
	pause;
	
	cls;

	while (1) {
		if (_kbhit) {
			printf("\t\t\t?선택?\n");
			printf("\t\t카드 값도 보게 할까요?\n");
			printf("\t\t\t(Y) 네   (N) 아니요\n");
			cm.cc = _getch();

			switch (cm.cc) {
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
void reset() {
	cls;

	char ch = "";
	
	while (1) {
		if (_kbhit) {
			printf("\t\t\t!경고!\n");
			printf("\t\t진짜 모든 값을 초기화 시키겠습니까?\n");
			printf("\t\t(Y) 네          (N) 아니요\n");
			ch = _getch();

			switch (ch) {
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
				//cm.Card_num = 0;
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
void check() {

	if (m.save == 0) { // 아이디를 저장하지 않았을때 
		printf("\t\t\t[확인하기 로그인 페이지]\n\n");
		printf("\t\t\t아이디 입력: ");
		scanf("%s", input_ID);

		printf("\t\t\t비밀번호 입력: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto show;
		}

		else {
			printf("\t\t\t  !!에러!!\n");
			printf("\t\t  아이디나 비밀번호가 틀렸습니다!\n");
			pause;

			cls;
			return;
		}

	}
	else { // 아이디를 저장했을때 
	show:
		if (cm.c == 0) {
			printf("\t\t\t  < 결과 >\n\n");
			printf("\t\t  당신의 이름: %s\n", m.name);
			printf("\t\t  당신의 아이디: %s\n", m.ID);
			printf("\t\t  당신의 비밀번호: %s\n", m.PW);
			printf("\t\t  당신의 통장 잔액: %lld\n", mm.Bank_cash);
		}
		else if (cm.c == 1) {
			printf("\t\t\t  < 결과 >\n\n");
			printf("\t\t  당신의 이름: %s\n", m.name);
			printf("\t\t  당신의 아이디: %s\n", m.ID);
			printf("\t\t  당신의 비밀번호: %s\n", m.PW);
			printf("\t\t  당신의 카드 번호: %d\n", cm.Card_num);
			printf("\t\t  당신의 통장 잔액: %lld\n", mm.Bank_cash);
			printf("\t\t  당신의 현금: %ld", cm.cash);

		}

		pause;

		cls;
		return;
	}
}

//------------------------Choice_error------------------------
void choice_error() {

	printf("\t\t\t    에러\n");
	printf("\t\t\t잘못된 선택 입니다!");
	pause;

	cls;
}