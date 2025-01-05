

factorials = [1]
for i in range(1,10):
    factorials.append(factorials[-1]*i)

def transform(num):
    rez = 0
    while(num>0):
        rez+=factorials[num%10]
        num = num // 10
    return rez



def take_value(n, cache={}):
    if n in cache:
        return n

    chain=set([n])

    fs = transform(n)
    while (fs not in chain) and (fs not in cache):
        chain.add(fs)
        fs = transform(fs)

    chainlen = len(chain)
    if fs in cache:
        chainlen += cache[fs]

    cache[n] = chainlen

    return cache[n]

count = 0
for i in range(0, 1000000):
    if take_value(i) == 60:
        count += 1

print (count)

# count = 0
# for i in range(3,10**6+1):
#     if(take_value(i)==60):
#         count+=1
#         print(i, count, "FOUND!!")
#     if(i%100 == 0):
#         print(i)
# count