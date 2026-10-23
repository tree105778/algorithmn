import sys

input = sys.stdin.readline

N = int(input())
ret = 0
mp = [[] for _ in range(N)]
visited = [False] * N

for i, j in enumerate(map(int, input().split())):
  if j == -1:
    continue
  mp[j].append(i)

M = int(input())
mp[M] = []


def dfs(n):
  global ret
  visited[n] = True

  if n == M:
    return
  if not len(mp[n]):
    ret += 1
    return
  for i in mp[n]:
    if len(mp[n]) == 1 and i == M:
      ret += 1
      return
    if not visited[i]:
      dfs(i)


dfs(0)
print(ret)
