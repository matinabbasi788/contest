def check(input_file, output_file, answer_file):
    """
    A checker for the problem that verifies the output correctly reports the number of characters received.

    Args:
        input_file: File object for input data.
        output_file: File object for the participant's output.
        answer_file: File object for the correct answer (not used in this checker).

    Returns:
        (int, str): A tuple where the first element is the score (1 for correct, 0 for incorrect),
        and the second element is a message describing the result.
    """
    # Read input
    n = int(input_file.read().strip())

    # Read participant's output
    output = output_file.read().strip()

    # Calculate the expected number of characters
    expected_characters = n * 4

    # Check if the output matches the expected number of characters
    if output == str(expected_characters):
        return 1, "OK"
    else:
        return 0, f"Incorrect: Expected {expected_characters}, but found {output}."

# Example usage in a local environment (for testing):
if __name__ == "__main__":
    from io import StringIO

    # Example input
    input_data = "3\n"
    output_data = "12\n"
    answer_data = ""  # Unused in this example

    # Simulate file objects
    input_file = StringIO(input_data)
    output_file = StringIO(output_data)
    answer_file = StringIO(answer_data)

    # Run the checker
    score, message = check(input_file, output_file, answer_file)
    print(f"Score: {score}, Message: {message}")

