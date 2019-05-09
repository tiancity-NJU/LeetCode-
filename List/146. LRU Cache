/*
author: ypz
*/

struct DoubleListNode {
    // 定义双向链表
    pair<int, int> data;       
    DoubleListNode *pre;
    DoubleListNode *nxt;
    DoubleListNode(pair<int, int> x): data(x), pre(NULL), nxt(NULL) {}
};

class LRUCache { 
private:
    // 初始化双向链表的头指针，以及链表中现有元素的个数
    DoubleListNode *dummy = new DoubleListNode({0, 0});
    int size = 0;
    int limit;
    
public:  
    // 初始化容量
    LRUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        // 如果链表为空，则返回-1
        if(size == 0) return -1;
    
        DoubleListNode *tmp = dummy -> nxt;
        // 如果容量为1，则直接判断键是否相同并返回结果
        if(limit == 1) {
            if((tmp -> data).first == key) 
                return (tmp -> data).second;
            else
                return -1;
        }
        // 如果容量大于1
        while(tmp != NULL) {
            // 如果键相同，则将更改该键值对的位置，挪到链表的头部，并取出值
            if((tmp -> data).first == key) {
                DoubleListNode *ptmp = tmp -> pre;
                DoubleListNode *ndummy = dummy -> nxt;
                // 如果该键值对正好位于头部，则不用执行更改顺序的操作，直接取出值
                if(ptmp == dummy)
                    return (tmp -> data).second;
                // 如果该键值对正好位于尾部，则可以简化尾部的操作
                if(tmp -> nxt == NULL) 
                    ptmp -> nxt = NULL;
                else {
                    DoubleListNode *ntmp = tmp -> nxt;
                    ntmp -> pre = ptmp;
                    ptmp -> nxt = ntmp; 
                }
                tmp -> nxt = ndummy;
                dummy -> nxt = tmp;
                tmp -> pre = dummy;
                ndummy -> pre = tmp;
                return (tmp -> data).second;
            }
            // 如果键不同，则将指针指向下一个节点
            tmp = tmp -> nxt;
        }
        return -1;
    }
    
    void put(int key, int value) { 
        // 创建新节点
        DoubleListNode *node = new DoubleListNode({key, value});
        
        // 如果链表不为空，需插在虚拟节点和第一个节点之间；如果链表为空，则可以直接插在末尾
        if(size > 0) {
            DoubleListNode *ndummy = dummy -> nxt;
            // 如果容量大于1，还需注意后续操作
            if(limit > 1) {
                node -> nxt = ndummy;
                ndummy -> pre = node;
            }
            // 如果容量为1，删除刚定义的尾节点，简化后续操作
            else
                ndummy -> pre = NULL;
        }
        dummy -> nxt = node;
        node -> pre = dummy;
        // 插入完成，元素数量加一
        size++;
        // 如果容量为1，删除工作已在前面执行，直接跳出函数
        if(limit <= 1) return;
        
        // 如果容量大于1，需进行以下两部判断来决定是否删除工作
        // 首先判断链表中是否存在键相同的简直对，将相同的旧键对应的键值对删除
        DoubleListNode *tmp = node -> nxt;
        while(tmp != NULL) {
            // 判断键是否相同
            if((tmp -> data).first == key) {
                DoubleListNode *ptmp = tmp -> pre;
                // 若相同的键在中间
                if(tmp -> nxt != NULL) {
                    DoubleListNode *ntmp = tmp -> nxt;
                    ntmp -> pre = ptmp;
                    ptmp -> nxt = ntmp;
                }
                // 若相同的键在末尾
                else {
                    ptmp -> nxt = NULL;
                    tmp -> pre = NULL;
                }
                // 更新元素数量
                size--;
                return;
            }
            tmp = tmp -> nxt;
        }
        
        // 若没有相同的键，则判断元素数量是否超过容量，若超过则删除末尾元素
        if(size > limit) {
            DoubleListNode *lst = dummy;
            while(lst -> nxt != NULL)
                lst = lst -> nxt;
            DoubleListNode *plst = lst -> pre;
            lst -> pre = NULL;
            plst -> nxt = NULL;
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
