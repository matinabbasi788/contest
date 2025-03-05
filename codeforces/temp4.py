
n = int(input())


def calculate(num):
    global cnt
    while (num % 10 == 0):
        num = num/10
        cnt = cnt+1

    num = num % 100
    return num


cnt = 0
f = 1
for i in range(1, n+1):
    f = f*i
    f = calculate(f)

print(cnt)
