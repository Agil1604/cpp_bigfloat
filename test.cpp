#include <iostream>
#include <string>

int main()
{
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

		ans.num = c;
		ans.power = a.power;
		ans.tol = a.tol;
		ans.sign = a.sign;
	
}
