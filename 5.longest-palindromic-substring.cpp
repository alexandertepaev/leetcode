/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
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
// @lc code=end

