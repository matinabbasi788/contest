def clean_phone_number(s):
    digits = ''.join(c for c in s if c.isdigit())
    return '0' + digits if len(digits) == 10 else digits

# Read phone numbers until '#'
phones = []
while True:
    line = input().strip()
    if line == "#":
        break
    phones.extend(clean_phone_number(p) for p in line.split(',') if p.strip())

# Flatten all phone numbers into one string
all_digits = ''.join(phones)
total_length = len(all_digits)
n = len(phones)  # Number of phone numbers

cursor = 0  # Current position in all_digits (0-based)
S = ""      # Result string

while True:
    try:
        instruction = input().strip()
        if not instruction:
            continue  # Skip empty lines
    except EOFError:
        break
    parts = instruction.split()
    cmd = parts[0]

    if cmd == "go":
        i = int(parts[1])
        if i < 0 or i >= n:
            print("MISS ME!")
            break
        cursor = i * 11

    elif cmd == "forward":
        i = int(parts[1])
        new_cursor = cursor + i
        if new_cursor > total_length:
            print("MISS ME!")
            break
        cursor = new_cursor

    elif cmd == "backward":
        i = int(parts[1])
        new_cursor = cursor - i
        if new_cursor < 0:
            print("MISS ME!")
            break
        cursor = new_cursor

    elif cmd == "next":
        i = int(parts[1])
        if cursor + i > total_length:
            print("MISS ME!")
            break
        S += all_digits[cursor:cursor + i]
        cursor += i

    elif cmd == "pick":
        if cursor >= total_length:
            print("MISS ME!")
            break
        i, j = int(parts[1]), int(parts[2])
        if not (0 <= i <= 10 and 0 <= j <= 10):
            print("MISS ME!")
            break
        # Find the current phone number's start and end positions
        phone_index = cursor // 11
        phone_start = phone_index * 11
        phone_end = phone_start + 11
        if phone_end > total_length:
            print("MISS ME!")
            break
        # Extract the current phone number
        phone = all_digits[phone_start:phone_end]
        # Pick the substring based on i and j
        if i <= j:
            S += phone[i:j + 1]
        else:
            S += phone[j:i + 1][::-1]

    elif cmd == "delete":
        i = int(parts[1])
        if i > len(S):
            print("MISS ME!")
            break
        S = S[:-i] if i > 0 else S

else:
    print(S[:10000])
