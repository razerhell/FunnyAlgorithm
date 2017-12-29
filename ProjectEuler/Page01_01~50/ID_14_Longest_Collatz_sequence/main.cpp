//The following iterative sequence is defined for the set of positive integers:
//
//n  n/2 (n is even)
//n  3n + 1 (n is odd)
//
//Using the rule above and starting with 13, we generate the following sequence:
//
//13  40  20  10  5  16  8  4  2  1
//It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//
//Which starting number, under one million, produces the longest chain?
//
//NOTE: Once the chain starts the terms are allowed to go above one million.

#include <iostream>
using namespace std;

#define Caps 1000000
long long int start = 0;
long long int times = 0;

long long int f(long long int);

int main(long long int argc, char crgv[]){
	
	long long int n;
	long long int m;

	for(n=999168; n>0; n--){
		m = f(n);
		if(m>times){
			times = m;
			start = n;
			cout << m << '\t' << n << endl;
		}
	}
	//837799----------------------------------------------------------------------¡Ì
	system("pause");
	return 0;
}

long long int f(long long int a){
	if(a == 1) return 0;
	else{
		if(a%2) return f(3*a+1) + 1;
		else return f(a/2) + 1;
	}
}