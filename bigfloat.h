#pragma once
#include <iostream>
#include <string>

class bigfloat
{
	public:
		std::string num; // само число без учета знака и точки
		unsigned power;  // положение точки как 10^(-power)
		int tol;  // максимальное количество знаков после запятой
		bool sign;  // знак числа: True -- отрицательное, False -- положительное
		
		// Конструкторы
		bigfloat(int tolerance = 6);
		bigfloat(std::string number, int tolerance = 6);
		bigfloat(const bigfloat& bf);
		
		
		// Деструкторы
		
		// Методы
		
		bigfloat count_pi(int tolerance);
		// bool ch_tol();  // change tolerance
		bool is_null(bigfloat bf);
		void erase_last_nulls(bigfloat& bf);
		friend std::string get_str(bigfloat& bf);
		// Перегрузка операторов
		const bigfloat& operator=(const bigfloat& bf);//готово
		// friend bigfloat operator "" _mbf(std::string number);
		friend std::ostream& operator <<(std::ostream& out, const bigfloat& bf);//готово
		friend std::istream& operator >>(std::istream &in, bigfloat& bf);//готово
		friend bigfloat operator +(const bigfloat& bf);//готово
		friend bigfloat operator -(const bigfloat& bf);//готово
		friend bigfloat operator +(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bigfloat operator -(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bigfloat operator *(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bigfloat operator /(const bigfloat& bf1, const bigfloat& bf2);
		//friend bigfloat operator %(const bigfloat& bf1, const int& bf2);
		friend bigfloat operator ++(bigfloat& bf);//готово
		friend bigfloat operator --(bigfloat& bf);//готово
		friend bigfloat operator ++(bigfloat& bf, int);
		friend bigfloat operator --(bigfloat& bf, int);
		friend bigfloat operator +=(bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator -=(bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator *=(bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator /=(bigfloat& bf1, const bigfloat& bf2);
		//friend bigfloat operator %=(bigfloat& bf1, const int& bf2);
		// friend bool operator !(const bigfloat& bf);
		// friend bool operator &&(const bigfloat& bf1, const bigfloat& bf2);
		// friend bool operator ||(const bigfloat& bf1, const bigfloat& bf2);
		friend bool operator <(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bool operator >(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bool operator >=(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bool operator <=(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bool operator ==(const bigfloat& bf1, const bigfloat& bf2);//готово
		friend bool operator !=(const bigfloat& bf1, const bigfloat& bf2);//готово
		
		friend void add_zeros(bigfloat& bf, int n);
};

