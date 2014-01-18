#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>

template<class T1, class T2>
struct node
{
	node(int level):level_(level) 
	{
		forward_ = new node*[level_];	
		for(int i = 0; i < level_; ++i)
			forward_[i] = NULL;
	}
	node (T1 key, T2 value, int level): key_(key), value_(value), level_(level) 
	{ 		
		forward_ = new node*[level_];	
		for(int i = 0; i < level_; ++i)
			forward_[i] = NULL;
	}
	virtual ~node() { delete [] forward_; }

	T1 key_;
	T2 value_;
	int level_;
	struct node **forward_;
};

template<class T1, class T2>
class skiplist
{
public:
	skiplist (int max_level = 12): max_level_(max_level) { 
		head_ = new node<T1, T2>(max_level_); 
	};
	virtual ~skiplist (){
		for(node_ptr tmp = head_->forward_[0]; tmp;){
			node_ptr next = tmp->forward_[0];
			delete tmp;
			tmp = next;
		}
	};
	T2 find(const T1& key) const;
	int insert(const T1& key, const T2& value);
	void remove(const T1& key);
	void traverse() const;

	typedef struct node<T1, T2>* node_ptr;
	
private:
	int new_level(double prob);

	node_ptr head_;
	int max_level_;
};

#include "skiplist.cpp"
#endif
