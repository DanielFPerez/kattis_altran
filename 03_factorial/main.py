# =============================================================================
#   Import Section
# =============================================================================
import sys
import math

# =============================================================================
#   Read data
# =============================================================================
# Input is 1 integer value
n = None
fact = math.factorial(24445)
for i in sys.stdin:
    n = int(i)

# =============================================================================
#   Solve task
# =============================================================================

# Factorial for numbers less than 5 have no trailing zeros
if n < 5:
    n_fact = math.factorial(n)
    print(n_fact)

else:

    # Specify multiples of 10 of the allowed numbers
    list_multipTen = [10, 100, 1000, 10000, 100000, 1000000, 10000000]

    # keep track of the factor to which numbers should be divided
    zeros_track = 10
    value_tracker = 1

    # Value to cache factorial result
    cached_val = int(1)

    # Loop over all factorial multipliers
    for i in range(2, n+1):
        # Ignore multiplications by powers of 10, as they just add zeros to the end of value
        if i in list_multipTen:
            pass
        # Multiplications by 5 add zeros proportional to "zeros_track"
        elif i % 5 == 0:
            if i % 25 == 0 and i > value_tracker:
                value_tracker = i
                # Perform multiplication
                cached_val *= i
                # Eliminate trailing zeros
                cached_val = cached_val // 100
            else:
                # Perform multiplication
                cached_val *= i
                # Eliminate trailing zeros
                cached_val = cached_val // 10
        # Otherwise perform normal multiplication
        else:
            cached_val *= i

    # At the end of the for-loop, cached_val contains factorial result without trailing zeros
    # Get the last 3 values allowing for a tolerance in "zeros" on the 2nd and 3rd most last positions
    result = int(cached_val % 1000000)

    result_str = str(result)

    # Split result in list
    mod_result_list = [int(j) for j in result_str]

    # Print result
    l_modresult = len(mod_result_list)

    if l_modresult < 3:
        print(''.join(map(str, mod_result_list)))
    else:
        print(''.join(map(str, mod_result_list[(l_modresult - 3):l_modresult])))










