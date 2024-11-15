number_of_customers = input()
list_of_customers = []
for i in range(int(number_of_customers)):
    list_of_customers.append(list(map(int, (input().split(' ')))))

list_of_sums = []
for customer in list_of_customers:
    list_of_sums.append(customer[0] + customer[1])

list_of_sums.sort()

half_or_more_of_customers_number = round(int(number_of_customers) / 2)
sum = list_of_sums[half_or_more_of_customers_number - 1]

better_customer = []
for cusotmer in list_of_customers:
    if cusotmer[0] + cusotmer[1] <= sum:
        better_customer.append(cusotmer)

candidates = []
for customer in better_customer:
    if cusotmer[0] + cusotmer[1] == sum:
        better_customer.remove(cusotmer)
        candidates.append(cusotmer)

sorted(candidates, key=lambda x: x[1])

number_of_empty_places = half_or_more_of_customers_number - len(better_customer) - 2
for i in range(number_of_empty_places):
    better_customer.append(candidates.pop(0))











sum_of_coffee = 0
sum_of_milk = 0

for customer2 in better_customer:
    sum_of_coffee += customer2[0]
    sum_of_milk += customer2[1]

kiram_to_in_soal = print

kiram_to_in_soal(sum_of_coffee, sum_of_milk)
