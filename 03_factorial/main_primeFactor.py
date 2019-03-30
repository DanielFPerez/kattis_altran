# =============================================================================
#   Import Section
# =============================================================================
import sys

# =============================================================================
#   Read data
# =============================================================================
import time
#
t0 = time.clock()

# Input is 1 integer value
n = 10000000

for i in sys.stdin:
    n = int(i)

# =============================================================================
#   Solve task
# =============================================================================
fact_result = int(1)

while n > 1:

    temp = n

    fact_result *= temp

    while fact_result % 10 == 0:
        fact_result //= 10

    if fact_result > 1000:
        fact_result = int(str(fact_result)[-4:])

    n -= 1

# Get the last 3 digits
extract_numb = fact_result % 100000

# Split result in list
mod_result_list = [int(j) for j in str(extract_numb)]


print(''.join(map(str, mod_result_list[- 3:])))


print("elapsed time: ", time.clock()-t0)