import sys

n, k = map(int, sys.stdin.readline().split())

data = list(map(int, sys.stdin.readline().split()))

current_sum = sum(data[:k])
max_sum = current_sum

for i in range(1, len(data) - k):
  current_sum = current_sum - data[i - 1] + data[i + k - 1]
  max_sum = max(max_sum, current_sum)

print(max_sum)
