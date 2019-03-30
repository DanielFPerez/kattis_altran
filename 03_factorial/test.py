import math

_FAC_TABLE = [1, 1]


def my_factorial(n):
    if n < len(_FAC_TABLE):
        return _FAC_TABLE[n]

    last = len(_FAC_TABLE) - 1
    total = _FAC_TABLE[last]

    for i in range(last + 1, n + 1):
        total *= i
        _FAC_TABLE.append(total)

import time

number = 34827405726

avoidable_factors = [10, 100, 1000, 10000, 100000, 1000000, 10000000]

if number % avoidable_factors == 1:
    print("oh boy")

t0 = time.clock()
digits = int(math.log10(number))+1
# digits = len(str(number))
print("elapsed time: ", time.clock()-t0)

test = 10 % 1000

n_fact = math.factorial(175)

# fact 15: 1307674368000

test = 175 * 64254256633470647331663425065268814583481505081604265418514550770804686072876188055571050478058617757759126922781165024629535283785249373891312681964606204095295066103627393173269746264321369017484780769692803221969220866353406389238110685563235329352338266633221089548828672
# ++++++++++++++++++++++++++++++++++++++++++++++++++++
# Find the trailing zeroes using modulo
# ++++++++++++++++++++++++++++++++++++++++++++++++++++
i_modulo = 10
trail_limit = 0

# Keep evaluating modulo until
while (n_fact % i_modulo) == 0:
    i_modulo *= 10
    trail_limit += 1

# Multiply resulting module *10^3 to get the last 3 digits before trailing zeros
i_modulo *= 100000

trail_val = n_fact % i_modulo

mod_result_list = [int(i) for i in str(trail_val)]

l_modresult = len(mod_result_list)

if l_modresult - trail_limit < 3:
    print(''.join(map(str, mod_result_list[:(l_modresult-trail_val)])))
else:
    print(''.join(map(str, mod_result_list[(l_modresult - trail_limit - 3):(l_modresult - trail_limit)])))

print("We are done")