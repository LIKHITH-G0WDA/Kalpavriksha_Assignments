#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

typedef struct
{
    int id;
    char name[50];
    int age;
} User;

void initfile() 
{
    if (fopen(FILENAME, "a")==NULL) 
    {
        printf("can't initialize the file");
        exit(1);
    }
    fclose(fopen(FILENAME, "a"));
}

void create_user() 
{
    FILE *file=fopen(FILENAME, "a");
    if (file==NULL) {
        printf("can't open file");
        exit(1);
    }

    User user;
    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf("%s", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);
    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully\n");
}

void read_users() 
{
    FILE *file=fopen(FILENAME, "r");
    if (file==NULL) {
        printf("can't open file");
        exit(1);
    }
    User user;
    printf("User list\n");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age)==3) {
        printf("ID:%d, Name:%s, Age:%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}


void update_user() 
{
    FILE *file = fopen(FILENAME, "r");
    if (file==NULL) 
    {
        printf("can't open file");
        return;
    }

    int target, exist=0;
    User user;
    printf("Enter User ID to update: ");
    scanf("%d", &target);

    FILE *temp = fopen("tempfile.txt", "w"); 
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) 
    {
        if (user.id==target) 
        {
            exist=1;
            printf("Enter new Name: ");
            scanf("%s", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    if (exist==1) 
    {
        remove("users.txt");
        rename("tempfile.txt", "users.txt");
        printf("User updated successfully\n");
    } 
    else 
    {
        remove("tempfile.txt");
        printf("User with ID %d not found\n", target);
    }
}

void delete_user() 
{
    FILE *file = fopen(FILENAME, "r");
    if (file==NULL) 
    {
        printf("Unable to open file\n");
        return;
    }

    int target, exist=0;
    User user;
    printf("Enter User ID to delete: ");
    scanf("%d", &target);

    FILE *temp = fopen("tempfile.txt", "w");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) 
    {
        if (user.id!=target) 
        {
            fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
        } else {
            exist=1;
        }
    }

    fclose(file);
    fclose(temp);

    if (exist==1) 
    {
        remove("users.txt");
        rename("tempfile.txt", "users.txt");
        printf("User deleted successfully");
    } 
    else 
    {
        remove("tempfile.txt");
        printf("User with ID %d not found\n", target);
    }
}
int main() 
{
    while(1)
    {
    int choice;
    initfile();
    printf("1. Add User\n");
    printf("2. Display User\n");
    printf("3. Update User\n");
    printf("4. Delete User\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:create_user();
            break;
        case 2:read_users();
            break;
        case 3:update_user();
            break;
        case 4:delete_user();
            break;
        case 5:
            printf("Exiting the program");
            exit(0);
        default:
            printf("Invalid choice");
    }
    }
}
