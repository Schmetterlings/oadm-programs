#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float matrixA[3][3] = { {5,3,-1}, {-3,-5,8}, {1,2,-2} };
	float matrixB[3][3] = { {-1,4,-1}, {1,-8,3}, {4,6,-7} };
	float lowestA[3] = { matrixA[0][0], matrixA[0][1], matrixA[0][2] };
	float lowestB[3] = { matrixB[0][0], matrixB[1][0], matrixB[2][0] };
	int opositeAxis[9] = { 9, 9, 9, 9, 9, 9,  9, 9, 9 };
	int solutionAxis[3] = {0,0,0};
	int choose;
	int i0;
	float solution;

	cout << "Chsoose Leader:" << endl << "1->D1" << endl << "2->D2" <<endl;
	cin >> choose;
	if (choose == 1) {
		for (int i = 0; i < 3; i++) {
			for (int a = 1; a < 3; a++) {
				if (lowestB[i] > matrixB[i][a]) { 
					lowestB[i] = matrixB[i][a];
					solutionAxis[i] = a;
				}
			}
		}
		
		int x = 0;
		for (int i = 0; i < 3; i++) {
			for (int a = 0; a < 3; a++) {
				if (lowestB[i] == matrixB[i][a]) {
					opositeAxis[x] = a;
				}
				x++;
			}
		}
		int j = 0;
		int k = 0;
		cout << "R(1) = { ";
		for (j = 0; j < 3; j++) {
			if (opositeAxis[j] != 9) { cout << opositeAxis[j] + 1 << " "; }
		}
		cout << "} = "; 
		for (k = 0; k < 3; k++) {
			if (opositeAxis[k] != 9) { cout << matrixA[0][opositeAxis[k]] << endl; break; }
		}
		cout << "R(2) = { ";
		for (j; j < 6; j++) {
			if (opositeAxis[j] != 9) { cout << opositeAxis[j] + 1 << " "; }
		}
		cout <<"} = ";
		for (k; k < 3; k++) {
			if (opositeAxis[k] != 9) { cout << matrixA[1][opositeAxis[j-2]] << endl; break; }
		}
		cout << "R(3) = { ";
		for (j; j < 9; j++) {
			if (opositeAxis[j] != 9) { cout << opositeAxis[j] + 1 << " "; }
		}
		cout << "} = ";
		for (k; k < 3; k++) {
			if (opositeAxis[k] != 9) { cout << matrixA[2][opositeAxis[j - 5]] << endl; break; }
		}

		for (int i = 0; i < 2; i++) {
			if (matrixA[i][solutionAxis[i]] < matrixA[i + 1][solutionAxis[i+1]]) {
				solution = matrixA[i][solutionAxis[i]];
				i0 = i+1;
			}
			else {
				solution = matrixA[i+1][solutionAxis[i+1]];
				i0 = i+2;
			}
		}
		cout << "i0 for D1 equals: " << i0 << endl;
		cout << "S* for D1 equals: " << solution;
	}
	else {

		for (int i = 0; i < 3; i++) {
			for (int a = 1; a < 3; a++) {
				if (lowestA[i] > matrixA[a][i]) {

					lowestA[i] = matrixA[a][i];
					opositeAxis[i] = a;
					solutionAxis[i] = a;
				}
			}
		}
		int x = 0;
		for (int i = 0; i < 3; i++) {
			for (int a = 0; a < 3; a++) {
				if (lowestA[i] == matrixA[i][a]) {
					opositeAxis[x] = a;
				}
				x++;
			}
		}

		int j = 0;
		int k = 0;
		cout << "R(1) = { ";
		for (j = 0; j < 3; j++) {
			if (opositeAxis[j] != 9) { cout << opositeAxis[j] + 1 << " "; }
		}
		cout << "} = ";
		for (k = 0; k < 3; k++) {
			if (opositeAxis[k] != 9) { cout << matrixA[opositeAxis[k]][0] << endl; break; }
		}
		cout << "R(2) = { ";
		for (j; j < 6; j++) {
			if (opositeAxis[j] != 9) { cout << opositeAxis[j] + 1 << " "; }
		}
		cout << "} = ";
		for (k; k < 3; k++) {
			if (opositeAxis[k] != 9) { cout << matrixA[opositeAxis[j-2]][1] << endl; break; }
		}
		cout << "R(3) = { ";
		for (j; j < 9; j++) {
			if (opositeAxis[j] != 9) { cout << opositeAxis[j] + 1 << " "; }
		}
		cout << "} = ";
		for (k; k < 3; k++) {
			if (opositeAxis[k] != 9) { cout << matrixA[opositeAxis[j-5]][2] << endl; break; }
		}

		for (int i = 0; i < 2; i++) {
			if (matrixB[solutionAxis[i]][i] < matrixB[solutionAxis[i + 1]][i + 1]) {
				solution = matrixB[solutionAxis[i]][i];
				i0 = i + 1;
			}
			else {
				solution = matrixB[solutionAxis[i+1]][i+1];
				i0 = i + 2;
			}
		}
		cout << "j0 for D1 equals: " << i0 << endl;
		cout << "S* for D1 equals: " << solution;
	}

	return 0;
}

/*int main() {
	float matrixA[3][3] = { {5,3,-1}, {-3,-5,8}, {1,2,-2} };
	float matrixB[3][3] = { {-1,4,1}, {1,-5,3}, {4,6,-7} };
	float lowestA[3] = { matrixA[0][0], matrixA[0][1], matrixA[0][2] };
	float lowestB[3] = { matrixB[0][0], matrixB[1][0], matrixB[2][0] };
	int xyA[9][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
	int xyB[9][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
	int solRow[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	*cout << "Matrix A: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int a = 0; a < 3; a++) {
			cout << "Cell " << i+1 << a+1 << ":" << endl;
			cin >> matrixA[i][a];
		}
	}

	cout << "Matrix B: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int a = 0; a < 3; a++) {
			cout << "Cell " << i+1 << a+1 << ":" << endl;
			cin >> matrixB[i][a];
		}
	}*

cout << "  Matrix A:\t\tMatrix B:" << endl;

for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
	{
		cout << setw(4) << matrixA[i][j];
	}
	cout << "\t\t";
	for (int j = 0; j < 3; j++)
	{
		cout << setw(4) << matrixB[i][j];
	}
	cout << endl;
}

cout << endl;

for (int i = 0; i < 3; i++) {
	for (int a = 1; a < 3; a++) {
		if (lowestA[i] > matrixA[a][i]) { lowestA[i] = matrixA[a][i]; }
	}
}

for (int i = 0; i < 3; i++) {
	for (int a = 1; a < 3; a++) {
		if (lowestB[i] > matrixB[i][a]) { lowestB[i] = matrixB[i][a]; }
	}
}
int x = 0;
for (int i = 0; i < 3; i++) {
	for (int a = 0; a < 3; a++) {
		if (lowestA[i] == matrixA[a][i]) {
			xyA[x][0] = a + 1;
			xyA[x][1] = i + 1;
		}
		x++;
	}
}

x = 0;
for (int i = 0; i < 3; i++) {
	for (int a = 0; a < 3; a++) {
		if (lowestB[i] == matrixB[i][a]) {
			xyB[x][0] = i + 1;
			xyB[x][1] = a + 1;
		}
		x++;
	}
}
x = 0;
for (int i = 0; i < 9; i++) {
	if ((xyA[i][0] == xyB[i][0] && xyA[i][1] == xyB[i][1]) && (xyA[i][0] != 0)) {
		cout << "(" << xyA[i][0] << ", " << xyA[i][1] << ")" << " yielding "
			<< "(" << matrixA[xyA[i][0] - 1][xyB[i][0] - 1] << ", " << matrixB[xyA[i][1] - 1][xyB[i][1] - 1] << ")" << endl;
		solRow[i] = i;
		x++;
	}

}
float** solutions = new float* [x];
x = 0;
for (int i = 0; i < 9; i++) {
	if (solRow[i] != 0) {
		solutions[x] = new float[2];
		solutions[x][0] = matrixA[xyA[i][0] - 1][xyB[i][0] - 1];
		solutions[x][1] = matrixB[xyA[i][0] - 1][xyB[i][0] - 1];
		x++;
	}
}
float solution[2] = { NULL, NULL };
for (int i = 0; i < x - 1; i++) {
	if ((solutions[i][0] < solutions[i + 1][0]) && (solutions[i][1] < solutions[i + 1][1])) {
		solution[0] = solutions[i][0];
		solution[1] = solutions[i][1];
	}
	else if ((solutions[i][0] > solutions[i + 1][0]) && (solutions[i][1] > solutions[i + 1][1])) {
		solution[0] = solutions[i + 1][0];
		solution[1] = solutions[i + 1][1];
	}
}

if (solution[1] != NULL && solution[0] != NULL) {
	cout << endl << "The pair (" << solution[0] << ", " << solution[1] << ") is better for both users" << endl;
}
else {
	cout << endl << "No feasible Nash equilibrium found." << endl;
}



return 0;
}*/