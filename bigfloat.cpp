#pragma once
#include <iostream>
#include "bigfloat.h"

// конструкторы

bigfloat::bigfloat(int tolerance){
	num = "0";
	power = 0;
	tol = tolerance;
	sign = false;
}

bigfloat::bigfloat(std::string number, int tolerance){
	tol = tolerance;
	if (number[0] == '-') {
		sign = true;
		number.erase(0, 1); // удаление знака
	}
	else {sign = false;}
	if (std::string::npos == number.find("."))
	{
		num = number;
		power = 0;
	}
	else
	{
		int point_pos = number.find(".");
		number = number.substr(0, point_pos + tolerance + 1);
		power = number.length() - point_pos - 1;
		num = number.erase(point_pos, 1);
	}	
}

//конструктор копирования
bigfloat::bigfloat(const bigfloat& bf){
	num = bf.num;
	power = bf.power;
	tol = bf.tol;
	sign = bf.sign;
}

//оператор присваивания
const bigfloat& bigfloat::operator=(const bigfloat& bf){
	if( &bf == this ) return *this;
	num = bf.num;
	power = bf.power;
	tol = bf.tol;
	sign = bf.sign;
	return *this;
}

//оператор ввода
std::istream& operator>>(std::istream& in, bigfloat& bf){
	std::string tmp;
	in >> tmp;
	bf = bigfloat(tmp, bf.tol);
	return in;
}

//оператор вывода
std::ostream& operator<<(std::ostream& out, bigfloat& bf){
	if (bf.sign)
	{
		out<<'-';
	}
	if (bf.power == 0)
	{
		out<<bf.num;
	}
	else
	{
		int i, len = bf.num.length() - bf.power;
		for (i = 0; i < len; ++i)
		{
			out<<bf.num[i];
		}
		out<<'.';
		len += bf.power;
		for (; i < len; ++i)
		{
			out<<bf.num[i];
		}
	}
	return out;
}

void add_zeros(bigfloat& bf, int n)
{
	for (int i = 0; i < n; i++)
	{
		bf.num.append("0");
		bf.power++;
	}
	if (bf.power>bf.tol)
	{
		bf.tol = bf.power;
	}
}

bigfloat operator +(bigfloat& bf1, bigfloat& bf2)
{
	std::string c;
	bigfloat ans;
	if (bf1.sign == bf2.sign)
	{
		if (bf1.power > bf2.power)
		{
			add_zeros(bf2, bf1.power - bf2.power);
		}
		else if (bf1.power < bf2.power)
		{
			add_zeros(bf1, bf2.power - bf1.power);
		}
		
		int len1 = bf1.num.length(), len2 = bf2.num.length();
		int k = 0;
		int lendif;
		if (len1 > len2)
		{
			lendif = len1 - len2;
			for (int i = len2 - 1; i>=0; --i)
			{
				k += bf1.num[i + lendif] + bf2.num[i] - '0';
				if (k>'9')
				{
					c.insert(0, 1, k - 10);
					k = 1;
				}
				else
				{
					c.insert(0, 1, k);
					k = 0;
				}
			}
			for (int i = lendif - 1; i>=0; --i)
			{
				k += bf1.num[i];
				if (k>'9')
				{
					c.insert(0, 1, k - 10);
					k = 1;
				}
				else
				{
					c.insert(0, 1, k);
					k = 0;
				}
			}
			if (k == 1)
			{
				c.insert(0, 1, '1');
			}
		}
		else
		{
			lendif = len2 - len1;
			for (int i = len1 - 1; i>=0; --i)
			{
				k += bf2.num[i + lendif] + bf1.num[i] - '0';
				if (k>'9')
				{
					c.insert(0, 1, k - 10);
					k = 1;
				}
				else
				{
					c.insert(0, 1, k);
					k = 0;
				}
			}
			for (int i = lendif - 1; i>=0; --i)
			{
				k += bf2.num[i];
				if (k>'9')
				{
					c.insert(0, 1, k - 10);
					k = 1;
				}
				else
				{
					c.insert(0, 1, k);
					k = 0;
				}
			}
			if (k == 1)
			{
				c.insert(0, 1, '1');
			}
		}
		ans.num = c;
		ans.power = bf1.power;
		ans.tol = bf1.tol;
		ans.sign = bf1.sign;
	}
	return ans;
}

int main(){
	bigfloat a, e;
	std::cin >> a >> e; 
	bigfloat c(a+e);
	std::cout << c << std::endl;
	// std::cout << e.num << ' ' << e.power << ' ' << e.sign << ' ' << e.tol << std::endl;
	// std::cout << e <<  std::endl;
	return 0;
}
