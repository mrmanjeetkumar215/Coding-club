#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PARTY 5
struct Party {
    char name[20];
    int votes;
};
//  Display Party List 
void listofparties (struct Party parties[], int TotalParty)
{
    printf("List of party: \n");
    for(int i =0 ; i < TotalParty ; i++)
    {
        printf("%d. %s\n", i+1, parties[i].name);
    }
}

//  Voting function
void chooseCandidate(struct Party parties[], int TotalParty, int choice)
{
    //  checks if the choice is valid or not
    if(choice >= 1 && choice <= TotalParty)
    {
        parties[choice - 1].votes++;
        printf("choosed your candidate for %s.\n", parties[choice - 1].name);
    }
     else {
        printf("Please select a valid party.\n");
    }
}

int WinningCandidate(struct Party parties[], int TotalParty )
{
    //  initializes leadingPartyIndex to 0
    int leadingParty= 0;
    for(int i =1; i < TotalParty; i++)
    {
        if(parties[i].votes > parties[leadingParty].votes)
        {
            leadingParty= i ;
        }
    }
    return leadingParty;
}

int main()
{
    int totalParty;
    struct Party parties[MAX_PARTY];
    
    printf("Voting System by Manjeet \n");
    
    printf("Enter the number of parties (up to %d): ", MAX_PARTY);
    scanf("%d", &totalParty);

    if (totalParty < 1 || totalParty > MAX_PARTY) {
        printf("Invalid number of Party.\n");
        return 1;
    }
    
    for (int i = 0; i < totalParty; i++) {
        printf("Enter the name of Party %d: ", i + 1);
        scanf(" %[^\n]", parties[i].name);
        parties[i].votes = 0;
    }
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Party\n");
        printf("2. Choose Candidate\n");
        printf("3.  Wining Party\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listofparties(parties, totalParty);
                break;
            case 2:
                listofparties(parties, totalParty);
                printf("Enter the number of the candidate you want to vote for: ");
                scanf("%d", &choice);
                chooseCandidate(parties, totalParty, choice);
                break;
            case 3:
                if (totalParty > 0) {
                    int leadingParty= WinningCandidate(parties, totalParty);
                    printf("Leading Candidate: %s with %d votes.\n", parties[leadingParty].name, parties[leadingParty].votes);
                } else {
                    printf("No Party available.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf(" Please select a valid option.\n");
        }
    }

    return 0;
}

