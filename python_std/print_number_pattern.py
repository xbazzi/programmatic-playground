def print_number_pattern(n, m):
    i = sub_helper(n, m) + m
    add_helper(i, m, n)

def sub_helper(n, m):
    print(n)
    if (n < 0):
        return n
    return sub_helper(n - m, m)

def add_helper(n, m, k):
    if (n == k):
        print(n)
        return n
    print(n)
    return add_helper(n + m, m, k)

def main():
    print_number_pattern(12, 3)

if __name__ == "__main__":
    main()