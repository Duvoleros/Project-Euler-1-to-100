import math

def sqrt(x: int) -> int:
	assert x >= 0
	i: int = 1
	while i * i <= x:
		i *= 2
	y: int = 0
	while i > 0:
		if (y + i)**2 <= x:
			y += i
		i //= 2
	return y
sum = 0
for i in range(2, 100):
	if(i in [4,9,16,25,36,49,64,81]):
		continue
	tmp = sqrt(i*10**198)
	while(tmp>0):
		sum+=tmp%10
		tmp = tmp//10
print(sum)