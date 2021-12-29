**实验报告13**
**李唐 21211010**
**（为什么不能用对计算机更友好的Markdown来代替Word来提交代码？）**

1. 	(动态内存分配)实现一个一元多项式计算系统。多项式的项数和系数保存在数组中，数组通过动态内存分配创建。函数原型如下：double polynomial(int *p, int n, double x)。
```c
int main()
{
	double x, m;
	int n;
	double* p, sum = 0.0;
	scanf("%lf", &x);
	scanf("%d", &n);
	p = (double*)malloc(n * sizeof(double));
	for (int i = 0; i <= n; i++)
	{
		scanf("%lf", (p + i));
	}
	for (int j = 0; j <= n; j++)
	{
		sum += (*(p + j)) * pow(x, n - j);
	}
	printf("%lf\n", sum);
	return 0;
}
```
2. (结构基础)用结构体实现：求一元二次方程ax2+bx+c=0的解
```c
#include <stdio.h>
#include <math.h>
struct EquationInfoStru {
	double a;
	double b;
	double c;
	int nRootStatus;
	double dRoot1;
	double dRoot2;
};
int root(struct EquationInfoStru* pEquaInfo)
{
	if (pEquaInfo->a == 0)
	{
		if (pEquaInfo->b == 0)
		{
			if (pEquaInfo->c == 0)
			{
				printf("infinite answers");
			}
			else {
				pEquaInfo->nRootStatus = 0;
			}
		}
		else {
			pEquaInfo->nRootStatus = 1;
			pEquaInfo->dRoot1 = -1 * pEquaInfo->c / pEquaInfo->b;
		}
	}
	else {
		double delta = pEquaInfo->b * pEquaInfo->b - pEquaInfo->a * pEquaInfo->c * 4;
		if (delta > 0)
		{
			pEquaInfo->nRootStatus = 2;
			pEquaInfo->dRoot1 = (-1 * pEquaInfo->b + sqrt(delta)) / (2 * pEquaInfo->a);
			pEquaInfo->dRoot2 = (-1 * pEquaInfo->b - sqrt(delta)) / (2 * pEquaInfo->a);
		}
		else if (delta == 0)
		{
			pEquaInfo->nRootStatus = 1;
			pEquaInfo->dRoot1 = (-1 * pEquaInfo->b) / (2 * pEquaInfo->a);
		}
		else {
			pEquaInfo->nRootStatus = 0;
		}
	}
	if (pEquaInfo->nRootStatus == 2)
	{
		printf("方程有两个不相等的根，分别为:\n");
		printf("%lf %lf\n", pEquaInfo->dRoot1, pEquaInfo->dRoot2);

	}
	else if (pEquaInfo->nRootStatus == 1)
	{
		printf("方程有两个相等的根，为:\n");
		printf("%lf\n", pEquaInfo->dRoot1);
	}
	else printf("方程无解\n");
	return 0;
}
int main()
{
	EquationInfoStru info = { 0, 0, 0, 0, 0, 0 };
	scanf("%lf %lf %lf", &info.a, &info.b, &info.c);
	root(&info);
	return 0;
}
```

3. (结构基础)用结构体实现如下工程

```c
#include<stdio.h>
#include<stdlib.h>
struct CheckInfoStru {
	char cGender;
	double dHeight;
	double dActualWeight;
	double dStandardWeight;
	double dOverweightPercent;
	int nResult;
};
double StandardWeight(char cGender, double dHeight)
{
	if (cGender == 'm' || cGender == 'M')
		return ((dHeight - 100) * 0.9);
	if (cGender == 'f' || cGender == 'F')
		return ((dHeight - 100) * 0.9 - 2.5);
}
int WeightStatus(double dStandardWeight, double dActualWeight)
{
	if (dStandardWeight <= (0.9 * dActualWeight))
		return 0;
	if ((dStandardWeight > (0.9 * dActualWeight)) && (dStandardWeight <= (1.1 * dActualWeight)))
		return 1;
	if ((dStandardWeight > (1.1 * dActualWeight)) && (dStandardWeight <= (1.2 * dActualWeight)))
		return 2;
	if ((dStandardWeight > (1.2 * dActualWeight)) && (dStandardWeight <= (1.3 * dActualWeight)))
		return 3;
	if ((dStandardWeight > (1.3 * dActualWeight)) && (dStandardWeight <= (1.5 * dActualWeight)))
		return 4;
	if (dStandardWeight > (1.5 * dActualWeight))
		return 5;
}
void OutputResult(struct CheckInfoStru* pUserData)
{
	if ((pUserData->cGender == 'm') || (pUserData->cGender == 'M'))
	{
		printf("您的身高为： %lf cm, 性别：男,体重：%lf kg\n", pUserData->dHeight, pUserData->dActualWeight);
		printf("您的标准体重应为：%lf kg\n", pUserData->dStandardWeight);
		if (pUserData->dOverweightPercent == 0)
		{
			printf("您的体重情况为太瘦\n");
			printf("您的体重低于标准体重的90%%\n");
		}
		else if (pUserData->dOverweightPercent == 1)
		{
			printf("您的体重情况为：正常\n");
			printf("您的体重低于标准体重的110%%且高于标准体重的90%%\n");
		}
		else if (pUserData->dOverweightPercent == 2)
		{
			printf("您的体重情况为：超重\n");
			printf("您的体重低于标准体重的120%%且高于标准体重的110%%\n");
		}
		else if (pUserData->dOverweightPercent == 3)
		{
			printf("您的体重情况为：轻度肥胖\n");
			printf("您的体重低于标准体重130%%且高于标准体重的120%%\n");
		}
		else if (pUserData->dOverweightPercent == 4)
		{
			printf("您的体重情况为：中度肥胖\n");
			printf("您的体重低于标准体重150%%且高于标准体重的130%%\n");
		}
		else if (pUserData->dOverweightPercent == 5)
		{
			printf("您的体重情况为：重度肥胖\n");
			printf("您的体重高于标准体重150%%\n");
		}
	}
	if ((pUserData->cGender == 'f') || (pUserData->cGender == 'F'))
	{
		printf("您的身高为： %lf cm, 性别：女,体重：%lf kg\n", pUserData->dHeight, pUserData->dActualWeight);
		printf("您的标准体重应为：%lf kg\n", pUserData->dStandardWeight);
		if (pUserData->dOverweightPercent == 0)
		{
			printf("您的体重情况为：太瘦\n");
			printf("您的体重低于标准体重的90%%\n");
		}
		else if (pUserData->dOverweightPercent == 1)
		{
			printf("您的体重情况为：正常\n");
			printf("您的体重低于标准体重的110%%且高于标准体重的90%%\n");
		}
		else if (pUserData->dOverweightPercent == 2)
		{
			printf("您的体重情况为：超重\n");
			printf("您的体重低于标准体重的120%%且高于标准体重的110%%\n");
		}
		else if (pUserData->dOverweightPercent == 3)
		{
			printf("您的体重情况为：轻度肥胖\n");
			printf("您的体重低于标准体重130%%且高于标准体重的120%%\n");
		}
		else if (pUserData->dOverweightPercent == 4)
		{
			printf("您的体重情况为：中度肥胖\n");
			printf("您的体重低于标准体重150%%且高于标准体重的130%%\n");
		}
		else if (pUserData->dOverweightPercent == 5)
		{
			printf("您的体重情况为：重度肥胖\n");
			printf("您的体重高于标准体重150%%\n");
		}
	}
}
int main()
{
	CheckInfoStru info = { ' ', 0, 0, 0, 0, 0 };
	int n = 0;
	printf("字符m或M表示男性，f或F表示女性\n");
	printf("身高单位为厘米，取值范围[50.0, 260.0]\n");
	printf("体重单位为kg，取值范围[30.0, 300.0]\n");
	printf("请输入您的身高，性别和体重:\n");
	scanf("%lf", &info.dHeight);
	scanf(" %c", &info.cGender);
	scanf("%lf", &info.dActualWeight);
	while ((info.dHeight < 50) || (info.dHeight > 260) || ((info.cGender != 'm') && (info.cGender != 'M') && (info.cGender != 'f') && (info.cGender != 'F')) || (info.dActualWeight < 30) || (info.dActualWeight > 300))
	{
		n++;
		if (n == 5)
		{
			printf("您已经连续输入错误5次，程序锁定\n");
			system("pause");
		}
		else
			printf("输入错误，你还有%d次输入的机会,请重新输入:\n", 5 - n);
		scanf("%lf", &info.dHeight);
		scanf(" %c", &info.cGender);
		scanf("%lf", &info.dActualWeight);
	}
	info.dStandardWeight = StandardWeight(info.cGender, info.dHeight);
	info.dOverweightPercent = WeightStatus(info.dStandardWeight, info.dActualWeight);
	OutputResult(&info);
	return 0;
}
```

4. **设一个班有若干学生(如10人)，请定义学生结构包含以下信息：学生学号、学生姓名、高级语言程序课的成绩，请写程序完成以下功能**

```c
#include<stdio.h>
struct student
{
	int number;
	char name[10];
	double grade;
}stud[100];

void rank(student* p, int n)
{
	int max = 0;
	for (int j = 0; j < n; j++)
	{
		if ((p + j)->grade >(p + max)->grade)
			max = j;
	}
	printf("第一名的学生信息:\n");
	printf("学号: %d 姓名: %s 成绩: %lf \n", (p + max)->number, (p + max)->name, (p + max)->grade);
}
int main()
{
	int n;
	printf("请输入学生的个数:\n");
	scanf("%d", &n);
	printf("请输入%d个学生的学号，姓名和成绩:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &stud[i].number);
		scanf("%s", stud[i].name);
		scanf("%lf", &stud[i].grade);
	}
	rank(stud, n);
	return 0;
}
```

