//
// Created by hisma on 28.03.2025.
//

#ifndef TASK3_H
#define TASK3_H

/**
 * @brief Вычисляет количество K-ичных чисел без 3+ подряд идущих нулей.
 *
 * @param base Основание системы счисления (2 ≤ base ≤ 10)
 * @param num_discharges Количество разрядов (1 < num_discharges < 20, base + num_discharges < 26)
 * @return double Количество допустимых чисел (в виде вещественного для избежания переполнения)
 */
double CountValidNumbers(int base, int num_discharges);

#endif //TASK3_H
