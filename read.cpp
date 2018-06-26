#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
/*
面向对象
	对象集
	行为
	属性 
*/
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
	ifstream infile("stu.dat",ios::binary);
	if(!infile)
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	while(!infile.eof())
	{
		infile>>GZZG[i].number>>GZZG[i].name>>GZZG[i].wage>>GZZG[i].pay_wages>>GZZG[i].post_allowance>>GZZG[i].merit_pay;
		i=i+1;
		n=n+1;		//使用全局变量来储存数组的大小 
	}
	infile.close();
	for(i=0;i<n;i++)
		cout<<GZZG[i].number<<" "<<GZZG[i].name<<" "<<GZZG[i].wage<<" "
			<<GZZG[i].pay_wages<<" "<<GZZG[i].post_allowance<<" "<<GZZG[i].merit_pay<<endl;
}

void write()
{
	ofstream outfile("gz.dat");
	if(!outfile)
	{
		cout<<"打开文件失败："<<endl;
		abort();				//退出程序，其作用与exit相同 
	}
	for(int i=0;i<n;i++)
	{
		outfile.write((char *)&GZZG[i],sizeof(GZZG[i]));
		cout<<endl;
	}	
	outfile.close();
} 

void find()
{
	int j;
	char gonghao[10];
	cin>>gonghao;
/*	cout<<"请选择查询方式："<<endl;
	cout<<"工号查询，请输入1；" <<endl;
	cout<<"姓名查询，请输入2：" <<endl;
	cin>>j;
	if(j==1)
	{
*/
	for(int i=0;i<n;i++)
		if(strcmp(GZZG[i].number,gonghao)==0)
		{
			cout<<"工号："<<GZZG[i].number<<endl;
			cout<<"姓名："<<GZZG[i].name<<endl;
			cout<<"岗位工资："<<GZZG[i].wage<<endl;
			cout<<"薪级工资："<<GZZG[i].pay_wages<<endl;
			cout<<"职务津贴"<<GZZG[i].post_allowance<<endl;
			cout<<"绩效工作："<<GZZG[i].merit_pay<<endl;
			cout<<"应发工资："<<GZZG[i].should_pay<<endl;
			cout<<"个人所得税："<<GZZG[i].personal_income_tax<<endl;
			cout<<"实发工资："<<GZZG[i].real_pay<<endl;
			break;
		}
}


void list()
{
	for(int i=0;i<n;i++)
	{
		cout<<"        |"<<"************************"<<"*      "<<endl;
		cout<<"        |"<<"工号："<<GZZG[i].number<<endl;
		cout<<"        |"<<"姓名："<<GZZG[i].name<<endl;
		cout<<"        |"<<"岗位工资："<<GZZG[i].wage<<endl;
		cout<<"        |"<<"薪级工资："<<GZZG[i].pay_wages<<endl;
		cout<<"        |"<<"职务津贴"<<GZZG[i].post_allowance<<endl;
		cout<<"        |"<<"绩效工作："<<GZZG[i].merit_pay<<endl;
		cout<<"        |"<<"应发工资："<<GZZG[i].should_pay<<endl;
		cout<<"        |"<<"个人所得税："<<GZZG[i].personal_income_tax<<endl;
		cout<<"        |"<<"实发工资："<<GZZG[i].real_pay<<endl;
		cout<<"        |"<<"************************"<<"*      "<<endl;
		cout<<endl<<endl;
	}
}

void modify()		//修改职工工资数据 
{	
	
	cout<<"请输入要修改的工号："<<endl;
	/*
	将工号查找出来，并且修改. 
	*/
	char gonghao[10];
	int i;
	float modify_wage,modify_pay_wages,modify_merit_pay;
	cin>>gonghao;
	for(i=0;i<n;i++)
		if(strcmp(GZZG[i].number,gonghao)==0)
		{
			break;
		}
	cout<<"i="<<i<<endl;
	cout<<"请输入修改后的岗位工资"<<endl;
		cin>>modify_wage;
	cout<<"请输入修改后的薪级工资"<<endl; 	
		cin>>modify_pay_wages;
	cout<<"请输入修改后的绩效工资"<<endl;
		cin>>modify_merit_pay;
		 
}

void del()			//删除职工工资数据 
{
	
} 

void add()			//添加职工工资数据 
{
		
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

int main()
{
	int i; 
	read(); 
	cout<<endl; 
	cout<<"hello熊岚滢！！！"<<endl;
/*	for(i=0;i<n;i++)
		cout<<GZZG[i].number<<" "<<GZZG[i].name<<" "<<GZZG[i].wage<<" "
			<<GZZG[i].pay_wages<<" "<<GZZG[i].post_allowance<<" "<<GZZG[i].merit_pay<<endl;
	cout<<"n="<<n<<endl; 
*/


//	write();
//	find();
	list();
	grsds();
	cout<<GZZG[1].personal_income_tax<<endl;
	modify();
	return 0;
} 
