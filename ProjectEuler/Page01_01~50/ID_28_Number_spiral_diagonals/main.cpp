//Number spiral diagonals
//Problem 28
//Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows :
//
//21 22 23 24 25
//20  7  8  9 10
//19  6  1  2 11
//18  5  4  3 12
//17 16 15 14 13
//
//It can be verified that the sum of the numbers on the diagonals is 101.
//
//What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way ?
//Answer:
//669171001
//Completed on Thu, 18 May 2017, 08 : 43


#include <iostream>

int main(int argc, char * argv[])
{
	unsigned int size;
	scanf("%d", &size);

	unsigned int step;
	unsigned int sum = 1;
	
	size--;
	size /= 2;

	unsigned int r = 8 * size * (size + 1) * (2 * size + 1) / 3 + 2 * size * (size + 1) + 4 * size + 1;

	printf("r: %d\n", r);

	system("pause");
	return 0;
}