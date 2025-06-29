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

// Definition of structures for Customer, Product, UserRecord, and OrderRecord:

// Customer: Stores information about customers
struct Customer {
    char c_name[50];
    char c_ID[20];
    char c_address[100];
    char c_phone[13];
};

// Product: Stores information about products in the inventory
struct Product {
    char p_name[50];
    char p_description[100];
    int p_stock;
    float p_cost;
};

// UserRecord: Stores information about system users (username and password)
struct UserRecord {
    char username[50];
    char password[50];
};

// OrderRecord: Stores details of customer orders, including products and quantities
struct OrderRecord {
    char c_ID[20];
    char order_ID[20];
    struct Product products[20]; // assuming a maximum of 20 products to be bought
    int p_quantity[20];
};

// Declaration of arrays to hold customer, product, user, and order information
struct Customer c_info[25];
struct Product prod_info[10];
struct UserRecord user_info[5];
struct OrderRecord order_info[100];

// Global counters for array indices
int i = 0, x = 0, y = 0; // i = number of customers, x = number of products, y = number of users

// Function declarations for all actions in the program
void loadcustomers();
void loadproducts();
void updatestock ();
void loadusers();
void savecustomers();
void saveproducts();
void saveusers();
void saveorders(struct OrderRecord order, int num);
void savelog(const char *log_message);
int addcustomer(int i);
int addproduct(int x);
int adduser(int y);
bool authenticateuser();
void createorder();
void searchproduct();

// Function to load customer data from the file into the customer array
void loadcustomers() {
    FILE *file = fopen("customers.txt", "r+");
    if (file == NULL) {
        printf ("Error opening file!\n");
        return;
    }
    i = 0;
    while (fscanf(file, "%49[^,], %19[^,], %99[^,], %14[^\n]\n", c_info[i].c_name, c_info[i].c_ID, c_info[i].c_address, c_info[i].c_phone) != EOF) {
        i++;
    }
    fclose(file);
}

// Function to load product data from the file into the product array
void loadproducts() {
    FILE *file = fopen("products.txt", "r+");
    if (file == NULL) {
        printf ("Error opening file!\n");
        return;
    }
    x = 0;
    while (fscanf(file, "%49[^,], %99[^,], %d, %f\n", prod_info[x].p_name, prod_info[x].p_description, &prod_info[x].p_stock, &prod_info[x].p_cost) != EOF) {
        x++;
    }
    fclose(file);
}

// Function to update the stock of a product
void updatestock () {
    int stockadd;
    char updatedprod[50];
    printf ("Which product stock would you like to update?: ");
    scanf("%49s", updatedprod);

    for (int i = 0; i < x; i++) {
        if (strcmp(prod_info[i].p_name, updatedprod) == 0){
            printf ("How much is being added to the stock? ");
            scanf("%d", &stockadd);
            prod_info[i].p_stock += stockadd;
            printf("Stock updated successfully! New stock: %d\n", prod_info[i].p_stock);
            return;
        }
    }
    printf("Product not found!\n");
}

// Function to load user data from the file into the user array
void loadusers() {
    FILE *file = fopen("users.txt", "r+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    y = 0;
    while (fscanf(file, "%49[^,], %49[^\n]\n", user_info[y].username, user_info[y].password) != EOF) {
        y++; // Increment the user index
    }
    fclose(file);
}

// Function to save customer data back to the file
void savecustomers() {
    FILE *file = fopen("customers.txt", "w");
    if (file == NULL) {
        printf("Error saving customers to file!\n");
        return;
    }
    for (int j = 0; j < i; j++) {
        fprintf(file, "%s, %s, %s, %s\n", c_info[j].c_name, c_info[j].c_ID, c_info[j].c_address, c_info[j].c_phone);
    }
    fclose(file);
}

// Function to save product data back to the file
void saveproducts() {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error saving products to file!\n");
        return;
    }
    for (int j = 0; j < x; j++) {
        fprintf(file, "%s, %s, %d, %.2f\n", prod_info[j].p_name, prod_info[j].p_description, prod_info[j].p_stock, prod_info[j].p_cost);
    }
    fclose(file);
}

// Function to save user data back to the file
void saveusers() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error saving users to file!\n");
        return;
    }
    for (int j = 0; j < y; j++) {
        fprintf(file, "%s, %s\n", user_info[j].username, user_info[j].password);
    }
    fclose(file);
}

// Function to save order data back to the file
void saveorders(struct OrderRecord order, int num) {
    FILE *file = fopen("orders.txt", "w");
    if (file == NULL) {
        printf("Error saving orders to file!\n");
        return;
    }
    for (int j = 0; j < num; j++) {
        if (strlen(order.products[j].p_name) > 0) { // makes sure it only adds orders in the array that have been entered instead of empty slots
            fprintf(file, "%s, %s, %s, %d\n", order.c_ID, order.order_ID, order.products[j].p_name, order.p_quantity[j]);
        }
    }
    fclose(file);
}

// Function to save a log message to a system log file
void savelog(const char *log_message) {
    FILE *file = fopen("system_log.txt", "a");
    if (file == NULL) {
        printf ("Error opening file!");
        return;
    }
    fprintf(file, "%s\n", log_message);
    fclose(file);
}

// Function to search for a product in the inventory by name
void searchproduct() {
    char search_name[50];
    bool found = false;
    printf("Enter product name to search (use _ for spaces): ");
    scanf("%49s", search_name);
    for (int i = 0; i < x; i++) {
        if (strcmp(prod_info[i].p_name, search_name) == 0) { // Compares the entered string with all product names to see if any match
            found = true;
            printf("Product found!\n");
            printf("Name: %s\n", prod_info[i].p_name);
            printf("Description: %s\n", prod_info[i].p_description);
            printf("Stock: %d\n", prod_info[i].p_stock);
            printf("Cost: $%.2f\n", prod_info[i].p_cost);
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

// Function to add a new customer to the system
int addcustomer(int i) {
    if (i >= 25) {
        printf("Maximum number of customers reached.\n");
        return i;
    }
    printf("Please enter the customer's name (use _ for spaces): ");
    scanf("%49s", c_info[i].c_name);
    printf("Please enter the customer's ID: ");
    scanf("%19s", c_info[i].c_ID);
    printf("Please enter the customer's address (use _ for spaces): ");
    scanf("%99s", c_info[i].c_address);
    printf("Please enter the customer's phone number [(888)8888888]: ");
    scanf("%13s", c_info[i].c_phone);
    printf("\n");
    i++; // Increment the customer index after adding
    return i;
}

// Function to add a new product to the system
int addproduct(int x) {
    if (x >= 10) {
        printf("Maximum number of products reached.\n");
        return x;
    }
    printf("Enter product name (use _ for spaces): ");
    scanf("%49s", prod_info[x].p_name);
    printf("Enter product description (use _ for spaces): ");
    scanf("%99s", prod_info[x].p_description);
    printf("Enter product stock amount: ");
    scanf("%d", &prod_info[x].p_stock);
    printf("Enter product cost: ");
    scanf("%f", &prod_info[x].p_cost);
    printf("\n");
    x++; // Increment the product index after adding
    return x;
}

// Function to add a new user to the system
int adduser(int y) {
    if (y >= 5) {
        printf("Maximum number of users reached.\n");
        return y;
    }
    printf("Enter username: ");
    scanf("%49s", user_info[y].username);
    printf("Enter password: ");
    scanf("%49s", user_info[y].password);
    printf("\n");
    y++;
    return y;
}

// Function to authenticate a user based on username and password
bool authenticateuser() {
    char input_username[100];
    char input_password[100];
    bool found = false;
    printf("Enter username for authentication: ");
    scanf("%49s", input_username);
    printf("Enter password for authentication: ");
    scanf("%49s", input_password);
    for (int z = 0; z < 4; z++) {
        if (strcmp(user_info[z].username, input_username) == 0 && strcmp(user_info[z].password, input_password) == 0) {
            //Compares the entered username and password with the all correct usernames and passwords
            found = true;
            printf("Authentication successful.\n\n");
            return true;
        }
    }
    printf("Authentication unsuccessful.\n\n");
    return false;
}

// Function to create a new order, authenticate the user, and update stock
void createorder() {
    struct OrderRecord order;
    int num;
    bool is_authenticated;
    float total_cost = 0.0;

    // Authenticate the user first
    is_authenticated = authenticateuser();
    if (is_authenticated) {
        printf("Enter Customer ID for the order: ");
        scanf("%19s", order.c_ID);
        printf("Enter Order ID: ");
        scanf("%19s", order.order_ID);
        printf("Enter the number of different products being ordered: ");
        scanf("%d", &num);

        // Check if the number of products is within bounds
        if (num > x) {
            printf("Error: Cannot add more than %d products per order.\n", x);
            return;
        }

        bool order_successful = true;

        // Process each product in the order
        for (int j = 0; j < num; j++) {
            printf("Enter product name: ");
            scanf("%49s", order.products[j].p_name);
            printf("Enter product quantity: ");
            scanf("%d", &order.p_quantity[j]);

            bool product_found = false;
            for (int k = 0; k < x; k++) {
                if (strcmp(prod_info[k].p_name, order.products[j].p_name) == 0) {
                    product_found = true;

                    if (prod_info[k].p_stock >= order.p_quantity[j]) {
                        // Reduce stock and check for low stock
                        prod_info[k].p_stock -= order.p_quantity[j];

                        // Calculate total cost for this product
                        float product_total = prod_info[k].p_cost * order.p_quantity[j];
                        total_cost += product_total; // Add to the total order cost
                        if (prod_info[k].p_stock < 5) {
                            printf("WARNING: Low stock for %s! Only %d left. Consider restocking.\n", prod_info[k].p_name, prod_info[k].p_stock);
                        }
                    } else {
                        printf("Not enough stock for %s! Order cannot be processed.\n", order.products[j].p_name);
                        order_successful = false; // Mark the order as unsuccessful
                        break; // Exit the loop as order cannot be processed
                    }
                    break; // Exit the product search loop once the product is found
                }
            }

            if (!product_found) {
                printf("Product %s not found in inventory. Order cannot be processed.\n", order.products[j].p_name);
                order_successful = false; // Mark the order as unsuccessful
                break; // Exit the loop as we can't process this order
            }
        }

        // If the order was successfully processed, it is saved and the stock updated
        if (order_successful) {
            saveorders(order, num); // Save the order details to a file
            printf("Order created successfully, and stock updated.\n");
            printf("Total cost of the order: $%.2f\n\n", total_cost); // Display total cost
        } else {
            printf("Order creation failed. Please review the input and try again.\n\n");
        } } else {
        printf("Unable to create order. User not authenticated.\n\n");
    }
}

int main() {

    loadcustomers();
    loadproducts();
    loadusers();

    int choice;

    do {
        printf("\n=======================================\n");
        printf("Welcome to the Order Management System!\n"); // main menu
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
                i = addcustomer(i); // Carries out addcustomer function and assigns the new value of i
                savecustomers();
                savelog("New customer added.");
                break;
            case 2:
                x = addproduct(x); // Carries out addproduct function and assigns the new value of x
                saveproducts();
                savelog("New product added.");
                break;
            case 3:
                updatestock();
                savelog("Stock updated.");
                break;
            case 4:
                y = adduser(y); // Carries out adduser function and assigns the new value of y
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
}
