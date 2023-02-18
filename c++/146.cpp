/*
[哈希+双向链表](https://leetcode.cn/problems/lru-cache/comments/#:~:text=c%2B%2B%2C%20%E5%8F%8C%E5%90%91%E9%93%BE%E8%A1%A8%E4%B8%8Ehashmap%E7%BB%84%E5%90%88%EF%BC%8C%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6O%EF%BC%881%EF%BC%89%2C%20%E8%AF%A6%E7%BB%86%E7%9C%8B%E6%B3%A8%E9%87%8A)

查询复杂度：map：O(logn)
	unordered_map: O(1)
*/
class LRUCache {
    //结点结构：双向链表，键值对
    struct DList {
        DList* pre;
        DList* next;
        int key, value;
        DList(int key,int value): key(key),value(value),pre(NULL),next(NULL) {};
    };

    //链表头尾结点，均不存储数据
    DList* head, *tail;
    unordered_map<int, DList*> mp;
    int capacity;
    //mp的数据量
    int size;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new DList(-1,-1);
        tail = new DList(-1,-1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            DList* node = mp[key];
            remove(node);
            push(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            DList* node = mp[key];
            remove(node);
            push(node);
            node->value = value;
            return;
        }
        if(size==capacity){
            int top = head->next->key;
            remove(head->next);
            mp.erase(top);
        }
        DList* node = new DList(key,value);
        push(node);
        mp[key] = node;
    }

    void remove(DList* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        size--;
    }

    void push(DList* node){
        node->pre = tail->pre;
        tail->pre->next = node;
        node->next = tail;
        tail->pre = node;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */