if __name__ == "__main__":
  X = int(input())
  X -= 1

  S = [c for c in "HelloWorld"]
  S.pop(X)
  print(*S, sep='')