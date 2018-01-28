'''

Powerful digit sum
Problem 56 
A googol (10100) is a massive number: one followed by one-hundred zeros; 100 ** 100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a ** b, where a, b < 100, what is the maximum digital sum?

Answer:
972
Completed on Sun, 28 Jan 2018, 11:20

'''

def numberToList(num):
	res = list()
	while num != 0:
		n = num % 10
		num /= 10
		print("%d, %d" % (num, int(num)))
		num = int(num)
		res.append(n)

	return res

BASE_MAX = 100
POWER_MAX = 100
digitSum_max = 0

for i in range(BASE_MAX + 1):
	for j in range(POWER_MAX + 1):
		tempSum = sum(list(map(lambda x : ord(x) - ord('0'), list(str(i ** j)))))
		if tempSum >= digitSum_max:
			print(tempSum)
			digitSum_max = tempSum
