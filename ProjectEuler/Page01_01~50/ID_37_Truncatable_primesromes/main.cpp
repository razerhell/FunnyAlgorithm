//Truncatable primes
//Problem 37
//The number 3797 has an interesting property.
//
//Being prime itself, it is possible to continuously remove digits from left to right, 
//
//and remain prime at each stage : 
//
//3797, 797, 97, and 7. 
//
//Similarly we can work from right to left : 
//
//3797, 379, 37, and 3.
//
//Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
//
//NOTE : 2, 3, 5, and 7 are not considered to be truncatable primes.
//
//Answer : 
//748317
//23
//37
//53
//73
//313
//317
//373
//797
//3137
//3797
//739397
//Completed on Wed, 20 Dec 2017, 15:10


#include <iostream>
#include <unordered_set>

bool isPrime(int num, std::unordered_set<int> * pBaseSet, int opFlag = 0);
bool isPrime(int num);
bool isTruncatablePrimes(int num, std::unordered_set<int> * pBaseSet);
void numToVec(int num, int base, std::vector<int> & vec);
int vecToNum(const std::vector<int> & vec, size_t s, size_t e);

int main(int argc, char * argv[])
{

	std::unordered_set<int> baseSet = { 2, 3, 5, 7 };
	std::unordered_set<int> truncatablePrimes;

	for (int i = 11; truncatablePrimes.size() < 11; ++i)
	{
		if (i % 100000 == 0)
			std::cout << i << std::endl;

		if (i == 27)
		{
			i = i;
		}

		if (!isPrime(i, &baseSet))
		{
			continue;
		}

		baseSet.insert(i);
		//std::cout << i << std::endl;

		if (!isTruncatablePrimes(i, &baseSet))
		{
			continue;
		}
		truncatablePrimes.insert(i);
		std::cout << i << std::endl;
	}

	std::cin.get();
	return 0;
}

int vecToNum(const std::vector<int> & vec, size_t s, size_t e)
{
	int num = 0;
	if (vec.empty())
		return 0;
	if (s > e)
		return 0;
	if (s >= vec.size() || e >= vec.size())
		return 0;

	while (e > s)
	{
		num *= 10;
		num += vec[s];
		++s;
	}
	num *= 10;
	num += vec[s];

	return num;
}


void numToVec(int num, int base, std::vector<int> & vec)
{
	std::list<int> vecList;
	while (num > 0)
	{
		vecList.push_front(num % base);
		num /= base;
	}

	vec.clear();
	vec.resize(vecList.size());
	for (size_t i = 0; i < vec.size(); ++i)
	{
		vec[i] = vecList.front();
		vecList.pop_front();
	}
}

bool isTruncatablePrimes(int num, std::unordered_set<int> * pBaseSet)
{
	std::vector<int> vec;
	numToVec(num, 10, vec);
	size_t i = 1;
	size_t j = vec.size() - 2;
	int numLeft;
	int numRight;

	while (i < vec.size())
	{
		numLeft = vecToNum(vec, 0, j);
		numRight = vecToNum(vec, i, vec.size() - 1);
		if (isPrime(numLeft, pBaseSet) && isPrime(numRight, pBaseSet))
		{
			++i;
			--j;
			continue;
		}
		return false;
	}

	return true;
}

bool isPrime(int num, std::unordered_set<int> * pBaseSet, int opFlag)
{
	if (num < 2)
		return false;
	// 如果质数已经存在于集合中了
	if (pBaseSet->find(num) != pBaseSet->end())
		return true;

	// 若没有基础集合则需自增判定
	if (pBaseSet == NULL)
		return isPrime(num);


	for (int base : (*pBaseSet))
	{
		if (num % base == 0)
			return false;
	}

	switch (opFlag)
	{
	case 1:
		pBaseSet->insert(num);
		break;
	default:
		break;
	}

	return true;
}

bool isPrime(int num)
{
	int maxLimit = static_cast<int>(sqrt(num)) + 1;

	// 小于等于1的数实际为非法数
	if (num <= 1)
		return false;

	// 遍历一个数到它的平方根若没有出现质因数，则该数字为一个质数
	for (int i = 4; i < maxLimit; ++i)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}