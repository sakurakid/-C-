#include <stdio.h>
#include <malloc.h>
typedef struct node{
	struct node *llink;
	int date;
	struct node *rlink;
}stud;

stud*creat(int n);
stud*search(stud*h,int n);
void insert(stud*p);

stud*creat(int n)
{
	stud*p,*h,*s;
	int i;
	if((h=(stud*)malloc(sizeof(stud)))==NULL)
	{
		printf("233�ж�");
		exit(0);
	}
	h->date=0;
	h->llink=NULL;
	h->rlink=NULL;
	p=h;
	for(i = 0;i < n;i++)
	{
		if((s=(stud*)malloc(sizeof(stud)))==NULL)
		{
			printf("233�ж�");
			exit(0);
		}
		p->rlink=s;
		printf("�����%d������\n",i+1);
		scanf("%d",&s->date);
		s->llink=p;
		s->rlink=NULL;
		p=s;
	}
	h->llink=s;
	p->rlink=h;
	return h;
}
stud*search(stud*h)
{
	stud*p;
	int a,n;
	printf("���������ѯ����\n");
	scanf("%d",&n);
	p=h->rlink;
	while(p!=h)
	{
		a=p->date;
		if(a==n)
		{
			printf("�е�233\n");
			break;
		}
		else
		{
			p=p->rlink;
		}
		   
	}
}

void print(stud *h)
{
	int n;
	stud*t;
	t=h->rlink;
	while(t!=h)
	{
		printf("%d ",t->date);
		t=t->rlink;
	}
}


void insert(stud*p)
{
	int a;
	stud*s;
	if((s=(stud*)malloc(sizeof(stud)))==NULL)
		{
			printf("233�ж�");
			exit(0);
		}
	printf("���������������\n");
	scanf("%d",&s->date);
	s->rlink=p->rlink;
	p->rlink=s;
	s->llink=p;
	(s->rlink)->llink=s; 
}

int main(void)
{
	stud*head;
	int n;
	scanf("%d",&n);
	head=creat(n);
	print(head);
	search(head);
	print(head);
	return 0;
}
