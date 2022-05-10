#include <stdio.h>
#include <string.h>
#include <malloc.h>
int wordcount(char *filename);
int charcount(char *filename);

int main(int argc, char *argv[]) {

	//第一个参数默认是可执行文件本身，第二个参数开始是接受到的参数

	char filename[30];
	char operation;
	int toalchar;
	int totalword;
	if (!strcmp(argv[1], "-w")) {
		wordcount(argv[2]);
	} else if (!strcmp(argv[1], "-c")) {
		charcount(argv[2]);
	}
	return 0;
}

int wordcount(char *filename) {
	FILE *fp = NULL;
	FILE *fp2 = NULL;
	char buffer[1003];
	int bufferLen;
	int i;
	char c;
	int isLastBlank = 0;
	int totalword = 0;
	int wordNum = 0;
	if ( (fp = fopen(filename, "rb")) == NULL ) {
		perror(filename);
		return NULL;
	}

	while (fgets(buffer, 1003, fp) != NULL) {
		bufferLen = strlen(buffer);

		for (i = 0; i < bufferLen; i++) {
			c = buffer[i];
			if ( c == ' ' || c == '\t') {
				!isLastBlank &&wordNum++;
				isLastBlank = 1;
			} else if (c != '\n' && c != '\r') {

				isLastBlank = 0;
			}
		}
		!isLastBlank &&wordNum++;
		isLastBlank = 1;
		totalword += wordNum;
		wordNum = 0;
	}
	printf("单词数:%d ", totalword);
	fp2 = fopen("result.txt", "a");
	if (fp2) {
		fprintf(fp2, "单词数:%d\n", totalword);
		fclose(fp2);
	}
	return 0;
}


int charcount(char *filename) {

	FILE *fp = NULL;
	FILE *fp2 = NULL;
	char buffer[1003];
	int bufferLen;
	int i;
	char c;
	int isLastBlank = 0;
	int totalchar = 0;
	int charNum = 0;
	if ( (fp = fopen(filename, "rb")) == NULL ) {
		perror(filename);
		return NULL;
	}
	while (fgets(buffer, 1003, fp) != NULL) {
		bufferLen = strlen(buffer);
		for (i = 0; i < bufferLen; i++) {
			c = buffer[i];
			if ( c == ' ' || c == '\t') {
				isLastBlank = 1;
			} else if (c != '\n' && c != '\r') {
				charNum++;
				isLastBlank = 0;
			}
		}

		isLastBlank = 1;

		totalchar += charNum;

		charNum = 0;

	}
	printf("字符数:%d", totalchar);
	fp2 = fopen("result.txt", "a");
	if (fp2) {
		fprintf(fp2, "字符数:%d\n", totalchar);
		fclose(fp2);
	}
	return 0;
}
