'''
You are given a 0-indexed array of strings words and a 2D array of integers queries.
Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
'''


def vowelStrings(words, queries):
    # Write your code
    pass

# Driver Code
words1 = ["aba","bcb","ece","aa","e"]
queries1 = [[0,2],[1,4],[1,1]]
print(vowelStrings(words1, queries1)) # should return [2,3,0]

words2 = ["a","e","i"]
queries2 = [[0,2],[0,1],[2,2]]
print(vowelStrings(words2, queries2)) # should return [3,2,1]