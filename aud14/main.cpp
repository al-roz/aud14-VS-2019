#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

const int n = 10;

struct MATRIX
{
	int size;	
	int** matx;
	int id;
};

typedef struct MATRIX Matrix;

void memory_allocation(Matrix* x)
{
	x->matx = new int* [x->size];
	
	for (int i = 0; i < x->size; i++)
	{
		x->matx[i] = new int[x->size];
	}
}

void generateRandom(Matrix* x)
{
	for (int i = 0; i < x->size; i++)
		for (int j = 0; j < x->size; j++)
			x->matx[i][j] = rand() % 20 + 1;
}

void input(Matrix* x)
{
	x->size = rand() % 10 + 1;
	cout << x->size << endl;
	memory_allocation(x);

	//for (int i = 0; i < x->size; i++)
	//	for (int j = 0; j < x->size; j++)
	//		cin >> x->matx[i][j];

	generateRandom(x);
}

void input(Matrix* x, int size)
{
	x->size = size;
	cout << x->size << endl;
	memory_allocation(x);

	//for (int i = 0; i < x->size; i++)
	//	for (int j = 0; j < x->size; j++)
	//		cin >> x->matx[i][j];

	generateRandom(x);
}

void output(Matrix* x)
{
	for (int i = 0; i < x->size; i++)
	{
		for (int j = 0; j < x->size; j++)
			cout << x->matx[i][j] << " ";
		cout << endl;
	}
}

void output(string FileNamse, Matrix* x)
{
	ofstream file;
	file.open(FileNamse);
	for (int kol = 0; kol < n; kol++)
	{
		
		for (int i = 0; i < x[kol].size; i++)
		{
			for (int j = 0; j < x[kol].size; j++)
				file << x[kol].matx[i][j] << " ";
			file << endl;
		}
		file << endl;
	}	
	file.close();

}

int main()
{
	srand(time(0));
	
	Matrix* m = new Matrix [n];
	for (int i = 0; i < n; i++)
	{
		input(&m[i]);
		output(&m[i]);
		m[i].id = i;
		cout << endl;
	}

	output("Test.txt", m);
	

}