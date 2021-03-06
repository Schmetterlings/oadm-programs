#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int nOfFVar, nOfineq, nOfVarPower, coefOfVal;
	double coefOfMultiVar;

	cout << "Number of function variables: ";
	cin >> nOfFVar;

	cout << "Number of inequalities: ";
	cin >> nOfineq;

	int i,a;

	double** matrixD = new double*[nOfFVar+nOfineq];
	double** matrixQ = new double*[nOfFVar+nOfineq];

	for (i = 0; i < nOfFVar + nOfineq; i++)
	{
		matrixD[i] = new double[nOfFVar + nOfineq];
		matrixQ[i] = new double[nOfFVar + nOfineq];
		for (a = 0; a < nOfFVar+nOfineq; a++)
		{
			matrixD[i][a] = 0;
		}
	}

	cout << "Coeffient of variable1 * variable2: ";
	cin >> coefOfMultiVar;
	matrixD[0][1] = coefOfMultiVar/2;
	matrixD[1][0] = coefOfMultiVar/2;

	for (i = 0; i < nOfFVar; i++)
	{
		cout << "Coefficient of variable to power of 2 number " << i + 1 << ": ";
		cin >> matrixD[i][i];
	}

	for (i = 0; i < nOfFVar + nOfineq; i++)
	{
		for (a = 0; a < nOfFVar; a++)
		{
			matrixQ[i][a] = matrixD[i][a] * 2;
		}
	}

	double* matrixC = new double[nOfFVar + nOfineq];
	for (i = 0; i < nOfFVar+nOfineq; i++)
	{
		if (i < nOfFVar) 
		{
			cout << "Coefficient of variable without power number "<< i + 1 <<": ";
			cin >> matrixC[i];
		}
		else {
			matrixC[i] = 0;
		}
	}

	double** matrixA = new double* [nOfineq * 2];
	for (i = 0; i < nOfineq*2; i++)
	{
		matrixA[i] = new double[nOfineq+nOfFVar];
		for (a = 0; a < nOfFVar+nOfineq; a++)
		{
			if (a >= nOfFVar && (a - nOfFVar == i))
			{
				matrixA[i][a] = 1;
			}else {
				matrixA[i][a] = 0;
			}
		}
	}

	for (i = 0; i < nOfineq; i++)
	{
		for (a = 0; a < nOfFVar; a++)
		{
			cout << "Coefficient of " << a+1 << " variable in " << i+1 << " inequality: ";
			cin >> matrixA[i][a];
		}
	}

	double* matrixb = new double[nOfineq];
	for (i = 0; i < nOfineq; i++)
	{
		cout << "Beta value of inequalities number " << i + 1 <<": ";
		cin >> matrixb[i];
	}

	double** matrixDelta = new double* [nOfFVar + nOfineq];
	for (i = 0; i < nOfFVar + nOfineq; i++)
	{
		matrixDelta[i] = new double[nOfFVar + nOfineq];
		for (a = 0; a < nOfFVar + nOfineq; a++)
		{
			if (a == i) {
				if ((-1 * matrixC[i] - (matrixD[i][nOfFVar] * matrixb[i] + matrixD[i][nOfFVar + 1] * matrixb[i + 1])) < 0) {
					matrixDelta[i][a] = -1;
				}
				else {
					matrixDelta[i][a] = 1;
				}
			}
			else {
				matrixDelta[i][a] = 0;
			}
			
		}
	}

	double** matrixOdd = new double* [nOfFVar + nOfineq];
	for (i = 0; i < nOfFVar + nOfineq; i++)
	{
		matrixOdd[i] = new double[nOfFVar + nOfineq];
		for (a = 0; a < nOfFVar + nOfineq; a++)
		{
			if (i == a) {
				matrixOdd[i][a] = -1;
			}
			else {
				matrixOdd[i][a] = 0;
			}
		}
	}

	int c;
	double** bigMatrix = new double* [nOfFVar + nOfineq*2];
	for (i = 0; i < nOfFVar + nOfineq * 2; i++) {
		c = 0;
		bigMatrix[i] = new double[3 * nOfFVar + 5 * nOfineq];
		if (i < nOfineq) {
			for (a = 0; a < nOfFVar + nOfineq; a++) {
				bigMatrix[i][c] = matrixA[i][a];
				c++;
			}
			for (a = 0; a < 2 * nOfFVar + 4 * nOfineq; a++) {
				bigMatrix[i][c] = 0;
				c++;
			}
		}
		else {
			for (a = 0; a < nOfineq+nOfFVar; a++) {
				bigMatrix[i][c] = matrixQ[i-nOfineq][a];
				c++;
			}
			for (a = 0; a < nOfineq; a++) {
				bigMatrix[i][c] = matrixA[a][i-nOfineq];
				c++;
			}
			for (a = 0; a < nOfineq; a++) {
				bigMatrix[i][c] = matrixA[a][i- nOfineq]*-1;
				c++;
			}
			for (a = 0; a < nOfFVar + nOfineq; a++) {
				bigMatrix[i][c] = matrixOdd[i- nOfineq][a];
				c++;
			}
			for (a = 0; a < nOfFVar + nOfineq; a++) {
				bigMatrix[i][c] = matrixDelta[i- nOfineq][a];
				c++;
			}
		}

	}

	for (i = 0; i < nOfFVar + nOfineq * 2; i++) {
		for (a = 0; a < 3 * nOfFVar + 5 * nOfineq; a++) {
			cout << setw(4) << bigMatrix[i][a];
		}
		cout << endl;
	}

}