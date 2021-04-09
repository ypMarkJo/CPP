//// 바둑판(19 * 19)에서 돌아다니는 벌레의 궤적을 난수를 발생시켜 누적하는 프로그램 구현
//#include <iostream>
//#include<cstdlib>
//#include<time.h>
//#include<vector>
//using namespace std;
//
//typedef struct Point {
//    int x = 0;
//    int y = 0;
//}POINT;
//
//int main() {
//    srand(time(NULL));
//    POINT pt;
//
//
//    vector<POINT> v;
//    v.push_back(pt);
//
//    while (1)
//    {
//        pt.x += (rand() % 5) - 2;
//        pt.y += (rand() % 5) - 2;
//
//        if (pt.x < 0)   pt.x = 0;
//        else if (pt.x > 18)   pt.x = 18;
//        if (pt.y < 0)   pt.y = 0;
//        else if (pt.y > 18)   pt.y = 18;
//
//        v.push_back(pt);
//
//        if (pt.x == 18 && pt.y == 18) break;
//    }
//
//    for (int i = 0; i < v.size(); i++)
//    {
//        printf("count: %3d, x값: %d,y값: %d\n", i, v[i].x, v[i].y);
//    }
//
//    return 0;
//}