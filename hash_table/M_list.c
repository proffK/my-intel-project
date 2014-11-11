#include <stdio.h>
#include <stdlib.h>
#include "M_list.h"
#include <string.h>
#include <errno.h>

list* list_create(void){
	
	list* new_list = (list*) calloc (1, sizeof(list));
	
	if (new_list == NULL) {
		
		errno = ENOMEM;
		abort();
		
	}
	
	return new_list;
} 

int list_delete(list* deleted_list){
	
	if (deleted_list != NULL) {
		
		free(deleted_list);
		deleted_list = NULL;
		return 0;
		
	}
	return -1;
}
	


struct list_elem* add_elem(list* lst, elem_t* new_elem, elem_t* (*cpy) (elem_t*, elem_t*)){
	
	if (list_valide(lst)) {
	
	struct list_elem* new_list_elem = (struct list_elem*) calloc (1, sizeof(struct list_elem));
	
	if (new_list_elem == NULL) {
		
		errno = ENOMEM;
		abort();
		
	}
	
	cpy(&(new_list_elem -> data), new_elem);
	new_list_elem -> prev = lst -> head;
	lst -> head = new_list_elem;
	++(lst -> size);
	
	if (lst -> size == 0) {
		
		lst -> tail = new_list_elem;
		
	}
	
	return new_list_elem;	
	
	}
	
	return 0;
}

struct list_elem* insert_elem(list* lst, elem_t* new_elem, struct list_elem* next_elem,\
						elem_t* (*cpy) (elem_t*, elem_t*)){
							
	if (list_valide(lst)) {
	
	struct list_elem* new_list_elem = (struct list_elem*) calloc (1, sizeof(struct list_elem));
	
	if (new_list_elem == NULL) {
		
		errno = ENOMEM;
		abort();
		
	}
	
	if (next_elem -> prev == NULL) {
		
		cpy(&(new_list_elem -> data), new_elem);
		next_elem -> prev = new_list_elem;
		new_list_elem -> next = next_elem;
		lst -> tail = new_list_elem;
		++(lst -> size);
		
		return new_list_elem;
	}
	
	cpy(&(new_list_elem -> data), new_elem);
	new_list_elem -> prev = next_elem -> prev;
	next_elem -> prev -> next = new_list_elem;
	next_elem -> prev = new_list_elem;
	new_list_elem -> next = next_elem;
	lst -> head = new_list_elem;
	++(lst -> size);
	
	return new_list_elem;	
	
	}
	
	return 0;
	
}

struct list_elem* delete_elem(list* lst, struct list_elem* deleted_elem);

struct list_elem* find_elem(list* lst, elem_t finded_elem, int (*cmp) (elem_t*, elem_t*));

int list_valide(list* lst);

int list_dump(list* lst); 
