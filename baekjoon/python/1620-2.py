import sys


def main():
  input_data = sys.stdin.read().splitlines()
  n, m = map(int, input_data[0].split())
  data = input_data[1 : n + 1]
  mp = {name: i + 1 for (i, name) in enumerate(data)}
  result = []

  for p in input_data[n + 1 : n + 1 + m]:
    if p.isdecimal():
      result.append(data[int(p) - 1])
    else:
      result.append(str(mp[p]))

  print("\n".join(result))


if __name__ == "__main__":
  main()
