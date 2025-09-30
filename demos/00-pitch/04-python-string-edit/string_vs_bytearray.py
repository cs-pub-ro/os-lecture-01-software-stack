import time

NUM_ROUNDS = 100000
STR_SIZE = 64

# Initialize the string and bytearray
initial_string = ""
initial_bytearray = bytearray(STR_SIZE)

# Measure time for string concatenation (immutable)
start_time = time.time()
for i in range(0, NUM_ROUNDS):
    s = initial_string
    for j in range(0, STR_SIZE-1):
        s = s + "a"
end_time = time.time()

string_time = end_time - start_time

# Measure time for bytearray modification (mutable)
start_time = time.time()
for i in range(0, NUM_ROUNDS):
    ba = initial_bytearray
    for j in range(0, STR_SIZE-1):
        ba[j] = 0x61
end_time = time.time()

bytearray_time = end_time - start_time

print(f"Time for string concatenation: {string_time:.4f} seconds")
print(f"Time for bytearray modifications: {bytearray_time:.4f} seconds")
