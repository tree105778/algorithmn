import sys
import math
from collections import Counter

n = int(sys.stdin.readline())
result = []
for _ in range(n):
  m = int(sys.stdin.readline())

  input_data = [sys.stdin.readline().split()[1] for _ in range(m)]
  c = Counter(input_data)
  temp = math.prod(i + 1 for i in c.values()) - 1
  result.append(str(temp))

print("\n".join(result))
