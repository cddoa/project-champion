#include "prompts.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string defaultPrompt(int rank, int wins, int losses) { // default prompt
    std::string playerInput;
    std::cout << "Your record: " << wins << "-" << losses << "\n";
    std::cout << "Your rank: " << rank << "\n";
    std::cout << "------------------------------\n";
    std::cout << "1. Choose next opponent\n";
    std::cout << "2. Retire\n";
    std::cout << "------------------------------\n";
    std::cout << " \n";
    getline(std::cin, playerInput);
    std::cout << " \n";
    return playerInput;
};

std::string trainingPrompt() { // training prompt
    std::string playerInput;
    std::cout << "What would you like to train this week?\n";
    std::cout << "1. Striking\n";
    std::cout << "2. Grappling\n";
    std::cout << "3. Health\n";
    std::cout << "4. Stamina\n";
    std::cout << " \n";
    getline(std::cin, playerInput);
    return playerInput;
}

void press_any_key() // press enter key prompt
{
    std::string temp;
    std::cout << "Press Enter to Continue \n";
    std::getline(std::cin, temp);
    std::cout << " \n";
}

void displayNewStats(int playerStriking, int playerGrappling,
    int playerConditioning) {
    std::cout << "-----------------------\n";
    std::cout << "YOUR NEW STATS:\n";
    std::cout << "Striking: " << playerStriking << "\n";
    std::cout << "Grappling: " << playerGrappling << "\n";
    std::cout << "Conditioning: " << playerConditioning << "\n";
    std::cout << "-----------------------\n";
    std::cout << " \n";
}

void displayNextOpponent(std::string opponentName,  std::string opponentRank) {

    std::cout << "--------------------------------------------\n";
    std::cout << "YOUR NEXT OPPONENT: " << opponentName << "\n";
    std::cout << "RANK: " << opponentRank << "\n";    
    std::cout << "--------------------------------------------\n";
    std::cout << " \n";
}

std::string championPrompt(int wins, int losses, int defenses) {

    std::string playerInput;
    std::cout << "Your record: " << wins << "-" << losses << "\n";
    std::cout << "Your rank: Champion\n";
    std::cout << "Title defenses: " << defenses << "\n";
    std::cout << "------------------------------\n";
    std::cout << "1. Choose next opponent\n";
    std::cout << "2. Retire\n";
    std::cout << "------------------------------\n";
    std::cout << " \n";
    getline(std::cin, playerInput);
    std::cout << " \n";
    return playerInput;

}

void fightCardPrompt(std::string playerName, std::string opponentName, int timesFought, int playerRank, int opponentIndex, std::string weightClass) {
    srand(time(nullptr));
    int rng;
    
    std::cout << "------------------------------------------------------------------------\n";
    

    if (playerRank > 16) {
        rng = 1 + (rand() % 100);
        if (rng <= 60) {
           
            std::cout << " \n";
            std::cout << "UFC Fight Night prelim fight \n";
            std::cout << " \n";
        }
        else if (rng > 60 && rng <= 80) {
            std::cout << " \n";
            std::cout << "UFC PPV prelim fight \n";
           std::cout << " \n";        
        }
        else if (rng > 80 && rng <= 100) {
            std::cout << " \n";
            std::cout << "UFC Fight Night Main Card fight \n";
            std::cout << " \n";
        }
    }

    else if (playerRank <= 16 && playerRank >= 12) {
        rng = 1 + (rand() % 100);
        if (rng <= 60) {
            std::cout << " \n";
            std::cout << "UFC Fight Night Main Card fight \n";
            std::cout << " \n";        
        }
        else if (rng > 60 ) {
            std::cout << " \n";
            std::cout << "UFC PPV prelim fight \n";
            std::cout << " \n";
        }
    }
    
    else if (playerRank < 12 && playerRank >= 7) {
        rng = 1 + (rand() % 100);
        if (rng <= 60) {
            std::cout << " \n";
            std::cout << "UFC Fight Night Main Event \n";
            std::cout << " \n";
        }
        else if (rng > 60) {
            std::cout << " \n";
            std::cout << "UFC PPV Main Card fight \n";
            std::cout << " \n";
        }
        
    }

    else if (playerRank < 7 && playerRank >= 1 && opponentIndex != 0) {
        rng = 1 + (rand() % 100);
        if (rng <= 60) {
            std::cout << " \n";
            std::cout << "UFC Fight PPV Main Card fight \n";
            std::cout << " \n";
        }
        else if (rng > 60 && rng <= 90) {
            std::cout << " \n";
            std::cout << "UFC Fight Night Main Event \n";
            std::cout << " \n";
        }
        else if (rng > 90) {
            std::cout << " \n";
            std::cout << "UFC PPV Main Event \n";
            std::cout << " \n";
        }
       
    }

    else if (playerRank == 0 || opponentIndex == 0) {
        std::cout << " \n";
        std::cout << "UFC PPV Main Event \n";
        std::cout << " \n";
    
    }


    std::cout << playerName << " vs " << opponentName << " ";

    if (timesFought > 1) {
        std::cout << timesFought << "\n";
    
    }
    else {
        std::cout << " \n";
    }

    if (playerRank == 0 || opponentIndex == 0) {
        std::cout << " \n";
        std::cout << weightClass << " Championship \n";
        std::cout << " \n";
    
    }
    else {
        std::cout << " \n";
        std::cout << weightClass << " Bout \n";
        std::cout << " \n";
    }
    std::cout << "------------------------------------------------------------------------\n";

}

void displayNewStrikingStats(std::string attackName[], int level[], int defense) {

    std::cout << "-------------------------\n";
    std::cout << "YOUR NEW STRIKING STATS:\n";
    std::cout << " \n";

    for (int i = 0; i < 4; i++) {        

        if (attackName[i] == " ") {
            std::cout << "";
        }
        else {
            std::cout << attackName[i] << ": " << level[i] << "\n";            
        }
    }
    std::cout << "Striking Defense: " << defense <<"\n";
    std::cout << " \n";
    std::cout << "-------------------------\n";
    std::cout << " \n";
}


void displayNewGrapplingStats(std::string topAttackName[], std::string bottomAttackName[], int topLevel[], int bottomLevel[], int takedown) {

    std::cout << "-------------------------\n";
    std::cout << "YOUR NEW GRAPPLING STATS:\n";
    std::cout << "\n";
    for (int i = 0; i < 4; i++) {

        if (topAttackName[i] == " ") {
            std::cout << "";
        }
        else {
            std::cout << topAttackName[i] << ": " << topLevel[i] << "\n";
        }
    }

    for (int i = 0; i < 4; i++) {

        if (bottomAttackName[i] == " ") {
            std::cout << "";
        }
        else {
            std::cout << bottomAttackName[i] << ": " << bottomLevel[i] << "\n";
        }
    }

    std::cout << "Takedowns and takedown defense: " << takedown << "\n";

    std::cout << " \n";
    std::cout << "-------------------------\n";
    std::cout << " \n";


}

std::string firstFightPrompt() {
    std::string playerInput;
    std::cout << " \n";
    std::cout << "---------------------------\n";
    std::cout << " \n";
    std::cout << "1. Keep the fight standing\n";
    std::cout << "2. Shoot a takedown\n";
    std::cout << " \n";
    std::cout << "---------------------------\n";
    std::cout << " \n";
    getline(std::cin, playerInput);
    return playerInput;

}

int healthCheck(int health) {

    int koHealth = 0;

    if (health <= 0) {
        
        return koHealth;
    
    }
    else {
    
    
        return health;

    }

}
