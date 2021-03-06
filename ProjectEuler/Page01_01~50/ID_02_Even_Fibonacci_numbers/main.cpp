// Even_Fibonacci_numbers

/*Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

*/

#include <iostream>
using namespace std;

int main(int argc, char argv[]){
	
	int n1 = 1;
	int n2 = 2;
	int sum = 0;

	while( n2 <= 4000000 ){ //当n2不超过4000，000时，继续循环
		if( n2 % 2 == 0){
			sum += n2;
			cout << n2 << endl;//输出啊当前n2的值
		}
		n2 = n1 + n2;
		n1 = n2 - n1;
	}

	cout << "====================" << endl;

	cout << sum << endl;

// 4613732   ============================================ √

	system("pause");
	return 0;
}