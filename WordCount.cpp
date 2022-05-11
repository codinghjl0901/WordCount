#include <stdio.h>
#include <string.h>
#include <malloc.h>
int wordcount(char *Filename);
int charcount(char *Filename);
//��������� 
int main(int input0, char *input[]) {


	//char Filename[50];
	//int totalchar = 0;
	//int totalword = 0;
	//���������Ϣ������ʾ�ʡ�-w����Ҫ�жϵ�����ʱ�����������·�֧ 
	if (!strcmp(input[1], "-w"))
	 {
		wordcount(input[2]);
	} 
	//���������Ϣ������ʾ�ʡ�-c����Ҫ�ж��ַ���ʱ�����������·�֧ 
	else if (!strcmp(input[1], "-c"))
	 {
		charcount(input[2]);
	}
	//���������Ϣ��û����Ӧ��ʾ�ַ�ʱ�����ж�Ϊ��������޷�������صļ��� 
	else
	{
		printf("������Ϣ�д�������������:\n");
	}
	return 0;
}
//���㵥�����ĺ��� 
int wordcount(char *Filename) {
	FILE *fp0 = NULL;       //�����ļ����͵�ָ�� 
	FILE *fp1 = NULL;
	char buffer[2024];  	//���建���ݴ��� 
	int bufferlength = 0;      
	int i = 0;
	char c;                //��������洢�õ��ĵ��ʣ������ж��Ƿ��ѵ����ĵ���β 
	bool isLastEnd = 0;
	int totalword = 0;
	int wordnum = 0;
	if ( (fp0 = fopen(Filename, "rb")) == NULL ) {
		//����ļ����������ӡ��صĴ�����Ϣ 
		perror(Filename);
		return NULL;
	}

	while (fgets(buffer, 2024, fp0) != NULL)    //ѭ��ͳ�Ƶ��ʵĸ��� 
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
		wordnum = 0;         //���ñ���Ϊ�㣬�Ա���һ��ѭ�� 
	}
	printf("������:%d ", totalword);
	fp1 = fopen("result.txt", "a");
	if (fp1) {
		fprintf(fp1, "������:%d\n", totalword);
		fclose(fp1);
	}
	else
	{
		
	}
	return 0;
}

//�����ַ����ĺ��� 
int charcount(char *Filename) {

	FILE *fp0 = NULL;      //�����ļ����͵�ָ��
	FILE *fp1 = NULL;
	char buffer[2024];     //���建���ݴ��� 
	int bufferlength = 0;
	int i = 0;
	char c;                //��������洢�õ����ַ��������ж��Ƿ��ѵ����ĵ���β 
	bool isLastEnd = 0;
	int totalchar = 0;
	int charnum = 0;
	if ( (fp0 = fopen(Filename, "rb")) == NULL ) 
	{
		perror(Filename);
		return NULL;
	}
	while (fgets(buffer, 2024, fp0) != NULL)     //ѭ��ͳ�Ƶ��ַ����� 
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

		charnum = 0;               //���ñ���Ϊ�㣬�Ա���һ��ѭ�� 

	}
	printf("�ַ���:%d", totalchar);
	fp1 = fopen("result.txt", "a");
	if (fp1) 
	{
		fprintf(fp1, "�ַ���:%d\n", totalchar);
		fclose(fp1);
	}
	else{
		
	} 
	return 0;
}
