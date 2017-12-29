//A palindromic number reads the same both ways. The largest palindrome made from the product 
//	
//	of two 2-digit numbers is 9009 = 91 99.
//
//Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <cmath>

bool f(int);
int main(int argc, char argv[]){
	int n1, n2;
	int mul;
	int biggest=0;
	for(n1=999; n1>99; n1--)
		for(n2=n1; n2>99; n2--){
			mul = n1*n2;
			if(mul>biggest && f(mul)) biggest = mul;
		}
	
	std::cout << biggest << std::endl;
	system("pause");
	//906609------------------------------------------------------------------------¡Ì
	return 0;
}

bool f(int mul){
	int digit = 1;
	int m = mul;
	int n;
	bool ispalind = true;
	while(m/10){
		digit++;
		m /= 10;
	}
	for(n=digit/2; n>0; n--){
		if( ((int)(mul/pow(10, n-1)))%10 != ((int)(mul/pow(10, digit-n)))%10 ){
			ispalind = false;
			break;
		}
	}
	return ispalind;
}