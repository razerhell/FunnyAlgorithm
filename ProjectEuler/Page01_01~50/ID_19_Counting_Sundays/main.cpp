//You are given the following information, but you may prefer to do some research for yourself.
//
//1 Jan 1900 was a Monday.
//Thirty days has September,
//April, June and November.
//All the rest have thirty-one,
//Saving February alone,
//Which has twenty-eight, rain or shine.
//And on leap years, twenty-nine.
//A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
//How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <iostream>
#include <ctime>
using namespace std;

bool leap(int);

int main(){
	double t = clock();
	

	int year = 0;
	int month = 0;
	int day = 0;
	int mou[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int y = 0;
	int m = 0; 
	int d = 0;
	int w = 0;
	int s = 0;
	int md = 0;
	
	cout << "target" << endl;
	cin >> year >> month >> day;
	cout << "now" << endl;
	cin >> y >> m >> d;
	md = mou[m] + (m==2 ? leap(y) : 0);

	while(1){
		if(d>md){
			m++;
			if(m>12){
				y++;
				m=1;
			}
			md=mou[m];
			if(m==2) md+=leap(y);
			d=1;
		}
		if(y==year && m==month && d==day) break;
		d++;
		w++;
	}

	cout << s << endl;
	cout << w << endl;
	cout << clock() - t << "ms" << endl;
	//171--------------------------------------------------------------------¡Ì
	system("pause");
	return 0;
}

bool leap(int a){
	if(a%100 && !(a%4)) return true;
	else if( !(a%400) ) return true;
	else return false;
}