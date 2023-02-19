//
// Created by 伍高巍 on 2023/2/19.
//

//有5个学生，每个学生又三门课的成绩，从键盘输入学生数据（包括学生号、姓名、三门课的成绩），计算出平均成绩，将原有数据和计算出的平均分数存放在磁盘文件“stud”中。

#include <cstdio>
#include <cstdlib>

#define N 5

struct Stduent
{
	int no;
	char name[10];
	int score1;
	int score2;
	int score3;
	int avg_score;
};

typedef struct Stduent Student;

int main()
{
	Stduent std[N];
	FILE *f;
	f = std::fopen("../2008/stdu.txt", "w+");
	if (f == NULL)
	{
		printf("文件创建失败!\n");
		exit(0);
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &std[i].no);
		scanf("%s", std[i].name);
		scanf("%d", &std[i].score1);
		scanf("%d", &std[i].score2);
		scanf("%d", &std[i].score3);
		std[i].avg_score = (std[i].score1 + std[i].score2 + std[i].score3) / 3;
		fprintf(f, "%d,%s,%d,%d,%d,%d\n", std[i].no, std[i].name, std[i].score1, std[i].score2, std[i].score3,
				std[i].avg_score);
	}
	fclose(f);
	return 0;
}