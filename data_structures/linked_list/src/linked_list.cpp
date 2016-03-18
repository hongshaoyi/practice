#include <iostream>
#include <stdlib.h>

#include "../include/linked_list.h"

using namespace std;

linked_list::linked_list()
{
	head_node = init_link_node(0);
};

/*linked_list::linked_list(const linked_list &other_list)
{
	head_node = init_link_node(0);
	
	link_node* next_node = other_list.head_node.next_;
	
	if (next_node != NULL)
	{
		head_node->next_ = next_node;
		next_node->prev_ = head_node;

		reset_link_node(other_list.head_node);
	}
}*/

linked_list::~linked_list()
{
	link_node* delete_node = head_node;
	link_node* next_node = NULL;

	do
	{
		next_node = delete_node->next_;

		delete delete_node;
	}
	while (next_node != NULL);

	head_node = NULL;
}

bool linked_list::insert(const int _data)
{
	link_node* last_node = head_node;

	while (last_node->next_ != NULL)
		last_node = last_node->next_;

	link_node* new_node = init_link_node(_data);

	last_node->next_ = new_node;
	new_node->prev_ = last_node;

	return true;
}

bool linked_list::remove(const int _data)
{
	link_node* delete_node = head_node;
	bool result = false;

	while (delete_node->next_ != NULL)
	{
		delete_node = delete_node->next_;

		if (delete_node->data_ == _data)
		{
			delete_node->prev_->next_ = delete_node->next_;
			
			if (delete_node->next_ != NULL)
				delete_node->next_->prev_ = delete_node->prev_->next_;

			result = true;
		}
	}

	return result;
}

inline link_node* linked_list::init_link_node(const int _data)
{
	link_node* new_node = new link_node;

	if (new_node == NULL)
	{
		cout << "bad memory alloc!" << endl;
		abort();
		return NULL;
	}

	reset_link_node(*new_node);
	
	new_node->data_ = _data;

	return new_node;
}

inline void linked_list::reset_link_node(link_node &_reset_node)
{
	_reset_node.data_ = 0;
	_reset_node.prev_ = NULL;
	_reset_node.next_ = NULL;
}

