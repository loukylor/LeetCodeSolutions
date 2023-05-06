class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        num_map = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}

        # Start with empty string as curr_letters,
        # since it will get removed and not affect the outcome
        curr_letters = [""]
        for digit in digits:
            # Loop through possible letters and add them to curr letters        
            for _ in range(len(curr_letters)):
                
                # Remove the current letter and use that in later loop
                curr_letter = curr_letters.pop(0)
                for possible_letter in num_map[digit]:
                    curr_letters.append(curr_letter + possible_letter)
        return curr_letters
