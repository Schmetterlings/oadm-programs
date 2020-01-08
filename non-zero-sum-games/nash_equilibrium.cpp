#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    // 3x3 games only
    int matrixA[3][3] = {{5, 3, -1}, {-3, -5, 8}, {-3, 2, -2}};
    int matrixB[3][3] = {{-1, 4, 1}, {1, -8, 3}, {4, 6, -7}};

    /*
    std::cout << "{Matrix A}" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "[Row " << i + 1 << "]" << std::endl;
        for (int j = 0; j < 3; j++)
        {
            std::cout << "Column " << j + 1 << ": ";
            std::cin >> matrixA[i][j];
        }
    }
    std::cout << "{Matrix B}" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "[Row " << i + 1 << "]" << std::endl;
        for (int j = 0; j < 3; j++)
        {
            std::cout << "Column " << j + 1 << ": ";
            std::cin >> matrixB[i][j];
        }
    }
    */

    // Draw payoff matrices
    std::cout << std::endl
              << "A\t\t\tB" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << std::setw(4) << matrixA[i][j];
        }
        std::cout << "\t\t";
        for (int j = 0; j < 3; j++)
        {
            std::cout << std::setw(4) << matrixB[i][j];
        }
        std::cout << std::endl;
    }

    // Find minimums
    int currentMinA, currentMinB, minimumsA[3], minimumsB[3];
    std::vector<int> possibleRowTemp, possibleColumnTemp, nashEqRowTemp, nashEqColumnTemp;
    std::vector<std::vector<int>> possibleRow, possibleColumn, nashEqRow, nashEqColumn;

    for (int i = 0; i < 3; i++)
    {
        currentMinA = 1000;
        for (int j = 0; j < 3; j++)
        {
            if (currentMinA > matrixA[j][i])
            {
                currentMinA = matrixA[j][i];
                possibleRowTemp.clear();
                possibleColumnTemp.clear();
                possibleRowTemp.push_back(j);
                possibleColumnTemp.push_back(i);
            }
            else if (currentMinA == matrixA[j][i])
            {
                possibleRowTemp.push_back(j);
                possibleColumnTemp.push_back(i);
            }
        }
        minimumsA[i] = currentMinA;
        possibleRow.push_back(possibleRowTemp);
        possibleColumn.push_back(possibleColumnTemp);
    }

    /*
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < possibleRow.at(i).size(); j++)
        {
            std::cout << "Possible Nash eq. row: " << possibleRow.at(i).at(j) + 1 << std::endl;
            std::cout << "Possible Nash eq. column: " << possibleColumn.at(i).at(j) + 1 << std::endl;
        }
    }
    */

    for (int i = 0; i < 3; i++)
    {
        currentMinB = 1000;
        for (int j = 0; j < 3; j++)
        {
            if (currentMinB > matrixB[i][j])
            {
                currentMinB = matrixB[i][j];

                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < possibleRow.at(k).size(); l++)
                    {
                        if (possibleRow.at(k).at(l) == i)
                        {
                            if (possibleColumn.at(k).at(l) == j)
                            {
                                nashEqRowTemp.clear();
                                nashEqColumnTemp.clear();
                                nashEqRowTemp.push_back(i);
                                nashEqColumnTemp.push_back(j);
                            }
                        }
                    }
                }
            }
            else if (currentMinB == matrixB[i][j])
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < possibleRow.at(k).size(); l++)
                    {
                        if (possibleRow.at(k).at(l) == i)
                        {
                            if (possibleColumn.at(k).at(l) == j)
                            {
                                nashEqRowTemp.push_back(i);
                                nashEqColumnTemp.push_back(j);
                            }
                        }
                    }
                }
            }
        }
        minimumsB[i] = currentMinB;
        nashEqRow.push_back(nashEqRowTemp);
        nashEqColumn.push_back(nashEqColumnTemp);
    }

    /*
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Matrix A minimums: " << minimumsA[i];
        std::cout << std::endl;
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Matrix B minimums: " << minimumsB[i];
        std::cout << std::endl;
    }
    */

    // Display Nash eqs.
    int lastNashRow = 0, lastNashColumn = 0;
    for (int i = 0; i < nashEqRow.size(); i++)
    {
        for (int j = 0; j < nashEqRow.at(i).size(); j++)
        {
            if (lastNashRow != nashEqRow.at(i).at(j) + 1 && lastNashColumn != nashEqColumn.at(i).at(j) + 1)
            {
                lastNashRow = nashEqRow.at(i).at(j) + 1;
                lastNashColumn = nashEqColumn.at(i).at(j) + 1;
                std::cout
                    << "Found Nash eq. at (" << nashEqRow.at(i).at(j) + 1 << ", " << nashEqColumn.at(i).at(j) + 1 << ")"
                    << " yielding (" << matrixA[nashEqRow.at(i).at(j)][nashEqColumn.at(i).at(j)] << ", "
                    << matrixB[nashEqRow.at(i).at(j)][nashEqColumn.at(i).at(j)] << ")" << std::endl;
            }
        }
    }

    // Choose better pair for both players if possible
    int better[2];
    bool isBetter = false;

    if (!nashEqRow.empty())
    {
        for (int i = 0; i < nashEqRow.size(); i++)
        {
            for (int j = 0; j < nashEqRow.at(i).size(); j++)
            {
                for (int k = 0; k < nashEqRow.at(i).size(); k++)
                {
                    if (!isBetter)
                    {
                        if (matrixA[nashEqRow.at(i).at(j)][nashEqColumn.at(i).at(j)] >= matrixA[nashEqRow.at(i).at(k)][nashEqColumn.at(i).at(k)])
                        {
                            if (matrixB[nashEqRow.at(i).at(j)][nashEqColumn.at(i).at(j)] >= matrixB[nashEqRow.at(i).at(k)][nashEqColumn.at(i).at(k)])
                            {
                                better[0] = nashEqRow.at(i).at(k);
                                better[1] = nashEqColumn.at(i).at(k);
                                isBetter = true;
                            }
                        }
                    }
                    else
                    {
                        if (matrixA[better[0]][better[1]] >= matrixA[nashEqRow.at(i).at(k)][nashEqColumn.at(i).at(k)])
                        {
                            if (matrixB[better[0]][better[1]] >= matrixB[nashEqRow.at(i).at(k)][nashEqColumn.at(i).at(k)])
                            {
                                better[0] = nashEqRow.at(i).at(k);
                                better[1] = nashEqColumn.at(i).at(k);
                            }
                        }
                    }
                }
            }
        }

        if (isBetter)
        {
            std::cout << "Feasible solution pair: (" << better[0] + 1 << ", " << better[1] + 1 << ")" << std::endl;
        }
    }
    else
    {
        std::cout << "No feasible Nash equilibrium found." << std::endl;
    }

    // Find maximums
    int currentMaxA, currentMaxB, maximumsA[3], maximumsB[3];

    for (int i = 0; i < 3; i++)
    {
        currentMaxA = -1000;
        for (int j = 0; j < 3; j++)
        {
            if (currentMaxA < matrixA[j][i])
            {
                currentMaxA = matrixA[j][i];
            }
        }
        maximumsA[i] = currentMaxA;
    }
    for (int i = 0; i < 3; i++)
    {
        currentMaxB = -1000;
        for (int j = 0; j < 3; j++)
        {
            if (currentMaxB < matrixB[j][i])
            {
                currentMaxB = matrixB[j][i];
            }
        }
        maximumsB[i] = currentMaxB;
    }

    // Find minimax
    int minimaxA = maximumsA[0], minimaxB = maximumsB[0];

    for (int i = 0; i < 2; i++)
    {
        if (minimaxA > maximumsA[i + 1])
        {
            minimaxA = maximumsA[i + 1];
        }
        if (minimaxB > maximumsB[i + 1])
        {
            minimaxB = maximumsB[i + 1];
        }
    }
    std::cout << "Minimax for player D1: " << minimaxA << std::endl;
    std::cout << "Minimax for player D2: " << minimaxB << std::endl;

    return 0;
}