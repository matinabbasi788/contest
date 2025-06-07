import os
import subprocess

def run_tests(solution_cmd, test_dir="testcases"):
    if not os.path.exists(test_dir):
        print(f"Directory '{test_dir}' not found.")
        return

    in_files = [f for f in os.listdir(test_dir) if f.endswith(".in")]
    if not in_files:
        print(f"No .in files found in '{test_dir}'.")
        return

    passed = 0
    failed = 0

    for in_file in sorted(in_files):
        base_name = os.path.splitext(in_file)[0]
        out_file = f"{base_name}.out"
        out_path = os.path.join(test_dir, out_file)

        if not os.path.exists(out_path):
            print(f"Missing .out file for test '{base_name}'.")
            failed += 1
            continue

        # Read input and expected output
        with open(os.path.join(test_dir, in_file), 'r') as f:
            input_data = f.read().strip()
        with open(out_path, 'r') as f:
            expected_output = f.read().strip()

        # Run solution
        try:
            result = subprocess.run(
                solution_cmd,
                input=input_data,
                text=True,
                capture_output=True,
                timeout=5  # Adjust timeout if needed
            )
        except subprocess.TimeoutExpired:
            print(f"⏰ Test '{base_name}': Timeout")
            failed += 1
            continue

        actual_output = result.stdout.strip()
        error_output = result.stderr.strip()

        # Check results
        if result.returncode != 0:
            print(f"❌ Test '{base_name}': Runtime Error (exit code {result.returncode})")
            print(f"   Stderr: {error_output}")
            failed += 1
        elif actual_output == expected_output:
            print(f"✅ Test '{base_name}': Passed")
            passed += 1
        else:
            print(f"❌ Test '{base_name}': Failed")
            print(f"   Expected: {expected_output}")
            print(f"   Received: {actual_output}")
            failed += 1

    print(f"\n📊 Summary: {passed} passed, {failed} failed")

if __name__ == "__main__":
    # Configure your solution command here:
    # For Python: ["python3", "boat.py"]
    # For C++: ["./a.out"] (compile first)
    SOLUTION_CMD = ["python3", "I-am-Sherlocked.py"]
    TEST_DIR = "/home/lab/Downloads/TD24/F/"  # Directory containing .in/.out files
    
    run_tests(SOLUTION_CMD, TEST_DIR)
