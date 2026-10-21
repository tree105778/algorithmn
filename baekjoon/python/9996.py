import sys


def main():
  n = int(sys.stdin.readline())
  patterA, patternB = sys.stdin.readline().rstrip().split("*")

  data = [sys.stdin.readline().rstrip() for _ in range(n)]

  for d in data:
    if len(d) >= 2:
      if d.endswith(patternB) and d.startswith(patterA):
        print("DA")
      else:
        print("NE")
    else:
      print("NE")


if __name__ == "__main__":
  main()
