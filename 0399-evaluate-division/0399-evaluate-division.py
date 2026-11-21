class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:

        graph = {}
        res = []

        for i in range(len(equations)):
            a,b = equations[i]
            
            if a not in graph: graph[a] = []
            if b not in graph: graph[b] = []

            graph[a].append((b, values[i]))
            graph[b].append((a, 1/values[i]))
        
        def dfs(curr, target, product, visited):
            if curr == target: return product
            visited.add(curr)
            for nei, val in graph[curr]:
                if nei not in visited:
                    ans = dfs(nei, target, product * val, visited)
                    if ans != -1.0:
                        return ans
            
            return -1.0

           

        for x, y in queries:

            if x not in graph or y not in graph:
                res.append(-1.0)
            elif x == y: 
                res.append(1.0)
            else:
                ans = dfs(x, y, 1.0, set())
                res.append(ans)
        
        return res

        