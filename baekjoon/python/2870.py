import sys

input = sys.stdin.readline
N = int(input())
input_data = [input().rstrip() for _ in range(N)]
numbers = []

for text in input_data:
  newText = ""
  for ch in text:
    if ch.isalpha():
      newText += " "
    else:
      newText += ch
  numbers.extend(map(int, newText.split()))

numbers.sort()

print("\n".join(map(str, numbers)))
