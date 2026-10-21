import sys

text = sys.stdin.readline().rstrip()

print(1 if text == text[::-1] else 0)
