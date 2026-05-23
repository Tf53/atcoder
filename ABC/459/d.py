if __name__  == "__main__":
  T = int(input())

  def solve():
    s = input()
    n = len(s)

    cnt = [0] * 26

    for c in s:
      cnt[ord(c) - ord('a')] += 1
    
    for i in range(26):
      if cnt[i] > (n + 1) // 2:
        print("No")
        return
      
    ans = []
    pre = -1
    while True:
      dev = 0
      idx = -1
      for i in range(26):
        if pre == i:
          continue
        if dev < cnt[i]:
          idx = i
          dev = cnt[i]
      if idx == -1:
        break
      ans.append(chr(ord('a') + idx))
      cnt[idx] -= 1
      pre = idx
      
    print("Yes")
    print(*ans, sep='')


  for _ in range(T):
    solve()
    