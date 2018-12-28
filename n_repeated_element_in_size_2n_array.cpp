/*

In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5

*/

/*
solution:
use a hash map to count the number of repeated times
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> hash_map;
        for (auto const value : A)
        {
            hash_map[value]++;
            if (hash_map[value]>1)
            {
                return value;
            }
        }
    }
};
