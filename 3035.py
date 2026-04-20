class Solution:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        # count every letter pair
        # we don't care about individuals because we are guaranteed to have enough letters
        seen_letters = [False] * 26
        pairs = 0
        for word in words:
            for letter in word:
                index = ord(letter) - ord("a")
                seen_letters[index] = not seen_letters[index]

                # we've seen this letter twice, so it's a pair
                if not seen_letters[index]:
                    pairs += 1

        # sort words shortest to longest, since we want to use as few pairs as possible
        words.sort(key=lambda x: len(x))
        for i in range(len(words)):
            word_len = len(words[i])

            # subtract from pairs by the word length
            pairs -= word_len // 2
  
            # if we ran out of pairs, it is no longer possible to make palindromes
            # our final answer is the index, not including the word we are on
            if pairs < 0:
                return i

        # if we got through without ending early, all words can be palindromes
        return len(words)
