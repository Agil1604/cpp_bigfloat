#include <iostream>
#include "bigfloat.h"
#include "gtest/gtest.h"

TEST(test1, comparison)
{
    EXPECT_EQ(1, (1.5_mbf >= 1.00_mbf));
    EXPECT_EQ(0, (1.00_mbf > 1.00000_mbf));
    EXPECT_EQ(0, (1.000_mbf < 1.00000_mbf));
    EXPECT_EQ(1, (1.0000_mbf >= 1.00000_mbf));
    EXPECT_EQ(1, (1.00000_mbf <= 1.00000_mbf));
    EXPECT_EQ(1, (1_mbf <= 5_mbf));
    EXPECT_EQ(0, (1_mbf >= 5_mbf));
    EXPECT_EQ(1, (1_mbf >= -5_mbf));
    EXPECT_EQ(1, (1.5_mbf >= 1_mbf));
}

TEST(test1, equality)
{
    EXPECT_EQ(1, (1.5_mbf == 1.500_mbf));
    EXPECT_EQ(1, (1_mbf == 1.00000_mbf));
    EXPECT_EQ(0, (5_mbf == -5.0_mbf));
    EXPECT_EQ(0, (1.0_mbf != 1.00000_mbf));
    EXPECT_EQ(0, (5_mbf != 5.0_mbf));
}


TEST(test2, checking_plus)
{
    EXPECT_EQ(1, (1_mbf + 1_mbf == 2_mbf));
    EXPECT_EQ(1, (99_mbf + 1.5_mbf == 100.5_mbf));
    EXPECT_EQ(1, (1_mbf + 1.5_mbf == 2.50_mbf));
    EXPECT_EQ(1, (-1_mbf + 1.5_mbf == 0.5_mbf));
    EXPECT_EQ(1, (10_mbf + (-1.5_mbf) != -8.5_mbf));
    EXPECT_EQ(1, (0_mbf + 0_mbf == -0_mbf));
    EXPECT_EQ(1, (-1_mbf + 1.5_mbf == 0.5_mbf));
    EXPECT_EQ(1, (-100_mbf + 1.5_mbf == -98.5_mbf));
}

TEST(test2, checking_minus)
{
    EXPECT_EQ(1, (-0_mbf - 0_mbf == 0_mbf));
    EXPECT_EQ(1, (-1_mbf - 1.5_mbf != 2_mbf));
    EXPECT_EQ(1, (100_mbf - 1.5_mbf == 98.5_mbf));
    EXPECT_EQ(1, (-100_mbf - 1.5_mbf == -101.5_mbf));
    EXPECT_EQ(1, (100000.11_mbf - 1_mbf == 99999.11_mbf));
    EXPECT_EQ(1, (0.931527_mbf - 1324.628914_mbf == -1323.697387_mbf));

}

TEST(test3, multiplication)
{
    EXPECT_EQ(1, (1_mbf * 1_mbf == 1_mbf));
    EXPECT_EQ(1, (1.5_mbf * 1.5_mbf == 2.25_mbf));
    EXPECT_EQ(1, (0_mbf * 1.5_mbf == 0_mbf));
    EXPECT_EQ(1, (-1_mbf * (-1.5_mbf) == 1.5_mbf));
    EXPECT_EQ(1, (10_mbf * (-1.5_mbf) == -15_mbf));
    EXPECT_EQ(1, (0_mbf * 0_mbf == -0_mbf));
    EXPECT_EQ(1, (100_mbf * 0.5_mbf == 50_mbf));
}

TEST(test4, division)
{
    EXPECT_EQ(1, (100_mbf / 0.5_mbf == 200_mbf));
    EXPECT_EQ(1, (0.5_mbf / 0.5_mbf == 1_mbf));
    EXPECT_EQ(1, (100_mbf / -0.5_mbf == -200_mbf));
    EXPECT_EQ(1, (1_mbf / 5_mbf == 0.2_mbf));
    EXPECT_EQ(1, (100_mbf / 100_mbf == 1_mbf));
    EXPECT_EQ(1, (1000_mbf / 10_mbf == 100_mbf));
    EXPECT_EQ(1, (1_mbf / 9_mbf == 0.111111_mbf));
}


TEST(test5, operations_and_assigment)
{
    bigfloat a = 1.555555_mbf;

	a += 1.5_mbf;
    EXPECT_EQ(1, (a == 3.055555_mbf));
    
    a *= 2.1_mbf;
    bigfloat ans = 3.055555_mbf*2.1_mbf;

    EXPECT_EQ(a, ans);
    
    a /= 64_mbf;
    ans = ans/64_mbf;
    EXPECT_EQ(a, ans);
    
    a -= -0.89974_mbf;
    ans = ans - (-0.89974_mbf);
    EXPECT_EQ(a, ans);
}


TEST(test6, other)
{
    bigfloat a = 1.555555_mbf;
	a.set_tolerance(3);

    EXPECT_EQ(1, (a == 1.555_mbf));

	a = 0_mbf;
    EXPECT_EQ(1, a.is_zero());
    EXPECT_EQ(1, (a.get_str() == "0"));
	
    a = -1.5_mbf;
    EXPECT_EQ(1, (a.get_str() == "-1.5"));
}

