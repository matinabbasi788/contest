class Solution:
    def romanToInt(self, s: str) -> int:
        ans = 0
        i = 0
        while i < len(s):
            if i < len(s) - 1:
                if s[i]+s[i+1] == 'IV':
                    ans += 4
                    i += 2
                    continue
                elif s[i]+s[i+1] == 'IX':
                    ans += 9
                    i += 2
                    continue
                elif s[i]+s[i+1] == 'XL':
                    ans += 40
                    i += 2
                    continue
                elif s[i]+s[i+1] == 'XC':
                    ans += 90
                    i += 2
                    continue
                elif s[i]+s[i+1] == 'CD':
                    ans += 400
                    i += 2
                    continue
                elif s[i]+s[i+1] == 'CM':
                    ans += 900
                    i += 2
                    continue
                if i >= len(s):
                    break
            if s[i] == 'I':
                ans += 1
                i += 1
            elif s[i] == 'V':
                ans += 5
                i += 1
            elif s[i] == 'X':
                ans += 10
                i += 1
            elif s[i] == 'L':
                ans += 50
                i += 1
            elif s[i] == 'C':
                ans += 100
                i += 1
            elif s[i] == 'D':
                ans += 500
                i += 1
            elif s[i] == 'M':
                ans += 1000
                i += 1
        return ans


c = Solution()
res = c.romanToInt("MCMXCIV")
print(res)
