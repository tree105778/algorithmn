import sys


def main():
  ret = 0
  input_data = sys.stdin.read().splitlines()
  n = int(input_data[0])
  m = int(input_data[1])
  data = list(map(int, input_data[2].split()))

  data.sort()

  i = 0
  j = n - 1

  while i < j:
    if data[i] + data[j] == m:
      ret += 1
      j -= 1
    elif data[i] + data[j] < m:
      i += 1
    elif data[i] + data[j] > m:
      j -= 1

  print(ret)


if __name__ == "__main__":
  main()
