#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

struct Voter
{
    int voterId;
    char fName[30];
    char lName[30];
    char street[30];
    char city[30];
    char phone[30];
    bool hasVoted;
};

struct Admin {
    char fName[30];
    char lName[30];
    char userName[30];
    char password[30];
};

void printVoters(struct Voter voters[], int numElements);

const char* randomPasswordGenerator(int n);

void adminLogin(char currentUser[], char currentUserPassword[], struct Admin admin1);

void voterSearch(struct Voter voters[], int numElements );

char password[20];

int main() {
//    Create Polling Station Data
    struct Admin admin1 = {"Jessica", "James", "jjames", "password"};

    struct Voter voter1 = {123456,"Mary", "Johnson", "12 Perry Street", "Halifax", "902-555-5555", false};
    struct Voter voter2 = {235678,"Frank", "White", "79 Pleasant Street", "Dartmouth", "902-647-4675", false};
    struct Voter voter3 = {564738,"Tim", "Black", "3A Willow Lane", "Halifax", "902-890-7465", false};
    struct Voter voter4 = {759384,"Mike", "Tompkins", "1101 Portland Street", "Dartmouth", "902-555-1234", false};
    struct Voter voter5 = {899374,"John", "Blank", "45 Robie Street", "Halifax", "902-888-3455", false};
//Add Voter Structs To a Voters Array
    struct Voter voters[] = {voter1, voter2, voter3, voter4, voter5};

    char currentUser[30];
    char currentUserPassword[30];
    int option;
    bool isRunning = true;
//Run Admin Login Function
    adminLogin(currentUser, currentUserPassword, admin1);
    do {
        printf("Please choose an option:\n\n");
        printf("1. Search for existing voter\n");
        printf("2. Edit existing voter information\n");
        printf("3. Add voter\n");
        printf("4. Print voter infromation\n");
        printf("5. Print full voter list\n\n");
        printf("Enter value (1-5):\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                voterSearch(voters, 5);
                break;
            case 5:
                printVoters(voters, sizeof(voters) / sizeof(voters[0]));
                break;
        }
    } while(isRunning);


//    printf("%s", randomPasswordGenerator(6));

    return 0;
}

void printVoters(struct Voter voters[], int numElements) {
    printf("ID        First Name     Last Name     Street                    City               Phone              Has Voted\n\n");

    for (int i = 0; i < numElements; i++) {
        printf("%-10d", voters[i].voterId);
        printf("%-14s %-15s", voters[i].fName, voters[i].lName);
        printf("%-25s", voters[i].street);
        printf("%-19s", voters[i].city);
        printf("%-19s", voters[i].phone);
        printf("%s\n", voters[i].hasVoted ? "Yes" : "No");
    }
}

const char* randomPasswordGenerator(int n) {
    int i;
    int randomizer;

//  initialize password characters
    srand((unsigned int) (time(NULL)));

    char numbers[] = "1234567890";
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uCaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbols[] = "!@#$%^&*()-_=+?<>,.;:'";
    randomizer = rand() % 4;
    char *p = password;

    for(i=0; i<n; i++) {
        if(randomizer == 1 ) {
            p[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
        }
        else if(randomizer == 2) {
            p[i] = letters[rand() % 26];
            randomizer = rand() % 4;
        }
        else if(randomizer == 3) {
            p[i] = uCaseLetters[rand() % 26];
            randomizer = rand() % 4;
        }
        else {
            p[i] = symbols[rand() % 22];
            randomizer = rand() % 4;
        }
    }
    return p;
}

void adminLogin(char currentUser[], char currentUserPassword[], struct Admin admin1) {
    bool isRunning = true;

    do {
        printf("Please enter your username and password:\nUsername:\n");
        fgets(currentUser, 30, stdin);
        currentUser [ strcspn(currentUser, "\r\n")] = '\0';
        printf("Password:\n");
        fgets(currentUserPassword, 30, stdin);
        currentUserPassword [ strcspn(currentUserPassword, "\r\n")] = '\0';

        if (strcmp(currentUser, admin1.userName) == 0 && strcmp(currentUserPassword, admin1.password) == 0) {
            printf("Welcome %s %s\n", admin1.fName, admin1.lName);
            isRunning= false;
        } else {
            printf("Please try again.\n");
        }
    } while(isRunning);
}

void voterSearch(struct Voter voters[], int numElements) {
    char vFName[30];
    char vLName[30];
    bool isRunning = true;
    int option;
    do {
        printf("Enter voter first name:\n");
        scanf("%s", &vFName);
        printf("Enter voter last name:\n");
        scanf("%w", &vLName);

        for (int i = 0; i < numElements; i++) {
            if (strcmp(&voters[i].fName, vFName) == 0) {
                printf("ID        First Name     Last Name     Street                    City               Phone              Has Voted\n\n");
                printf("%-10d%-14s%-15s%-25s%-19s%-19s%s\n", voters[i].voterId, voters[i].fName, voters[i].lName,
                       voters[i].street, voters[i].city, voters[i].phone, voters[i].hasVoted ? "Yes" : "No");
            }
        }
        printf("Voter not found\n");
        printf("Please choose:\n");
        printf("1. Enter another voter\n");
        printf("2. Exit to main menu\n");
        fflush(stdin);
        scanf(" %d", &option);
        if(option == 2) isRunning = false;
    } while(isRunning);
}
