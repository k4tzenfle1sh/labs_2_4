#include <iostream>
#include <cmath>

using namespace std;

const double L = -0.2603; // L = -1/(max(G(x))

double F(double x)
{
	return cos(x) - pow(x, 3) + 2; //function
}

double G(double x)
{
	return (-1)*sin(x) - 3 * pow(x, 2); //derivative
}


void dichotom(double x0, double x1, double eps)
{
	int n = 1;
	double f0, f1, f, x;

	f0 = F(x0);
	f1 = F(x1);

	do
	{
		x = (x0 + x1) / 2;
		f = F(x);

		cout << "Iteration: " << n << ":\t x = " << x << " equal f(x) = " << f << endl;

		if (F(x)*F(x0) < 0)
			x1 = x;
		else x0 = x;

		n++;

	} while (fabs(f) > eps);

	cout << "Equal is: " << x << endl << "Iteretion's count: " << n << endl;
}

void chord(double x0, double x1, double eps) {
	double x = NULL,
		f0, f1, f;
	int n = 1;
	bool isZero = false;

	f0 = F(x0);
	f1 = F(x1);
	do {
		if (f1 - f0 == 0) {
			cout << "Divided by zero." << endl;
			isZero = true;
			break;
		}
		else {
			x = x0 - (x1 - x0) * f0 / (f1 - f0);
			f = F(x);

			cout << "Iteration: " << n << ":\t x = " << x << " equal f(x) = " << f << endl;

			if (f0 * f < 0)
			{
				x0 = x;
				f0 = f;
			}
			else
			{
				x1 = x;
				f1 = f;
			}
			n++;
		}
	} while (fabs(f) > eps);

	if (!isZero)
		cout << "Equal is: " << x << endl << "Iteretion's count: " << n << endl;
	else
		cout << "unexpected error. exit." << endl;
}

void newton(double x0, double x1, double eps)
{
	double x = NULL;
	int n = 1;
	double f0, g0;

	do
	{
		g0 = G(x0);
		f0 = F(x0);
		if (g0 == 0.0)
		{
			cout << "Divided by zero. Derivative is equal " << x0 << endl;
			break;
		}
		else {
			x1 = x0 - (f0 / g0);

			cout << "Iteration: " << n << ":\t x = " << x1 << " equal f(x) = " << F(x1) << endl;
			x0 = x1;
			n++;
		}

	} while (fabs(F(x1))> eps);

	cout << "Equal is: " << x0 << endl << "Iteretion's count: " << n << endl;
}

void secant(double x0, double x1, double eps)
{
	double x = NULL,
		x2 = NULL;
	int n = 1;
	double f0, f1, f2;

	do
	{
		f0 = F(x0);
		f1 = F(x1);

		x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
		f2 = F(x2);

		cout << "Iteration: " << n << ":\t x = " << x2 << " equal f(x) = " << f2 << endl;

		x0 = x1;
		f0 = f1;

		x1 = x2;
		f1 = f2;

		n++;

	} while (fabs(F(x1)) > eps);

	cout << "Equal is: " << x2 << endl << "Iteretion's count: " << n << endl;
}

void iteration(double x0, double eps)
{
	int n = 1;
	double x = NULL, temp;

	cout << "Iteration: " << n << ":\t x = " << x0 << endl;
	do
	{
		x = x0 - (L*F(x0));
		cout << "Iteration: " << n << ":\t x = " << x << endl;

		n++;

		temp = x0;
		x0 = x;

	} while (fabs(temp - x0) > eps);

	cout << "Equal is: " << x << endl << "Iteretion's count: " << n << endl;
}

int main()
{
	double x0, x1,
		eps;
	cout << "the interval low limit: ";
	cin >> x0;
	cout << "the interval high limit: ";
	cin >> x1;
	cout << "calculation accuracy: ";
	cin >> eps;

	cout << "\ndichotomy:" << endl;
	dichotom(x0, x1, eps);

	cout << "\nchord method:" << endl;
	chord(x0, x1, eps);

	cout << "\nNewton's method:" << endl;
	newton(x0, x1, eps);

	cout << "\nsecant method:" << endl;
	secant(x0, x1, eps);

	cout << "\niteration method:" << endl;
	iteration(x0, eps);

	system("pause");
	return 0;
}
