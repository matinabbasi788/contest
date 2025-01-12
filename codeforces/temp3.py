import threading
from itertools import permutations

# Define the barrier and other shared resources
cycle_barrier = threading.Barrier(3)
output_lock = threading.Lock()
sequence = list(permutations("ABC"))
num_permutations = len(sequence)

# Define the worker function
def worker(thread_id):
    global sequence
    for i in range(num_permutations):
        # Compute the current permutation index for this thread
        index = (i + thread_id) % num_permutations
        # Print the result with proper formatting
        with output_lock:
            if thread_id == 0:
                print("(", end="")
            print(f"{'|'.join(sequence[index])}|", end="")
            if thread_id == 2:
                print(")")
        # Wait at the barrier
        cycle_barrier.wait()

# Create and start threads
threads = []
for i in range(3):
    thread = threading.Thread(target=worker, args=(i,))
    threads.append(thread)
    thread.start()

# Wait for all threads to complete
for thread in threads:
    thread.join()

