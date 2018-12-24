/*
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"], and the remaining columns of A are ["b","v"], ["e","y"], and ["f","z"].  (Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]].)

Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A is in non-decreasing sorted order.

Return the minimum possible value of D.length.

Example:

Input: ["cba","daf","ghi"]
Output: 1
Explanation: 
After choosing D = {1}, each column ["c","d","g"] and ["a","f","i"] are in non-decreasing sorted order.
If we chose D = {}, then a column ["b","a","h"] would not be in non-decreasing sorted order.
*/

/*
Solution:
If found one column non-sorted, just delete it
*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // number of rows
        int rows = A.size();
        // number of columns
        int cols = A[0].size();
        vector<int> D;
        // for each column j, loop rows i, compare i and i-1
        // if non_dec exists, then mark j and increase the size of D
        for (int j = 0; j < cols; j++) {
            bool non_dec = false;
            for (int i = 1; i < rows; i++) {
                if (A[i-1][j] > A[i][j]) {
                    non_dec = true;
                    break;
                }
            }
            if (non_dec) D.push_back(j);
        }
        
        return D.size();
    }
};
