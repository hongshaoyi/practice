#include <iostream>
#include <stdlib.h>

#include "../include/linked_list.h"

using namespace std;

linked_list::linked_list()
{
	head_node_ = init_link_node(0);
};

/*linked_list::linked_list(const linked_list &other_list)
{
	head_node_ = init_link_node(0);
	
	link_node* next_node = other_list.head_node_.next_;
	
	if (next_node != NULL)
	{
		head_node_->next_ = next_node;
		next_node->prev_ = head_node_;

		reset_link_node(other_list.head_node_);
	}
}*/

linked_list::~linked_list()
{
	link_node* next_node = NULL;
	link_node* delete_node = head_node_;

	while (delete_node != NULL)
	{
		next_node = delete_node->next_;

		delete delete_node;

		delete_node = next_node;
	}

	head_node_ = NULL;
}

bool linked_list::insert(const int _data)
{
	link_node* last_node = head_node_;

	while (last_node->next_ != NULL)
		last_node = last_node->next_;

	link_node* new_node = init_link_node(_data);

	last_node->next_ = new_node;
	new_node->prev_ = last_node;

	return true;
}

bool linked_list::remove(const int _data)
{
	link_node* delete_node = head_node_;
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

bool linked_list::is_equal_array_list(const int* _array_list, const int _size)
{
	//because the array list can not have none elements, but the linked list can have none datas
	//so here is a deal, when the array list is null and the size is 0, it means that it has none elements, not the illegal input
	if (_array_list == NULL)
	{
		if (_size == 0)
			return head_node_->next_ == NULL ? true : false;
		else
		{
			cout << "the array is illegal!" << endl;

			return false;
		}
	}

	bool is_equal = true;
	link_node* check_node = head_node_->next_;

	for (int index = 0; index < _size; index++)
	{
		if (check_node == NULL || check_node->data_ != _array_list[index])
		{
			is_equal = false;
			
			cout << "the data is not equal!" << endl;
			
			break;
		}

		check_node = check_node->next_;
	}

	return is_equal;
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

