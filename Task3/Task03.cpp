//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько 
//имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится 
//более трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include <iostream>
#include <cmath>
#include "Task3.h"

using namespace std;

/**
 * @brief Вычисление кол-ва чисел с данным количеством разрядов и основанием, в которых не идут 3 подряд идущих 0
 *
 * @param base Основание
 * @param num_discharges Количество разрядов
 * @return
 */
double CountValidNumbers(int base, int num_discharges)
{
	int dp[4] = {0}, new_dp[4] = {0};
	dp[0] = base - 1;
	for (int i=2; i <= num_discharges; i++)
	{
		new_dp[0] = (dp[0] + dp[1] + dp[2] + dp[3]) * (base - 1);
		new_dp[1] = dp[0];
		new_dp[2] = dp[1];
		new_dp[3] = dp[2];
		copy(new_dp, new_dp + 4, dp);
	}
	double total = (base - 1) * pow(base, num_discharges - 1);
	return total - dp[3];
}

int main()
{
	//FIXME: понятные имена переменных + понятное объявление + замена множества переменных на массив
	//int i,k,n,nz,_nz,oz,_oz,tz,_tz, thz, _thz, fz, _fz;
	int base, num_discharges;
	cout << "input base:";
	cin >> base;
	cout << "input number of discharges:";
	cin >> num_discharges;

	cout << endl << CountValidNumbers(base, num_discharges);
	return 0;
}

