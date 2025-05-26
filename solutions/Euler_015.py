dp = []
for i in range(0,21):
    dp.append([])
    for j in range(0,21):
        if(i==0 or j==0):
            dp[i].append(1)
        else:
            dp[i].append(dp[i-1][j] + dp[i][j-1])
print(dp[-1][-1])
