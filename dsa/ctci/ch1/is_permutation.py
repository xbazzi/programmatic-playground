from collections import Counter

def is_permutation(s1: str, s2: str) -> bool:
    if len(s1) != len(s2): return False
    
    letters = {}
    # Store s1 in dict
    for char in s1:
        char = char.lower()
        if char in letters:
            letters[char] = letters[char] + 1
        else:
            letters[char] = 1
    
    # Subtract frequency if s2 char in dict
    for char in s2:
        char = char.lower()
        if char not in letters or letters[char] == 0:
            return False
        else:
            letters[char] = letters[char] - 1
    return True

def is_permutation_v2(s1: str, s2: str) -> bool:
    if len(s1) != len(s2): return False
    if Counter(s1.lower()) != Counter(s2.lower()):
        return False
    return True

def main():
    s1 = "holaafasj"
    s2 = "hsfAajola"
    result = is_permutation(s1, s2)
    print(result)
    print(is_permutation_v2(s1, s2))

if __name__ == "__main__":
    main()