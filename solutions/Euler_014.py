def collatz_chain_length(n, chain_lengths):
    if n in chain_lengths:
        return chain_lengths[n]
    if n % 2 == 0:
        new_n = n // 2
    else:
        new_n = 3 * n + 1
    chain_lengths[n] = 1 + collatz_chain_length(new_n, chain_lengths)
    return chain_lengths[n]

def longest_collatz_chain(limit):
    chain_lengths = {1: 1}
    max_chain_length = 0
    max_chain_start = 0

    for i in range(1, limit):
        length = collatz_chain_length(i, chain_lengths)
        if length >= max_chain_length:
            max_chain_length = length
            max_chain_start = i
    return max_chain_start

limit = int(1e6)
starting_number = longest_collatz_chain(limit)
print(f"The starting number under {limit} that produces the longest Collatz chain is: {starting_number}")
