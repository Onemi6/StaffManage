#include <stdio.h>
#include "Operate.h"
#include "LinkList.h"


void main()
{
	LinkList  L;
	int i;

	//初始化链表
	InitList_L( L );

	//从文件中读出学生数据并插入链表中
	//这个文件peoscore.dat必须手工在程序目录下创建
	//手工创建的是一个空文件，由程序自动写入和读出
	//也可以按自己的模式和知识保存数据
	LoadData(L,"staffscore.dat.txt");
	
	PrintWelcome( );//显示欢迎信息

	printf("请输入密码：");

	scanf("%d",&i);

	if(i==12345)
	{	
		//调用用户界面，接受用户的操作选择
		UserOperate(L);
	}
	else 
	{   
		printf("密码错误，你还有2次机会\n");

		scanf("%d",&i);

		if(i==12345)

		{
			//第二次调用用户界面，接受用户的操作选择
			UserOperate(L);
		}

		else

		{
			printf("密码错误，你还有1次机会\n");

			scanf("%d",&i);

			if(i==12345)

			{
				//第三次调用用户界面，接受用户的操作选择
				UserOperate(L);
			}

			else

			{
				PrintHello2( );	
			}
		}

	}


	SaveData(L,"staffscore.dat.txt");

	DestroyList_L( L );		
}