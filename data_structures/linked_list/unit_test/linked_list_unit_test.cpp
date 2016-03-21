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

void linked_list_unit_test::start_test()
{
	cout << "start the constructor test!" << endl;

	if (!new_test_list())
		cout << "test Constructor failed!" << endl;
	else
		cout << "pass the constructor test!" << endl;

	cout << "start the insert test!" << endl;
	
	if (!test_insert())
		cout << "test insert failed!" << endl;
	else
		cout << "pass the insert test!" << endl;

	cout << "start the remove test!" << endl;
	
	if (!test_remove())
		cout << "test remove failed!" << endl;
	else
		cout << "pass the remove test!" << endl;

	delete_test_list();

	cout << "all test done!" << endl;
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

	test_linked_list_->clear_all();

	return normal_insert_result;
}

bool linked_list_unit_test::test_remove()
{
	if(!is_init_test_obj())
		return false;

	int start_list[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int start_size = sizeof(start_list) / sizeof(int);
	
	bool insert_result = true;
	
	for (int index = 0; index < start_size; index++)
	{
		if (!test_linked_list_->insert(start_list[index]))
		{
			insert_result = false;
			
			cout << "insert failed!, insert index: " << index << "insert data: " << start_list[index] << endl;
			
			break;
		}
	}

	if (!insert_result)
		return false;

	int remove_list[] = {2, 8, 5, 10, 1, 9};
	int remove_size = sizeof(remove_list) / sizeof(int);

	bool remove_result = true;

	for (int index = 0; index < remove_size; index++)
	{
		if (!test_linked_list_->remove(remove_list[index]))
		{
			remove_result = false;

			cout << "remove failed!, remove index: " << index << "remove data: " << remove_list[index] << endl;

			break;
		}
	}

	if (!remove_result)
		return false;

	int final_list[] = {7, 6, 4, 3};
	int final_size = sizeof(final_list) / sizeof(int);

	bool normal_remove_result = test_linked_list_->is_equal_array_list(final_list, final_size);

	test_linked_list_->clear_all();
	
	return normal_remove_result;
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
