class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        if n < 10:
            return []
        seen = set()
        ans = set()
        current = s[:10]
        seen.add(current)
        for i in range(10, n):
            current = current[1:] + s[i]
            if current in seen:
                ans.add(current)
            else:
                seen.add(current)
        return list(ans)

        