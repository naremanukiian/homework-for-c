#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int id;
    float grade;
} Student;

void add_student(Student **students, int *num_students);
void remove_student(Student **students, int *num_students, int id);
void search_student(Student *students, int num_students, int id);
void display_students(Student *students, int num_students);
void calculate_average_grade(Student *students, int num_students);
void save_to_file(Student *students, int num_students);
void read_from_file(Student **students, int *num_students);
void free_memory(Student *students);

int main() {
    Student *students = NULL;
    int num_students = 0;
    int choice;
    int id;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add a new student\n");
        printf("2. Remove a student by ID\n");
        printf("3. Search a student by ID\n");
        printf("4. Display all student details\n");
        printf("5. Display average grade\n");
        printf("6. Save student details to file\n");
        printf("7. Read student details from file\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(&students, &num_students);
                break;
            case 2:
                printf("Enter student ID to remove: ");
                scanf("%d", &id);
                remove_student(&students, &num_students, id);
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                search_student(students, num_students, id);
                break;
            case 4:
                display_students(students, num_students);
                break;
            case 5:
                calculate_average_grade(students, num_students);
                break;
            case 6:
                save_to_file(students, num_students);
                break;
            case 7:
                read_from_file(&students, &num_students);
                break;
            case 8:
                free_memory(students);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void add_student(Student **students, int *num_students) {
    *students = realloc(*students, (*num_students + 1) * sizeof(Student));
    if (*students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter student's name: ");
    scanf("%s", (*students)[*num_students].name);
    printf("Enter student's surname: ");
    scanf("%s", (*students)[*num_students].surname);
    printf("Enter student's ID: ");
    scanf("%d", &(*students)[*num_students].id);
    printf("Enter student's grade: ");
    scanf("%f", &(*students)[*num_students].grade);

    (*num_students)++;
}

void remove_student(Student **students, int *num_students, int id) {
    int i, index = -1;

    for (i = 0; i < *num_students; i++) {
        if ((*students)[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    for (i = index; i < *num_students - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }


    *students = realloc(*students, (*num_students - 1) * sizeof(Student));
    (*num_students)--;
    printf("Student with ID %d removed.\n", id);
}

void search_student(Student *students, int num_students, int id) {
    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("Student Found: %s %s, ID: %d, Grade: %.2f\n", students[i].name, students[i].surname, students[i].id, students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void display_students(Student *students, int num_students) {
    if (num_students == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nAll Student Details:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Surname: %s, ID: %d, Grade: %.2f\n", students[i].name, students[i].surname, students[i].id, students[i].grade);
    }
}

void calculate_average_grade(Student *students, int num_students) {
    if (num_students == 0) {
        printf("No students to calculate average grade.\n");
        return;
    }

    float total_grade = 0;
    for (int i = 0; i < num_students; i++) {
        total_grade += students[i].grade;
    }

    printf("Average grade: %.2f\n", total_grade / num_students);
}

void save_to_file(Student *students, int num_students) {
    FILE *file = fopen("group_details.csv", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s,%s,%d,%.2f\n", students[i].name, students[i].surname, students[i].id, students[i].grade);
    }

    fclose(file);
    printf("Student details saved to group_details.csv\n");
}

void read_from_file(Student **students, int *num_students) {
    FILE *file = fopen("group_details.csv", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (!feof(file)) {
        *students = realloc(*students, (*num_students + 1) * sizeof(Student));
        if (*students == NULL) {
            printf("Memory allocation failed!\n");
            fclose(file);
            exit(1);
        }

        fscanf(file, "%49[^,],%49[^,],%d,%f\n", (*students)[*num_students].name, (*students)[*num_students].surname, &(*students)[*num_students].id, &(*students)[*num_students].grade);
        (*num_students)++;
    }

    fclose(file);
    printf("Student details read from group_details.csv\n");
}

void free_memory(Student *students) {
    free(students);
}
