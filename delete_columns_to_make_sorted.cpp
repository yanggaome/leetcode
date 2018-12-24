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
