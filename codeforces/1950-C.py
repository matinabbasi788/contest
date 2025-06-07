for _ in range(int(input())):
    a, b = map(int, input().split(':'))
    if a == 00:
        print(f"{12:02}:{b:02} AM")
    elif a < 12:
        print(f"{a:02}:{b:02} AM")
    elif a == 12:
        print(f"{a:02}:{b:02} PM")
    else:
        print(f"{a-12:02}:{b:02} PM")
