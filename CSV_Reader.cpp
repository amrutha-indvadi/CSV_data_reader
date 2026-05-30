
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 256

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int Number;
	char Name[50];
	float Mark;
}Student;

int Initial = 0;
int Extended = 0;

void ReadFile(Student* Students, char* Line)
{
	char* LineStart = NULL;
	char* LineLast = NULL;
	int LineLength = 0;

	//Number
	LineStart = &Line[0];
	LineLast = strchr(Line, ',');
	LineLength = LineLast - LineStart;

	char* NumberString = (char*)malloc(sizeof(char) * (LineLength + 1));
	memset(NumberString, 0, (sizeof(char) * LineLength));
	strncpy(NumberString, Line, LineLength);
	NumberString[LineLength] = '\0';
	Students->Number = atoi(NumberString);

	//Name
	Line = &Line[0] + LineLength + 1;
	LineStart = &Line[0];
	LineLast = strchr(Line, ',');
	LineLength = LineLast - LineStart;

	char* NameString = (char*)malloc(sizeof(char) * (LineLength + 1));
	memset(NameString, 0, (sizeof(char) * LineLength));
	strncpy(NameString, Line, LineLength);
	NameString[LineLength] = '\0';
	strcpy(Students->Name, NameString);

	//Mark
	Line = &Line[0] + LineLength + 1;

	char* MarkString = (char*)malloc(sizeof(char) * (LineLength + 1));
	memset(MarkString, 0, (sizeof(char) * LineLength));
	strncpy(MarkString, Line, LineLength + 1);
	MarkString[LineLength] = '\0';
	Students->Mark = atof(MarkString);
}

int main()
{
	char FileLineBuffer[BUFFER_SIZE];

	FILE* File = fopen("Records.csv", "r");

	Student* Students = NULL;

	if (Initial >= Extended)
	{
		Student* Temp = (Student*)realloc(Students, sizeof(Student) * (Extended + 5));
		if (Temp)
		{
			Students = Temp;
			memset(Students + Extended, 0, sizeof(Student));
			Extended += 10;
		}
		memcpy(Students + Initial, &Students, sizeof(Students));
		Initial++;
	}

	while (fgets(FileLineBuffer, BUFFER_SIZE, File) != NULL)
	{
		ReadFile(Students, FileLineBuffer);
		printf("%-20d\t %-20s\t %-20f\t\n", Students->Number, Students->Name, Students->Mark);
	}

	fclose(File);
	return 0;
}
