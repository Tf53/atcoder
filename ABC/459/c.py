if __name__ == "__main__":
  N, Q = map(int, input().split())

  masu = [0 for _ in range(N)]
  sumN = [0 for _ in range(Q + 1)]

  s = [0 for _ in range(Q + 1)]
  sumN[0] = N

  count = 0
  for _ in range(Q):
    n , xy = map(int, input().split())
    if n == 1:
      x = xy - 1

      curr = masu[x]
      sumN[curr] -= 1
      masu[x] += 1
      next = masu[x]
      sumN[next] += 1
      s[next] += 1
      
      if sumN[count] == 0:
        count += 1

    else:
      y = xy
      if y + count < len(sumN):
        print(s[y + count])
      else:
        print(0)
