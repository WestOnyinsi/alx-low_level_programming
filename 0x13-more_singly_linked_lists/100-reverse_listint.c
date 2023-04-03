#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listintx *reverse_listint(listintx **head)
{
 listintx *prev = NULL;
 listintx *next = NULL;

 while (*head)
 {
 next = (*head)->next;
 (*head)->next = prev;
 prev = *head;
 *head = next;
 }

 *head = prev;

 return (*head);
}
