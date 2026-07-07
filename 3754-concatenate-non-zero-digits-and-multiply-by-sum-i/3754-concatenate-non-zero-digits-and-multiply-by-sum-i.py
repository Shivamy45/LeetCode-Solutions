class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = sum = 0
        d = 1
        while(n):
            r = n % 10
            if(r != 0):
                x = r * d + x
                d *= 10
                sum += r
            n //= 10
        return sum * x
        