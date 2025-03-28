//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
//определяется следующим образом :
//            <выражение> :: = <цифра> | (<выражение><знак><выражение>)
//            < знак > :: = +| − | *

#include <iostream>
#include <string>
//FIXME: новые инклуды для локали для винды
#include <io.h>
#include <fcntl.h>
#include "Task4.h"

//FIXME:убраны недосигаемые ретурны в функциях ParseMultiplicationAndDivision и ParseAdditionAndSubtraction
//FIXME:фигурные скобки перенесены на следующую строку
using namespace std;

//FIXME: Название функции с большой буквы + понятное название + изменение названия параметров
//int recnum(const string& stroka, int& ind) {
/**
 * @brief Читает число из строки
 *
 * @param expression выражение
 * @param current_pos индекс позиции в тексте
 * @return
 */
int ParseNumber(const string& expression, int& current_pos)
{
    if (current_pos >= expression.length() || !isdigit(expression[current_pos]))
        return 0;

    int num = expression[current_pos++] - '0'; // Преобразуем символ в число
    int next = ParseNumber(expression, current_pos); // Читаем следующие цифры

    return next == 0 ? num : num * 10 + next; // Собираем многозначное число
}



//FIXME: Название функции с большой буквы + понятное название + изменение названия параметров
//int delen(const string& stroka, int& ind, int left) {
/**
 * @brief Обработка * и / в выражении
 *
 * @param expression выражение
 * @param current_pos индекс позиции в тексте
 * @param left результат предыдущего шага
 * @return
 */
int ParseMultiplicationAndDivision(const string& expression, int& current_pos, int left)
{
    if (current_pos >= expression.length()) return left;

    char op = expression[current_pos];
    if (op != '*' && op != '/') return left;

    current_pos++;
    int right = ParseNumber(expression, current_pos);

    if (op == '*') return ParseMultiplicationAndDivision(expression, current_pos, left * right);
    if (op == '/')
    {
        if (right == 0) {
            wcout << L"Ошибка: деление на 0!\n";
            exit(1);
        }
        return ParseMultiplicationAndDivision(expression, current_pos, left / right);
    }
}
//FIXME: Название функции с большой буквы + понятное название + изменение названия параметров
//int primer(const string& stroka, int& ind, int left) {
/**
 * @brief Обработка + и - в выражении
 *
 * @param expression выражение
 * @param current_pos индекс позиции в тексте
 * @param left результат предыдущего шага
 * @return
 */
int ParseAdditionAndSubtraction(const string& expression, int& current_pos, int left)
{
    if (current_pos >= expression.length()) return left;

    char op = expression[current_pos];
    if (op != '+' && op != '-') return left;

    current_pos++;
    int right = ParseMultiplicationAndDivision(expression, current_pos, ParseNumber(expression, current_pos));

    if (op == '+') return ParseAdditionAndSubtraction(expression, current_pos, left + right);
    if (op == '-') return ParseAdditionAndSubtraction(expression, current_pos, left - right);
}

int main() {
    //FIXME: изменение вывода в консоль на 16 бит для правильного отображения на виндовс
    //setlocale(LC_ALL, "Russian");
    _setmode(_fileno(stdout), _O_U16TEXT);
    string s;
    wcout << L"Введите выражение:\n";
    cin >> s;

    int ind = 0;
    int res = ParseAdditionAndSubtraction(s, ind, ParseMultiplicationAndDivision(s, ind, ParseNumber(s, ind)));
    wcout << L"Результат: " << res << endl;

    return 0;
}
