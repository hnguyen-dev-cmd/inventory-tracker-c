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
void saveToCSV();

int main() {
    int choice;
    char name[100];
    float price, sale;
    char soldChar;
    bool sold;
    
    do{
        printf("\n=== Inventory Tracker ===\n");
        printf("1. Add an item\n");
        printf("2. View all items\n");
        printf("3. Mark an item as sold\n");
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
		break;
            default:
                printf("Invalid option, try again.\n");
        }
    }while(choice != 4);
    
    saveToCSV();
    
    
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
    if (itemCount == 0) {
        printf("📦 No items in inventory.\n");
        return;
    }

    printf("\n%-20s %-15s %-15s %-10s\n", "Item", "Purchase Price", "Sale Price", "Sold");
    printf("---------------------------------------------------------------------\n");
    
    for (int x = 0; x < itemCount; x++) {
        printf("%-20s $%-14.2f $%-14.2f %-10s\n",
               inventory[x].name,
               inventory[x].purchasePrice,
               inventory[x].salePrice,
               inventory[x].isSold ? "Yes" : "No");
    }
}

void markAsSold() {
    if (itemCount == 0) {
        printf("📦 No items in inventory.\n");
        return;
    }

    printf("\nItems:\n");
    for (int x = 0; x < itemCount; x++){
        printf("%d. %-20s Sold: %-3s\n", 
               x + 1, 
               inventory[x].name, 
               inventory[x].isSold ? "Yes" : "No");
    }

    int choice;
    printf("Input which item number to mark as sold: ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear input buffer
    choice--; // Convert to 0-based index

    if (choice < 0 || choice >= itemCount) {
        printf("❌ Invalid selection.\n");
        return;
    }

    inventory[choice].isSold = true;
    printf("✅ Item '%s' marked as sold.\n", inventory[choice].name);
}

void saveToCSV(){
    FILE *file = fopen("inventory.csv", "w");
    if(file == NULL){
        printf("File CSV could not be opened.\n");
        return;
    }
    
    fprintf(file, "Name,Purchase Price,Sale Price,Sold\n");
    
    for(int x = 0; x < itemCount; x++){
        fprintf(file, "%s,%.2f,%.2f,%s\n",
        inventory[x].name,
        inventory[x].purchasePrice,
        inventory[x].salePrice,
        inventory[x].isSold ? "Yes" : "No");
    }
    fclose(file);
}
