//4X4 배열에 한 row에 퀸 하나씩 총 4개의 퀸이 서로 공격할 수 없게 공존.
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
	if (startX == mapSize) return true;//리프노드(트리의 말단)까지 왔다면 리턴

	for (; startY < mapSize; startY++)//반복할 때마다 오른쪽으로 한칸씩 검색
	{
		if (mapmap[startX][startY] == NOT || mapmap[startX][startY] == QUEEN) continue;
		else if (mapmap[startX][startY] == CAN && mapmap[startX][startY] != QUEEN)
		{
			for (int i = 0; i < Maxsize; i++)
				for (int j = 0; j < Maxsize; j++)
					tempMap[i][j] = mapmap[i][j];

			tempMap[startX][startY] = QUEEN;//현재 좌표  퀸으로 지정.
			//NOT처리 시작.(가로 먼저)
			for (int i = 0; i < mapSize; i++)
				if (tempMap[startX][i] == CAN && tempMap[startX][i] != QUEEN) tempMap[startX][i] = NOT;
			//NOT처리 세로
			for (int i = startX + 1; i < mapSize; i++)
				if (tempMap[i][startY] == CAN && tempMap[i][startY] != QUEEN) tempMap[i][startY] = NOT;
			//NOT처리 왼쪽 대각선
			int tempX = startX + 1; int tempY=startY -1;
			for (int i = startX + 1; i < mapSize; i++)
			{
				if (tempX >= mapSize || tempY < 0) break;
				else if (tempMap[tempX][tempY] == CAN && tempMap[tempX][tempY] != QUEEN) tempMap[tempX][tempY] = NOT;
				tempX++; tempY--;
			}
			//NOT처리 오른쪽 대각선
			tempX = startX + 1; tempY = startY + 1;
			for (int i = startX + 1; i < mapSize; i++)
			{
				if (tempX >= mapSize || tempY >= mapSize) break;
				else if (tempMap[tempX][tempY] == CAN && tempMap[tempX][tempY] != QUEEN) tempMap[tempX][tempY] = NOT;
				tempX++; tempY++;
			}//----------------------------------------NOT처리 종료.
			
		
			if (startX == mapSize - 1)
			{
				system("cls");
				answer++;
				int bw = 1;
				cout << mapSize << " X " << mapSize << " 의 체스판에 " << endl << mapSize << " 개의 퀸이 위치하는 방법." << endl << "지금까지  " << answer << " 개 찾음" << endl;
				cout << "┌ ";
				for (int i = 0; i < mapSize*2; i++)	cout << "-";
				cout <<"┐"<< endl;
				for (int i = 0; i < mapSize; i++)//answer 도식화
				{ 
					cout << "│ ";  
					for (int j = 0; j < mapSize; j++)
					{ 
						if (tempMap[i][j] == 2) cout << "♡";
						else if (j%2==i%2) cout << "■";
						else  cout << "  ";
					}
					cout <<"│"<< endl;
				}
				cout << "└ ";
				for (int i = 0; i < mapSize * 2; i++)	cout << "-";
				cout << "┘" << endl;
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