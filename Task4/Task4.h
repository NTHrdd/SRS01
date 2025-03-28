//
// Created by hisma on 28.03.2025.
//

#ifndef TASK4_H
#define TASK4_H

#include <string>

/**
 * @brief Рекурсивно парсит целое число из строки выражения
 * @param expression Строка с арифметическим выражением
 * @param current_pos Текущая позиция парсинга в строке (индекс)
 * @return Распознанное целое число
 */
int ParseNumber(const std::string& expression, int& current_pos);

/**
 * @brief Обрабатывает операции умножения и деления
 * @param expression Строка с арифметическим выражением
 * @param current_pos Текущая позиция парсинга в строке (индекс)
 * @param left Накопленный результат левой части выражения
 * @return Результат вычисления операций умножения/деления
 */
int ParseMultiplicationAndDivision(const std::string& expression, int& current_pos, int left);

/**
 * @brief Обрабатывает операции сложения и вычитания
 * @param expression Строка с арифметическим выражением
 * @param current_pos Текущая позиция парсинга в строке (индекс)
 * @param left Накопленный результат левой части выражения
 * @return Конечный результат вычисления всего выражения
 */
int ParseAdditionAndSubtraction(const std::string& expression, int& current_pos, int left);

#endif //TASK4_H
