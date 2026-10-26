import sys

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
stack = []
result = [0] * N
for i in range(len(arr)):
  while stack and arr[stack[-1]] <= arr[i]:
    stack.pop()

  if stack:
    result[i] = stack[-1] + 1
  stack.append(i)
print(" ".join(map(str, result)))
