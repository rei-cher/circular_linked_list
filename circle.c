/**
 * Circularly linked list.
 * Duplicate values should be rejected.
 * This list does not own any of the void pointers passed to it.
 * The free function is not mandatory on creation.
 * The comp function is mandatory on creation.
 * The iter function is mandatory for the iter function.
 * Data should be inserted into this list in sorted order.
 * This list doesn't need to keep track of the head, since all nodes point both
 * forward and backwards you can just keep track of any node (or the last one
 * that was inserted) and you can get to any other node. This way your list is
 * "circular". If you keep track of a head and tail pointer and the tail just
 * points back to the head, that's not really "circular".
 */

#include <stdio.h>
#include <stdlib.h>

#include "circle.h"

typedef struct node node_t;

// struct that holds node data and next pointer
struct node
{
    struct node * p_next;
    struct node * p_prev;
    void *        p_ptr;
};

// struct that holds the linked list elements
struct circle
{
    node_t * p_ptr;
    free_f   p_free;
    comp_f   p_comp;
    int      size;
};

// TODO: static function prototypes here
static void remove_node(circle_t * p_circle);

circle_t * circle_create(free_f p_free, comp_f p_comp)
{
	circle_t * p_new_llist = calloc(1, sizeof(circle_t));

	if (NULL == p_new_llist)
	{
		goto END;
	}

	p_new_llist->p_ptr = NULL;
	p_new_llist->p_free = p_free;
	p_new_llist->p_comp = p_comp;
	p_new_llist->size = 0;

END:
	return p_new_llist;
}

void circle_destroy(circle_t ** pp_circle)
{
	if ((NULL == (* pp_circle)) ||
		(0 == (* pp_circle)->size))
	{
		goto END;
	}

	while (0 != (* pp_circle)->size)
	{
		remove_node((* pp_circle));
	}

	free((* pp_circle));
	(* pp_circle) = NULL;

END:
	return;
}

int circle_add(circle_t * p_circle, void * p_data)
{
	int SUCCESS = 1;

	if ((NULL == p_circle) ||
		(NULL == p_circle->p_comp))
	{
		goto END;
	}
		
	struct node * p_new_node = calloc(1, sizeof(struct node));

	if (NULL == p_new_node)
	{
		goto END;
	}

	p_new_node->p_ptr = p_data;

	if (NULL == p_circle->p_ptr)
	{
		p_new_node->p_next = p_new_node;
		p_new_node->p_prev = p_new_node;

		p_circle->p_ptr = p_new_node;
	}
	else
	{
		struct node * p_current = p_circle->p_ptr;

		while (0 > p_circle->p_comp(p_current->p_ptr, p_data))
		{
			p_current = p_current->p_prev;
		}

		struct node * p_tmp = p_current->p_prev;
		
		p_current->p_prev = p_new_node;
		p_new_node->p_prev = p_tmp;
		p_tmp->p_next = p_new_node;
		p_new_node->p_next = p_current;
	}
	
	p_circle->size++;
	SUCCESS = 0;
END:
	return SUCCESS;
}

int circle_remove(circle_t * p_circle, void * p_data)
{
	int SUCCESS = 1;

	if ((NULL == p_circle) ||
		(NULL == p_data) ||
		(NULL == p_circle->p_comp) ||
		(NULL == p_circle->p_ptr))
	{
		goto END;
	}

	struct node * p_current = p_circle->p_ptr;

	while (0 != p_circle->p_comp(p_current->p_ptr, p_data))
	{
		p_current = p_current->p_next;
	}

	struct node * p_prev_current = p_current->p_prev;
	struct node * p_next_current = p_current->p_next;

	p_prev_current->p_next = p_next_current;
	p_next_current->p_prev = p_prev_current;

	p_circle->p_free(p_current->p_ptr);
	free(p_current);

	p_circle->size--;

	SUCCESS = 0;
END:
	return SUCCESS;
}

int circle_size(circle_t * p_circle)
{
	int size = 0;

	if ((NULL == p_circle) ||
		(NULL == p_circle->p_ptr))
	{
		goto END;
	}

	size = p_circle->size;

END:
	return size;
}

int circle_contains(circle_t * p_circle, void * p_data)
{
	int SUCCESS = 1;
	int found = 0;

	if ((NULL == p_circle) ||
		(NULL == p_data) ||
		(NULL == p_circle->p_ptr) ||
		(NULL == p_circle->p_comp))
	{
		goto END;
	}

	struct node * p_current = p_circle->p_ptr;
	
	do
	{
		if (0 == p_circle->p_comp(p_current->p_ptr, p_data))
		{
			found = 1;
			SUCCESS = 0;
		}
		p_current = p_current->p_next;
	} while (0 == found);

END:
	return SUCCESS;
}

int circle_iter(circle_t * p_circle, iter_f p_iter)
{
	int SUCCESS = 1;

	if ((NULL == p_circle) ||
		(NULL == p_circle->p_ptr) ||
		(NULL == p_circle->p_comp))
	{
		goto END;
	}

	struct node * p_start = p_circle->p_ptr;
	struct node * p_current = p_start;

	do
	{
		p_iter(p_current->p_ptr);
		p_current = p_current->p_next;
	} while (p_start != p_current);

	SUCCESS = 0;

END:
	return SUCCESS;
}

// TODO: static function definitions here
static void remove_node(circle_t * p_circle)
{
	if ((NULL == p_circle) ||
		(NULL == p_circle->p_ptr) ||
		(0 == p_circle->size))
	{
		goto END;
	}



END:
	return;
}

// end of circle.c
