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
}GZZG[ii];




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
//	cin>>gonghao;
	gets(gonghao);
	printf("显示查询结果：\n") ;
	for(int i=0;i<n;i++)
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
	gets(gonghao); 
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
	
}


void del()			//删除职工工资数据 976872969
{
	char gonghao[10];
	int i,j,k,h;
	printf("请输入需要删除的职工工资数据的工号：");
	gets(gonghao);
	for(int i=0;i<n;i++)				//将需要删除的职工工资数据导出来 
		if(strcmp(GZZG[i].number,gonghao)==0)
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
			cout<<"i="<<i<<endl;
			h=i;
			cout<<"h="<<h<<endl;
			break;
		} 
	printf("|*********************************|");
	printf("|请确认该职工工资数据是否正确!!"); 
	printf("|请输入1执行删除操作：");
	printf("|如需放弃请输入2：");
	printf("|*********************************|");
	cin>>j;
	if(j==2)
	{
		printf("退出该操作;请输入xxxx（未实现）" );
	}
	else if(j==1)
	{
		for(k==h;k<n-1;k++)
		{
			GZZG[k]=GZZG[k+1];
		}
		printf("修改完成！！");
	}
	if(h==n)
	{
		printf("删除的员工为最后一个:");
	}
	else
	{
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
	}
} 



void add()			//添加职工工资数据 
{
	printf("欢迎进入添加界面！！！！！！");
	printf("请输入所添加职工的工号:");
		gets(GZZG[n].number);
		cout<<endl;
	printf("请输入所添加职工的姓名:");
	gets(GZZG[n].name);
	cout<<endl;
	printf("请输入所添加职工的岗位工资:");
	scanf("%f",&GZZG[n].wage);
	cout<<endl;
		
	printf("请输入所添加职工的薪级工资:");
	scanf("%f",&GZZG[n].pay_wages);
	cout<<endl;
	
	printf("请输入所添加职工的职务津贴:");
	scanf("%f",&GZZG[n].post_allowance);
	cout<<endl;
	
	printf("请输入所添加职工的绩效工资:");
	scanf("%f",&GZZG[n].merit_pay);
	cout<<endl;
	
//	printf("%s",&GZZG[n].name);
//	printf("%.2f",GZZG[n].pay_wages);	

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
		cout<<GZZG[i].real_pay<<endl;	
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
	printf("\t###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n\n");
	printf("\t请选择<1 - 7>:\n");
	printf("\t===============================================================\n");
	printf("\t|\t1.查询职工工资记录                                    |\n");
	printf("\t|\t2.修改职工工资记录                                    |\n");
	printf("\t|\t3.添加职工工资记录                                    |\n");
	printf("\t|\t4.删除职工工资记录                                    |\n");
	printf("\t|\t5.保存数据到文件                                      |\n");
	printf("\t|\t6.浏览职工记录                                        |\n");
	printf("\t|\t7.退出系统                                            |\n");
	printf("\t===============================================================\n\n");
	printf("\t你的选择是：\n");
	cin>>i;
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
	}
	else if(i==5)
	{
		printf("欢迎使用保存功能，请接下来按提示操作");
		write();
	}
	else if(i==6)
	{
		printf("欢迎使用浏览功能，请接下来按提示操作\n");
		
	}
	else if(i==7)
	{
		printf("欢迎使用查询功能，请接下来按提示操作\n");
	}
	else 
	{
		printf("输入错误请重新输入：\n");
		cin>>i;
	}
}			



int main()
{
	int i; 
	read();
	menu();
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
