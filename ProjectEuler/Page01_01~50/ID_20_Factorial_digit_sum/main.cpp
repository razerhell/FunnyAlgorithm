//n! means n  (n  1)  ...  3  2  1
//
//For example, 10! = 10  9  ...  3  2  1 = 3628800,
//and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
//Find the sum of the digits in the number 100!

#include <iostream>
#include <ctime>
using namespace std;

#define number 100

int mul[2 * number] = {1};

void f(int);

int main(){
	double t = clock();

	int sum = 0;
	int m = number + 1;
	while( --m ) f(m);

	for(m=0; m< 2*number; m++) sum+= mul[m];

	cout << sum << endl;

	cout << clock() - t << "ms" << endl;

	//648-----------------------------------------------------------¡Ì
	system("pause");
	return 0;
}

void f(int n){
	int m;
	int l = 2 * number;
	int temp = 0;

	while( !mul[l-1] ) l--;

	for(m=0; (m< l)  || temp; m++){
		temp += mul[m] * n;
		mul[m] = temp%10;
		temp /= 10;
	}

}