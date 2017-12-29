// Largest_prime_factor

/*The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?*/

#include <iostream>
using namespace std;

bool IsPrimeNUmber(long long int);

int main(int argc, char argv[]){

	const long long int N = 600851475143;
	
	cout << N << endl;

	long long int n;
	for(n=2; n < N/2+1; n++ ){
		if( N%n == 0){
			long long int b = N/n;
			if( IsPrimeNUmber(b) )
				cout << b << endl;
		}
	}

//  6857 ==================================================== ¡Ì

	system("pause");
	return 0;
}

bool IsPrimeNUmber(long long int n){
	long long int a = 1;
	for(a=2; a < n/2+1; a++){
		if( n%a == 0) return false;
	}
	return true;
}