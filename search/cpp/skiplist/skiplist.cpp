#include "skiplist.h"
#include <cstdlib>

template<class T1, class T2>
T2 skiplist<T1, T2>::find(const T1& key) const
{	
	//need to modify to support find fail!
	node_ptr tmp = head_;
	int level = max_level_;

	while(level--){
		while(tmp->forward_[level] && tmp->forward_[level]->key_ <= key)
			tmp = tmp->forward_[level];	
		
		if(tmp->key_ == key)
			return tmp->value_;
	}
}

template<class T1, class T2>
int skiplist<T1, T2>::insert(const T1& key, const T2& value)
{
	node_ptr added = new node<T1, T2>(key, value, new_level(0.5));
	node_ptr update[max_level_];
	node_ptr tmp = head_;
	int level = max_level_;

	while(level--){
		while(tmp->forward_[level] && tmp->forward_[level]->key_ < key)
			tmp = tmp->forward_[level];	
		update[level] = tmp;
	}

	if(update[0]->forward_[0] && update[0]->forward_[0]->key_ == key)
		return -1;

	for(int i = 0; i < added->level_; ++i){
		added->forward_[i] = update[i]->forward_[i];
		update[i]->forward_[i] = added;
	}
	return 0;
}
	
template<class T1, class T2>
void skiplist<T1, T2>::remove(const T1& key)
{
	node_ptr update[max_level_];
	node_ptr tmp = head_;
	int level = max_level_;

	while(level--){
		while(tmp->forward_[level] && tmp->forward_[level]->key_ < key)
			tmp = tmp->forward_[level];	
		
		update[level] = tmp;
	}

	tmp = update[0]->forward_[0];
	if(!tmp || tmp->key_ != key)
		return;

	for(int i = 0; i < tmp->level_; ++i)
		update[i]->forward_[i] = tmp->forward_[i];

	free(tmp);
}


template<class T1, class T2>
int skiplist<T1, T2>::new_level(double prob)
{
	int level = 1;
	while(level < max_level_ && (1.0 * std::rand()) / RAND_MAX <= prob)
		++level;	
	return level;
}

template<class T1, class T2>
void skiplist<T1, T2>::traverse() const
{
	int level = max_level_;
	while(level--){
		if (head_->forward_[level] == NULL)
			continue;

		std::cout << "level: " << level << std::endl;
		for(node_ptr tmp = head_->forward_[level]; tmp != NULL; tmp = tmp->forward_[level]){
			std::cout << tmp->key_ << " -> ";
		}
		std::cout << std::endl;
	}
}
