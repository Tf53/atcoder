if __name__ == "__main__":
  N, M = map(int, input().split())
  A = sorted(list(map(int, input().split())))
  B = sorted(list(map(int, input().split())))
  isUsed = [False] * M

  preUsed = 0
  def tansaku(x):
    left = -1
    right = M
    while right - left > 1:
      mid = (left + right) // 2
      if B[mid] >= B[preUsed]: 
        right = mid
      else: left = mid 
    return right
 
  count = 0
  for v in A:
    x = tansaku(v)
    if x != M and B[x] <= 2*v: 
      preUsed += 1
      count += 1
    if preUsed == M: break
  print(count)

  

