import sys


def main():
  n = int(sys.stdin.readline())

  ret = [0] * 26
  data = [sys.stdin.readline().rstrip() for _ in range(n)]

  for s in data:
    ret[ord(s[0]) - ord("a")] += 1

  result = [chr(i + ord("a")) for i, j in enumerate(ret) if j >= 5]

  if len(result) == 0:
    print("PREDAJA")
  else:
    print("".join(result))


if __name__ == "__main__":
  main()
