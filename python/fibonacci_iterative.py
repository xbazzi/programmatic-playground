def fibonacci(n: int) -> int:
    if n <= 1:
        return n
    prev = 0
    curr = 1
    # while (curr < n):
    for _ in range(2, n + 1):
        next = curr + prev
        prev = curr
        curr = next
    return curr

def main():
    print(fibonacci(10000))

if __name__ == "__main__":
    main()
