from itertools import combinations


def main():
  data = []

  for i in range(9):
    data.append(int(input()))

  data.sort()

  for c in combinations(data, 7):
    if sum(c) == 100:
      for i in list(c):
        print(i)
      break


if __name__ == "__main__":
  main()
