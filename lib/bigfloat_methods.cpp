#include <iostream>
#include "bigfloat.h"

// удаляет лишние нули на конце числа
void bigfloat::erase_last_nulls()
{
	int len = num.length();
	while (num[len-1] == '0' && len>1 && power > 0)
	{
		num.pop_back();
		power--;
		len--;
	}
}

// делает строку из bigfloat
std::string bigfloat::get_str() const
{
	std:: string str;
	if (sign)
	{
		str.append("-");
	}
	if (power == 0)
	{
		str.append(num);
	}
	else
	{
		int i, len = num.length() - power;
		for (i = 0; i < len; ++i)
		{
			str.push_back(num[i]);
		}
		str.append(".");
		len += power;
		for (; i < len; ++i)
		{
			str.push_back(num[i]);
		}
	}
	return str;
}

// проверяет на равенство нулю
bool bigfloat::is_null() const
{
	int len = num.length();
	for (int i = 0; i < len; ++i)
	{
		if (num[i] != '0')
		{
			return false;
		}
	}
	return true;
}

// добавляет нужное количество нулей в конец числа
void bigfloat::add_zeros(int n)
{
	for (int i = 0; i < n; i++)
	{
		num.append("0");
		power++;
	}
	if (power > tol)
	{
		tol = power;
	}
}

void bigfloat::set_tolerance(int tolerance)
{
	if (tolerance<0)
	{
		std::cout << "wrong tolerance" << std::endl;
		exit(1);
	}
	
	if (tolerance >= tol){tol = tolerance;}
	else
	{
		if (tol > power){tol = power;}
		num = num.substr(0, num.length() + tolerance - tol);
		if (power > tolerance)
		{
			power = tolerance;
		}
		tol = tolerance;
	}
}
		
// вычисляет число пи с заданной точностью
// bigfloat count_pi(int tolerance)
// {
	
// }

