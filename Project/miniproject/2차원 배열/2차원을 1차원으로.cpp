//#include<iostream>
//#include<time.h>
//using namespace std;
//
//int main() {
//	srand((unsigned int)time(NULL));
//	int a[3][4] = { 0, };
//	int* Pa = (int*)a;
//	for (int i = 0; i < 12; i++) {
//			Pa[i] = (rand() % 10 + 1);
//      printf("%4d ", Pa[i]);
//	}
//	printf("\n========================================\n");
//
//	int b[4][5] = { 0, };
//	int* Pb = (int*)b; 
//	for (int i = 0; i < 20;i++) {
//		Pb[i] = (rand() % 10 + 1);
//		printf("%4d ", Pb[i]);
//	}
//	printf("\n========================================\n");
//	int c[3][5] = { 0, };
//	int* Pc = (int*)c;
//	int sum = 0;
//	for(int i=0;i<3;i++){
//		for (int j = 0; j < 5; j++) {
//			for (int k=0; k < 4; k++) {
//				sum Pa[4 * i + k] * Pb[5 * k+ j];
//				Pc[5 * i + j] += sum;
//			}
//         //c[i][j] = (a[i][0] * b[0][j]) + (a[i][1] * b[1][j]) + (a[i][2] * b[2][j]) + (a[i][3] * b[3][j]);
//		}
//			
//		}
//	for (int i = 0; i < 15; i++){
//		printf("%4d",Pc[i]);
//	}
//	
//	
//
//	return 0;
//}