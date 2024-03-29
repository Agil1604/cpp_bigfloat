#pragma once
#include <string>

class bigfloat
{
	private:
		void add_zeros(int n);
		void erase_last_nulls();
	
		std::string num; // само число без учета знака и точки
		unsigned power;  // положение точки как 10^(-power)
		bool sign;  // знак числа: True -- отрицательное, False -- положительное
	public:

		int tol;  // максимальное количество знаков после запятой
		
		// Конструкторы
		explicit bigfloat(int tolerance = 6);
		explicit bigfloat(std::string number, int tolerance = 6);

		
		// Методы
		bool is_zero() const;
		std::string get_str() const;
		void set_tolerance(int tolerance);
		
		// Перегрузка операторов
		const bigfloat& operator=(int x);
				
		friend std::ostream& operator <<(std::ostream& out, const bigfloat& bf);
		friend std::istream& operator >>(std::istream &in, bigfloat& bf);
		
		friend bigfloat operator +(const bigfloat& bf);
		friend bigfloat operator -(const bigfloat& bf);
		friend bigfloat operator +(const bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator -(const bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator *(const bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator /(const bigfloat& bf1, const bigfloat& bf2);
		
		friend bigfloat operator ++(bigfloat& bf);
		friend bigfloat operator --(bigfloat& bf);
		friend bigfloat operator ++(bigfloat& bf, int);
		friend bigfloat operator --(bigfloat& bf, int);
		
		friend bool operator <(const bigfloat& bf1, const bigfloat& bf2);
		friend bool operator >(const bigfloat& bf1, const bigfloat& bf2);
		friend bool operator >=(const bigfloat& bf1, const bigfloat& bf2);
		friend bool operator <=(const bigfloat& bf1, const bigfloat& bf2);
		friend bool operator ==(const bigfloat& bf1, const bigfloat& bf2);
		friend bool operator !=(const bigfloat& bf1, const bigfloat& bf2);
				
		friend bigfloat operator +=(bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator -=(bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator *=(bigfloat& bf1, const bigfloat& bf2);
		friend bigfloat operator /=(bigfloat& bf1, const bigfloat& bf2);
		
		// в разработке

		// friend bigfloat operator %=(bigfloat& bf1, const int& bf2);
		// friend bigfloat operator %(const bigfloat& bf1, const int& bf2);
		// operator<=>				
};


bigfloat operator ""_mbf(const char* str);

bigfloat square_root(bigfloat n);
