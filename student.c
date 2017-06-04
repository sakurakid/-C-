#include <stdio.h>
#include "student.h"
#include <stdlib.h>
#include <string.h>
int menu()
{
	    char n;	
	    do{
	    system("cls");
		printf("\t\t\t|-------------------------------------------------|\n");
		printf("\t\t\t|      *****学生管理系统*****                     |\n");
		printf("\t\t\t|-------------------------------------------------|\n");
		printf("\t\t\t|          1.学生成绩录入                         |\n");
		printf("\t\t\t|          2.学生成绩排序和删除                   |\n");
		printf("\t\t\t|          3.成绩的修改                           |\n");  
		printf("\t\t\t|          4.学生成绩分析                         |\n");
		printf("\t\t\t|          5.退出程序                             |\n"); 
		printf("\t\t\t---------------------------------------------------\n");
		printf("请选择1-5：");
		n=getch(); 
	    }while(n<'0'||n>'5');
	    return(n-48);
}

void login()
{
	printf("\n\n\n\t\t\t  学生信息管理系统\n\n");
    printf("\t\t\t     版本号：0.2\n\n");
    printf("\n\n\n\n\t\t\t    2017年5月10日\n\n");
    printf("\n\n\t\t\t      sakurakid\n");
} 
struct student *luru()
{
	
	struct student*rhead ,*r,*t,*stu;
	rhead=(struct student*)malloc(sizeof(struct student));
	t=rhead;
	rhead->next=NULL;
	char xx;
	int flag=1;
	printf("\t\t_____________________________\n");
	printf("\t\t|        学生管理系统       |\n");
	printf("\t\t_____________________________\n");
	printf("\t\t|                           |\n");
	printf("\t\t|        输入1添加          |\n");
	printf("\t\t|        输入0退出          |\n");
	printf("\t\t|___________________________|\n"); 
	while(xx!='1'&&xx!='0')
	{
		xx=getch();
	}
	if(xx=='1')
	{
		system("CLS");
		do{
			system("CLS");
			stu=(struct student*)malloc(sizeof(struct student));
			printf("\t\t_____________________________\n");
			printf("\t\t|        学生管理系统       |\n");
			printf("\t\t|___________________________|\n");
			printf("\t\t|                           |\n");
			printf("\t\t|        输入1添加          |\n");
			printf("\t\t|        输入0退出          |\n");
			printf("\t\t|___________________________|\n"); 
			printf("\t\t学号: ");scanf("%d",&stu->num);
			if(stu->num > 99999999||stu->num < 10000000)
			{
				printf("\t\t______________________\n");
				printf("\t\t_请输入8位非负数__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入学号: ");scanf("%d",&stu->num);
			}
		    printf("\t\t姓名: ");scanf("%s",stu->name);
		    if(stu->name[0] > 0)
			{
				printf("\t\t______________________\n");
				printf("\t\t______姓名请输入汉字__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入姓名: ");scanf("%s",stu->name);
			}
		    printf("\t\t语文: ");scanf("%d",&stu->yw);
		    printf("\t\t数学: ");scanf("%d",&stu->sx);
			printf("\t\t英语: ");scanf("%d",&stu->yy);
		    if(stu->sx<0||stu->sx>100||stu->yw<0||stu->yw>100||stu->yy<0||stu->yy>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_成绩请输入0-100之间__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入成绩\n");
				printf("\t\t语文: ");scanf("%d",&stu->yw);
		        printf("\t\t数学: ");scanf("%d",&stu->sx);
			    printf("\t\t英语: ");scanf("%d",&stu->yy);
			}
			t->next=stu;
			t=stu;
		   xx = getch();
		   printf("继续输入请按1，退出请按0："); 
		   while(xx!='1'&&xx!='0')
    	  {
		     xx=getch();
	      }
		}while(xx=='1');
		t->next=NULL;
   }
   return (rhead);
}

void cr(struct student *h)
{
	struct student *stu;
	FILE*fp;
	if((fp=fopen("学生信息.txt","wt"))==NULL)
	{
		printf("文件出错233，按任意键退出！");
		getch();
		exit(1); 
	}
	for(stu=h->next;stu!=NULL;stu=stu->next)
	{
		fprintf(fp,"%d %s %d %d %d\n",stu->num,stu->name,stu->yw,stu->sx,stu->yy);
	}
	fclose(fp);
}

struct student*cc()
{
	struct student*ahead,*r,*stu;
	FILE*f1;
	f1=fopen("学生信息.txt","rt");
	ahead=(struct student*)malloc(sizeof(struct student));
	ahead->next=NULL;
	r=ahead;
	while(!feof(f1))
	{
		stu=(struct student*)malloc(sizeof(struct student));
		fscanf(f1,"%d %s %d %d %d\n",&stu->num,stu->name,&stu->yw,&stu->sx,&stu->yy);	
		r->next=stu;
		r=stu;
	}
	r->next=NULL;
	fclose(f1);
	return ahead;	 
}

int menu1()
{
	system("CLS");
	char n;
	do{
	system("CLS");
	printf("\t\t__________________________________________________\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|   1.顺序排序   2.按英语排序   3.按语文排序     |\n");
	printf("\t\t|   4.按数学排序 5.删除学生     6.添加学生       |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|______________按0退出___________________________|\n");
	printf("\t\t请选择0-6：");
	n=getch(); 
	}while(n<'0'||n>'6');
	return (n-48);	    
} 

void paxu()
{
	system("CLS");
	char n;
   do{	
		switch(menu1())
	   {
		case 1:
			px1();
			printf("123");
			break;
		case 2:
			system("CLS");
			px2();
			break;
		case 3:
			system("CLS");
			px3();
			break;
		case 4:
			system("CLS");
			px4();
			break;
		case 5:
			system("CLS");
			sanch();
			break;
		case 6:
			system("CLS");
			tj();
			break;
	   }
	   printf("继续输入请按1，退出请按0：");
	   n=getch();
	   while(n!='1'&&n!='0')
    	  {
		     n=getch();
	      }
   }while(n=='1');
   if(n=='0')
       return;
}

void px1()
{
	struct student *t,*h; 
	h=cc();
	printf("\n");
	printf("\t\t%10s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","平均分","总分");
	printf("\t\t--------------------------------------------------------------\n");
	for(t=h->next;t!=NULL;t=t->next)
	{
		printf("\t\t%10d%10s%10d%10d%10d%\n",t->num,t->name,t->yw,t->sx,t->yy);
	} 
}
void px2()
{
	struct student *p,*q,*head,*t; 
	head=cc();
	int tnum;
	char tname[6];
	int tyw;
	int tsx;
	int tyy;
	for(p = head->next;p->next!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->yy < q->yy)
			{
				tnum=p->num;
				p->num=q->num;
				q->num=tnum;
				
				strcpy(tname,p->name);
				strcpy(p->name,q->name);
				strcpy(q->name,tname);
				
				tyw=p->yw;
				p->yw=q->yw;
				q->yw=tyw;
				
				tsx=p->sx;
				p->sx=q->sx;
				q->sx=tsx;
				
				tyy=p->yy;
				p->yy=q->yy;
				q->yy=tyy;
				
				
			}
		} 
	}
    printf("\t\t                    英语排序                                   \n");
	printf("\t\t%10s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","平均分","总分");
	printf("\t\t--------------------------------------------------------------\n");
	for(t=head->next;t!=NULL;t=t->next)
	{
		printf("\t\t%10d%10s%10d%10d%10d%\n",t->num,t->name,t->yw,t->sx,t->yy);
	} 
}
void px3()
{
	struct student *p,*q,*head,*t; 
	head=cc();
	int tnum;
	char tname[6];
	int tyw;
	int tsx;
	int tyy;
	for(p = head->next;p->next!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->yw < q->yw)
			{
				tnum=p->num;
				p->num=q->num;
				q->num=tnum;
				
				strcpy(tname,p->name);
				strcpy(p->name,q->name);
				strcpy(q->name,tname);
				
				tyw=p->yw;
				p->yw=q->yw;
				q->yw=tyw;
				
				tsx=p->sx;
				p->sx=q->sx;
				q->sx=tsx;
				
				tyy=p->yy;
				p->yy=q->yy;
				q->yy=tyy;		
			}
		} 
	}
	printf("\t\t                    语文排序                                   \n");
	printf("\t\t%10s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","平均分","总分");
	printf("\t\t--------------------------------------------------------------\n");
	for(t=head->next;t!=NULL;t=t->next)
	{
		printf("\t\t%10d%10s%10d%10d%10d%\n",t->num,t->name,t->yw,t->sx,t->yy);
	} 
}
void px4()
{
	struct student *p,*q,*head,*t; 
	head=cc();
	int tnum;
	char tname[6];
	int tyw;
	int tsx;
	int tyy;
	for(p = head->next;p->next!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->sx < q->sx)
			{
				tnum=p->num;
				p->num=q->num;
				q->num=tnum;
				
				strcpy(tname,p->name);
				strcpy(p->name,q->name);
				strcpy(q->name,tname);
				
				tyw=p->yw;
				p->yw=q->yw;
				q->yw=tyw;
				
				tsx=p->sx;
				p->sx=q->sx;
				q->sx=tsx;
				
				tyy=p->yy;
				p->yy=q->yy;
				q->yy=tyy;
			}
		} 
	}
	printf("\t\t                    数学排序                                   \n");
	printf("\t\t%10s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","平均分","总分");
	printf("\t\t--------------------------------------------------------------\n");
	for(t=head->next;t!=NULL;t=t->next)
	{
		printf("\t\t%10d%10s%10d%10d%10d%\n",t->num,t->name,t->yw,t->sx,t->yy);
	} 
}
void  sanch()
{
	px1();
	struct student *p,*q,*phead,*t,*m; 
	phead=cc();
	int n;
	int flag=0;
	printf("\t\t____________________________________________________\n");
	printf("\t\t|______________删除学生信息_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	printf("\t\t请输入要删除的学生学号：");
	scanf("%d",&n);
	p=phead;
	for(m=phead;m!=NULL;m=m->next)
	{
		if(m->num==n)
		{
		    printf("\t\t已经查到改学生的信息\n");
		    flag=0;
            break;
		}
		else
		    flag=1;  
	}
	if(flag==1)
	    printf("\t\t抱歉，没有查到该学生的信息\n");
	if(flag==0)
	{
		if(phead->num==n)
	   {
		  phead=phead->next;
	   }
	   else
      {
		while(p->num!=n && p->next!=NULL)
		{
			t=p;
			p=p->next;
		}
		if(p->num==n)
		{
			t->next=p->next;
		}
	  }
	  printf("\t\t该学生信息已删除\n");
	}
	cr(phead);
}
void tj()
{
	struct student *phead,*stu; 
	phead=cc();
	printf("\t\t____________________________________________________\n");
	printf("\t\t|______________添加学生信息_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	stu=(struct student*)malloc(sizeof(struct student));
	printf("\t\t学号: ");scanf("%d",&stu->num);
			if(stu->num > 99999999||stu->num < 10000000)
			{
				printf("\t\t______________________\n");
				printf("\t\t_请输入8位非负数__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入学号: ");scanf("%d",&stu->num);
			}
		    printf("\t\t姓名: ");scanf("%s",stu->name);
		    if(stu->name[0] > 0)
			{
				printf("\t\t______________________\n");
				printf("\t\t______姓名请输入汉字__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入姓名: ");scanf("%s",stu->name);
			}
		    printf("\t\t语文: ");scanf("%d",&stu->yw);
		    printf("\t\t数学: ");scanf("%d",&stu->sx);
			printf("\t\t英语: ");scanf("%d",&stu->yy);
		    if(stu->sx<0||stu->sx>100||stu->yw<0||stu->yw>100||stu->yy<0||stu->yy>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_成绩请输入0-100之间__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入成绩\n");
				printf("\t\t语文: ");scanf("%d",&stu->yw);
		        printf("\t\t数学: ");scanf("%d",&stu->sx);
			    printf("\t\t英语: ");scanf("%d",&stu->yy);
			} 
	    stu->next=phead->next;
	    phead->next=stu;
		printf("\t\t学生信息已存入\n");
		cr(phead);
}
void xg()
{
	system("CLS");
	char n;
	do{
	system("CLS");
	px1();
	struct student *p,*q,*phead,*t,*m; 
	int flag=0;
	int timp; 
	phead=cc();
	printf("\t\t____________________________________________________\n");
	printf("\t\t|______________修改学生信息_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	printf("\t\t请输入要修改的学生学号：");
	scanf("%d",&timp);
	p=phead;
	for(m=phead;m!=NULL;m=m->next)
	{
		if(m->num==timp)
		{
		    printf("\t\t已经查到改学生的信息\n");
		    flag=0;
            break;
		}
		else
		    flag=1;  
	}
	if(flag==1)
	    printf("\t\t抱歉，没有查到该学生的信息\n");
	if(flag==0)
	{
		printf("\t\t该学生的原信息如下\n");
	printf("\t\t学号：%d\n",m->num);
	printf("\t\t姓名：%s\n",m->name);
	printf("\t\t语文：%d\n",m->yw);
	printf("\t\t数学：%d\n",m->sx);
	printf("\t\t英语：%d\n\n",m->yy);
	printf("\t\t请重新输入该学生的信息\n");
	printf("\t\t学号: ");scanf("%d",&m->num);
			if(m->num > 99999999||m->num < 10000000)
			{
				printf("\t\t______________________\n");
				printf("\t\t_请输入8位非负数__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入学号: ");scanf("%d",&m->num);
			}
		    printf("\t\t姓名: ");scanf("%s",m->name);
		    if(m->name[0] > 0)
			{
				printf("\t\t______________________\n");
				printf("\t\t______姓名请输入汉字__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入姓名: ");scanf("%s",m->name);
			}
		    printf("\t\t语文: ");scanf("%d",&m->yw);
		    printf("\t\t数学: ");scanf("%d",&m->sx);
			printf("\t\t英语: ");scanf("%d",&m->yy);
		    if(m->sx<0||m->sx>100||m->yw<0||m->yw>100||m->yy<0||m->yy>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_成绩请输入0-100之间__\n");
				printf("\t\t______________________\n");
				printf("\t\t重新输入成绩\n");
				printf("\t\t语文: ");scanf("%d",&m->yw);
		        printf("\t\t数学: ");scanf("%d",&m->sx);
			    printf("\t\t英语: ");scanf("%d",&m->yy);
			} 
			printf("\t\t该学生信息已修改\n");
			cr(phead);
	}
	printf("继续修改请按1，退出请按0：");
	n=getch();
	while(n!='1'&&n!='0')
    {
	    n=getch();
	}	
	}while(n=='1');
   if(n=='0')
       return;
} 
void fx()
{
	struct student *p,*q,*phead,*t,*m; 
	int flag=0;
	int jyw=0;
	int jsx=0;
	int jyy=0;
	int timp;
	int n=0; 
	phead=cc();
	p=phead;
	for(t=p->next;t!=NULL;t=t->next)
	{
		n++;
		if(t->sx>=60)
		    jsx++;
		if(t->yw>=60)
		    jyw++;
		if(t->yy>=60)
		    jyy++;
	} 
	printf("\t\t____________________________________________________\n");
	printf("\t\t|______________学生成绩分析_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	printf("\t\t一共录入了%d个学生成绩\n",n);
	printf("\t\t语文及格人数为%d\n",jyw);
	printf("\t\t数学及格人数为%d\n",jsx);
	printf("\t\t英语及格人数为%d\n",jyy); 
	printf("\t\t分析完毕\n");
	printf("退出请按0：");  
}


