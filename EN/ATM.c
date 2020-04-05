#include "ATM.h" // ���� �߰��ؾ��� ������ �ش������� �߰��� �κ��� �ִ� ATM.h�� �ڵ忡 �����Ѵ�.

char input_ID[20]; // ID���� �Է¹޴� ����
char input_PW[20]; // PW���� �Է¹޴� ����
char choice; // ���� �޴��� �ִ� ����� �����Ѵ� ����

char filename[50] = "";


void draw_main() {
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

void ran() {
	int i;

	for (i = 0; i < 10; i++) {
		cm.card_name[i] = (rand() % 26 + 65);
	}
}

int main(void) {
	system("title ATM Machine"); // ������ ATM Machine�� �����Ѵ�.
	system("mode con: cols=63 lines=19"); // cols(����)�� 47, lines(����)�� 12�� �����Ѵ�.
	system("color 1F"); // ������ a ��, cmd(��� ������Ʈ) ��ɾ ó���� �˰��̴�.

	m.save = 0; // m(member ����ü)�� �ִ� save����(���̵� ���� ������)�� 0(�������� �ʴ´�)�� �����Ѵ�.
	mm.Bank_cash = 0; // mm(money_manage ����ü)�� �ִ� Bank_cash����(���࿡ �ִ� ��)�� 0���� �ʱ�ȭ�� ��Ų��.

	srand(time(NULL));

	cm.Card_num = abs(rand() * 1000000);
	
	cm.c = 0;

	while (1) {
		ran();
		draw_main();
		choice = _getch(); // choice�� ��� ����� ���� �Ұ��� ���Ѵ�.

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
				else if(choice == 'p'){
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
				else{
					cls;

					choice_error();

					break;

					
				}
	}
}

//------------------------Login------------------------
void login() {

	printf("\t\t\t[ATM Login Page]\n\n");
	printf("\t\t\tInput ID: ");
	scanf("%s", input_ID);

	printf("\t\t\tInput PW: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) { // �Է� ���� ��� ������ m�� �ִ� ����� �� �Ѵ�.
		cls;

			printf("\t\t\t*Login Success*\n");
			printf("\t\t  (I) ID Save    (M) Main menu");

			while (1) {
				if (_kbhit()) {
					m.saveID = _getch(); // m�� saveID������ ���̵� ������ ������, �ƴ��� �����Ѵ�.

					switch (m.saveID) {

					case 'i': { // i�� �������� ��
						cls;

						m.save = 1; // m�� save������ 1(���̵�����)���� �����Ѵ�.
						return;
					}

					case 'm': // m�� �������� ��
						cls;

						m.save = 0; // m�� save������ 0(���̵����� ���� ����)���� �����Ѵ�.
						return;

					}
				}
			}
	}

	else {
		cls;

		printf("\t\t\t  !!Error!!\n");
		printf("\t\t  ID or PW is wrong!");

		m.save = 0;
		pause;

		cls;
		return;
	}
}

//------------------------Sign Up------------------------
void signup() {

	printf("\t\t\t[ATM Sign up Page]\n\n");

	printf("\t\t\tInput your name: ");
	scanf("%s", m.name);

	cls;
	printf("\t\t\t[ATM Sign up Page]\n\n");

	printf("\t\t\tPlease input ID\n");
	printf("\t\t\tID input: ");
	scanf("%s", m.ID);

	cls;
	printf("\t\t\t[ATM Sign up Page]\n\n");

	printf("\t\t\tPlease input PW\n");
	printf("\t\t\tPW input: ");
	scanf("%s", m.PW);


	cls;

	printf("\t\t\t[ATM Sign up Page]\n\n");
	printf("\t\t\tCash input: ");
	scanf("%d", &m.input_cash);

	cm.cash = m.input_cash;

	cls;

	if (m.name == "" || m.ID == "" || m.PW == "") { // �Է��� ��簪�� NULL�̸� ȸ�� ������ ���ϰ� �Ѵ�.
		printf("\t\t\t  !!Error!!\n");
		printf("\t\t  Sorry, but you can't sign up!");

		pause;
		cls;
		return;
	}
	// �ƴϸ� ȸ�� ������ ���� ��Ų��.

	printf("\t\t\t  *Success*\n");
	printf("\t\t  You success to make your ID");
	pause;

	cls;
	return;
}

//------------------------Deposit------------------------
void deposit() {

	if (m.save == 1) { // m�� save������ 1(���̵�����)�϶� ������ �Ա� ȭ���� �����ش�.
	plus:

		printf("\t\t\tYour cash: %d\n", m.input_cash);
		printf("\t\t\tinput money to plus: ");
		scanf("%d", &mm.input_money);

		if (mm.input_money > m.input_cash) { // ���� �Է��� ���� ���ݺ��� Ŭ�� ���� ������� �ʴٰ� �����ش�.
			cls;

			printf("\t\t  You don't have money to deposit!\n");
			pause;

			cls;
			return;
		}

		m.input_cash -= mm.input_money; // ���ݿ��� �Է��� ���� ����
		mm.Bank_cash += mm.input_money; // �� ������ ���൷�� ���Ѵ�.

		cls;
		printf("\t\tYour Money in a bank is %lld\n", mm.Bank_cash); // �׸��� �� ���Ѱ��� ����Ѵ�.
		pause;

		cls;
		return;
	}

	else { // ���̵� ������ �ƴҶ�
		printf("\t\t\t[Deposit Login Page]\n\n");
		printf("\t\t\tinput ID: ");
		scanf("%s", input_ID);

		printf("\t\t\tinput PW: ");
		scanf("%s", input_PW);

		cls;

		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto plus;
		}

		else {
			printf("\t\t\t  !!Error!!\n");
			printf("\t\t ID or PW is wrong!\n");
			pause;

			cls;
			return;
		}

	}
}

//------------------------Withdraw------------------------
void withdraw() {

	if (m.save == 1) { // m�� save������ 1(���̵� ����)�϶� ������ ��� ȭ���� ���� �ش�.
	minus:

		printf("\t\t\tBank money: %lld\n", mm.Bank_cash);
		printf("\t\t\tinput money to minus: ");
		scanf("%d", &mm.input_money);

		cls;
		if (mm.input_money > mm.Bank_cash) { // ���� �Է��� ���� ���࿡ �ִµ� ���� ũ�� ���࿡ ���� ������� �ʴٰ� �����ش�.
			printf("\t\tYou don't have enough to withdraw!\n");
			pause;

			cls;
			return;
		}
		mm.Bank_cash -= mm.input_money; // ���࿡ �ִµ� ���� �Է¹��� ���� ����.
		m.input_cash += mm.input_money; // �׸��� ���ݿ� �Է¹��� ���� ���Ѵ�.

		printf("\t\t\tYour cash: %d\n", m.input_cash);
		pause;

		cls;

		return;
	}
	// m�� save������ 0(���̵� ���� �����ʴ´�)�϶�
	else {
		printf("\t\t\t[Withdraw Login Page]\n\n");
		printf("\t\t\tinput ID: ");
		scanf("%s", input_ID);

		printf("\t\t\tinput PW: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto minus;
		}

		else {
			printf("\t\t\t  !!Error!!\n");
			printf("\t\t  ID or PW is wrong!\n");
			pause;

			cls;
			return;
		}

	}
}

//------------------------ID_load------------------------
void ID_load() {

	FILE * f;

	printf("\t\t\t  [ID Load Page]\n");
	printf("\t\t Input File name: ");
	scanf("%s", filename);

	if (!strcmp("", filename)) {
		cls;
		printf("\t\t\t  !!Error!!\n");
		printf("\t\t You didn't input any thing!\n");
		pause;

		cls;
		return;
	}

	else {

		f = fopen(filename, "r");

		if (f == NULL) {
			cls;
			printf("\t\t\t  !!Error!!\n");
			printf("\t\t There is no file \'%s\'\n", filename);

			pause;
			cls;
			return;
		}

		else {
			fscanf(f, "%s %s %s %lld %d", m.name, m.ID, m.PW, &mm.Bank_cash, &m.saveID);
			fclose(f);

			cls;

			printf("\t\t\t [Auth ID]\n");
			printf("\t\t  Input PW: ");
			scanf("%s", input_PW);

			if (!strcmp(input_PW, m.PW)) {
				cls;

				printf("\t\t\t  *Success*\n");
				printf("\t\t  Loading your ID successed!");
				pause;

				cls;

				printf("\t\t\t  < Result >\n\n");
				printf("\t\tName: %s  ID: %s  PW: %s\n", m.name, m.ID, m.PW);
				printf("\t\tBank_cash: %lld",mm.Bank_cash);


				pause;
				cls;

				return;
			}

			else {
				cls;
				printf("\t\t\t  !!Error!!\n");
				printf("\t\t That was Incorrect PW!\n");

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

		printf("\t\t[Remember_data Login Page]\n\n");
		printf("\t\t\tinput ID: ");
		scanf("%s", input_ID);

		printf("\t\t\tinput PW: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			save();
		}

		else {
			printf("\t\t\t  !!Error!!\n");
			printf("\t\t  ID or PW is wrong!\n");
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

		printf("\t\t\t  !!Error!!\n");
		printf("\t\t  There has an error while saving!");

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

	printf("\t\t\t  < Save Data >\n\n");
	printf("\t\t  Result: Saving data successed!!\n");

	pause;
	cls;

	return;
}

//------------------------Add_cash------------------------
void add_cash() {

	if (m.save == 1) {
	add:

		printf("\t\t\t[ ID_load ]\n");
		printf("\t\tRange(0 ~1000000)\n\n");
		printf("\t\t\tInput cash to add: ");
		scanf("%d", &mm.input_add_cash);

		if (mm.input_add_cash > 1000000) {
			cls;

			printf("\t\t\t  !!Error!!\n");
			printf("\t\t  You can't input too much cash!\n");

			pause;
			cls;
			return;

		}

		cm.cash = mm.input_add_cash;

		cls;
		printf("\t\t\tYour cash: %d", m.input_cash);

		pause;
		cls;
		return;

	}

	else {
		printf("\t\t\t[ Add_cash Login Page ]\n\n");
		printf("\t\t\tinput ID: ");
		scanf("%s", input_ID);

		printf("\t\t\tinput PW: ");
		scanf("%s", input_PW);


		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto add;
		}

		else {
			printf("\t\t\t  !!Error!!\n");
			printf("\t\t  ID or PW is wrong!\n");
			pause;

			cls;
			return;
		}

	}
}

//------------------------Get_card------------------------
void Get_card() {
	cls;
	
	printf("\t\t\t[Get Card Login]\n");
	printf("\t\t\tinput ID: ");
	scanf("%s", input_ID);

	printf("\t\t\tinput PW: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {

		input_ID[20] = "";
		input_PW[20] = "";

		cls;
	}
	
	else {
		cls;
		printf("\t\t\t!!Error!!\n");
		printf("\t\tID or PW is wrong!\n");
		pause;

		cls;
		return;
	}

	FILE *Card;
	Card = fopen(cm.card_name, "wt");

	fprintf(Card, "%ld ", cm.cash);
	fprintf(Card, "%d", cm.Card_num);

	if (Card == NULL) {
		printf("\t\t\t  !!Error!!\n");
		printf("\t\t  There has an error while making Card!\n");

		pause;

		cls;
		return;
	}

	printf("\t\t\t  *Success*\n");
	printf("\t\t  Succeed to making Card!\n");
	
	fclose(Card);
	pause;

	cls;
	return;

}

//------------------------Put_card------------------------
void Put_card() {
	cls;

	printf("\t\t\t[Put card Page]\n\n");
	printf("\t\t\tinput ID: ");
	scanf("%s", input_ID);

	printf("\t\t\tinput PW: ");
	scanf("%s", input_PW);

	if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {

		input_ID[20] = "";
		input_PW[20] = "";

		cls;

	}

	else {
		cls;

		printf("\t\t\t!!Error!!\n");
		printf("\t\tID or PW is wrong!\n");
		pause;

		cls;
		return;
	}

	printf("\t\tPlease input card name: ");
	scanf("%s", cm.card_name);

	FILE *Card;

	Card = fopen(cm.card_name, "r");

	if (Card == NULL) {
		cls;

		printf("\t\t\t!!Error!!\n");
		printf("\t\tThere is no \'%s\' card!\n", cm.card_name);
		pause;

		cls;
		return;
	}

	fscanf(Card, "%ld %d", &cm.cash, &cm.Card_num);

	fclose(Card);
	cls;
	
	printf("\t\t\t*Success*\n");
	printf("\t\tSucceed to bring info!\n");
	pause;
	
	cls;

	while (1) {
		if (_kbhit) {
			printf("\t\t\t?Choice?\n");
			printf("\t\tDo you want to see Card info, too?\n");
			printf("\t\t\t(Y) yes   (N) no\n");
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
			printf("\t\t\t!WARNING!\n");
			printf("\t\tDo you really want to reset all?\n");
			printf("\t\t(Y) yes          (N) no\n");
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

	if (m.save == 0) { // ���̵� �������� �ʾ����� 
		printf("\t\t\t[Check Login Page]\n\n");
		printf("\t\t\tinput ID: ");
		scanf("%s", input_ID);

		printf("\t\t\tinput PW: ");
		scanf("%s", input_PW);

		cls;
		if (!strcmp(input_ID, m.ID) && !strcmp(input_PW, m.PW)) {
			goto show;
		}

		else {
			printf("\t\t\t  !!Error!!\n");
			printf("\t\t  You can't check them!\n");
			pause;

			cls;
			return;
		}

	}
	else { // ���̵� ���������� 
	show:
		if (cm.c == 0) {
			printf("\t\t\t  < Result >\n\n");
			printf("\t\t  Your Name: %s\n", m.name);
			printf("\t\t  Your ID: %s\n", m.ID);
			printf("\t\t  Your PW: %s\n", m.PW);
			printf("\t\t  Your Bank money: %lld\n", mm.Bank_cash);
		}
		else if (cm.c == 1) {
			printf("\t\t\t  < Result >\n\n");
			printf("\t\t  Your Name: %s\n", m.name);
			printf("\t\t  Your ID: %s\n", m.ID);
			printf("\t\t  Your PW: %s\n", m.PW);
			printf("\t\t  Your Card number: %d\n", cm.Card_num);
			printf("\t\t  Your Bank money: %lld\n", mm.Bank_cash);
			printf("\t\t  Your Cash: %ld", cm.cash);

		}

		pause;

		cls;
		return;
	}
}

//------------------------Choice_error------------------------
void choice_error() {

	printf("\t\t\t   Error\n");
	printf("\t\t\tWrong Choice!");
	pause;

	cls;
}