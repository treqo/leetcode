# --- Finding the optimal solution ---
# Returns the minimum number of coins to achieve the value x
# Params:
#   x : Integer representing the final value we want
#   coins : a list of possible coin values
#   debug : extra print statements if True
def min_coins(x, coins, debug=False):
    result = {} # Initialize the result dictionary {value : min number of coins to achieve}

    result[0] = 0
    for s in range(1, x+1):
        result[s] = s
        for c in coins:
            if s - c >= 0:
                result[s] = min(result[s], result[s-c] + 1)

    if debug:
        for value, min_coins in result.items():
            print(f"Value: {value}, Minimum Coins: {min_coins}")

    return result[x]

# --- Constructing the Optimal Solution ---
# Returns the number of unique solutions (possible sets of coins)
# Params:
#   x : Integer representing the final value we want
#   coins : a list of possible coin values
def count_coins(x, coins, debug=False, sort=True):
    result = {} 

    result[0] = 1
    for s in range(1, x+1):
        result[s] = 0
        for c in coins:
            if s - c >= 0:
                result[s] += result[s-c]

    return result[x]


# --- Constructing the Optimal Solution ---
# Returns a list of coins that represents the set of coins corresponding 
# to the minimal coins to target value solution
# Params:
#   x : Integer representing the final value we want
#   coins : a list of possible coin values
#   sorted : return sorted or not?
#
# Time Complexity of O(nx)
#   - n : the number of coins
#   - x : the target sum
def min_coins_opt_sol(x, coins, debug=False, sort=True):
    result = {} # Initialize the result dictionary {value : list}

    result[0] = []
    for s in range(1, x+1):
        result[s] = [1] * s
        for c in coins:
            if s - c >= 0:
                new_result = result[s-c] + [c]
                if len(new_result) < len(result[s]):
                    result[s] = new_result
    if debug:
        for value, min_coins in result.items():
            print(f"Value: {value}, Minimum Coins: {min_coins}")

    if sort:
        return sorted(result[x])
    
    return result[x]

if __name__ == '__main__':
    print(min_coins(13, [1, 2, 5], True)) # 4
    print(min_coins(13, [1, 4, 5])) # 3
    print(min_coins(42, [1, 5, 6, 17])) # 5

    print(min_coins_opt_sol(13, [1, 2, 5], True)) # 4
    print(min_coins_opt_sol(13, [1, 4, 5])) # 3
    print(min_coins_opt_sol(42, [1, 5, 6, 17])) # 5

    print(count_coins(13, [1, 2, 5])) # 634
    print(count_coins(13, [1, 4, 5])) # 88
    print(count_coins(42, [1, 5, 6, 17])) # 1103532


