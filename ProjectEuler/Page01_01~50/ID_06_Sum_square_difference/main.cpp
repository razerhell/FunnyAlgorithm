//The sum of the squares of the first ten natural numbers is,
//
//1^2 + 2^2 + ... + 10^2 = 385
//
//The square of the sum of the first ten natural numbers is,
//
//(1 + 2 + ... + 10)^2 = 55^2 = 3025
//
//Hence the difference between the sum of the squares of the first ten 
//
//natural numbers and the square of the sum is 3025  385 = 2640.
//
//Find the difference between the sum of the squares of the first one hundred 
//
//natural numbers and the square of the sum.

#include <iostream>

int main(int argc, char argv[]){
	
	long long int n;
	long long int sum1=0, sum2=0;
	for(n=0; n<=100; n++){
		sum1 += n*n;
		sum2 += n;
	}

	sum2 = sum2 * sum2;

	std::cout << "sum1\t" << sum1 << std::endl << "sum2\t" << sum2 << std::endl << sum2 - sum1 << std::endl;

	//25164150---------------------------------------------¡Ì

	system("pause");
	return 0;
}