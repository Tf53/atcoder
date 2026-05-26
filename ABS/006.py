def calc_next(S):
  N = len(S)

  res = [[N] * 26 for _ in range(N + 1)]


  for i in range(N - 1, -1, -1):
    for j in range(26):
      res[i][j] = res[i + 1][j]
    res[i][ord(S[i]) - ord('a')] = i
  
  return res

if __name__ == "__main__":
  N, K = map(int, input().split())
  S = input()

  res = ''
  nex = calc_next(S)

  j = -1
  for i in range(K):
    for ordc in range(26):
      k = nex[j + 1][ordc]

      if N - k >= K - i:
        res = res + chr(ord('a') + ordc)
        j = k
        break

  print(res)

  


  

