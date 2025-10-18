text1 = input()
text2 = input()
text3 = input()

alfabet = [0] * 26

for i in range(len(text1)):
    alfabet[ord(text1[i]) - ord('A')] += 1

for i in text2:
    alfabet[ord(i) - ord('A')] += 1

for i in text3:
    alfabet[ord(i) - ord('A')] -= 1

for i in alfabet:
    if i != 0:
        print("NO")
        break
else:
    print("YES")