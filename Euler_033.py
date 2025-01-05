fractions = []
in_total = 1
for denum in range(21,100):
    for j in range (1,denum//10):
        num = j*10 + denum//10
        if(denum % 10 != 0):
            if((j/(denum % 10)== num/denum)):
                fractions.append((num, denum));
                in_total = in_total * denum / num;
# 4 curious fractions are:
# [(16, 64), (26, 65), (19, 95), (49, 98)]
print("Fractions are:",fractions)
print(f"Answer: {round(in_total)}")

