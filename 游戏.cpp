#include<stdio.h>
#include<windows.h>

int a1[20][20]={0};
char a[20][20];

int shu=0;

void tu()  //目前输入方式简陋，只能这样了，用数组坐标。
{

	a[5][6]='@';
	a[5][7]='@';
	a[5][8]='@';
	a[5][9]='@';
	a[5][10]='@';
	a[5][11]='@';
	a[5][12]='@';
	a[5][13]='@';
	a[5][14]='@';
	a[5][15]='@';
	a[5][16]='@';

}

void ditu()//初始化地图，把a1和a地图清空
{
	int x,y;

	for(x=0;x<20;x++)
	{
		for(y=0;y<20;y++)
			a[x][y]=' ';
			a1[x][y]=0;
	}

}

void dy()//地图打印,把地图a打印出来
{
	int x,y;
	for(x=0;x<20;x++)
	{
		for(y=0;y<20;y++)
		printf("%c ",a[x][y]);
		printf("\n");	
	}
}

void guize()//运行规则
{
	int x,y;
		for(x=0;x<20;x++)
	{
			for(y=0;y<20;y++)
			{
			if(a[x-1][y-1]=='@')shu++;
			if(a[x-1][y]=='@')shu++;
			if(a[x-1][y+1]=='@')shu++;
			if(a[x][y-1]=='@')shu++;
			if(a[x][y]=='@')a1[x][y]=1;
			if(a[x][y+1]=='@')shu++;
			if(a[x+1][y-1]=='@')shu++;
			if(a[x+1][y]=='@')shu++;
			if(a[x+1][y+1]=='@')shu++;//判断一个格子周围是否有细胞，有则shu加1

			if(!(shu==2||shu==3))a1[x][y]=0;	//若周围有3个或2个细胞，则当前格子细胞不变，否则细胞死亡（1：新生，0：死亡）。
				if(shu==3)a1[x][y]=1;			//若周围有3个细胞，则当前格子诞生一个新细胞。
				
				shu=0;	//shu储存一个格子周围有多少个细胞数量

			}
	
	}

		for(x=0;x<20;x++)//a1是储存1和0的生死判断图,a是储存@的实际打印地图。
	{
		for(y=0;y<20;y++)
		{
		if(a1[x][y]==1)a[x][y]='@';
		if(a1[x][y]==0)a[x][y]=' ';
		}
	}

}

	int main(void)
	{
		system("color f0");//改变背景 字体颜色 system("color 0e");

		ditu();//初始化地图

		tu();//输入细胞坐标

		dy();//打印显示

		Sleep(1000);//延时

		system("cls");//清屏


		for(;;)//无限循环
		{

			guize();//规则判断

			dy();//打印显示

			Sleep(100);//延时0.1秒

			system("cls");//清屏
		
		}
		return 0;
	}	
