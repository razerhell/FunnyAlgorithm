//Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
//If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//
//For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
//
//The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
//Evaluate the sum of all the amicable numbers under 10000.

#include <iostream>
#include <ctime>
using namespace std;

#define target (10000+1)

int number[target];
int sumOfPrime(int);
void jadge(int);

int main(){
	double t = clock();
	int m;
	int n;
	int sum = 0;

	for(n=3; n<target; n++) number[n]=1;

	for(m=3; m<target; m++){
		if( number[m] != 1 ) continue;
		jadge(m);
	}
	for(n=1; n<target; n++) if(number[n]==2) sum+= n;
	cout << sum << endl;
	cout << clock() - t << "ms" << endl;

	//31626-------------------------------------------------------¡Ì
	system("pause");
	return 0;
}

int sumOfPrime(int m){
	int sum = 1;
	int sq;
	int n;
	sq = sqrt(m);
	for(n=2; n<=sq; n++){
		if( !(m%n) ) sum += (n + (int)(m/n) );
	}
	if( (n-1)*(n-1) == m) sum-=(n-1);
	return sum;
}

void jadge(int m){
	int sum;
	sum = sumOfPrime(m);
	if(sum == 1 || sum==m){
		number[m]=0;
	}else{
		if(m == sumOfPrime(sum)){
			cout  << m << '\t' << sum << endl;
			number[m]=2;
			if(sum<target)	number[sum]=2;
		}else{
			number[m]=0;
		}
	}
}