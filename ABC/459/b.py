if __name__ == "__main__":
  N = int(input())
  S = list(input().split())

  ans = []
  for s in S:
    first = s[0]
    if('a' <= first and first <= 'c'):
      ans.append(2)
    elif('d' <= first and first <= 'f'):
      ans.append(3)
    elif('g' <= first and first <= 'i'):
      ans.append(4)
    elif('j' <= first and first <= 'l'):
      ans.append(5)
    elif('m' <= first and first <= 'o'):
      ans.append(6)
    elif('p' <= first and first <= 's'):
      ans.append(7)
    elif('t' <= first and first <= 'v'):
      ans.append(8)
    else:
      ans.append(9)
  
  print(*ans, sep='')
  