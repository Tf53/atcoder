
if __name__ == "__main__":
  H, W = map(int, input().split())
  A = [list(map(int, input().split())) for _ in range(H)]

  yoko = list(map(sum, A))
  tate = list(map(sum, zip(*A)))
  
  for i in range(H):
    print(' '.join(map(lambda j: str(yoko[i] + tate[j] - A[i][j]), range(W))))