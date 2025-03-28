//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их об
//щее налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле,
//в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

#include "Task1.h"
#include <iostream>
#include <fstream>
#include <vector>
//FIXME: новые инклуды для локали для винды
#include <io.h>
#include <fcntl.h>

//FIXME: перенос скобок на 30,34,38,102,104,107 строках

using namespace std;

/**
 * @brief Жадный алгоритм.
 *
 * @param dp - вектор артефактов с весом и налогом каждого
 * @param k - индекс артефакта
 * @param s  - индекс веса артефакта
 * @param weight - вес рюкзака
 * @param nalog - стоимость налога
 */
//FIXME: название функции с большой буквы
//void findAnswer(const vector<vector<int>>& dp, int k, int s, vector<int>& weight, vector<int>& nalog)
void FindAnswer(const vector<vector<int>>& dp, int k, int s, vector<int>& weight, vector<int>& nalog)
{
    if (k == 0)
    {
        return;
    }
    if (dp[k][s] == dp[k - 1][s])
    {
        FindAnswer(dp, k - 1, s, weight, nalog);
    }
    else
    {
        wcout << L"берем артефакт с индексом " << k << L", ";
        FindAnswer(dp, k - 1, s - weight[k], weight, nalog);
    }
}

/**
 * @brief Считывает данные из файла.
 *
 * @param input Входной поток данных.
 * @param num_artifact Количество артефактов.
 * @param min_weight Минимальный требуемый вес.
 * @param weight Вектор весов артефактов.
 * @param nalog Вектор налогов на артефакты.
 */
void ReadData(ifstream& input, int& num_artifact, int& min_weight, vector<int>& weight, vector<int>& nalog)
{
    input >> num_artifact >> min_weight;
    weight.resize(num_artifact + 1);
    nalog.resize(num_artifact + 1);
    for (int i = 1; i <= num_artifact; i++)
    {
        input >> weight[i];//считывание весов и налогов
    }
    for (int i = 1; i <= num_artifact; i++)
    {
        input >> nalog[i];
    }
}

/**
 * @brief Вычисляет максимальный возможный вес.
 *
 * @param weight Вектор весов артефактов.
 * @return Максимальный возможный вес.
 */
int CalculateMaxWeight(const vector<int>& weight)
{
    //FIXME: переименование перемнной на snake_case
    //int maxWeight = 0;
    int max_weight = 0;
    for (int i = 1; i < weight.size(); i++)
    {
        max_weight += weight[i];//нахождение макс веса для массива
    }
    return max_weight;
}

/**
 * @brief Решает задачу о рюкзаке с минимизацией налога.
 *
 * @param num_artifact Количество артефактов.
 * @param max_weight Максимальный возможный вес.
 * @param weight Вектор весов артефактов.
 * @param nalog Вектор налогов на артефакты.
 *
 * @return Двумерный вектор, представляющий таблицу динамического программирования.
 */
vector<vector<int>> SolveKnapsack(int num_artifact, int max_weight, const vector<int>& weight, const vector<int>& nalog) {
    //FIXME: замена названия переменной на понятное для использования
    //vector<vector<int>> db(num_artifact + 1, vector<int>(max_weight + 1, 10000000));
    vector<vector<int>> list_artifacts(num_artifact + 1, vector<int>(max_weight + 1, 10000000));
    list_artifacts[0][0] = 0;
    for (int i = 1; i <= num_artifact; i++)
    {
        for (int s = 0; s <= max_weight; s++)
        {
            list_artifacts[i][s] = list_artifacts[i - 1][s];
            if (s >= weight[i] && list_artifacts[i - 1][s - weight[i]] != 10000000)
            {
                list_artifacts[i][s] = min(list_artifacts[i][s], list_artifacts[i - 1][s - weight[i]] + nalog[i]);
            }
        }
    }
    return list_artifacts;
}

/**
 * @brief Находит оптимальное решение и выводит результаты.
 *
 * @param list_artifacts Таблица динамического программирования.
 * @param num_artifact Количество артефактов.
 * @param min_weight Минимальный требуемый вес.
 * @param max_weight Максимальный возможный вес.
 * @param weight     Вектор весов.
 * @param nalog      Вектор налогов.
 */
void FindAndPrintSolution(const vector<vector<int>>& list_artifacts, int num_artifact, int min_weight, int max_weight, vector<int>& weight, vector<int>& nalog)
{
    //FIXME: замена названий на snake_case
    //int minNalog = 10000000;
    //int bestWeight = -1;
    int min_nalog = 10000000, best_weight = -1;

    for (int s = min_weight + 1; s <= max_weight; s++)
    {
        if (list_artifacts[num_artifact][s] < min_nalog)
        {
            min_nalog = list_artifacts[num_artifact][s];
            best_weight = s;
        }
    }
    wcout << L"Минимальный налог: " << min_nalog << endl;
    wcout << L"Суммарный вес: " << best_weight << endl;
    FindAnswer(list_artifacts, num_artifact, best_weight, weight, nalog);
    wcout << endl;
}

int main()
{
    //FIXME: изменение вывода в консоль на 16 бит для правильного отображения на виндовс
    //setlocale(LC_ALL, "Russian");
    _setmode(_fileno(stdout), _O_U16TEXT);
    //FIXME: переименование переменных на snake_case + понятное название
    //int N, Z;
    int num_artifact, min_weight;
    //FIXME: переименование входного потока данных на понятное название
    //ifstream f1("археолог.txt");
    ifstream input(L"Task1/археолог.txt");
    vector<int> weight;
    vector<int> nalog;

    ReadData(input, num_artifact, min_weight, weight, nalog);

    int max_weight = CalculateMaxWeight(weight);

    vector<vector<int>> list_artifacts = SolveKnapsack(num_artifact, max_weight, weight, nalog);

    FindAndPrintSolution(list_artifacts, num_artifact, min_weight, max_weight, weight, nalog);

    return 0;
}