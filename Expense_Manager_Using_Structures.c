#include <stdio.h>
#define MAX 50 // maximum items entry

// structure definition
typedef struct item_details {
    char itemName[30]; // item name
    int quantity; // item quantity
    float price; // per item price
    float totalAmount; // total amount = quantity * price
} item;

int main() {
    item thing[MAX]; // structure variable
    int i, choice;
    int count = 0;
    float expenses = 0.0f;

    i = 0;
    // infinite loop
    do {
        printf("Enter item details [%2d]:\n", i + 1);
        printf("Item? ");
        fgets(thing[i].itemName, sizeof(thing[i].itemName), stdin);
        printf("Price? ");
        scanf("%f", &thing[i].price);
        printf("Quantity? ");
        scanf("%d", &thing[i].quantity);
        getchar(); // consume the newline character
        thing[i].totalAmount = (float)thing[i].quantity * thing[i].price;
        expenses += thing[i].totalAmount;
        i++; // increase loop counter
        count++; // increase record counter
        printf("\nWant more items? Press 1 to continue: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character
    } while (choice == 1);

    // print all items
    printf("\nAll details are:\n");
    for (i = 0; i < count; i++) {
        printf("%-30s\t%.2f\t%3d\t%.2f\n", thing[i].itemName, thing[i].price, thing[i].quantity, thing[i].totalAmount);
    }

    printf("\n#### Total expense: %.2f\n", expenses);
    printf("Do you want to divide among friends? Press 1 for yes: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int numFriends;
        printf("How many friends? ");
        scanf("%d", &numFriends);
        printf("Each friend will have to pay: %.2f\n", (expenses / (float)numFriends));
    }

    printf("\n~Thanks for using me... Enjoy your party!!!~\n");
    return 0;
}
