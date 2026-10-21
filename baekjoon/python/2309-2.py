import sys
from itertools import combinations


def main():
  data = [int(sys.stdin.readline()) for _ in range(9)]
  total_sum = sum(data)
  for c in combinations(data, 2):
    if total_sum - sum(c) == 100:
      result = [x for x in data if x not in c]
      result.sort()

      print("\n".join(map(str, result)))
      break


if __name__ == "__main__":
  main()
