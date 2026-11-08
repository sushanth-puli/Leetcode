class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        haystack = haystack.split(needle, 1)
        if len(haystack) == 1:
            return -1
        return len(haystack[0])