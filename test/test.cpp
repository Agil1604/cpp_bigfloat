#include <iostream>
#include "bigfloat.h"
#include "gtest/gtest.h"

TEST(test1, comparison)
{
    EXPECT_EQ(1, (1.5_mbf == 1.500_mbf));
    EXPECT_EQ(1, (1.5_mbf >= 1.00_mbf));
    EXPECT_EQ(1, (1_mbf == 1.00000_mbf));
    EXPECT_EQ(0, (1.0_mbf != 1.00000_mbf));
    EXPECT_EQ(0, (1.00_mbf > 1.00000_mbf));
    EXPECT_EQ(0, (1.000_mbf < 1.00000_mbf));
    EXPECT_EQ(1, (1.0000_mbf >= 1.00000_mbf));
}
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
// }


// TEST(test2, )
// {
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
// }


// TEST(test3, )
// {
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
// }

// TEST(test4, )
// {
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
// }

// TEST(test5, )
// {
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
// }

// TEST(test6, )
// {
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
//     EXPECT_EQ(1, );
// }
// void test1(void)
// {
// 	std::cout << "test 1: ";
// 	bool x = true;
	
// 	if (1.00000_mbf <= 1.00000_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (1_mbf <= 5_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (1_mbf >= 5_mbf){x*=0;}
	
// 	if (1_mbf >= -5_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (1.5_mbf >= 1_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (5_mbf != 5.0_mbf){x*=0;}
	
// 	if (5_mbf == -5.0_mbf){x*=0;}

// 	if (x){std::cout << "correct" << std::endl;}
// 	else{std::cout << "wrong" << std::endl;}
// }

// void test2(void)
// {
// 	std::cout << "test 2: ";
// 	bool x = true;
	
// 	if (1_mbf + 1_mbf == 2_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (99_mbf + 1.5_mbf == 100.5_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (1_mbf + 1.5_mbf == 2.50_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (-1_mbf + 1.5_mbf == 0.5_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (10_mbf + (-1.5_mbf) != -8.5_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (0_mbf + 0_mbf == -0_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (-1_mbf - 1.5_mbf != 2_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (-1_mbf + 1.5_mbf == 0.5_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (100_mbf - 1.5_mbf == 98.5_mbf){x*=1;}
// 	else{x*=0;};
	
// 	if (-100_mbf + 1.5_mbf == -98.5_mbf){x*=1;}
// 	else{x*=0;}

	
// 	if (x){std::cout << "correct" << std::endl;}
// 	else{std::cout << "wrong" << std::endl;}
// }

// void test3(void)
// {
// 	std::cout << "test 3: ";
// 	bool x = true;
	
// 	if (1_mbf * 1_mbf == 1_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (1.5_mbf * 1.5_mbf == 2.25_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (0_mbf * 1.5_mbf == 0_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (-1_mbf * (-1.5_mbf) == 1.5_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (10_mbf * (-1.5_mbf) == -15_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (0_mbf * 0_mbf == -0_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (100_mbf * 0.5_mbf == 50_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (x){std::cout << "correct" << std::endl;}
// 	else{std::cout << "wrong" << std::endl;}
// }

// void test4(void)
// {
// 	std::cout << "test 4: ";
// 	bool x = true;
	
// 	if (100_mbf / 0.5_mbf == 200_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (0.5_mbf / 0.5_mbf == 1_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (100_mbf / -0.5_mbf == -200_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (1_mbf / 5_mbf == 0.2_mbf){x*=1;}
// 	else{x*=0;}
// 	if (100_mbf / 100_mbf == 1_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (1000_mbf / 10_mbf == 100_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (x){std::cout << "correct" << std::endl;}
// 	else{std::cout << "wrong" << std::endl;}
// }

// void test5(void)
// {
// 	std::cout << "test 5: ";
// 	bool x = true;
// 	bigfloat a;
	
// 	a = 1.555555_mbf;
// 	a.set_tolerance(3);
	
// 	if (a == 1.555_mbf){x*=1;}
// 	else{x*=0;}
	
// 	if (!a.is_null()){x*=1;}
// 	else{x*=0;}	
	
// 	a = 0_mbf;
// 	if (a.is_null()){x*=1;}
// 	else{x*=0;}	
	
// 	if (a.get_str() == "0"){x*=1;}
// 	else{x*=0;}
	
// 	a = -1.5_mbf;
// 	if (a.get_str() == "-1.5"){x*=1;}
// 	else{x*=0;}
	
// 	if (x){std::cout << "correct" << std::endl;}
// 	else{std::cout << "wrong" << std::endl;}
// }

// int main()
// {
// 	test1();
// 	test2();
// 	test3();
// 	test4();
// 	test5();
// 	return 0;
// }
