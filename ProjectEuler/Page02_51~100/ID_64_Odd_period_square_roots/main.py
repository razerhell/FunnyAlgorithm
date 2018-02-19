
'''
Odd period square roots
Problem 64

Answer:
1322
Completed on Mon, 19 Feb 2018, 12:11

solution:
https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Algorithm
'''
from math import sqrt
def getNext(sq:int, sub:int, deno:int, valueList:list, paramsList:list):
	newSub = deno * valueList[-1] - sub
	newDeno = int((sq - newSub * newSub) / deno)
	newValue = int((valueList[0] + newSub) / newDeno)

	try:
		isIn = paramsList.index((newSub, newDeno))
		return isIn
	except ValueError:
		valueList.append(newValue)
		paramsList.append((newSub, newDeno))
		return getNext(sq, newSub, newDeno, valueList, paramsList)



oddCount = 0
for i in range(1, 10001):
	vList = list()
	pList = list()
	tempS = sqrt(i)
	if tempS == int(tempS):
		continue
	tempS = int(tempS)
	vList.append(tempS)
	pList.append((0, 1))
	res = getNext(i, 0, 1, vList, pList)
	if (len(vList) - res) % 2 == 1:
		oddCount += 1
print(oddCount)

