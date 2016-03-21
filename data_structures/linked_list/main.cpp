#include <iostream>

#include "include/linked_list.h"
#include "unit_test/linked_list_unit_test.h"

using namespace std;

int main(int argc, char** argv)
{
	linked_list_unit_test test;

	if (test.start_test())
		cout << "pass the unit test!" << endl;
	else
		cout << "fail the unit test!" << endl;

	return 0;
}
