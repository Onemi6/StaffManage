#ifndef _LIST_L_H_
#define _LIST_L_H_

//链表操作有关的宏
#define  TRUE         1
#define  FALSE        0
#define  OK           1
#define  ERROR        0
#define  INFEASIBLE  -1
#define  OVERFLOW    -2

typedef  int  Status;

//定义数据对象的类型
typedef  struct Staff
{
	char ID[10];              //ID号
	char name[20];            //姓名
	char sex;                 //性别
	int  age;                 //年龄
	char number[11];          //电话
	char address[20];         //住址，
    char E[20];               //E-mail
	int  pay;                 //工资
	int  worktimes;           //工龄
	char department[20];      //所在部门
}Information;

//定义链表结点结构
typedef  struct lnode
{
	Information  data;        //结点数据
	struct lnode  *next;   //指向下一个结点的指针
}LNode, *LinkList, *ListType;


//链表操作函数声明
Status  InitList_L(LinkList &L);

//销毁链表
//释放包括头结点的所有结点
Status DestroyList_L(LinkList &L );

//清空链表
//释放头结点之外的所有结点
Status ClearList_L(LinkList L );

//判断链表是否为空，
//返回值，空：TRUE；不空：FALSE
Status ListEmpty(LinkList L );

//求链表的长度，即链表中数据结点的个数
int ListLength(LinkList L );


//从链表中取位序为i的结点数据，并用e返回该值
Status GetElem(LinkList L, int i, Information &e );


//判断元素e是否在链表中，如果在返回其在链表中的位序，否则返回0
int    LocateElem(LinkList L, Information e, 
					 Status (*compare)(Information e1, Information e2) );

//往链表中添加一个结点，结点数据为e
Status  InsertList_L(LinkList &L, int i , Information e);

//删除位序为i的结点，并用e返回结点数据
Status DeleteList_L(LinkList L, int i, Information &e);

//遍历链表中的每个结点，并调用visit（）对结点数据处理
Status ListTraverse(LinkList L, Status (*visit)(Information e) );

//修改位序为i的结点数据
Status ListModify(LinkList L, int i, Information e );

//从文件中将员工信息导入内存，每个员工信息用一个链表节点保存，从文件
//中顺序读员工信息的同时，将节点插入链表中
void  LoadData(LinkList  L, char *filename );

//将链表中的员工信息写到文件中，链表中每个节点都对应一个员工的信息，
void  SaveData(LinkList  L, char *filename );


#endif
