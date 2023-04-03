
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

char password[20];

char passcode[20];

struct PollOfficer {
    char fName[20];
    char lName[20];
    char userName[30];
    char password[30];
};

struct Admin {
    int id;
    char fName[30];
    char lName[30];
    char userName[30];
    char password[30];
};

struct Voter
{
    int voterId;
    char fName[30];
    char lName[30];
    char street[30];
    char city[30];
    char phone[30];
    bool hasVoted;
    char passcode[6];
};

struct Voter voters[100];

struct Candidate {
    int id;
    char fName[30];
    char lName[30];
    char party[30];
    int vCount;
};

char currentUser[30];
char currentUserPassword[30];
int option;
