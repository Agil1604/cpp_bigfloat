#include <iostream>
#include "bigfloat.h"

void calc_split(int a, int b, bigfloat& Pab, bigfloat& Qab, bigfloat& Rab)
{
    bigfloat Pam = 0_mbf, Qam = 0_mbf, Ram = 0_mbf;
    bigfloat Pmb = 0_mbf, Qmb = 0_mbf, Rmb = 0_mbf;
    if (b == a + 1)
    {   
        bigfloat six = 6_mbf, five = 5_mbf, two = 2_mbf, one = 1_mbf, la;
		la = a;
        Pab = -(six*la - five)*(two*la - one)*(six*la - one);
        Qab = 10939058860032000_mbf * (la * la * la);
        Rab = Pab * (545140134_mbf*la + 13591409_mbf);
    }
    else
    {
        int m = (a + b) / 2;
        calc_split(a, m, Pam, Qam, Ram);
        calc_split(m, b, Pmb, Qmb, Rmb);
        
        Pab = Pam * Pmb;
        Qab = Qam * Qmb;
        Rab = Qmb * Ram + Pam * Rmb;
    }
}

bigfloat square_root(bigfloat n) {
    bigfloat x = 1_mbf;
	bigfloat last;
    bigfloat two(n.tol);
    two = 2_mbf;
    while (x * x != n && last != x)
	{
		last = x;
        x = (x + n / x) / two;
	}
	return x;
}

bigfloat count_pi(int tolerance)
{
    bigfloat P1n = 0_mbf, Q1n = 0_mbf, R1n = 0_mbf;
    calc_split(1, tolerance / 10 + 2, P1n, Q1n, R1n);
    bigfloat rt = 10005_mbf;
    rt.set_tolerance(tolerance + 10);
    rt = square_root(rt);

    bigfloat num1 = 426880_mbf, num2 = 13591409_mbf;

    bigfloat pi;
	pi = (num1 * rt * Q1n) / (num2*Q1n + R1n);
    pi.set_tolerance(tolerance);

    return pi;
}

int main()
{
	int a;
 	std::cin >> a;
	std::cout << count_pi(a) << std::endl;
	return 0;
}
