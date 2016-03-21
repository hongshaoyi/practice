#include <iostream>

#include "linked_list_unit_test.h"
#include "../include/linked_list.h"

using namespace std;

linked_list_unit_test::linked_list_unit_test() : test_linked_list_(NULL)
{
}

linked_list_unit_test::~linked_list_unit_test()
{
	delete_test_list();
}

bool linked_list_unit_test::start_test()
{
	if (!new_test_list())
	{
		cout << "test Constructor failed!" << endl;

		return false;
	}

	if (!test_insert())
	{
		cout << "test insert failed!" << endl;

		return false;
	}

	delete_test_list();
}

bool linked_list_unit_test::test_insert()
{
	if (!is_init_test_obj())
		return false;

	int test_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(test_list) / sizeof(int);
	bool insert_result = true;
	
	for (int index = 0; index < size; index++)
	{
		if (!test_linked_list_->insert(test_list[index]))
		{
			insert_result = false;
			
			cout << "insert failed!, insert index: " << index << "insert data: " << test_list[index] << endl;
			
			break;
		}
	}

	if (!insert_result)
		return false;

	bool normal_insert_result = test_linked_list_->is_equal_array_list(test_list, size);

	return normal_insert_result;
}

bool linked_list_unit_test::test_remove()
{
	if(!is_init_test_obj())
		return false;

	int test_list[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int size = sizeof(test_list) / sizeof(int);
	bool insert_result = true;
	
	for (int index = 0; index < size; index++)
	{
		if (!test_linked_list_->insert(test_list[index]))
		{
			insert_result = false;
			
			cout << "insert failed!, insert index: " << index << "insert data: " << test_list[index] << endl;
			
			break;
		}
	}

	if (!insert_result)
		return false;

	return true;
}

inline bool linked_list_unit_test::new_test_list()
{
	delete_test_list();

	test_linked_list_ = new linked_list();

	if (test_linked_list_ == NULL)
	{
		cout << "bad alloc!" << endl;

		return false;
	}

	return true;
}

inline void linked_list_unit_test::delete_test_list()
{
	if (test_linked_list_ != NULL)
	{
		delete test_linked_list_;

		test_linked_list_ = NULL;
	}
}

inline bool linked_list_unit_test::is_init_test_obj()
{
	bool result = true;

	if (test_linked_list_ == NULL)
	{
		result = false;
		
		cout << "you must init the data first!" << endl;
	}

	return result;
}
