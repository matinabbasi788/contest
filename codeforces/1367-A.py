for _ in range(int(input())):
    temp = input()
    for i in range(1, len(temp), 2):
        if temp[i - 1] != temp[i]:
            if i == len(temp):
                print(temp[i], end='')
            else:
                print(temp[i - 1], end='')
        
        if temp[i - 1] == temp[i]:
            print(temp[i], end='')
            i += 1
