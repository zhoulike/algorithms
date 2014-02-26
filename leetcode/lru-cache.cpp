struct list_{
	int key;
	int value;
	struct list_* prev;
	struct list_* next;
	list_(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
	list_() : prev(NULL), next(NULL) {}
};

class LRUCache{
public:
    LRUCache(int capacity) : cap(capacity), current(0) {
        head = new list_();
		head->next = head->prev = head;
    }
    
    int get(int key) {
        struct list_ *node = find(key);
		if(node){
			if(head->next != node){
				remove(node);
				insert(node);
			}
			return node->value;
		}
		return -1;
    }
    
    void set(int key, int value) {
        struct list_ *node = find(key);
		if(node){
			if(head->next != node){
				remove(node);
				insert(node);
			}
			node->value = value;
		} else {
			if(current != cap){
				node = new list_(key, value);
				insert(node);
				++current;
			} else {
				node = head->prev;
				node->key = key;
				node->value = value;
				remove(node);
				insert(node);
			}
		}
    }
    
private:
	void remove(struct list_ *node){
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void insert(struct list_ *node){
		node->next = head->next;
		node->prev = head;
		head->next = node;
		node->next->prev = node;
	}
	struct list_* find(int key){
		for(struct list_ *node = head->next; node != head; node = node->next)
			if(node->key == key){
				return node;
			}
		return NULL;
	}
	int cap;
	int current;
	struct list_ *head;
};