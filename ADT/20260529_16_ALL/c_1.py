if __name__ == "__main__":
  N = int(input())
  A = list(map(int, input().split()))

  appearN = [0] * N

  def method(A):
    for v in A:
      appearN[v - 1] += 1
      if appearN[v - 1] == 2:
        print(v)

  method(A) 