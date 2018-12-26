/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        // C++ STL
        // return bitset<32>(x^y).count();
        
        int xy = x ^ y;                 // exclusive OR, 1+0 = 1, 1+1=0, 0+0=0, xy: 1, different bits, xy: 0, same bits
        int num_of_diff_bits = 0;
  
        while (xy > 0) {
            num_of_diff_bits += xy & 1; // if the last digit of xy is 1 (different bits), add 1
            xy >>= 1;                   // shift xy to the right by one bit for the next & comparison with 1
        } 
  
        return num_of_diff_bits; 
    }
};
