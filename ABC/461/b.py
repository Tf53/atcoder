if __name__ == "__main__":
  N = int(input())
  A = list(map(int,input().split()))
  B = list(map(int,input().split()))

  check = True
  for i in range(N):
    if B[A[i] - 1] != i + 1:
      check = False
  print("Yes" if check else "No")
