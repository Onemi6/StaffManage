#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include "Operate.h"


//*************************************************************************
/*system("color ??")             ͷ�ļ�Ϊ stdlib.h
//��ɫ����������ʮ����������ָ�� -- ��һ��Ϊ�������ڶ�����Ϊǰ����ÿ�����ֿ���Ϊ�����κ�ֵ֮һ:

  //           0 = ��ɫ         4 = ��ɫ        8 = ��ɫ         C = ����ɫ          
  //           1 = ��ɫ         5 = ��ɫ        9 = ����ɫ       D = ����ɫ
  //           2 = ��ɫ         6 = ��ɫ        A = ����ɫ       E = ����ɫ
  //           3 = ����ɫ       7 = ��ɫ        B = ��ǳ��ɫ     F = ����ɫ           
*/
//*************************************************************************

				
/* �û�������������ʱ������ʾ������ʾһЩ��ӭ��Ϣ */
void PrintWelcome( )
{
	system("color F1");
	puts(" ");		
	puts("********************************************************************" );
	puts("                     ��ӭʹ�ù�˾Ա����Ϣ����ϵͳ!" );
	puts("********************************************************************" );
	puts(" ");				
}



//*************************************************************************				
//*************************************************************************

//��һ��˵�
void UserOperate(ListType  L)
{
	int  option = 0;
	
	do
	{
		//��ʾ�û�����ѡ��
		ChoiceType();
		scanf("%d", &option );
		//�����û�ѡ�������غ������ָ���Ĳ���
		
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

//ѡ��ģʽ�˵�
void ChoiceType()
{
	system("cls");
	PrintWelcome( );
	system("color F2");
	puts(" ");	
	puts("1:����Աģʽ!");
	puts("2:�ÿ�ģʽ!  ");
	puts("0:�˳�ϵͳ!  ");	
	puts(" ");
}

//*************************************************************************				
//*************************************************************************
//�������Աģʽ�˵�ѡ��
void UserOperateG(ListType  L)	
{
	system("cls");
	int  option = 0;	
	
	do
	{
		//��ʾ�û�����ѡ��
		PrintOptionG( );
		scanf("%d", &option );
		
		//�����û�ѡ�������غ������ָ���Ĳ���
		
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


//�޸�Ա����Ϣ�˵�
void UserOperateG3(ListType  L)
{
	int  option = 0,pos;	
	Information e,staff;
	
	printf("������Ա����ID:" );
	getchar();  //�Ե�ǰ��Ļس���,���������ַ�������ʱ�����
	gets(staff.ID );
	pos = LocateElem(L, staff, IsEqualID );
	if(pos > 0 )
	{
		GetElem(L,pos,e);
		PrntOneStaff(e);
		
		do
		{
			//��ʾ�û�����ѡ��
			PrintfOptionG3();
			scanf("%d", &option );
			
			//�����û�ѡ�������غ������ָ���Ĳ���
			
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

/* ����ʾ������ʾ�û����Խ��еĲ������Լ������ķ��� */
//����Աģʽ�˵�
void PrintOptionG( )
{
					
	puts(" ");
	puts("                            ����Աģʽ !                              ");
	puts("��ѡ�������" );
	puts("1�����Ա����Ϣ            2��ɾ��Ա����Ϣ           3���޸�Ա����Ϣ" );
	puts("0:������һ������");
	puts(" ");
					
}
				
//*************************************************************************

//*************************************************************************

//�����Ա������һ��Ա��
void AddStaff(ListType  L)
{
	Information  staff;
	
	printf("������Ա����ID��(������10λ):" );
	getchar();  //�Ե�ǰ��Ļس���,���������ַ�������ʱ�����
	gets(staff.ID );
	
	//�ж����Ա����Ƿ��Ѿ����ڸ�ID�ŵ�Ա��������Ѿ����ڣ�������������
	if( LocateElem(L, staff, IsEqualID) )
	{
		puts("����ʧ�ܣ���Ա���Ѿ�����!" );
		return;
	}
	else
	{
		printf("������Ա��������(������20λ):" );
		//	getchar();
		gets(staff.name );
		
		printf("������Ա�����Ա�(��:M,Ů:W):" );
		//	getchar();
		staff.sex=getchar();
		
		printf("������Ա��������:" );
		scanf("%d", &staff.age );
		
		printf("������Ա���ĵ绰(������11λ):" );
		getchar();
		gets(staff.number);
		
		printf("������Ա����סַ(������20λ):" );
		//	getchar();
		gets(staff.address);
		
		printf("������Ա����E-mail(������20λ):" );
		//	getchar();
		gets(staff.E);
		
		printf("������Ա���Ĺ���:" );
		scanf("%d", &staff.pay );
		
		printf("������Ա���Ĺ���:" );
		scanf("%d", &staff.worktimes );
		
		printf("������Ա�������ڲ���(������20λ):" );
		getchar();
		gets(staff.department);
		
		
		//����Ա���������Ա���
		//Ϊ����������ǰ�����ӵĽ��ŵ����Ա��ǰ��
		if(InsertList_L(L, 1, staff ) )
		{
			puts("�����ɹ�!" );
		}
		else
		{
			puts("����ʧ��!" );
		}
	}
}
				
				
				
//*************************************************************************
//*************************************************************************


//�����Ա���ɾ��һ��Ա��������ѧ����ID�ž���ɾ���ĸ�Ա��
void DelStaff(ListType  L)
{
	Information staff;
	int pos;
	char i;
	
	printf("������Ա����ID��(������10λ��:" );
	getchar();  //�Ե�ǰ��Ļس���,���������ַ�������ʱ�����

	gets(staff.ID);

	//������ڸ�ID�ŵ�Ա�����򷵻��������Ա��е�λ����������ڷ���0
	pos = LocateElem(L, staff, IsEqualID ); 
	
	if(pos )   
	{
		printf("ȷ���Ƿ�ɾ����Y/N!��");
		scanf("%c",&i);
		if(i=='Y'||i=='y')
		{
			if(DeleteList_L(L, pos, staff) )
			{
				puts("ɾ���ɹ�!");
				return;
			}
			else
			{
				puts("ɾ��ʧ��!" );
			}
		}
		else
		{
			printf("δ����ɾ��!");
		}
	}
	else
	{
		puts("��ID������!" );		
	}
	
}

//*************************************************************************
//*************************************************************************


//�޸�Ա����Ϣ
void PrintfOptionG3()
{
	system("color F4");
	//	system("cls");
	puts(" ");
	puts("��ѡ�������" );
	puts("        �޸�Ա����Ϣ" );
	puts("1:����    2:�Ա�    3:����"    );
	puts("4:�绰    5:סַ    6:E-mail"  );
	puts("7:����    8:����    9:���ڲ���");
	puts("0:������һ������");
	puts(" ");
}


//�޸�Ա������
void ModifyName(ListType  L, int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա��������:");
	gets(staff.name);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}
}


//�޸�Ա���Ա�
void ModifySex(ListType  L,int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա�����Ա�:");
	staff.sex=getchar();
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}
}
				

//�޸�Ա������
void ModifyAge(ListType  L,int pos)
{						
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա��������:");
	scanf("%d",&staff.age);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}
}



//�޸�Ա���绰 
void ModifyNumber(ListType  L,int pos)
{					
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա���ĵ绰:");
	gets(staff.number);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}   
}

//�޸�Ա��סַ
void ModifyAddress(ListType  L,int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա����סַ:");
	gets(staff.address);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}         
}

//�޸�Ա��E-mail
void ModifyE(ListType  L,int pos)
{					
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա����E-mail:");
	gets(staff.E);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}  
}


//�޸�Ա������
void ModifyPay(ListType  L,int pos)
{
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա���Ĺ���:");
	scanf("%d",&staff.pay);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}
}


//�޸�Ա������
void ModifyWorktimes(ListType  L,int pos)
{					
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա���Ĺ���:");
	scanf("%d",&staff.worktimes);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}
}


//�޸�Ա�����ڲ���
void ModifyDepartment(ListType  L,int pos)
{		
	Information staff;
	getchar();
	GetElem(L,pos,staff);
	printf("������Ա�������ڲ���:");
	gets(staff.department);
	if(pos > 0 )
	{
		ListModify(L, pos, staff );
		puts("�����ɹ�" );
	}
	else
	{
		puts("����ʧ��" );
	}  
}
				
//*************************************************************************				
//*************************************************************************

//����ÿ�ģʽ				
void UserOperateF(ListType  L)
{
	system("cls");
	int  option = 0;	
					
	do
	{
    	//��ʾ�û�����ѡ��
		PrintOptionF( );
		scanf("%d", &option );
						
		//�����û�ѡ�������غ������ָ���Ĳ���
						
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
	

//�ÿ�ģʽ�˵�				
void PrintOptionF( )
{
	
	system("color F5");
	puts("                            �ÿ�ģʽ!                                ");
	puts("��ѡ�������" );
	puts("1����ѯԱ����Ϣ            2����ʾƽ��ˮƽ           3: Ա����Ϣ����" );
	puts("4:�������Ա����Ϣ");
	puts("0:������һ������");
	puts(" ");
	
}

//*************************************************************************

//*************************************************************************
		
//�ÿͲ�ѯ				
void UserOperateF1(ListType  L)
{
	int  option = 0;	
	
	do
	{
		//��ʾ�û�����ѡ��
		PrintfOptionF1();
		scanf("%d", &option );
		
		//�����û�ѡ�������غ������ָ���Ĳ���
		
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
				
//��ʾƽ��ˮƽ				
void UserOperateF2(ListType  L)
{
	int  option = 0;	
	
	do
	{
		//��ʾ�û�����ѡ��
		PrintfOptionF2();
		scanf("%d", &option );
		
		//�����û�ѡ�������غ������ָ���Ĳ���
		
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

//�ÿ�����				
void UserOperateF3(ListType  L)
{
	int  option = 0;	
	
	do
	{
		//��ʾ�û�����ѡ��
		PrintfOptionF3();
		scanf("%d", &option );
		
		//�����û�ѡ�������غ������ָ���Ĳ���
		
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

//�Ƚ�����Ա����Ϣ��ID���Ƿ����
//������򷵻�TRUE�����򷵻�FALSE
//���������Ա��������int LocateElem(ListType L, Information e, Information (*compare)(Information e1, Information e2) 
//��ʱ�򣬽��ú�������Ϊ�������������ݸ�compare
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


//�Ƚ�����Ա����Ϣ�������Ƿ����
//������򷵻�TRUE�����򷵻�FALSE
//���������Ա��������int LocateElem(ListType L, Information e, Information (*compare)(Information e1, Information e2) 
//��ʱ�򣬽��ú�������Ϊ�������������ݸ�compare
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
//��ӡһ����Ա����Ϣ
//����ListTraverse()������ʱ�򣬽��ú�����������Ϊ�ڶ����������ݸ�visit

Status  PrntOneStaff(Information staff)
{
	printf("Ա����ID:%s\n",staff.ID );
	printf("Ա��������:%s\n",staff.name);
	printf("Ա�����Ա�:%c\n",staff.sex);
	printf("Ա��������:%d\n",staff.age);
	printf("Ա���ĵ绰:%s\n",staff.number);
	printf("Ա���ĵ�ַ:%s\n",staff.address);
	printf("Ա����E-mail:%s\n",staff.E);
	printf("Ա���Ĺ���:%d\n",staff.pay);
	printf("Ա���Ĺ���:%d\n",staff.worktimes);
	printf("Ա�����ڲ���:%s\n",staff.department);
	printf("\n");
	return OK;
}


//��ӡ����Ա��Ϣ

void PrntAll(ListType  L)
{
	ListTraverse(L, PrntOneStaff );
}

//��ѯԱ����Ϣ

void PrintfOptionF1()
{
	system("color F6");
	//	system("cls");
	puts(" ");
	puts("��ѡ�������" );
	puts("��ѯԱ����Ϣ" );
	puts("1:ID  2:����" );
	puts("0:������һ������");
	puts(" ");
}


//����ID��ѯ
void IDChk(ListType  L)
{
	int pos;
	Information staff;
	
	printf("������Ա����ID:" );
	getchar();  //�Ե�ǰ��Ļس���,���������ַ�������ʱ�����
	gets(staff.ID );
	if(pos = LocateElem(L, staff, IsEqualID) )
	{
		GetElem(L, pos, staff );
		PrntOneStaff(staff );
	}
	else
	{
		puts("û�д�ID��Ա!" );
	}
}


//����������ѯ
void NameChk(ListType  L)
{
	int pos;
	Information staff;
	
	printf("������Ա��������:" );
	getchar();  //�Ե�ǰ��Ļس���,���������ַ�������ʱ�����
	gets(staff.name);
	if(pos = LocateElem(L, staff, IsEqualName) )
	{
		GetElem(L, pos, staff );
		PrntOneStaff(staff );
	}
	else
	{
		puts("û�д�������Ա!" );
	}
}



//********************************************************************
//**********************************************************************


//��ʾƽ��ˮƽ
void PrintfOptionF2()
{
	system("color F8");
	//system("cls");
	puts(" ");
	puts("��ѡ�������" );
	puts("��ʾƽ��ˮƽ" );
	puts("1:����   2:����   3:���� ");
	puts("0:������һ������");
	puts(" ");
}


//Ա��ƽ������
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
		printf("Ա��ƽ������ :%d",n/i);
	}
}


//Ա��ƽ������
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
		printf("Ա��ƽ������:%d",n/i);
	}
}


//Ա��ƽ������
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
		printf("Ա��ƽ������:%d",n/i);
	}
}			

//********************************************************************
//*********************************************************************

//Ա����Ϣ����
void PrintfOptionF3()
{
	
	system("color F9");
	//	system("cls");
	puts(" ");
	puts("��ѡ�������" );
	puts("Ա����Ϣ����" );
	puts("1:����ID    2:��������");
	puts("0:������һ������");
	puts(" ");
}
				
//�Ƚ�ID�Ĵ�С
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


//����ID��������
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
	
	printf("����ID����ɹ�!");
	
} 


//�Ƚ������Ĵ�С
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


//����������������

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
	
	printf("������������ɹ�!");
	
}

//********************************************************************
//*********************************************************************



/* �����˳�ʱ������ʾ������ʾһЩ��л���ԣ��Ը�ʹ����һ����ӡ�� */

//�˳�����ʱ���ֵĽ���
void PrintHello1( )
{
	system("color FA");
	puts(" ");
	puts("***************************************************************" );
	puts("                   ��лʹ�ã��ټ���                            " );
	puts("***************************************************************" );
	puts(" ");
	
}


//���3�����������Ľ���
void PrintHello2( )
{
	system("color FC");
	puts(" ");
	puts("***************************************************************" );
	puts("                   ��������ټ���                            " );
	puts("***************************************************************" );
	puts(" ");
	
}