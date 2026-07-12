#include<stdio.h>
#include<stdint.h>

typedef struct
{
    char name[30];
    uint8_t age;
    float gpa;
} Student;

void inputStudent(Student *sv){
    printf("Enter name: ");
    scanf("%s", sv->name);
    printf("Enter age: ");
    scanf("%d", &sv->age);
    printf("Enter GPA: ");
    scanf("%f", &sv->gpa);
}

void printStudent(const Student *sv){
    printf("Name : %s, Age : %d, GPA : %.2f\n", sv->name, sv->age, sv->gpa);
}

float averageGPA(Student list[], uint8_t size){
    float sum = 0;
    for (uint8_t i = 0; i < size; i++){
        sum += list[i].gpa;
    }
    return sum / size;
}

int main()
{
    Student students[3];
    for (uint8_t i = 0; i < 3; i++){
        printf("Enter information for student %d:\n", i + 1);
        inputStudent(&students[i]);
    }

    printf("\nStudent Information:\n");
    for (uint8_t i = 0; i < 3; i++){
        printStudent(&students[i]);
    }

    float avgGPA = averageGPA(students, 3);
    printf("\nAverage GPA: %.2f\n", avgGPA);

    return 0;
}