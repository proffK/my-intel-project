#ifndef _M_LIST_
#define _M_LIST_

typedef char* elem_t;

struct list_elem{
	
	elem_t data;
	struct list_elem* next;
	struct list_elem* prev;
	
};

typedef struct {
	
	struct list_elem* head;
	struct list_elem* tail;
	int size;
	
} list;



list* list_create(void);

int list_delete(list* deleted_list);

struct list_elem* add_elem(list* lst, elem_t* new_elem, elem_t* (*cpy) (elem_t*, elem_t*));

struct list_elem* insert_elem(list* lst, elem_t* new_elem, struct list_elem* next_elem,\
						elem_t* (*cpy) (elem_t*, elem_t*));

struct list_elem* delete_elem(list* lst, struct list_elem* deleted_elem);

struct list_elem* find_elem(list* lst, elem_t finded_elem, int (*cmp) (elem_t*, elem_t*));

int list_valide(list* lst);

int list_dump(list* lst);


#endif
