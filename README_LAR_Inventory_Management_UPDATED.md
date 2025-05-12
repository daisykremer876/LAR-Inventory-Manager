# Inventory and Order Management System for L.A.R. Farmers Export Ltd

## 🌱 About the Project

### Definition of Problem

#### BACKGROUND
L.A.R. Farmers Export Limited is a sea moss business located at Old Harbour (Mobile Business), St. Catherine, Jamaica, owned by Lowenzo Robinson. Established in 2020, the organization was created to meet the growing demand for high-quality sea moss products in both local and international markets. Lowenzo Robinson, with a deep passion for sustainable agriculture, recognized the potential of sea moss as a natural source of nutrition and wellness, which led to the founding of this enterprise. The business not only aims to provide customers with premium sea moss but also plays a significant role in supporting local farmers and promoting sustainable practices. This commitment to the community has contributed to the economic development and well-being of the region, making L.A.R. Farmers Export Limited an essential part of the local agricultural landscape.

#### PROBLEM CONTEXT
At L.A.R. Farmers Export Limited, the day-to-day operations revolve around the efficient management of customer orders and product delivery. Customer orders are placed via phone. The sales representative writes the order details down. Then invoices or receipts are handwritten for customer confirmation. 

The reliance on paper documentation extends to inventory management, creating a system that is entirely paper based. While this operational flow supports a traditional approach to customer service, it also presents challenges in terms of efficiency and organization. Each piece of paper must be carefully managed to avoid errors and ensure accurate record-keeping, which can be time-consuming for the staff. 

#### PROBLEM DESCRIPTION
The current paper-based system at L.A.R. Farmers Export Limited presents several challenges that can be addressed through programming and automation. Here are the key issues identified:

**1. Order Processing**
- Orders are taken over the phone and handwritten on paper, which increases the risk of inaccuracies due to human error and illegibility.
- The process is time-consuming, especially when multiple items or changes need to be recorded.
- If an employee is not available to take an order, customers may have to wait or repeat their order details, causing delays.
- The system lacks automation for confirming orders or generating invoices, resulting in delays in processing and order completion.

**2. Inventory Management**
- Stock levels are manually recorded and are prone to errors, which can lead to discrepancies between actual stock and recorded inventory that may not be detected immediately, leading to inventory shortage or overstock situations.
- This may result in missed sales opportunities and delays in order fulfilment. 

**3. Invoice and Fee Calculation**
- The user must manually calculate the total cost of each order, leading to incorrect billing and customer dissatisfaction, as well as additional delays.
- Invoices are handwritten and may not clearly break down the details of the products and charges, leading to potential confusion for customers.

**4. Customer History and Reporting**
- Customer interactions and past orders are recorded on paper, which makes it difficult to track purchase histories accurately as it requires the employee to sift through paper records, which is time-consuming and prone to errors.
- Generating reports for sales analysis or inventory assessment is not automated and requires the employee to manually compile information from paper records, reducing the efficiency of performance analyses.

### Identification of Specification

#### FUNCTIONAL REQUIREMENTS
- The system must allow the employee to record customer orders, including customer name, contact information, products ordered, quantities, and order status.
- Orders should be stored in a file and must be retrievable for viewing.
- The system must store customer information (name, contact details) in a file and include order history. The customer file should facilitate the addition of new customers and retrieval of customer information.
- The system must track inventory levels, adjusting stock counts after each order is processed and notifying the user of low stock once the inventory reaches a predefined level.
- The system must allow employees to search for products by name or to check details.
- The system must include user authentication, requiring employees to log in before accessing the system. User credentials should be stored securely in a file.
- The system must allow the addition of new users with unique login credentials.
- The system must allow the employee to update product stock availability.

#### NON-FUNCTIONAL REQUIREMENTS
- The system must have a simple, menu-driven interface that allows the user to perform key tasks (e.g., order entry, invoice generation) without extensive training and display clear instructions for each task.
- The system should be able to handle 20 orders in a single session without noticeable delays (i.e., longer than 5 seconds per order processing time).
- The system must provide clear error messages to the user in case of input errors (e.g., invalid data entry or missing fields).
- The system must maintain a log file that records all critical system events, including user login attempts, data updates, and any errors encountered during operation.

## 🛠️ How It Works
The system runs in the command line and stores all data in plaintext files (`customers.txt`, `orders.txt`, `products.txt`, `users.txt`, etc.). It uses structs and arrays for record management and enforces login-based access to sensitive operations. The menu-driven interface makes it intuitive even for users without prior software experience.

## 💡 Human Impact
This project was a mission rooted in our belief in the power of code to uplift small businesses and underserved communities. As young high school students from the Caribbean, we have seen how a lack of digital tools can constrain local enterprises. By working with L.A.R. Farmers Export Ltd, we recognized the opportunity to bridge that gap. This system not only improves efficiency for the business but also demonstrates how students like us can contribute to grassroots economic development with practical, sustainable technology.
The solution directly addresses inefficiencies faced by a growing Jamaican small business. Our collaboration with L.A.R. Farmers Export Ltd represents the kind of grassroots innovation we believe in — where local students build tech for local needs.

## 📁 Source Code
```c
/* C code block omitted for brevity in this Markdown export */
```

## ✅ Key Features
- Lightweight, file-based storage
- Full modular functions for add/update/search
- User login authentication
- Console-friendly UI

## 🔒 Future Improvements
We plan to:
- Expand array limits and add dynamic memory
- Improve input validation
- Add reporting features (e.g., sales summaries)
- Transition to a GUI and database back-end

## 👩🏽‍💻 Authors
- Daisy Kremer (@daisykremer)
- Gabrielle Numa

---
For questions or collaborations, reach out via GitHub or email.
