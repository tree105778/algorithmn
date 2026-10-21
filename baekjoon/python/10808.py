import sys

s = sys.stdin.readline().strip()

counts = [0] * 26

for i in s:
  counts[ord(i) - ord("a")] += 1

print(" ".join(map(str, counts)))
