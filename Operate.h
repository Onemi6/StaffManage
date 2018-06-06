#ifndef  _UI_H_
#define  _UI_H_

#include  "LinkList.h"


/* �û�������������ʱ������ʾ������ʾһЩ��ӭ��Ϣ */
void PrintWelcome( );

//�û���������
void UserOperate(ListType  L);

//ѡ��ģʽ����
void ChoiceType();

//�����ߺ���
void UserOperateG(ListType  L);

//�޸���Ϣ����
void UserOperateG3(ListType  L);

/* ����ʾ������ʾ�û����Խ��еĲ������Լ������ķ��� */
void PrintOptionG( );

//�޸�Ա����Ϣ
void PrintfOptionG3();

//�ÿͺ���
void UserOperateF(ListType  L);

//��ѯ����
void UserOperateF1(ListType  L);

//��ʾƽ��ˮƽ����
void UserOperateF2(ListType  L);

//�������
void UserOperateF3(ListType  L);


//�ÿͲ�������
void PrintOptionF( );

//�Ƚ�����Ա����Ϣ��ID���Ƿ����
//������򷵻�TRUE�����򷵻�FALSE
//���������Ա��������int LocateElem(ListType L, Information e, Information (*compare)(ElemType e1, ElemType e2) 
//��ʱ�򣬽��ú�������Ϊ�������������ݸ�compare
Status IsEqualID(Information e1, Information e2 );


Status IsEqualName(Information e1, Information e2 );
//�����Ա������һ��Ա��
void AddStaff(ListType  L);

//�����Ա���ɾ��һ��Ա��������Ա����ID�ž���ɾ���ĸ�Ա��
void DelStaff(ListType  L);

//�޸�Ա������
void ModifyName(ListType  L, int pos);

//�޸�Ա���Ա�
void ModifySex(ListType  L, int pos);

//�޸�Ա������
void ModifyAge(ListType  L, int pos);

//�޸�Ա���绰 
void ModifyNumber(ListType  L, int pos);

//�޸�Ա��סַ
void ModifyAddress(ListType  L, int pos);

//�޸�Ա��E-mail
void ModifyE(ListType  L, int pos);

//�޸�Ա������
void ModifyPay(ListType  L, int pos);

//�޸�Ա������
void ModifyWorktimes(ListType  L, int pos);

//�޸�Ա�����ڲ���
void ModifyDepartment(ListType  L, int pos);

//��ӡһ����Ա����Ϣ
//����ListTraverse()������ʱ�򣬽��ú�����������Ϊ�ڶ����������ݸ�visit
Status  PrntOneStaff(Information staff);

//��ӡ����Ա��Ϣ
void PrntAll(ListType  L);

//��ѯԱ����Ϣ
void PrintfOptionF1();

//����ID��ѯ
void IDChk(ListType  L);

//����������ѯ
void NameChk(ListType  L);

//��ʾƽ��ˮƽ
void PrintfOptionF2();

//Ա��ƽ������
void AverageAge(ListType  L);

//Ա��ƽ������
void AveragePay(ListType L);

//Ա��ƽ������
void AverageWorktimes(ListType L);

//Ա����Ϣ����
void PrintfOptionF3();

//�Ƚ�ID��С
Status maxId(Information e1, Information e2 );

//����ID����
void IDSort(ListType L);

//�Ƚ�������С
Status maxNa(Information e1, Information e2 );
//������������
void NameSort(ListType L);

/* �����˳�ʱ������ʾ������ʾһЩ��л���ԣ��Ը�ʹ����һ����ӡ�� */

//�˳�����ʱ���ֵĽ���
void PrintHello1( );

//���3�����������Ľ���
void PrintHello2( );


#endif