/*
[差值法](https://leetcode.cn/problems/min-stack/solution/yigezhan-by-shaorui-tz5l/#:~:text=%E4%B8%8B%E4%B8%80%E9%A2%98%E8%A7%A3-,%E5%B7%AE%E5%80%BC%E6%B3%95%E2%80%94%E2%80%94%E4%B8%80%E4%B8%AA%E6%A0%88,-%E5%85%B3%E6%B3%A8%20TA)
*/
class MinStack {
    struct node{
        int data;
        struct node *next;
        node(int a): data(a),next(nullptr){};
    };
    node *tp;
    int min;
public:
    MinStack() {
        tp = nullptr;
        min = 0x7fffffff;
    }
    
    void push(int val) {
        node *t = new node(val);
        if(tp==nullptr){
            tp = t;
        }else{
            t->next=tp;
            tp = t;
        }
        min = val<min?val:min;
    }
    
    void pop() {
        node *t=tp;
        tp = tp->next;
        if(t->data==min){
            if(tp!=nullptr){
                node *p=tp;
                min = p->data;
                while(p){
                    min = p->data<min?p->data:min;
                    p = p->next;
                }
            }else min = 0x7fffffff;
        }
        delete t;
    }
    
    int top() {
        return tp->data;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */