'''
Consider quadratic Diophantine equations of the form:

x2 – Dy2 = 1

For example, when D=13, the minimal solution in x is 6492 – 13×1802 = 1.

It can be assumed that there are no solutions in positive integers when D is square.

By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

32 – 2×22 = 1
22 – 3×12 = 1
92 – 5×42 = 1
52 – 6×22 = 1
82 – 7×32 = 1

Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.


Answer:
661
Completed on Thu, 22 Feb 2018, 15:40


2:(3, 2)
5:(9, 4)
10:(19, 6)
13:(649, 180)
29:(9801, 1820)
46:(24335, 3588)
53:(66249, 9100)
61:(1766319049, 226153980)
109:(158070671986249, 15140424455100)
181:(2469645423824185801, 183567298683461940)
277:(159150073798980475849, 9562401173878027020)
397:(838721786045180184649, 42094239791738433660)
409:(25052977273092427986049, 1238789998647218582160)
421:(3879474045914926879468217167061449, 189073995951839020880499780706260)
541:(3707453360023867028800645599667005001, 159395869721270110077187138775196900)
661:(16421658242965910275055840472270471049, 638728478116949861246791167518480580)

佩尔方程
https://zh.wikipedia.org/wiki/%E4%BD%A9%E5%B0%94%E6%96%B9%E7%A8%8B



'''



maxMinXD = 0
maxMinX = 0

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

def getOut(valueList:list):
	resList = list()
	for i in range(len(valueList)):
		currDenomilator = 0
		currMolecular = 1
		for j in valueList[::-1][i::]:
			currMolecular, currDenomilator = currDenomilator, currMolecular
			currMolecular += j * currDenomilator
		resList.append((currMolecular, currDenomilator))
	return resList[::-1]

for d in range (2, 1001):
	vList = list()
	pList = list()
	tempS = sqrt(d)
	if tempS == int(tempS):
		continue
	tempS = int(tempS)
	vList.append(tempS)
	pList.append((0, 1))
	pos = getNext(d, 0, 1, vList, pList)
	isFind = False
	while not isFind:
		vList += vList[pos:]
		res = getOut(vList)
		for j in res:
			x = j[0]
			y = j[1]

			if x * x - d * y * y != 1:
				continue
			
			isFind = True

			if x <= maxMinX:
				break
			
			maxMinX = x
			maxMinXD = d
			print("%d:" % (d, ), end = '')
			print((x, y))
			break

print(maxMinXD)