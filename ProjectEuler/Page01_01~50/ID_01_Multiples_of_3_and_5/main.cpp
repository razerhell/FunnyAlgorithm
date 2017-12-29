//Multiples_of_3_and_5

/*If we list all the natural numbers below 10 that are 

multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.*/

#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	
	int n;
	int sum = 0;

	for(n=3; n<1000; n++){
		if( !(n%3) || !(n%5) ) sum += n;
	}

	cout << sum << endl;

//   233168    ====================================================== ¡Ì

	system("pause");
	return 0;
}