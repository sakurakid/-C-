#include <stdio.h>
int main(void)
{
	int e[10][10];
	int book[10];
	int dis[10];
	int n,m,i,j,k,a,b,c,t,min,u,f;
	
	scanf("%d %d",&n,&m);
	for(i = 1;i <= n;i++){
		for(j = 1;j <= n;j++){
			if(i == j)
				e[i][j]=0;
			else
			    e[i][j]=9999;
		}
	}
	
	for(i = 0;i < m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=c;
	}
	
	for(i = 1;i <= n;i++)
	{
		dis[i]=e[1][i];
	}
	
    for(i = 1;i <= n;i++)
    {
    	book[i]=1;
    }
    book[1]=0;
	
	for(i = 0;i <=n-1;i++)
	{
		min=9999;
		for(j = 1;j <= n;j++)
		{
			if(book[j]==1 && dis[j]<min)
			{
				min=dis[j];
				t=j;
			}
		}
		book[t]=0;
		for(f = 1;f <= n;f++)
		{
			if(e[t][f] < 9999)
			{
				if(dis[f]>e[t][f]+dis[t])
				{
					dis[f]=e[t][f]+dis[t];
				}
			}
		}
	}
	for(i = 1;i <= n;i++)
		{
			printf("%d ",dis[i]);
		}
		
	return 0;
}
