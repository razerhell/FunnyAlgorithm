//A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
//
//a^2 + b^2 = c^2
//For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

#include <iostream>

int main(int argc, char argv[]){
	int m, n;
	for(m=0; m<1000; m++)
		for(n=m+1; n<1000-m-n; n++)
			if( (m*m+n*n) == ((1000-m-n)*(1000-m-n)) )
				std::cout << m * n * (1000-m-n) << std::endl;
	//31875000---------------------------------------------------------------------¡Ì
	system("pause");
	return 0;
}