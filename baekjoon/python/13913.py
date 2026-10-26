import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())
queue = deque([N])
dist = [-1] * 100005
parent = [-1] * 100005
dist[N] = 0
trace = []

while queue:
  n = queue.popleft()

  for i in [n - 1, n + 1, n * 2]:
    if 0 <= i <= 100000 and dist[i] == -1:
      dist[i] = dist[n] + 1
      queue.append(i)
      parent[i] = n

i = K
trace.append(i)
while i != N:
  i = parent[i]
  trace.append(i)

trace.reverse()
print(dist[K])
print(" ".join(map(str, trace)))
