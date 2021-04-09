#include<iostream>
#include<stack>
#include<time.h>
using namespace std;

typedef struct point
{
	int x;
	int y;
}POINT;

int main() {
	srand(time(NULL));
    POINT pt;
    pt.x = 0;
    pt.y = 0;
    stack <POINT> s;
 
    while (1) {
        pt.x += (rand() % 5) - 2;
        pt.y += (rand() % 5) - 2;
        if (pt.x < 0)pt.x = 0;
        else if (pt.x > 18)pt.x = 18;
        if (pt.y < 0)pt.y = 0;
        s.push(pt);     
        if (pt.x == 18 && pt.y == 18)break;
    }
    while(1){
        cout <<"경로수: "<<s.size()<<"x값: "<<s.top().x<<"y값: "<<s.top().y << endl;
        s.pop();
        if (s.size() == 0)break;
    }
}
