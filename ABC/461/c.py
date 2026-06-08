if __name__ == "__main__":
  N, K, M = map(int, input().split())
  CV = []
  for _ in range(N):
    Ci, Vi = map(int,input().split())
    CV.append((Ci, Vi))
  CV.sort(key=lambda x:x[1])

  count = 0
  setC = set()
  fM = M
  for c, v in reversed(CV):
    if M < K or (fM - len(setC)) < M:
      count += v

      if c not in setC:
        M -= 1
      setC.add(c)

      K -= 1
      if K == 0: break
    else:
      if c in setC: continue

      count += v
      M -= 1
      K -= 1
      setC.add(c)
      if K == 0: break
  
  print(count)

  

