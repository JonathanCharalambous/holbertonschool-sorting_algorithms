#include "sort.h"

/**
 * insertion_sort_list - sorts an array usiing insertion sort
 * @list: the list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	cur = (*list)->next;
	while (cur)
	{
		temp = cur;
		cur = cur->next;

		while (temp->prev && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
		}
	}
}
