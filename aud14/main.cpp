#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

const int n = 10;

struct Matrix
{
	int size;	
	int** matx;
	int id;

	void memory_allocation()
	{
		matx = new int* [size];
		for (int i = 0; i < size; i++)
			matx[i] = new int[size];
	}

	void generateRandom()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matx[i][j] = rand() % 20 + 1;
	}

	void input()
	{
		size = rand() % 10 + 1;
		cout << size << endl;
		memory_allocation();
		/*for (int i = 0 ; i < size ; i++)
			for (int j = 0; j < size; j++)
			{
				cin >> matx[i][j];
			}*/
		generateRandom();
	}

	void input(int x)
	{
		size = x;
		cout << size << endl;
		memory_allocation();
		/*for (int i = 0 ; i < size ; i++)
			for (int j = 0; j < size; j++)
			{
				cin >> matx[i][j];
			}*/
		generateRandom();
	}

	void output()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matx[i][j] << " " ;
			}
			cout << endl;
		}
	}

	void output(string FileName, Matrix* x)
	{
		ofstream file;
		file.open(FileName);
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
};



int main()
{
	srand(time(0));
	
	Matrix* m = new Matrix [n];
	for (int i = 0; i < n; i++)
	{
		m[i].input();
		m[i].output();
		m[i].id = i;
		cout << endl;
	}
	m->output("Test.txt",m);

}