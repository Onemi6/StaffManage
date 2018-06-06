#ifndef _LIST_L_H_
#define _LIST_L_H_

//��������йصĺ�
#define  TRUE         1
#define  FALSE        0
#define  OK           1
#define  ERROR        0
#define  INFEASIBLE  -1
#define  OVERFLOW    -2

typedef  int  Status;

//�������ݶ��������
typedef  struct Staff
{
	char ID[10];              //ID��
	char name[20];            //����
	char sex;                 //�Ա�
	int  age;                 //����
	char number[11];          //�绰
	char address[20];         //סַ��
    char E[20];               //E-mail
	int  pay;                 //����
	int  worktimes;           //����
	char department[20];      //���ڲ���
}Information;

//����������ṹ
typedef  struct lnode
{
	Information  data;        //�������
	struct lnode  *next;   //ָ����һ������ָ��
}LNode, *LinkList, *ListType;


//���������������
Status  InitList_L(LinkList &L);

//��������
//�ͷŰ���ͷ�������н��
Status DestroyList_L(LinkList &L );

//�������
//�ͷ�ͷ���֮������н��
Status ClearList_L(LinkList L );

//�ж������Ƿ�Ϊ�գ�
//����ֵ���գ�TRUE�����գ�FALSE
Status ListEmpty(LinkList L );

//������ĳ��ȣ������������ݽ��ĸ���
int ListLength(LinkList L );


//��������ȡλ��Ϊi�Ľ�����ݣ�����e���ظ�ֵ
Status GetElem(LinkList L, int i, Information &e );


//�ж�Ԫ��e�Ƿ��������У�����ڷ������������е�λ�򣬷��򷵻�0
int    LocateElem(LinkList L, Information e, 
					 Status (*compare)(Information e1, Information e2) );

//�����������һ����㣬�������Ϊe
Status  InsertList_L(LinkList &L, int i , Information e);

//ɾ��λ��Ϊi�Ľ�㣬����e���ؽ������
Status DeleteList_L(LinkList L, int i, Information &e);

//���������е�ÿ����㣬������visit�����Խ�����ݴ���
Status ListTraverse(LinkList L, Status (*visit)(Information e) );

//�޸�λ��Ϊi�Ľ������
Status ListModify(LinkList L, int i, Information e );

//���ļ��н�Ա����Ϣ�����ڴ棬ÿ��Ա����Ϣ��һ������ڵ㱣�棬���ļ�
//��˳���Ա����Ϣ��ͬʱ�����ڵ����������
void  LoadData(LinkList  L, char *filename );

//�������е�Ա����Ϣд���ļ��У�������ÿ���ڵ㶼��Ӧһ��Ա������Ϣ��
void  SaveData(LinkList  L, char *filename );


#endif
