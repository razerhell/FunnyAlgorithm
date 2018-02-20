'''
Convergents of e
Problem 65

Hence the sequence of the first ten convergents for √2 are:

1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...
What is most surprising is that the important mathematical constant,
e = [2; 1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...].

The first ten terms in the sequence of convergents for e are:

2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.

Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.


Answer:
272
Completed on Tue, 20 Feb 2018, 09:37


6963524437876961749120273824619538346438023188214475670667
——————————
2561737478789858711161539537921323010415623148113041714756
'''

l = [2, 1, 2, 1, 1, 4, 1, 1, 6, 1, 1, 8, 1, 1, 10, 1, 1, 12, 1, 1, 14, 1, 1, 16, 1, 1, 18, 1, 1, 20, 1, 1, 22, 1, 1, 24, 1, 1, 26, 1, 1, 28, 1, 1, 30, 1, 1, 32, 1, 1, 34, 1, 1, 36, 1, 1, 38, 1, 1, 40, 1, 1, 42, 1, 1, 44, 1, 1, 46, 1, 1, 48, 1, 1, 50, 1, 1, 52, 1, 1, 54, 1, 1, 56, 1, 1, 58, 1, 1, 60, 1, 1, 62, 1, 1, 64, 1, 1, 66, 1, 1, 68]
l = l[0:100][::-1]

currDenomilator = 0
currMolecular = 1

for i in l:
	currMolecular, currDenomilator = currDenomilator, currMolecular
	currMolecular += i * currDenomilator

print(currMolecular)
print('——————————')
print(currDenomilator)	
print()
print(sum(list(map(lambda x:int(x), list(str(currMolecular))))))