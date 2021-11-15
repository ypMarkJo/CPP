//4X4 �迭�� �� row�� �� �ϳ��� �� 4���� ���� ���� ������ �� ���� ����.
#define Maxsize 12
#define CAN 0
#define NOT 1
#define QUEEN 2

#include<iostream>
#include<cstdlib>
using namespace std;

int answer = 0;
bool FindQueen(int startX,int startY, int mapSize, short(*mapmap)[Maxsize])
{
	startY = 0;
	short tempMap[Maxsize][Maxsize] = { {0,} };
	if (startX == mapSize) return true;//�������(Ʈ���� ����)���� �Դٸ� ����

	for (; startY < mapSize; startY++)//�ݺ��� ������ ���������� ��ĭ�� �˻�
	{
		if (mapmap[startX][startY] == NOT || mapmap[startX][startY] == QUEEN) continue;
		else if (mapmap[startX][startY] == CAN && mapmap[startX][startY] != QUEEN)
		{
			for (int i = 0; i < Maxsize; i++)
				for (int j = 0; j < Maxsize; j++)
					tempMap[i][j] = mapmap[i][j];

			tempMap[startX][startY] = QUEEN;//���� ��ǥ  ������ ����.
			//NOTó�� ����.(���� ����)
			for (int i = 0; i < mapSize; i++)
				if (tempMap[startX][i] == CAN && tempMap[startX][i] != QUEEN) tempMap[startX][i] = NOT;
			//NOTó�� ����
			for (int i = startX + 1; i < mapSize; i++)
				if (tempMap[i][startY] == CAN && tempMap[i][startY] != QUEEN) tempMap[i][startY] = NOT;
			//NOTó�� ���� �밢��
			int tempX = startX + 1; int tempY=startY -1;
			for (int i = startX + 1; i < mapSize; i++)
			{
				if (tempX >= mapSize || tempY < 0) break;
				else if (tempMap[tempX][tempY] == CAN && tempMap[tempX][tempY] != QUEEN) tempMap[tempX][tempY] = NOT;
				tempX++; tempY--;
			}
			//NOTó�� ������ �밢��
			tempX = startX + 1; tempY = startY + 1;
			for (int i = startX + 1; i < mapSize; i++)
			{
				if (tempX >= mapSize || tempY >= mapSize) break;
				else if (tempMap[tempX][tempY] == CAN && tempMap[tempX][tempY] != QUEEN) tempMap[tempX][tempY] = NOT;
				tempX++; tempY++;
			}//----------------------------------------NOTó�� ����.
			
		
			if (startX == mapSize - 1)
			{
				system("cls");
				answer++;
				int bw = 1;
				cout << mapSize << " X " << mapSize << " �� ü���ǿ� " << endl << mapSize << " ���� ���� ��ġ�ϴ� ���." << endl << "���ݱ���  " << answer << " �� ã��" << endl;
				cout << "�� ";
				for (int i = 0; i < mapSize*2; i++)	cout << "-";
				cout <<"��"<< endl;
				for (int i = 0; i < mapSize; i++)//answer ����ȭ
				{ 
					cout << "�� ";  
					for (int j = 0; j < mapSize; j++)
					{ 
						if (tempMap[i][j] == 2) cout << "��";
						else if (j%2==i%2) cout << "��";
						else  cout << "  ";
					}
					cout <<"��"<< endl;
				}
				cout << "�� ";
				for (int i = 0; i < mapSize * 2; i++)	cout << "-";
				cout << "��" << endl;
				continue;
			} 
			FindQueen(startX+1, 0, mapSize, tempMap);
		} 
	}
}
int main()
{
	int mapSize = 0;

	short map[Maxsize][Maxsize] = { {0,} };
	answer = 0;
	cout << "input mapsize(max==12)" << endl << "->";
	cin >> mapSize;

	FindQueen(0, 0, mapSize, map);

	cout << "Answer: " << answer << endl;
	return 0;
}