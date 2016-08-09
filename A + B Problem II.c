#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main()
{
    int T;
    int i,j,k;
    char num1[20][1000],num2[20][1000],c1,c2;
    int mid_num[1001],length1,length2;
    int interger_num=0,left_num=0,sum_num,max;
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        scanf("%s",num1[i]);
        scanf("%s",num2[i]);
    }
    for(i=0;i<T;i++)
    {
        left_num=0;
        length1=strlen(num1[i]);
        length2=strlen(num2[i]);
        if(length1>=length2)
            sum_num=length1;
        else
            sum_num=length2;
        max=sum_num;
        for(j=length1-1,k=length2-1;j>=0&&k>=0;j--,k--)
        {
            c1=num1[i][j]-48;
            c2=num2[i][k]-48;
            interger_num=(c1+c2+left_num)%10;
            left_num=(c1+c2+left_num)/10;
            mid_num[sum_num]=interger_num;
            sum_num--;
        }
        if(j>=0)
        {
            for(;j>=0;j--)
            {
                c1=num1[i][j]-48;
                mid_num[sum_num]=(c1+left_num)%10;
                left_num=(c1+left_num)/10;
                sum_num--;
            }
        }
        if(k>=0)
        {
            for(;k>=0;k--)
            {
                c2=num2[i][k]-48;
                mid_num[sum_num]=(c2+left_num)%10;
                left_num=(c2+left_num)/10;
                sum_num--;
            }
        }
        mid_num[sum_num]=left_num;
        printf("Case %d:\n",i+1);
        printf("%s + %s = ",num1[i],num2[i]);
        if(left_num==0)
        {
            for(j=1;j<=max;j++)
            printf("%d",mid_num[j]);
        }
        if(left_num==1)
        {
            for(j=0;j<=max;j++)
            printf("%d",mid_num[j]);
        }
        if(i!=T-1)
            printf("\n\n");
        else
            printf("\n");
    }
}
