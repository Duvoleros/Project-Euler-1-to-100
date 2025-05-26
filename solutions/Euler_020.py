rez = 1
for i in range(1,101):
    rez*=i
digits =0 
while(rez!=0):
    digits+=rez%10
    rez = rez//10
digits