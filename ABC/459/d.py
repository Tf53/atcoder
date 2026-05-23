if __name__  == "__main__":
  T = int(input())

  for _ in range(T):
    S = input()
    count = [0 for _ in range(26)]
    for s in S:
      count[ord(s) - ord('a')] += 1
    count.sort()
    