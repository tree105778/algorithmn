import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
data = list(map(int, input().split()))
stack = deque()
result = [-1] * N

for i in range(N - 1, -1, -1):
  while stack and stack[-1] <= data[i]:
    stack.pop()
  if stack:
    result[i] = stack[-1]
  stack.append(data[i])

print(" ".join(map(str, result)))
