#include "stdio.h"
#include "stdlib.h"
#include "string.h"
main()
{
	int num,color_num[1000]={0},i,j,mid,max;
	char color[1000][16];
	scanf("%d",&num);
	while(num!=0)
    {
        color_num[0]=1;
        for(i=0;i<num;i++)
        {
            scanf("%s",color[i]);

            for(j=0;j<i;j++)
            {
                if(strcmp(color[i],color[j])==0)
                {
                    color_num[j]++;
                    color_num[i]=color_num[j];
                }
            }
        }
        max=color_num[0];
        mid=0;
        for(i=0;i<num;i++)
        {
            if(color_num[i]>max)
            {
                max=color_num[i];
                mid=i;
            }
        }
        printf("%s\n",color[mid]);
        for(i=0;i<1000;i++)
            color_num[i]=0;
        scanf("%d",&num);
    }
}

