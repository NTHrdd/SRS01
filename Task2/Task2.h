//
// Created by hisma on 28.03.2025.
//

#ifndef TASK2_H
#define TASK2_H

#include <fstream>
#include <vector>

/**
 * @brief Считывание данных из файла.
 *
 * @param input Входной файл
 * @param size_board Размер доски (1 < N < 80)
 * @param board Вектор для хранения данных доски
 */
void ReadData(std::ifstream& input, int& size_board, std::vector<std::vector<int>>& board);

/**
 * @brief Вычисление минимальной суммы пути черепашки.
 *
 * @param size_board Размер доски
 * @param board Матрица с данными доски
 * @return int Минимальная сумма пути
 */
int ComputeMinPath(int size_board, const std::vector<std::vector<int>>& board);

#endif //TASK2_H
