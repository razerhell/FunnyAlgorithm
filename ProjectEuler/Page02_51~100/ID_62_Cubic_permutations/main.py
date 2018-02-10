'''
Cubic permutations
Problem 62 
The cube, 41063625 (3453), can be permuted to produce two other cubes: 56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.


Answer:
127035954683
Completed on Sat, 10 Feb 2018, 13:33

'''
def numToStr(num:int):
	res = list(str(num))
	res.sort()

	return ''.join(res)


DICT = dict()
MAX_POWER = 4


for i in range(10 ** (MAX_POWER - 1), 10 ** MAX_POWER):
	i = i * i * i
	iStr = numToStr(i)
	value = None
	try:
		DICT[iStr] += (i, )
	except KeyError:
		DICT[iStr] = (i, )

for key, value in DICT.items():
	if len(value) >= 5:
		print(key[0])
		print(value)
		print()