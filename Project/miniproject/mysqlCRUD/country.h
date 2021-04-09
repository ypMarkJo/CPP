#pragma once

#include <string>
using namespace std;

class Country
{
public:
    Country()
    {
        Code = Name = Continent = Region = SurfaceArea = "";
        IndepYear = Population = LifeExpectancy = GNP = GNPOld = "";
        LocalName = GovernmentForm = HeadOfState = Capital = Code2 = "";
    }

    ~Country() {}

    string Code, Name, Continent, Region, SurfaceArea, IndepYear, Population, LifeExpectancy, GNP, GNPOld, LocalName, GovernmentForm, HeadOfState, Capital, Code2;

    void print()
    {
        printf("%s\n ", Code.c_str());   // .c_str() => char형 포인터를 넘겨줄때 사용..?
        printf("%s\n ", Name.c_str());
        printf("%s\n ", Continent.c_str());
        printf("%s\n ", Region.c_str());
        printf("%s\n ", SurfaceArea.c_str());
        printf("%s\n ", IndepYear.c_str());
        printf("%s\n ", Population.c_str());
        printf("%s\n ", LifeExpectancy.c_str());
        printf("%s\n ", GNP.c_str());
        printf("%s\n ", GNPOld.c_str());
        printf("%s\n ", LocalName.c_str());
        printf("%s\n ", GovernmentForm.c_str());
        printf("%s\n ", HeadOfState.c_str());
        printf("%s\n ", Capital.c_str());
        printf("%s\n ", Code2.c_str());
    }

};

