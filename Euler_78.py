def partition(n):
    parts = [1]+[0]*n
    for num in range(1,n+1):
        print(num)
        for i, x in enumerate(range(num, n+1)):
            parts[x] += parts[i]
            parts[x] %= 10**6
    for i, x in enumerate(parts):
        if(x%10**6 == 0):
            print(i, x)        
    return parts[n]
# counter = 0
# parts = [1]
# while(True):
#     parts.append(0)
#     for i, x in enumerate(range(2, len(parts))):
#         parts[x] += parts[i]
#         parts[x] %= 10**7
#     print(len(parts),parts[-1])
#     if((parts[-1])%10**6 == 0 and parts[-1]>10**6):
#         break
print(partition(60000))