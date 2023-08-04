def check_group_photo_possible(N, X, heights):
    heights.sort()

    for i in range(N):
        if(heights[i + N] - heights[i] < X):
            return "NO"
    return "YES"

# Read the number of test cases
t = int(input().strip())

for _ in range(t):
    # Read input for each test case
    N, X = map(int, input().strip().split())
    heights = list(map(int, input().strip().split()))

    # Check if it's possible to arrange the group photo
    result = check_group_photo_possible(N, X, heights)
    print(result)



# Input:

# 3
# 3 6
# 1 3 9 10 12 16
# 3 1
# 2 5 2 2 2 5
# 1 2
# 8 6