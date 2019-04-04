#include <iostream>

int averageThree(int one, int two, int three)
{
	return (one + two + three) / 3;
}

int averageFourEven(int one, int two, int three, int four)
{
	int sum = 0;

	if(one % 2 == 0)
	{
		sum += one;
	}
	if(two % 2 == 0)
	{
		sum += two;
	}
	if(three % 2 == 0)
	{
		sum += three;
	}
	if(four % 2 == 0)
	{
		sum += four;
	}

	return sum;
}

int main()
{
	int number = 
}

