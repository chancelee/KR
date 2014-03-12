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
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size = requestsize
Param	: requestsize ��������Ŀռ��С�� 
����      index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
*/
int 
fitequal(int requestsize, int *index);

/*
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size �պ�>= 
����       requestsize��
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
*/
int 
fitenough(int requestsize, int *index);

/*
Function: ��del_table���ҵ�һ��(size, start)��¼��ʹ��size �ǵ�һ��>= 
����        requestsize��
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
*/
int 
fitfirst(int requestsize, int *index);

/*
Function: ����WAY����del_table���ҵ�һ�����ʵ�(size, start)��¼��
����      �Ƕ�����fitxxx�����ķ�װ��
���� 
Param	: requestsize ��������Ŀռ��С�� 
          index���ڽ��շ�������(size, start) ��del_table�е��±�
Return  :  -1 ʧ�ܣ� 0�ɹ���������index.
*/
int 
getsize(int requestsize, int *index);


/*
Function: ��ѯ������ַ����Ƿ������chBuf�С� 
����
Param	: chInput ��ʱ����û�������ַ��� 
           index ���ڽ��ո��ַ�����Ӧ��(size, start)��add_table�е��±�
           
Return  :  -1 �����ڣ� 0���ڣ�������index.
*/
int 
query(char chInput[], int *index);


/*
Function: ��(size, start)��¼����Ĳ��뵽table[*max]��
����  
Param	:  table[*max]
����        size, start
����        
Return  :  None.

Effect   : ����*max
*/
void
insertintoaddtable(int table[], int *max, int size, int start);

/*
Function: ��(size, start)��¼����Ĳ��뵽table[*max]��, ����del_tableָʾ�������пռ��������
����  
Param	:  table[*max]
����        size, start
����        
Return  :  None.

Effect   : ����*max, ��del_tableָʾ���������пռ�������ϣ������ٷ���
*/
void
insertintodeltable(int table[], int *max, int size, int start);


/*
Function: ��index ����ʶ��(size, start)��table[*max]��ɾ��, ����֤table�������ԡ�
����  
Param	: 
����        
Return  :  None.

Effect  : ����*max;
*/
void
removefromtable(int table[], int *max, int index);

/*
Function: ��table[index]����ʶ��(size, start)����Ϊ�´����ֵ��
����  
Param	: 
����        
Return  :  None.

Effect  : 
*/
void
updatetable(int table[], int index, int size, int start);


/*
Function: ���û�����chInput[]�洢��chBuf[]�С�
����  
Param	: chInput[]Ϊ�û��������ʱ�洢
����        
Return  :  -1 �洢ʧ�ܣ� 0 �ɹ�.

Effect  : ����add_table, indexMAX_add, �����������
          del_table,indexMAX_buf
*/
int
add(char chInput[]);

/*
Function: ��ͼ��chBuf[]��ɾ���û�����chInput[]��
����  
Param	: chInput[]Ϊ�û��������ʱ�洢
����        
Return  :  -1 ɾ��ʧ�ܣ� 0 �ɹ�.

Effect  : ����add_table, 
           ����del_table�� ��������Կ��пռ�������ϣ�Ӱ��del_table
*/
int
del(char chInput[]);

/*
Function: ��ͼ��chBuf[]�н�ԭ������origin����Ϊ����������new��
����  
Param	: originָ����޸�����
           newָ��������
����        
Return  :  -1 �޸�ʧ�ܣ� 0 �ɹ�.

Effect  : ����add_table, 
           ����del_table�� ��������Կ��пռ�������ϣ�Ӱ��del_table
*/
int
modify(char origin[], char new[]);


/*
Function: ��chInput[]�洢��chBuf[start]
����  
Param	: chBuf, start, chInput, requestsize      
����        
Return  :  -1 �洢ʧ�ܣ� 0 �ɹ�.

Effect  : ����chBuf[]
*/
void
store(char chBuf[], int start, char chInput[], int requestsize);

/*
Function: ����add_table, ���chBuf, ������д洢���ַ������롣
����  
Param	 : None         
����        
Return  : None.

Effect  : None
*/
void
display(void);


/*
Function: ͳ��chBuf[] 0 ��indexMAX_buf ���ֽڵ�ʹ�����,
����  
Param	 : None          
����        
Return  : None
Effect   : None
*/
void
statistics(void);
