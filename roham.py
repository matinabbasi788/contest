numbers = input()
letters = input()
num_list = []
letters_list = []
for num in numbers:
    num_list.append(int(num))

num_list.sort()

if letters == 'ABC':
    print(num_list[0],num_list[1],num_list[2])
elif letters == 'BAC':
        print(num_list[1],num_list[0],num_list[2])
elif letters == 'BCA':
        print(num_list[1],num_list[2],num_list[0])
elif letters == 'ACB':
        print(num_list[0],num_list[2],num_list[1])
elif letters == 'CAB':
        print(num_list[2],num_list[0],num_list[1])
elif letters == 'CBA':
        print(num_list[2],num_list[1],num_list[0])