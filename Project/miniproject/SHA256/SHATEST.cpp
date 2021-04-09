#include <iostream>
#include <string>
#include <vector>
#include "SHA256.h"

using namespace std;

string makeMerkleString(vector<string>& v)
{
	//v�� ������ üũ�ؼ� Ȧ���� �������Ҹ� �ϳ� �� ����
	if (v.size() % 2 != 0)
	{
		v.push_back(v.back());
	}
	//�� ���ҵ鿡 ���� �ΰ��� ���ؼ� SHA256*2 ����
	//�ӽ� ���� ������ ���� ����
	vector<string> v2;
	for (int i = 0; i < (v.size()/2); i++)
	{
		string t = v[2*i] + v[2*i+1];
		v2.push_back(sha256(sha256(t)));
		//v2[i]=sha256(sha256(t)) ��� ���� �迭�� �޸𸮰� Ȯ���� �ȵż� ������ ��.
	}
	//����� ���͸� �ٽ� makeMarketing �Լ� ȣ�⿡ ���
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