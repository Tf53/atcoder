if __name__ == "__main__":
  N, M = map(int, input().split())

  count = 0
  while True:
    if M == 0:
      break
    M = N % M
    count += 1
  print(count)