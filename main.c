/*
���������õ�λ�������ӵ�
9^5
����5�ι����ǣ�
1.
1*9=9
sum[2]=0,mod[1]=9
result[1]=9
2.
9*9=81
sum[2]=8,mod[1]=1
result[2]=8 result[1]=1
3.
81*9
sum[2]=0 mod[1]=9
sum[3]=7 mod[2]=2
result[3]=7 result[2]=2 result[1]=9
4.
729*9
...
5.
6561*9
...
*/
#include <stdio.h>
#include<stdlib.h>
#define Single 4000//������Ҫ�޸ľ���ֻ���޸������ʱ����Ϊ50

int add(int tag,long int Sum[],long int Mod[])//�ݹ����Ҫ����һλ�Ľ�λ������һλ����һλ�Ľ�λ�ų���һλΪ89��һλ��λΪ1�����
{
	int adds;
	if (tag==0)//��1λ����λ0��λΪ0
	{
		adds=0;	
	}
	else
	{
		adds =(add(tag-1,Sum,Mod) +Sum[tag]+Mod[tag])/10;//��λ�Ľ�λΪ��λ�Ľ�λѭ������һλ
	}
	return adds;
}

int main()
{
	int b,i,j,count;
	long int a;
    long int sum[Single+2],mod[Single+1];
	int result[Single+1];//ÿ�γ�a�������
	while(1)//��ʼ��result����λΪ0
	{
	for(i=0;i<=Single;i++)
	{
		result[i]=0;
	}
	result[1]=1;//��ʼ��result��һλΪ1Ϊ��һ��a*result׼��
	system("title �պ������⾫��a^^b1.0beta��");//������֮ת���ַ����ı���
	printf("����������a,b ע��a !=0 ms < 10^10,b>0 ע����aΪ������b����Ϊ����\n");
	scanf("%d,%d",&a,&b);
	for(i=1;i<=b;i++)//ѭ��b�Σ���һ��Ϊa*1
	{
		for(j=0;j<=Single;j++)//��ʼ��sum��mod
		{
			sum[j]=0;
			mod[j]=0;
		}
		sum[Single+1]=0;//��ʼ����51�����֣��ж��Ƿ����
		for(j=1;j<=Single;j++)//ѭ���ó�a*����λ������
		{
			sum[j+1]=(result[j]*a)/10;//��˵Ľ�λ����
			mod[j]=(result[j]*a)%10;//��˵���������
		}
		for(j=1;j<=Single;j++)//��ʼ��resultΪ0Ϊ�´�ѭ��ʹ��
		{
			result[j]=0;
		}
		for(j=1;j<=Single;j++)//ѭ���ó�������λ�Ľ��
		{
			result[j]=(sum[j]+mod[j]+add(j-1,sum,mod))%10;//�ݹ����
		}
	}
	printf("֧����󾫶ȣ�%d\n",Single);
	if(sum[Single+1]!=0) printf("Error!!!\n�������ͷ�����Ը��¾���\n");//�ж��Ƿ����
	else
	{
		i=Single;//��ʼ��
		count=0;
		while(result[i]==0)
		{
			i--;//�ҵ���һ����Ϊ0 ��λ��
		}
		for(;i>=1;i--)//ѭ����������
		{
			printf("%d",result[i]);
			count++;
		}
		printf("\n��ǰ��Ч����%d\n",count);
	}
	system("pause>null && cls");//��ͣ�������DOS������
	
	}
	return 0;
}
