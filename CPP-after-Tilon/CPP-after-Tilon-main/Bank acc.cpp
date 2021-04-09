#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef struct _ACNT {
	int ID = 0;
	char Name[20] = "\0";
	int Blnc = 0;
}ACNT;

int main() {
	int flag = 0;
	ACNT Cstm[256] = {};
	int Amnt;
	while (flag == 0) {
		cout << "-------메뉴-------" << endl;
		cout << "1. 계좌개설\n" << "2. 입금\n" << "3. 출금\n" << "4. 계좌정보 전체출력\n"
			<< "5. 프로그램 종료\n" << endl;
		int insert = 0;
		cin >> insert;
		switch (insert) {
		case 1:
			cout << "입력: (ID,이름,초기잔고)" << endl;
			int ID;
			cin >> ID;
			Cstm[ID].ID = ID;
			cin>> Cstm[ID].Name >> Cstm[ID].Blnc;
			cout << "\n[계좌개설]\n" << "계좌 ID:" << Cstm[ID].ID << endl <<
				"이름: " << Cstm[ID].Name << endl << "입금액: " << Cstm[ID].Blnc << endl << endl;
			break;
		case 2:
			cout << "입금: (ID,입금액)" << endl;
			cin >> ID >> Amnt;
			Cstm[ID].Blnc += Amnt;
			cout << "\n[ 입 금 ]\n" << "계좌 ID:" << Cstm[ID].ID << endl <<
				"입금액: " << Amnt << endl << "잔고: " << Cstm[ID].Blnc << endl << endl;
			break;
		case 3:
			cout << "출금: (ID,출금액)" << endl;
			cin >> ID >> Amnt;
			Cstm[ID].Blnc -= Amnt;
			cout << "\n[ 출 금 ]\n" << "계좌 ID:" << Cstm[ID].ID << endl <<
				"출금액: " << Amnt << endl << "잔고: " << Cstm[ID].Blnc << endl << endl;
			break;
		case 4:
			cout << "\n[전체 계좌조회]\n";
			for (int i = 0;i < 256;i++) {
				if (Cstm[i].ID != 0) {
					 cout<< "계좌 ID:" << Cstm[i].ID << endl <<
						"이름: " << Cstm[i].Name << endl << "입금액: " << Cstm[i].Blnc << endl << endl;
				}
				else continue;
			}
			break;
		case 5:
			flag = 1;
		}

	}
}
