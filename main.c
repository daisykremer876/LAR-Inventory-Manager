/*
Names: Gabrielle Numa and Daisy Kremer
Date of Creation: January 10, 2025
Program Description: This program is a basic Order and Inventory Management System
that stores and manages customer, product, user, and order information.
It includes functionality to load and save data to files, add new customers,
and log system activity, supporting efficient data organization and retrieval.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Customer structure
struct Customer {
    char c_name[50];
    char c_ID[20];
    char c_address[100];
    char c_phone[13];
};

// Product structure
struct Product {
    char p_name[50];
    char p_description[100];
    int p_stock;
    float p_cost;
};

// User structure
struct UserRecord {
    char username[50];
    char password[50];
};

// Order structure
struct OrderRecord {
    char c_ID[20];
    char order_ID[20];
    struct Product products[20];
    int p_quantity[20];
};

// Declare arrays
struct Customer c_info[25];
struct Product prod_info[10];
struct UserRecord user_info[5];
struct OrderRecord order_info[100];

// Function declarations
void loadcustomers();
void loadproducts();
void loadusers();
void savecustomers();
void saveproducts();
void saveusers();
void savelog(const char *log_message);
void searchproduct();
int addcustomer(int i);
int addproduct(int x);
int adduser(int y);
bool authenticateuser();
void createorder();
void updatestock();

int main() {
    loadcustomers();
    loadproducts();
    loadusers();
    int choice;

    do {
        printf("\n=======================================\n");
        printf("Welcome to the Order Management System!\n");
        printf("1. Add Customer\n");
        printf("2. Add Product\n");
        printf("3. Update Stock\n");
        printf("4. Add User\n");
        printf("5. Create Order\n");
        printf("6. Search For Product\n");
        printf("7. Exit\n");
        printf("=======================================\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                i = addcustomer(i);
                savecustomers();
                savelog("New customer added.");
                break;
            case 2:
                x = addproduct(x);
                saveproducts();
                savelog("New product added.");
                break;
            case 3:
                updatestock();
                savelog("Stock updated.");
                break;
            case 4:
                y = adduser(y);
                saveusers();
                savelog("New user added.");
                break;
            case 5:
                createorder();
                savelog("New order created.");
                break;
            case 6:
                searchproduct();
                savelog("Product searched.");
                break;
            case 7:
                printf("Exiting the system.\n");
                savelog("System exited.");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    savecustomers();
    saveproducts();
    saveusers();
    return 0;
}
