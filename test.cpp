#include <iostream>
#include <string>

int main()
{
	std::string a = "127";
	std::string b = "256";
	std::string c;
	int k = 0;
	for (int i = 2; i>=0; --i)
	{
		k += a[i] + b[i] - '0';
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
	std::cout<<c<< std::endl;
}
