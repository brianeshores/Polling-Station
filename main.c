#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"
#include "functions.h"

void printVoters(struct Voter voters[], int n);

const char* randomPasswordGenerator(int n);

void adminLogin(char cUser[], char cUserPassword[], struct Admin admin1);

void voterSearch(struct Voter voters[], int n );

void recordVotes(struct Voter voters[], struct Candidate candidates[], int nVoters, int nCan, char pCode[]);

char passcode[20];

int main() {

    struct Admin admin1 = {"Jessica", "James", "jjames", "password"};

    struct Candidate candidate1 = {1, "Michelle", "Wright", "Liberal", 0};
    struct Candidate candidate2 = {2, "Pete", "Patrick", "Conservative", 0};
    struct Candidate candidate3 = {3, "Sarah", "Grady", "NDP", 0};

    struct Voter voter1 = {123456,"Mary", "Johnson", "12 Perry Street", "Halifax", "902-555-5555", false};
    struct Voter voter2 = {235678,"Frank", "White", "79 Pleasant Street", "Dartmouth", "902-647-4675", false};
    struct Voter voter3 = {564738,"Tim", "Black", "3A Willow Lane", "Halifax", "902-890-7465", false};
    struct Voter voter4 = {759384,"Mike", "Tompkins", "1101 Portland Street", "Dartmouth", "902-555-1234", false};
    struct Voter voter5 = {899374,"John", "Blank", "45 Robie Street", "Halifax", "902-888-3455", false};
    struct Voter voter6 = {899374,"Jill", "Jones", "445 Main Street", "Sackville", "902-454-3423", false};
    struct Voter voter7 = {899374,"Bob", "Bronson", "28 View Street", "Bedford", "902-899-3344", false};
//Add Voter Structs To a Voters Array
    struct Voter voters[] = {voter1, voter2, voter3, voter4, voter5, voter6, voter7};
    struct Candidate candidates[] = {candidate1, candidate2, candidate3};

    int numVoters = sizeof(voters)/sizeof(voters[0]);
    int numCandidates = sizeof(candidates)/sizeof(candidates[0]);
    void printCandidates(struct Candidate candidates[], int numElements);


//Run Admin Login Function
    adminLogin(currentUser, currentUserPassword, admin1);
    do {
        printf("Please choose an option:\n\n");
        printf("1. Search for existing voter\n");
        printf("2. Edit existing voter information\n");
        printf("3. Add voter\n");
        printf("4. Print voter infromation\n");
        printf("5. Print full voter list\n");
        printf("6. Print candidate list\n");
        printf("7. Switch to voter machine mode\n\n");
        printf("Enter value (1-7):\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                voterSearch(voters, numVoters);
                break;
            case 5:
                printVoters(voters, numVoters);
                break;
            case 6:
                printCandidates(candidates, numCandidates);
                break;
            case 7:
                recordVotes(voters, candidates, numVoters, numCandidates, passcode);
                break;
        }
    } while(isRunning);

    return 0;
}
//Prints all voters to console
void printVoters(struct Voter voters[], int numElements) {
    printf("ID        First Name     Last Name     Street                    City               Phone              Has Voted\n\n");

    for (int i = 0; i < numElements; i++) {
        printf("%-10d", voters[i].voterId);
        printf("%-14s %-14s", voters[i].fName, voters[i].lName);
        printf("%-26s", voters[i].street);
        printf("%-19s", voters[i].city);
        printf("%-19s", voters[i].phone);
        printf("%s\n", voters[i].hasVoted ? "Yes" : "No");
    }
    printf("\n");
}

void printCandidates(struct Candidate candidates[], int numElements) {
    printf("ID        First Name     Last Name        Party               #Votes\n\n");

    for (int i = 0; i < numElements; i++) {
        printf("%-10d", candidates[i].id);
        printf("%-14s %-17s", candidates[i].fName, candidates[i].lName);
        printf("%-23s", candidates[i].party);
        printf("%-10d\n", candidates[i].vCount);
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
//main login for program
void adminLogin(char cUser[], char cUserPassword[], struct Admin admin1) {
    bool isRunning = true;

    do {
        printf("Please enter your username and password:\nUsername:\n");
        fgets(cUser, 30, stdin);
        cUser [ strcspn(cUser, "\r\n")] = '\0';
        printf("Password:\n");
        fgets(cUserPassword, 30, stdin);
        cUserPassword [ strcspn(cUserPassword, "\r\n")] = '\0';

        if (strcmp(cUser, admin1.userName) == 0 && strcmp(cUserPassword, admin1.password) == 0) {
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
        if(strcmp(voters[i].passcode, pCode) == 0) {
            printf("Hello, %s %s, welcome!\n\n", voters[i].fName, voters[i].lName);
            printf("Please choose a candidate to vote for:\n");
            for(int j = 0; j < nCan; j++) {
                printf("%d.  %s %s ---- %s\n", j+1, candidates[j].fName, candidates[j].lName, candidates[j].party);
            }
            scanf("%d", &voteChoice);
            candidates[voteChoice-1].vCount++;
            voters[i].hasVoted = true;
            printf("%s %s vote count = %d\n", candidates[voteChoice-1].fName, candidates[voteChoice-1].lName, candidates[voteChoice-1].vCount);
        }
    }
}
