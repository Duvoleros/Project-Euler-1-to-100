def coin_change(n, coins):
    parts = [1]+[0]*n
    for c in coins:
        for i, x in enumerate(range(c, n+1)):
            parts[x] += parts[i]
    return parts

coins = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144}
for i, x in enumerate(coin_change(150, coins)):
    print(i, x)