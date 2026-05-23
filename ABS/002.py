from itertools import product

if __name__ == "__main__":
  N = int(input())

  def check(S):
    count = 0
    for c in S:
      if c == '(':
        count += 1
      else:
        count -= 1

      if count < 0:
        return False
    
    return (count == 0)


  for S in product(['(', ')'], repeat=N):
    if check(S):
      print(*S, sep='')
      
