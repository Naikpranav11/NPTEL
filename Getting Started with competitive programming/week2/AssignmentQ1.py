def sort_partitions(m, b, lst):
    k = (m + b - 1) // b  # Calculate the number of partitions (ceiling of m/b)
    sorted_partitions = []

    for i in range(k):
        partition = lst[i * b: (i + 1) * b]  # Extract the current partition
        partition.sort()  # Sort the current partition
        sorted_partitions.extend(partition)  # Append the sorted partition to the result list

    return sorted_partitions

# Read the input
m, b = map(int, input().strip().split())
lst = list(map(int, input().strip().split()))

# Get the resulting list after sorting each partition
resulting_list = sort_partitions(m, b, lst)

# Print the resulting list
print(*resulting_list)
