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
        //c_str : string �� char*���� ��ȯ���ش�. �޴� ���ڴ� ����, ���ڿ� �迭�� ���� �ּҰ��� �����Ѵ�. C ��Ÿ���� ���� �迭�� string��ü�� �����ϰ� �������� c_str�Լ��� ���.
        printf("%s\n", Name.c_str());
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", District.c_str());
        printf("%s\n", Population.c_str());
    }
};