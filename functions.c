//
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#include <time.h>
//#include <stdlib.h>
//#include "definitions.h"

//
//
//
//const char* randomPasswordGenerator(int n) {
//    int i;
//    int randomizer;
//
//  initialize password characters
//    srand((unsigned int) (time(NULL)));
//
//    char numbers[] = "1234567890";
//    char letters[] = "abcdefghijklmnopqrstuvwxyz";
//    char uCaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    char symbols[] = "!@#$%^&*()-_=+?<>,.;:'";
//    randomizer = rand() % 4;
//    char *p = password;
//
//    for(i=0; i<n; i++) {
//        if(randomizer == 1 ) {
//            p[i] = numbers[rand() % 10];
//            randomizer = rand() % 4;
//        }
//        else if(randomizer == 2) {
//            p[i] = letters[rand() % 26];
//            randomizer = rand() % 4;
//        }
//        else if(randomizer == 3) {
//            p[i] = uCaseLetters[rand() % 26];
//            randomizer = rand() % 4;
//        }
//        else {
//            p[i] = symbols[rand() % 22];
//            randomizer = rand() % 4;
//        }
//    }
//    return p;
//}
//
//void adminLogin(char currentUser[], char currentUserPassword[], struct Admin admin1) {
//    bool isRunning = true;
//
//    do {
//        printf("Please enter your username and password:\nUsername:\n");
//        fgets(currentUser, 30, stdin);
//        currentUser [ strcspn(currentUser, "\r\n")] = '\0';
//        printf("Password:\n");
//        fgets(currentUserPassword, 30, stdin);
//        currentUserPassword [ strcspn(currentUserPassword, "\r\n")] = '\0';
//
//        if (strcmp(currentUser, admin1.userName) == 0 && strcmp(currentUserPassword, admin1.password) == 0) {
//            printf("Welcome %s %s\n", admin1.fName, admin1.lName);
//            isRunning= false;
//        } else {
//            printf("Please try again.\n");
//        }
//    } while(isRunning);
//}
//
//void voterSearch(struct Voter voters[], int numElements) {
//    char vFName[30];
//    char vLName[30];
//    bool isRunning = true;
//    int option;
//    do {
//        printf("Enter voter first name:\n");
//        scanf("%s", &vFName);
//        printf("Enter voter last name:\n");
//        scanf("%w", &vLName);
//
//        for (int i = 0; i < numElements; i++) {
//            if (strcmp(&voters[i].fName, vFName) == 0) {
//                printf("ID        First Name     Last Name     Street                    City               Phone              Has Voted\n\n");
//                printf("%-10d%-14s%-15s%-25s%-19s%-19s%s\n", voters[i].voterId, voters[i].fName, voters[i].lName,
//                       voters[i].street, voters[i].city, voters[i].phone, voters[i].hasVoted ? "Yes" : "No");
//            } else {
//                printf("Voter not found\n");
//                break;
//            }
//        }
//        printf("Please choose:\n");
//        printf("1. Enter another voter\n");
//        printf("2. Exit to main menu\n");
//        fflush(stdin);
//        scanf(" %d", &option);
//        printf("%d", option);
//        if(option == 2) isRunning = false;
//    } while(isRunning);
//}
//
//void printVoters(struct Voter voters[], int numElements) {
//    printf("ID        First Name     Last Name     Street                    City               Phone              Has Voted\n\n");
//
//    for (int i = 0; i < numElements; i++) {
//        printf("%-10d", voters[i].voterId);
//        printf("%-14s %-15s", voters[i].fName, voters[i].lName);
//        printf("%-25s", voters[i].street);
//        printf("%-19s", voters[i].city);
//        printf("%-19s", voters[i].phone);
//        printf("%s\n", voters[i].hasVoted ? "Yes" : "No");
//    }
//}
