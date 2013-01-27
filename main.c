/*
本程序利用单位相乘再相加的
9^5
计算5次过程是：
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
#define Single 4000//精度若要修改精度只需修改这里此时精度为50

int add(int tag,long int Sum[],long int Mod[])//递归调用要求下一位的进位先求下一位的下一位的进位排除上一位为89下一位进位为1的情况
{
	int adds;
	if (tag==0)//第1位的下位0进位为0
	{
		adds=0;	
	}
	else
	{
		adds =(add(tag-1,Sum,Mod) +Sum[tag]+Mod[tag])/10;//本位的进位为下位的进位循环到第一位
	}
	return adds;
}

int main()
{
	int b,i,j,count;
	long int a;
    long int sum[Single+2],mod[Single+1];
	int result[Single+1];//每次乘a的最后结果
	while(1)//初始化result各个位为0
	{
	for(i=0;i<=Single;i++)
	{
		result[i]=0;
	}
	result[1]=1;//初始化result第一位为1为第一次a*result准备
	system("title 颜海镜任意精度a^^b1.0beta版");//批处理之转义字符，改标题
	printf("请输入整数a,b 注：a !=0 ms < 10^10,b>0 注：若a为负数，b不能为奇数\n");
	scanf("%d,%d",&a,&b);
	for(i=1;i<=b;i++)//循环b次，第一次为a*1
	{
		for(j=0;j<=Single;j++)//初始化sum和mod
		{
			sum[j]=0;
			mod[j]=0;
		}
		sum[Single+1]=0;//初始化第51个数字，判断是否溢出
		for(j=1;j<=Single;j++)//循环得出a*各个位的数字
		{
			sum[j+1]=(result[j]*a)/10;//想乘的进位部分
			mod[j]=(result[j]*a)%10;//想乘的余数部分
		}
		for(j=1;j<=Single;j++)//初始化result为0为下次循环使用
		{
			result[j]=0;
		}
		for(j=1;j<=Single;j++)//循环得出最后各个位的结果
		{
			result[j]=(sum[j]+mod[j]+add(j-1,sum,mod))%10;//递归调用
		}
	}
	printf("支持最大精度：%d\n",Single);
	if(sum[Single+1]!=0) printf("Error!!!\n溢出了猪头，试试改下精度\n");//判断是否溢出
	else
	{
		i=Single;//初始化
		count=0;
		while(result[i]==0)
		{
			i--;//找到第一个不为0 的位置
		}
		for(;i>=1;i--)//循环输出最后结果
		{
			printf("%d",result[i]);
			count++;
		}
		printf("\n当前有效数：%d\n",count);
	}
	system("pause>null && cls");//暂停清屏详见DOS命令行
	
	}
	return 0;
}
