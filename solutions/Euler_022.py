names = input().split(",")
names2 = []
for name in names:
    names2.append(name[1:-1])
names2.sort()
result = 0
for i in range(0,len(names2)):
    summary = 0
    for g in range(0,len(names2[i])):
        summary+=ord(names2[i][g])-ord('A'[0])
    result+=(summary+len(names2[i]))*(i+1)
    print(i+1,names2[i], summary+len(names2[i]))
print(result)