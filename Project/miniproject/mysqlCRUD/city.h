#include <string>
using namespace std;

class City {
public:
    string Name, CountryCode, District, Population;

    City() {
        Name = "";
        CountryCode = "";
        District = "";
        Population = "";
    }
    ~City() {}


    void print() {
        //c_str : string 을 char*으로 변환해준다. 받는 인자는 없고, 문자열 배열의 시작 주소값을 리턴한다. C 스타일의 문자 배열로 string객체를 복사하고 싶을때는 c_str함수를 사용.
        printf("%s\n", Name.c_str());
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", District.c_str());
        printf("%s\n", Population.c_str());
    }
};