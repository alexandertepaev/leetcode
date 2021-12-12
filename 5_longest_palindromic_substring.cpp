/*
    5. Longest Palindromic Substring
    Given a string s, return the longest palindromic substring in s.

    https://leetcode.com/problems/longest-palindromic-substring/

    Results: 
        Runtime: 12 ms, faster than 93.39% of C++ online submissions.
        Memory Usage: 7.6 MB, less than 70.60% of C++ online submissions.
*/
#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
string longestPalindrome(string s)
{
    string palindrome;
    
    for(int i = 0; i < s.length(); i++)
    {
        // Find size of the sequence of identical chars
        int seqsize = 1;
        for(int j = i + 1; j < s.length() && s[i] == s[j]; j++)
        {
            seqsize++;
        }
        
        // Center around this sequnce, increment the size of the frame
        // until we encounter a counterexample
        int offset = 0;
        while(i - offset - 1 >= 0 && 
              i + seqsize + offset < s.length() &&
              s[i - offset - 1] == s[i + seqsize + offset])
        {
            offset++;
        }
        
        // Check if size of the found candidate is greater
        // than the size of the current one
        if(seqsize + offset * 2 > palindrome.length())
        {
            palindrome = s.substr(i - offset, seqsize + offset * 2);
        }
    }
    
    return palindrome;
}
};

int main(int argc, char const *argv[])
{
    Solution sol;

    cout << sol.longestPalindrome(string("babad")) << '\n';
    cout << sol.longestPalindrome(string("cbbd")) << '\n';
    cout << sol.longestPalindrome(string("a")) << '\n';
    cout << sol.longestPalindrome(string("ac")) << '\n';
    return 0;
}