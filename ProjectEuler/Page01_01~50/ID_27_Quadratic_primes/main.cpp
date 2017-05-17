//Quadratic primes
//Problem 27
//Euler discovered the remarkable quadratic formula :
//
//n*n + n + 41
//It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤390≤n≤39.However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 412 + 41 + 41n = 41, 412 + 41 + 41 is clearly divisible by 41.
//
//The incredible formula n*n−79*n + 1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤790≤n≤79.The product of the coefficients, −79 and 1601, is −126479.
//
//Considering quadratics of the form :
//
//n*n + a*n + b, where |a| ＜1000  and  |b| ＜　1000
//
//Find the product of the coefficients, aa and bb, for the quadratic expression that produces the maximum number of primes for consecutive values of nn, starting with n = 0n = 0.
//
//
//Answer:
//-59231
//Completed on Wed, 17 May 2017, 12 : 10
#include <iostream>
#include <vector>
using namespace std;

#define A_LIMIT	1000
#define B_LIMIT	1000

bool isPrime(int number)
{
	if (number <= 1) return false;
	int temp = (int)sqrt(number);

	for (int i = 2; i <=temp; ++i)
		if (number % i == 0) return false;

	return true;
}

bool isPrime(vector<int> &priVec, int number)
{
	if (number <= 1) return false;
	int temp = (int)sqrt(number);

	for (size_t i = 0; i < priVec.size(); ++i)
		if (number % priVec[i] == 0) return false;

	return true;
}

void generatePriArrays(vector<int> &priArray, int limit)
{
	priArray.clear();
	priArray.push_back(2);
	for (int i = 3; i < limit; ++i)
		if (isPrime(priArray, i))
			priArray.push_back(i);
}

void showVec(const vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		printf("%d ", vec[i]);
	printf("\n");
}

int formulaLimit(int a, int b)
{
	int i;
	for (i = 0; i <= b; ++i)
		if (!isPrime(i * i + a * i + b)) break ;
	return i;
}

int main(int argc, char * argv[])
{
	vector<int> primeArray;
	generatePriArrays(primeArray, B_LIMIT);
	int li = 0;
	int la = 0;
	int lb = 0;

	//printf("%d\n", formulaLimit(-999, 997));

	for (int bi = primeArray.size() - 1; bi >= 0; --bi)
	{
		int b = primeArray[bi];
		for (int usa = 1; usa < A_LIMIT; usa += 2)
		{
			int l = formulaLimit(usa, b);
			if (l > li)
			{
				li = l;
				la = usa;
				lb = b;
				printf("a:%d, b:%d, %d\n", la, lb, li);
			}
			l = formulaLimit(-usa, b);
			if (l > li)
			{
				li = l;
				la = -usa;
				lb = b;
				printf("a:%d, b:%d, %d\n", la, lb, li);
			}
		}
	}

	system("pause");
	return 0;
}