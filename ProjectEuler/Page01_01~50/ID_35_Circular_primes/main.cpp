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

// ��ȡС��ĳ��������������
void getBasePrimeNumber(std::unordered_set<int> & basePrimeNums, int maxLimit);

// ���һ�����Ƿ�������
bool isPrime(int num, std::unordered_set<int> * pBaseSet);
bool isPrime(int num);

// �ֽ�����ֵ�ÿһλ
void intToDigitList(int num, std::list<int>& digitList);

// is there any 2 or 5?
bool isThereAny2or5(std::list<int>& nums);

// ���б����Ϊ������
int digitListToInt(std::list<int>& digitList);

int main(int argc, char *argv[])
{
	int maxLimit = 1000000;
	int basePrimeMax = static_cast<int>(sqrt(maxLimit)) + 1;
	
	std::unordered_set<int> basePrimeNumSet;
	getBasePrimeNumber(basePrimeNumSet, basePrimeMax);
	std::unordered_set<int> circularPrimeSet = { 2, 3, 5 };
	std::list<int> digitList;

	// ���� 1 ~ 1,000,000
	for (int i = 7; i < maxLimit; i += 2) // ��֦1��ż��ֱ�ӹ���
	{
		// �����������������
		if (!isPrime(i, &basePrimeNumSet))
			continue;
		
		// ����ֽ�������2��5��ֱ������
		intToDigitList(i, digitList);
		if (isThereAny2or5(digitList))
			continue ;

		// ѭ��n�Σ���ѭ�������г����˷�������������
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
	// ��������Ѿ������ڼ�������
	if (pBaseSet->find(num) != pBaseSet->end())
		return true;

	// ��û�л����������������ж�
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
	
	// С�ڵ���1����ʵ��Ϊ�Ƿ���
	if (num <= 1)
		return false; 
	
	// ����һ����������ƽ������û�г������������������Ϊһ������
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
