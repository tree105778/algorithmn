import sys


def main():
  n, m = map(int, sys.stdin.readline().split())
  data = []
  mp = {}
  for i in range(n):
    p = sys.stdin.readline().rstrip()
    data.append(p)
    mp[p] = i + 1

  for _ in range(m):
    s = sys.stdin.readline().rstrip()
    if s.isdecimal():
      print(data[int(s) - 1])
    else:
      print(mp[s])


if __name__ == "__main__":
  main()
