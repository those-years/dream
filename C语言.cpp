#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
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
}GZZG[ii];				//�ṹ������ȫ�ֱ��� 




void read()
{
	int i;
	FILE *fp;
	if((fp=fopen("stu.dat","r"))==NULL)
	{
		printf("Can not open file\n");
		exit(1);	
	}	
	while(!feof(fp))	//��������ļ�����������ֵfeofΪ����ֵ��������ֵΪ0��!0Ϊ�� 
	{
		fscanf(fp,"%s  %s  %f  %f  %f  %f",GZZG[i].number,GZZG[i].name,&GZZG[i].wage,&GZZG[i].pay_wages,&GZZG[i].post_allowance,&GZZG[i].merit_pay);
		/*
		�ַ�������ȡ��ַ�� ->GZZG[i].number(�ַ���) 
		����Ҫȡ��ַ��		->&GZZG[i].wage(����) 
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
		%.2f ->������λС��
		%s	->����ַ���
		%f	->��������� 
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
//		fwrite(&GZZG[i],sizeof(struct gzzg),n,fp);		ʹ���������д��ʱ��д������ݻ�������GZZG[i].wage; 
		fprintf(fp,"%s   %s   %.2f   %.2f   %.2f   %.2f \r\n ",GZZG[i].number,GZZG[i].name,GZZG[i].wage,GZZG[i].pay_wages,GZZG[i].post_allowance,GZZG[i].merit_pay);
	/*
	д���ļ����ַ�������ʱӦ��һ����������룬��Ҫ������Ҫ��β������\r\n; 
	*/
	}
	fclose(fp);

} 

void find()		//��ѯְ���������� 
{
	int j;
	char gonghao[10];
	printf("������Ҫ���в�ѯ�Ĺ��ţ�"); 
	scanf("%s",gonghao);
//	cin>>gonghao;
//	gets(gonghao);
	printf("��ʾ��ѯ�����\n") ;
	for(int i=0;i<n;i++)
	{
		if(strcmp(GZZG[i].number,gonghao)==0)
		{	
			printf("���ţ�");
			printf("%s\n",GZZG[i].number);
			
			printf("������");
			printf("%s\n",GZZG[i].name);
			
			printf("��λ���ʣ�");
			printf("%.2f\n",GZZG[i].wage);
			
			printf("н�����ʣ�");
			printf("%.2f\n",GZZG[i].pay_wages);
			
			printf("ְ�������");
			printf("%.2f\n",GZZG[i].post_allowance);
			
			printf("��Ч������");
			printf("%.2f\n",GZZG[i].merit_pay);
			
			printf("Ӧ�����ʣ�");
			printf("%.2f\n",GZZG[i].should_pay);
			
			printf("��������˰��");
			printf("%.2f\n",GZZG[i].personal_income_tax);		
			
			printf("ʵ�����ʣ�");
			printf("%.2f\n",GZZG[i].real_pay);
			
			break;
		}
	}
}

/*
c���ݴ�ӡ��ʽ 
%s
��
%f
���Ƴ��� 
*/
void list()			//�������ְ���������� 
{
	printf("      ����ְ�������������£�\n");
	for(int i=0;i<n;i++)
	{
		printf("	***************************\n") ;
		printf("	|���ţ�");
		printf("%s\n",GZZG[i].number);
			
		printf("	|������");
		printf("%s\n",GZZG[i].name);
			
		printf("	|��λ���ʣ�");
		printf("%.2f\n",GZZG[i].wage);
			
		printf("	|н�����ʣ�");
		printf("%.2f\n",GZZG[i].pay_wages);
			
		printf("	|ְ�������");
		printf("%.2f\n",GZZG[i].post_allowance);
			
		printf("	|��Ч������");
		printf("%.2f\n",GZZG[i].merit_pay);
			
		printf("	|Ӧ�����ʣ�");
		printf("%.2f\n",GZZG[i].should_pay);
			
		printf("	|��������˰��");
		printf("%.2f\n",GZZG[i].personal_income_tax);		
			
		printf("	|ʵ�����ʣ�");
		printf("%.2f\n",GZZG[i].real_pay);
		printf("	***************************");
		cout<<endl<<endl;
	}
}

void modify()		//�޸�ְ���������� 
{	
	
	printf("������Ҫ�޸ĵĹ���:"); 
	/*
	�����Ų��ҳ����������޸�. 
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
	
	printf("�������޸ĺ�ĸ�λ����:");
	scanf("%\nf",&GZZG[i].wage);

	printf("�������޸ĺ��н������:"); 	
	scanf("%f\n",&GZZG[i].pay_wages);
	
	printf("�������޸ĺ��ְ�����:");
	scanf("%f\n",&GZZG[i].post_allowance);
	
	printf("�������޸ĺ�ļ�Ч����:");
	scanf("%f\n",&GZZG[i].merit_pay);
	
//	return 0;
}


void del()			//ɾ��ְ���������� 976872969
{
	char gonghao[10];
	int i,j,k,h;
	printf("			��������Ҫɾ����ְ���������ݵĹ��ţ�");
	scanf("%s",gonghao);
	for(int i=0;i<n;i++)				//����Ҫɾ����ְ���������ݵ����� 
		if(strcmp(GZZG[i].number,gonghao)==0)
		{
			printf("			***************************\n") ;
			printf("			|���ţ�");
			printf("%s\n",GZZG[i].number);
			
			printf("			|������");
			printf("%s\n",GZZG[i].name);
			
			printf("			|��λ���ʣ�");
			printf("%.2f\n",GZZG[i].wage);
				
			printf("			|н�����ʣ�");
			printf("%.2f\n",GZZG[i].pay_wages);
			
			printf("			|ְ�������");
			printf("%.2f\n",GZZG[i].post_allowance);
			
			printf("			|��Ч������");
			printf("%.2f\n",GZZG[i].merit_pay);
			
			printf("			|Ӧ�����ʣ�");
			printf("%.2f\n",GZZG[i].should_pay);
			
			printf("			|��������˰��");
			printf("%.2f\n",GZZG[i].personal_income_tax);		
			
			printf("			|ʵ�����ʣ�");
			printf("%.2f\n",GZZG[i].real_pay);
			printf("			***************************\n\n");
			break;
		} 
	printf("			|*********************************|\n");
	printf("			|��ȷ�ϸ�ְ�����������Ƿ���ȷ!!\n"); 
	printf("			|������1ִ��ɾ��������\n");
	printf("			|�������������2��\n");
	printf("			|*********************************|\n");
	printf("			�����룺"); 
	scanf("%d",&j);
	if(j==2)
	{
		printf("			�˳��ò���;������xxxx��δʵ�֣�" );
	}
	else if(j==1)
	{
		for(k==h;k<n-1;k++)
		{
			GZZG[k]=GZZG[k+1];
		}
		printf("			�޸���ɣ���");
	}
	if(h==n)
	{
		printf("ɾ����Ա��Ϊ���һ��:");
	}
	else
	{
		cout<<h<<endl;
		printf("			|���ţ�");
		printf("%s\n",GZZG[h].number);
			
		printf("			|������");
		printf("%s\n",GZZG[h].name);
			
		printf("			|��λ���ʣ�");
		printf("%.2f\n",GZZG[h].wage);
				
		printf("			|н�����ʣ�");
		printf("%.2f\n",GZZG[h].pay_wages);
			
		printf("			|ְ�������");
		printf("%.2f\n",GZZG[h].post_allowance);
			
		printf("			|��Ч������");
		printf("%.2f\n",GZZG[h].merit_pay);
			
		printf("			|Ӧ�����ʣ�");
		printf("%.2f\n",GZZG[h].should_pay);
			
		printf("			|��������˰��");
		printf("%.2f\n",GZZG[h].personal_income_tax);		
			
		printf("			|ʵ�����ʣ�");
		printf("%.2f\n",GZZG[h].real_pay);
	}
} 



void add()			//���ְ���������� 
{
/*
������Ҫע��һ���ڣ�scanf�� ��\n�� ���Ǳ�ʾ����һ���س�����
���Ǳ�ʾ�������еĿհ��ַ��������س�,�ո�,tab ����������Ҫ
��������,��������һ���ǿհ��ַ�����,���Ǹ��ַ���Ȼ�����ڻ������С�
����scanf���꣬���س������Զ����� 
*/
	printf("\t\t\t�����������ְ���Ĺ���:");
	scanf("%s",GZZG[n].number);

	printf("\t\t\t�����������ְ��������:");
	scanf("%s\n",GZZG[n].name);

	printf("\t\t\t�����������ְ���ĸ�λ����:");
	scanf("%f",&GZZG[n].wage);
		
	printf("\t\t\t�����������ְ����н������:");
	scanf("%f",&GZZG[n].pay_wages);
	
	printf("\t\t\t�����������ְ����ְ�����:");
	scanf("%f",&GZZG[n].post_allowance);
	
	printf("\t\t\t�����������ְ���ļ�Ч����:");
	scanf("%f",&GZZG[n].merit_pay);		

	/*
	��������ʱҪȡ��ַ��&
	�������ʱ���� 
	*/
	
}



void func_real_pay()	//����ʵ������ 
{
	int i;
//	grsds();
	for(i=0;i<n;i++)
	{
		GZZG[i].real_pay=GZZG[i].should_pay-GZZG[i].personal_income_tax;	
	} 
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
	int i; 
/*
	cout<<"			"<<"|***************************|"<<endl;
	cout<<"			"<<"|��ӭ����˵�����"<<endl;
	cout<<"			"<<"|��ѯְ��������ϸ��Ϣ������1"<<endl;
	cout<<"			"<<"|�޸�ְ��������ϸ��Ϣ������2"<<endl;
	cout<<"			"<<"|����µ�ְ��������Ϣ������3"<<endl;
	cout<<"			"<<"|ɾ��ְ������������4"<<endl;
	cout<<"			"<<"|���浱ǰ����������5"<<endl;
	cout<<"			"<<"|�������ְ��������Ϣ������6"<<endl;
	cout<<"			"<<"|�˳��˵�������7"<<endl;	
	cout<<"			"<<"|***************************|"<<endl;
*/
	printf("\t\t\t###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n\n");
	printf("\t\t\t��ѡ��<1 - 7>:\n");
	printf("\t\t\t===============================================================\n");
	printf("\t\t\t|\t1.��ѯְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t2.�޸�ְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t3.���ְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t4.ɾ��ְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t5.�������ݵ��ļ�                                      |\n");
	printf("\t\t\t|\t6.���ְ����¼                                        |\n");
	printf("\t\t\t|\t7.�˳�ϵͳ                                            |\n");
	printf("\t\t\t===============================================================\n\n");
	printf("\t\t\t���ѡ���ǣ�");
	scanf("%d",&i);
	cout<<i;
	/*
	�ɸĳ�while��� 
	*/


	
	
	if(i==1)
	{
		printf("��ӭʹ�ò�ѯ���ܣ������������ʾ����");
		find();
	}
	else if(i==2)
	{
		printf("��ӭʹ���޸Ĺ��ܣ������������ʾ����");
		modify();
	}
	else if(i==3)
	{
		printf("��ӭʹ����ӹ��ܣ������������ʾ����");
		add();
	}
	else if(i==4)
	{
		printf("��ӭʹ��ɾ�����ܣ������������ʾ����");
		del(); 
	}
	else if(i==5)
	{
		printf("��ӭʹ�ñ��湦�ܣ������������ʾ����");
		write();
	}
	else if(i==6)
	{
		printf("��ӭʹ��������ܣ������������ʾ����\n");
		list();
		
	}
	else if(i==7)
	{
		printf("��ӭʹ�ò�ѯ���ܣ������������ʾ����\n");
	}
	else 
	{
		printf("����������������룺\n");
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
	printf("\t\t\t###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n\n");
	printf("\t\t\t��ѡ��<1 - 7>:\n");
	printf("\t\t\t===============================================================\n");
	printf("\t\t\t|\t1.��ѯְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t2.�޸�ְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t3.���ְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t4.ɾ��ְ�����ʼ�¼                                    |\n");
	printf("\t\t\t|\t5.�������ݵ��ļ�                                      |\n");
	printf("\t\t\t|\t6.���ְ����¼                                        |\n");
	printf("\t\t\t|\t7.�˳�ϵͳ                                            |\n");
	printf("\t\t\t===============================================================\n\n");
	printf("\t\t\t���ѡ���ǣ�");
	scanf("%d",&i);

	�ɸĳ�while��� 
	*/
	
	
	/*
	ʹ��һ��do while()��� 
	*/
	do
	{
	//	system("cls");
		printf("\t\t\t###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n\n");
		printf("\t\t\t��ѡ��<1 - 7>:\n");
		printf("\t\t\t===============================================================\n");
		printf("\t\t\t|\t1.��ѯְ�����ʼ�¼                                    |\n");
		printf("\t\t\t|\t2.�޸�ְ�����ʼ�¼                                    |\n");
		printf("\t\t\t|\t3.���ְ�����ʼ�¼                                    |\n");
		printf("\t\t\t|\t4.ɾ��ְ�����ʼ�¼                                    |\n");
		printf("\t\t\t|\t5.�������ݵ��ļ�                                      |\n");
		printf("\t\t\t|\t6.���ְ����¼                                        |\n");
		printf("\t\t\t|\t7.�˳�ϵͳ                                            |\n");
		printf("\t\t\t===============================================================\n\n");
		printf("\t\t\t���ѡ���ǣ�");
		scanf("%d",&i);	
		
		switch(i)
		{
			case 1:
				printf("\t\t\t��ӭʹ�ò�ѯ���ܣ������������ʾ����\n");
				grsds();
				func_real_pay();
				find();
				break;
		
			case 2:
				printf("\t\t\t��ӭʹ���޸Ĺ��ܣ������������ʾ����\n");
				modify();
				break;
			
			case 3:
				printf("\t\t\t��ӭʹ����ӹ��ܣ������������ʾ����\n");
				add();
				break;
			
			case 4:
				printf("\t\t\t��ӭʹ��ɾ�����ܣ������������ʾ����\n");
				del(); 
				break;
			
			case 5:
				printf("\t\t\t��ӭʹ�ñ��湦�ܣ������������ʾ����");
				write();
				break;
			
			case 6:
				printf("\t\t\t��ӭʹ��������ܣ������������ʾ����\n");
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

		printf("\t\t\t��ӭʹ�ò�ѯ���ܣ������������ʾ����\n");
		grsds();
		func_real_pay();
		find();
	}
	else if(i==2)
	{
		printf("\t\t\t��ӭʹ���޸Ĺ��ܣ������������ʾ����\n");
		modify();
	}
	else if(i==3)
	{
		printf("\t\t\t��ӭʹ����ӹ��ܣ������������ʾ����\n");
		add();
	}
	else if(i==4)
	{
		printf("\t\t\t��ӭʹ��ɾ�����ܣ������������ʾ����\n");
		del(); 
	}
	else if(i==5)
	{
		printf("\t\t\t��ӭʹ�ñ��湦�ܣ������������ʾ����");
		write();
	}
	else if(i==6)
	{
		printf("\t\t\t��ӭʹ��������ܣ������������ʾ����\n");
		list();
		
	}
	else if(i==7)
	{
		printf("\t\t\t��ӭʹ�ò�ѯ���ܣ������������ʾ����\n");
	}
	else 
	{
		printf("\t\t\t����������������룺\n");
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
	cout<<"		"<<"		"<<"hello����ޣ�����"<<endl;
	cout<<endl;
	cout<<"		"<<"||***************************************||" <<endl;
	cout<<"		"<<"||��ʼ����˵������ڽ���˵�����ʾ���� ||"<<endl; 
	cout<<"		"<<"||***************************************||" <<endl;
	menu(); 

	cout<<GZZG[n].name<<endl;
	cout<<"hello"<<endl; 
	add();

	system("cls");	//��������
	menu(); 
	*/
	return 0;
} 
