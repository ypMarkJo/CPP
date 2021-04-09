![image](https://user-images.githubusercontent.com/80379900/113986106-d666cb80-9887-11eb-8cfd-74fce0a8832e.png)

> **UML(Unified Modeling Language)에서 화살표는 상속을 의미하며 화살표의 머리는 기초 클래스를 향해야한다.** 

- 테블릿은 노트북의 일종이고 노트북은 컴퓨터의 일종이다.

**↓ IS-A 상속 예제**

```C++
#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "요청 내용을 계산합니다." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int battary;
public:
	NotebookComp(char* name, int initChag)
		: Computer(name), battary(initChag)
	{  }
	void Charging() { battary += 5; }
	void UseBattary() { battary -= 1; }
	void MovingCal()
	{
		if (GetBattaryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}

		cout << "이동하면서 ";
		Calculate();
		UseBattary();
	}
	int GetBattaryInfo() { return battary; }
};

class TabletNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(char* name, int initChag, char* pen)
		: NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void Write(char* penInfo)
	{
		if (GetBattaryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattary();
	}
};

int main(void)
{
	NotebookComp nc((char*)"이수종", 5);
	TabletNotebook tn((char*)"정수영", 5, (char*)"ISE-241-242");
	nc.MovingCal();
	tn.Write((char*)"ISE-241-242");
	return 0;
}
```
> **IS-A나 HAS-A상속은 두 클래스 객체가 강한 연관이 있을 때만 효율성이 생긴다.**
> 
> -> **예를 들어 총과 경찰을 표현하는데는 경찰이 총이 없는 경우도 있으므로 상속은 부적절하다.** 

**↓ HAS-A 상속 예제**

```C++
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;    	// 장전된 총알의 수
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shut()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;    // 소유한 수갑의 수
	Gun* pistol;     // 소유하고 있는 권총
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shut()//상속이면 재정의를 하지않고 사용가능하지만
			// 피스톨 객체로 쓰기 때문에 재정의가 필요하다.
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shut();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman1(5, 3);
	pman1.Shut();
	pman1.PutHandcuff();

	Police pman2(0, 3);     // 권총소유하지 않은 경찰
	pman2.Shut();
	pman2.PutHandcuff();
	return 0;
}
```
