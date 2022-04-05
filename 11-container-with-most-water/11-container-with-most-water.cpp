class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxCapacity = 0, left = 0, right = height.size()-1;
        while(left < right){
            //int distance = right - left;
            //int capacity = min(height[left], height[right]) * distance;
            maxCapacity = max(maxCapacity, min(height[left], height[right]) * (right - left));
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return maxCapacity;
    }
};