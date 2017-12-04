//The number, 197, is called a circular prime because all rotations of the digits : 
//
//197, 971, and 719, are themselves prime.
//
//There are thirteen such primes below 100 : 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
//
//How many circular primes are there below one million ?

//Answer:
//40730
//Completed on Mon, 4 Dec 2017, 13 : 33

#include <iostream>
#include <unordered_set>

// 获取小于某个数的所有质数
void getBasePrimeNumber(std::unordered_set<int> & basePrimeNums, int maxLimit);

// 辨别一个数是否是质数
bool isPrime(int num, std::unordered_set<int> * pBaseSet);
bool isPrime(int num);

// 分解出数字的每一位
void intToDigitList(int num, std::list<int>& digitList);

// is there any 2 or 5?
bool isThereAny2or5(std::list<int>& nums);

// 将列表组合为整型数
int digitListToInt(std::list<int>& digitList);

int main(int argc, char *argv[])
{
	int maxLimit = 1000000;
	int basePrimeMax = static_cast<int>(sqrt(maxLimit)) + 1;
	
	std::unordered_set<int> basePrimeNumSet;
	getBasePrimeNumber(basePrimeNumSet, basePrimeMax);
	std::unordered_set<int> circularPrimeSet = { 2, 3, 5 };
	std::list<int> digitList;

	// 遍历 1 ~ 1,000,000
	for (int i = 7; i < maxLimit; i += 2) // 剪枝1：偶数直接过滤
	{
		// 如果不是质数则跳过
		if (!isPrime(i, &basePrimeNumSet))
			continue;
		
		// 如果分解结果中有2或5则直接跳过
		intToDigitList(i, digitList);
		if (isThereAny2or5(digitList))
			continue ;

		// 循环n次，若循环过程中出现了非质数，则跳过
		size_t j = 1;
		while (j < digitList.size())
		{
			int tempNum = digitList.front();
			digitList.pop_front();
			digitList.push_back(tempNum);
			int tempRes = digitListToInt(digitList);
			if (!isPrime(tempRes, &basePrimeNumSet))
				break;
			j++;
		}

		if (j == digitList.size())
			circularPrimeSet.insert(i);
	}

	printf("set nums: %d\n", circularPrimeSet.size());
	system("pause");
	return 0;
}

void getBasePrimeNumber(std::unordered_set<int> & basePrimeNums, int maxLimit)
{
	if (maxLimit <= 1)
		return;
	if (maxLimit == 2)
	{
		basePrimeNums.insert(2);
		return;
	}
	if (maxLimit == 3)
	{
		basePrimeNums.insert(2);
		basePrimeNums.insert(3);
		return;
	}

	basePrimeNums.insert(2);
	basePrimeNums.insert(3);

	for (int i = 4; i <= maxLimit; ++i)
	{
		if (isPrime(i, &basePrimeNums))
			basePrimeNums.insert(i);
	}
}

bool isPrime(int num, std::unordered_set<int> * pBaseSet)
{
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

void intToDigitList(int num, std::list<int>& digitList)
{
	digitList.clear();
	while (num != 0)
	{
		digitList.push_front(num % 10);
		num /= 10;
	}
}


bool isThereAny2or5(std::list<int>& nums)
{
	for (int i : nums)
	{
		if (i % 2 == 0 || i % 5 == 0)
			return true;
	}

	return false;
}


int digitListToInt(std::list<int>& digitList)
{
	int res = 0;

	for (int num : digitList)
	{
		res *= 10;
		res += num;
	}

	return res;
}
