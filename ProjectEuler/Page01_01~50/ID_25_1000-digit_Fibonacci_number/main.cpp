//1000-digit Fibonacci number
//Problem 25
//The Fibonacci sequence is defined by the recurrence relation:
//
//Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
//Hence the first 12 terms will be:
//
//F1 = 1
//F2 = 1
//F3 = 2
//F4 = 3
//F5 = 5
//F6 = 8
//F7 = 13
//F8 = 21
//F9 = 34
//F10 = 55
//F11 = 89
//F12 = 144
//The 12th term, F12, is the first term to contain three digits.
//
//What is the first term in the Fibonacci sequence to contain 1000 digits?
//
//4782
//
#include <iostream>
using namespace std;

#define SIZE 1000

void plusDigitAdd(int** n, bool flag);
int showDigit(int* digit);
void showNumber(int* number);

int main(){

	bool flag = false;
	int** number = new int*[2];
	int sum = 3;
	int digit = 1;
	int temp;

	//分配内存空间赋初值
	number[0] = new int[SIZE];
	memset(number[0], 0, sizeof(int)*SIZE);
	number[0][0] = 1;
	number[1] = new int[SIZE];
	memset(number[1], 0, sizeof(int)*SIZE);
	number[1][0] = 1;
	
	while(!number[!flag][SIZE-1]){
		plusDigitAdd(number, flag);
		temp = showDigit(number[flag]);


		//cout << sum << '\t' << temp << '\t';
		//showNumber(number[flag]);
		//cout << endl;

		if(temp != digit){
			digit = temp;
			cout << sum << '\t' << digit << endl;
		}
		
		flag = !flag;
		sum ++;
	}

	system("pause");
	return 0;
}

void plusDigitAdd(int** n, bool flag){
	int i=0;
	int carry=0;
	int f = showDigit(n[!flag]);
	while( i <=f ||  carry ){

		n[flag][i] += n[!flag][i] + carry;
		carry = n[flag][i]/10;
		n[flag][i] = n[flag][i]%10;
		i++;
		if(i == SIZE){
			break;
		}
	}
}


void showNumber(int* number){

	int i=SIZE-1;
	while( !number[i]){
		i--;
	}

	for(; i>=0; i--){
		cout << number[i];
	}
}


int showDigit(int* digit){
	int i=SIZE-1;
	while(!digit[i]){
		i--;
	}
	return i+1;
}