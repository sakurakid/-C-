#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person                               //����ṹ��
{
	char num[10];   //ѧ��
	char name[15]; //����
	int age;      //����
	int en;      //Ӣ��ɼ�
	int ji;      //רҵ�ɼ�
}person;
person per[100];  //����100
char filename[20];                                      //����ȫ�ֱ���
void logon()                                            //��½���� ʹϵͳ��������
{
 printf("\n\n\n\t\t\t  ѧ����Ϣ����ϵͳ\n\n");
 printf("\t\t\t     �汾�ţ�2.0\n\n");
 printf("\n\n\n\n\t\t\t    2012��3��10��\n\n");
 printf("\t\t\t   C��**��514��\n");
 printf("\n\n\t\t\t     Ace_cm_liu\n");
 printf("\n\n\t\t\t    ���ݼ�����\n");
 system("pause");
}
int menu_filename()
   {
	  system("cls");
	  printf("��������Ҫ�������ļ���:");
	  scanf("\t%s",filename);
    }
    //*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
int menu_select()                              //�˵�ѡ��ϵͳ����
{
	 char c;
	  do{
		system("cls");
		printf("\t\t �q�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");
		printf("\t\t��         ѧ����Ϣ����ϵͳ         ��\n");
        printf("\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s\n");
		printf("\t\t   ��������������������������������\n");
		printf("\t\t   �� 1. ��Ӽ�¼    2. ��ʾ��¼ ��\n");
		printf("\t\t   ��                            ��\n");
		printf("\t\t   �� 3. ��Ϣ��ѯ    4. ���ݼ��� ��\n");
		printf("\t\t   ��                            ��\n");
		printf("\t\t   �� 5. �޸ļ�¼    6. ɾ����¼ ��\n");
		printf("\t\t   ��                            ��\n");
		printf("\t\t   �� 0. �˳�����                ��\n");
		printf("\t\t   ��������������������������������\n");
		printf("\t\t����ѡ��(0-6):");
		c=getchar();
	 }while(c<'0'||c>'6');
		return (c-'0');                                      //�ַ���ȥ��0���õ�������������//
}

	//*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void add()                                      //�ɼ���¼������Ӻ���
  {
	FILE *fp;
	int i=0,n=0;
	char sign='y';                              //���ȶ���sing='y'
	system("cls");                                //��������  ϵͳ�е���
	while(sign!='n'&&sign!='N')                    //��ʵֻ�е�����N��nʱ������ѭ��
      {
	    printf("             ----ѧ����¼���----\n");
	    printf("ѧ�ţ�\n");
	    scanf("\t%s",per[i].num);
	    printf("����:\n");
	    scanf("\t%s",per[i].name);
	    printf("���䣺\n");
	    scanf("\t%d",&per[i].age);
	    printf("Ӣ�\n");
	    scanf("\t%d",&per[i].en);
	    printf("רҵ��\n");
	    scanf("\t%d",&per[i].ji);
        printf("�Ƿ�������?(y/n)");
	    scanf("\t%c",&sign);
	    i++;
	    n=n+1;
	    system( "cls ");
   }system("pause");                                     //�ȴ�����

   if((fp=fopen(filename,"a"))==NULL)                    //��2������ʽ�����ļ�β׷��//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;                                         //����ļ����ִ��� �ͷ���
	   }
		for(i=0;i<n;i++)
		if(fwrite(&per[i],sizeof(person),1,fp)!=1)      //��2������ʽд���ļ���//һ��д��һ������//
	    printf("file write error\n");
	    fclose(fp);                                       //�ر��ļ�
	    system("pasue");
  }
     //*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
  void scan()                        //��ʾ��¼  ����ȫ����Ϣ���
   {
	void amend();                         //�����޸ĺ���//
	char sign='y';
	FILE *fp;
    int i=0,n;
    system("cls");
      if((fp=fopen(filename,"r"))==NULL)             //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }
    while(!feof(fp))                              //һֱ��ȡ֪���ļ�β����
	{
		fread(&per[i],sizeof(person),1,fp);  //��2���Ʒ�ʽ���ļ���Ϣ���������ڴ���//һ�ζ�ȡһ��//
		 i++;
     }
    fclose(fp);
	 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
     printf("        ѧ��            ����           ����    Ӣ��    רҵ\n");
	 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    for(n=0;n<i-1;n++)                             //ѭ��ȫ�����
     printf("\t%s \t%s \t\t%d \t%d \t%d\n",per[n].num,per[n].name,per[n].age,per[n].en,per[n].ji);
	 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	 system("pause");
	 system("cls");
	 printf("�Ƿ���Ҫ�޸�?(y/n)");
	 scanf("\t%c",&sign);
	if(sign!='n'&&sign!='N')                    //ѡ���Ƿ������������޸�//
	 amend();
	 system("pause");

  }

     //*********************************************************************//
	 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                    //���ݲ�ѯ//
  void query()                     //ѧ����Ϣ�Ĳ�ͬ��ʽ��ѯ
   {
	FILE *fp;
	int i=0,n=0;
	int m;
	system("cls");
	printf("\t\n��ѡ���ѯ��ʽ:\n");
    printf("\t����������������\n");
	printf("\t��1--ģ����ѯ ��\n");
    printf("\t��2------���� ��\n");
    printf("\t��3------ѧ�� ��\n");
    printf("\t��4------���� ��\n");
    printf("\t����������������\n");
	printf("��������Ҫ��ѯ�ķ�ʽ\n");
	scanf("%d",&m);
	while(m!=1&&m!=2&&m!=3&&m!=4)
		{
			printf("������������²�ѯ\n");
	        scanf("%d",&m);
	    }
      if((fp=fopen(filename,"r"))==NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }

    while(!feof(fp))
	{
		fread(&per[i],sizeof(person),1,fp);                      //��2���Ʒ�ʽ���ļ���Ϣ���������ڴ���//һ�ζ�ȡһ��//
	    i++;n=n+1;
     }

       if(m==1)                                                 //ģ����ѯ
      {
	    char s[3];                                             //���������������ռ���ֽ� /һ������ռ2���ֽ� ���һ��β���˴�С�����
		int i=0;
		system("cls");
        printf("\t���������ѯ����:");
		scanf("%s",s);
		for(i=0;i<n-1;i++)                                               //�ļ���Ϣ�Ѿ���ȡ�������� �˴�����ѭ��������һ���Ĳ���
		{

		  if(per[i].name[0]==s[0]&&per[i].name[1]==s[1])              //�Ƚ�per[i].name���������ǰ�����ַ��Ƿ���ͬ//
		    {
		        printf("\tѧ��: %s\n",per[i].num);
		        printf("\t����: %s\n",per[i].name);
		        printf("\t����: %d\n",per[i].age);
		        printf("\tӢ��: %d\n",per[i].en);
		        printf("\t�����: %d\n",per[i].ji);
	     	    printf("\t                     \n");
	        }
		}
	 }

	if(m==2)                                            //������ѯ
	   {
		char s[20];
		int i=0;
		printf("\t���������ѯ������:");
		scanf("\t%s",s);
		while(strcmp(per[i].name,s)!=0&&i<n) i++;            //�Ƚ�per[i].name�������������Ƿ���ͬ//
		if(i==n)
		{
			printf("\tͨѶ¼��û�д���!\n");
			system("pause");
			return;
		}
		  printf("\tѧ��: %s\n",per[i].num);
		  printf("\t����: %s\n",per[i].name);
		  printf("\t����: %d\n",per[i].age);
		  printf("\tӢ��: %d\n",per[i].en);
		  printf("\t�����: %d\n",per[i].ji);
	     }
	if(m==3)                                                            //ѧ�Ų�ѯ
		{
		  char s[15];
		  int i=0;
		  printf("���������ѯ��ѧ�ţ�");
		  scanf("\t%s",s);
		 while(strcmp(per[i].num,s)!=0&&i<n)i++;                       //�Ƚ�per[i].name��������ѧ���Ƿ���ͬ//
			if(i==n)
			{
				printf("\tͨѶ¼��û�д���!\n");
				system("pause");
			    return;
			}
			printf("\tѧ��: %s\n",per[i].num);
		    printf("\t����: %s\n",per[i].name);
		    printf("\t����: %d\n",per[i].age);
		    printf("\tӢ��: %d\n",per[i].en);
		    printf("\t�����: %d\n",per[i].ji);
		  }
		  fclose(fp);
		  system("pause");
  }
	//*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                         //����ͳ��//
 void date()
  {
	FILE *fp;
	struct person temp;                               //������ʱ�������ڽ���ʱ���������Ϣ���ں���Ľ���//
	int sum;                                         //�ܷ�
	int s[100];
    int i=0,n=0;
	int j,k,t;
	int m;
	system("cls");
	printf("\t\nѡ������ʽ:\n");
    printf("\t����������������\n");
    printf("\t��1------Ӣ�� ��\n");
    printf("\t��2----����� ��\n");
	printf("\t��3----  �ܷ� ��\n");
    printf("\t��4------���� ��\n");
    printf("\t����������������\n");
	printf("��������Ҫ����ķ�ʽ\n");
	scanf("%d",&m);
	system("cls");
	while(m!=1&&m!=2&&m!=3&&m!=4)
		{
			printf("�����������������\n");
	        scanf("%d",&m);
	    }
     if((fp=fopen(filename,"r"))==NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }

   while(!feof(fp))                               //һֱ���ж�ȡֱ���ļ�β//
	 {
	   fread(&per[i],sizeof(person),1,fp);
	   i++;n=n+1;
      }
   if(m==1)
	  {
	  for(i=0;i<n-1;i++)                           //����ð�ݷ���������//
	  {
		 k=i;
	    for(j=i+1;j<n;j++)
	    if(per[j].en>per[k].en)                              //����//�Ƚϴ�С//
	    k=j;
		temp=per[k];per[k]=per[i];per[i]=temp;                  //����������ʱ�������ݽ���//
		}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("        ѧ��            ����           ����    Ӣ��    רҵ\n");
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				for(i=0;i<n-1;i++)
	        printf("\t%s \t%s \t\t%d \t%d \t%d\n",per[i].num,per[i].name,per[i].age,per[i].en,per[i].ji);
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		fclose(fp);
		}

	if(m==2)
	  {
		for(i=0;i<n-1;i++)
		 {
			  k=i;
	       for(j=i+1;j<n;j++)
			if(per[j].ji>per[k].ji)
			  k=j;
		    temp=per[k];per[k]=per[i];per[i]=temp;
		  }
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("        ѧ��            ����           ����    Ӣ��    רҵ\n");
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	    for(i=0;i<n-1;i++)
	        printf("\t%s \t%s \t\t%d \t%d \t%d\n",per[i].num,per[i].name,per[i].age,per[i].en,per[i].ji);
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		  fclose(fp);
	    }
	if(m==3)
	  {
		for(i=0;i<n-1;i++)
	       {
			 sum=0;
			 sum=per[i].en+per[i].ji;
			 s[i]=sum;                                           // ��һ�����������������Ϣ����//
	        }
	        for(i=0;i<n-1;i++)
		      {
			    k=i;
	            for(j=i+1;j<n;j++)
				  if(s[j]>s[k])
					k=j;
		        t=s[k];s[k]=s[i];s[i]=t;                          //�����ִܷ�С��������//
		        temp=per[k];per[k]=per[i];per[i]=temp;            //��֮ʹ��������Ӧ˳�����ִܷ�Сһ������//
		        }
				  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                  printf("        ѧ��            ����           ����    Ӣ��    רҵ    �ܷ�   \n");
	              printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				for(i=0;i<n-1;i++)
	              printf("\t%s \t%s \t\t%d \t%d \t%d \t%d\n",per[i].num,per[i].name,per[i].age,per[i].en,per[i].ji,s[i]);
	              printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				fclose(fp);
      }
      system("pause");
	}

	//*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                                 // �����޸�//
void amend()
  {
	FILE *fp;
	int i=0,n=0;
    char s[15];
	int m;
	system("cls");
	printf("\t\n��ѡ���޸ķ�ʽ:\n");
    printf("\t����������������\n");
    printf("\t��1------���� ��\n");
    printf("\t��2------ѧ�� ��\n");
    printf("\t��3------���� ��\n");
    printf("\t����������������\n");
	printf("��������Ҫ�޸ĵķ�ʽ\n");
	scanf("%d",&m);
	while(m!=1&&m!=2&&m!=3)
		{
			printf("��������������޸�\n");
	        scanf("%d",&m);
	    }
	 if((fp=fopen(filename,"r"))==NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }
	while(!feof(fp))
	{
		fread(&per[i],sizeof(person),1,fp);
		i++;n=n+1;
	}i=0;
	fclose(fp);
	system("cls");
  if(m==1)
	{
	  char s[20];
	  int i=0;
	  printf("\t���������޸ĵ�����:");
	  scanf("\t%s",s);
	  while(strcmp(per[i].name,s)!=0&&i<n) i++;                           //���бȽ� �ҵ�����Ҫ����Ϣ
		if(i==n)
		 {
			printf("\tͨѶ¼��û�д���!\n");
			return;
		 }
	    else{
	         printf("ѧ�ţ�\n");
	         scanf("\t%s",per[i].num);
	         printf("����:\n");
	         scanf("\t%s",per[i].name);
	         printf("���䣺\n");
	         scanf("\t%d",&per[i].age);
	         printf("Ӣ�\n");
	         scanf("\t%d",&per[i].en);
	         printf("רҵ��\n");
	         scanf("\t%d",&per[i].ji);
	      }
      }
	if(m==2)
	   {
		char s[15];
		int i=0;
		printf("���������޸ĵ�ѧ�ţ�");
		scanf("\t%s",s);
		while(strcmp(per[i].num,s)!=0&&i<n)i++;
		   if(i==n)
			{
			 printf("\tͨѶ¼��û�д���!\n");
			 return;
			}
			else{
	             printf("ѧ�ţ�\n");
	             scanf("\t%s",per[i].num);
	             printf("����:\n");
	             scanf("\t%s",per[i].name);
	             printf("���䣺\n");
	             scanf("\t%d",&per[i].age);
	             printf("Ӣ�\n");
	             scanf("\t%d",&per[i].en);
	             printf("רҵ��\n");
	             scanf("\t%d",&per[i].ji);
			    }
	    }
	 if((fp=fopen(filename,"w"))==NULL)                            //�����޸ĺ���������д���ļ���
	      {
		    printf("cannot open the files\n");
            return;
	       }
		for(i=0;i<n-1;i++)
		  if(fwrite(&per[i],sizeof(person),1,fp)!=1)
	      printf("file write error\n");
		  fclose(fp);
		  printf("��Ϣ�Ѿ��޸ĳɹ�\n");
		  system("pause");
}
      //*********************************************************************//
	  //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                                        //����ɾ��//
void delet()
  {
    FILE *fp;
    char s[10];
	int i=0,n=0;
	  if((fp=fopen(filename,"r"))==NULL)                  //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }

    while(!feof(fp))
	{
	  fread(&per[i],sizeof(person),1,fp);               //���ļ���Ϣ��ȡ�������ڴ���//
	  i++;n=n+1;
     }
    fclose(fp);
	 if((fp=fopen(filename,"w"))==NULL)                 //��2����д�뷽ʽ���ļ�//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }
	printf("ѧ��ѧ�ţ�");
	scanf("%s",s);
    for(i=0;i<n-1;i++)
	 if(!(strcmp(per[i].num,s)==0))                    //�ҵ�����ƥ�����Ϣ���в���//   ����������Ͼ�д����������������ݴ����ݾ�������ɾ����
	  fwrite(&per[i],sizeof(person),1,fp)!=1;             //��2���Ʒ�ʽ����Ϣ���ڴ���д���ļ�����//
	 fclose(fp);
	 printf("����ɾ���ɹ�");
	 system("pause");
}
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
	 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                             //����switch�����в˵�ѡ��//
  int main()
  {
	  int n=0;
	  logon();
	  menu_filename();                                         //����ȫ�ֱ����ļ���
	  for(;;)                                                 //ѭ��ʹ��������ֱ��������������
	  {
		  switch(menu_select())                               // �����ĵ���//
		  {
		  case 1:
			  printf("\t\t *^_^*ѧ����¼��� *^_^*\n");
			  add();
			  break;
		  case 2:
			  printf("\t\t *^_^*ѧ����Ϣ��� *^_^*\n");
			  scan();
			  break;
		  case 3:
			  printf("\t\t *^_^*ѧ����Ϣ��ѯ *^_^*\n");
			  query();
              break;
		  case 4:
			  printf("\t\t *^_^*���ݼ��� *^_^*\n");
			  date();
			  break;
		  case 5:
			  printf("\t\t *^_^*�����޸� *^_^*\n");
              amend();
			  break;
		  case 6:
			   printf("\t\t *^_^*����ɾ�� *^_^*\n");
			   delet();
			   break;
		  case 0:
		        printf("\n\t\tллʹ�ã��ټ�!\n");
		        printf("\n\t\t");
		        system("pause");
		        exit(0);
		  }
	  }
	  system("pause");
  }
