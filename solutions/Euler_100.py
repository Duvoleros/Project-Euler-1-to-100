r = 6
b = 15
while(r+b<10**12):
    r = 2*b + r-1
    b = b + 2*r
print(b)