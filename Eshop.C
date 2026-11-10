
#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
};

struct Product clothes[] = {
    {1, "T-Shirt", 499},
    {2, "Jeans", 999},
    {3, "Jacket", 1499},
    {4, "Shirt", 799}
};

struct Product groceries[] = {
    {1, "Rice (1kg)", 60},
    {2, "Milk (1L)", 60},
    {3, "Sugar (1kg)", 45},
    {4, "Cooking Oil (1L)", 140}
};

struct Product stationery[] = {
    {1, "Notebook", 50},
    {2, "Pen", 10},
    {3, "Pencil", 5},
    {4, "School Bag", 599}
};

float total = 0;

void display(struct Product p[], int size) {
    int i;

    printf("\n--------------------------------\n");
    printf(" ID\tPRODUCT\t\tPRICE\n");
    printf("--------------------------------\n");

    for (i = 0; i < size; i++) {
        printf(" %d\t%-15s Rs. %.2f\n",
               p[i].id, p[i].name, p[i].price);
    }
}

void shop(struct Product p[], int size) {
    int id, quantity;

    display(p, size);

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    if (id < 1 || id > size) {
        printf("Invalid Product ID!\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("Invalid Quantity!\n");
        return;
    }

    float amount = p[id - 1].price * quantity;
    total += amount;

    printf("\nProduct Added Successfully!\n");
    printf("Product: %s\n", p[id - 1].name);
    printf("Quantity: %d\n", quantity);
    printf("Amount: Rs. %.2f\n", amount);
}

int main() {
    int choice;

    printf("====================================\n");
    printf("       WELCOME TO ONLINE E-SHOP     \n");
    printf("====================================\n");

    do {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Clothes\n");
        printf("2. Groceries\n");
        printf("3. Stationery\n");
        printf("4. View Total Bill\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                shop(clothes, 4);
                break;

            case 2:
                shop(groceries, 4);
                break;

            case 3:
                shop(stationery, 4);
                break;

            case 4:
                printf("\n========== YOUR BILL ==========\n");
                printf("Total Amount: Rs. %.2f\n", total);
                printf("===============================\n");
                break;

            case 5:
                printf("\nThank you for shopping with us!\n");
                printf("Your final bill is Rs. %.2f\n", total);
                printf("Visit Again!\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
