#include <stdio.h>

#define ITEMS 6

typedef struct {
    const char *name;
    int price;
} MenuItem;

void printMenu(const MenuItem menu[]) {
    printf("\n========== CAMPUS CANTEEN ==========\n");
    for (int i = 0; i < ITEMS; i++)
        printf("%d. %-18s Rs.%d\n", i + 1, menu[i].name, menu[i].price);
    printf("0. Finish order\n");
}

int readInteger(const char *prompt) {
    int value;
    int ch;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            return value;
        }
        printf("Invalid input. Enter a number.\n");
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        if (ch == EOF) return 0;
    }
}

void takeOrder(const MenuItem menu[]) {
    int quantities[ITEMS] = {0};
    int choice, quantity;
    long subtotal = 0;

    while (1) {
        printMenu(menu);
        choice = readInteger("Choose item (0 to bill): ");
        if (choice == 0) break;
        if (choice < 1 || choice > ITEMS) {
            printf("Please select an item from 1 to %d.\n", ITEMS);
            continue;
        }
        quantity = readInteger("Enter quantity (1-100): ");
        if (quantity < 1 || quantity > 100 || quantities[choice - 1] > 1000 - quantity) {
            printf("Invalid quantity or item quantity limit reached.\n");
            continue;
        }
        quantities[choice - 1] += quantity;
        printf("Added %d x %s.\n", quantity, menu[choice - 1].name);
    }

    printf("\n=============== RECEIPT ===============\n");
    printf("%-18s %5s %9s\n", "Item", "Qty", "Amount");
    for (int i = 0; i < ITEMS; i++) {
        if (quantities[i] > 0) {
            long amount = (long) quantities[i] * menu[i].price;
            subtotal += amount;
            printf("%-18s %5d Rs.%6ld\n", menu[i].name, quantities[i], amount);
        }
    }
    if (subtotal == 0) {
        printf("No items ordered.\n");
        return;
    }
    long discount = subtotal >= 200 ? subtotal / 10 : 0;
    printf("---------------------------------------\n");
    printf("Subtotal: Rs.%ld\n", subtotal);
    printf("Discount: Rs.%ld\n", discount);
    printf("TOTAL:    Rs.%ld\n", subtotal - discount);
    printf("Thank you! Visit again.\n");
}

int main(void) {
    const MenuItem menu[ITEMS] = {
        {"Samosa", 20}, {"Tea", 15}, {"Sandwich", 50},
        {"Burger", 70}, {"Noodles", 60}, {"Coffee", 30}
    };
    int again;
    printf("Welcome to Smart Canteen Billing System!\n");
    do {
        takeOrder(menu);
        again = readInteger("\nNext customer? (1 = Yes, 0 = No): ");
    } while (again == 1);
    printf("Canteen closed. Goodbye!\n");
    return 0;
}
