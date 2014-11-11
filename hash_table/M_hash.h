#ifndef _M_HASH_
#define _M_HASH_
#include "M_list.h"

typedef struct {
	
	list* data;
	int size;
	long number_elem;

} hash_table;

hash_table* hash_table_create(int size);

int hash_table_add(elem_t elem, int (*hash_gen) (elem_t));

int hash_table_valide(hash_table* table);

int hash_table_dump(hash_table* table);

int hash_table_delete(hash_table* table);

int hash_table_find(hash_table* table, int (*hash_gen) (elem_t), elem_t);



#endif
