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

bigfloat bigfloat::new_tol(const bigfloat& bf, int n)
{
	
}

int main(){
	bigfloat a;
	std::cin >> a; 
	bigfloat e = a;
	std::cout << e.num << ' ' << e.power << ' ' << e.sign << ' ' << e.tol << std::endl;
	std::cout << e <<  std::endl;
	return 0;
}
