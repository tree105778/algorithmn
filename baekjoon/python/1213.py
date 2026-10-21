def main():
  a = 0
  a_a = ""
  a_b = ""
  alpha = [0] * 26
  s = input()
  for ch in s:
    alpha[ord(ch) - ord("A")] += 1

  for i in range(26):
    if alpha[i] % 2 == 1:
      a += 1
      a_b += chr(i + ord("A"))
    a_a += chr(i + ord("A")) * (alpha[i] // 2)

  if a > 1:
    print("I'm Sorry Hansoo")
  else:
    print(a_a + a_b + a_a[::-1])


if __name__ == "__main__":
  main()
