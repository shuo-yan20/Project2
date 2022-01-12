#include"2020011375_05_01_GameCore.h"
#include<stdlib.h>
#include<time.h>
/***********************************
【函数名称】MakeRandomTarget
【函数功能】生成一个四位数的随机数（各位为1~9，且各不相同）
【参数】
【返回值】返回一个随机数
【开发者及日期】杨朔 2021.10.28
************************************/
int MakeRandomTarget()
{
	int Dig[9] = { 1,2,3,4,5,6,7,8,9 };
	int Targt[4] = { 1,2,3,4 };//随机数数组
	int ReTarget = 0;//欲返回该变量的值
	int Radom = 0;//数组的随机索引
	srand((unsigned)time(0));
	for (int i = 0; i < 4; i++)
	{
		Radom = rand() % (9 - i);//随机1个 0~(8-i) 的索引
		Targt[i] = Dig[Radom];
		if (i==3)
		{
			break;
		}
		for (int j=0;j<8-i-Radom;j++)
		{
			Dig[Radom + j] = Dig[Radom + j + 1];
		}
	}
	ReTarget = 1000 * Targt[0] + 100 * Targt[1] + 10 * Targt[2] + Targt[3];
	return ReTarget;
}
/***********************************
【函数名称】IsValidNumber
【函数功能】判断输入的四位数是否符合要求（1-9，各位不同）
【参数】输入int类型 iNumber
【返回值】返回布尔值，如果符合要求则为Ture,反之为False
【开发者及日期】杨朔 2021.10.28
************************************/
_Bool IsValidNumber(int iNumber)//可以用循环，直到符合要求break.getchar()不要忘记
{
	int Number[4] = { 1,2,3,4 };
	Number[0] = (iNumber / 1000) % 10;
	Number[1] = (iNumber / 100) % 10;
	Number[2] = (iNumber / 10) % 10;
	Number[3] = iNumber % 10;
	if (Number[0] && Number[1] && Number[2] && Number[3])//判断是否有0
	{
		//无0，判断四个数中是否存在相等的两个数
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (Number[i] == Number[j])
				{
					return 0;
				}
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
/***********************************
【函数名称】GetABCount
【函数功能】计算A和B
【参数】输入并输出数组Count
【返回值】void
【开发者及日期】杨朔 2021.10.28
************************************/
void GetABCount(int Target, int Input, int Count[2])
{
	//拆Target和Input
	int Targt[4] = { 1,2,3,4 };
	int Inpt[4] = { 1,2,3,4 };
	Targt[0] = (Target / 1000) % 10;
	Targt[1] = (Target / 100) % 10;
	Targt[2] = (Target / 10) % 10;
	Targt[3] = Target % 10;
	Inpt[0] = (Input / 1000) % 10;
	Inpt[1] = (Input / 100) % 10;
	Inpt[2] = (Input / 10) % 10;
	Inpt[3] = Input % 10;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((i == j) && (Targt[i] == Inpt[j]))
			{
				Count[0]++;
				break;
			}
			if ((i != j) && (Targt[i] == Inpt[j]))
			{
				Count[1]++;
				break;
			}
		}
	}
}