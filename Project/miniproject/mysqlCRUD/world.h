#include <string>
#include <vector>
using namespace std;

class World
{
public:
    

public:
    World() {}
    ~World() {}

    virtual void print()=0;
    virtual void save(MYSQL_ROW& row)=0;
    
};

class Country : public World
{
public:
    string Code, Name, Continent, Region, SurfaceArea,
        IndepYear, Population, LifeExpectancy, GNP, GNPOld,
        LocalName, GovernmentForm, HeadOfState, Capital, Code2;

public:
    Country()
    {
        Code, Name, Continent, Region, SurfaceArea,
            IndepYear, Population, LifeExpectancy, GNP, GNPOld,
            LocalName, GovernmentForm, HeadOfState, Capital, Code2 = "";
    }
    ~Country() {}
    void print()
    {
        printf("%s\n", Code.c_str());    //%s <- char*형식의 인수를 받는다.
        printf("%s\n", Name.c_str());
        printf("%s\n", Continent.c_str());
        printf("%s\n", Region.c_str());
        printf("%s\n", SurfaceArea.c_str());
        printf("%s\n", IndepYear.c_str());
        printf("%s\n", Population.c_str());
        printf("%s\n", LifeExpectancy.c_str());
        printf("%s\n", GNP.c_str());
        printf("%s\n", GNPOld.c_str());
        printf("%s\n", LocalName.c_str());
        printf("%s\n", GovernmentForm.c_str());
        printf("%s\n", HeadOfState.c_str());
        printf("%s\n", Capital.c_str());
        printf("%s\n", Code2.c_str());
    }
    void save(MYSQL_ROW& row) {
        int idx = 0;
        if (row[idx])  Code = row[idx]; idx++;
        if (row[idx])  Name = row[idx]; idx++;
        if (row[idx])  Continent = row[idx]; idx++;
        if (row[idx])  Region = row[idx]; idx++;
        if (row[idx])  SurfaceArea = row[idx]; idx++;
        if (row[idx])  IndepYear = row[idx]; idx++;
        if (row[idx])  Population = row[idx]; idx++;
        if (row[idx])  LifeExpectancy = row[idx]; idx++;
        if (row[idx])  GNP = row[idx]; idx++;
        if (row[idx])  GNPOld = row[idx]; idx++;
        if (row[idx])  LocalName = row[idx]; idx++;
        if (row[idx])  GovernmentForm = row[idx]; idx++;
        if (row[idx])  HeadOfState = row[idx]; idx++;
        if (row[idx])  Capital = row[idx]; idx++;
        if (row[idx])  Code2 = row[idx];


    }
};

class City : public World
{
public:
    string ID, Name, CountryCode, District, Population;

public:
    City()
    {
        ID, Name, CountryCode, District, Population="";
    }
    ~City() {}
    void print() {
        //c_str : string 을 char*으로 변환해준다. 받는 인자는 없고, 문자열 배열의 시작 주소값을 리턴한다. C 스타일의 문자 배열로 string객체를 복사하고 싶을때는 c_str함수를 사용.
        printf("%s\n", ID.c_str());
        printf("%s\n", Name.c_str());
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", District.c_str());
        printf("%s\n", Population.c_str());
    }
    void save(MYSQL_ROW& row) {
        int idx = 0;
        if (row[idx])   ID = row[idx]; idx++;
        if (row[idx])   Name = row[idx]; idx++;
        if (row[idx])   CountryCode = row[idx]; idx++;
        if (row[idx])   District = row[idx]; idx++;
        if (row[idx])   Population = row[idx];
    }
};

class CountryLanguage : public World
{
public:
       string CountryCode, Language, IsOfficial, Percentage;

public:
    CountryLanguage()
    {
        CountryCode, Language, IsOfficial, Percentage="";
    }
    ~CountryLanguage() {}
    void print() {
        printf("%s\n", CountryCode.c_str());
        printf("%s\n", Language.c_str());
        printf("%s\n", IsOfficial.c_str());
        printf("%s\n", Percentage.c_str());

    }
    void save(MYSQL_ROW& row) {
        int idx = 0;

        if (row[idx])  CountryCode = row[idx]; idx++;
        if (row[idx])  Language = row[idx]; idx++;
        if (row[idx])  IsOfficial = row[idx]; idx++;
        if (row[idx])  Percentage = row[idx];

    }
};
