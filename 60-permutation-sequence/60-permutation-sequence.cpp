class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string ans = "";
        vector<int> number;
        // Running the loop from (1 -> n-1)
        for(int i=1; i < n; i++){
            fact = fact * i;
            number.push_back(i);
        }
        number.push_back(n);            // Adding the last no. into the vector.
        
        // Since our algorithm runs on 0-based indexing (i.e., For k=17 --> 16th element from 0)
        k = k - 1;
        while(true){
            ans = ans + to_string(number[k/fact]);  // Picking the 1st element & storing into the string.
            number.erase(number.begin() + k/fact);  // Removing the element we currently stored.
            
            if(number.size() == 0)  break;
            k = k % fact;
            fact = fact / number.size();       // fact = (currFactorial / no. of remaining ele in the vector)
        }
        return ans;
    }
};