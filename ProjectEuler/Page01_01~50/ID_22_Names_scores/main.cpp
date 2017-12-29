/*
Names scores
Problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?


Answer:
871198282
Completed on Tue, 11 Nov 2014, 14:22
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <list>
#include "Name.h"
using namespace std;

#define ROW 6000
#define COL 20

bool compareName( Name &lhs, Name &rhs);

int main(){

	srand((int)time(NULL));//随机数时间做种

	//预读取文件
	ifstream data("names.txt");
	if( !data ){
		cout << "Loading Error..." << endl;
	system("pause");
	return 0;
	}

	int *name = new int[ROW];
	long long int TotalNameScores = 0;//定义一个变量用于记录总分数
	int i, j;//用于辅助循环的辅助变量
	char tempChar;//定义一个变量作为文件流对象输出的中转站
	bool isName = false;//定义一个变量用于确定当前读入的字符是否是有效字符(初始化为否)
	bool isQuote = false;//定义一个变量存放当前字符是否为引号状态
	list<Name> nameList;
	list<Name>::iterator nameIterator;
	Name* temp;

	i=-1;//i初始化为上一个已经读完的名字的存放位置
	int theNumberOfName = 0;//the number of name
	//读取文件中的所有名字读取到name列表中
	while (!data.eof())
	{
		data >> tempChar;
		isQuote = tempChar == '\"';
		switch ( (isQuote << 1) + isName )
		{
		case 0: 
			break;
		case 1:
			name[j] = tempChar - 'A' +1;
			j++;
			break;
		case 2:
			i++;
			j = 0;
			isName = true;
			break;
		case 3:
			name[j] = '\0';
			isName = false;
			temp = new Name(name);
			nameList.push_back(*temp);
			break;
		default:
			break;
		}
	}
	data.close();//关闭文件流对象

	nameList.sort(compareName);

	

	for(nameIterator = nameList.begin(), i = 1; nameIterator != nameList.end();  nameIterator++, i++){
		//nameIterator->showName();
		TotalNameScores += nameIterator->value() * i;
	}

	cout << endl <<  TotalNameScores << endl;

	system("pause");
	return 0;
}


bool compareName( Name &lhs, Name &rhs)
{
	return lhs < rhs;
}