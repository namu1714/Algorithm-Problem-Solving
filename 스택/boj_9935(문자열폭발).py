str = input()
pok = input()
pokLastChar = pok[-1]
stack = []
length = len(pok)

for s in str:
	stack.append(s)
	if s == pokLastChar:
		if ''.join(stack[-length:]) == pok:
			del stack[-length:]

if ''.join(stack) == '':
	print("FRULA")
else:
	print(''.join(stack))