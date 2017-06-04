#include <stdio.h>
#include <stdlib.h>
#include "student.h"
 #include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	    system("color 4F");
	    login();
        //struct student *head;
	    Sleep(1000);
		while(1)
		{
			switch(menu())
			{
				case 1:
					system("CLS");
					printf("\t\t________学生成绩添加_______");
				    head=luru();
				    cr(head);
				    int choice;
					scanf("%d",&choice);
					if(choice==0)
						break;
				case 2:
					system("CLS");
					//printf("\t\t_________学生成绩排序和删除___\d");
					paxu();
					int end;
					scanf("%d",&end);
					if(end==0)
						break;
				case 3:
					system("CLS");
					printf("\t\t__________成绩的修改__________");
				    xg();
					int a;
					scanf("%d",&a);
					if(a==0)
						break;
				case 4:
					system("CLS");
					printf("\t\t___________学生信息分析_______");
					fx();
					int b; 
					scanf("%d",&b);
					if(b==0)
						break;
				case 5:
				    system("CLS");
					printf("\t\t___________谢谢使用哈_______\n");
					Sleep(1000);
					exit(-1);	
					break; 
			}
			system("PAUSE");
		}
	return 0;
}
