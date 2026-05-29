if __name__ == "__main__":
  N = int(input())
  A = sorted(list(map(int, input().split())))
  Q = int(input())
  #0より大きい最小
  def bsl(B, x):
    left = -1
    right = N
    while right - left > 1:
      mid = (left + right) // 2
      if B[mid] >= x: right = mid
      else: left = mid
    
    if right < N:
      return B[right] - x
    else:
      return 1000000000
    
  
  def bss(B, x):
    left = -1
    right = N
    while right - left > 1:
      mid = (left + right) // 2
      if B[mid] <= x: left = mid
      else: right = mid
    
    if left >= 0:
      return x - B[left]
    else:
      return 1000000000
    

  def search():
    x = int(input())
    right = abs(bsl(A,x))
    left = abs(bss(A,x))
    print(right if right < left else left)


  for _ in range(Q):
    search()
