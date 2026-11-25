# Smart Canteen Billing System

**Team: The DeBurgers | Mini Hackathon | UPES, Dehradun**

A console-based canteen billing application developed in C by first-year B.Tech Computer Science and Engineering students. The project automates food ordering, bill calculation, discounts and receipt generation.

**Project status:** Completed

## Objective

To simplify campus canteen billing while applying foundational C programming concepts to a practical problem.

## Features

- Interactive menu with six food and beverage options.
- Multiple items per order with automatic quantity aggregation.
- Input validation for menu choices and quantities.
- Automatic subtotal and final bill calculation.
- 10% discount on orders of Rs. 200 or more, calculated in whole rupees.
- Itemized receipts with quantities and prices.
- Support for consecutive customers without restarting the program.
- Handling of empty orders.

## Menu

| Item | Price (INR) |
| --- | ---: |
| Samosa | 20 |
| Tea | 15 |
| Sandwich | 50 |
| Burger | 70 |
| Noodles | 60 |
| Coffee | 30 |

## Technologies and concepts

- C programming language and standard I/O library
- Structures, arrays and pointers
- Functions and modular programming
- Loops, conditionals and input validation
- GCC compiler

## Getting started

Clone the repository:

```bash
git clone https://github.com/Wood-stack1/Smart-canteen-billing.git
cd Smart-canteen-billing
```

Compile:

```bash
gcc -std=c11 -Wall -Wextra smart_canteen.c -o smart_canteen
```

Run on Linux or macOS:

```bash
./smart_canteen
```

On Windows, compile with `gcc smart_canteen.c -o smart_canteen.exe` and run `.\smart_canteen.exe` in PowerShell.

## How it works

1. Select a menu item by its number.
2. Enter a quantity between 1 and 100.
3. Repeat to add more items (up to 1,000 units per item per order).
4. Enter 0 to finish the order and generate a receipt.
5. Enter 1 to serve another customer or 0 to exit.

## Sample output

Example: three burgers at Rs. 70 each.

```text
=============== RECEIPT ===============
Item                 Qty    Amount
Burger                 3 Rs.   210
---------------------------------------
Subtotal: Rs.210
Discount: Rs.21
TOTAL:    Rs.189
Thank you! Visit again.
```

## Program structure

| Function | Purpose |
| --- | --- |
| `printMenu()` | Displays available items and prices |
| `readInteger()` | Reads integer input and handles non-numeric input |
| `takeOrder()` | Processes orders, calculates discounts and prints receipts |
| `main()` | Initializes the menu and manages consecutive customers |

## Team — The DeBurgers

| Member | Contribution |
| --- | --- |
| Saksham Mittal | Coding and development |
| Rakshita Manchanda | Testing |
| Ekansh Shekhar Singh | Presentation and documentation |

## Academic details

- **Institution:** UPES, Dehradun
- **Programme:** B.Tech Computer Science and Engineering
- **Year:** First Year
- **Event:** Mini Hackathon
- **Faculty mentor:** Ambika Agarwal

## Future scope

Potential enhancements include inventory management, persistent sales records, digital payment integration, configurable menus and a graphical interface. These are proposed improvements, not current features.

## Acknowledgements

We thank our faculty mentor, Ambika Agarwal, for her guidance and UPES for the opportunity to develop this project as part of the Mini Hackathon.
