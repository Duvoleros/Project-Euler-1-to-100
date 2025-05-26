def next_permutation(sequence):#taken from internet
	count = len(sequence)
	i = count
	while True:
		if i < 2:
			return False
		i -= 1
		if (sequence[i - 1] < sequence[i]):
			break
	j = count
	while j > i and not (sequence[i - 1] < sequence[j - 1]):
		j -= 1
	sequence[i - 1], sequence[j - 1] = sequence[j - 1], sequence[i - 1]
	j = count
	while i < j - 1:
		j -= 1
		sequence[i], sequence[j] = sequence[j], sequence[i]
		i += 1
	return sequence

counter = 1
number = ["0","1",'2','3','4','5','6','7','8','9']
while (counter<1000000):
    number = next_permutation(number)
    counter+=1
    
print(int("".join(number)))