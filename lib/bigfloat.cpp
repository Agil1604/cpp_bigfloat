#include <iostream>
#include "bigfloat.h"

// литерал
bigfloat operator""_mbf(const char* tmp)
{
	// any number -> bigfloat
	std::string str = std::string(tmp);

	if (std::string::npos == str.find("."))
	{
		return bigfloat(str);
	}
	else
	{
		return bigfloat(str, str.length() - str.find(".") + 2);
	}
}

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
	else if (number[0] == '+') {
		sign = false;
		number.erase(0, 1); // удаление знака
	}
	else {sign = false;}
	while (number[0] == '0' &&  number[1] != '.' && number.length() > 1){number.erase(0, 1);}
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

// операторы

const bigfloat& bigfloat::operator=(int x){
	if (x < 0)
	{
		sign = 1;
		x *= -1;
	}
	else {sign = 0;}
	num = std::to_string(x);
	power = 0;
	return *this;
}

// оператор ввода
std::istream& operator>>(std::istream& in, bigfloat& bf){
	std::string tmp;
	in >> tmp;
	bf = bigfloat(tmp, bf.tol);
	return in;
}

// оператор вывода
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

// сложение чисел
bigfloat operator +(const bigfloat& bf1, const bigfloat& bf2)
{
	std::string c = {};
	bigfloat a = bf1;
	bigfloat b = bf2;
	bigfloat ans;
	if (a.sign == b.sign)
	{
		if (a.power > b.power)
		{
			b.add_zeros(a.power - b.power);
		}
		else if (a.power < b.power)
		{
			a.add_zeros(b.power - a.power);
		}
		
		int len1 = a.num.length(), len2 = b.num.length();
		int k = 0;
		int lendif;
		if (len1 < len2)
		{
			ans = a;
			a = b;
			b = ans;
			
			k = len1;
			len1 = len2;
			len2 = k;
		}
		k = 0;

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

// вычитаниеи чисел
bigfloat operator -(const bigfloat& bf1, const bigfloat& bf2)
{
	std::string c = {};
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
				b.add_zeros(a.power - b.power);
			}
			else if (a.power < b.power)
			{
				a.add_zeros(b.power - a.power);
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
			while (c[0] == '0' && c.length() - a.power > 1){c.erase(0, 1);}
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

// оператор больше
bool operator >(const bigfloat& bf1, const bigfloat& bf2)
{
	if (bf1.is_zero() && bf2.is_zero()){return false;}
	if (!bf1.sign && bf2.sign)
	{
		return true;
	}
	else if (bf1.sign && !bf2.sign)
	{
		return false;
	}
	bigfloat a = bf1, b = bf2;
	if (a.power > b.power)
	{
		b.add_zeros(a.power - b.power);
	}
	else if (a.power < b.power)
	{
		a.add_zeros(b.power - a.power);
	}
	
	if (!a.sign)
	{
		if (a.num.length() - a.power > b.num.length() - b.power)
		{
			return true;
		}
		if (a.num.length() - a.power < b.num.length() - b.power)
		{
			return false;
		}
		int minlen;
		if (a.num.length() > b.num.length()){minlen = b.num.length();}
		else {minlen = a.num.length();}
		for (int i = 0; i < minlen; i++)
		{
			if (a.num[i] > b.num[i]){return true;}
			if (a.num[i] < b.num[i]){return false;}
		}
		if (a.num.length() > b.num.length()){return true;}
		else {return false;}
	}
	else //if (bf1.sign)
	{
		if (a.num.length() - a.power < b.num.length() - b.power)
		{
			return true;
		}
		if (a.num.length() - a.power > b.num.length() - b.power)
		{
			return false;
		}
		int minlen;
		if (a.num.length() < b.num.length()){minlen = b.num.length();}
		else {minlen = a.num.length();}
		for (int i = 0; i < minlen; i++)
		{
			if (a.num[i] < b.num[i]){return true;}
			if (a.num[i] > b.num[i]){return false;}
		}
		if (a.num.length() < b.num.length()){return true;}
		else {return false;}
	}
}

// проверка равенства двух чисел
bool operator ==(const bigfloat& bf1, const bigfloat& bf2)
{
	if (bf1.is_zero() && bf2.is_zero()){return true;}
	bigfloat a = bf1, b = bf2;
	if (a.power > b.power)
	{
		b.add_zeros(a.power - b.power);
	}
	else if (a.power < b.power)
	{
		a.add_zeros(b.power - a.power);
	}
	
	if (!a.num.compare(b.num) && a.sign == b.sign && a.power == b.power)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// проверка неравенства двух чисел
bool operator !=(const bigfloat& bf1, const bigfloat& bf2)
{
	return !(bf1 == bf2);
}

// оператор больше или равно
bool operator >=(const bigfloat& bf1, const bigfloat& bf2)
{
	return (bf1 == bf2 || bf1 > bf2);
}

// оператор меньше
bool operator <(const bigfloat& bf1, const bigfloat& bf2)
{
	return !(bf1 >= bf2);
}

// оператор меньше или равно
bool operator <=(const bigfloat& bf1, const bigfloat& bf2)
{
	return !(bf1 > bf2);
}

// унарный плюс
bigfloat operator +(const bigfloat& bf)
{
	return bf;
}

// унарный минус
bigfloat operator -(const bigfloat& bf)
{
	bigfloat a = bf;
	a.sign = !a.sign;
	return a;
}

// префиксный инкремент
bigfloat operator ++(bigfloat& bf)
{
	bf = bf + 1_mbf;
	return bf;
}

// постфиксный инкремент
bigfloat operator ++(bigfloat& bf, int)
{
	bigfloat a = bf;
	bf = bf + 1_mbf;
	return a;
}

// префиксный декремент
bigfloat operator --(bigfloat& bf)
{
	bf = bf - 1_mbf;
	return bf;
}

// постфиксный декремент
bigfloat operator --(bigfloat& bf, int)
{
	bigfloat a = bf;
	bf = bf - 1_mbf;
	return a;
}

// оператор умножение
bigfloat operator *(const bigfloat& bf1, const bigfloat& bf2)
{
	std::string c = {};
	bigfloat ans;
	int len1 = bf1.num.length(), len2 = bf2.num.length();
	for (int i = len1 + len2 - 1; i >= 0; --i)
	{
		c.append("0");
	}
	int k;
	for (int i = len2 - 1; i >= 0; --i)
	{
		
		for (int j = len1 - 1; j >= 0; --j)
		{
			k = (bf2.num[i] - '0') * (bf1.num[j] - '0');
			c[i + j + 1] += k%10;
			if (c[i + j + 1] > '9')
			{
				c[i + j] += 1;
				c[i + j + 1] -= 10;
			}
			c[i + j] += k/10;
		}
	}
	ans.power = bf1.power + bf2.power;
	while (c[0] == '0' && c.length() - ans.power > 1){c.erase(0, 1);}
	ans.tol = (bf1.tol > bf2.tol ? bf1.tol : bf2.tol);
	ans.num = c;
	ans.sign = (bf1.sign == bf2.sign ? false : true);
	return ans;
}

// оператор деление
bigfloat operator /(const bigfloat& bf1, const bigfloat& bf2)
{
	if (bf2.is_zero())
	{
		std::cout << "wrong input" << std::endl;
		exit(1);
	}
	bigfloat op1 = bf1, op2 = bf2;
	bigfloat ans;
	bigfloat a;
	bigfloat k;
		
	std::string c = {};
	op1.power = 0;
	op2.power = 0;
	op1.sign = 0;
	op2.sign = 0;
	
	int pow = bf1.power - bf2.power;
	op1.add_zeros(op1.tol - pow);
	pow = op1.power + pow;
	int len = op1.num.length();
	a.num = "";

	for (int i = 0; i < len; i++)
	{
		k.num = "0";
		if (a.is_zero())
		{a.num = op1.num.substr(i, 1);}
		else{a.num.append(op1.num.substr(i, 1));}

		while ((k + 1_mbf)*op2 <= a){++k;}
		a = a - k*op2;
		c.append(k.num);
	}
	ans.power = pow;
	while (c[0] == '0' && c.length() - ans.power > 1){c.erase(0, 1);}
	ans.num = c;
	ans.sign = (bf1.sign == bf2.sign ? false : true);
	ans.tol = bf1.tol;
	
	ans.erase_last_nulls();
	return ans;
}


bigfloat operator +=(bigfloat& bf1, const bigfloat& bf2)
{
	bf1 = bf1 + bf2;
	return bf1;
}

bigfloat operator -=(bigfloat& bf1, const bigfloat& bf2)
{
	bf1 = bf1 - bf2;
	return bf1;
}

bigfloat operator *=(bigfloat& bf1, const bigfloat& bf2)
{
	bf1 = bf1 * bf2;
	return bf1;
}

bigfloat operator /=(bigfloat& bf1, const bigfloat& bf2)
{
	bf1 = bf1 / bf2;
	return bf1;
}