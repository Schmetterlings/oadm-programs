#include <iostream>
#include <cmath>

using namespace std;
double function(double x, double y)
{
	return 10 * pow((x + y - 5), 2) + pow((x - y), 2);
}

double gss(double point[2], double di[2])
{
	double a = -1000;
	double b = 1000;
	double gr = (sqrt(5) - 1) / 2;

	double c, d;
	double eps = 0.0001;

	d = b - gr * (b - a);
	c = a + gr * (b - a);

	while (abs(c - d) > eps)
	{
		if (function(point[0] + c * di[0], point[1] + c * di[1]) > function(point[0] + d * di[0], point[1] + d * di[1]))
		{
			b = c;
			c = d;
			// d = a + (b - c);
			d = b - gr * (b - a);
		}
		else
		{
			a = d;
			d = c;
			// c = b - (d - a);
			c = a + gr * (b - a);
		}
	}

	return (a + b) / 2;
}

int main()
{
	double const eps = 0.0001;
	double point1[2] = {0, 0};
	double point2[2] = {0, 0};
	double d0[2] = {1, 0};
	double d1[2] = {0, 1};
	double alpha;

	while (true)
	{
		cout << "Point 1: " << point1[0] << " " << point1[1] << endl;
		alpha = gss(point1, d0);
		point2[0] = point1[0] + alpha * d0[0];
		point2[1] = point1[1] + alpha * d0[1];

		if (abs(point2[0] - point1[0]) < eps && abs(point2[1] - point1[1]) < eps)
		{
			cout << "X: " << point2[0] << " Y: " << point2[1] << endl;
			cout << "f(X, Y): " << function(point2[0], point2[1]) << endl;
			break;
		}

		cout << "Point 2: " << point2[0] << " " << point2[1] << endl;
		alpha = gss(point2, d1);
		point1[0] = point2[0] + alpha * d1[0];
		point1[1] = point2[1] + alpha * d1[1];

		if (abs(point1[0] - point2[0]) < eps && abs(point1[1] - point2[1]) < eps)
		{
			cout << "X: " << point1[0] << " Y: " << point1[1] << endl
				 << endl;
			cout << "f(X, Y): " << function(point1[0], point1[1]) << endl;
			break;
		}

		cout << "X: " << point1[0] << " Y: " << point1[1] << endl;
		cout << "f(X, Y): " << function(point1[0], point1[1]) << endl
			 << endl;
	}

	return 0;
}