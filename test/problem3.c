// Given a string s, return the longest palindromic substring in s.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    // Write your code here.
}

// Driver code
int main() {
    char s[] = "babad";
    char* result = longestPalindrome(s);
    printf("Longest Palindromic Substring: %s\n", result); // should return "bab" ("aba" is also a valid answer.)
    free(result); 
    return 0;
}