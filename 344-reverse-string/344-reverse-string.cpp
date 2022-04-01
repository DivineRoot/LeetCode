class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> ans;
        int end = s.size() - 1;
        int n = s.size()/2;
        for(int i = 0 ; i<n ; i++){
            char temp = s[i];
            s[i] = s[end];
            s[end] = temp;
            end--;
        }
    }
};