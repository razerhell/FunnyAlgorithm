//finished
#include <iostream>
#include <vector>
using namespace std;

void f(vector<int>& v, int number)
{
	v.push_back(number);
	if (number == 1) return;
	if (number % 2 == 0)	
		f(v, number / 2);
	else
	{
		v.push_back((number + 1) / 2);
		f(v, (number - 1) / 2);
	}
}

int showVector(const vector <int>& v)
{
	int sum = 0;
	vector<int>::const_iterator ite;
	for (ite = v.begin(); ite != v.end(); ++ite)
	{
		sum += *ite;
		cout << *ite << ' ';
	}
	cout << endl << sum << endl;
	return sum;
}

int main(int argc, char * argv[])
{
	
	int n;
	vector <int> vec;

	cin >> n;
	f(vec, n);
	int sum = showVector(vec);

	system("pause");
	return 0;
}
