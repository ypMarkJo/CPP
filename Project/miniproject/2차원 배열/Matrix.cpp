#include<iostream>
#include<ctime>
using namespace std;

class Matrix {
private:
	int R, C;
	int* Term;
public:
	Matrix(int _R, int _C);
	~Matrix();
	Matrix getData();
	void Show() ;
	Matrix* Trans() ;
	Matrix* Multiply(Matrix& M) ;
	Matrix& Add(Matrix& M) ;
};
Matrix::Matrix(int _R, int _C):R(_R),C(_C)
{
	Term = new int [R * C];
}
Matrix::~Matrix()
{
	cout << "dest " << Term << endl;
	delete[] Term;
}
Matrix Matrix::getData()
{
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)	Term[r * C + c] = rand() % 101;
}
void Matrix::Show()
{
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++) cout <<" "<< Term[r * C + c];
		cout << endl;
	}
}
Matrix* Matrix::Trans()
{
	Matrix* T = new Matrix(C,R);
	for (int r = 0; r < C; r++)
	{
		for (int c = 0; c < R; c++)
		{
			T->Term[r * R + c] = Term[c*C+r];
		}
	}
	return T;
}
Matrix* Matrix::Multiply(Matrix& M)
{
	Matrix* MTP = new Matrix(R, M.C);
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < M.C; c++)
		{
			
		}
	}

}