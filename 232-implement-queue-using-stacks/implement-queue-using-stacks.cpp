class MyQueue {
public:
    stack<int> st1,st2;
    int working;
    MyQueue() {
        working=1;
    }
    
    void push(int x) {
        if(working==1){
            st1.push(x);
        }
        else{
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
            working=1;
            push(x);
        }
    }
    
    int pop() {
        if(working==1){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            working=2;
        }
        int ele=st2.top();
        st2.pop();
        return ele;
    }
    int peek() {
        if(working==1){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            working=2;
        }
        int ele=st2.top();
        return ele;
    }
    
    bool empty() {
        if(working==1 && !st1.empty()) return false;
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */