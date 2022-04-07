/* 1. Using Priority Queue: TC: O(N)    SC:O(1) */
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

/*
2. Using Heap: TC: O(N)    SC:O(1)

class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
         make_heap(s.begin(), s.end());
        
         while (s.size() > 1) {
            int x = s.front();
            pop_heap(s.begin(), s.end());
            s.pop_back();
            
            int y = s.front();
            pop_heap(s.begin(), s.end());
            s.pop_back();
            
            if (x == y) continue;
            
            s.push_back(x - y);
            push_heap(s.begin(), s.end());
        }
        
        return s.size() ? s.front() : 0;
    }
};

3. Using sorting & replacing end no's by their diff.
    TC: O(NlogN) + (O(N) * O(NlogN)) ==> O(NlogN) + O(N^2logN)      SC: O(1)
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
*/