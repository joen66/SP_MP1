#ifndef SP_HW1_LIBRARY_H
# define SP_HW1_LIBRARY_H
# define MAX_TITLE_LENGTH (32)
# define MAX_RESERVE (16)
struct BookInfo{
	char title[MAX_TITLE_LENGTH];
	int number_of_resv_req; /*>=0, <MAX_RESERVE*/
	int userID_for_resv_request[MAX_RESERVE];
};
# define NO_USER (-1)
#endif
/*userID_for_resv_request[0] is either NO_USER or integer >=0*/
