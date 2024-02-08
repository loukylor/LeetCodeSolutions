class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head_ = nullptr;
        keys_ = {};
    }

    ~LRUCache() {
        if (head_ == nullptr) {
            return;
        }
        Node* curr = head_-> next;
        while (curr != head_) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
        delete head_;
        head_ = nullptr;
    }
    
    int get(int key) {
        if (keys_.count(key) == 0) {
            return -1;
        }
        use(keys_[key]);
        return keys_[key]->value;
    }
    
    void put(int key, int value) {
        // Replace head on empty node
        if (head_ == nullptr) {
            head_ = new Node{key, value, nullptr, nullptr};
            head_->last = head_;
            head_->next = head_;
            keys_[key] = head_;
            return;
        }

        Node* node;
        if (keys_.count(key) == 0) {
            // Create new node if not present in the cache
            node = new Node{key, value, nullptr, nullptr};
            keys_[key] = node;
        } else {
            // Else grab the node from the cache
            node = keys_[key];
            node->value = value;
        }

        use(node);
    }

private:
    struct Node 
    {
        int key;
        int value;
        Node* next;
        Node* last;
    };
    Node* head_;
    map<int, Node*> keys_;
    int capacity_;

    void use(Node* node) {
        // Move updated node to the front        
        if (node != head_) {
            // If not, move node to front and make it head

            // Remove node
            if (node->last != nullptr) {
                node->last->next = node->next;
                node->next->last = node->last;
            }

            // Make node head
            node->next = head_;
            head_->last->next = node;
            node->last = head_->last;
            head_->last = node;
            head_ = node;
        }

        // Remove least recently used entry
        if (keys_.size() > capacity_) {
            Node* last_node = head_->last;
            head_->last = last_node->last;
            last_node->last->next = head_;
            keys_.erase(last_node->key);
            delete last_node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */