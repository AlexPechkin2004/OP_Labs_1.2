#include "Header.h"

void AddElement(Branch*& branch, double element) {
	if (!branch) {
		branch = new Branch;
		branch->leftBranch = NULL;
		branch->rightBranch = NULL;
		branch->data = element;
		return;
	}

	if (element >= branch->data) {
		AddElement(branch->rightBranch, element);
	}
	else {
		AddElement(branch->leftBranch, element);
	}
}

void TreeOutput(Branch* branch, int tabs) {
	if (!branch) {
		return;
	}
	TreeOutput(branch->rightBranch, ++tabs);

	for (int i = 1; i < tabs; i++) {
		cout << "\t";
	}
	cout << branch->data << endl;

	TreeOutput(branch->leftBranch, tabs);
}

void SwapMaxAndMin(Branch*& branch) {
	if (!branch) {
		return;
	}
	double max = getMax(branch);
	double min = getMin(branch);
	setMinOnMaxPosition(branch, min);
	setMaxOnMinPosition(branch, max);

}

double getMin(Branch* branch) {
	if (branch->leftBranch != NULL) {
		return getMin(branch->leftBranch);
	}
	else {
		return branch->data;
	}
}

double getMax(Branch* branch) {
	if (branch->rightBranch != NULL) {
		return getMax(branch->rightBranch);
	}
	else {
		return branch->data;
	}
}

void setMinOnMaxPosition(Branch*& branch, double value) {
	if (branch->rightBranch != NULL) {
		setMinOnMaxPosition(branch->rightBranch, value);
	}
	else {
		branch->data = value;
		return;
	}
}

void setMaxOnMinPosition(Branch*& branch, double value) {
	if (branch->leftBranch != NULL) {
		setMaxOnMinPosition(branch->leftBranch, value);
	}
	else {
		branch->data = value;
		return;
	}
}