#include<stdio.h>
#include"2020011375_05_01_GameCore.h"
int main(int argc, char* argv[])
{
    int iTarget = 0;
    //���������в�������Ϊ2������
    if (argc == 2) 
    {
        //iTarget = atoi(argv[1]);
        scanf("%d", &iTarget);
    }
    else 
    {
        iTarget = MakeRandomTarget();
    }
    int Target = 0;
    Target = MakeRandomTarget();//���������
    while (1)
    {
        int ABCount[2] = { 0,0 };//����A B
        ABCount[0] = 0;
        ABCount[1] = 0;
        while (1)//�Ƿ�Ϊ�������֣������˳�ѭ��
        {
            scanf("%d", &iTarget);
            getchar();
            if (IsValidNumber(iTarget))
            {
                break;
            }
        }
        GetABCount(Target, iTarget, ABCount);
        if (ABCount[0] == 4 && ABCount[1] == 0)
        {
            printf("Bingo!\n");
            break;
        }
        else
        {
            printf("%dA%dB\n", ABCount[0], ABCount[1]);
        }
    }
    return 0;
}

