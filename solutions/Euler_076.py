def partition(n):
    parts = [1]+[0]*n
    for num in range(1,n+1):
        for i, x in enumerate(range(num, n+1)):
            parts[x] += parts[i]
    return parts[n]
print(partition(100)-1)