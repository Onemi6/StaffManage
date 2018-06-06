#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include "Operate.h"


//*************************************************************************
/*system("color ??")             头文件为 stdlib.h
//颜色属性由两个十六进制数字指定 -- 第一个为背景，第二个则为前景。每个数字可以为以下任何值之一:

  //           0 = 黑色         4 = 红色        8 = 灰色         C = 淡红色          
  //           1 = 蓝色         5 = 紫色        9 = 淡蓝色       D = 淡紫色
  //           2 = 绿色         6 = 黄色        A = 淡绿色       E = 淡黄色
  //           3 = 湖蓝色       7 = 白色        B = 淡浅绿色     F = 亮白色           
*/
//*************************************************************************

				
/* 用户操作界面启动时，在显示器上显示一些欢迎信息 */
void PrintWelcome( )
{
	system("color F1");
	puts(" ");		
	puts("********************************************************************" );
	puts("                     欢迎使用公司员工信息管理系统!" );
	puts("********************************************************************" );
	puts(" ");				
}



//*************************************************************************				
//*************************************************************************

//第一层菜单
void UserOperate(ListType  L)
{
	int  option = 0;
	
	do
	{
		//提示用户操作选择
		ChoiceType();
		scanf("%d", &option );
		//根据用户选择调用相关函数完成指定的操作
		
		switch(option )
		{
		case 1:
			UserOperateG( L);
			break;
		case 2:
			UserOperateF(L );
			break;
		default:
			break;
		}
	}while(option );
    PrintHello1();
}

//选择模式菜单
void ChoiceType()
{
	system("cls");
	PrintWelcome( );
	system("color F2");
	puts(" ");	
	puts("1:管理员模式!");
	puts("2:访客模式!  ");
	puts("0:退出系统!  ");	
	puts(" ");
}

//*************************************************************************				
//*************************************************************************
//进入管理员模式菜单选择
void UserOperateG(ListType  L)	
{
	system("cls");
	int  option = 0;	
	
	do
	{
		//提示用户操作选择
		PrintOptionG( );
		scanf("%d", &option );
		
		//根据用户选择调用相关函数完成指定的操作
		
		switch(option )
		{
		case 1:
			AddStaff(L);
			break;
		case 2:
			DelStaff(L);
			break;
		case 3:
			UserOperateG3(L);
			break;
		default:  
			break;
		}
	}while(option );
}


//修改员工信息菜单
void UserOperateG3(ListType  L)
{
	int  option = 0,pos;	
	Information e,staff;
	
	printf("请输入员工的ID:" );
	getchar();  //吃掉前面的回车键,否则后面的字符串输入时会出错
	gets(staff.ID );
	pos = LocateElem(L, staff, IsEqualID );
	if(pos > 0 )
	{
		GetElem(L,pos,e);
		PrntOneStaff(e);
		
		do
		{
			//提示用户操作选择
			PrintfOptionG3();
			scanf("%d", &option );
			
			//根据用户选择调用相关函数完成指定的操作
			
			switch(option )
			{
			case 1:
				ModifyName(L,pos);
				break;
			case 2:
				ModifySex(L,pos);
				break;
			case 3:
				ModifyAge(L,pos);
				break;
			case 4:
				ModifyNumber(L,pos);
				break;
			case 5:
				ModifyAddress(L,pos);
				break;
			case 6:
				ModifyE(L,pos);
				break;
			case 7:
				ModifyPay(L,pos);
				break;
			case 8:
				ModifyWorktimes(L,pos);
				break;
			case 9:
				ModifyDepartment(L,pos);
				break;
			default:  
				break;
			}
		}while(option );
	}
}
	
	
//*************************************************************************

//*************************************************************************	

/* 在显示器上显示用户可以进行的操作，以及操作的方法 */
//管理员模式菜单
void PrintOptionG( )
{
					
	puts(" ");
	puts("                            管理员模式 !                              ");
	puts("请选择操作：" );
	puts("1：添加员工信息            2：删除员工信息           3：修改员工信息" );
	puts("0:返回上一级操作");
	puts(" ");
					
}
				
//*************************************************************************

//*************************************************************************

//往线性表中添加一个员工
void AddStaff(ListType  L)
{
	Information  staff;
	
	printf("请输入员工的ID号(不超过10位):" );
	getchar();  //吃掉前面的回车键,否则后面的字符串输入时会出错
	gets(staff.ID );
	
	//判断线性表中是否已经存在该ID号的员工，如果已经存在，则放弃插入操作
	if( LocateElem(L, staff, IsEqualID) )
	{
		puts("操作失败，该员工已经存在!" );
		return;
	}
	else
	{
		printf("请输入员工的姓名(不超过20位):" );
		//	getchar();
		gets(staff.name );
		
		printf("请输入员工的性别(男:M,女:W):" );
		//	getchar();
		staff.sex=getchar();
		
		printf("请输入员工的年龄:" );
		scanf("%d", &staff.age );
		
		printf("请输入员工的电话(不超过11位):" );
		getchar();
		gets(staff.number);
		
		printf("请输入员工的住址(不超过20位):" );
		//	getchar();
		gets(staff.address);
		
		printf("请输入员工的E-mail(不超过20位):" );
		//	getchar();
		gets(staff.E);
		
		printf("请输入员工的工资:" );
		scanf("%d", &staff.pay );
		
		printf("请输入员工的工龄:" );
		scanf("%d", &staff.worktimes );
		
		printf("请输入员工的所在部门(不超过20位):" );
		getchar();
		gets(staff.department);
		
		
		//将该员工放入线性表中
		//为简单起见，我们把新添加的结点放到线性表的前面
		if(InsertList_L(L, 1, staff ) )
		{
			puts("操作成功!" );
		}
		else
		{
			puts("操作失败!" );
		}
	}
}
				
				
				
//*************************************************************************
//*************************************************************************


//从线性表中删除一个员工，根据学生的ID号决定删除哪个员工
void DelStaff(ListType  L)
{
	Information staff;
	int pos;
	char i;
	
	printf("请输入员工的ID号(不超过10位）:" );
	getchar();  //吃掉前面的回车键,否则后面的字符串输入时会出错

	gets(staff.ID);

	//如果存在该ID号的员工，则返回其在线性表中的位序，如果不存在返回0
	pos = LocateElem(L, staff, IsEqualID ); 
	
	if(pos )   
	{
		printf("确认是否删除（Y/N!）");
		scanf("%c",&i);
		if(i=='Y'||i=='y')
		{
			if(DeleteList_L(L, pos, staff) )
			{
				puts("删除成功!");
				return;
			}
			else
			{
				puts("删除失败!" );
			}
		}
		else
		{
			printf("未进行删除!");
		}
	}
	else
	{
		puts("此ID不存在!" );		
	}
	
}

//*************************************************************************
//*************************************************************************


//修改员工信息
void PrintfOptionG3()
{
	system("color F4");
	//	system("cls");
	puts(" ");
	puts("请选择操作：" );
	puts("        修改员工信息" );
	puts("1:姓名    2:性别    3:年龄"    );
	puts("4:电话    5:住址    6:E-mail"  );
	puts("7:工资    8:工龄    9:所在部门");
	puts("0:返回上一级操作");
	puts(" ");
}


//修改员工姓名
void ModifyName(ListType  L, int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的姓名:");
	gets(staff.name);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}
}


//修改员工性别
void ModifySex(ListType  L,int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的性别:");
	staff.sex=getchar();
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}
}
				

//修改员工年龄
void ModifyAge(ListType  L,int pos)
{						
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的年龄:");
	scanf("%d",&staff.age);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}
}



//修改员工电话 
void ModifyNumber(ListType  L,int pos)
{					
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的电话:");
	gets(staff.number);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}   
}

//修改员工住址
void ModifyAddress(ListType  L,int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的住址:");
	gets(staff.address);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}         
}

//修改员工E-mail
void ModifyE(ListType  L,int pos)
{					
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的E-mail:");
	gets(staff.E);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}  
}


//修改员工工资
void ModifyPay(ListType  L,int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的工资:");
	scanf("%d",&staff.pay);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}
}


//修改员工工龄
void ModifyWorktimes(ListType  L,int pos)
{					
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的工龄:");
	scanf("%d",&staff.worktimes);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}
}


//修改员工所在部门
void ModifyDepartment(ListType  L,int pos)
{		
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("请输入员工的所在部门:");
	gets(staff.department);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("操作成功" );
	}
	else
	{
		puts("操作失败" );
	}  
}
				
//*************************************************************************				
//*************************************************************************

//进入访客模式				
void UserOperateF(ListType  L)
{
	system("cls");
	int  option = 0;	
					
	do
	{
    	//提示用户操作选择
		PrintOptionF( );
		scanf("%d", &option );
						
		//根据用户选择调用相关函数完成指定的操作
						
		switch(option )
		{
			case 1:
				UserOperateF1(L);
				break;
			case 2:
				UserOperateF2(L);
				break;
			case 3:
				UserOperateF3(L);
				break;
			case 4:
				PrntAll( L);
				break;
			default:  
				break;
		}
	}while(option );
}
	

//访客模式菜单				
void PrintOptionF( )
{
	
	system("color F5");
	puts("                            访客模式!                                ");
	puts("请选择操作：" );
	puts("1：查询员工信息            2：显示平均水平           3: 员工信息排序" );
	puts("4:输出所有员工信息");
	puts("0:返回上一级操作");
	puts(" ");
	
}

//*************************************************************************

//*************************************************************************
		
//访客查询				
void UserOperateF1(ListType  L)
{
	int  option = 0;	
	
	do
	{
		//提示用户操作选择
		PrintfOptionF1();
		scanf("%d", &option );
		
		//根据用户选择调用相关函数完成指定的操作
		
		switch(option )
		{
		case 1:
			IDChk(L);
			break;
		case 2:
			NameChk(L);
			break;
		default:  
			break;
		}
	}while(option );
}
				
//显示平均水平				
void UserOperateF2(ListType  L)
{
	int  option = 0;	
	
	do
	{
		//提示用户操作选择
		PrintfOptionF2();
		scanf("%d", &option );
		
		//根据用户选择调用相关函数完成指定的操作
		
		switch(option )
		{
		case 1:
			AverageAge( L);
			break;
		case 2:
			AveragePay( L);
			break;
		case 3:
			AverageWorktimes( L);
			break;
		default:  
			break;
		}
	}while(option );
}

//访客排序				
void UserOperateF3(ListType  L)
{
	int  option = 0;	
	
	do
	{
		//提示用户操作选择
		PrintfOptionF3();
		scanf("%d", &option );
		
		//根据用户选择调用相关函数完成指定的操作
		
		switch(option )
		{
		case 1:
			IDSort(L);
			break;
		case 2:
			NameSort(L);
			break;
		default:  
			break;
		}
	}while(option );
}



				
				
//*************************************************************************

//*************************************************************************

//比较两个员工信息的ID号是否相等
//若相等则返回TRUE，否则返回FALSE
//当调用线性表操作函数int LocateElem(ListType L, Information e, Information (*compare)(Information e1, Information e2) 
//的时候，将该函数名作为第三个参数传递给compare
Status IsEqualID(Information e1, Information e2 )
{
	if( strcmp(e1.ID, e2.ID)==0 )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


//比较两个员工信息的姓名是否相等
//若相等则返回TRUE，否则返回FALSE
//当调用线性表操作函数int LocateElem(ListType L, Information e, Information (*compare)(Information e1, Information e2) 
//的时候，将该函数名作为第三个参数传递给compare
Status IsEqualName(Information e1, Information e2 )
{
	if(strcmp(e1.name , e2.name )==0 )
	{
		return TRUE;
	}
	else
	{	
		return FALSE;
		
	}
}	
				
//********************************************************************
//********************************************************************
//打印一个成员的信息
//调用ListTraverse()函数的时候，将该函数的名字作为第二个参数传递给visit

Status  PrntOneStaff(Information staff)
{
	printf("员工的ID:%s\n",staff.ID );
	printf("员工的姓名:%s\n",staff.name);
	printf("员工的性别:%c\n",staff.sex);
	printf("员工的年龄:%d\n",staff.age);
	printf("员工的电话:%s\n",staff.number);
	printf("员工的地址:%s\n",staff.address);
	printf("员工的E-mail:%s\n",staff.E);
	printf("员工的工资:%d\n",staff.pay);
	printf("员工的工龄:%d\n",staff.worktimes);
	printf("员工所在部门:%s\n",staff.department);
	printf("\n");
	return OK;
}


//打印所有员信息

void PrntAll(ListType  L)
{
	ListTraverse(L, PrntOneStaff );
}

//查询员工信息

void PrintfOptionF1()
{
	system("color F6");
	//	system("cls");
	puts(" ");
	puts("请选择操作：" );
	puts("查询员工信息" );
	puts("1:ID  2:姓名" );
	puts("0:返回上一级操作");
	puts(" ");
}


//根据ID查询
void IDChk(ListType  L)
{
	int pos;
	Information staff;
	
	printf("请输入员工的ID:" );
	getchar();  //吃掉前面的回车键,否则后面的字符串输入时会出错
	gets(staff.ID );
	if(pos = LocateElem(L, staff, IsEqualID) )
	{
		GetElem(L, pos, staff );
		PrntOneStaff(staff );
	}
	else
	{
		puts("没有此ID成员!" );
	}
}


//根据姓名查询
void NameChk(ListType  L)
{
	int pos;
	Information staff;
	
	printf("请输入员工的姓名:" );
	getchar();  //吃掉前面的回车键,否则后面的字符串输入时会出错
	gets(staff.name);
	if(pos = LocateElem(L, staff, IsEqualName) )
	{
		GetElem(L, pos, staff );
		PrntOneStaff(staff );
	}
	else
	{
		puts("没有此姓名成员!" );
	}
}



//********************************************************************
//**********************************************************************


//显示平均水平
void PrintfOptionF2()
{
	system("color F8");
	//system("cls");
	puts(" ");
	puts("请选择操作：" );
	puts("显示平均水平" );
	puts("1:年龄   2:工资   3:工龄 ");
	puts("0:返回上一级操作");
	puts(" ");
}


//员工平均年龄
void AverageAge(ListType  L)
{
	int n=0,i=0;
	LNode  *p = L->next;
	while(p)
	{
		n+=p->data.age;
		i++;
		p=p->next;
	}
	if(!p)
	{
		printf("员工平均年龄 :%d",n/i);
	}
}


//员工平均工资
void AveragePay(ListType L)
{
	int n=0,i=0;
	LNode  *p = L->next;
	while(p)
	{
		n+=p->data.pay;
		i++;
		p=p->next;
	}
	if(!p)
	{
		printf("员工平均工资:%d",n/i);
	}
}


//员工平均工龄
void AverageWorktimes(ListType L)
{
	int n=0,i=0;
	LNode  *p = L->next;
	while(p)
	{
		n+=p->data.worktimes;
		i++;
		p=p->next;
	}
	if(!p)
	{
		printf("员工平均工龄:%d",n/i);
	}
}			

//********************************************************************
//*********************************************************************

//员工信息排序
void PrintfOptionF3()
{
	
	system("color F9");
	//	system("cls");
	puts(" ");
	puts("请选择操作：" );
	puts("员工信息排序" );
	puts("1:根据ID    2:根据姓名");
	puts("0:返回上一级操作");
	puts(" ");
}
				
//比较ID的大小
Status maxId(Information e1, Information e2 )
{
	if(strcmp(e1.ID,e2.ID)>0)
	{
		
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
}


//根据ID进行排序
void  IDSort(ListType L)
{   
	LNode *p;
	Information m;
	int i,j,size;

	size=ListLength(L);

	for (i=1;i<=size-1;i++)
	{
		p=L->next;
		for (j=1;j<=size-i;j++)
		{
			if (maxId(p->data,p->next->data))
			{
				m=p->data;
				p->data=p->next->data;
				p->next->data=m;
			}
			p=p->next;
		}
	}
	
	printf("根据ID排序成功!");
	
} 


//比较姓名的大小
Status maxNa(Information e1, Information e2 )
{
	if(strcmp(e1.name,e2.name)>0)
	{
		
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
}


//根据姓名进行排序

void	NameSort(ListType L)

{   
	LNode *p;
	Information m;
	int i,j,size;

	size=ListLength(L);

	for (i=1;i<=size-1;i++)
	{
		p=L->next;
		for (j=1;j<=size-i;j++)
		{
			
			if (maxNa(p->data,p->next->data))
			{
				m=p->data;
				p->data=p->next->data;
				p->next->data=m;
			}
			p=p->next;
		}
	}
	
	printf("根据姓名排序成功!");
	
}

//********************************************************************
//*********************************************************************



/* 程序退出时，在显示器上显示一些感谢语言，以给使用者一个好印象 */

//退出程序时出现的界面
void PrintHello1( )
{
	system("color FA");
	puts(" ");
	puts("***************************************************************" );
	puts("                   感谢使用，再见！                            " );
	puts("***************************************************************" );
	puts(" ");
	
}


//输错3次密码后输出的界面
void PrintHello2( )
{
	system("color FC");
	puts(" ");
	puts("***************************************************************" );
	puts("                   密码错误，再见！                            " );
	puts("***************************************************************" );
	puts(" ");
	
}