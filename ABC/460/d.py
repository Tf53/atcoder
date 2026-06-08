from collections import deque

if __name__ == "__main__":
  DIRECTIONS_8 = [
    (-1, -1), (-1, 0), (-1, 1),
    ( 0, -1),          ( 0, 1),
    ( 1, -1), ( 1, 0), ( 1, 1)
  ]
  H, W = map(int, input().split())
  bord = []
  d = [[-1] * W for _ in range(H)]
  isVisited = [[False] * W for _ in range(H)]

  for _ in range(H):
    S = input()
    bord.append(S)
  
  def getBlackAndInit():
    black = []
    for i in range(H):
      for j in range(W):
        if bord[i][j] == '#':
          black.append((i, j))
          bord[i][j] = '.'
    return black

  def next(x, y):
    list = []
    for rx, ry in DIRECTIONS_8:
      newx = rx + x
      newy = ry + y
      if 0 <= newx < W and 0 <= newy < W:
        list.append((newx, newy))
    return list
  
  def bfs(si, sj):
    isVisited[si][sj] = True
    nxt = next(si, sj)
    for si, sj in nxt:



  blacks = getBlackAndInit()


