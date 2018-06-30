#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
const int ii=100;
int n=0; 
struct gzzg{
	char number[10];
	char name[10];		//姓名
	float wage;		//岗位工资
	float pay_wages;		//薪级工资
	float post_allowance;	//职务津贴
	float merit_pay;		//绩效工资
	float should_pay;		//应发工资
	float personal_income_tax;//个人所得税
	float real_pay;		//实发工资
}GZZG[ii];				//结构体数组全局变量 




void read()
{
	int i;
	FILE *fp;
	if((fp=fopen("stu.dat","r"))==NULL)
	{
		printf("Can not open file\n");
		exit(1);	
	}	
	while(!feof(fp))	//如果遇到文件结束，函数值feof为非零值，否则函数值为0。!0为真 
	{
		fscanf(fp,"%s  %s  %f  %f  %f  %f",GZZG[i].number,GZZG[i].name,&GZZG[i].wage,&GZZG[i].pay_wages,&GZZG[i].post_allowance,&GZZG[i].merit_pay);
		/*
		字符串不用取地址符 ->GZZG[i].number(字符串) 
		数据要取地址符		->&GZZG[i].wage(数据) 
		*/
		i++;
		n++;
	}
	cout<<n<<endl;
	fclose(fp); 
	for(i=0;i<n;i++)
	{
		printf("%s   %s   %.2f   %.2f   %.2f   %.2f \n",GZZG[i].number,GZZG[i].name,GZZG[i].wage,GZZG[i].pay_wages,GZZG[i].post_allowance,GZZG[i].merit_pay);
		/*
		%.2f ->保留两位小数
		%s	->输出字符串
		%f	->输出浮点数 
		*/
	}
}

void write()
{
	int i;
	FILE *fp;
	if((fp=fopen("gz.text","rb+"))==NULL)
	{
		printf("Can not open file\n");
		exit(1);	
	}
	for(i=0;i<n;i++)
	{
//		fwrite(&GZZG[i],sizeof(struct gzzg),n,fp);		使用这个函数写入时，写入的数据会乱码如GZZG[i].wage; 
		fprintf(fp,"%s   %s   %.2f   %.2f   %.2f   %.2f \r\n ",GZZG[i].number,GZZG[i].name,GZZG[i].wage,GZZG[i].pay_wages,GZZG[i].post_allowance,GZZG[i].merit_pay);
	/*
	写入文件有字符和数据时应该一个个逐个输入，想要换行需要在尾部加入\r\n; 
	*/
	}
	fclose(fp);

} 

void find()		//查询职工工资数据 
{
	int j;
	char gonghao[10];
	printf("请输入要进行查询的工号："); 
	scanf("%s",gonghao);
//	cin>>gonghao;
//	gets(gonghao);
	printf("显示查询结果：\n") ;
	for(int i=0;i<n;i++)
	{
		if(strcmp(GZZG[i].number,gonghao)==0)
		{	
			printf("工号：");
			printf("%s\n",GZZG[i].number);
			
			printf("姓名：");
			printf("%s\n",GZZG[i].name);
			
			printf("岗位工资：");
			printf("%.2f\n",GZZG[i].wage);
			
			printf("薪级工资：");
			printf("%.2f\n",GZZG[i].pay_wages);
			
			printf("职务津贴：");
			printf("%.2f\n",GZZG[i].post_allowance);
			
			printf("绩效工作：");
			printf("%.2f\n",GZZG[i].merit_pay);
			
			printf("应发工资：");
			printf("%.2f\n",GZZG[i].should_pay);
			
			printf("个人所得税：");
			printf("%.2f\n",GZZG[i].personal_income_tax);		
			
			printf("实发工资：");
			printf("%.2f\n",GZZG[i].real_pay);
			
			break;
		}
	}
}

/*
c数据打印格式 
%s
和
%f
控制长度 
*/
void list()			//浏览所有职工工资数据 
{
	printf("      所有职工工资数据如下：\n");
	for(int i=0;i<n;i++)
	{
		printf("	***************************\n") ;
		printf("	|工号：");
		printf("%s\n",GZZG[i].number);
			
		printf("	|姓名：");
		printf("%s\n",GZZG[i].name);
			
		printf("	|岗位工资：");
		printf("%.2f\n",GZZG[i].wage);
			
		printf("	|薪级工资：");
		printf("%.2f\n",GZZG[i].pay_wages);
			
		printf("	|职务津贴：");
		printf("%.2f\n",GZZG[i].post_allowance);
			
		printf("	|绩效工作：");
		printf("%.2f\n",GZZG[i].merit_pay);
			
		printf("	|应发工资：");
		printf("%.2f\n",GZZG[i].should_pay);
			
		printf("	|个人所得税：");
		printf("%.2f\n",GZZG[i].personal_income_tax);		
			
		printf("	|实发工资：");
		printf("%.2f\n",GZZG[i].real_pay);
		printf("	***************************");
		cout<<endl<<endl;
	}
}

void modify()		//修改职工工资数据 
{	
	
	printf("请输入要修改的工号:"); 
	/*
	将工号查找出来，并且修改. 
	*/
	char gonghao[10];
	int i;
	float modify_wage,modify_pay_wages,modify_merit_pay;
	scanf("%s",gonghao); 
	for(i=0;i<n;i++)
		if(strcmp(GZZG[i].number,gonghao)==0)
		{
			break;
		}
	cout<<"i="<<i<<endl;
	
	printf("请输入修改后的岗位工资:");
	scanf("%\nf",&GZZG[i].wage);

	printf("请输入修改后的薪级工资:"); 	
	scanf("%f\n",&GZZG[i].pay_wages);
	
	printf("请输入修改后的职务津贴:");
	scanf("%f\n",&GZZG[i].post_allowance);
	
	printf("请输入修改后的绩效工资:");
	scanf("%f\n",&GZZG[i].merit_pay);
	
//	return 0;
}


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



void add()			//添加职工工资数据 
{
/*
这里需要注意一点在：scanf中 “\n” 不是表示接受一个回车符，
而是表示忽略所有的空白字符（包括回车,空格,tab ）。所以想要
结束输入,输入任意一个非空白字符即可,但是该字符仍然会留在缓冲区中。
而且scanf输完，按回车键会自动换行 
*/
	printf("\t\t\t请输入所添加职工的工号:");
	scanf("%s",GZZG[n].number);

	printf("\t\t\t请输入所添加职工的姓名:");
	scanf("%s\n",GZZG[n].name);

	printf("\t\t\t请输入所添加职工的岗位工资:");
	scanf("%f",&GZZG[n].wage);
		
	printf("\t\t\t请输入所添加职工的薪级工资:");
	scanf("%f",&GZZG[n].pay_wages);
	
	printf("\t\t\t请输入所添加职工的职务津贴:");
	scanf("%f",&GZZG[n].post_allowance);
	
	printf("\t\t\t请输入所添加职工的绩效工资:");
	scanf("%f",&GZZG[n].merit_pay);		

	/*
	输入数据时要取地址符&
	输出数据时不用 
	*/
	
}



void func_real_pay()	//计算实发工资 
{
	int i;
//	grsds();
	for(i=0;i<n;i++)
	{
		GZZG[i].real_pay=GZZG[i].should_pay-GZZG[i].personal_income_tax;	
	} 
}

void grsds()		//计算个人所得税 
{
	for(int i=0;i<n;i++)
	{
		GZZG[i].should_pay=GZZG[i].wage+GZZG[i].pay_wages+GZZG[i].post_allowance;
		if(GZZG[i].should_pay>=100000)
		{
			GZZG[i].personal_income_tax=(GZZG[i].should_pay-100000)*0.45+20000*1.3+15000*0.2+3000*0.15+1500*0.1+500*0.5;	//20000*1.3+15000*0.2+3000*0.15+1500*0.1+500*0.5
		}
		
		else if(GZZG[i].should_pay>=80000)
		{
			GZZG[i].personal_income_tax=(GZZG[i].should_pay-80000)*0.4+20000*0.9+15000*0.2+3000*0.15+1500*0.1+500*0.5;	//20000*1.3+15000*0.2+3000*0.15+1500*0.1+500*0.5;
		}
		
		else if(GZZG[i].should_pay>=60000)
		{
			GZZG[i].personal_income_tax=(GZZG[i].should_pay-60000)*0.35+20000*0.55+15000*0.2+3000*0.15+1500*0.1+500*0.5;
		}
		
		else if(GZZG[i].should_pay>=40000)
		{
			GZZG[i].personal_income_tax=(GZZG[i].should_pay-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.5;
		}

		else if(GZZG[i].should_pay>=20000)
		{
			GZZG[i].personal_income_tax=(GZZG[i].should_pay-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.5;
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



void menu()
{
	int i; 
/*
	cout<<"			"<<"|***************************|"<<endl;
	cout<<"			"<<"|欢迎进入菜单！！"<<endl;
	cout<<"			"<<"|查询职工工资详细信息请输入1"<<endl;
	cout<<"			"<<"|修改职工工资详细信息请输入2"<<endl;
	cout<<"			"<<"|添加新的职工工资信息请输入3"<<endl;
	cout<<"			"<<"|删除职工工资请输入4"<<endl;
	cout<<"			"<<"|保存当前操作请输入5"<<endl;
	cout<<"			"<<"|浏览所有职工工资信息请输入6"<<endl;
	cout<<"			"<<"|退出菜单请输入7"<<endl;	
	cout<<"			"<<"|***************************|"<<endl;
*/
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
	cout<<i;
	/*
	可改成while语句 
	*/


	
	
	if(i==1)
	{
		printf("欢迎使用查询功能，请接下来按提示操作");
		find();
	}
	else if(i==2)
	{
		printf("欢迎使用修改功能，请接下来按提示操作");
		modify();
	}
	else if(i==3)
	{
		printf("欢迎使用添加功能，请接下来按提示操作");
		add();
	}
	else if(i==4)
	{
		printf("欢迎使用删除功能，请接下来按提示操作");
		del(); 
	}
	else if(i==5)
	{
		printf("欢迎使用保存功能，请接下来按提示操作");
		write();
	}
	else if(i==6)
	{
		printf("欢迎使用浏览功能，请接下来按提示操作\n");
		list();
		
	}
	else if(i==7)
	{
		printf("欢迎使用查询功能，请接下来按提示操作\n");
	}
	else 
	{
		printf("输入错误请重新输入：\n");
		scanf("%d",&i);
	}
}			



int main()
{
	int i; 
	read();
	grsds();
	func_real_pay();
	/*
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

	可改成while语句 
	*/
	
	
	/*
	使用一个do while()语句 
	*/
	do
	{
	//	system("cls");
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
		
		switch(i)
		{
			case 1:
				printf("\t\t\t欢迎使用查询功能，请接下来按提示操作\n");
				grsds();
				func_real_pay();
				find();
				break;
		
			case 2:
				printf("\t\t\t欢迎使用修改功能，请接下来按提示操作\n");
				modify();
				break;
			
			case 3:
				printf("\t\t\t欢迎使用添加功能，请接下来按提示操作\n");
				add();
				break;
			
			case 4:
				printf("\t\t\t欢迎使用删除功能，请接下来按提示操作\n");
				del(); 
				break;
			
			case 5:
				printf("\t\t\t欢迎使用保存功能，请接下来按提示操作");
				write();
				break;
			
			case 6:
				printf("\t\t\t欢迎使用浏览功能，请接下来按提示操作\n");
				list();
				break;
			case 7:
				
				break;
		}
	}
	while(i!=7);
	/*
	if(i==1)
	{

		printf("\t\t\t欢迎使用查询功能，请接下来按提示操作\n");
		grsds();
		func_real_pay();
		find();
	}
	else if(i==2)
	{
		printf("\t\t\t欢迎使用修改功能，请接下来按提示操作\n");
		modify();
	}
	else if(i==3)
	{
		printf("\t\t\t欢迎使用添加功能，请接下来按提示操作\n");
		add();
	}
	else if(i==4)
	{
		printf("\t\t\t欢迎使用删除功能，请接下来按提示操作\n");
		del(); 
	}
	else if(i==5)
	{
		printf("\t\t\t欢迎使用保存功能，请接下来按提示操作");
		write();
	}
	else if(i==6)
	{
		printf("\t\t\t欢迎使用浏览功能，请接下来按提示操作\n");
		list();
		
	}
	else if(i==7)
	{
		printf("\t\t\t欢迎使用查询功能，请接下来按提示操作\n");
	}
	else 
	{
		printf("\t\t\t输入错误请重新输入：\n");
		scanf("%d",&i);
	}
*/	
	
	
	
	
	
	
	
//	menu();
//	cout<<GZZG[0].name<<GZZG[0].number<<endl; 
//	write();
//	find();
//	list();
//	modify();
//	add();

/*	cout<<endl; 
	cout<<"		"<<"		"<<"hello熊岚滢！！！"<<endl;
	cout<<endl;
	cout<<"		"<<"||***************************************||" <<endl;
	cout<<"		"<<"||开始进入菜单，请在进入菜单后按提示操作 ||"<<endl; 
	cout<<"		"<<"||***************************************||" <<endl;
	menu(); 

	cout<<GZZG[n].name<<endl;
	cout<<"hello"<<endl; 
	add();

	system("cls");	//清屏函数
	menu(); 
	*/
	return 0;
} 
