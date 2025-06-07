for _ in range(int(input())):
    n = int(input())
    s = input()
    stack = []
    ans = 0
    for i in range(n):
        if stack:
            # if stack[-1] == ')' and s[i] == '(':
            #     ans += 1
            #     continue
            if stack[-1] == '(' and s[i] == ')':
                stack.pop()
                continue
        stack.append(s[i])
    print(len(stack)//2)
