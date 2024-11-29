#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"
#define MAX_NAME 50

typedef struct
{
    int id;
    char name[MAX_NAME];
    int age;
} User;

void create_user();
void read_users();
void update_user();
void delete_user();
void initialize_file();

int main() 
{
    int choice;
    initialize_file();

    do 
    {
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                create_user();
                break;
            case 2:
                read_users();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initialize_file() 
{
    FILE *file = fopen(FILENAME, "a");
    if (!file) 
    {
        printf("Unable to initialize the file.\n");
        exit(1);
    }
    fclose(file);
}

void create_user() 
{
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Unable to open file.\n");
        return;
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
    printf("User added successfully.\n");
}

void read_users() 
{
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Unable to open file.\n");
        return;
    }

    User user;
    printf("\nUser List\n");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

void update_user() 
{
    FILE *file = fopen(FILENAME, "r");
    if (!file) 
    {
        printf("Unable to open file.\n");
        return;
    }

    int target_id, found = 0;
    User user;
    printf("Enter User ID to update: ");
    scanf("%d", &target_id);

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) 
    {
        printf("Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) 
    {
        if (user.id == target_id) 
        {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    if (found) 
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User updated successfully.\n");
    } 
    else 
    {
        remove("temp.txt");
        printf("User with ID %d not found.\n", target_id);
    }
}

void delete_user() 
{
    FILE *file = fopen(FILENAME, "r");
    if (!file) 
    {
        printf("Unable to open file.\n");
        return;
    }

    int target_id, found = 0;
    User user;
    printf("Enter User ID to delete: ");
    scanf("%d", &target_id);

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) 
    {
        printf("Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) == 3) 
    {
        if (user.id != target_id) 
        {
            fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (found) 
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User deleted successfully.\n");
    } 
    else 
    {
        remove("temp.txt");
        printf("User with ID %d not found.\n", target_id);
    }
}
