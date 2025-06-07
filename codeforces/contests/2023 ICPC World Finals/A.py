from sympy import symbols, Eq, solve

# Define symbols
a, b, c = symbols('a b c')

# Define the five equations
equations = [
    Eq(a + b + c, 12),  # a + b + c = 12
    Eq(2*a + b, 13),     # 2a + b = 13
    Eq(b + 2*c, 24),     # b + 2c = 24
    Eq(3*c, 24),         # 3c = 24
    Eq(a + 2*b, 17)      # a + 2b = 17
]

# Function to solve the system considering one equation as a lie
def solve_system_with_one_lie(equations):
    # List to store the valid solutions
    solutions = []

    # Try removing each equation one at a time
    for i in range(5):
        # Create a sub-system without the ith equation
        sub_equations = equations[:i] + equations[i+1:]
        
        # Solve the system of equations
        sol = solve(sub_equations, (a, b, c))
        
        # If the solution satisfies all remaining equations, add it to the valid solutions list
        if all(eq.subs(sol) == True for eq in sub_equations):
            solutions.append(sol)

    # Return the valid solution(s)
    return solutions

# Get valid solutions
valid_solutions = solve_system_with_one_lie(equations)

# Print the valid solutions
if valid_solutions:
    for sol in valid_solutions:
        print(f"Valid solution: axex legs = {sol[a]}, basilisk legs = {sol[b]}, centaur legs = {sol[c]}")
else:
    print("No valid solution found.")

