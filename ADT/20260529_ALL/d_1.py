from collections import deque
def getNextList(circle, N):
  nextList = [[] for _ in range(N)]
  for i in range(N):
    xi, yi, ri = circle[i]
    for j in range(N):
      if i == j: continue
      xj, yj, rj = circle[j]
      if isNext(xi, yi, ri, xj, yj, rj):
        nextList[i].append(j)
  return nextList

def isNext(x1, y1, r1, x2, y2, r2):
  d = (x1 - x2)**2 + (y1 - y2)**2
  r_diff = (r1 - r2)**2
  r_sum = (r1 + r2)**2
  if r_sum < d or r_diff > d:
    return False
  else:
    return True

if __name__ == "__main__":
  N = int(input())
  sx, sy, tx, ty = map(int, input().split())

  circle = []
  for _ in range(N):
    (xi, yi, ri) = map(int, input().split())
    circle.append((xi, yi, ri))

  startcircle = []
  targetcircle = []
  for i in range(N):
    xi, yi, ri = circle[i]
    if (sx - xi)**2 + (sy - yi)**2 == ri**2:
      startcircle.append(i)
    if (tx - xi)**2 + (ty - yi)**2 == ri**2:
      targetcircle.append(i)
  
  nextList = getNextList(circle, N)
  isVisited = [False] * N
  targetset = set(targetcircle)
  queue = deque()
  ans = False

  for start in startcircle:
    queue.append(start)
    isVisited[start] = True

  while queue:
    curr = queue.popleft()

    if curr in targetset:
      ans = True
      break
    
    for nxt in nextList[curr]:
      if not isVisited[nxt]: 
        isVisited[nxt] = True
        queue.append(nxt)
  
  print("Yes" if ans else "No")



