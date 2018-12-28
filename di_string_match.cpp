/*
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
 

Example 1:

Input: "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: "III"
Output: [0,1,2,3]
Example 3:

Input: "DDI"
Output: [3,2,0,1]
 

Note:

1 <= S.length <= 10000
S only contains characters "I" or "D".
*/

/*
always push the current smallest or largest value according to the current character is I or D
ad hoc or greedy
*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        const int N = S.length();
        vector<int> A;
        int lo = 0;
        int hi = N;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == 'I') // A[i] < A[i+1]
            {
                A.push_back(lo++); // A.push_back(lo), then lo++
            }
            else // S[i] == 'D', A[i] > A[i+1]
            {
                A.push_back(hi--); // A.push_back(hi), then hi--
            }
        }
        
        A.push_back(lo); // it does not matter to put hi or lo for the last element
        
        return A; 
    }
};
