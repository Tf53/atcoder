  
if __name__ == "__main__":
  N = int(input())
  edges = [[] for _ in range(N)]
  for _ in range(N - 1):
    Ai, Bi = map(int, input().split())
    Ai -= 1
    Bi -= 1
    edges[Ai].append(Bi)
    edges[Bi].append(Ai)


  def dfs(s):
    dist = [-1] * N
    dist[s] = 0

    st = [s]

    while st:
      curr = st.pop()
      for v in edges[curr]:
        if dist[v] == -1:
          st.append(v)
          dist[v] = dist[curr] + 1    
    return dist
  

  dist0 = dfs(0)
  mv = max(enumerate(dist0), key=lambda x: x[1])[0]
  distmv = dfs(mv)
  print(max(distmv) + 1)

  
  