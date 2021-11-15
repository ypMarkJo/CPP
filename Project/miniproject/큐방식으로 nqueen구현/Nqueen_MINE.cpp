#include <iostream>
using namespace std;
int row[100], n;
int cnt = 0;
int check(int k) {//퀸이 놓여도 되는지 확인하는 함수.
	if (k == 0) return 1;
	for (int i = 0; i < k; i++) {
		if (row[i] == row[k] || abs(row[i] - row[k]) == abs(i - k)) return 0;//row[i]와 row[k]가 같다는 건 직선배열에 놓인다는 뜻. 
	}	                                                                                                          //abs(row[i]-row[k])==abs(i-k) 는 대각선에 위치한다는 뜻. 둘 중 하나라도 해당되면 false.
	return 1;
}
void putQ(int i) {// 퀸을 놓아보는 함수.
		// [A1:  i==n: 원하는 크기의 마지막 행까지 i가 진행되었다. == 퀸이 한 행에 하나씩 배치가 됐다.]
	if (i == n) {
		cnt++;
		//system("cls");
		cout << "현재까지 찾은 방법 : " << cnt << endl << endl;;
		        //------------[A2 : 퀸 위치 도식화 코딩 ↓]------------------
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == row[i]) cout << "☆";
				else if(i%2==j%2) cout << "■";
				else cout << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}	         //-------------------[ A2: 여기까지 ]------------------------
	//=======================[ A1 : 끝 ]====================================
	for (int j = 0; j <n; j++) {
		row[i] = j;//row에 담아주는 정보는 그 행의 퀸이 놓이는 열(column)의 위치
		if (check(i) == 1) putQ(i + 1);//Check를 통해 직선배열 /대각선 배열에 퀸을  놓을 수 있으면 거기에 놓고 다음 행으로 진출 false면 그 다음 열에 퀸을 놓아봄.
	}
}
int main() 
{
	cout << "체스판의 크기 (최대:100 X 100)" << endl << "->";
	cin >> n;
	putQ(0);
	cout << "총 방법 수: "<<cnt << endl;
  } 