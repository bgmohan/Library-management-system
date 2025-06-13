#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

void addBook() {
    FILE *fp = fopen("library.dat", "ab");
    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    getchar(); // flush newline
    fgets(b.title, 50, stdin);
    strtok(b.title, "\n");
    printf("Enter Author: ");
    fgets(b.author, 50, stdin);
    strtok(b.author, "\n");
    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    printf("Book added successfully.\n");
}

void displayBooks() {
    FILE *fp = fopen("library.dat", "rb");
    struct Book b;
    printf("\nID\tTitle\t\tAuthor\t\tQty\n");
    printf("---------------------------------------------\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("%d\t%s\t\t%s\t\t%d\n", b.id, b.title, b.author, b.quantity);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Menu:\n1. Add Book\n2. Display Books\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}