class MyStack {
public:
    queue<int> Q1;
    
    void push(int x) {
        Q1.push(x);
        for(int i=0; i<Q1.size()-1; i++){
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
        return Q1.size() == 0;
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