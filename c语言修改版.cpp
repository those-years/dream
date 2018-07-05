/**************************************
Copyright (C), 2018, 广西民族大学17软件工程

File name:课程设计c语言修改版

Author: 林建行	Version: C语言修改版	Date:2018.7.1

Description:  本系统的主要功能是：职工工资记录的录入、查询、修改、添加、删除及数据保存功能。
              根据现有工资系统的实际情况确定职工工资记录由职工工号、职工姓名、岗位工资、薪级
			  工资、职务津贴、绩效工资、应发工资、个人所得税和实发工资9个项目构成。系统应实现
			  工资记录的逐条添加、保存、根据工号进行查询、浏览、删除，并能在添加修改的同时自
			  动完成个人所得税和应发工资的计算。

Fuction list:    
                read(): 读取职工数据; 
                write()；保存数据; 
                find()； 根据工号查询相应的工资记录; 
                list()； 浏览全部职工工资信息; 
                modify()；指定工号修改职工工资信息 
                del()： 删除指定工号职工的记录 
                add()： 添加一个新的职工工资信息 
                grsds()：计算个人所得税 
                func_real_pay()：计算职工的实发工资 

****************************************/


#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include <windows.h> 
using namespace std;
const int ii=100;	//文件中职工工资数据的最大值 
int n=0; 			//记录gx.text文件中职工工资数据的个数 
struct gzzg{
    char number[10];
    char name[10];				//姓名
    float wage;					//岗位工资
    float pay_wages;			//薪级工资
    float post_allowance;		//职务津贴
    float merit_pay;			//绩效工资
    float should_pay;			//应发工资
    float personal_income_tax;	//个人所得税
    float real_pay;				//实发工资
}GZZG[ii];						//结构体数组全局变量 



/***************************************************

Function:	read(); 
Description: 主函数执行时要调用和必须调用的第一个函数，读取
             文件中的职工工资数据到一个结构体数组GZZG[ii]； 
Calls: 无 

Called by: main()； 

Return:  无返回值; 

*****************************************************/
void read()
{
    int i;
    FILE *fp;
    if((fp=fopen("gx.dat","r"))==NULL)
    {
        printf("Can not open file\n");
        exit(1);	
    }	
    while(!feof(fp))	//如果遇到文件结束，函数值feof为非零值，否则函数值为0。!0为真 
    {
        fscanf(fp,"%s  %s  %f  %f  %f  %f",
                GZZG[i].number,GZZG[i].name,&GZZG[i].wage,
				&GZZG[i].pay_wages,&GZZG[i].post_allowance,&GZZG[i].merit_pay);
        i=i+1;
        n=n+1;
    }
    fclose(fp); 
}



/*****************************************************

Function: write();
Description: 在进入系统进行操作后退可执行此函数保存此前
             的操作，并且将结构体数组保存到gz.dat文件中 ; 
Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 

*****************************************************/
void write()
{
    int i;
    FILE *fp;
    if((fp=fopen("gz.dat","rb+"))==NULL)
    {
        printf("Can not open file\n");
        exit(1);	
    }
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s   %s   %.2f   %.2f   %.2f   %.2f  %.2f  %.2f  %.2f\r\n ",
                GZZG[i].number,GZZG[i].name,GZZG[i].wage,GZZG[i].pay_wages,GZZG[i].post_allowance,
                GZZG[i].merit_pay,GZZG[i].should_pay,GZZG[i].personal_income_tax,GZZG[i].real_pay);
    }
    printf("\n保存成功");
    fclose(fp);

} 



/*****************************************************
Function: find();

Description: 根据工号查询相应的职工工资记录 
        
Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 
*****************************************************/
void find()		//查询职工工资数据 
{
    int j=0;
    char gonghao[10];
    printf("\t\t\t请输入要进行查询的工号："); 
    scanf("%s",gonghao);
    printf("\t\t\t显示查询结果：\n\n") ;
    
    for(int i=0;i<n;i++)
    {
    	j=j+1;
        if(strcmp(GZZG[i].number,gonghao)==0)
        {	        	
            printf("			***************************\n") ;
            printf("			|工号：");
            printf("%-19s|\n",GZZG[i].number);
	    			
            printf("			|姓名：");
            printf("%-19s|\n",GZZG[i].name);
			
            printf("			|岗位工资：");
            printf("%-15.2f|\n",GZZG[i].wage);
	    		
            printf("			|薪级工资：");
            printf("%-15.2f|\n",GZZG[i].pay_wages);
			
            printf("			|职务津贴：");
            printf("%-15.2f|\n",GZZG[i].post_allowance);
	    		
            printf("			|绩效工作：");
            printf("%-15.2f|\n",GZZG[i].merit_pay);
			
            printf("			|应发工资：");
            printf("%-15.2f|\n",GZZG[i].should_pay);
			
            printf("			|个人所得税：");
            printf("%-13.2f|\n",GZZG[i].personal_income_tax);		
			
       	    printf("			|实发工资：");
       	    printf("%-15.2f|\n",GZZG[i].real_pay);
            printf("			***************************\n");
            
            break;
        }
        if(j==n)		//判断工号是否存在 
        {
            printf("\t\t\t输入工号不存在\n");
	    }	
    }

    
}



/*****************************************************
Function: list();

Description: 浏览所有员工的工资数据;

Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 
*****************************************************/
void list()			//浏览所有职工工资数据 
{
    printf("      			所有职工工资数据如下：\n");
    
    for(int i=0;i<n;i++)
    {
    	Sleep(1000);
        printf("			***************************\n") ;
        printf("			|工号：");
        printf("%-19s|\n",GZZG[i].number);
	    			
        printf("			|姓名：");
        printf("%-19s|\n",GZZG[i].name);
			
        printf("			|岗位工资：");
        printf("%-15.2f|\n",GZZG[i].wage);
	    		
        printf("			|薪级工资：");
        printf("%-15.2f|\n",GZZG[i].pay_wages);
			
        printf("			|职务津贴：");
        printf("%-15.2f|\n",GZZG[i].post_allowance);
	    		
        printf("			|绩效工作：");
        printf("%-15.2f|\n",GZZG[i].merit_pay);
			
        printf("			|应发工资：");
        printf("%-15.2f|\n",GZZG[i].should_pay);
			
        printf("			|个人所得税：");
        printf("%-13.2f|\n",GZZG[i].personal_income_tax);		
			
        printf("			|实发工资：");
        printf("%-15.2f|\n",GZZG[i].real_pay);
        printf("			***************************\n\n");
	}
}



/*****************************************************
Function: modify();
Description: 修改职工的工资数据 
Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 
*****************************************************/
void modify()		//修改职工工资数据 
{	
	
    printf("请输入要修改的工号:"); 
    char gonghao[10];
    int i;
    scanf("%s",gonghao); 
    for(i=0;i<n;i++)
        if(strcmp(GZZG[i].number,gonghao)==0)
        {
            break;
        }
	
    printf("请输入修改后的岗位工资:");
    scanf("%\nf",&GZZG[i].wage);

    printf("请输入修改后的薪级工资:"); 	
    scanf("%f\n",&GZZG[i].pay_wages);
	
    printf("请输入修改后的职务津贴:");
    scanf("%f\n",&GZZG[i].post_allowance);
	
    printf("请输入修改后的绩效工资:");
    scanf("%f\n",&GZZG[i].merit_pay);

}



/*****************************************************

Function: del();
Description: 删除指定工号的职工记录 
Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 

*****************************************************/
void del()			//删除职工工资数据 976872969
{
    char gonghao[10];
    int i,j,k,h;
    printf("			请输入需要删除的职工工资数据的工号：");
    scanf("%s",gonghao);
    for(int i=0;i<n;i++)				//将需要删除的职工工资数据导出来 
        if(strcmp(GZZG[i].number,gonghao)==0)
        {
            printf("			***************************\n") ;
            printf("			|工号：");
            printf("%s\n",GZZG[i].number);
			
            printf("			|姓名：");
            printf("%s\n",GZZG[i].name);
			
            printf("			|岗位工资：");
            printf("%.2f\n",GZZG[i].wage);
				
            printf("			|薪级工资：");
            printf("%.2f\n",GZZG[i].pay_wages);
			
            printf("			|职务津贴：");
            printf("%.2f\n",GZZG[i].post_allowance);
			
            printf("			|绩效工作：");
            printf("%.2f\n",GZZG[i].merit_pay);
			
            printf("			|应发工资：");
            printf("%.2f\n",GZZG[i].should_pay);
			
            printf("			|个人所得税：");
            printf("%.2f\n",GZZG[i].personal_income_tax);		
			
            printf("			|实发工资：");
            printf("%.2f\n",GZZG[i].real_pay);
            printf("			***************************\n\n");
            break;
        } 
    printf("			|*********************************|\n");
    printf("			|请确认该职工工资数据是否正确!!\n"); 
    printf("			|请输入1执行删除操作：\n");
    printf("			|如需放弃请输入2：\n");
    printf("			|*********************************|\n");
    printf("			请输入："); 
    scanf("%d",&j);
    if(j==2)
    {
        printf("			退出该操作;请输入xxxx（未实现）" );
    }
    else if(j==1)
    {
        for(k==h;k<n-1;k++)
        {
            GZZG[k]=GZZG[k+1];
        }
        printf("			修改完成！！");
    }
    if(h==n)
    {
    printf("删除的员工为最后一个:");
    }
    else
    {
        cout<<h<<endl;
        printf("			|工号：");
        printf("%s\n",GZZG[h].number);
	
        printf("			|姓名：");
        printf("%s\n",GZZG[h].name);
		
        printf("			|岗位工资：");
        printf("%.2f\n",GZZG[h].wage);
				
        printf("			|薪级工资：");
        printf("%.2f\n",GZZG[h].pay_wages);
			
        printf("			|职务津贴：");
        printf("%.2f\n",GZZG[h].post_allowance);
			
        printf("			|绩效工作：");
        printf("%.2f\n",GZZG[h].merit_pay);
			
        printf("			|应发工资：");
        printf("%.2f\n",GZZG[h].should_pay);
	
        printf("			|个人所得税：");
        printf("%.2f\n",GZZG[h].personal_income_tax);		
			
        printf("			|实发工资：");
        printf("%.2f\n",GZZG[h].real_pay);
    }
} 


/*****************************************************
Function: add();
Description: 将新的职工工资记录添加到结构体数组GZZG[ii]
            的末尾 ； 
Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 
*****************************************************/
void add()	
{
    printf("\t\t\t请输入所添加职工的工号:");
    scanf("%s",GZZG[n].number);

    printf("\t\t\t请输入所添加职工的姓名:");
    scanf("%s",GZZG[n].name);

    printf("\t\t\t请输入所添加职工的岗位工资:");
    scanf("%f",&GZZG[n].wage);
		
    printf("\t\t\t请输入所添加职工的薪级工资:");
    scanf("%f",&GZZG[n].pay_wages);
	
    printf("\t\t\t请输入所添加职工的职务津贴:");
    scanf("%f",&GZZG[n].post_allowance);
	
    printf("\t\t\t请输入所添加职工的绩效工资:");
    scanf("%f",&GZZG[n].merit_pay);	
	
	printf("\n\t\t\t添加成功");		
}


/*****************************************************
Function: func_real_pay();
Description: 计算gz.dat文件中所有职工的实发工资;
 
Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 
*****************************************************/
void  func_real_pay()     	
{
    int i;
    for(i=0;i<n;i++)
    {
        GZZG[i].real_pay=GZZG[i].should_pay-GZZG[i].personal_income_tax;	
    } 
}


/*****************************************************
Function: grsds();
Description: 计算gz.dat文件中所有职工的应发工资和个人
             所得税;
Calls:  无调用函数; 

Called by: menu(); 

Return:  无返回值; 
*****************************************************/
void grsds()		
{
    for(int i=0;i<n;i++)
    {
        GZZG[i].should_pay=GZZG[i].wage+GZZG[i].pay_wages+GZZG[i].post_allowance+GZZG[i].merit_pay;
        if(GZZG[i].should_pay>=100000)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-100000)*0.45
                                        +20000*1.3+15000*0.2+3000*0.15+1500*0.1+500*0.5;
        }
		
        else if(GZZG[i].should_pay>=80000)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-80000)*0.4
                                        +20000*0.9+15000*0.2+3000*0.15+1500*0.1+500*0.5;	
        }
		
        else if(GZZG[i].should_pay>=60000)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-60000)*0.35
                                        +20000*0.55+15000*0.2+3000*0.15+1500*0.1+500*0.5;
        }
		
        else if(GZZG[i].should_pay>=40000)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-40000)*0.3
                                        +20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.5;
        }

        else if(GZZG[i].should_pay>=20000)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-20000)*0.25
                                        +15000*0.2+3000*0.15+1500*0.1+500*0.5;
        }
		
        else if(GZZG[i].should_pay>=5000)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-5000)*0.2+850;
        }
		
        else if(GZZG[i].should_pay>=2000)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-2000)*0.15+400;
        }
		
        else if(GZZG[i].should_pay>=500)
        {
            GZZG[i].personal_income_tax=(GZZG[i].should_pay-500)*0.1+25;
        }
		
        else 
        {
            GZZG[i].personal_income_tax=GZZG[i].should_pay*0.05;
        }
    }
}


/*****************************************************
Function: menu();
Description:显示系统菜单并且实现系统所有功能;
 
Calls:  read()
        write();
        find();
        modify();
        list();
        del();
        add();
        func_real_pay();
        grsds();
 

Called by: main(); 

Return:  无返回值; 
*****************************************************/
void menu()
{
    int i,j;
    do
    {
    	system("cls"); 
        printf("\t\t\t###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n\n");
        printf("\t\t\t请选择<1 - 7>:\n");
        printf("\t\t\t===============================================================\n");
        printf("\t\t\t|\t1.查询职工工资记录                                    |\n");
        printf("\t\t\t|\t2.修改职工工资记录                                    |\n");
        printf("\t\t\t|\t3.添加职工工资记录                                    |\n");
        printf("\t\t\t|\t4.删除职工工资记录                                    |\n");
        printf("\t\t\t|\t5.保存数据到文件                                      |\n");
        printf("\t\t\t|\t6.浏览职工记录                                        |\n");
        printf("\t\t\t|\t7.退出系统                                            |\n");
        printf("\t\t\t===============================================================\n\n");
        printf("\t\t\t你的选择是：");
        scanf("%d",&i);	
		while(i>7)
		{
			printf("\t\t\t输入数字不在1-7之间，请重新输入:"); 
			scanf("%d",&i);	
		}
        switch(i)
        {
            case 1:
            {
                printf("\t\t\t欢迎使用查询功能，请接下来按提示操作\n");
                grsds();
                func_real_pay();
                find();
                do
                {
                    printf("\t\t\t输入0返回上一层：");
                    scanf("%d",&j);
                    if(j==0)
                    {
                        break;
                    }
                }
                while(j!=0);
                break;
            }
            
            case 2:
            {	
                printf("\t\t\t欢迎使用修改功能，请接下来按提示操作\n");
                modify();
                printf("修改完成！！\n");
                do
                {
                    printf("\t\t\t输入0返回上一层：");
                    scanf("%d",&j);
                    if(j==0)
                    {
                        break;
					}
                }
                while(j!=0);
                break;
            }
			
            case 3:
            {
                printf("\t\t\t欢迎使用添加功能，请接下来按提示操作\n");
                add();
                n=n+1;
                grsds();
                func_real_pay();
                do
                {
                    printf("\t\t\t输入0返回上一层：");
                    scanf("%d",&j);
                    if(j==0)
                    {
                        break;
                    }
                }
                while(j!=0);
                break;
            }
			
            case 4:
            {
                printf("\t\t\t欢迎使用删除功能，请接下来按提示操作\n");
                del(); 
                do
                {
                    printf("\t\t\t输入0返回上一层：");
                    scanf("%d",&j);
                    if(j==0)
                    {
                        break;
                    }
                }
                while(j!=0);
                break;
            }
			
            case 5:
            {
                printf("\t\t\t欢迎使用保存功能，请接下来按提示操作");
                write();
                do
                {
                    printf("\t\t\t输入0返回上一层：");
                    scanf("%d",&j);
                    if(j==0)
                    {
                        break;
                    }
                }
                while(j!=0);
                break;
            }
		
            case 6:
            {
                printf("\t\t\t欢迎使用浏览功能，请接下来按提示操作\n");
                list();
                do
                {
                    printf("\t\t\t输入0返回上一层：");
                    scanf("%d",&j);
                    if(j==0)
                    {
                        break;
                    }
                }
                while(j!=0);
                break;
            }
			
            case 7:
            {
                break;
            }				
        }
    }
    while(i!=7);

}

int main()
{ 
    read();
    grsds();
    func_real_pay();
	system("color bc");	
    menu();
    
    printf("\t\t\t欢迎使用本系统，再见！！！！！！"); 
	
    return 0;
} 
