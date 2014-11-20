#include "M_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

const int PRIME_SIZE = 2221;

///###########################################################

int hash1(char** str);

int hash2(char** str);

int hash3(char** str);

int hash4(char** str);

int hash5(char** str);

int hash6(char** str);

int hash7(char** str);

int hashtest(FILE* input_file, FILE* output_file, int (*hash) (char** str));

///###########################################################

int main(){
	FILE* input_file = 0;
	FILE* output_file = 0;
	
	input_file = fopen("J. D. Salinger - The Catcher in the Rye - 1951.txt", "r");
	
	output_file = fopen("rezult1.cvs", "w");
	
	hashtest(input_file, output_file, hash1);
	
	output_file = fopen("rezult2.cvs", "w");
	
	hashtest(input_file, output_file, hash2);
	
	output_file = fopen("rezult3.cvs", "w");
	
	hashtest(input_file, output_file, hash3);
	
	output_file = fopen("rezult4.cvs", "w");
	
	hashtest(input_file, output_file, hash4);
	
	output_file = fopen("rezult5.cvs", "w");
	
	hashtest(input_file, output_file, hash5);
	
	output_file = fopen("rezult6.cvs", "w");
	
	hashtest(input_file, output_file, hash6);
	
	output_file = fopen("rezult7.cvs", "w");
	
	hashtest(input_file, output_file, hash7);

	return 0;
		
}
///###########################################################
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
///###########################################################
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
///###########################################################
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
///###########################################################
int hash4(char** str){
	return 1;
}
///###########################################################
int hash5(char** str){
	return abs((*str)[0]);
}
///###########################################################
int hash6(char** str){
	return abs(strlen(*str));
}
///###########################################################
int hash7(char** str){

    int hash = 0;
    
    int i = 0;
    
	int max = strlen(*str);
	
	if (str != NULL) hash = (*str)[0];
	
	for(i = 1; i < max; ++i){
		hash += (unsigned char) (*str)[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
	}

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return abs(hash);

}
///###########################################################

int hashtest(FILE* input_file, FILE* output_file, int (*hash) (char** str)){
	hash_table* table = 0;
	int i = 0;
	char* tempstr = (char*) calloc (100, sizeof(char));
	
	
	table = hash_table_create(PRIME_SIZE);
	rewind(input_file);
	
	fprintf(output_file, "list number , list elements of sort \n");

	while(fscanf(input_file, "%s", tempstr) > 0){

		if (!(hash_table_find(table, hash, &tempstr)))
			hash_table_add(table, &tempstr, hash);

	}

	
	
	for (i = 0; i < table -> size; ++i){
		
		
		fprintf(output_file, "%d , %d \n", i,  (table -> data[i]) -> size);
		
	}
	hash_table_delete(table);
}


"%[^\"]"
