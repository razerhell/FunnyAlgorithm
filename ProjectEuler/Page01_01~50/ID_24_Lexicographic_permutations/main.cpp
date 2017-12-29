/*
A permutation is an ordered arrangement of objects. 

For example, 3124 is one possible permutation of the 

digits 1, 2, 3 and 4. If all of the permutations are 

listed numerically or alphabetically, we call it 

lexicographic order. The lexicographic permutations

of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

2783915460

*/

#include <iostream>
using namespace std;

#define SIZE 10

int** permutation;
int index = 0;
int* number = new int[SIZE];
int SUM = 0;

int pToInt(int *p);
void findPermutation(int* p);
void insertPermutation(int* p);
void showP(int *p);

int main(){

	//计算将会产生的排列组合的规模
	int s = 1;
	for(int i=1; i<=SIZE; i++){
		s *= i;
	}
	permutation = new int*[s];
	for(int i=0; i<s; i++){
		permutation[i] = new int[SIZE];
	}

	//将用于存储数字的数组初始化
	for(int i=0; i<SIZE; i++){
		number[i] = SIZE;
	}

	findPermutation(number);
	
	cout << s << endl;

	showP(permutation[999999]);


	system("pause");
	return 0;
}


int pToInt(int *p){//将数组转化为数字
	int sum = 0;
	for(int i=0; i<SIZE; i++){
		sum *= 10;
		sum += p[i];
	}
	return sum;
}

void findPermutation(int* p){
	//立flag
	bool* flag = new bool[SIZE];
	memset(flag, false, sizeof(bool)*SIZE);

	int n = 0;//已被使用过的数字
	for(int i=0; i<SIZE; i++){//标记已被使用过的数字为true
		if(p[i] < SIZE){
			flag[p[i]] = true;
			n++;
		}
	}

	if( n==SIZE ){
		insertPermutation(p);
		return;
	}

	for(int i=0; i<SIZE; i ++){
		if(flag[i]){

		}
		if(!flag[i]){
			p[n] = i;
			findPermutation(p);
			p[n] = SIZE;
		}
	}

}


void insertPermutation(int* p){
	int r =  pToInt(p);
	for(int i=0; i<SIZE; i++){
		permutation[SUM][i] = p[i];	
	}
	SUM++;
	if( SUM%10000 == 0){
		cout << SUM << endl;
	}
}


void showP(int *p){
	for(int i=0; i<SIZE; i++){
		cout << p[i];
	}
	cout << endl;
}