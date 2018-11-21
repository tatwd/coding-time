#include "list.h"

int main()
{
	int arr[5] = { 1, 2, 3, 4,5 };
	list_node *list = array2list(arr, 5);
	print_list(list);
	empty(list);
}
