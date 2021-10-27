#include <stdio.h>

#define MAX_SIZE 101

typedef struct
{
	const char* surname;
	const char* group;
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
		char* surname = calloc(MAX_SIZE, sizeof(char));
		char* group = calloc(MAX_SIZE, sizeof(char));

		printf("Enter student %d:\n", i + 1);

		printf("Enter surname: ");
		gets_s(surname, MAX_SIZE);

		printf("Enter group: ");
		gets_s(group, MAX_SIZE);

		students[i].surname = surname;
		students[i].group = group;

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