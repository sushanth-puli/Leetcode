class ProductOfNumbers:

    def __init__(self):
        self.pref = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.pref = [1]
        else:
            self.pref.append(self.pref[-1] * num)

    def getProduct(self, k: int) -> int:
        n = len(self.pref)
        if k >= n:
            return 0
        return self.pref[-1] // self.pref[n - k - 1]
