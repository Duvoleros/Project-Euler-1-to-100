def sum_of_proper_divisors(n):
    sum_divisors = 0
    for i in range(1, n):
        if n % i == 0:
            sum_divisors += i
    return sum_divisors

def is_abundant(n):
    return sum_of_proper_divisors(n) > n

def main():
    limit = 28123
    abundant_numbers = [n for n in range(1, limit + 1) if is_abundant(n)]

    abundant_sums = set()
    for i in range(len(abundant_numbers)):
        for j in range(i, len(abundant_numbers)):
            abundant_sums.add(abundant_numbers[i] + abundant_numbers[j])

    non_abundant_sums = [n for n in range(1, limit + 1) if n not in abundant_sums]

    total_sum = sum(non_abundant_sums)
    print("The sum is:", total_sum)

if __name__ == "__main__":
    main()
