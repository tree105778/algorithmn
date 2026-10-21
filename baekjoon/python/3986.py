import sys


def main():
  ret = 0
  n = int(sys.stdin.readline())
  tc = [sys.stdin.readline().rstrip() for _ in range(n)]

  for s in tc:
    stack = []
    for ch in s:
      if len(stack) > 0 and stack[-1] == ch:
        stack.pop()
      else:
        stack.append(ch)
    if len(stack) == 0:
      ret += 1

  print(ret)


if __name__ == "__main__":
  main()
