def isPowerOfTwo(n: int) -> bool:
   
    if n == 1:  #base case
        return True

    # If n is less than 1 or not divisible by 2, it cannot be a power of two
    if n <= 0 or n % 2 != 0:
        return False

    #recursion application
    return isPowerOfTwo(n // 2)

def main():   # main function
    test_cases = [1, 16, 3]
    for n in test_cases:
        result = isPowerOfTwo(n)
        print(f"Is {n} a power of two? {result}")
if __name__ == "__main__":
    main()

