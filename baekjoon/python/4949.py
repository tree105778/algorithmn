import sys
from collections import deque

input_data = sys.stdin.read().splitlines()[:-1]
result = []
matching = {")": "(", "]": "["}

for line in input_data:
  dq = deque()
  flag = False
  for i in line:
    if i in "([":
      dq.append(i)
    elif i in matching and (not dq or dq.pop() != matching[i]):
      flag = True
      break
  if dq or flag:
    result.append("no")
  else:
    result.append("yes")

print("\n".join(result))
