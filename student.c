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
		printf("\t\t\t|      *****ѧ������ϵͳ*****                     |\n");
		printf("\t\t\t|-------------------------------------------------|\n");
		printf("\t\t\t|          1.ѧ���ɼ�¼��                         |\n");
		printf("\t\t\t|          2.ѧ���ɼ������ɾ��                   |\n");
		printf("\t\t\t|          3.�ɼ����޸�                           |\n");  
		printf("\t\t\t|          4.ѧ���ɼ�����                         |\n");
		printf("\t\t\t|          5.�˳�����                             |\n"); 
		printf("\t\t\t---------------------------------------------------\n");
		printf("��ѡ��1-5��");
		n=getch(); 
	    }while(n<'0'||n>'5');
	    return(n-48);
}

void login()
{
	printf("\n\n\n\t\t\t  ѧ����Ϣ����ϵͳ\n\n");
    printf("\t\t\t     �汾�ţ�0.2\n\n");
    printf("\n\n\n\n\t\t\t    2017��5��10��\n\n");
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
	printf("\t\t|        ѧ������ϵͳ       |\n");
	printf("\t\t_____________________________\n");
	printf("\t\t|                           |\n");
	printf("\t\t|        ����1���          |\n");
	printf("\t\t|        ����0�˳�          |\n");
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
			printf("\t\t|        ѧ������ϵͳ       |\n");
			printf("\t\t|___________________________|\n");
			printf("\t\t|                           |\n");
			printf("\t\t|        ����1���          |\n");
			printf("\t\t|        ����0�˳�          |\n");
			printf("\t\t|___________________________|\n"); 
			printf("\t\tѧ��: ");scanf("%d",&stu->num);
			if(stu->num > 99999999||stu->num < 10000000)
			{
				printf("\t\t______________________\n");
				printf("\t\t_������8λ�Ǹ���__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ѧ��: ");scanf("%d",&stu->num);
			}
		    printf("\t\t����: ");scanf("%s",stu->name);
		    if(stu->name[0] > 0)
			{
				printf("\t\t______________________\n");
				printf("\t\t______���������뺺��__\n");
				printf("\t\t______________________\n");
				printf("\t\t������������: ");scanf("%s",stu->name);
			}
		    printf("\t\t����: ");scanf("%d",&stu->yw);
		    printf("\t\t��ѧ: ");scanf("%d",&stu->sx);
			printf("\t\tӢ��: ");scanf("%d",&stu->yy);
		    if(stu->sx<0||stu->sx>100||stu->yw<0||stu->yw>100||stu->yy<0||stu->yy>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_�ɼ�������0-100֮��__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ɼ�\n");
				printf("\t\t����: ");scanf("%d",&stu->yw);
		        printf("\t\t��ѧ: ");scanf("%d",&stu->sx);
			    printf("\t\tӢ��: ");scanf("%d",&stu->yy);
			}
			t->next=stu;
			t=stu;
		   xx = getch();
		   printf("���������밴1���˳��밴0��"); 
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
	if((fp=fopen("ѧ����Ϣ.txt","wt"))==NULL)
	{
		printf("�ļ�����233����������˳���");
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
	f1=fopen("ѧ����Ϣ.txt","rt");
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
	printf("\t\t|   1.˳������   2.��Ӣ������   3.����������     |\n");
	printf("\t\t|   4.����ѧ���� 5.ɾ��ѧ��     6.���ѧ��       |\n");
	printf("\t\t|                                                |\n");
	printf("\t\t|______________��0�˳�___________________________|\n");
	printf("\t\t��ѡ��0-6��");
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
	   printf("���������밴1���˳��밴0��");
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
	printf("\t\t%10s%10s%10s%10s%10s\n","ѧ��","����","����","��ѧ","Ӣ��","ƽ����","�ܷ�");
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
    printf("\t\t                    Ӣ������                                   \n");
	printf("\t\t%10s%10s%10s%10s%10s\n","ѧ��","����","����","��ѧ","Ӣ��","ƽ����","�ܷ�");
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
	printf("\t\t                    ��������                                   \n");
	printf("\t\t%10s%10s%10s%10s%10s\n","ѧ��","����","����","��ѧ","Ӣ��","ƽ����","�ܷ�");
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
	printf("\t\t                    ��ѧ����                                   \n");
	printf("\t\t%10s%10s%10s%10s%10s\n","ѧ��","����","����","��ѧ","Ӣ��","ƽ����","�ܷ�");
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
	printf("\t\t|______________ɾ��ѧ����Ϣ_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	printf("\t\t������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%d",&n);
	p=phead;
	for(m=phead;m!=NULL;m=m->next)
	{
		if(m->num==n)
		{
		    printf("\t\t�Ѿ��鵽��ѧ������Ϣ\n");
		    flag=0;
            break;
		}
		else
		    flag=1;  
	}
	if(flag==1)
	    printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
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
	  printf("\t\t��ѧ����Ϣ��ɾ��\n");
	}
	cr(phead);
}
void tj()
{
	struct student *phead,*stu; 
	phead=cc();
	printf("\t\t____________________________________________________\n");
	printf("\t\t|______________���ѧ����Ϣ_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	stu=(struct student*)malloc(sizeof(struct student));
	printf("\t\tѧ��: ");scanf("%d",&stu->num);
			if(stu->num > 99999999||stu->num < 10000000)
			{
				printf("\t\t______________________\n");
				printf("\t\t_������8λ�Ǹ���__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ѧ��: ");scanf("%d",&stu->num);
			}
		    printf("\t\t����: ");scanf("%s",stu->name);
		    if(stu->name[0] > 0)
			{
				printf("\t\t______________________\n");
				printf("\t\t______���������뺺��__\n");
				printf("\t\t______________________\n");
				printf("\t\t������������: ");scanf("%s",stu->name);
			}
		    printf("\t\t����: ");scanf("%d",&stu->yw);
		    printf("\t\t��ѧ: ");scanf("%d",&stu->sx);
			printf("\t\tӢ��: ");scanf("%d",&stu->yy);
		    if(stu->sx<0||stu->sx>100||stu->yw<0||stu->yw>100||stu->yy<0||stu->yy>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_�ɼ�������0-100֮��__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ɼ�\n");
				printf("\t\t����: ");scanf("%d",&stu->yw);
		        printf("\t\t��ѧ: ");scanf("%d",&stu->sx);
			    printf("\t\tӢ��: ");scanf("%d",&stu->yy);
			} 
	    stu->next=phead->next;
	    phead->next=stu;
		printf("\t\tѧ����Ϣ�Ѵ���\n");
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
	printf("\t\t|______________�޸�ѧ����Ϣ_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	printf("\t\t������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%d",&timp);
	p=phead;
	for(m=phead;m!=NULL;m=m->next)
	{
		if(m->num==timp)
		{
		    printf("\t\t�Ѿ��鵽��ѧ������Ϣ\n");
		    flag=0;
            break;
		}
		else
		    flag=1;  
	}
	if(flag==1)
	    printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
	if(flag==0)
	{
		printf("\t\t��ѧ����ԭ��Ϣ����\n");
	printf("\t\tѧ�ţ�%d\n",m->num);
	printf("\t\t������%s\n",m->name);
	printf("\t\t���ģ�%d\n",m->yw);
	printf("\t\t��ѧ��%d\n",m->sx);
	printf("\t\tӢ�%d\n\n",m->yy);
	printf("\t\t�����������ѧ������Ϣ\n");
	printf("\t\tѧ��: ");scanf("%d",&m->num);
			if(m->num > 99999999||m->num < 10000000)
			{
				printf("\t\t______________________\n");
				printf("\t\t_������8λ�Ǹ���__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ѧ��: ");scanf("%d",&m->num);
			}
		    printf("\t\t����: ");scanf("%s",m->name);
		    if(m->name[0] > 0)
			{
				printf("\t\t______________________\n");
				printf("\t\t______���������뺺��__\n");
				printf("\t\t______________________\n");
				printf("\t\t������������: ");scanf("%s",m->name);
			}
		    printf("\t\t����: ");scanf("%d",&m->yw);
		    printf("\t\t��ѧ: ");scanf("%d",&m->sx);
			printf("\t\tӢ��: ");scanf("%d",&m->yy);
		    if(m->sx<0||m->sx>100||m->yw<0||m->yw>100||m->yy<0||m->yy>100)
			{
				printf("\t\t______________________\n");
				printf("\t\t_�ɼ�������0-100֮��__\n");
				printf("\t\t______________________\n");
				printf("\t\t��������ɼ�\n");
				printf("\t\t����: ");scanf("%d",&m->yw);
		        printf("\t\t��ѧ: ");scanf("%d",&m->sx);
			    printf("\t\tӢ��: ");scanf("%d",&m->yy);
			} 
			printf("\t\t��ѧ����Ϣ���޸�\n");
			cr(phead);
	}
	printf("�����޸��밴1���˳��밴0��");
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
	printf("\t\t|______________ѧ���ɼ�����_________________________|\n");
	printf("\t\t|___________________________________________________|\n");
	printf("\t\tһ��¼����%d��ѧ���ɼ�\n",n);
	printf("\t\t���ļ�������Ϊ%d\n",jyw);
	printf("\t\t��ѧ��������Ϊ%d\n",jsx);
	printf("\t\tӢ�Ｐ������Ϊ%d\n",jyy); 
	printf("\t\t�������\n");
	printf("�˳��밴0��");  
}


