if __name__ == "__main__":
  T = int(input())
  for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int,input().split())
    d = (x1 - x2)**2 + (y1 - y2)**2
    r_diff = (r1 - r2)**2
    r_sum = (r1 + r2)**2
    if r_diff > d or r_sum < d:
      print("No")
    else:
      print("Yes")