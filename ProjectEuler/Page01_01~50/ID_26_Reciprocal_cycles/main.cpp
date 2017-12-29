//reciprocal cycles
//problem 26
//a unit fraction contains 1 in the numerator. the decimal representation of the unit fractions with denominators 2 to 10 are given:
//
//1/2	= 	0.5
//1/3	= 	0.(3)
//1/4	= 	0.25
//1/5	= 	0.2
//1/6	= 	0.1(6)
//1/7	= 	0.(142857)
//1/8	= 	0.125
//1/9	= 	0.(1)
//1/10	= 	0.1
//where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. it can be seen that 1/7 has a 6-digit recurring cycle.
//
//find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

//983


#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

#define MAX_D 1000

int temp[MAX_D+1];
int getCycle(int d);
int check(int i, int d);

int main(){
	int t=clock();
	int i;
	int max = 0;
	int temp = 0;
	for(i = 0; i<1000; i++){
		temp = getCycle(i);
		if(temp >= max){
			max = temp;
			printf("%d\t:%d\n", i, max);
		}
	}
	t = clock() - t;
	printf("time:%d\n", t);
	system("pause");
	return 0;
}

int getCycle(int d){
	memset(temp, 1, sizeof(int) * d);
	int i=0;
	int t=1;
	int te;
	while(i<d){
		te = t/d;
		//printf("%d", te);
		t -=  te * d;
		if(check(i, t)) break;
		t *= 10;
		i++;
	}
	return i;
}

int check(int i, int d){
	int j, k, l;
	for(j=0; j<i; j++){
		if(d == temp[j]) return 1;
	}
	temp[i] = d;
	return 0;
}
