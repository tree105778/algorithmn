import sys

a, b, c = map(int, sys.stdin.readline().split())
costs = [0, a, b * 2, c * 3]
pay = [0] * 100

for _ in range(3):
  i, j = map(int, sys.stdin.readline().split())
  for k in range(i, j):
    pay[k] += 1

print(sum(costs[p] for p in pay))
