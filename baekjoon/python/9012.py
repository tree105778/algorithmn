import sys
from collections import deque

input = sys.stdin.readline


def main():
  T = int(input())
  result = []
  while T:
    queue = deque()
    flag = False
    data = input().rstrip()
    for i in data:
      if i == "(":
        queue.append(i)
      elif i == ")" and queue:
        queue.pop()
      else:
        flag = True
    if queue or flag:
      result.append("NO")
    else:
      result.append("YES")
    T -= 1
  print("\n".join(result))


if __name__ == "__main__":
  main()
