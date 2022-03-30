class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)  return false;       //If matrix is empty.
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0, end = (m*n) -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(matrix[mid/n][mid%n] == target)
                return true;
            if(matrix[mid/n][mid%n] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return false;
    }
};

/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};
*/