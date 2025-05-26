till = 1500000

prime_numbers = []
f = open("primes.txt", "r")
for i in f.readlines():
    if(len(prime_numbers)<till):
        prime_numbers.append(int(i))


def get_d(h):
    # if(h in prime_numbers):
    #     return h*(2-(h==2))
    tmp = 2*h
    rez = 1 
    for i in prime_numbers:
        power = 0
        while(tmp%i==0):
            tmp = tmp//i
            power+=1
        rez*=i**(power//2)
        if(tmp == 1):
            break
    return rez


triples = dict()

for h in range(2,till):
    d = get_d(h)
    if(h+d> till/2):
        break
    for k in range(1,till):
        a = h+d*k
        b = d*k +(d*k)**2//(2*h)
        c = b+h
        if((a+b+c) <= till):
            if((a+b+c) in triples):
                triples[(a+b+c)]+=1
            else:
                triples[(a+b+c)]=1
        else:
            break
    if(h%500 == 0):
        print(h)
max = 0
for x in triples:
    #print(x, triples[x])
    if(triples[x] == 1):
        max+=1
print(max," answer ")
