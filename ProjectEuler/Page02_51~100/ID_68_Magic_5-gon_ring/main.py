'''

>> from itertools import combinations, permutations
>> permutations([1, 2, 3], 2)
<itertools.permutations at 0x7febfd880fc0>
>> list(permutations([1, 2, 3], 2))
[(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]

>> list(combinations([1, 2, 3], 2))
[(1, 2), (1, 3), (2, 3)]

2951051817673439
2594936378711015
2594936378711015
2951051817673439
2594936378711015
6531031914842725
2951051817673439
6357528249411013
6357528249411013
6531031914842725
2594936378711015
6357528249411013
6531031914842725
2951051817673439
6357528249411013
6531031914842725
2951051817673439
6531031914842725
2594936378711015
6357528249411013

6531031914842725

Answer:
6531031914842725
Completed on Tue, 6 Mar 2018, 15:44

'''

from itertools import permutations

#print(len(list(permutations([i for i in range(1, 11)], 10))))

# 前五位做外环，后五位做内环

base = [i for i in range(1, 11)]
l = len(base)

def listToCricle(outC:list, inC:list):
	res = list()
	ind = [i for i in range(5)][::-1]
	for i in ind:
		t = (outC[i], inC[i], inC[i-1])
		res.append(t)
	return res
	
def isMagic(circle:list):
	sumList = list(map(lambda x:sum(x), circle))
	ind = [i for i in range(5)][::-1]
	for i in ind:
		if sumList[i] == sumList[i-1]:
			continue
		return False
	return True
	
def adjustSequence(circle:list):
	minHead = circle[0][0]
	minHeadI = 0
	
	for i in range(1, 5):
		if circle[i][0] > minHead:
			continue
		minHead = circle[i][0]
		minHeadI = i
	
	return circle[minHeadI:] + circle[:minHeadI]

def circleToStr(circle:list):
	l = list()
	for i in circle:
		l += list(i)
	l = list(map(lambda x:str(x), l))
	return ''.join(l)
	
maxStr = 0
for i in permutations(base, 10):
	outCircle = list(i[0:5])
	inCircle = list(i[5:10])
	res = listToCricle(outCircle, inCircle)
	if not isMagic(res):
		continue
		
	seres = adjustSequence(res)	
	
	resStr = circleToStr(seres)
	if len(resStr) > 16:
		continue
	resInt = int(resStr)
	if resInt > maxStr:
		maxStr = resInt
	
	print(resInt)

print()
print(maxStr)