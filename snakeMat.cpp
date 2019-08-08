#include<stdio.h>
int main()
{
    int n,num,matrix[30][30];
    int i,j;
    while(scanf("%d",&n)>0)
    {
        num=0;
        //遍历连接上三角的斜线，包括对角线
        for(i=0; i<n; ++i)
        {
            if(i%2==0)  //则最小值在下面
            {
                for(j=i; j>=0; --j) //上三角第i条斜线有i个点
                    matrix[j][i-j]=++num;   //有i个点所以行递减i次，每个点的行列相加等于i所以列=i-行
            }
            else    //否则最小值在上面
            {
 
                for(j=0; j<=i; ++j) //和最小值在下面类似
                    matrix[j][i-j]=++num;
            }
        }
 
        //遍历连接下三角的斜线，比上三角复杂
        for(i=n-2; i>=0; --i)   //为了通过每条斜线的点数i控制行列关系所以递减i
        {
            if(i%2==0)  //则最小值在下面
            {
                int tem=n;  //最小值在下面用tem控制行递减
                for(j=n-1-i; j<n; ++j)  //列等于总列数减去该斜线的总点数i，减一是为了对应0
                    matrix[--tem][j]=++num;
            }
            else    //否则最小值在上面
            {
                int tem=n;  //同上
                for(j=n-1-i; j<n; ++j)
                    matrix[j][--tem]=++num;
            }
        }
        //输出蛇形阵
        for(i=0; i<n; ++i)
        {
            for(j=0; j<n; ++j)
                printf("%4d",matrix[i][j]);
            printf("\n");
        }
 
    }
    return 0;
}