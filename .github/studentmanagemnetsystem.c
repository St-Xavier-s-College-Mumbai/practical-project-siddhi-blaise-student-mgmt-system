#include <stdio.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int roll_no;
    char name[50];
    float marks;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);
void viewStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void sortStudentsByName(struct Student students[], int count);

int main() {
    struct Student students[100];  // Array to store up to 100 students
    int count = 0;  // Number of students
    int choice;

    do {
        printf("\n*** Student Management System ***\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. View All Students\n");
        printf("5. Search Student by Roll No\n");
        printf("6. Sort Students by Name\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                updateStudent(students, count);
                break;
            case 3:
                deleteStudent(students, &count);
                break;
            case 4:
                viewStudents(students, count);
                break;
            case 5:
                searchStudent(students, count);
                break;
            case 6:
                sortStudentsByName(students, count);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to add a student
void addStudent(struct Student students[], int *count) {
    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll_no);
    printf("Enter name: ");
    scanf(" %[^\n]s", students[*count].name);
    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to update a student's details
void updateStudent(struct Student students[], int count) {
    int roll_no, i, found = 0;
    printf("Enter roll number of student to update: ");
    scanf("%d", &roll_no);
    
    for (i = 0; i < count; i++) {
        if (students[i].roll_no == roll_no) {
            found = 1;
            printf("Enter new name: ");
            scanf(" %[^\n]s", students[i].name);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student details updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found!\n", roll_no);
    }
}

// Function to delete a student
void deleteStudent(struct Student students[], int *count) {
    int roll_no, i, j, found = 0;
    printf("Enter roll number of student to delete: ");
    scanf("%d", &roll_no);
    
    for (i = 0; i < *count; i++) {
        if (students[i].roll_no == roll_no) {
            found = 1;
            // Shift all students after the found student to the left
            for (j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found!\n", roll_no);
    }
}

// Function to view all students
void viewStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display!\n");
    } else {
        printf("\nRoll No\t\tName\t\tMarks\n");
        printf("---------------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t\t%s\t\t%.2f\n", students[i].roll_no, students[i].name, students[i].marks);
        }
    }
}

// Function to search a student by roll number
void searchStudent(struct Student students[], int count) {
    int roll_no, i, found = 0;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_no);
    
    for (i = 0; i < count; i++) {
        if (students[i].roll_no == roll_no) {
            found = 1;
            printf("\nStudent found:\n");
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found!\n", roll_no);
    }
}

// Function to sort students by name
void sortStudentsByName(struct Student students[], int count) {
    struct Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by name successfully!\n");
}
