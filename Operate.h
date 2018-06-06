#ifndef  _UI_H_
#define  _UI_H_

#include  "LinkList.h"


/* 用户操作界面启动时，在显示器上显示一些欢迎信息 */
void PrintWelcome( );

//用户操作界面
void UserOperate(ListType  L);

//选择模式界面
void ChoiceType();

//管理者函数
void UserOperateG(ListType  L);

//修改信息函数
void UserOperateG3(ListType  L);

/* 在显示器上显示用户可以进行的操作，以及操作的方法 */
void PrintOptionG( );

//修改员工信息
void PrintfOptionG3();

//访客函数
void UserOperateF(ListType  L);

//查询界面
void UserOperateF1(ListType  L);

//显示平均水平界面
void UserOperateF2(ListType  L);

//排序界面
void UserOperateF3(ListType  L);


//访客操作界面
void PrintOptionF( );

//比较两个员工信息的ID号是否相等
//若相等则返回TRUE，否则返回FALSE
//当调用线性表操作函数int LocateElem(ListType L, Information e, Information (*compare)(ElemType e1, ElemType e2) 
//的时候，将该函数名作为第三个参数传递给compare
Status IsEqualID(Information e1, Information e2 );


Status IsEqualName(Information e1, Information e2 );
//往线性表中添加一个员工
void AddStaff(ListType  L);

//从线性表中删除一个员工，根据员工的ID号决定删除哪个员工
void DelStaff(ListType  L);

//修改员工姓名
void ModifyName(ListType  L, int pos);

//修改员工性别
void ModifySex(ListType  L, int pos);

//修改员工年龄
void ModifyAge(ListType  L, int pos);

//修改员工电话 
void ModifyNumber(ListType  L, int pos);

//修改员工住址
void ModifyAddress(ListType  L, int pos);

//修改员工E-mail
void ModifyE(ListType  L, int pos);

//修改员工工资
void ModifyPay(ListType  L, int pos);

//修改员工工龄
void ModifyWorktimes(ListType  L, int pos);

//修改员工所在部门
void ModifyDepartment(ListType  L, int pos);

//打印一个成员的信息
//调用ListTraverse()函数的时候，将该函数的名字作为第二个参数传递给visit
Status  PrntOneStaff(Information staff);

//打印所有员信息
void PrntAll(ListType  L);

//查询员工信息
void PrintfOptionF1();

//根据ID查询
void IDChk(ListType  L);

//根据姓名查询
void NameChk(ListType  L);

//显示平均水平
void PrintfOptionF2();

//员工平均工资
void AverageAge(ListType  L);

//员工平均年龄
void AveragePay(ListType L);

//员工平均工龄
void AverageWorktimes(ListType L);

//员工信息排序
void PrintfOptionF3();

//比较ID大小
Status maxId(Information e1, Information e2 );

//根据ID排序
void IDSort(ListType L);

//比较姓名大小
Status maxNa(Information e1, Information e2 );
//根据姓名排序
void NameSort(ListType L);

/* 程序退出时，在显示器上显示一些感谢语言，以给使用者一个好印象 */

//退出程序时出现的界面
void PrintHello1( );

//输错3次密码后输出的界面
void PrintHello2( );


#endif