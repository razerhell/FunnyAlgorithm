/*
Non-abundant sums
Problem 23
A perfect number is a number for which the sum of its proper

divisors is exactly equal to the number.

For example, the sum of the proper divisors of 28 would 

be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is 

less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, 

the smallest number that can be written as the sum of two abundant 

numbers is 24. By mathematical analysis, it can be shown that all 

integers greater than 28123 can be written as the sum of two abundant 

numbers. However, this upper limit cannot be reduced any further by 

analysis even though it is known that the greatest number that cannot 

be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.


Answer:
4179871

*/

#include <iostream>
using namespace std;

#define SIZE 28123

int abundant[SIZE] = {0};
int as = 0;

int getDivisorSum(int n);
bool isSO2A(int n);

int main(int argc, char* argv[]){
	int sum = 0;
	int i;
	int ds = 0;
	int temp;
	int o=0;
	for(i=1; i<=SIZE; i++){
		ds = getDivisorSum(i);
		if( i < ds){
			abundant[as] = i;
			as++;
		}
		if(!isSO2A(i)){
			sum += i;
			cout << i << endl;
		}else{	
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}

int getDivisorSum(int n){
	int backn = n;
	int sum = 0;
	int divisor = 0;
	sum = 0;
	int s = sqrt(n)+1;
	sum -= n;
	if((s-1)*(s-1) == n) sum -= s-1;
	for(int i=1; i<s; i++){
		if( n%i == 0)
			sum += i + n/i;
	}

	//do{
	//	divisor = getSmallestDivisor(n);
	//	n /= divisor;
	//	sum += divisor;
	//}while(divisor != 1);

	return sum;
}

bool isSO2A(int n){
	int i;
	int j;
	int temp;
	for(i = 0; i<as; i++){
		for(j = i; j<as; j++){
			temp = n - abundant[i] - abundant[j];
			if( temp == 0) 
				return true;
		}
	}
	return false;
}
