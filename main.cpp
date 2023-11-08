#include "main.h"

//std::vector<int> method(int N, std::vector<std::vector<int>>& distance, int step, int start_from, bool enable_dumb_insert);

int main()
{
    std::ifstream matrix_input("matrix_input.txt");
    int size = 0;
    matrix_input >> size; //first we want a size of the matrix in our file
    std::cout << size << "\n";
    std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>(size, std::vector<float>(size, 0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix_input >> matrix[i][j];
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    int input;
    std::cout << "1 for neighbour\n2 for city\n3 for bruteforce\n> ";
    std::cin >> input;
    if (input == 1) method_neighbour(size, matrix);
    if (input == 2) method_city(size, matrix, size, randomint(0, size - 1));
    if (input == 3) print_optimal(matrix);
}