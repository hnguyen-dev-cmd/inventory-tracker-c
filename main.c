#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    float purchasePrice;
    float salePrice;
    bool isSold;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem(char name[], float price, float sale, bool sold);
void viewItems();
void markAsSold();

int main() {
    int choice;
    char name[100];
    float price, sale;
    char soldChar;
    bool sold;
    
    while (1) {
        printf("\n=== Inventory Tracker ===\n");
        printf("1. Add item\n");
        printf("2. View all items\n");
        printf("3. Mark item as sold\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                printf("What is the item name? ");
                scanf(" %[^\n]", name);
            
                printf("What is the item purchase price? ");
                scanf("%f", &price);
        
                printf("What is the item sale price? ");
                scanf("%f", &sale);
                
                printf("Is the item sold? (Y/N): ");
                scanf(" %c", &soldChar); // space before %c to skip whitespace
                sold = (soldChar == 'Y' || soldChar == 'y');
                
                addItem(name, price, sale, sold);
                printf("✅ Item added successfully!\n");
                
                break;
            case 2:
                viewItems();
                break;
            case 3:
                markAsSold();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, try again.\n");
        }
    }
    return 0;
}

void addItem(char name[], float price, float sale, bool sold) {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full!\n");
        return;
    }
    
    strcpy(inventory[itemCount].name, name);
    inventory[itemCount].purchasePrice = price;
    inventory[itemCount].salePrice = sale;
    inventory[itemCount].isSold = sold;
    itemCount++;
}

void viewItems() {
    // TODO: Fill in code to view all items
    printf("[viewItems] Function not implemented yet.\n");
}

void markAsSold() {
    // TODO: Fill in code to mark item as sold
    printf("[markAsSold] Function not implemented yet.\n");
}