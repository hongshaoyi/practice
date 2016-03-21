#ifndef __LINKED_LIST_UNIT_TEST_H__
#define __LINKED_LIST_UNIT_TEST_H__

class linked_list;

class linked_list_unit_test
{
public:
	linked_list_unit_test();
	~linked_list_unit_test();

	bool start_test();

private:
	linked_list* test_linked_list_;

	bool test_insert();
	bool test_remove();
	
	inline bool new_test_list();
	inline void delete_test_list();
	inline bool is_init_test_obj();
};

#endif
