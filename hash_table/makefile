hash: main.o liblist.a libhash.a 
	gcc $< -o $@ -L. -lhash  -llist -lm
main.o: main.c
	gcc -Wall -c $<
libhash.a: M_hash.o
	ar rcs $@ $< 
liblist.a: M_list.o
	ar rcs $@ $< 
M_list.o: M_list.c
	gcc -Wall -c $<
M_hash.o: M_hash.c
	gcc -Wall -c $<
clean:
	rm -f *.o
	
	
