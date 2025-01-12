for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = 0
    l = []
    for i in s:
        if i in l:
            ans += 1
        else:
            ans += 2
            l.append(i)
    print(ans)

for _ in range(int(input())):
    number_of_candies = int(input())
    list_of_candies_wieght = list(map(int, input().split()))
    number_of_digit_two = 0
    number_of_digit_one = 0 
    for weight in list_of_candies_wieght:
        if weight == 1:
            number_of_digit_one += 1
        else:
            number_of_digit_two += 1

    if number_of_digit_one % 2 ==0:


        pass
