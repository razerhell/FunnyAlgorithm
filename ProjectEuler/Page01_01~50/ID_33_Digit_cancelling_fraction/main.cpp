//Digit cancelling fractions
//Problem 33
//The fraction 49 / 98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49 / 98 = 4 / 8, which is correct, is obtained by cancelling the 9s.
//
//We shall consider fractions like, 30 / 50 = 3 / 5, to be trivial examples.
//
//There are exactly four non - trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
//
//If the product of these four fractions is given in its lowest common terms, find the value of the denominator.


//Answer:
//100
//Completed on Thu, 25 May 2017, 08 : 51


#include <iostream>
#include <vector>
using namespace std;

bool isFraction(int num)
{

	if ( num % 10 > num / 100 && num / 10 > 10)
		return true;

	return false;
}

void constructNumVec(vector<int> & vec)
{
	for (int i = 111; i < 1000; ++i)
		if (isFraction(i))	vec.push_back(i);
}

int main(int argc, char * argv[])
{
	vector<int> vec;
	constructNumVec(vec);

	for (size_t i = 0; i < vec.size(); ++i)
	{
		int number = vec[i];
		double num1 = double(number / 10) / (number % 100);
		double num2 = double(number / 100) / (number % 10);

		if (fabs(num1 - num2) < 1e-3)
			printf("%d\n", number);
	}

	system("pause");
	return 0;
}