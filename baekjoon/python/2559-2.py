import sys


def main():
  n, k = map(int, sys.stdin.readline().split())
  data = list(map(int, sys.stdin.readline().split()))

  pre_sum = [0] * (n + 1)
  for i in range(n):
    pre_sum[i + 1] = data[i] + pre_sum[i]

  print(max(pre_sum[i] - pre_sum[i - k] for i in range(k, n + 1)))


if __name__ == "__main__":
  main()
