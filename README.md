# LAR Inventory Manager

A C-based inventory and order management system designed for L.A.R. Farmers Export Limited, a sea moss company based in Jamaica. Developed by Daisy Kremer and Gabrielle Numa for their CAPE Computer Science Internal Assessment 2025.

## 🚀 Features
- Customer management with ID, address, and contact info
- Product catalog and stock management
- Order creation with automatic stock updates
- Low stock notifications
- Invoice total calculations
- Basic user authentication
- Activity logging to `system_log.txt`

## 📂 File Structure
- `main.c` - C source code
- `customers.txt` - Stores customer records
- `products.txt` - Stores product information
- `orders.txt` - Stores order transactions
- `users.txt` - Login credentials
- `system_log.txt` - Log of system events

## 🖥️ How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/daisykremer876/LAR-Inventory-Manager.git
   ```
2. Compile using a C compiler:
   ```bash
   gcc main.c -o lar_inventory_manager
   ./lar_inventory_manager
   ```
3. Use the menu interface to:
   - Add customers or products
   - Record and retrieve orders
   - Update stock or user accounts
   - Search for product details

## 📌 Status
The system is complete and functionally tested but not yet deployed in the business.

## 👩🏽‍💻 Authors
- **Daisy Kremer**
- **Gabrielle Numa**

## 🔗 GitHub Repository
[https://github.com/daisykremer876/LAR-Inventory-Manager](https://github.com/daisykremer876/LAR-Inventory-Manager)