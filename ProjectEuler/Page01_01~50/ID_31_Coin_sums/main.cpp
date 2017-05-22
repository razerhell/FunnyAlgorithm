//Coin sums
//Problem 31
//In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation :
//
//1p, 2p, 5p, 10p, 20p, 50p, £1(100p) and £2(200p).
//It is possible to make £2 in the following way :
//
//1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
//How many different ways can £2 be made using any number of coins ?


//Answer:
//73682
//Completed on Mon, 22 May 2017, 10 : 41


#include <iostream>
#include <map>
using namespace std;

#define COIN_KINDS		8
#define TARGET_VALUE	200

int COIN_VALUE[COIN_KINDS] = {1, 2, 5, 10, 20, 50, 100, 200};

int main(int argc, char * argv[])
{

	int *kindsRecord = new int[TARGET_VALUE + 1];
	for (int i = 0; i < TARGET_VALUE + 1; ++i)
		kindsRecord[i] = 0;
	kindsRecord[0] = 1;

	for (int i = 0; i < COIN_KINDS; ++i)
		for (int j = COIN_VALUE[i]; j < TARGET_VALUE + 1; ++j)
			kindsRecord[j] += kindsRecord[j - COIN_VALUE[i]];

	printf("\nkinds: %d \n\n", kindsRecord[TARGET_VALUE]);

	for (int i = 0; i < TARGET_VALUE + 1; ++i)
		printf("%d: %d\n", i, kindsRecord[i]);

	delete[] kindsRecord;
	system("pause");
	return 0;
}