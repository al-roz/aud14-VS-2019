#include <iostream>
#include <time.h>
#include <fstream>
#include <ctime>
#include <Windows.h>
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
		cout << "size = " << size << endl;
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
		cout << "size = " << size << endl;
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

	Matrix multiplication(Matrix* x)
	{
		if (size != x->size)
		{
			cout << "multiplication is not possible";
		}
		Matrix c;
		c.matx = new int* [size];
		c.size = size;
		for (int i = 0; i < size; i++)
		{
			c.matx[i] = new int[x->size];
			for (int j = 0; j < x->size; j++)
			{
				c.matx[i][j] = 0;
				for (int k = 0; k < size; k++)
					c.matx[i][j] += matx[i][k] * x->matx[k][j];
			}

		}
		return c;
	}
};

class Timer
{
private:
	double _start;
	double _end;
	double res;
	int sec;
	int min;
	void res_ans()
	{
		_end = clock();
		res = (_end - _start) / CLOCKS_PER_SEC;
	}

public:
	void start()
	{
		_start = clock();
	}

	void stop()
	{
		res_ans();
		cout << "time =" << res * 1000 << "ms";
	}
	void stop(string s)
	{
		
		res_ans();
		int x;
		x = (int)res;
		if (s == "s")
		{			
			sec = x;
			cout << "time =" << sec << " s";
		}
		if (s == "m")
		{
			min = sec / 60;
			cout << "time =" << min << " min";
		}
		if (s == "full")
		{
			cout << "time = " << x / 60 << " min " << x % 60 << " s " << res - x << "ms";
		}

	}


};

int main()
{
	srand(time(0));
	Timer t;
	t.start();
	
	Matrix* m = new Matrix [n];
	for (int i = 0; i < n; i++)
	{
		m[i].input();
		m[i].output();
		m[i].id = i;
		cout << endl;
	}
	Matrix k;
	Sleep(2000);
	k = m[0].multiplication(&m[0]);
	m->output("Test.txt",m);
	k.output();
	t.stop();
	

}