# for _ in range(int(input())):
#     s = input()
#     if s.find(">") :
#         # number1 = s[:s.find(">")]
#         # s2 = s[s.find(">")+1: ]
#         number1 , t,number2  = input().split(">")
#         number1 = int(number1)
#         number2 = int(number2)
#         if number1>number2 :
#             print(a)

t = int(input())
for _ in range(t):
    s = input()
    if '=' in s:
        a, b = map(int, s.split('='))
        if a == b:
            print(f"{a}={b}")
        else:
            if a < b:
                print(f"{a}<{b}")
            elif a > b:
                print(f"{a}>{b}")
            else:
                a = b - 1
                print(f"{a}<{b}")
    elif '<' in s:
        a, b = map(int, s.split('<'))
        if a < b:
            print(f"{a}<{b}")
        else:
            if a == b:
                print(f"{a}={b}")
            else:
                a = 0
                print(f"{a}<{b}")
    else:
        a, b = map(int, s.split('>'))
        if a > b:
            print(f"{a}>{b}")
        elif a < b:
            print(f"{a}<{b}")
        else:
            if a == b:
                print(f"{a}={b}")
            else:
                b = 0
                print(f"{a}>{b}")
            