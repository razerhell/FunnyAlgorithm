//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>

#define M 20
int findBiggestDiv(int, int);
int main(int argc, char argv[]){
	int n;
	int mul;
	for(n=1, mul=1; n<=M; n++){
		if( !(mul%n) ) continue;
		mul *= (int)(n/findBiggestDiv(mul, n));
	}
	std::cout << mul << std::endl;
	//232792560----------------------------------------------------------------¡Ì
	system("pause");
	return 0;
}
int findBiggestDiv(int a, int b){
	int m;
	for(m=b; m>1; m--) if( !(a%m) && !(b%m)) return m * findBiggestDiv((int)(a/m), (int)(b/m));
	return 1;
}