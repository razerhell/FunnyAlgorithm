//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//
//What is the 10 001st prime number?

#include <iostream>

int main(int argc,  char argv[]){
	int m;
	int n=1;
	int num=2;
	int a[10001] = {2, 0};
	while(n<10001){
		num++;
		for(m=0; m<n; m++)	if( !(num%a[m]))	break;
		if(m==n){
			a[n] = num;
			std::cout << num << std::endl;
			n++;
		}
	}

	//104743-------------------------------------------------------------¡Ì
	system("pause");
	return 0;
}