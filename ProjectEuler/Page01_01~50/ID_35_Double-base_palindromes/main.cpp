//Double - base palindromes
//Problem 36
//The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
//
//Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
//
//(Please note that the palindromic number, in either base, may not include leading zeros.)

//Answer:
//872185
//Completed on Thu, 7 Dec 2017, 10:07

#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>

void numToCharVec(int num, int base, std::vector<char> & charVec);
bool isPalindromic(const std::vector<char> & charVec);
int main(int argc, char * argv[])
{
	std::unordered_set<int> numSet;
	int sum = 0;

	for (int i = 0; i < 1000000; ++i)
	{
		std::vector<char> base10, base2;
		numToCharVec(i, 10, base10);
		numToCharVec(i, 2, base2);

		if (isPalindromic(base10) && isPalindromic(base2))
		{
			numSet.insert(i);
		}
	}

	for (int i : numSet)
	{
		sum += i;
	}


	printf("set size : %d, sum = %d\n", numSet.size(), sum);


	system("pause");
	return 0;
}


void numToCharVec(int num, int base, std::vector<char> & charVec)
{
	std::list<char> charList;
	while (num > 0)
	{
		charList.push_front(static_cast<char>(num % base));
		num /= base;
	}

	charVec.clear();
	charVec.resize(charList.size());
	for (size_t i = 0; i < charVec.size(); ++i)
	{
		charVec[i] = charList.front();
		charList.pop_front();
	}
}

bool isPalindromic(const std::vector<char> & charVec)
{
	if (charVec.empty())
		return false;
	size_t i, j, k;
	i = 0;
	j = charVec.size() - 1;

	while (i < j)
	{
		if (charVec[i] != charVec[j])
			return false;
		++i;
		--j;
	}

	return true;
}
