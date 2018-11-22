#include "list.h"

int main()
{
	int arr[5] = { 1, 2, 3, 4,5 };

	list *li = array2list(arr, 5);
	print_list(li);

	insert(li, 0, 12);
	print_list(li);

	remove_node(li, 12);
	print_list(li);

	list_node *node = find(li, 3);
	print_list(node);

	empty(li);
}
