//Lattice paths
//Problem 15
//Starting in the top left corner of a 22 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//
//
//How many such routes are there through a 2020 grid

#include <iostream>
#include <ctime>
using namespace std;

#define size 20
long long int plan[size+2][size+2] = {0};

int main(int argc, char argv[]){
	double t = clock();
	
	int col, row;
	plan[size][size+1] = 1;
	for(col=size; col>=0; col--)
		for(row=size; row>=0; row--){
			plan[row][col] = plan[row+1][col] + plan[row][col+1];
		}
	cout << size << "X" << size << ":" <<endl;
	cout << "路径种数\t" << plan[0][0] << endl;
	cout << "花费时间\t" << clock() - t << "ms" << endl;
	//137846528820---------------------------------------------------------------√
	system("pause");
	return 0;
}