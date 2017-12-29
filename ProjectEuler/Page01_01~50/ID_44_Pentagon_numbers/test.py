def nToPentagonNumbers(num):
	return int( ( 3 * num * num - num) / 2 )

num2395 = nToPentagonNumbers(2395)
num1020 = nToPentagonNumbers(1020)
num2167 = nToPentagonNumbers(2167)
num1912 = nToPentagonNumbers(1912)

print(num2395)
print(num1020)
print(num2167)
print(num1912)
print()
print(num2395 - num1020)
print(num2395 - num2167)