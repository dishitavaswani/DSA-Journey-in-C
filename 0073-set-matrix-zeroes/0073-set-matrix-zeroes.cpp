class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        set<int> rowSet;
        set<int> colSet;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                if(rowSet.count(i) || colSet.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};