#include <iostream>
using namespace std;
int row[100], n;
int cnt = 0;
int check(int k) {//���� ������ �Ǵ��� Ȯ���ϴ� �Լ�.
	if (k == 0) return 1;
	for (int i = 0; i < k; i++) {
		if (row[i] == row[k] || abs(row[i] - row[k]) == abs(i - k)) return 0;//row[i]�� row[k]�� ���ٴ� �� �����迭�� ���δٴ� ��. 
	}	                                                                                                          //abs(row[i]-row[k])==abs(i-k) �� �밢���� ��ġ�Ѵٴ� ��. �� �� �ϳ��� �ش�Ǹ� false.
	return 1;
}
void putQ(int i) {// ���� ���ƺ��� �Լ�.
		// [A1:  i==n: ���ϴ� ũ���� ������ ����� i�� ����Ǿ���. == ���� �� �࿡ �ϳ��� ��ġ�� �ƴ�.]
	if (i == n) {
		cnt++;
		//system("cls");
		cout << "������� ã�� ��� : " << cnt << endl << endl;;
		        //------------[A2 : �� ��ġ ����ȭ �ڵ� ��]------------------
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == row[i]) cout << "��";
				else if(i%2==j%2) cout << "��";
				else cout << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}	         //-------------------[ A2: ������� ]------------------------
	//=======================[ A1 : �� ]====================================
	for (int j = 0; j <n; j++) {
		row[i] = j;//row�� ����ִ� ������ �� ���� ���� ���̴� ��(column)�� ��ġ
		if (check(i) == 1) putQ(i + 1);//Check�� ���� �����迭 /�밢�� �迭�� ����  ���� �� ������ �ű⿡ ���� ���� ������ ���� false�� �� ���� ���� ���� ���ƺ�.
	}
}
int main() 
{
	cout << "ü������ ũ�� (�ִ�:100 X 100)" << endl << "->";
	cin >> n;
	putQ(0);
	cout << "�� ��� ��: "<<cnt << endl;
  } 