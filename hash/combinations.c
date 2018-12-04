#include<stdio.h>
int main()
{
        int i,j,k,l,m,n,o,p,q,r,count=0;
        for(i=0;i<=9;i++)
        for(j=0;j<=9;j++)
        for(k=0;k<=9;k++)
        for(l=0;l<=9;l++)
        for(m=0;m<=9;m++)
//      for(n=0;n<=9;n++)
//      for(o=0;o<=9;o++)
//      for(p=0;p<=9;p++)
//      for(q=0;q<=9;q++)
//      for(r=0;r<=9;r++)       
        {
                printf("%d%d%d%d%d\n",i,j,k,l,m);
                count++;
        }
        printf("\n#The total combination %d\n",count);
        return 0;
}