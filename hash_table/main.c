#include "M_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int PRIME_SIZE = 761;

int hash1(char** str);

int hash2(char** str);

int hash3(char** str);

int hash4(char** str);

int hash5(char** str);

int hash6(char** str);

int main(){
	FILE* input_file = 0;
	FILE* output_file = 0;
	char* tempstr = NULL;
	int i = 0;
	hash_table* table = hash_table_create(PRIME_SIZE);
	
	tempstr = (char*) calloc (100, sizeof(char));
	
	input_file = fopen("Game_of_thrones.txt", "r");
	
	output_file = fopen("rezult.cvs", "w");
	
	while(fscanf(input_file, "%s", tempstr) > 0){
		
		hash_table_add(table, &tempstr, hash1);
		++i;
	}
	
	printf("\n%d", i);
	
	fprintf(output_file, "list number:, ");
	
	for (i = 0; i < table -> size; ++i){
		
		fprintf(output_file, "%d ,", i);
		
	}
	
	fprintf(output_file, "\nlist elements of sort 1 (sum):, ");
	
	for (i = 0; i < table -> size; ++i){
		
		fprintf(output_file, "%d ,", (table -> data[i]) -> size);
		
	}
	
	hash_table_delete(table);
	
	table = hash_table_create(PRIME_SIZE);
	
	rewind(input_file);
	
	while(fscanf(input_file, "%s", tempstr) > 0){
		
		hash_table_add(table, &tempstr, hash2);
		++i;
	}
	
	fprintf(output_file, "\nlist elements of sort 2 (mul):, ");
	
	for (i = 0; i < table -> size; ++i){
		
		fprintf(output_file, "%d ,", (table -> data[i]) -> size);
		
	}
	
	hash_table_delete(table);
	
	table = hash_table_create(PRIME_SIZE);
	
	rewind(input_file);
	
	while(fscanf(input_file, "%s", tempstr) > 0){
		
		hash_table_add(table, &tempstr, hash3);
		++i;
	}
	
	fprintf(output_file, "\nlist elements of sort 3 (XOR):, ");
	
	for (i = 0; i < table -> size; ++i){
		
		fprintf(output_file, "%d ,", (table -> data[i]) -> size);
		
	}
	
	hash_table_delete(table);
	
	table = hash_table_create(PRIME_SIZE);
	
	rewind(input_file);
	
	while(fscanf(input_file, "%s", tempstr) > 0){
		
		hash_table_add(table, &tempstr, hash4);
		++i;
	}
	
	fprintf(output_file, "\nlist elements of sort 4 (1):, ");
	
	for (i = 0; i < table -> size; ++i){
		
		fprintf(output_file, "%d ,", (table -> data[i]) -> size);
		
	}
	
	hash_table_delete(table);
	
	table = hash_table_create(PRIME_SIZE);
	
	rewind(input_file);
	
	while(fscanf(input_file, "%s", tempstr) > 0){
		
		printf("\n%d", hash5(&tempstr));
		
		hash_table_add(table, &tempstr, hash5);
		++i;
	}
	
	fprintf(output_file, "\nlist elements of sort 5 (first char):, ");
	
	for (i = 0; i < table -> size; ++i){
		
		fprintf(output_file, "%d ,", (table -> data[i]) -> size);
		
	}
	
	hash_table_delete(table);
	
	table = hash_table_create(PRIME_SIZE);
	
	rewind(input_file);
	
	while(fscanf(input_file, "%s", tempstr) > 0){
		
		hash_table_add(table, &tempstr, hash6);
		++i;
	}
	
	fprintf(output_file, "\nlist elements of sort 6 (len):, ");
	
	for (i = 0; i < table -> size; ++i){
		
		fprintf(output_file, "%d ,", (table -> data[i]) -> size);
		
	}
	
	hash_table_delete(table);
	
	return 0;
	
	
	
}

int hash1(char** str){
	int i = 0;
	int rezult = 1;
	int max = strlen(*str);
	
	
	for(i = 0; i < max; ++i){
		
		rezult += (*str)[i];
	}
	
	rezult = rezult % 100000;
	return abs(rezult);
}

int hash2(char** str){
	int i = 0;
	int rezult = 1;
	int max = strlen(*str);
	
	
	for(i = 0; i < max; ++i){
		
		rezult *= (*str)[i];
	}
	
	rezult = rezult % 100000;
	return abs(rezult);
}

int hash3(char** str){
	int i = 0;
	int rezult = 0;
	int max = strlen(*str);
	
	if (str != NULL) rezult = (*str)[0];
	
	for(i = 1; i < max; ++i){
		rezult = (rezult << 1) ^ (*str)[i];
	}
	
	return abs(rezult);
}

int hash4(char** str){
	return 1;
}

int hash5(char** str){
	return abs((*str)[0]);
}

int hash6(char** str){
	return abs(strlen(*str));
}
