#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "library.h"
#include "sharedfunc.h"
int main(int argc, char* argv[]){
	int book_idx=0,fdBooks,fdLockBooks,given_user_id;
    if( argc != 3 ){
        perror("invalid the number of arguments\n");
		return -1;
    }
	book_idx = atoi(argv[1]);
	given_user_id = atoi(argv[2]);

	if( (fdBooks = open("books", O_RDWR)) ==-1){
		perror("open error");
		return -1;
	}
	printf("%d", fdBooks);
	if( setLock(fdBooks, book_idx,"R") ){
		perror("setLock return error");
		return -1;
	}

	struct BookInfo book;
	if(read(fdBooks, &book, sizeof( struct BookInfo ) ) <0 ){
		perror("read error\n");
	}
	printf("%s\n", book.title);

	sleep(10);
	setLock(fdBooks, book_idx,"U");
    return 0;
}
