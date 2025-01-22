from collections import Counter

def possible_palindrome(s: str) -> bool:
    flag = False
    alpha_only = ''.join(filter(str.isalpha, s.lower()))
    letters = Counter(alpha_only)
    for char in letters:
        if letters[char] % 2 != 0:
            flag = not flag
            if flag == False:
                return flag
    return True

result = possible_palindrome('bbbaaaaa')
print(result)