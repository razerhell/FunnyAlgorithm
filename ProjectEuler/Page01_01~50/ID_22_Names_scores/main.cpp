/*
Names scores
Problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 �� 53 = 49714.

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

	srand((int)time(NULL));//�����ʱ������

	//Ԥ��ȡ�ļ�
	ifstream data("names.txt");
	if( !data ){
		cout << "Loading Error..." << endl;
	system("pause");
	return 0;
	}

	int *name = new int[ROW];
	long long int TotalNameScores = 0;//����һ���������ڼ�¼�ܷ���
	int i, j;//���ڸ���ѭ���ĸ�������
	char tempChar;//����һ��������Ϊ�ļ��������������תվ
	bool isName = false;//����һ����������ȷ����ǰ������ַ��Ƿ�����Ч�ַ�(��ʼ��Ϊ��)
	bool isQuote = false;//����һ��������ŵ�ǰ�ַ��Ƿ�Ϊ����״̬
	list<Name> nameList;
	list<Name>::iterator nameIterator;
	Name* temp;

	i=-1;//i��ʼ��Ϊ��һ���Ѿ���������ֵĴ��λ��
	int theNumberOfName = 0;//the number of name
	//��ȡ�ļ��е��������ֶ�ȡ��name�б���
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
	data.close();//�ر��ļ�������

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