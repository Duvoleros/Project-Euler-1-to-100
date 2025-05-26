def roman_to_arabic(roman_num):
    arabic_num = 0
    roman_numerals = {
        'M': 1000, 'CM': 900, 'D': 500, 'CD': 400,
        'C': 100, 'XC': 90, 'L': 50, 'XL': 40,
        'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1
    }
    i = 0
    while i < len(roman_num):
        if i + 1 < len(roman_num) and roman_num[i:i+2] in roman_numerals:
            arabic_num += roman_numerals[roman_num[i:i+2]]
            i += 2
        else:
            arabic_num += roman_numerals[roman_num[i]]
            i += 1
    return arabic_num

def arabic_to_roman(arabic_num):
    values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbols = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
    roman_num = ''
    for i in range(len(values)):
        while arabic_num >= values[i]:
            roman_num += symbols[i]
            arabic_num -= values[i]
    return roman_num

# We don't need to use these functions, as we already know all cases to minimize.
# We need just to hardcode them.


def main():
    optimizations = {'VIIII': 1, 'IIII': 2, 'XXXX': 2, 'LXXXX': 1, 'CCCC': 2, 'DCCCC': 1}
    delta = 0
    sfile = open("89_roman.txt", "r")
    for i in sfile.readlines():
        for k in optimizations:
            if(k in i):
                delta += optimizations[k]
    print(f"Answer: {delta}")


if __name__ == "__main__":
    main()
