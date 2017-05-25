//Digit factorials
//Problem 34
//145 is a curious number, as 1!+ 4!+ 5!= 1 + 24 + 120 = 145.
//
//Find the sum of all numbers which are equal to the sum of the factorial of their digits.
//
//Note: as 1!= 1 and 2!= 2 are not sums they are not included.

//Answer:
//40730
//Completed on Thu, 25 May 2017, 10 : 30

#include <iostream>
#include <vector>

using namespace std;
#define LIMIT		(int)1e7

void getNumberFactorials(vector<int> &vec)
{
	vec.clear();
	vec.resize(10);
	int pro = 1;
	vec[0] = 1;
	for (int i = 1; i < 10; ++i)
	{
		vec[i] = pro *= i;
	}
}

void showVecInt(const vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		printf("%d\n", vec[i]);
}

int main(int argc, char * argv[])
{
	vector<int> vec;
	vector<int> digitFactorials;
	getNumberFactorials(vec);

	for (unsigned int i = 10; i < LIMIT; ++i)
	{
		unsigned int sum = 0;
		unsigned int number = i;
		while (number)
		{
			sum += vec[number % 10];
			number /= 10;
		}
		if (i % (int)1e6 == 0)
			printf("===\n%d\n===\n", i);
		if (sum == i)
		{
			digitFactorials.push_back(sum);
			printf("%d\n", sum);
		}
	}
	
	int sum = 0;
	for (size_t i = 0; i < digitFactorials.size(); ++i)
		sum += digitFactorials[i];
	printf("size : %d \n", sum);

	system("pause");
	return 0;
}