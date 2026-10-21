import sys


def main():
  result = []
  n = int(sys.stdin.readline())
  for _ in range(n):
    mp = {}
    m = int(sys.stdin.readline())
    temp = 1
    for _ in range(m):
      _, cloth = sys.stdin.readline().split()
      if cloth not in mp:
        mp[cloth] = 0
      mp[cloth] += 1
    for i in mp.values():
      temp *= i + 1
    result.append(str(temp - 1))

  print("\n".join(result))


if __name__ == "__main__":
  main()
