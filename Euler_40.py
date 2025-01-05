string = ""
for i in range(0,300000):
    string = string + str(i)
answer = 1
delta = 1
while(delta<=10**6):
    print(delta,string[delta])
    answer*=int(string[delta])
    delta*=10
answer