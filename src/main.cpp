#include <iostream>
#include <time.h>
#include "bigfloat.h"
#include "my_pi.h"


int main()
{
    clock_t t;
	int a;
    std::cout << "enter your tolerance: ";
 	std::cin >> a;
	t = clock();
    std::cout << "pi: " << count_pi(a) << std::endl;
	t = clock() - t;
    std::cout << "calculation time: " << ((float)t)/CLOCKS_PER_SEC << std::endl;
    return 0;
}