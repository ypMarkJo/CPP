#include <iostream>
#include <string>
#include <vector>
#include "SHA256.h"

using namespace std;

string makeMerkleString(vector<string>& v)
{
	//v의 개수를 체크해서 홀수면 최종원소를 하나 더 복사
	if (v.size() % 2 != 0)
	{
		v.push_back(v.back());
	}
	//각 원소들에 대해 두개씩 더해서 SHA256*2 실행
	//임시 벡터 변수를 만들어서 저장
	vector<string> v2;
	for (int i = 0; i < (v.size()/2); i++)
	{
		string t = v[2*i] + v[2*i+1];
		v2.push_back(sha256(sha256(t)));
		//v2[i]=sha256(sha256(t)) 라고 쓰면 배열의 메모리가 확보가 안돼서 에러가 남.
	}
	//저장된 벡터를 다시 makeMarketing 함수 호출에 사용
	if (v2.size() == 1) return v2[0];
	return makeMerkleString(v2);
}
int main(int argc, char* argv[])
{
	vector<string> vec;

	vec.push_back("{sender:tom, receiver:john, amount:10, tid=abcd3432eqvfdfdbfwfwe}");
	vec.push_back("{sender:joe, receiver:david, amount:1, tid=1dwefq2feqefefewf34}");
	vec.push_back("{sender:abc, receiver:dddd, amount:2, tid=1ew1e1we1vfdsfvddfew1}");
	vec.push_back("{sender:123c, receiver:345, amount:5, tid=fvd1vdfv2vdv2fdv2fdv2}");
	vec.push_back("{sender:023c, receiver:045, amount:5, tid=1fdvdf2svsdv sdv0a00}");

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = sha256(sha256(vec[i]));
	}
		cout << "MerkleString : " << makeMerkleString(vec) << endl;
	return 0;
}