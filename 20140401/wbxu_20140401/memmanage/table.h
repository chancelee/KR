#ifndef  TABLE_H_6AEDF8D6_CF88_44ce_9E06_CCF5E6129889
#define  TABLE_H_6AEDF8D6_CF88_44ce_9E06_CCF5E6129889

/*
Function: ��record�����(size, start)��¼����Ĳ��뵽g_add_table��
����  
Param	:  table, record
����        
����        
Return  :  None.

Effect   : ����g_add_table
*/
void
insertintoaddtable(struct tag_table *table, struct tag_record *record);

/*
Function: ��record�����(size, start)��¼����Ĳ��뵽g_del_table��, ����g_del_tableָʾ�������пռ��������
����  
Param	:  table[*max]
����        size, start
����        
Return  :  None.

Effect   : ����g_del_table, ��g_del_tableָʾ���������пռ�������ϣ������ٷ���
*/
void
insertintodeltable(struct tag_table *table, struct tag_record *record);



/*
Function: ��index ����ʶ��(size, start)��¼��table��ɾ��, ����֤table�������ԡ�
����  
Param	: table, index
����        
Return  :  None.

Effect  : ����table;
*/
void
removefromtable(struct tag_table *table, int index);

/*
Function: ��table����Ӧindex����ʶ��(size, start)��¼����Ϊ�´����record��
����  
Param	: 
����        
Return  :  None.

Effect  :  ����table
*/
void
updatetable(struct tag_table *table, int index, struct tag_record *record);


/*
Function: get the table that index belongs to, and set the max value of this range.
*/
int
gettable(int index, int *max);


#endif