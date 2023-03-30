#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"
#include "functions.h"

//Function Declarations
void printVoters(struct Voter voters[], int n);
const char* randomPasswordGenerator(int n);
void systemLogin(struct PollOfficer pollOfficer, char cUser[], char cUserPassword[]);
void adminLogin(char cUser[], char cUserPassword[], struct Admin admins[], int numAdmins);
void voterSearch(struct Voter voters[], int n );
void recordVotes(struct Voter voters[], struct Candidate candidates[], int nVoters, int nCan, char pCode[]);
void printCandidates(struct Candidate candidates[], int numElements);
void editVoterInfo(struct Voter voters[], int numElements);
void addVoter(struct Voter voters[], int numVoters);
void addAdmin(struct Admin admins[], int numAdmins);
void printAdmins(struct Admin admins[], int numAdmins);

char passcode[20];

int main() {

    struct PollOfficer pollOfficer = {"Mike", "Fowler", "mfowler", "password"};

    struct Admin admin1 = {"Jessica", "James", "jjames", "password"};
    struct Admin admin2 = {"Tim", "Murphy", "tmurphy", "password" };

    struct Candidate candidate1 = {1, "Michelle", "Wright", "Liberal", 0};
    struct Candidate candidate2 = {2, "Pete", "Patrick", "Conservative", 0};
    struct Candidate candidate3 = {3, "Sarah", "Grady", "NDP", 0};

    struct Voter voter1 = {1,"Mary", "Johnson", "12 Perry Street", "Halifax", "902-555-5555", false};
    struct Voter voter2 = {2,"Frank", "White", "79 Pleasant Street", "Dartmouth", "902-647-4675", false};
    struct Voter voter3 = {3,"Tim", "Black", "3A Willow Lane", "Halifax", "902-890-7465", false};
    struct Voter voter4 = {4,"Mike", "Tompkins", "1101 Portland Street", "Dartmouth", "902-555-1234", false};
    struct Voter voter5 = {5,"John", "Blank", "45 Robie Street", "Halifax", "902-888-3455", false};
    struct Voter voter6 = {6,"Jill", "Jones", "445 Main Street", "Sackville", "902-454-3423", false};
    struct Voter voter7 = {7,"Matt", "Larson", "28 View Street", "Bedford", "902-899-3344", false};
    struct Voter voter8 = {8,"Lucy", "Anderson", "28 PineStreet", "Halifax", "902-234-3444", false};
    struct Voter voter9 = {9,"Sarah", "Bryant", "28 Tulip Street", "Dartmouth", "902-456-7423", false};
    struct Voter voter10 = {10,"Barb", "Williams", "28 Rose Street", "Halifax", "902-785-3456", false};
    struct Voter voter11 = {11,"Michelle", "Macphee", "28 Maple Street", "Dartmouth", "902-100-9765", false};
    struct Voter voter12 = {12,"Tanya", "Hopkins", "28 Evergreen Street", "Bedford", "902-845-1234", false};
    struct Voter voter13 = {13,"Chris", "Mcdavid", "28 James Street", "Bedford", "902-856-7423", false};
    struct Voter voter14 = {14,"Ted", "Manson", "28 Finley Street", "Halifax", "902-657-9805", false};
    struct Voter voter15 = {15,"Tim", "Park", "28 Portland Street", "Dartmouth", "902-432-9876", false};
    struct Voter voter16 = {16,"Alex", "Marchand", "28 Primrose Street", "Bedford", "902-234-87675", false};
    struct Voter voter17 = {17,"Jordyn", "Harrison", "28 Neptune Street", "Sackville", "902-123-7654", false};
    struct Voter voter18 = {18,"Brian", "Murray", "28 Main Street", "Halifax", "902-256-0956", false};
    struct Voter voter19 = {19,"Dale", "Murphy", "28 Park Street", "Enfield", "902-888-3456", false};
    struct Voter voter20 = {20,"Amy", "Mcneil", "28 Viewpoint Street", "Halifax", "902-895-0945", false};
    struct Voter voter21 = {21,"Daniel", "Lynch", "28 Dartmouth Street", "Halifax", "902-892-0345", false};
    struct Voter voter22 = {22,"Francis", "Barber", "28 Sackville Street", "Bedford", "902-467-2456", false};
    struct Voter voter23 = {23,"Tommy", "Plaskett", "28 Skye Street", "Dartmouth", "902-197-4567", false};
    struct Voter voter24 = {24,"Joel", "Patrick", "28 Tower Street", "Halifax", "902-891-0000", false};
    struct Voter voter25 = {25,"Ellie", "Jones", "28 Marginal Road", "Bedford", "902-834-9567", false};

//Add Voter Structs To a Voters Array
    struct Voter voters[100] = {
            voter1, voter2, voter3, voter4, voter5, voter6, voter7,
            voter8, voter9, voter10, voter11, voter12, voter13, voter14,
            voter15, voter16, voter17, voter18, voter19, voter20, voter21,
            voter22, voter23, voter24, voter25
    };
    struct Candidate candidates[100] = {candidate1, candidate2, candidate3};

    struct Admin admins[100] = {admin1, admin2};

    int numVoters = sizeof(voters)/sizeof(voters[0]);
    int numCandidates = sizeof(candidates)/sizeof(candidates[0]);
    int numAdmins = sizeof(admins)/sizeof(admins[0]);

//System start
    systemLogin(pollOfficer, currentUser, currentUserPassword);
    do {
        printf("Please choose an option:\n\n");
        printf("1. Add Voter\n");
        printf("2. Add admin\n");
        printf("3. Print admin list\n");
        printf("4. Search for existing voter\n");
        printf("5. Edit existing voter information\n");
        printf("6. Print full voter list\n");
        printf("7. Print candidate list\n");
        printf("8. Switch to voter machine mode\n");
        printf("9. Admin Login\n");
        printf("10. Exit Program\n");
        printf("Enter value (1-9):\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addVoter(voters, numVoters);
                break;
            case 2:
                addAdmin(admins, numAdmins);
                break;
            case 3:
                printAdmins(admins, numAdmins);
                break;
            case 4:
                voterSearch(voters, numVoters);
                break;
            case 5:
                editVoterInfo(voters, numVoters);
                break;
            case 6:
                printVoters(voters, numVoters);
                break;
            case 7:
                printCandidates(candidates, numCandidates);
                break;
            case 8:
                recordVotes(voters, candidates, numVoters, numCandidates, passcode);
                break;
            case 9:
                isRunning = false;
            case 10:
                isRunning = false;
        }
    } while(isRunning);
//Run Admin Login Function
    adminLogin(currentUser, currentUserPassword, admins, numAdmins);
    do {
        printf("Please choose an option:\n\n");
        printf("1. Search for existing voter\n");
        printf("2. Edit existing voter information\n");
        printf("3. Print full voter list\n");
        printf("4. Print candidate list\n");
        printf("5. Switch to voter machine mode\n");
        printf("6. Exit Program\n");
        printf("Enter value (1-6):\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                voterSearch(voters, numVoters);
                break;
            case 2:
                editVoterInfo(voters, numVoters);
                break;
            case 4:
                printVoters(voters, numVoters);
                break;
            case 5:
                printCandidates(candidates, numCandidates);
                break;
            case 6:
                recordVotes(voters, candidates, numVoters, numCandidates, passcode);
                break;
            case 7:
                isRunning = false;
        }
    } while(isRunning);

    return 0;
}

//Functions

//Adds a voter to voter list
void addVoter(struct Voter voters[], int numVoters) {
    char vFName[30];
    char vLName[30];
    char vStreet[30];
    char  vCity[30];
    char  vPhone[30];
    struct Voter addedVoter;
    bool isRunning = true;
    do {
        printf("Enter new voters first name:\n");
        scanf("%s", vFName);
        strcpy(addedVoter.fName, vFName);
        printf("Enter new voters last name:\n");
        scanf("%s", vLName);
        strcpy(addedVoter.lName, vLName);
        fflush(stdin);
        printf("Enter new voters street name and number:\n");
        fgets(vStreet, 30, stdin);
        vStreet [ strcspn(vStreet, "\r\n")] = '\0';
        strcpy(addedVoter.street, vStreet);
        printf("Enter new voters city of residence:\n");
        scanf("%s", vCity);
        strcpy(addedVoter.city, vCity);
        printf("Enter new voters phone number:\n");
        scanf("%s", vPhone);
        strcpy(addedVoter.phone, vPhone);
        addedVoter.hasVoted = false;
        for(int i = 0; i<numVoters; i++) {
            if(strcmp(voters[i].fName, "") == 0) {
                addedVoter.voterId = i+1;
                voters[i] = addedVoter;
                break;
            }
        }
        isRunning = false;
    } while(isRunning);
}
//Add admin
void addAdmin(struct Admin admins[], int numAdmins) {
    char aFName[30];
    char aLName[30];
    char aUserName[30];
    char  aPassword[30];
    struct Admin addedAdmin;
    bool isRunning = true;
    do {
        printf("Enter new admin's first name:\n");
        scanf("%s", aFName);
        strcpy(addedAdmin.fName, aFName);
        printf("Enter new admin's last name:\n");
        scanf("%s", aLName);
        strcpy(addedAdmin.lName, aLName);
        printf("Enter new admin's user name:\n");
        scanf("%s", aUserName);
        strcpy(addedAdmin.userName, aUserName);
        printf("Enter new admin's password:\n");
        scanf("%s", aPassword);
        strcpy(addedAdmin.password, aPassword);
        for(int i = 0; i <numAdmins; i++) {
            if (strcmp(admins[i].fName, "") == 0) {
                admins[i] = addedAdmin;
            }
        }
        isRunning = false;
    } while(isRunning);
}
//Prints all admins to console
void printAdmins(struct Admin admins[], int numAdmins) {
    printf("First Name     Last Name     User Name         Password\n\n");

    for (int i = 0; i <= numAdmins; i++) {
        if (strcmp(admins[i].fName, "") != 0) {
            printf("%-14s %-14s", admins[i].fName, admins[i].lName);
            printf("%-26s", admins[i].userName);
            printf("%-19s\n", admins[i].password);
        }
    }
    printf("\n");
}
//Prints all voters to console
void printVoters(struct Voter voters[], int numVoters) {
    printf("ID        First Name     Last Name     Street                    City               Phone              Has Voted\n\n");

    for (int i = 0; i < numVoters; i++) {
        if (voters[i].voterId != 0) {
            printf("%-10d", voters[i].voterId);
            printf("%-14s %-14s", voters[i].fName, voters[i].lName);
            printf("%-26s", voters[i].street);
            printf("%-19s", voters[i].city);
            printf("%-19s", voters[i].phone);
            printf("%s\n", voters[i].hasVoted ? "Yes" : "No");
        }
    }
    printf("\n");
}

void printCandidates(struct Candidate candidates[], int numElements) {
    printf("ID        First Name     Last Name        Party               #Votes\n\n");

    for (int i = 0; i < numElements; i++) {
        printf("\n");
        if (candidates[i].id != 0) {
            printf("%-10d", candidates[i].id);
            printf("%-14s %-17s", candidates[i].fName, candidates[i].lName);
            printf("%-23s", candidates[i].party);
            printf("%-10d\n", candidates[i].vCount);
        }
    }
    printf("\n");
}
//returns a password of length n
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
    strcat(p, "\0");
    return p;
}

//system login
void systemLogin(struct PollOfficer pollOfficer, char cUser[], char cUserPassword[]) {
    bool isRunning = true;
    do {
        printf("WELCOME TO POLLSTAR!\n");
        printf("============================================================================\n\n");
        printf("SYSTEM LOGIN\n");
        printf("----------------------------------------------------------------------------\n\n");
        printf("Username:\n");
        fgets(cUser, 30, stdin);
        cUser [ strcspn(cUser, "\r\n")] = '\0';
        printf("Password:\n");
        fgets(cUserPassword, 30, stdin);
        cUserPassword [ strcspn(cUserPassword, "\r\n")] = '\0';
            if (strcmp(cUser, pollOfficer.userName) == 0 && strcmp(cUserPassword, pollOfficer.password) == 0) {
                printf("Welcome %s %s\n", pollOfficer.fName, pollOfficer.lName);
                isRunning = false;
                break;
            } else {
                printf("Please try again.\n");
            }
    } while(isRunning);
}
//admin login
void adminLogin(char cUser[], char cUserPassword[], struct Admin admins[], int numAdmins) {
    bool isRunning = true;

    do {
        printf("WELCOME TO POLLSTAR!\n");
        printf("============================================================================\n\n");
        printf("ADMIN LOGIN\n");
        printf("----------------------------------------------------------------------------\n\n");
        printf("Username:\n");
        fgets(cUser, 30, stdin);
        cUser [ strcspn(cUser, "\r\n")] = '\0';
        printf("Password:\n");
        fgets(cUserPassword, 30, stdin);
        cUserPassword [ strcspn(cUserPassword, "\r\n")] = '\0';
        for(int i = 0; i <= numAdmins; i++) {
            if (strcmp(cUser, admins[i].userName) == 0 && strcmp(cUserPassword, admins[i].password) == 0) {
                printf("Welcome %s %s\n", admins[i].fName, admins[i].lName);
                isRunning = false;
                break;
            } else {
                printf("Please try again.\n");
            }
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
        scanf("%s", vFName);
        printf("Enter voter last name:\n");
        scanf("%s", vLName);

        for (int i = 0; i < numElements; i++) {
            if (strcmp(voters[i].fName, vFName) == 0  && strcmp(voters[i].lName, vLName) == 0) {
                printf("ID        First Name     Last Name     Street                    City               Phone              Has Voted\n\n");
                printf("%-10d%-14s%-15s%-25s%-19s%-19s%s\n\n", voters[i].voterId, voters[i].fName, voters[i].lName,
                       voters[i].street, voters[i].city, voters[i].phone, voters[i].hasVoted ? "Yes" : "No");
                printf("Create voter passcode?\n1. Yes\n2. No\n");
                scanf("%d", &option);
                if(option == 1) {
                    strcpy(voters[i].passcode, randomPasswordGenerator(6));
                    printf("%s\n\n", voters[i].passcode);
                }
            }
        }
        printf("Please choose:\n");
        printf("1. Enter another voter\n");
        printf("2. Exit to main menu\n");
        fflush(stdin);
        scanf(" %d", &option);
        if(option == 2) isRunning = false;
    } while(isRunning);
}

void recordVotes(struct Voter voters[], struct Candidate candidates[], int nVoters, int nCan, char pCode[]) {
    int voteChoice;
    printf("Please enter voter code:\n");
    fflush(stdin);
    fgets(pCode, 20, stdin);
    passcode [ strcspn(pCode, "\r\n")] = '\0';
    for(int i = 0; i < nVoters; i++) {
//        if(strcmp(pCode, "password")) break;
        if(strcmp(voters[i].passcode, pCode) == 0 && voters[i].hasVoted == false) {
            printf("Hello, %s %s, welcome!\n\n", voters[i].fName, voters[i].lName);
            printf("Please choose a candidate to vote for:\n");
            for(int j = 0; j < nCan; j++) {
                printf("%d.  %s %s ---- %s\n", j+1, candidates[j].fName, candidates[j].lName, candidates[j].party);
            }
            scanf("%d", &voteChoice);
            candidates[voteChoice-1].vCount++;
            voters[i].hasVoted = true;
        }
    }
}

void editVoterInfo(struct Voter voters[], int numElements) {
    int id;
    char vFName[30];
    char vLName[30];
    char street[30];
    char city[30];
    char phone[30];
    bool isRunning = true;
    int option;

    do {
        printf("Enter voter ID number.\n");
        scanf("%d", &id);
        for (int i = 0; i < numElements; i++) {
            if (id == voters[i].voterId) {
                printf("%-10d%-14s%-15s%-25s%-19s%-19s%s\n\n", voters[i].voterId, voters[i].fName, voters[i].lName,
                       voters[i].street, voters[i].city, voters[i].phone, voters[i].hasVoted ? "Yes" : "No");
                printf("What would you like to edit? Please Choose:\n\n");
                printf("1. First Name\n2. Last Name\n3. Street Address\n4. City\n5. Phone Number\n6. Main Menu\n\n");
                printf("Enter #(1-7)\n");
                scanf("%d", &option);
                fflush(stdin);

                switch(option) {
                    case 1:
                        printf("Enter new first name:\n");
                        scanf("%s", vFName);
                        strcpy(voters[i].fName, vFName);
                        break;
                    case 2:
                        printf("Enter new last name:\n");
                        scanf("%s", vLName);
                        strcpy(voters[i].lName, vLName);
                        break;
                    case 3:
                        printf("Enter new street address:\n");
                        fgets(street, 30, stdin);
                        street [ strcspn(street, "\r\n")] = '\0';
                        strcpy(voters[i].street, street);
                        break;
                    case 4:
                        printf("Enter new city:\n");
                        fgets(city, 30, stdin);
                        city [ strcspn(city, "\r\n")] = '\0';
                        strcpy(voters[i].city, city);
                        break;
                    case 5:
                        printf("Enter new phone number:\n");
                        scanf("%s", phone);
                        strcpy(voters[i].phone, phone);
                        break;
                    case 6:
                        isRunning = false;
                        break;
                } break;
            }
        }
        printf("Voter ID not recognized.\n\n");
    }while(isRunning);
}
