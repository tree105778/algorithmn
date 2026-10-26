import sys

inpnt = sys.stdin.readline
N = int(input())
data = list(map(int, input().split()))
stack = []
result = [-1] * N

for i in range(len(data)):
  while stack and data[stack[-1]] < data[i]:
    result[stack.pop()] = data[i]
  stack.append(i)

print(result)
