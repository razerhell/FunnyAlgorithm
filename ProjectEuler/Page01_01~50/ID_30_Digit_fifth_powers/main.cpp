//Digit fifth powers
//Problem 30
//Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits :
//
//1634 = 14 + 64 + 34 + 44
//8208 = 84 + 24 + 04 + 84
//9474 = 94 + 44 + 74 + 44
//As 1 = 14 is not a sum it is not included.
//
//The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
//Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.


//Answer:
//443839
//Completed on Sun, 21 May 2017, 08:00


#include <iostream>
using namespace std;

#define MAX_POWER 6
#define POW_5(x)	(x * x * x * x * x)
#define POW_4(x)	(x * x * x * x)

int getDigit(int number, int * digit)
{
	int i = 0;
	while (number != 0)
	{
		digit[i++] = number % 10;
		number /= 10;
	}
	return i;
}

bool isSumOfAPower(const int &number)
{
	int *digit = new int[MAX_POWER];
	int maxi = getDigit(number, digit);
	int sum = 0;

	for (int i = 0; i < maxi; ++i)
	{
		sum += POW_5(digit[i]);
	}

	if (number == sum) 
		return true;
	else
		return false;
}

int main(int argc, char * argv[])
{

	int maxLimit = 1e6;
	printf("\nmaxLimit : %d\n\n", maxLimit);
	int sum = 0;

	for (int i = 10; i < maxLimit; ++i)
		if (isSumOfAPower(i))
		{
			printf("%d\n", i);
			sum += i;
		}

	printf("\nsum : %d\n\n", sum);

	system("pause");
	return 0;
}