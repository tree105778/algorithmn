import sys

text = sys.stdin.readline().rstrip()
result = []

for ch in text:
  if "a" <= ch <= "z":
    # if ch.islower():
    newCh = chr((ord(ch) - ord("a") + 13) % 26 + ord("a"))
    result.append(newCh)
  elif "A" <= ch <= "Z":
    # elif ch.isupper():
    newCh = chr((ord(ch) - ord("A") + 13) % 26 + ord("A"))
    result.append(newCh)
  else:
    result.append(ch)

print("".join(result))
