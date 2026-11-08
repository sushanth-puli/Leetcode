class Solution:

    def letterCombinations(self, digits: str) -> list[str]:
        # Because our keys are sequential integers, we can just 
        # use a list for the lookup table
        mapping = [["a", "b", "c"],
        ["d", "e", "f"],
        ["g", "h", "i"],
        ["j", "k", "l"],
        ["m", "n", "o"],
        ["p", "q", "r", "s"],
        ["t", "u", "v"],
        ["w", "x", "y", "z"]]
        
        # accumulate the output by repeatedly taking 
        # the Cartesian product

        output = []
        for digit in digits:
            digit = int(digit)
            if not output:
                # On the first iteration, add the letters for the first digit
                # Subtract 2 from digit to get the corresponding list index
                output += mapping[digit-2]
            else:
                # On subsequent iterations, take
                # Cartesian product of existing output 
                # and next digit's letters
                output = [f"{a}{b}" for a in output for b in mapping[digit-2]]
        return output