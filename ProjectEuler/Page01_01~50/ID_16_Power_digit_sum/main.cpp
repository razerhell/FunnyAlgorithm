//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
//What is the sum of the digits of the number 2^1000?

#include <iostream>
#include <ctime>
using namespace std;

#define times 1000

int main(int argc, char argv[]){
	double t = clock();

	int num[times] = {0};
	num[0] = 1;
	int n, m;
	int temp = 0;
	int sum = 0;

	for(n=0; n<times; n++){
		for(m=0; m<times; m++){
			temp += num[m] * 2;
			num[m] = temp % 10;
			temp /= 10;
		}
	}

	for(n=0; n<times; n++){
		sum += num[n];
	}

	cout << sum << endl;
	cout << "ÏûºÄÊ±¼ä" << '\t' << clock() - t << "ms" << endl;
	//1366---------------------------------------------------------------------------------¡Ì
	system("pause");
	return 0;
}