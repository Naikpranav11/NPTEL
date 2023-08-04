def max_score(n, memo={}):
    if n in memo:
        return memo[n]
    
    if n <= 1:
        return 0
    
    max_val = 0
    for j in range(1, n//2 + 1):
        max_val = max(max_val, j*(n-j) + max_score(j, memo) + max_score(n-j, memo))
    
    memo[n] = max_val
    return max_val

T = int(input())
for _ in range(T):
    N = int(input())
    print(max_score(N))
