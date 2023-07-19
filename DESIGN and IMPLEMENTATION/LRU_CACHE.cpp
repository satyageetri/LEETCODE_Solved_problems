class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* prev ; Node* next;
        Node(int _key , int _val){
            key = _key;
            value = _val;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int , Node*> in_use;
    int size ;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head; 
    }


    void addnode(Node* newnode){
        //Node* temp = head;
        newnode->next = head->next;
        head->next->prev = newnode;
        head->next = newnode;
        newnode->prev = head;

    }

    void delnode(Node* delnode){
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        /*
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext ;
        delnext->prev = delprev ;
        */
    }

    int get(int key_) {
        if(in_use.find(key_) == in_use.end()){
            return(-1);
        }
        Node* temp = in_use[key_];
        int val = temp->value;
        in_use.erase(key_);
        delnode(temp);
        addnode(temp);
        in_use[key_] = head->next;
        return(val);
    }
    
    void put(int key_, int value_) {
        if(in_use.find(key_) != in_use.end()){
            Node* temp = in_use[key_];
            in_use.erase(key_);
            temp->value = value_;
            delnode(temp);
            addnode(temp);
            in_use[key_] = head->next;
            return ;
        }
        if(in_use.size() == size){
            in_use.erase(tail->prev->key);
            delnode(tail->prev);
        } 
        Node* temp = new Node(key_ , value_);
        in_use.erase(key_);
        addnode(temp);
        in_use[key_] = head->next;
        return;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */