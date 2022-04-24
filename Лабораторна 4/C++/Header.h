#pragma once
#include <iostream>
#include <thread>

using namespace std;

class BoolMatrix
{
private:
	int m, n, ** M, **temp, counter=0;

public:
	BoolMatrix();
	BoolMatrix(int m, int n);
	BoolMatrix operator|(BoolMatrix M2);
	BoolMatrix operator~();

	void set_m(int m_);
	void set_n(int n_);
	
	void count1();

	int** getM();
	int getCounter();
};

void output(BoolMatrix, int, int);