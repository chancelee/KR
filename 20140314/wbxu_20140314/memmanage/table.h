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
Param	: table[*max]
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

Effect  :  ����table
*/
void
updatetable(int table[], int index, int size, int start);


/*
Function: get the table that index belongs to, and set the max value of this range.
*/
int
gettable(int index, int *max);
