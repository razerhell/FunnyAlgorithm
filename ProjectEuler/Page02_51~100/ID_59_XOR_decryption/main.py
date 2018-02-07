
'''
XOR decryption
Problem 59 
Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.


Answer:
107359
Completed on Wed, 7 Feb 2018, 10:09

Key: got
Original Text:
(The Gospel of John, chapter 1) 
1 In the beginning the Word already existed. He was with God, and he was God. 
2 He was in the beginning with God. 
3 He created everything there is. Nothing exists that he didn't make. 
4 Life itself was in him, and this life gives light to everyone. 
5 The light shines through the darkness, and the darkness can never extinguish it. 
6 God sent John the Baptist 
7 to tell everyone about the light so that everyone might believe because of his testimony. 
8 John himself was not the light; he was only a witness to the light. 
9 The one who is the true light, who gives light to everyone, was going to come into the world. 
10 But although the world was made through him, the world didn't recognize him when he came. 
11 Even in his own land and among his own people, he was not accepted. 
12 But to all who believed him and accepted him, he gave the right to become children of God. 
13 They are reborn! This is not a physical birth resulting from human passion or plan, 
	this rebirth comes from God.14 So the Word became human and lived here on earth among us. 
	He was full of unfailing love and faithfulness. And we have seen his glory, 
	the glory of the only Son of the Father.

'''
def generateList(dic:list, l:list, currN:int, maxN:int):
	#若已达到遍历上限则进行返回
	if currN >= maxN :
		dic.append(list(l))
		return

	#递归增加尾数
	for i in range(ord('a'), ord('z') + 1):
		l.append(i)
		generateList(dic, l, currN + 1, maxN)
		l.pop()

def decode(key:list, message:list):
	messageLength = len(message)
	i = 0
	res = list()
	keys = list()

	while len(keys) < messageLength:
		keys += key
	while i < messageLength:	
		ibk = i
		i += 1
		res.append(int(message[ibk]) ^ keys[ibk])
	return res
		
#生成密文字典
keyDic = list()
singleKey = list()
generateList(keyDic, singleKey, 0, 3)

#读入文件
f = open("p059_cipher.txt", 'r')
fdata = f.read()
f.close()
fdata = fdata.strip('\n')
message = fdata.split(',')
message = list(map(lambda x:int(x), message))

#读入英文单词
f = open("words.txt", 'r')
words = list()
while True:
	line = f.readline().strip('\n')
	if not line:
		break
	words.append(line)

#遍历解密
for key in keyDic:
	resAscii = decode(key, message)
	res = ''.join(list(map(lambda x:chr(x), resAscii)))
	isIn = False
	for word in words:
		if len(word) <= 4:
			continue

		findRes = res.find(word)
		if findRes >= 0:
			isIn = True
			print(''.join(list(map(lambda x:chr(x), key))))
			print(word)
			print(findRes)
			print(res)
			print(sum(resAscii))
			print()
			#input()
			break
	if not isIn:
		continue

'''
	print(key)
	print(res)
	print()
'''