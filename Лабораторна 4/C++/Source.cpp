#include "header.h"

BoolMatrix::BoolMatrix() 
{
}

BoolMatrix::BoolMatrix(int m, int n)
{
	M = new int* [m];
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		M[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			M[i][j] = rand() % 2;
		}
	}
}

BoolMatrix BoolMatrix::operator|(BoolMatrix M2)
{
	temp = new int* [m];
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		temp[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			if (M[i][j] == 0 && M2.getM()[i][j] == 0)
			{
				temp[i][j] = 0;
			}
			else
			{
				temp[i][j] = 1;
			}
		}
	}
	M = temp;
	return *this;
}

BoolMatrix BoolMatrix::operator~()
{
	temp = new int* [m];
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		temp[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			if (M[i][j] == 0)
			{
				temp[i][j] = 1;
			}
			else
			{
				temp[i][j] = 0;
			}
		}
	}
	M = temp;
	return *this;
}

int** BoolMatrix::getM()
{
	return M;
}

int BoolMatrix::getCounter()
{
	return counter;
}

void BoolMatrix::set_m(int m_)
{
	m = m_;
}

void BoolMatrix::set_n(int n_)
{
	n = n_;
}

void BoolMatrix::count1()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (M[i][j] == 1)
			{
				counter++;
			}
		}
		cout << endl;
	}
}

void output(BoolMatrix M, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(6);
			cout << M.getM()[i][j];
		}
		cout << endl;
	}
}