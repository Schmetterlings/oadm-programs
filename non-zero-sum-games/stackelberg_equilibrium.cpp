#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    int leader;
    std::cout << "Who is the leader? (1 or 2): ";
    std::cin >> leader;

    // 3x3 games only
    int matrixA[3][3] = {{5, 3, -1}, {-3, -5, 8}, {1, 2, -2}};
    int matrixB[3][3] = {{-1, 4, 4}, {5, -8, 5}, {6, 6, -7}};

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

    // Find follower's best responses and leaders maximums
    int currentMin, maximums[3];
    std::vector<int> maximumCandidates;

    for (int i = 0; i < 3; i++)
    {
        currentMin = 1000;
        for (int j = 0; j < 3; j++)
        {
            if (leader == 1)
            {
                if (currentMin > matrixB[i][j])
                {
                    currentMin = matrixB[i][j];
                    maximumCandidates.clear();
                    maximumCandidates.push_back(matrixA[i][j]);
                }
                else if (currentMin == matrixB[i][j])
                {
                    maximumCandidates.push_back(matrixA[i][j]);
                }
            }
            else
            {
                if (currentMin > matrixA[j][i])
                {
                    currentMin = matrixA[j][i];
                    maximumCandidates.clear();
                    maximumCandidates.push_back(matrixB[j][i]);
                }
                else if (currentMin == matrixA[j][i])
                {
                    maximumCandidates.push_back(matrixB[j][i]);
                }
            }
            //std::cout << "Current minimum: " << currentMin << std::endl;
        }
        if (maximumCandidates.size() > 1)
        {
            maximums[i] = maximumCandidates.at(0);
            for (int j = 0; j < maximumCandidates.size() - 1; j++)
            {
                if (maximums[i] < maximumCandidates.at(j + 1))
                {
                    maximums[i] = maximumCandidates.at(j + 1);
                }
            }
        }
        else
        {
            maximums[i] = maximumCandidates.at(0);
        }
    }

    std::cout << "Maximums: " << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << maximums[i] << " ";
    }
    std::cout << std::endl;

    // Determine von Stackelberg equilibrium
    int leaderResult = maximums[0], leaderMove = 1;
    for (int i = 0; i < 2; i++)
    {
        if (maximums[i] > maximums[i + 1])
        {
            leaderResult = maximums[i + 1];
            leaderMove = i + 2;
        }
    }
    std::cout << "Leader's result (S*): " << leaderResult << std::endl;
    std::cout << "Leader should play: " << leaderMove << std::endl;

    return 0;
}