'''

Maximum path sum II
Problem 67 
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)


Answer:
7273
Completed on Fri, 23 Feb 2018, 14:23

分解子问题：
以当前节点为根的树最大值 = 当前节点值 + 两棵子树中的较大值

'''


f = open('p067_triangle.txt', 'r')

data = list()
for line in f.readlines():
	line = list(map(lambda x:int(x), line.split()))
	data.append(line)

data = data[::-1]
for i in range(1, len(data)):
	for j in range(len(data[i])):
		lastI = i - 1
		data[i][j] += max(data[lastI][j], data[lastI][j + 1])

print(data)