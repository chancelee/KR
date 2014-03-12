//different ways you can use to get suitable size
#define		FIT_EQUAL				0
#define		FIT_FIRST				1
#define 	FIT_ENOUGH			    2
#define		FIT_EQUAL_ENOUGH	    3
#define		FIT_EQUAL_FIRST		    4

//
#define 	MAX_SPACE	            10000

//
#define 	MAX_INPUT		        128

//which table: add_table, or del_table
#define		ADD		                0
#define		DEL			            1

#define     SPLIT                   8

//#define     LOG(s)      {printf("%s"}

//storage for your input.
extern char chBuf[MAX_SPACE];

//
extern char chInput[MAX_INPUT];

//used for maintain
//seems a waste.
extern int add_table[MAX_SPACE];
extern int del_table[MAX_SPACE];

//how many (size, start) are stored into table;
extern int indexMAX_add;
extern int indexMAX_del;
extern int indexMAX_buf;

//the way you can get suitable size
extern int fitWAY;

/*
Function: 从del_table中找到一个(size, start)记录，使得size = requestsize
Param	: requestsize 是想申请的空间大小， 
　　      index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
fitequal(int requestsize, int *index);

/*
Function: 从del_table中找到一个(size, start)记录，使得size 刚好>= 
　　       requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
fitenough(int requestsize, int *index);

/*
Function: 从del_table中找到一个(size, start)记录，使得size 是第一个>= 
　　        requestsize，
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
fitfirst(int requestsize, int *index);

/*
Function: 根据WAY，从del_table中找到一个合适的(size, start)记录，
　　      是对上面fitxxx函数的封装。
　　 
Param	: requestsize 是想申请的空间大小， 
          index用于接收符合条件(size, start) 在del_table中的下标
Return  :  -1 失败， 0成功，并设置index.
*/
int 
getsize(int requestsize, int *index);


/*
Function: 查询输入的字符串是否存在于chBuf中。 
　　
Param	: chInput 临时存放用户输入的字符串 
           index 用于接收该字符串对应的(size, start)在add_table中的下标
           
Return  :  -1 不存在， 0存在，并设置index.
*/
int 
query(char chInput[], int *index);


/*
Function: 将(size, start)记录有序的插入到table[*max]中
　　  
Param	:  table[*max]
　　        size, start
　　        
Return  :  None.

Effect   : 更新*max
*/
void
insertintoaddtable(int table[], int *max, int size, int start);

/*
Function: 将(size, start)记录有序的插入到table[*max]中, 并对del_table指示连续空闲空间进行整合
　　  
Param	:  table[*max]
　　        size, start
　　        
Return  :  None.

Effect   : 更新*max, 对del_table指示的连续空闲空间进行整合，进行再分配
*/
void
insertintodeltable(int table[], int *max, int size, int start);


/*
Function: 将index 所标识的(size, start)从table[*max]中删除, 并保证table的有序性。
　　  
Param	: 
　　        
Return  :  None.

Effect  : 更新*max;
*/
void
removefromtable(int table[], int *max, int index);

/*
Function: 将table[index]所标识的(size, start)更新为新传入的值。
　　  
Param	: 
　　        
Return  :  None.

Effect  : 
*/
void
updatetable(int table[], int index, int size, int start);


/*
Function: 将用户输入chInput[]存储至chBuf[]中。
　　  
Param	: chInput[]为用户输入的临时存储
　　        
Return  :  -1 存储失败， 0 成功.

Effect  : 更新add_table, indexMAX_add, 根据情况更新
          del_table,indexMAX_buf
*/
int
add(char chInput[]);

/*
Function: 试图从chBuf[]中删除用户输入chInput[]。
　　  
Param	: chInput[]为用户输入的临时存储
　　        
Return  :  -1 删除失败， 0 成功.

Effect  : 更新add_table, 
           更新del_table， 根据情况对空闲空间进行整合，影响del_table
*/
int
del(char chInput[]);

/*
Function: 试图从chBuf[]中将原有输入origin更改为新输入内容new。
　　  
Param	: origin指向待修改内容
           new指向新内容
　　        
Return  :  -1 修改失败， 0 成功.

Effect  : 更新add_table, 
           更新del_table， 根据情况对空闲空间进行整合，影响del_table
*/
int
modify(char origin[], char new[]);


/*
Function: 将chInput[]存储至chBuf[start]
　　  
Param	: chBuf, start, chInput, requestsize      
　　        
Return  :  -1 存储失败， 0 成功.

Effect  : 更新chBuf[]
*/
void
store(char chBuf[], int start, char chInput[], int requestsize);

/*
Function: 遍历add_table, 结合chBuf, 输出所有存储的字符串输入。
　　  
Param	 : None         
　　        
Return  : None.

Effect  : None
*/
void
display(void);


/*
Function: 统计chBuf[] 0 ～indexMAX_buf 各字节的使用情况,
　　  
Param	 : None          
　　        
Return  : None
Effect   : None
*/
void
statistics(void);
