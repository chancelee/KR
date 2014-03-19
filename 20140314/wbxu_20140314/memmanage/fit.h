//different ways you can use to get suitable size
#define		FIT_EQUAL				0
#define		FIT_FIRST				1
#define 	FIT_ENOUGH			    2
#define		FIT_EQUAL_ENOUGH	    3
#define		FIT_EQUAL_FIRST		    4


/*
Function: 从del_table中找到一个(size, start)记录，使得size = requestsize
Param	: requestsize 是想申请的空间大小， 
　　      index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS 成功，并设置index.
*/
int 
fitequal(int requestsize, int *index);

/*
Function: 从del_table中找到一个(size, start)记录，使得size 刚好>= 
　　       requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS 成功，并设置index.
*/
int 
fitenough(int requestsize, int *index);

/*
Function: 从del_table中找到一个(size, start)记录，使得size 是第一个>= 
　　        requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS 成功，并设置index.
*/
int 
fitfirst(int requestsize, int *index);

/*
Function: 根据fitWAY，从del_table中找到一个合适的(size, start)记录，
　　      是对上面fitxxx函数的封装。
　　 
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  NOT_EXIST 失败， SUCCESS 成功，并设置index.
*/
int 
getsize(int requestsize, int *index);

/*
Function: set the default way according to your input
*/
void
setfit(int select);
