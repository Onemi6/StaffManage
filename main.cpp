#include <stdio.h>
#include "Operate.h"
#include "LinkList.h"


void main()
{
	LinkList  L;
	int i;

	//��ʼ������
	InitList_L( L );

	//���ļ��ж���ѧ�����ݲ�����������
	//����ļ�peoscore.dat�����ֹ��ڳ���Ŀ¼�´���
	//�ֹ���������һ�����ļ����ɳ����Զ�д��Ͷ���
	//Ҳ���԰��Լ���ģʽ��֪ʶ��������
	LoadData(L,"staffscore.dat.txt");
	
	PrintWelcome( );//��ʾ��ӭ��Ϣ

	printf("���������룺");

	scanf("%d",&i);

	if(i==12345)
	{	
		//�����û����棬�����û��Ĳ���ѡ��
		UserOperate(L);
	}
	else 
	{   
		printf("��������㻹��2�λ���\n");

		scanf("%d",&i);

		if(i==12345)

		{
			//�ڶ��ε����û����棬�����û��Ĳ���ѡ��
			UserOperate(L);
		}

		else

		{
			printf("��������㻹��1�λ���\n");

			scanf("%d",&i);

			if(i==12345)

			{
				//�����ε����û����棬�����û��Ĳ���ѡ��
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