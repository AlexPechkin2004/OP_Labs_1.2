#include "header.h"

int main()
{
	int m, n;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;
	cout << "Matrix 1:" << endl;
	BoolMatrix M1 = BoolMatrix(m, n);
	output(M1, m, n);
	std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000));
	cout << "Matrix 2:" << endl;
	BoolMatrix M2 = BoolMatrix(m, n);
	output(M2, m, n);

	BoolMatrix M3;
	M1.set_m(m);
	M1.set_n(n);
	M2.set_m(m);
	M2.set_n(n);
	M3.set_m(m);
	M3.set_n(n);

	cout << "Matrix 3:" << endl;
	M3 = M1 | M2;
	output(M3, m, n);

	cout << "Matrix 3 inversion:" << endl;
	M3 = ~M3;
	output(M3, m, n);

	M3.count1();
	cout << "Matrix 3 inversion contains " << M3.getCounter() << " numbers 1" << endl;
}
