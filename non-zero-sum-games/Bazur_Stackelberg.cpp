#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float matrixA[3][3] = { {5,3,-1}, {-3,-5,8}, {1,2,-2} };
	float matrixB[3][3] = { {-1,4,1}, {1,-8,3}, {4,6,-7} };
	float lowestA[3] = { matrixA[0][0], matrixA[0][1], matrixA[0][2] };
	float lowestB[3] = { matrixB[0][0], matrixB[1][0], matrixB[2][0] };
	int opositeAxis[3] = { 0, 0, 0 };
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
					opositeAxis[i] = a;
				}
			}
		}

		cout << "R(1) = {" << opositeAxis[0]+1 << "} = " << matrixA[0][opositeAxis[0]]<<endl;
		cout << "R(2) = {" << opositeAxis[1]+1 << "} = " << matrixA[1][opositeAxis[1]]<<endl;
		cout << "R(3) = {" << opositeAxis[2]+1 << "} = " << matrixA[2][opositeAxis[2]]<<endl;

		for (int i = 0; i < 2; i++) {
			if (matrixA[i][opositeAxis[i]] < matrixA[i + 1][opositeAxis[i+1]]) {
				solution = matrixA[i][opositeAxis[i]];
				i0 = i+1;
			}
			else {
				solution = matrixA[i+1][opositeAxis[i+1]];
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
				}
			}
		}

		cout << "R(1) = {" << opositeAxis[0] + 1 << "} = " << matrixB[opositeAxis[0]][0] << endl;
		cout << "R(2) = {" << opositeAxis[1] + 1 << "} = " << matrixB[opositeAxis[1]][1] << endl;
		cout << "R(3) = {" << opositeAxis[2] + 1 << "} = " << matrixB[opositeAxis[2]][2] << endl;

		for (int i = 0; i < 2; i++) {
			if (matrixB[opositeAxis[i]][i] < matrixB[opositeAxis[i + 1]][i + 1]) {
				solution = matrixB[opositeAxis[i]][i];
				i0 = i + 1;
			}
			else {
				solution = matrixB[opositeAxis[i+1]][i+1];
				i0 = i + 2;
			}
		}
		cout << "j0 for D1 equals: " << i0 << endl;
		cout << "S* for D1 equals: " << solution;
	}

	return 0;
}
