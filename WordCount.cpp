#include <stdio.h>
#include <string.h>
#include <malloc.h>
int wordcount(char *Filename);
int charcount(char *Filename);
//主函数入口 
int main(int input0, char *input[]) {


	//char Filename[50];
	//int totalchar = 0;
	//int totalword = 0;
	//如果输入信息中有提示词“-w”是要判断单词数时，将进入以下分支 
	if (!strcmp(input[1], "-w"))
	 {
		wordcount(input[2]);
	} 
	//如果输入信息中有提示词“-c”是要判断字符数时，将进入以下分支 
	else if (!strcmp(input[1], "-c"))
	 {
		charcount(input[2]);
	}
	//如果输入信息中没有相应提示字符时，则判定为输入错误，无法进行相关的计算 
	else
	{
		printf("输入信息有错误，请重新输入:\n");
	}
	return 0;
}
//计算单词数的函数 
int wordcount(char *Filename) {
	FILE *fp0 = NULL;       //定义文件类型的指针 
	FILE *fp1 = NULL;
	char buffer[2024];  	//定义缓冲暂存区 
	int bufferlength = 0;      
	int i = 0;
	char c;                //定义变量存储得到的单词，用来判断是否已到达文档结尾 
	bool isLastEnd = 0;
	int totalword = 0;
	int wordnum = 0;
	if ( (fp0 = fopen(Filename, "rb")) == NULL ) {
		//如果文件错误将输出打印相关的错误信息 
		perror(Filename);
		return NULL;
	}

	while (fgets(buffer, 2024, fp0) != NULL)    //循环统计单词的个数 
	{
		bufferlength = strlen(buffer);

		for (i = 0; i < bufferlength; i++) {
			c = buffer[i];
			if ( c == ' ' || c == '\t') {
				!isLastEnd &&wordnum++;
				isLastEnd = true;
			} else if (c != '\n' && c != '\r') {

				isLastEnd = false;
			}
		}
		!isLastEnd &&wordnum++;
		isLastEnd = true;
		totalword += wordnum;
		wordnum = 0;         //重置变量为零，以便下一次循环 
	}
	printf("单词数:%d ", totalword);
	fp1 = fopen("result.txt", "a");
	if (fp1) {
		fprintf(fp1, "单词数:%d\n", totalword);
		fclose(fp1);
	}
	else
	{
		
	}
	return 0;
}

//计算字符数的函数 
int charcount(char *Filename) {

	FILE *fp0 = NULL;      //定义文件类型的指针
	FILE *fp1 = NULL;
	char buffer[2024];     //定义缓冲暂存区 
	int bufferlength = 0;
	int i = 0;
	char c;                //定义变量存储得到的字符，用来判断是否已到达文档结尾 
	bool isLastEnd = 0;
	int totalchar = 0;
	int charnum = 0;
	if ( (fp0 = fopen(Filename, "rb")) == NULL ) 
	{
		perror(Filename);
		return NULL;
	}
	while (fgets(buffer, 2024, fp0) != NULL)     //循环统计的字符数量 
	{
		bufferlength = strlen(buffer);
		for (i = 0; i < bufferlength; i++) {
			c = buffer[i];
			if ( c == ' ' || c == '\t') {
				isLastEnd = true;
			} else if (c != '\n' && c != '\r') {
				charnum++;
				isLastEnd = false; 
			}
		}

		isLastEnd = true;

		totalchar += charnum;

		charnum = 0;               //重置变量为零，以便下一次循环 

	}
	printf("字符数:%d", totalchar);
	fp1 = fopen("result.txt", "a");
	if (fp1) 
	{
		fprintf(fp1, "字符数:%d\n", totalchar);
		fclose(fp1);
	}
	else{
		
	} 
	return 0;
}
