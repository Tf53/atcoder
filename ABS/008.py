if __name__ == "__main__":
  N = int(input())
  S = input()
  atcoder = "atcoder"
  n = 1000000007

  def index(c):
    n = -1
    match c:
      case code if code == 'a': n = 0
      case code if code == 't': n = 1
      case code if code == 'c': n = 2
      case code if code == 'o': n = 3
      case code if code == 'd': n = 4
      case code if code == 'e': n = 5
      case code if code == 'r': n = 6
    return n


  def isContains(c):
    n = False
    match c:
      case code if code == 'a': n = True
      case code if code == 't': n = True
      case code if code == 'c': n = True
      case code if code == 'o': n = True
      case code if code == 'd': n = True
      case code if code == 'e': n = True
      case code if code == 'r': n = True
    return n


  res = [[0] * N for _ in range(7)]
  diff = 0
  for j, c in enumerate(S):
    if isContains(c) and index(c) == 0:
      res[index(c)][j] = 1
      diff = j
      break

  for i, c in enumerate(S):
    if i <= diff: continue

    for j in range(7):
      res[j][i] = res[j][i-1]
    
    if isContains(c):
      idx = index(c)
      if idx > 0:
        res[idx][i] = (res[idx][i - 1] + res[idx - 1][i - 1]) % n
      else:
        res[idx][i] = res[idx][i - 1] + 1 
  
  print(res[6][N - 1])


    


  




  


