#include <stdio.h>


// Structure to represent a bank account
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

// Function to create a new account
void createAccount(struct Account accounts[], int *numAccounts) {
    struct Account newAccount;
    printf("\nEnter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    accounts[*numAccounts] = newAccount;
    (*numAccounts)++;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit(struct Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            
           
            printf("Amount deposited successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money from an account
void withdraw(struct Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("New Balance:",accounts[i].balance);
                printf("Amount withdrawn successfully!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to view account balance
void viewBalance(struct Account accounts[], int numAccounts) {
    int accountNumber;
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    struct Account accounts[100];
    int numAccounts = 0;
    int choice;
    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                viewBalance(accounts, numAccounts);
                break;
            case 5:
                printf("Thank you for using Bank Management System!\n");
                break;
            default:
                printf("Error");
                break;
                 }
    } while (choice != 5);

    return 0;
}

