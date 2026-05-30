from itertools import combinations

if __name__ == "__main__":
  N, K = map(int, input().split())
  S = []
  for _ in range(N):
    s = input()
    S.append(s)

  def countEng(S):
    eng = [0] * 26
    for Si in S:
      for c in Si:
        eng[ord(c) - ord('a')] += 1
    
    count = 0
    for v in eng:
      if v == K: count += 1
    return count

  count = []
  for n in range(1, N + 1):
    for v in combinations(S, n):
      count.append(countEng(v))
  print(max(count))
