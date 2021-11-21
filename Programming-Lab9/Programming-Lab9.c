#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

typedef struct
{
	char surname[MAX_SIZE];
	char group[MAX_SIZE];
} Student;

int main()
{
	int size;
	printf("Enter size of array: ");
	scanf_s("%d", &size);
	getchar();

	Student* students = calloc(size, sizeof(Student));

	printf("\nEnter students:\n\n");
	for (int i = 0; i < size; i++)
	{
		char surname[MAX_SIZE];
		char group[MAX_SIZE];

		printf("Enter student %d:\n", i + 1);

		printf("Enter surname: ");
		gets_s(surname, MAX_SIZE);

		printf("Enter group: ");
		gets_s(group, MAX_SIZE);

		strcpy_s(students[i].surname, MAX_SIZE, surname);
		strcpy_s(students[i].group, MAX_SIZE, group);

		printf("\n");
	}

	for (int i = 1; i < size; i++)
	{
		Student value = students[i];
		int j = i;
		while (j > 0 && strcmp(value.surname, students[j - 1].surname) < 0)
		{
			students[j] = students[j - 1];
			j--;
		}
		students[j] = value;
	}

	printf("Sorted array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("Student %d: %s, %s\n", i + 1, students[i].surname, students[i].group);
	}
	printf("\n");

	char group[MAX_SIZE];
	printf("Enter group: ");
	gets_s(group, MAX_SIZE);

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(students[i].group, group))
		{
			printf("%s\n", students[i].surname);
		}
	}

	getch();
	return 0;
}