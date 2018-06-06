#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "LinkList.h"
#include  "Operate.h"


//初始化链表
Status  InitList_L(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));
	if (!L)
		return OVERFLOW;
	L->next = NULL;
	return OK;
}  


//销毁链表
//释放包括头结点的所有结点
Status DestroyList_L(LinkList &L )
{
	LNode *p;
	
	while( L )
	{
		p = L;
		L = L->next;
		free(p );
	}
	
	return OK;
}

//清空链表
//释放头结点之外的所有结点
Status ClearList_L(LinkList L )
{
	LNode *p;
	
	while(L->next )
	{
		p = L->next;
		L->next = p->next;
		free(p );
	}
	
	return OK;
}


//判断链表是否为空，
//返回值，空：TRUE；不空：FALSE
Status ListEmpty(LinkList L )
{
	
	if(!L->next )
		return TRUE;
	
	return FALSE;
}

//求链表的长度，即链表中数据结点的个数
int ListLength(LinkList L )
{
	int length;
	LNode *p;
	
	length = 0;
	p = L->next;
	while(p )
	{
		length++;
		p=p->next;
	}
	
	return length;
}

//从链表中取位序为i的结点数据，并用e返回该值
Status GetElem(LinkList L, int i, Information &e )
{
	int j=1;
	LNode *p = L->next;
	
	//找到元素所在的位置
	while(p && j<i )
	{
		p = p->next;
		j++;
	}
	if(!p || j>i )
		return FALSE;     //找不到位序为i的结点
	
	//找到位序为i的结点，用e把其数据返回
	e = p->data;
	return OK;
}

//判断元素e是否在链表中，如果在返回其在链表中的位序，否则返回0
int    LocateElem(LinkList L, Information e, 
				  Status (*compare)(Information e1, Information e2) )
{
	int pos = 1;
	LNode  *p = L->next;
	while(p )
	{
		if( (*compare)(e, p->data) )
			return pos;               //元素e在链表中，返回其位置
		pos++;
		p = p->next;
	}
	
	return 0;    //元素e不在链表中，返回0
}


//往链表中添加一个结点，结点数据为e
Status  InsertList_L(LinkList &L, int i , Information e)
{
	LNode *s , *p;
	int j;
	if ( i < 1 )
		return ERROR;
	
	p=L;
	for (j=1;j<=i-1;j++)
	{
		if (p->next == NULL)
			return ERROR;
		
		p = p->next;
	}
	s=(LNode * )malloc(sizeof(LNode));
	if(!s)
		return OVERFLOW;
	
	s -> data= e ;
	s -> next= p -> next ;
	p -> next= s ;
	return OK;
	
}

//删除位序为i的结点，并用e返回结点数据
Status DeleteList_L(LinkList L, int i, Information &e)
{
	int j;
	LNode * p,* s;
	if (i<1)
		return ERROR;
	
    p=L;
	for ( j = 1 ; j <= i-1 ; j++)
	{
		if ( p->next == NULL)
			return ERROR;
		p=p->next;
		
	}
	s=p->next;
	p->next=s->next;
	
	e=s->data;
	free(s);
	return OK;
	
}

//遍历链表中的每个结点，并调用visit（）对结点数据处理
Status ListTraverse(LinkList L, Status (*visit)(Information e) )
{
	LNode *p;
	
	for( p = L->next; p != NULL; p = p->next )
	{
		if( !(*visit)(p->data) )
			return ERROR;	
	}
	
	return OK;
}

//修改位序为i的结点数据
Status ListModify(LinkList L, int i, Information e )
{
	
	int j=1;
	LNode *p = L->next;
	
	//找到元素所在的位置
	while(p && j<i )
	{
		p = p->next;
		j++;
	}
	if(!p || j>i )
		return FALSE;     //找不到位序为i的结点
	
	//找到位序为i的结点，修改其结点数据
	p->data = e;
	return OK;
}




//从文件中将员工信息导入内存，每个员工信息用一个链表节点保存，从文件
//中顺序读员工信息的同时，将节点插入链表中


void  LoadData(LinkList  L, char *filename )
{
	Information  staff;      
	FILE   *pfile;         //文件指针
	
	
	//打开保存员工信息的数据文件
	pfile = fopen(filename, "rb" );
	if(!pfile )
	{
		printf("文件打开失败!\n" );
		exit(0 );
	}
	
	while(fread((char*)&staff, sizeof(Information), 1, pfile) == 1 )
		InsertList_L(L, 1, staff ); //放到链表中
	
	fclose(pfile );
	pfile = NULL;
}





//将链表中的员工信息写到文件中，链表中每个节点都对应一个员工的信息，


void  SaveData(LinkList  L, char *filename )
{
	
	long  lstunum=0;
	LNode *pnode;
	FILE  *pfile;
	
	
	//打开保存员工信息的数据文件
	pfile = fopen(filename, "wb" );
	if(!pfile  )
	{
		printf("文件打开失败！\n" );
		exit(0 );
	}
	
	//将链表中的信息存到文件中
	pnode = L->next;
	while(pnode != NULL )
	{
		fwrite(&(pnode->data), sizeof(Information), 1, pfile );    //每次写入一个员工（节点）信息
		pnode = pnode->next;                                       //往后移动到下一个节点
		lstunum += 1;                                              //统计员工数
	}
	//printf("现有%d个员工."，lstunum);
	
	fclose(pfile );
	pfile = NULL;
}