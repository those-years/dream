#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define M 100
int n=0;																							 //定义一个全局变量
typedef struct people  
{  
	char number[10];			//工号
    char name[10];				//姓名  
    float wage;					//岗位工资  
	float pay_wages;			//薪级工资
	float post_allowance;		//职务津贴
	float merit_pay;			//绩效工资
	float should_pay;			//应发工资
	float personal_income_tax;	//个人所得税
	float real_pay;				//实发工资
}ZGGZ;//工资数据结构体


int menu_select()																					//功能选择模块
{  
    char c;  
    do  
    {  
        system("cls");        
        printf("\t\t1.查询职工工资\n");  
        printf("\t\t2.修改职工工资\n");  
        printf("\t\t3.添加职工工资 \n");  
        printf("\t\t4.删除职工工资\n");  
        printf("\t\t5.浏览职工工资\n");  
        printf("\t\t6.保存职工工资\n");  
        printf("\t\t7.退出 \n");  
        printf("\t\t请您选择(1-7):");      
        c=getchar();   
    }while(c<'1'||c>'7');//检查输入是否符合规范  
    return(c-'0');  
}  

int read(ZGGZ t[])																					//文件读取模块
{
	   int i;
       FILE *fp;//定义文件指针
       if ((fp = fopen("gx.dat", "rb")) == NULL)
       {
              printf("工资数据文件打开失败，请检查文件是否存在或损坏后重试!");
              return 0;
       }
	   fscanf(fp,"%d",&n);
	   for(i=0;i<n;i++)
		   fscanf(fp,"%10s%10s%f%f%f%f%f%f%f",t[i].number,t[i].name,&t[i].wage,&t[i].pay_wages,&t[i].post_allowance,&t[i].merit_pay,&t[i].should_pay,&t[i].personal_income_tax,&t[i].real_pay);
       fclose(fp);
       return 0;
}

int find(ZGGZ S[])						//工资查询模块  
{  
	int m,j;  
    char flag='y';  
    while(flag!='n'&&flag!='N')  
    {  
		system("cls");
        printf("\n\t\t***********查询方式************\n");  
        printf("\t\t┌------------------------------┐\n");  
        printf("\t\t│          1.查找工号          │\n");  
        printf("\t\t│          2.查找姓名          │\n");  
        printf("\t\t│          3.返回              │\n");    
        printf("\t\t└------------------------------┘\n");  
        printf("\n\t\t请选择查询方式:");  
        scanf("\t\t%d",&m);					//选择查询方式  
	
		do										//检查输入是否符合规范  
			{  
				j=0;  
				if(m!=1&&m!=2&&m!=3)  
				{     
					j=1;  
					printf("\t\t您输入的查询方式不存在,请重新输入:");  
					scanf("\t\t%d",&m);			//不符合规范则重新选择查询方式  
				}  
			}while(j); 

		if(m==1)								//工号查询
			{
				int i;							//现在查询员工序号
				int flag=0;						//标记员工有没有存在
				char gonghao[10];
				printf("\n");
				printf("请输入要查询员工的编号：");
				scanf("%s",gonghao);
				for (i = 0; i < n; i++)
				{
					if (strcmp(S[i].number,gonghao)==0)
					{
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					printf("\t\t姓名:%s\n",S[i].name);  
					printf("\t\t岗位工资:%f\n",S[i].wage);  
					printf("\t\t薪级工资:%f\n",S[i].pay_wages);  
					printf("\t\t职务津贴:%f\n",S[i].post_allowance);  
					printf("\t\t绩效工资:%f\n",S[i].merit_pay);  
					printf("\t\t应发工资:%f\n",S[i].should_pay);
					printf("\t\t个人所得税:%f\n",S[i].personal_income_tax);  
					printf("\t\t实发工资:%f\n",S[i].real_pay);  
				}
				else
				{
					printf("没有找到该编号的员工！\n");
				}
				printf("\n");
				system("pause");
			}

		if(m==2)								//姓名查询
		{
			int i;								//现在查询员工序号
			int flag=0;							//标记员工有没有存在
			char nm[10];
			printf("\n");
			printf("请输入要查询员工的姓名：");
			scanf("%s",nm);
			for (i = 0; i < n; i++)
			{
				if (strcmp(S[i].name,nm)==0)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
					for (i = 0; i < n; i++)			//防止出现重名状况
					{
						if (strcmp(S[i].name,nm)==0)
						{
							printf("\n\t\t工号:%s\n",S[i].number);  
							printf("\t\t岗位工资:%f\n",S[i].name);  
							printf("\t\t薪级工资:%f\n",S[i].wage);  
							printf("\t\t职务津贴:%f\n",S[i].pay_wages);  
							printf("\t\t绩效工资:%f\n",S[i].merit_pay);  
							printf("\t\t应发工资:%f\n",S[i].should_pay);
							printf("\t\t个人所得税:%f\n",S[i].personal_income_tax);  
							printf("\t\t实发工资:%f\n",S[i].real_pay);  
						}
					}
				
			}
			else
			{
				printf("没有找到该姓名的员工！\n");
			}
			printf("\n");
			system("pause");
		}

		if(m==3)							    	//返回
		{
			return 0;
		}

		printf("\t\t是否继续查询?(Y/N)");  
		scanf("\t\t%c",&flag);  
	}
	return 0;  
}  

void add_money(ZGGZ S[])									//自检模块 计算应发工资       
{
	for(int i=0;i<n;i++)
		S[i].should_pay=S[i].wage+S[i].pay_wages+S[i].post_allowance+S[i].merit_pay;
}

void grsds(ZGGZ S[])										//自检模块 计算个人所得税       
{
		if(should_pay>=100000)
	{
		personal_income_tax=(should_pay-100000)*0.45+29850;	//20000*1.3+15000*0.2+3000*0.15+1500*0.1+500*0.5
	}
	else if(should_pay>=80000)
	{
		personal_income_tax=(should_pay-80000)*0.4+21850;
	}
	
	else if(should_pay>=60000)
	{
		personal_income_tax=(should_pay-60000)*0.35+14850;
	}
	else if(should_pay>=40000)
	{
		personal_income_tax=(should_pay-40000)*0.3+8850;
	}

	else if(should_pay>=20000)
	{
		personal_income_tax=(should_pay-20000)*0.25+3850;
	}
	else if(should_pay>=5000)
	{
		personal_income_tax=(should_pay-5000)*0.2+850;
	}
	else if(should_pay>=2000)
	{
		personal_income_tax=(should_pay-2000)*0.15+400;
	}
	else if(should_pay>=500)
	{
		personal_income_tax=(should_pay-500)*0.1+25;
	}
	else 
	{
		personal_income_tax=should_pay*0.05;
	}
}

void add_wages(ZGGZ S[])																									//自检模块 计算实发工资	       
{
	for(int i=0;i<n;i++)
		S[i].real_pay=S[i].should_pay-S[i].tax;
}

int list(ZGGZ S[])																											//浏览模块
{
	
	int i=0;																												//当前浏览的位置
	char flag='y';																											//判断是否继续浏览
	int m,j;																												//选择浏览方式
	int k=10;																												//单次浏览最大数量,默认为10

		system("cls");
		printf("\n\t\t***********浏览方式************\n");  
		printf("\t\t┌------------------------------┐\n");  
		printf("\t\t│          1.分批次浏览        │\n");  
		printf("\t\t│          2.全部浏览          │\n");  
		printf("\t\t│          3.返回              │\n");    
		printf("\t\t└------------------------------┘\n");  
		printf("\n\t\t请选择查询方式:");  
		scanf("\t\t%d",&m);																									//选择浏览方式  
		do																													//检查输入是否符合规范  
		{  
			j=0;  
			if(m!=1&&m!=2&&m!=3)  
			{     
				j=1;  
				printf("\t\t您输入的浏览方式不存在,请重新输入:");  
				scanf("\t\t%d",&m);																							//不符合规范则重新选择浏览方式  
			}  
		}while(j); 

	if(m==1)																												//分批次浏览
	{
		printf("\n");
		printf("请输入单次浏览最大数量(默认为10):");
		scanf("%d",&k);
		printf("\n浏览结果如下:");
		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("工号:%s  %s\n",S[i].number,S[i].name);  
			printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].wage,S[i].pay_wages,S[i].post_allowance,S[i].merit_pay);  
			printf("应发工资:%f\t个人所得税:%f\t实发工资:%f",S[i].should_pay,S[i].personal_income_tax,S[i].real_pay);
			printf("\n");
			i++;		 
			if(i%k==0)
			{	
				printf("\n");
				printf("\t\t是否继续浏览?(Y/N)");  
				scanf("\t\t%c",&flag); 
			}
		}
		printf("\n工资数据已全部浏览完毕,即将自动返回主菜单\n\n");
	}
	
	if(m==2)																												//全部浏览
	{

		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("工号:%s  %s\n",S[i].number,S[i].name);  
			printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].wage,S[i].pay_wages,S[i].post_allowance,S[i].merit_pay);  
			printf("应发工资:%f\t个人所得税:%f\t实发工资:%f",S[i].should_pay,S[i].personal_income_tax,S[i].real_pay);
			printf("\n");
			i++;		 
		}
		printf("\n工资数据已全部浏览完毕,即将自动返回主菜单\n\n");
	}
	
	if(m==3)																												//返回
		{
			return 0;
		}
	return 0;
}

int main()
{
	
	ZGGZ adr[M];
	read(adr);
	add_money(adr);
	grsds(adr);
	add_wages(adr);
	for(;;)  
    {  
        switch(menu_select())  
        {  
        case 1:  
            printf("\n\t\t查询职工工资数据\n");  
            find(adr);  
            system("pause");  
            break;  
        case 2:   
            modify(adr);  
            system("pause");  
            break;  
        case 3:   
            add(adr);  
            system("pause");  
            break;  
        case 4:  
            printf("\n\t\t功能尚未完善，请尽情期待\n");  
//            del();  
            system("pause");  
            break;  
        case 5:  
            list(adr);  
            system("pause");  
            break;  
        case 6:   
            write(adr);  
            system("pause");  
            break;  

        case 7:      
            printf("\n\t\t谢谢使用，再见!\n");  //结束程序      
            printf("\n\t\t");      
            system("pause");      
            exit(0);      
        }  
    }  

	return 0;
}
