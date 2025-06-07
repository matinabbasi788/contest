def is_valid_subgrid(grid, r1, r2, c1, c2):
    for i in range(r1, r2 + 1):
        for j in range(c1, c2 + 1):
            val = grid[i][j]
            can_reach = False
            
            # Left: val > max of all between c1 and j-1
            if j == c1 or val > max([grid[i][k] for k in range(c1, j)]):
                can_reach = True
            # Right: val > max of all between j+1 and c2
            elif j == c2 or val > max([grid[i][k] for k in range(j + 1, c2 + 1)]):
                can_reach = True
            # Top: val > max of all between r1 and i-1
            elif i == r1 or val > max([grid[k][j] for k in range(r1, i)]):
                can_reach = True
            # Bottom: val > max of all between i+1 and r2
            elif i == r2 or val > max([grid[k][j] for k in range(i + 1, r2 + 1)]):
                can_reach = True
            
            if not can_reach:
                return False
    return True

def solve_parking_theory(n, m, grid):
    count = 0
    for r1 in range(n):
        for r2 in range(r1, n):
            for c1 in range(m):
                for c2 in range(c1, m):
                    if is_valid_subgrid(grid, r1, r2, c1, c2):
                        count += 1
    return count

# Test cases
def run_test_case(n, m, grid, expected):
    result = solve_parking_theory(n, m, grid)
    print(f"Input: {n} x {m}")
    print("Grid:")
    for row in grid:
        print(row)
    print(f"Output: {result}")
    print(f"Expected: {expected}")
    print(f"Correct: {result == expected}\n")

# Test case 1: 2x3
n1, m1 = 2, 3
grid1 = [
    [1, 2, 5],
    [3, 4, 6]
]
run_test_case(n1, m1, grid1, 18)

# Test case 2: 6x6
n2, m2 = 6, 6
grid2 = [
    [14, 18, 4, 36, 23, 1],
    [2, 17, 32, 33, 11, 5],
    [15, 6, 28, 24, 22, 16],
    [12, 26, 20, 30, 7, 29],
    [34, 27, 35, 10, 3, 31],
    [19, 25, 21, 8, 9, 13]
]
run_test_case(n2, m2, grid2, 376)
