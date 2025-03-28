//Черепашка.На квадратной доске расставлены целые неотрицательные числа, каждое из которых 
//не превосходит 100. Черепашка, находящаяся в левом нижнем углу, мечтает по пасть в правый 
//верхний.При этом она может переползать только в клетку справа или сверху и хочет, чтобы 
//сумма всех чисел, оказавшихся у нее на пути, была бы минимальной.Определить эту сумму.
//Ввод и вывод организовать при помощи текстовых файлов.Формат входных данных :
//в первой строке входного файла записано число N - размер доски(1 < N < 80).Далее следует N
//строк, каждая из которых содержит N целых чисел, представляющих доску.В выходной файл
//нужно вывести единственное число : минимальную сумму.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
//FIXME: новые инклуды для локали для винды
#include <io.h>
#include <fcntl.h>
#include "Task2.h"

//FIXME: перенос скобок на 30,32,37,39,53,59,64,69,71 строках
using namespace std;

/**
 * @brief Считывание данных из файла.
 *
 * @param input Входной файл
 * @param size_board Размер доски (1 < N < 80)
 * @param board Вектор доски
 */
void ReadData(ifstream& input, int& size_board, vector<vector<int>>& board)
{
    if (size_board <= 1 || size_board >= 80)
    {
        wcerr << L"Некорректный размер доски: " << size_board << L". Должно быть 1 < N < 80\n";
        input.close();
    }
    for (int i = 0; i < size_board; ++i)
        {
        for (int j = 0; j < size_board; ++j)
        {
            input >> board[i][j];
        }
    }
}

/**
 * @brief Вычисление минимального пути
 *
 * @param size_board Размер доски (1 < N < 80)
 * @param board Вектор доски
 * @return
 */
int ComputeMinPath(int size_board, const vector<vector<int>>& board)
{
    vector<vector<int>> dp(size_board, vector<int>(size_board, 0));

    dp[size_board - 1][0] = board[size_board - 1][0];

    for (int i = size_board - 2; i >= 0; i--)
    {
        dp[i][0] = dp[i + 1][0] + board[i][0];
    }

    for (int j = 1; j < size_board; j++)
    {
        dp[size_board - 1][j] = dp[size_board - 1][j - 1] + board[size_board - 1][j];
    }

    for (int i = size_board - 2; i >= 0; i--)
    {
        for (int j = 1; j < size_board; ++j)
        {
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + board[i][j];
        }
    }
    return dp[0][size_board - 1];
}

int main() {
    //FIXME: изменение вывода в консоль на 16 бит для правильного отображения на виндовс
    //setlocale(LC_ALL, "Russian");
    _setmode(_fileno(stdout), _O_U16TEXT);
    ifstream input(L"Task2/input.txt");
    ofstream output(L"Task2/output.txt");
    //FIXME: замена названия переменной на понятное для использования + snake_case
    //int N;
    int size_board;
    input >> size_board;
    vector<vector<int>> board(size_board, vector<int>(size_board));
    ReadData(input, size_board, board);

    int result = ComputeMinPath(size_board, board);
    output << result << endl;
    wcout << L"Значение " << result << L" записано в файл\n";
}