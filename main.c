#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CUSTOMERS 25
#define MAX_PRODUCTS 10
#define MAX_USERS 5
#define MAX_ORDERS 100
#define MAX_ORDER_ITEMS 20

struct Customer {
    char c_name[50];
    char c_ID[20];
    char c_address[100];
    char c_phone[13];
};

struct Product {
    char p_name[50];
    char p_description[100];
    int p_stock;
    float p_cost;
};

struct UserRecord {
    char username[50];
    char password[50];
};

struct OrderRecord {
    char c_ID[20];
    char order_ID[20];
    struct Product products[MAX_ORDER_ITEMS];
    int p_quantity[MAX_ORDER_ITEMS];
};

struct Customer c_info[MAX_CUSTOMERS];
struct Product prod_info[MAX_PRODUCTS];
struct UserRecord user_info[MAX_USERS];
struct OrderRecord order_info[MAX_ORDERS];
int customer_count = 0, product_count = 0, user_count = 0;

void loadcustomers() {}
void loadproducts() {}
void loadusers() {}
void savecustomers() {}
void saveproducts() {}
void saveusers() {}
void saveorders(struct OrderRecord order, int num) {}
void savelog(const char *msg) {}
int addcustomer() { return customer_count; }
int addproduct() { return product_count; }
int adduser() { return user_count; }
bool authenticateuser() { return true; }
void createorder() {}
void searchproduct() {}
void updatestock() {}

int main() {
    loadcustomers();
    loadproducts();
    loadusers();
    int choice;
    do {
        printf("\n==== Order Management System ===="
               "\n1. Add Customer"
               "\n2. Add Product"
               "\n3. Update Stock"
               "\n4. Add User"
               "\n5. Create Order"
               "\n6. Search Product"
               "\n7. Exit"
               "\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: customer_count = addcustomer(); savecustomers(); savelog("Added customer"); break;
            case 2: product_count = addproduct(); saveproducts(); savelog("Added product"); break;
            case 3: updatestock(); saveproducts(); savelog("Updated stock"); break;
            case 4: user_count = adduser(); saveusers(); savelog("Added user"); break;
            case 5: createorder(); savelog("Created order"); break;
            case 6: searchproduct(); break;
            case 7: printf("Exiting...\n"); savelog("System exited"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);
    return 0;
}