class MyStack {                                   //                | 5 |  | 5 |<-- Top of 'STACK'
public:                                           //                | 3 |  | 3 |
    queue<int> Q1;                                // front of Que-->| 2 |  | 2 |
    
    void push(int x) {                                      // For val: 2 -> 3 -> 5
        Q1.push(x);                                         // [ 2 ] -> [ 2 3 ] -> [ 2 3 5 ]
        for(int i=0; i<Q1.size()-1; i++){                   // [ 2 ] -> [ 3 2 ] -> [ 5 3 2 ] --> stack 
            Q1.push(Q1.front());
            Q1.pop();
        }
    }
    
    int pop() {
        int x = Q1.front();
        Q1.pop();
        return x;
    }
    
    int top() {
        return Q1.front();
    }
    
    bool empty() {
        return Q1.empty();              // return Q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */