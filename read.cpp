#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
/*
�������
	����
	��Ϊ
	���� 
*/
const int ii=100;
int n=0; 
struct gzzg{
	char number[10];
	char name[10];		//����
	float wage;		//��λ����
	float pay_wages;		//н������
	float post_allowance;	//ְ�����
	float merit_pay;		//��Ч����
	float should_pay;		//Ӧ������
	float personal_income_tax;//��������˰
	float real_pay;		//ʵ������
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
		n=n+1;		//ʹ��ȫ�ֱ�������������Ĵ�С 
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
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		abort();				//�˳�������������exit��ͬ 
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
/*	cout<<"��ѡ���ѯ��ʽ��"<<endl;
	cout<<"���Ų�ѯ��������1��" <<endl;
	cout<<"������ѯ��������2��" <<endl;
	cin>>j;
	if(j==1)
	{
*/
	for(int i=0;i<n;i++)
		if(strcmp(GZZG[i].number,gonghao)==0)
		{
			cout<<"���ţ�"<<GZZG[i].number<<endl;
			cout<<"������"<<GZZG[i].name<<endl;
			cout<<"��λ���ʣ�"<<GZZG[i].wage<<endl;
			cout<<"н�����ʣ�"<<GZZG[i].pay_wages<<endl;
			cout<<"ְ�����"<<GZZG[i].post_allowance<<endl;
			cout<<"��Ч������"<<GZZG[i].merit_pay<<endl;
			cout<<"Ӧ�����ʣ�"<<GZZG[i].should_pay<<endl;
			cout<<"��������˰��"<<GZZG[i].personal_income_tax<<endl;
			cout<<"ʵ�����ʣ�"<<GZZG[i].real_pay<<endl;
			break;
		}
}


void list()
{
	for(int i=0;i<n;i++)
	{
		cout<<"        |"<<"************************"<<"*      "<<endl;
		cout<<"        |"<<"���ţ�"<<GZZG[i].number<<endl;
		cout<<"        |"<<"������"<<GZZG[i].name<<endl;
		cout<<"        |"<<"��λ���ʣ�"<<GZZG[i].wage<<endl;
		cout<<"        |"<<"н�����ʣ�"<<GZZG[i].pay_wages<<endl;
		cout<<"        |"<<"ְ�����"<<GZZG[i].post_allowance<<endl;
		cout<<"        |"<<"��Ч������"<<GZZG[i].merit_pay<<endl;
		cout<<"        |"<<"Ӧ�����ʣ�"<<GZZG[i].should_pay<<endl;
		cout<<"        |"<<"��������˰��"<<GZZG[i].personal_income_tax<<endl;
		cout<<"        |"<<"ʵ�����ʣ�"<<GZZG[i].real_pay<<endl;
		cout<<"        |"<<"************************"<<"*      "<<endl;
		cout<<endl<<endl;
	}
}

void modify()		//�޸�ְ���������� 
{	
	
	cout<<"������Ҫ�޸ĵĹ��ţ�"<<endl;
	/*
	�����Ų��ҳ����������޸�. 
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
	cout<<"�������޸ĺ�ĸ�λ����"<<endl;
		cin>>modify_wage;
	cout<<"�������޸ĺ��н������"<<endl; 	
		cin>>modify_pay_wages;
	cout<<"�������޸ĺ�ļ�Ч����"<<endl;
		cin>>modify_merit_pay;
	
}


void del()			//ɾ��ְ���������� 976872969
{
	char gonghao[10];
	int i,j,k,h;
	cout<<"��������Ҫɾ����ְ���������ݵĹ��ţ�";
	cin>>gonghao;
	for(int i=0;i<n;i++)				//����Ҫɾ����ְ���������ݵ����� 
		if(strcmp(GZZG[i].number,gonghao)==0)
		{
			cout<<"���ţ�"<<GZZG[i].number<<endl;
			cout<<"������"<<GZZG[i].name<<endl;
			cout<<"��λ���ʣ�"<<GZZG[i].wage<<endl;
			cout<<"н�����ʣ�"<<GZZG[i].pay_wages<<endl;
			cout<<"ְ�����"<<GZZG[i].post_allowance<<endl;
			cout<<"��Ч������"<<GZZG[i].merit_pay<<endl;
			cout<<"Ӧ�����ʣ�"<<GZZG[i].should_pay<<endl;
			cout<<"��������˰��"<<GZZG[i].personal_income_tax<<endl;
			cout<<"ʵ�����ʣ�"<<GZZG[i].real_pay<<endl;
			cout<<"i="<<i<<endl;
			h=i;
			cout<<"h="<<h<<endl;
			break;
		} 
	cout<<"|*********************************|"<<endl;
	cout<<"|��ȷ�ϸ�ְ�����������Ƿ���ȷ!!"<<endl; 
	cout<<"|������1ִ��ɾ��������"<<endl;
	cout<<"|�������������2��"<<endl;
	cout<<"|*********************************|"<<endl;
	cin>>j;
	if(j==2)
	{
		cout<<"�˳��ò���;������xxxx��δʵ�֣�" <<endl;
	}
	else if(j==1)
	{
		for(k==h;k<n-1;k++)
		{
			GZZG[k]=GZZG[k+1];
		}
		cout<<"�޸���ɣ���"<<endl;
	}
	if(h==n)
	{
		cout<<"ɾ����Ա��Ϊ���һ��:"<<endl; 
	}
	else
	{
	cout<<"���ţ�"<<GZZG[h].number<<endl;
	cout<<"������"<<GZZG[h].name<<endl;
	cout<<"��λ���ʣ�"<<GZZG[h].wage<<endl;
	cout<<"н�����ʣ�"<<GZZG[h].pay_wages<<endl;
	cout<<"ְ�����"<<GZZG[h].post_allowance<<endl;
	cout<<"��Ч������"<<GZZG[h].merit_pay<<endl;
	cout<<"Ӧ�����ʣ�"<<GZZG[h].should_pay<<endl;
	cout<<"��������˰��"<<GZZG[h].personal_income_tax<<endl;
	cout<<"ʵ�����ʣ�"<<GZZG[h].real_pay<<endl;
	}
} 



void add()			//����ְ���������� 
{
	int i;
	
	
}



void grsds()		//�����������˰ 
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
	cout<<"***************************|"<<endl;
	cout<<"��ӭ����˵�����"<<endl;
	cout<<"��ѯְ��������ϸ��Ϣ������1"<<endl;
	cout<<"�޸�ְ��������ϸ��Ϣ������2"<<endl;
	cout<<"�����µ�ְ��������Ϣ������3"<<endl;
	cout<<"ɾ��ְ������������4"<<endl;
	cout<<"���浱ǰ����������5"<<endl;
	cout<<"�������ְ��������Ϣ������6"<<endl;
	cout<<"�˳��˵�������7"<<endl;	
}			



int main()
{
	int i; 
	read(); 
	cout<<endl; 
	cout<<"		"<<"		"<<"hello����ޣ�����"<<endl;
	cout<<endl;
	cout<<"		"<<"||***************************************||" <<endl;
	cout<<"		"<<"||��ʼ����˵������ڽ���˵�����ʾ���� ||"<<endl; 
	cout<<"		"<<"||***************************************||" <<endl;
	
/*	for(i=0;i<n;i++)
		cout<<GZZG[i].number<<" "<<GZZG[i].name<<" "<<GZZG[i].wage<<" "
			<<GZZG[i].pay_wages<<" "<<GZZG[i].post_allowance<<" "<<GZZG[i].merit_pay<<endl;
	cout<<"n="<<n<<endl; 
*/


//	write();
//	find();
	list();
//	grsds();
//	cout<<GZZG[1].personal_income_tax<<endl;
	//modify();
	del();
	return 0;
} 