triangular = []
pentagonal = []
hexagonal = []
for i in range(0,100000):
    triangular.append(i*(i+1)//2)
    pentagonal.append(i*(3*i-1)//2)
    hexagonal.append(i*(2*i-1))
print(list(set(hexagonal).intersection(pentagonal).intersection(triangular)))