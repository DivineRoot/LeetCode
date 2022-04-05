class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxCapacity = 0, capacity = 0, left = 0, right = height.size()-1;
        while(left < right){
            int distance = right - left;
            if(height[left] > height[right]){
                capacity = height[right]*distance;
                right--;
            }
            else{
                capacity = height[left]*distance;
                left++;
            }
            maxCapacity = max(maxCapacity, capacity);
        }
        return maxCapacity;
    }
};