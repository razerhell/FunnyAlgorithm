//Pandigital products
//Problem 32
//We shall say that an n - digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5 - digit number, 15234, is 1 through 5 pandigital.
//
//The product 7254 is unusual, as the identity, 39 ¡Á 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
//
//Find the sum of all products whose multiplicand / multiplier / product identity can be written as a 1 through 9 pandigital.
//
//HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
//
//	Answer :
//	45228
//	Completed on Wed, 24 May 2017, 16 : 53

#include <iostream>
#include <set>

using namespace std;

int constructNum(int *num)
{
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		sum *= 10;
		sum += num[i];
	}

	return sum;
}

void find5DigitNum(set<int>& numSet, int *num, int currentDig, bool *record)
{
	if (currentDig >= 5)
	{
		numSet.insert(constructNum(num));
		return;
	}

	for (int i = 1; i < 10; ++i)
	{
		if (record[i]) continue;

		record[i] = true;

		num[currentDig] = i;
		find5DigitNum(numSet, num, currentDig + 1, record);
		record[i] = false;
	}
}

void findAll5DigitNum(set<int> &numSet)
{
	bool record[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	int number[5];

	find5DigitNum(numSet, number, 0, record);

}

void fillNumInRecord(int num, int *record)
{
	while (num)
	{
		++record[num % 10];
		num /= 10;
	}
}

bool check(int num1, int num2, int &pro)
{
	int record[10] = { false, false , false , false , false , false , false , false , false , false };
	pro = num1 * num2;

	fillNumInRecord(num1, record);
	fillNumInRecord(num2, record);
	fillNumInRecord(pro, record);

	if (0 != record[0]) return false;
	for (int i = 1; i < 10; ++i)
		if (record[i] != 1) return false;

	return true;
}

int main(int argc, char * argv[])
{
	
	set<int> numSet;
	set<int> avalibleSet;
	findAll5DigitNum(numSet);

	printf("\nnumset size %d \n\n", numSet.size());

	set<int>::iterator ite = numSet.begin();

	int num1, num2, pro;
	while (numSet.end() != ite)
	{
		num1 = *ite / 1000;
		num2 = *ite % 1000;
		if (check(num1, num2, pro))
		{
			avalibleSet.insert(pro);
			printf("%d\t%d\t%d\n", num1, num2, pro);
		}

		num1 = *ite / 10000;
		num2 = *ite % 10000;
		if (check(num1, num2, pro))
		{
			avalibleSet.insert(pro);
			printf("%d\t%d\t%d\n", num1, num2, pro);
		}

		++ite;
	}

	printf("\navalibleSet size %d \n\n", avalibleSet.size());
	
	ite = avalibleSet.begin();
	int sum = 0;
	while (ite != avalibleSet.end())
		sum += *ite++;

	printf("\nsum %d \n", sum);

	system("pause");
	return 0;
}