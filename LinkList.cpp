#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "LinkList.h"
#include  "Operate.h"


//��ʼ������
Status  InitList_L(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));
	if (!L)
		return OVERFLOW;
	L->next = NULL;
	return OK;
}  


//��������
//�ͷŰ���ͷ�������н��
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

//�������
//�ͷ�ͷ���֮������н��
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


//�ж������Ƿ�Ϊ�գ�
//����ֵ���գ�TRUE�����գ�FALSE
Status ListEmpty(LinkList L )
{
	
	if(!L->next )
		return TRUE;
	
	return FALSE;
}

//������ĳ��ȣ������������ݽ��ĸ���
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

//��������ȡλ��Ϊi�Ľ�����ݣ�����e���ظ�ֵ
Status GetElem(LinkList L, int i, Information &e )
{
	int j=1;
	LNode *p = L->next;
	
	//�ҵ�Ԫ�����ڵ�λ��
	while(p && j<i )
	{
		p = p->next;
		j++;
	}
	if(!p || j>i )
		return FALSE;     //�Ҳ���λ��Ϊi�Ľ��
	
	//�ҵ�λ��Ϊi�Ľ�㣬��e�������ݷ���
	e = p->data;
	return OK;
}

//�ж�Ԫ��e�Ƿ��������У�����ڷ������������е�λ�򣬷��򷵻�0
int    LocateElem(LinkList L, Information e, 
				  Status (*compare)(Information e1, Information e2) )
{
	int pos = 1;
	LNode  *p = L->next;
	while(p )
	{
		if( (*compare)(e, p->data) )
			return pos;               //Ԫ��e�������У�������λ��
		pos++;
		p = p->next;
	}
	
	return 0;    //Ԫ��e���������У�����0
}


//�����������һ����㣬�������Ϊe
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

//ɾ��λ��Ϊi�Ľ�㣬����e���ؽ������
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

//���������е�ÿ����㣬������visit�����Խ�����ݴ���
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

//�޸�λ��Ϊi�Ľ������
Status ListModify(LinkList L, int i, Information e )
{
	
	int j=1;
	LNode *p = L->next;
	
	//�ҵ�Ԫ�����ڵ�λ��
	while(p && j<i )
	{
		p = p->next;
		j++;
	}
	if(!p || j>i )
		return FALSE;     //�Ҳ���λ��Ϊi�Ľ��
	
	//�ҵ�λ��Ϊi�Ľ�㣬�޸���������
	p->data = e;
	return OK;
}




//���ļ��н�Ա����Ϣ�����ڴ棬ÿ��Ա����Ϣ��һ������ڵ㱣�棬���ļ�
//��˳���Ա����Ϣ��ͬʱ�����ڵ����������


void  LoadData(LinkList  L, char *filename )
{
	Information  staff;      
	FILE   *pfile;         //�ļ�ָ��
	
	
	//�򿪱���Ա����Ϣ�������ļ�
	pfile = fopen(filename, "rb" );
	if(!pfile )
	{
		printf("�ļ���ʧ��!\n" );
		exit(0 );
	}
	
	while(fread((char*)&staff, sizeof(Information), 1, pfile) == 1 )
		InsertList_L(L, 1, staff ); //�ŵ�������
	
	fclose(pfile );
	pfile = NULL;
}





//�������е�Ա����Ϣд���ļ��У�������ÿ���ڵ㶼��Ӧһ��Ա������Ϣ��


void  SaveData(LinkList  L, char *filename )
{
	
	long  lstunum=0;
	LNode *pnode;
	FILE  *pfile;
	
	
	//�򿪱���Ա����Ϣ�������ļ�
	pfile = fopen(filename, "wb" );
	if(!pfile  )
	{
		printf("�ļ���ʧ�ܣ�\n" );
		exit(0 );
	}
	
	//�������е���Ϣ�浽�ļ���
	pnode = L->next;
	while(pnode != NULL )
	{
		fwrite(&(pnode->data), sizeof(Information), 1, pfile );    //ÿ��д��һ��Ա�����ڵ㣩��Ϣ
		pnode = pnode->next;                                       //�����ƶ�����һ���ڵ�
		lstunum += 1;                                              //ͳ��Ա����
	}
	//printf("����%d��Ա��."��lstunum);
	
	fclose(pfile );
	pfile = NULL;
}