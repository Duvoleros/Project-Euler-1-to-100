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

def check_prime(numb):
    index = 0
    sqrt = numb**0.5
    while(prime_numbers[index]<=sqrt):
        if(numb%prime_numbers[index]==0):
            return False
        index+=1
    return True

prime_numbers = []
rezult = 0
file = open("primes.txt", "r")
for i in file.readlines():
    temp = int(i)
    if(temp<10**5):
        prime_numbers.append(int(i))
print(len(prime_numbers))
number = ["1",'2','3','4','5','7','6']
while(True):
    temp = int("".join(number))
    if(temp%2==1 and temp%5!=0):
        if(check_prime(temp)):
            rezult = temp
            print("FINALLY FOUND",temp," !!!!!!!!!!!!!!!!")
        print(temp, rezult)
    number = next_permutation(number)
    if(number==['7','6','5','4','3','2','1']):
        break
print("REZULT ",rezult)
