def to_factor (num):
    numbers = []
    counter = 2
    while(num!=1):
        while(num % counter == 0):
            numbers.append(counter)
            num = num/counter
        counter+=1
    print(numbers)

to_factor(600851475143)
