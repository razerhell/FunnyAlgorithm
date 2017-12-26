'''
Coded triangle numbers
Problem 42 
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?


Answer:
162
Completed on Tue, 26 Dec 2017, 09:26
'''


file = open("p042_words.txt", "r")
data = file.read()
file.close()
import math

triangleNums = list(range(1, 20))

for c, value in enumerate(triangleNums, 1):
	triangleNums[c-1] = int(value * (value + 1) / 2)
triangleNums = set(triangleNums)
print(triangleNums)

numCount = 0
dataList = data.split(',')
print(len(dataList))
for s in dataList:
	ss = list(s)
	sumof = 0
	for c in ss:
		if c == '"':
			continue
		sumof += ord(c) - ord('A') + 1
	'''
	sumof *= 2
	num1 = int(math.sqrt(sumof))
	num2 = num1 + 1
	if num1 * num2 != sumof:
		continue
	'''
	if sumof not in triangleNums:
		continue
	numCount += 1

print("numCount: %d" % (numCount))