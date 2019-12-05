#include <iostream>
#include <cmath>

double Q[4][4];
double c[4];
double A[2][4];
double Ap[2][4];
double b[2];
double bp[2];
double deltai[4];
double tableau[6][16];
using namespace std;

int main()
{
    double temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Q[i][j] = 0;
        }
    }
    cout << "Input the coefficient of x1^2" << endl;
    cin >> temp;
    Q[0][0] = 2 * temp;
    cout << "Input the coefficient of x2^2" << endl;
    cin >> temp;
    Q[1][1] = 2 * temp;
    cout << "Input the coefficient of x1x2" << endl;
    cin >> Q[0][1];
    Q[1][0] = Q[0][1];
    cout << "Input the coefficient of x1" << endl;
    cin >> c[0];
    cout << "Input the coefficient of x2" << endl;
    cin >> c[1];
    c[2] = 0;
    c[3] = 0;
    cout << "Input the first constraint (x1, x2 <= b)" << endl;
    cin >> A[0][0];
    cin >> A[0][1];
    cin >> b[0];
    A[0][2] = 1;
    A[0][3] = 0;
    cout << "Input the second constraint (x1, x2 <= b)" << endl;
    cin >> A[1][0];
    cin >> A[1][1];
    cin >> b[1];
    A[1][2] = 0;
    A[1][3] = 1;
    
    for (int i = 0; i < 4; i++)
    {
        if (-c[i] >= 0)
        {
            deltai[i] = 1;
        }
        else
        {
            deltai[i] = -1;
        }
    }
    double a1 = A[0][1] / A[1][1];
    double a2 = A[1][0] / A[0][0];

    for (int j = 0; j < 4; j++)
    {
        Ap[0][j] = A[0][j] - a1 * A[1][j];
        Ap[1][j] = A[1][j] - a2 * A[0][j];
    }
    bp[0] = b[0] - a1 * b[1];
    bp[1] = b[1] - a2 * b[0];
    double a3 = 1 / Ap[0][0];
    double a4 = 1 / Ap[1][1];
    for (int j = 0; j < 4; j++)
    {
        Ap[0][j] = Ap[0][j] * a3;
        Ap[1][j] = Ap[1][j] * a4;
    }
    bp[0] = bp[0] * a3;
    bp[1] = bp[1] * a4;
    for (int i = 0; i < 2; i++)
    {
        ;
        for (int j = 0; j < 4; j++)
        {
            if (fabs(Ap[i][j]) < 0.00000001)
            {
                Ap[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            tableau[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tableau[i][j] = Ap[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tableau[2 + i][j] = Q[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tableau[2 + j][4 + i] = Ap[i][j];
            tableau[2 + j][6 + i] = -Ap[i][j];
        }
    }
    tableau[2][8] = -1;
    tableau[3][9] = -1;
    tableau[4][10] = -1;
    tableau[5][11] = -1;
    tableau[2][12] = deltai[0];
    tableau[3][13] = deltai[1];
    tableau[4][14] = deltai[2];
    tableau[5][15] = deltai[3];

    for (int i = 0; i < 6; i++)
    {
        cout << endl;
        for (int j = 0; j < 16; j++)
        {
            cout << tableau[i][j] << " | ";
        }
    }
    cout << endl;

    return 0;
}
