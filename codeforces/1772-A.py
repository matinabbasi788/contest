n = int(input())
while n:
    n -= 1
    exec(f"print({input()})")