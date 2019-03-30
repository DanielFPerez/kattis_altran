# =============================================================================
#   Import Section
# =============================================================================
import sys
import operator

# =============================================================================
#   Read data
# =============================================================================
input_stream = []

for i in sys.stdin:
    input_stream.append(int(i))

# =============================================================================
#   Solve task
# =============================================================================
def determine_election_result(votes):
    """
    Return the election result for the evaluated test case
    :param votes: (list) -- list of votes for each candidate. Candidate correspond to index of list +1
    :return: None. Printed result of evaluated test case
    """
    # Determine winning element with the most votes
    winner_index, winner_value = max(enumerate(votes), key=operator.itemgetter(1))

    # Check if there is more than 1 majority winner
    if len([i for i, x in enumerate(votes) if x == winner_value]) > 1:
        print("no winner")

    else:
        # Evaluate winner type
        winner_pctge = winner_value/sum(votes)

        if winner_pctge > 0.5:
            print("majority winner ", winner_index + 1)
        else:
            print("minority winner ", winner_index + 1)


# Test cases as first element in the input stream
T_cases = input_stream[0]
idx_tracker = 1

# Evaluate each test case
for i in range(T_cases):

    # Get the number of candidates in election
    n_candidates = input_stream[idx_tracker]

    idx_tracker += 1

    # Get results of election
    votes = input_stream[idx_tracker:(idx_tracker+n_candidates)]

    # Evaluate election results from votes
    determine_election_result(votes)

    idx_tracker += n_candidates

# Finished.