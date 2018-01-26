'''
Poker hands
Problem 54

In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

High Card: Highest value card.
单张数字最大的牌

One Pair: Two cards of the same value.
一对数字一样的牌

Two Pairs: Two different pairs.
两对不同的牌

Three of a Kind: Three cards of the same value.
三张数字相同的牌

Straight: All cards are consecutive values.
所有的牌都连续（顺子


Flush: All cards of the same suit.
所有的牌花色相同（清一色

Full House: Three of a kind and a pair.
三张牌+一对

Four of a Kind: Four cards of the same value.
四张牌数字相同

Straight Flush: All cards are consecutive values of same suit.
同花顺

Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
带Ace的同花顺

牌序
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?


Answer:
376
Completed on Fri, 26 Jan 2018, 13:23


'''
valueDict = {'2' : 1, '3' : 2, '4' : 3, '5' : 4, '6' : 5, '7' : 6, '8' : 7, '9' : 8, 'T' : 9, 'J' : 10, 'Q' : 11, 'K' : 12, 'A' : 13, }
keyDict = {1 : '2', 2 : '3', 3 : '4', 4 : '5', 5 : '6', 6 : '7', 7 : '8', 8 : '9', 9 : 'T', 10 : 'J', 11 : 'Q', 12 : 'K', 13 : 'A', }

#牌组中数值最大牌
def highCard(cards):
	highValue = valueDict[cards[0][0]]
	vlist = set()
	for i in cards:
		v = valueDict[i[0]]
		vlist.add(v)
	vlist = list(vlist)
	vlist.sort()
	v = 0
	for i in vlist[::-1]:
		v *= 100
		v += i
	v /= 100 ** len(vlist)
	return v

#0比较大小值
def highCards(cards0, cards1):
	v0 = highCard(cards0)
	v1 = highCard(cards1)
	if v0 > v1:
		return 0
	if v1 > v0:
		return 1

#统计花色或数字数量
def countCards(cards, type):
	res = {}
	for i in cards:
		res[i[type]] = 0
	for i in cards:
		res[i[type]] += 1
	return res

#12367是否有指定张数的牌存在
def isNumsOne(cards, num):
	res = countCards(cards, 0)
	for k, v in res.items():
		if v != num:
			continue
		return k
	return None


#4是否是顺子
def isStraight(cards):
	valueList = []
	for i in cards:
		valueList.append(valueDict[i[0]])
	valueList.sort()
	n = len(valueList) - 1
	for i in range(n):
		if valueList[i + 1] - valueList[i] == 1:
			continue
		return None
	return keyDict[valueList[n]]

#5是否清一色
def isFlush(cards):
	res = countCards(cards, 1)
	if len(res) > 1:
		return None
	for i in res.keys():
		return i

#8是否同花顺
def isStraightFlush(cards):
	if isFlush(cards) == None:
		return None
	return isStraight(cards)

#9是否同花顺而且还有Ace
def isRoyalFlush(cards):
	return isStraightFlush(cards) == 'A'
file = open("p054_poker.txt", "r")

#为牌组打分
def valueOfCards(cards):
	#9同花顺Ace
	if isRoyalFlush(cards):
		return 913
	
	#8同花顺
	v = isStraightFlush(cards)
	if v != None:
		return 800 + highCard(cards)
	
	#7四张同样的牌
	v = isNumsOne(cards, 4)
	if v != None:
		return 700 + valueDict[v]

	#6三张+一对
	v = isNumsOne(cards, 3)
	if v != None:
		v1 = isNumsOne(cards, 2)
		if v1 != None:
			return 600 + valueDict[v]

	#5清一色
	v = isFlush(cards)
	if v != None:
		return 500 + highCard(cards)

	#4顺子
	v = isStraight(cards)
	if v != None:
		return 400 + highCard(cards)

	#3三张
	v = isNumsOne(cards, 3)
	if v != None:
		return 300 + valueDict[v]

	#2两对不同的
	count = 0
	countList = list()
	res = countCards(cards, 0)
	for k, v in res.items():
		if v != 2:
			continue
		count += 1
		countList.append(valueDict[k])
	if count == 2:
		countList.sort()
		return 200 + countList[1] + countList[0] / 100 + valueDict[isNumsOne(cards, 1)] / 10000

	#1一对不同的
	v = isNumsOne(cards, 2)
	if v != None:
		return 100 + valueDict[v] + highCard(cards) / 100
	
	#0只能比大小
	return highCard(cards)


#判断谁能嬴
def whoWin(cards0, cards1):
	return None


fileData = []
for line in file:
	line = line.split()
	single0 = line[:5]
	single1 = line[5:]
	single = []
	single.append(single0)
	single.append(single1)
	fileData.append(single)
file.close()

winCount = 0

for ri in fileData:
	single0 = ri[0]
	single1 = ri[1]
	#print("value: %d, %d" % (len(countCards(single0, 0)), len(countCards(single1, 0))))
	
	v0 = valueOfCards(single0)
	v1 = valueOfCards(single1)

	if v0 > v1:
		winCount += 1

print(winCount)