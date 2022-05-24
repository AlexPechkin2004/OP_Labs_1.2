#pragma once
#pragma once
#include <iostream>

using namespace std;

struct Branch {
	double data;
	Branch* leftBranch;
	Branch* rightBranch;
};

void AddElement(Branch*&, double);
void TreeOutput(Branch*, int);
void SwapMaxAndMin(Branch*&);
double getMax(Branch*);
double getMin(Branch*);
void setMinOnMaxPosition(Branch*&, double);
void setMaxOnMinPosition(Branch*&, double);