#include "stdio.h"
#include "stdlib.h"

void main()
{
    int T,num_inter[20],*interger[20];
    int i,j;
    int present_max,sub_seq,head_seq,end_seq,mid_head,mid_end;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&num_inter[i]);
        interger[i]=(int *)malloc(sizeof(int)*num_inter[i]);
        for(j=0;j<num_inter[i];j++)
        {
            scanf("%d",&interger[i][j]);
        }
    }
    for(i=0;i<T;i++)
    {
        present_max=interger[i][0];
        sub_seq=interger[i][0];
        head_seq=1;
        end_seq=1;
        mid_head=1;
        mid_end=1;
        for(j=1;j<num_inter[i];j++)
        {
            if(interger[i][j]<=present_max+interger[i][j])
            {
                present_max=present_max+interger[i][j];
                mid_end=j+1;
            }
            else
            {
                present_max=interger[i][j];
                mid_head=j+1;
                mid_end=j+1;
            }
            if(present_max>sub_seq)
            {
                sub_seq=present_max;
                head_seq=mid_head;
                end_seq=mid_end;
            }
        }
        printf("Case %d:\n",i+1);
        printf("%d %d %d\n",sub_seq,head_seq,end_seq);
        if(i<T-1)
            printf("\n");
    }
}
