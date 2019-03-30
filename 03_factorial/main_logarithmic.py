# =============================================================================
#   Import Section
# =============================================================================
import sys
import math

# =============================================================================
#   Read data
# =============================================================================
# Input is 1 integer value
n = 1000000

# for i in sys.stdin:
#     n = int(i)

# =============================================================================
#   Solve task
# =============================================================================

# Factorial for numbers less than 5 have no trailing zeros
if n < 5:
    n_fact = math.factorial(n)
    print(n_fact)

else:

    # Separate the elements of the factorial
    log_prime_factors = [math.log(i) for i in range(1, n+1)]

    summed_primed = sum(log_prime_factors)

    fact_result = math.exp(summed_primed)

    print("Thats it my man!")