f1 = 1
f2 = 1
index = 2
while(len(str(f2))<1000):
    index+=1
    f1, f2 = f2, f1
    f2 = f1+f2
print (index)