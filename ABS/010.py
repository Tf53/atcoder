if __name__ == "__main__":
  N = int(input())
  class1 = [0] * N
  class2 = [0] * N

  def addN(cl, value, idx):
    if cl == 1:
      class1[idx] = class1[idx - 1] + value
      class2[idx] = class2[idx - 1]
    else:
      class2[idx] = class2[idx - 1] + value
      class1[idx] = class1[idx - 1]
  
  def printValue(left, right):
    sum1 = class1[right] - class1[left - 1] if left > 0 else class1[right]
    sum2 = class2[right] - class2[left - 1] if left > 0 else class2[right]
    print(sum1)
    print(sum2)



  ci, pi = map(int, input().split())
  if ci == 1:
    class1[0] = pi 
  else:
    class2[0] = pi
  for i in range(1, N):
    ci, pi = map(int, input().split())
    addN(ci, pi, i)

  Q = int(input())
  for _ in range(Q):
    left, right = map(int, input().split())
    printValue(left - 1, right - 1)