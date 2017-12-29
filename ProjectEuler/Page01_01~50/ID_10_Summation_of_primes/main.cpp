//Summation of primes
//Problem 10
//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

#include <iostream>
#include <cmath>

#define B 2000000

int* p;
int length = 10;

void addLength(int j, int n){
	int* a = p;
	int m;
	length = n;
	p = new int[length];
	for(m=0; m<j; m++){
		p[m] = a[m];
	}
	delete a;
}

int main(int argc, char argv[]){
	p = new int[length];
	p[0]=2;
	int m, n;
	int number=1;
	long long int sum = 2;
	for(m=2; m<B; m++){
		for(n=0; n<number && p[n]<sqrt(m); n++) if( !(m%p[n]) ) break;
		if(n==number||p[n]>=sqrt(m)){ 
			sum+=m; 
			p[number]=m;
			number++;
			if(number == length) addLength(length, length*2);
			
			std::cout << m << std::endl;
		}
	}
	delete p;
	std::cout << sum << std::endl;

	//142913828922-----------------------------------------------------¡Ì
	
	system("pause");
	return 0;
}