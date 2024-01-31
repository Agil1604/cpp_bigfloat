#include <iostream>
#include <string>

int main()
{
	//сравнять степени и запомнить
	int pow = 3;
	std::string a = "999999999";
	// найти разность длин
	int lena = 9;

	std::string b = "25670";
	int lenb = 5;
	
	std::string c;
	int k = 0;
	// миинмальная длина
	for (int i = 4; i>=0; --i)
	{
		k += a[i + 4] + b[i] - '0';
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
	// остаток длины
	for (int i = 3; i>=0; --i)
	{
		k += a[i];
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
	std::cout<<c<< std::endl;
}
