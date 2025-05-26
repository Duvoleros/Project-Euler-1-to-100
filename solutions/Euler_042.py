input = input().split(",")
words = []
for name in input:
    words.append(name[1:-1])
words.sort()
triangle = []
for i in range(1,80):
    triangle.append(i*(i+1)//2)
result = 0
for i in range(0,len(words)):
    summary = 0
    for g in range(0,len(words[i])):
        summary+=ord(words[i][g])-ord('A'[0])
    if(len(list(set([summary+len(words[i])]).intersection(triangle)))==1):
        result+=1
        print(i+1,words[i])
print(result)