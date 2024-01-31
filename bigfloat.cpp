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
std::ostream& operator<<(std::ostream& out, const bigfloat& bf){
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

bigfloat operator +(const bigfloat& bf1, const bigfloat& bf2)
{
	std::string c;
	bigfloat a = bf1;
	bigfloat b = bf2;
	bigfloat ans;
	if (a.sign == b.sign)
	{
		if (a.power > b.power)
		{
			add_zeros(b, a.power - b.power);
		}
		else if (a.power < b.power)
		{
			add_zeros(a, b.power - a.power);
		}
		
		int len1 = a.num.length(), len2 = b.num.length();
		int k = 0;
		int lendif;
		if (len1 < len2)
		{
			ans = a;
			a = b;
			b = ans;
		}
		lendif = len1 - len2;
		for (int i = len2 - 1; i>=0; --i)
		{
			k += a.num[i + lendif] + b.num[i] - '0';
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
			k += a.num[i];
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
		ans.num = c;
		ans.power = a.power;
		ans.tol = a.tol;
		ans.sign = a.sign;
	}
	else
	{
		if (a.sign)
		{
			a.sign = false;
			ans = b - a;
		}
		else
		{
			b.sign = false;
			ans = a - b;
		}
	}
	return ans;
}

bigfloat operator -(const bigfloat& bf1, const bigfloat& bf2)
{
	std::string c;
	bigfloat a = bf1;
	bigfloat b = bf2;
	bigfloat ans;
	if (!a.sign && !b.sign)
	{
		if (a < b)
		{
			ans = -(b - a);
		}
		else
		{
			if (a.power > b.power)
			{
				add_zeros(b, a.power - b.power);
			}
			else if (a.power < b.power)
			{
				add_zeros(a, b.power - a.power);
			}
			int len1 = a.num.length(), len2 = b.num.length();
			int k = 0;
			int lendif = len1 - len2;

			for (int i = len2 - 1; i>=0; --i)
			{
				k += a.num[i + lendif] - b.num[i] + '0';
				if (k >= '0')
				{
					c.insert(0, 1, k);
					k = 0;
				}
				else
				{
					c.insert(0, 1, k + 10);
					k = -1;
				}
			}
			for (int i = lendif - 1; i>=0; --i)
			{
				k += a.num[i];
				if (k >= '0')
				{
					c.insert(0, 1, k);
					k = 0;
				}
				else
				{
					c.insert(0, 1, k + 10);
					k = -1;
				}
			}
			if (c[0] == '0'){c.erase(0, 1);}
			ans.num = c;
			ans.power = a.power;
			ans.tol = a.tol;
			ans.sign = a.sign;
		}
		
	}
	else if (a.sign && b.sign)
	{
		b = -b;
		a = -a;
		ans = b - a;
	}
	else if (a.sign && !b.sign)
	{
		b = -b;
		ans = a + b;
	}
	else //if (!a.sign && b.sign)
	{
		b = -b;
		ans = a + b;
	}
	return ans;
}
bool operator >(const bigfloat& bf1, const bigfloat& bf2)
{
	if (!bf1.sign && bf2.sign)
	{
		return true;
	}
	else if (bf1.sign && !bf2.sign)
	{
		return false;
	}
	else if (!bf1.sign)
	{
		if (bf1.num.length() - bf1.power > bf2.num.length() - bf2.power)
		{
			return true;
		}
		if (bf1.num.length() - bf1.power < bf2.num.length() - bf2.power)
		{
			return false;
		}
		int minlen;
		if (bf1.num.length() > bf2.num.length()){minlen = bf2.num.length();}
		else {minlen = bf1.num.length();}
		for (int i = 0; i < minlen; i++)
		{
			if (bf1.num[i] > bf2.num[i]){return true;}
			if (bf1.num[i] < bf2.num[i]){return false;}
		}
		if (bf1.num.length() > bf2.num.length()){return true;}
		else {return false;}
	}
	else //if (bf1.sign)
	{
		if (bf1.num.length() - bf1.power < bf2.num.length() - bf2.power)
		{
			return true;
		}
		if (bf1.num.length() - bf1.power > bf2.num.length() - bf2.power)
		{
			return false;
		}
		int minlen;
		if (bf1.num.length() < bf2.num.length()){minlen = bf2.num.length();}
		else {minlen = bf1.num.length();}
		for (int i = 0; i < minlen; i++)
		{
			if (bf1.num[i] < bf2.num[i]){return true;}
			if (bf1.num[i] > bf2.num[i]){return false;}
		}
		if (bf1.num.length() < bf2.num.length()){return true;}
		else {return false;}
	}
}

bool operator ==(const bigfloat& bf1, const bigfloat& bf2)
{
	if (!bf1.num.compare(bf2.num) && bf1.sign == bf2.sign && bf1.power == bf2.power)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator !=(const bigfloat& bf1, const bigfloat& bf2)
{
	return !(bf1 == bf2);
}

bool operator >=(const bigfloat& bf1, const bigfloat& bf2)
{
	return (bf1 == bf2 || bf1 > bf2);
}

bool operator <(const bigfloat& bf1, const bigfloat& bf2)
{
	return !(bf1 >= bf2);
}

bool operator <=(const bigfloat& bf1, const bigfloat& bf2)
{
	return !(bf1 > bf2);
}

bigfloat operator +(const bigfloat& bf)
{
	return bf;
}

bigfloat operator -(const bigfloat& bf)
{
	bigfloat a = bf;
	a.sign = !a.sign;
	return a;
}

int main(){
	bigfloat a, e;
	std::cin >> a >> e; 
	
	std::cout << (a - e) << std::endl;
	// std::cout << e.num << ' ' << e.power << ' ' << e.sign << ' ' << e.tol << std::endl;
	// std::cout << e <<  std::endl;
	return 0;
}
