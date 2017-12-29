//If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
//
//NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 
//	  
//(one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

#include <iostream>
#include <ctime>
using namespace std;

#define hundred 7
#define thousand 8
#define and 3
#define mix 1000

int b[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 
				3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

int ten[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

int f(int);

int main(){
	double t = clock();

	int m;
	int sum = 0;
	for(m=1; m<=mix; m++){
		sum += f(m);
	}

	cout << sum << endl;
	cout << clock()-t << "ms" <<endl;
	//21124---------------------------------------------------------¡Ì
	system("pause");
	return 0;
}

int f(int a){
	if(a<20) return b[a];
	else if (a<100) return ten[a/10] + b[a%10];
	else if(a<1000) return f(a/100) + hundred + (a%100>0? (and + f(a%100)) : 0);
	else return f(a/1000) + thousand;
}