denum_limit = 1000

max_cycle_length = 0
max_denum = 0

for denum in range(2, denum_limit):
    if denum % 2 == 0 or denum % 5 == 0:
        continue

    rems = {}
    rem = 1 % denum
    pos = 0

    while rem not in rems and rem != 0:
        rems[rem] = pos
        rem = (rem * 10) % denum
        pos += 1

    if rem != 0:
        cycle_length = pos - rems[rem]
        if cycle_length > max_cycle_length:
            max_cycle_length = cycle_length
            max_denum = denum

print(f"The value of d < {denum_limit} with the longest recurring cycle ({max_cycle_length}) is: {max_denum}")
