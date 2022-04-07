/*
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x != y)  pq.push(y - x);
        }
        return pq.empty()? 0 : pq.top(); 
    }
};
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        for(int i = n-1; i>0; i--){
            stones[i-1] = stones[i] - stones[i-1];
            sort(stones.begin(), stones.end());
        }
        return stones[0];
    }
};
