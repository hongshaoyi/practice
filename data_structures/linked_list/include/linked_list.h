#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct link_node
{
	int data_;
	link_node* prev_;
	link_node* next_;
};

class linked_list
{
public:
	linked_list();
//	linked_list(const linked_list &other_list);
	~linked_list();
//	linked_list& operator =(linked_list &other_list);

	bool insert(const int _data);
	bool remove(const int _data);

private:
	link_node* head_node;	//the head node will not contain any data, the first data is next to the head node

	inline link_node* init_link_node(const int _data);
	inline void reset_link_node(link_node &_reset_node);
};

#endif
