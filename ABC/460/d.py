if __name__ == "__main__":
  DIRECTIONS_8 = [
    (-1, -1), (-1, 0), (-1, 1),
    ( 0, -1),          ( 0, 1),
    ( 1, -1), ( 1, 0), ( 1, 1)
  ]
  H, W = map(int, input().split())
  bord = []
  for _ in range(H):
    S = input()
    bord.append(S)
  
  def getBlack():
    black = []
    for i in range(H):
      for j in range(W):
        if bord[i][j] == '#':
          black.append((i, j))
    return black

  def next8(x, y):
    list = []
    for rx, ry in DIRECTIONS_8:
      newx = rx + x
      newy = ry + y
      if 0 <= newx < W and 0 <= newy < W:
        list.append((newx, newy))
    return list

  def getWhite(black):
    white = []
    for b in black:
      for nx, ny in next8(b[0], b[1]):
        white.append((nx, ny))
    return set(white)

  blacks = getBlack()
  whiteTable = [[False] * W for _ in range(H)]


