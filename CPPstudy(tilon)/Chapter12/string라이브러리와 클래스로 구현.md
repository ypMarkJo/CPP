## string라이브러리 기능을 구현한 String 클래스 구현.
```C++
#include<iostream>
#include<cstring>
using namespace std;

class String {
private:
	char* str;
	int len;
public:
	String():str(NULL),len(0) {};
	String(const char* _s);
	String(const String& _s);
	String operator+(const String& s2);
	String& operator=(const String& _s);
	void operator+= (const String& s);
	//String& operator+= (const String& s);
	bool operator==(const String& s);
	friend ostream& operator<<(ostream& os, const String& str);
	friend istream& operator>>(istream& is, String& s);
	~String() { if(str!=NULL)delete[] str; }
};
String::String(const char* _s){
	
	len = strlen(_s)+1;//마무리 공백추가
	str = new char[len];
	strcpy(str, _s);
};
String::String(const String& _s) {
	
	len = _s.len;
	str = new char[len];
	strcpy(str, _s.str);
};
String String::operator+(const String& s2) {
	char* str2 = new char[len + s2.len-1];//마무리 공백이 총 2칸 생김.그래서 -1로 한칸으로.
	strcpy(str2, str);//초기 str설정
	strcat(str2, s2.str);//str에 내용추가
	String temp(str2);
	delete[]str2;
	return temp;
}
String& String::operator=(const String& _s) {
	if (str != NULL) delete[]str;
	len = _s.len;
	str= new char[len];
	strcpy(str, _s.str);
	return *this;
};
//String& String::operator+= (const String& s)//<---왜 String 리턴?
//{
//	len += (s.len - 1);
//	char* tempstr = new char[len];
//	strcpy(tempstr, str);
//	strcat(tempstr, s.str);
//
//	if (str != NULL)
//		delete[]str;
//	str = tempstr;
//	return *this;
//}

void String::operator+= (const String& s)
{
	*this = *this + s;//<--방법1:객체를 추가적으로 더 생성하므로 성능이 나쁨.

	//len += (s.len - 1);//<--방법2: 코드는 복잡해지지만 성능은 더 좋음.
	//char* tempstr = new char[len];
	//strcpy(tempstr, str);
	//strcat(tempstr, s.str);

	//if (str != NULL)
	//	delete[]str;
	//str = tempstr;
	
}
bool String::operator==(const String& s) {
	return strcmp(str, s.str) ? false : true;//같으면 0반환 뒷쪽 true리턴.
}
ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}
istream& operator>>(istream& is, String& s)
{
	char str3[100];
	is>>str3;
	s = String(str3);
	return is;
}

int main() {
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;

	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}
```
