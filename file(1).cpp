#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define M 100
int n=0;																							 //����һ��ȫ�ֱ���
typedef struct people  
{  
	char number[10];			//����
    char name[10];				//����  
    float wage;					//��λ����  
	float pay_wages;			//н������
	float post_allowance;		//ְ�����
	float merit_pay;			//��Ч����
	float should_pay;			//Ӧ������
	float personal_income_tax;	//��������˰
	float real_pay;				//ʵ������
}ZGGZ;//�������ݽṹ��


int menu_select()																					//����ѡ��ģ��
{  
    char c;  
    do  
    {  
        system("cls");        
        printf("\t\t1.��ѯְ������\n");  
        printf("\t\t2.�޸�ְ������\n");  
        printf("\t\t3.���ְ������ \n");  
        printf("\t\t4.ɾ��ְ������\n");  
        printf("\t\t5.���ְ������\n");  
        printf("\t\t6.����ְ������\n");  
        printf("\t\t7.�˳� \n");  
        printf("\t\t����ѡ��(1-7):");      
        c=getchar();   
    }while(c<'1'||c>'7');//��������Ƿ���Ϲ淶  
    return(c-'0');  
}  

int read(ZGGZ t[])																					//�ļ���ȡģ��
{
	   int i;
       FILE *fp;//�����ļ�ָ��
       if ((fp = fopen("gx.dat", "rb")) == NULL)
       {
              printf("���������ļ���ʧ�ܣ������ļ��Ƿ���ڻ��𻵺�����!");
              return 0;
       }
	   fscanf(fp,"%d",&n);
	   for(i=0;i<n;i++)
		   fscanf(fp,"%10s%10s%f%f%f%f%f%f%f",t[i].number,t[i].name,&t[i].wage,&t[i].pay_wages,&t[i].post_allowance,&t[i].merit_pay,&t[i].should_pay,&t[i].personal_income_tax,&t[i].real_pay);
       fclose(fp);
       return 0;
}

int find(ZGGZ S[])						//���ʲ�ѯģ��  
{  
	int m,j;  
    char flag='y';  
    while(flag!='n'&&flag!='N')  
    {  
		system("cls");
        printf("\n\t\t***********��ѯ��ʽ************\n");  
        printf("\t\t��------------------------------��\n");  
        printf("\t\t��          1.���ҹ���          ��\n");  
        printf("\t\t��          2.��������          ��\n");  
        printf("\t\t��          3.����              ��\n");    
        printf("\t\t��------------------------------��\n");  
        printf("\n\t\t��ѡ���ѯ��ʽ:");  
        scanf("\t\t%d",&m);					//ѡ���ѯ��ʽ  
	
		do										//��������Ƿ���Ϲ淶  
			{  
				j=0;  
				if(m!=1&&m!=2&&m!=3)  
				{     
					j=1;  
					printf("\t\t������Ĳ�ѯ��ʽ������,����������:");  
					scanf("\t\t%d",&m);			//�����Ϲ淶������ѡ���ѯ��ʽ  
				}  
			}while(j); 

		if(m==1)								//���Ų�ѯ
			{
				int i;							//���ڲ�ѯԱ�����
				int flag=0;						//���Ա����û�д���
				char gonghao[10];
				printf("\n");
				printf("������Ҫ��ѯԱ���ı�ţ�");
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
					printf("\t\t����:%s\n",S[i].name);  
					printf("\t\t��λ����:%f\n",S[i].wage);  
					printf("\t\tн������:%f\n",S[i].pay_wages);  
					printf("\t\tְ�����:%f\n",S[i].post_allowance);  
					printf("\t\t��Ч����:%f\n",S[i].merit_pay);  
					printf("\t\tӦ������:%f\n",S[i].should_pay);
					printf("\t\t��������˰:%f\n",S[i].personal_income_tax);  
					printf("\t\tʵ������:%f\n",S[i].real_pay);  
				}
				else
				{
					printf("û���ҵ��ñ�ŵ�Ա����\n");
				}
				printf("\n");
				system("pause");
			}

		if(m==2)								//������ѯ
		{
			int i;								//���ڲ�ѯԱ�����
			int flag=0;							//���Ա����û�д���
			char nm[10];
			printf("\n");
			printf("������Ҫ��ѯԱ����������");
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
					for (i = 0; i < n; i++)			//��ֹ��������״��
					{
						if (strcmp(S[i].name,nm)==0)
						{
							printf("\n\t\t����:%s\n",S[i].number);  
							printf("\t\t��λ����:%f\n",S[i].name);  
							printf("\t\tн������:%f\n",S[i].wage);  
							printf("\t\tְ�����:%f\n",S[i].pay_wages);  
							printf("\t\t��Ч����:%f\n",S[i].merit_pay);  
							printf("\t\tӦ������:%f\n",S[i].should_pay);
							printf("\t\t��������˰:%f\n",S[i].personal_income_tax);  
							printf("\t\tʵ������:%f\n",S[i].real_pay);  
						}
					}
				
			}
			else
			{
				printf("û���ҵ���������Ա����\n");
			}
			printf("\n");
			system("pause");
		}

		if(m==3)							    	//����
		{
			return 0;
		}

		printf("\t\t�Ƿ������ѯ?(Y/N)");  
		scanf("\t\t%c",&flag);  
	}
	return 0;  
}  

void add_money(ZGGZ S[])									//�Լ�ģ�� ����Ӧ������       
{
	for(int i=0;i<n;i++)
		S[i].should_pay=S[i].wage+S[i].pay_wages+S[i].post_allowance+S[i].merit_pay;
}

void grsds(ZGGZ S[])										//�Լ�ģ�� �����������˰       
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

void add_wages(ZGGZ S[])																									//�Լ�ģ�� ����ʵ������	       
{
	for(int i=0;i<n;i++)
		S[i].real_pay=S[i].should_pay-S[i].tax;
}

int list(ZGGZ S[])																											//���ģ��
{
	
	int i=0;																												//��ǰ�����λ��
	char flag='y';																											//�ж��Ƿ�������
	int m,j;																												//ѡ�������ʽ
	int k=10;																												//��������������,Ĭ��Ϊ10

		system("cls");
		printf("\n\t\t***********�����ʽ************\n");  
		printf("\t\t��------------------------------��\n");  
		printf("\t\t��          1.���������        ��\n");  
		printf("\t\t��          2.ȫ�����          ��\n");  
		printf("\t\t��          3.����              ��\n");    
		printf("\t\t��------------------------------��\n");  
		printf("\n\t\t��ѡ���ѯ��ʽ:");  
		scanf("\t\t%d",&m);																									//ѡ�������ʽ  
		do																													//��������Ƿ���Ϲ淶  
		{  
			j=0;  
			if(m!=1&&m!=2&&m!=3)  
			{     
				j=1;  
				printf("\t\t������������ʽ������,����������:");  
				scanf("\t\t%d",&m);																							//�����Ϲ淶������ѡ�������ʽ  
			}  
		}while(j); 

	if(m==1)																												//���������
	{
		printf("\n");
		printf("�����뵥������������(Ĭ��Ϊ10):");
		scanf("%d",&k);
		printf("\n����������:");
		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("����:%s  %s\n",S[i].number,S[i].name);  
			printf("��λ����:%f\tн������:%f\tְ�����:%f\t��Ч����:%f\n",S[i].wage,S[i].pay_wages,S[i].post_allowance,S[i].merit_pay);  
			printf("Ӧ������:%f\t��������˰:%f\tʵ������:%f",S[i].should_pay,S[i].personal_income_tax,S[i].real_pay);
			printf("\n");
			i++;		 
			if(i%k==0)
			{	
				printf("\n");
				printf("\t\t�Ƿ�������?(Y/N)");  
				scanf("\t\t%c",&flag); 
			}
		}
		printf("\n����������ȫ��������,�����Զ��������˵�\n\n");
	}
	
	if(m==2)																												//ȫ�����
	{

		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("����:%s  %s\n",S[i].number,S[i].name);  
			printf("��λ����:%f\tн������:%f\tְ�����:%f\t��Ч����:%f\n",S[i].wage,S[i].pay_wages,S[i].post_allowance,S[i].merit_pay);  
			printf("Ӧ������:%f\t��������˰:%f\tʵ������:%f",S[i].should_pay,S[i].personal_income_tax,S[i].real_pay);
			printf("\n");
			i++;		 
		}
		printf("\n����������ȫ��������,�����Զ��������˵�\n\n");
	}
	
	if(m==3)																												//����
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
            printf("\n\t\t��ѯְ����������\n");  
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
            printf("\n\t\t������δ���ƣ��뾡���ڴ�\n");  
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
            printf("\n\t\tллʹ�ã��ټ�!\n");  //��������      
            printf("\n\t\t");      
            system("pause");      
            exit(0);      
        }  
    }  

	return 0;
}
