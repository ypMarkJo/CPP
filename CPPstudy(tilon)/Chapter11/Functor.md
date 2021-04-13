## 객체를 함수처럼 사용한다.

> 객체를 유동적으로 바꿔 담아줌으로써 마치 원하는 함수를 호출하는 효과를 준다.
> 
> 원리는 가상함수를 상속하는 클래스를 만들어주고 대입되는 객체에 따라 가상함수를 호출하는
> 
> 상속의 특성을 이용한다.

**▼ 예제 코드(버블정렬)**
> 오름차순 객체와 내림차순 객체를 각각 상속시켰다.

```C++
#include <iostream>
using namespace std;

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0;//순수가상함수
};

class AscendingSort : public SortRule   // 오름차순
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class DescendingSort : public SortRule    // 내림차순
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2)
			return true;
		else
			return false;
	}
};

class DataStorage    // for int data
{
private:
	int* arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= idx)
		{
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[idx++] = num;//post-increment operator
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	void SortData(const SortRule& functor)
	{
		for (int i = 0; i < (idx - 1); i++)
		{
			for (int j = 0; j < (idx - 1) - i; j++)
			{
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.SortData(AscendingSort());//객체를 오름차순을 담아줌
	storage.ShowAllData();

	storage.SortData(DescendingSort());//객체를 내림차순을 담아줌
	storage.ShowAllData();
	return 0;
}

```
**결과값:** ![image](https://user-images.githubusercontent.com/80379900/114528723-38f30980-9c84-11eb-90b1-ad4282faa674.png)
