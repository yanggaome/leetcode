/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example:
Input: "Hello"
Output: "hello"
*/

class Solution {
public:
    string toLowerCase(string str) {
        string lowercase;
        for (auto c : str) {
            lowercase+=tolower(c);
        }
        return lowercase;
    }
};
