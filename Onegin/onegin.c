#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <locale.h>

/*! \mainpage 
Belinsky once observed that "Eugene Onegin" was a real encyclopaedia of life in Russia.
And all the encyclopedias should be sorted alphabetically.
That's what this program does.
*/

/*!
 * This constant discribe max size of reading file
 * */
const long MAXSIZE = LONG_MAX;
/*!
 * This constant discribe max lenght of line in file
 * */
const int MAXLINE = INT_MAX;

/*! This function count lines and replace '\n' on '\0' in input string.
 * \param str - input string.
 * \param MAXLINE - max number of line.
 * \return number of lines.
 */
long count_lines(char* str, long MAXLINE);

/*! This function count character in input .txt file 
 * \param f - input .txt file
 * \param MAXSIZE - max size input file;
 * \return number of character in 
 */ 
long file_length(FILE* f, long MAXSIZE); 

/*! This function divide input string on array of pointer
 * \param list - output array of pointer
 * \param str - input string
 * \param MAXLINE - max line in input string
 */
void create_list_string(char** list, char* str, long length, long num_lines);

/*! This function alfabetically sort input list of string
 * \param list - input array of pointer
 * \param Start - First sorted element in list
 * \param End - Last sorted element in list
 */
void alfabet_quicksort(char** list, int Start, int End);


/*! This function write output file*/
void write_file_from_list(FILE* f, char** list, long num_lines);

int main(){
	/*!
	* create a necesarry variable 
	*/ 
	char** text = NULL; 
	char* buf = NULL;
	FILE* inputf = fopen("book.txt", "r");
	FILE* outputf = fopen("onegin.txt", "r+w");
	long file_size = 0;
	long num_lines = 0;
	
	setlocale(LC_ALL, "cp-1251");
	
	file_size = file_length(inputf , MAXSIZE);
	
	buf = (char*) calloc (file_size , sizeof (*buf));
	
	rewind(inputf);
	
	fread(buf, sizeof (char), file_size, inputf);
	
	num_lines = count_lines(buf, MAXSIZE);
	
	text = (char**) calloc (num_lines, sizeof (*text));
	
	create_list_string(text, buf, file_size, num_lines);
	
	alfabet_quicksort (text, 0, num_lines - 1);
	
	write_file_from_list(outputf, text, num_lines);
	
	free(buf);
	free(text);
	
	fclose(inputf);
	fclose(outputf);
	
	return 0;
}

long count_lines(char* str, long MAXLINE){
	long i = 0, counter = 0;
	
	while (str[i] != '\0' || i == MAXLINE){
		
		if (str[i] == '\n'){
			counter++;
			str[i] = '\0';
		}
		i++;
	}
	
	return counter; 
}

long file_length(FILE* f, long MAXSIZE){
	long i = 0;
	int c = 0;
	
	while ((c = fgetc(f)) != EOF && i < MAXSIZE) i++;
	
	return i;
}

void create_list_string(char** list, char* str, long length, long num_lines){
	long i = 0, a = 0;
	
	list[a] = str;
	++a;
	
	while (i < length - 1) {
		if (str[i] == '\0'){
			*(list + a) = str + i + 1;
			
			assert(a < num_lines);
					
			a++;
		}
	
	++i;
	}
}


void alfabet_quicksort(char** list, int Start, int End){
    char x = 0;
    int i = 0, j = 0;
    x = *(list[ ( Start + End ) / 2]);
    x = (x > 223) ? x - 32 : x;
    i = Start;
    j = End;

    do {
        assert(i >= 0 && i <= End);
	    char Char = *list[i];
        // This condition for comparison big and small russian characters
        Char = (Char > 223) ? Char - 32 : Char;
        
        while (Char < x){
            i++;
            Char = *list[i];
            Char = (Char > 223) ? Char - 32 : Char;
        }
        
        assert(j >= 0 && j <= End);
        
        Char = *list[j];
        Char = (Char > 223) ? Char - 32 : Char;
        
        while (Char > x){
            j--;
            Char = *list[j];
            Char = (Char > 223) ? Char - 32 : Char;
        }
        
        if (i <= j){
            char* Buffer;
            Buffer = list[i];
            list[i] = list[j];
            list[j] = Buffer;
            i++;
            j--;
			}
			
		} while (i <= j);
		
    if (j > Start) alfabet_quicksort (list, Start, j);
    if (i < End) alfabet_quicksort (list, i, End);
}

void write_file_from_list(FILE* f, char** list, long num_lines){
	long i = 0;
	for (i = 0; i < num_lines; ++i){
		fprintf(f, "%s", list[i]);
	}
}
