#include "prompts.h"
#include "fighting.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>


bool isNumber(const std::string& str) { //function to detect if string is a number
    for (char const& c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

// class for opponents
class fighter {
public:
    std::string fighterName;
    
    int striking;
    int grappling;
    int conditioning;
    int timesFought;

    fighter()
        : fighterName(""),  striking(0), grappling(0),
        conditioning(0), timesFought(0) {}

    fighter(std::string name, int striking, int grappling,
        int conditioning, int timesFought)
        : fighterName(name),  striking(striking),
        grappling(grappling), conditioning(conditioning), timesFought(timesFought) {}
};

//class for attacks
class attack {
public:
    std::string attackName;
    int level;
    int maxLevel;
    int cost;

    attack()
        : attackName(""), level(0), maxLevel(0), cost(0) {}

    attack(std::string attackName, int level, int maxLevel, int cost)
        : attackName(attackName), level(level), maxLevel(maxLevel), cost(cost) {}

};

// variables
std::string playerName;
int playerStrikingDef = 20; //player striking defense
int playerTakeDown = 20; //player's takedown/takedown defense stat
int playerHealth = 20; //player health
int playerStamina = 20;
std::string playerInput;
int trainingPoints;
int remainingWeeks = 0;
bool retired = false;
bool defaultPromptChosen = false;
bool opponentChosen = false;
int opponentStriking = 0;
int opponentGrappling = 0;
int opponentConditioning = 0;
std::string opponentName;
std::string opponentStyle;
std::string opponentRank;
int opponentIndex;
int playerRank = 20;
int wins = 0;
int losses = 0;
int titleDefenses;
int totalTitleDefenses = 0;
bool fightResult = false;
bool titleShot;
bool isChampion = false;
int rng = 0;
int opponentTimesFought;
int highestRank = 20;
bool randomRank;
std::string weightSelection;
std::string weightClass;
bool weightSelected = false;
bool styleSelected = false;
std::string fightingStyle;
int rng2;

int main() {
    srand(time(nullptr));

    std::cout << "Enter your fighter's name: ";
    getline(std::cin, playerName);
    std::cout << " \n";

    fighter rankings[21]; //rankings array

    attack playerStrikingAttacks[4]; //different types of attacks array
    attack playerTopGroundAttacks[4];
    attack playerBottomGroundAttacks[4];

    std::string strikeNames[4]; //arrays to store names/levels of attacks to put into functions
    int strikeLevels[4];
    int strikeCosts[4];
    std::string topAttackNames[4];
    int topAttackLevels[4];
    int topAttackCosts[4];
    std::string bottomAttackNames[4];
    int bottomAttackLevels[4];
    int bottomAttackCosts[4];

    //arrays for different attacks according to fighting style

    attack strikerStrikingAttacks[4] = { //attacks for striker class
        attack("Left Hook", 20, 90, 15),
        attack("Right Overhand", 30, 100, 20),
        attack("Leg Kick", 20, 60, 10),
        attack("Head Kick", 30, 120, 40)
    };

    attack strikerTopGroundAttacks[4] = {
        attack("Ground and pound", 20, 100, 25),
        attack(" ", 30, 100, 20),
        attack(" ", 20, 20, 10),
        attack(" ", 20, 20, 20)
    };

    attack strikerBottomGroundAttacks[4] = {
        attack("Get Up", 20, 100, 20),
        attack("Get On Top", 20, 100, 20),
        attack(" ", 20, 30, 20),
        attack(" ", 20, 30, 20)
    };

    attack grapplerStrikingAttacks[4] = { //attacks for grappler class
        attack("Jab", 20, 70, 10),
        attack("Cross", 20, 80, 20),
        attack("Right Hook", 20, 100, 30),
        attack(" ", 20, 30, 20)
    };

    attack grapplerTopGroundAttacks[4] = {
        attack("Ground and pound", 30, 100, 25),
        attack("Arm Bar", 20, 100, 30),
        attack("Arm Triangle", 20, 100, 30),
        attack("Rear Naked Choke", 20, 100, 35)
    };

    attack grapplerBottomGroundAttacks[4] = {
        attack("Get Up", 30, 100, 25),
        attack("Arm Bar From Guard", 20, 100, 30),
        attack("Triangle Choke", 20, 100, 30),
        attack("Get On Top", 30, 100, 25)
    };

    attack boxerStrikingAttacks[4] = { //attacks for boxer class
        attack("1-2", 30, 100, 20),
        attack("Right Hook", 20, 110, 25),
        attack("Right Uppercut", 20, 110, 25),
        attack("Liver Hook", 30, 110, 30)
    };

    attack boxerTopGroundAttacks[4] = {
        attack("Ground and pound", 20, 100, 25),
        attack(" ", 30, 100, 20),
        attack(" ", 20, 20, 10),
        attack(" ", 20, 20, 20)

    };

    attack boxerBottomGroundAttacks[4] = {
        attack("Get Up", 20, 100, 25),
        attack("Get On Top", 20, 100, 25),
        attack(" ", 20, 30, 20),
        attack(" ", 20, 30, 20)
    };



    // weightclasses and all of opponents info
    fighter flyweight[21] = {
        fighter("Alexandre Pantoja",  75, 80, 85, 0),
        fighter("Brandon Moreno",  75, 80, 85, 0),
        fighter("Brandon Royval",  80, 80, 80, 0),
        fighter("Amir Albazi",  85, 75, 80, 0),
        fighter("Kai Kara-France",  70, 80, 70, 0),
        fighter("Tatsuro Taira",  85, 70, 65, 0),
        fighter("Alex Perez",  80, 75, 65, 0),
        fighter("Matheus Nicolau",  80, 75, 80, 0),
        fighter("Steve Erceg",  80, 71, 80, 0),
        fighter("Manel Kape",  75, 70, 70, 0),
        fighter("Tim Elliott",  60, 70, 70, 0),
        fighter("Matt Schnell",  65, 55, 65, 0),
        fighter("Tagir Ulanbekov",  50, 60, 60, 0),
        fighter("Bruno Silva",  60, 60, 60, 0),
        fighter("Asu Almabayev",  55, 55, 60, 0),
        fighter("Cody Durden",  45, 45, 40, 0),
        fighter("Boner Clancy",  30, 20, 25, 0),
        fighter("Willem Dafoe",  21, 30, 25, 0),
        fighter("Howard Hamlin",  20, 25, 21, 0),
        fighter("Steve Lee",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };

    fighter bantamweight[21] = {
        fighter("Sean O'Malley",  75, 80, 85, 0),
        fighter("Merab Dvalishvili",  80, 80, 80, 0),
        fighter("Umar Nurmagomedov",  85, 75, 80, 0),
        fighter("Petr Yan",  70, 80, 70, 0),
        fighter("Cory Sandhagen",  85, 70, 65, 0),
        fighter("Deiveson Figueiredo",  80, 75, 65, 0),
        fighter("Henry Cejudo",  80, 75, 80, 0),
        fighter("Marlon Vera",  80, 71, 80, 0),
        fighter("Song Yadong",  75, 70, 70, 0),
        fighter("Rob Font",  60, 70, 70, 0),
        fighter("Jose Aldo",  65, 55, 65, 0),
        fighter("Mario Bautista",  50, 60, 60, 0),
        fighter("Kyler Phillips",  60, 60, 60, 0),
        fighter("Jonathan Martinez",  55, 55, 60, 0),
        fighter("Dominick Cruz",  55, 55, 50, 0),
        fighter("Montel Jackson",  55, 60, 45, 0),
        fighter("Payton Talbott",  30, 20, 25, 0),
        fighter("John Hayward",  21, 30, 25, 0),
        fighter("Noah Zhao",  20, 25, 21, 0),
        fighter("Chuck McGill",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };
    fighter featherweight[21] = {
        fighter("Ilia Topuria",  75, 80, 85, 0),
        fighter("Alexander Volkonovski",  80, 80, 80, 0),
        fighter("Max Holloway",  85, 75, 80, 0),
        fighter("Brian Ortega",  70, 80, 70, 0),
        fighter("Yair Rodriguez",  85, 70, 65, 0),
        fighter("Arnold Allen",  80, 75, 65, 0),
        fighter("Movsar Evloev",  80, 75, 80, 0),
        fighter("Josh Emmet",  80, 71, 80, 0),
        fighter("Aljamain Sterling",  75, 70, 70, 0),
        fighter("Calvin Kattar",  60, 70, 70, 0),
        fighter("Giga Chikadze",  65, 55, 65, 0),
        fighter("Lerone Murphy",  50, 60, 60, 0),
        fighter("Diego Lopez",  60, 60, 60, 0),
        fighter("Bryce Mitchell",  55, 55, 60, 0),
        fighter("Dan Ige",  55, 55, 50, 0),
        fighter("Edson Barboza",  55, 60, 45, 0),
        fighter("Jared Fogle",  30, 20, 25, 0),
        fighter("Christian Chandler",  21, 30, 25, 0),
        fighter("Sean Combs",  20, 25, 21, 0),
        fighter("Daniel Larson",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };
    fighter lightweight[21] = {
        fighter("John Smith",  75, 80, 85, 0),
        fighter("Islam Makhachev",  80, 80, 80, 0),
        fighter("Arman Tsarukyan", 80, 75, 80, 0),
        fighter("Charles Oliveira",  75, 85, 80, 0),
        fighter("Justin Gaethje",  70, 80, 70, 0),
        fighter("Dustin Poirier",  85, 70, 65, 0),
        fighter("Dan Hooker",  80, 75, 65, 0),
        fighter("Micheal Chandler",  80, 75, 80, 0),
        fighter("Beniel Dariush",  80, 71, 80, 0),
        fighter("Matseusz Gamrot",  75, 70, 70, 0),
        fighter("Rafael Fiziev",  60, 70, 70, 0),
        fighter("Renato Moicano",  65, 55, 65, 0),
        fighter("Benoit Saint Denis",  50, 60, 60, 0),
        fighter("Rafael Dos Anjos",  60, 60, 60, 0),
        fighter("Bryce Mitchell",  55, 55, 60, 0),
        fighter("Paddy Pimblett",  55, 55, 50, 0),
        fighter("Jalin Turner",  30, 20, 25, 0),
        fighter("Jimmy McGill",  21, 30, 25, 0),
        fighter("Henry Gooner",  20, 25, 21, 0),
        fighter("Vincent Chan",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };
    fighter welterweight[21] = {
        fighter("John Hagen",  75, 80, 85, 0),
        fighter("Belal Muhammad",  80, 80, 80, 0),
        fighter("Shavkat Rakhmonov",  85, 75, 80, 0),
        fighter("Kamaru Usman",  80, 85, 80, 0),
        fighter("Leon Edwards",  70, 80, 70, 0),
        fighter("Jack Della Maddalena",  70, 80, 70, 0),
        fighter("Colby Covington",  85, 70, 65, 0),
        fighter("Gilbert Burns",  80, 75, 65, 0),
        fighter("Ian Machado Garry",  80, 75, 80, 0),
        fighter("Sean Brady",  80, 71, 80, 0),
        fighter("Stephen Thompson",  75, 70, 70, 0),
        fighter("Geoff Neal",  60, 70, 70, 0),
        fighter("Joaquin Buckley",  65, 55, 65, 0),
        fighter("Micheal Morales",  50, 60, 60, 0),
        fighter("Micheal Page",  60, 50, 60, 0),
        fighter("Vincent Luque",  55, 45, 50, 0),
        fighter("Neil Magny",  35, 35, 30, 0),
        fighter("Christopher Moltisanti",  21, 30, 25, 0),
        fighter("Lalo Salamanca",  20, 25, 21, 0),
        fighter("Duke Dennis",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };

    fighter middleweight[21] = {
        fighter("Dricus Du Plessis",  75, 80, 85, 0),
        fighter("Sean Strickland",  80, 80, 80, 0),
        fighter("Israel Adesanya",  85, 75, 80, 0),
        fighter("Robert Whittaker",  80, 85, 80, 0),
        fighter("Nassourdine Imavov",  70, 80, 70, 0),
        fighter("Caio Borralho",  70, 80, 70, 0),
        fighter("Khamzat Chimaev",  85, 70, 65, 0),
        fighter("Jared Cannonier",  80, 75, 65, 0),
        fighter("Brendan Allen",  80, 75, 80, 0),
        fighter("Katsuki Bakugo",  80, 71, 80, 0),
        fighter("Marvin Vettori",  75, 70, 70, 0),
        fighter("Jack Hermansson",  60, 70, 70, 0),
        fighter("Roman Dolidze",  65, 55, 65, 0),
        fighter("Anthony Hernandez",  50, 60, 60, 0),
        fighter("Michel Pereira",  60, 60, 60, 0),
        fighter("Paulo Costa",  55, 55, 60, 0),
        fighter("Chris Curtis",  55, 55, 50, 0),
        fighter("Kyrie Nguyen",  21, 30, 25, 0),
        fighter("Bob Odenkirk",  20, 25, 21, 0),
        fighter("Anthony Soprano",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };

    fighter lightheavyweight[21] = {
        fighter("Alex Pereira",  90, 70, 85, 0),
        fighter("Jiri Prochazka",  80, 80, 80, 0),
        fighter("Gojo Satoru",  85, 75, 80, 0),
        fighter("Magomed Ankalaev",  80, 85, 80, 0),
        fighter("Jamahal Hill",  75, 75, 75, 0),
        fighter("Jan Blachowicz",  70, 80, 70, 0),
        fighter("Aleksandar Rakic",  70, 80, 70, 0),
        fighter("Volkan Oezdemir",  85, 70, 65, 0),
        fighter("Nikita Krylov",  80, 75, 65, 0),
        fighter("Khalil Rountree Jr.",  80, 75, 80, 0),
        fighter("Johnny Walker",  80, 71, 80, 0),
        fighter("Carlos Ulberg",  75, 70, 70, 0),
        fighter("Azamat Murzakanov",  60, 70, 70, 0),
        fighter("Anthony Smith",  65, 55, 65, 0),
        fighter("Dominick Reyes",  50, 60, 60, 0),
        fighter("Alonzo Menifield",  60, 60, 60, 0),
        fighter("Bogdan Guskov",  55, 55, 50, 0),
        fighter("Rick Grimes",  21, 30, 25, 0),
        fighter("Lebron Jame",  20, 25, 21, 0),
        fighter("Izuku Midoriya",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };

    fighter heavyweight[21] = {
        fighter("Jon Jones",  80, 70, 85, 0),
        fighter("Tom Aspinall",  80, 80, 80, 0),
        fighter("Ciryl Gane",  85, 75, 80, 0),
        fighter("Alexander Volkov",  80, 85, 80, 0),
        fighter("Sergei PavloVich",  75, 75, 75, 0),
        fighter("Peter Griffin",  70, 80, 70, 0),
        fighter("Curtis Blaydes",  70, 80, 70, 0),
        fighter("Jaliton Almeida",  85, 70, 65, 0),
        fighter("Serghei Spivac",  80, 75, 65, 0),
        fighter("Jairzinho Rozenstruik",  80, 75, 80, 0),
        fighter("Marcin Tybura",  80, 71, 80, 0),
        fighter("Derrick Lewis",  75, 70, 70, 0),
        fighter("Tai Tuivasa",  60, 70, 70, 0),
        fighter("Alexandr Romanov",  65, 55, 65, 0),
        fighter("Marcos Rogerio de Lima",  50, 60, 60, 0),
        fighter("Rodrigo Nascimento",  50, 50, 40, 0),
        fighter("Stipe Miocic",  35, 45, 40, 0),
        fighter("Flynn White",  21, 30, 25, 0),
        fighter("Joshua Block",  20, 25, 21, 0),
        fighter("Tyler Blevins",  25, 21, 21, 0),
        fighter(playerName,  playerStrikingDef, playerTakeDown  ,playerHealth, 0)
    };

    //weightclass selection

    while (weightSelected == false) {
        std::cout << "Select your weightclass: \n";
        std::cout << " \n";
        std::cout << "1. Flyweight \n";
        std::cout << "2. Bantamweight \n";
        std::cout << "3. Featherweight \n";
        std::cout << "4. Lightweight \n";
        std::cout << "5. Welterweight \n";
        std::cout << "6. Middleweight \n";
        std::cout << "7. Light Heavyweight \n";
        std::cout << "8. Heavyweight \n";
        std::cout << " \n";
        getline(std::cin, weightSelection);


        if (weightSelection == "1") { //weightclass chosen array is copied into rankings array
            std::copy(flyweight, flyweight + 21, rankings);
            weightSelected = true;
            weightClass = "Flyweight";
        }
        else if (weightSelection == "2") {
            std::copy(bantamweight, bantamweight + 21, rankings);
            weightSelected = true;
            weightClass = "Bantamweight";
        }
        else if (weightSelection == "3") {
            std::copy(featherweight, featherweight + 21, rankings);
            weightSelected = true;
            weightClass = "Featherweight";
        }
        else if (weightSelection == "4") {
            std::copy(lightweight, lightweight + 21, rankings);
            weightSelected = true;
            weightClass = "Lightweight";
        }
        else if (weightSelection == "5") {
            std::copy(welterweight, welterweight + 21, rankings);
            weightSelected = true;
            weightClass = "Welterweight";
        }
        else if (weightSelection == "6") {
            std::copy(middleweight, middleweight + 21, rankings);
            weightSelected = true;
            weightClass = "Middleweight";
        }
        else if (weightSelection == "7") {
            std::copy(lightheavyweight, lightheavyweight + 21, rankings);
            weightSelected = true;
            weightClass = "Light Heavyweight";
        }
        else if (weightSelection == "8") {
            std::copy(heavyweight, heavyweight + 21, rankings);
            weightSelected = true;
            weightClass = "Heavyweight";
        }
        else {
            std::cout << " \n";
            std::cout << "Not an option \n";
            std::cout << " \n";
        }
    }
    std::cout << " \n";

    //fighting style selection

    while (styleSelected == false) {
        std::cout << "Select your fighting style: \n";
        std::cout << " \n";
        std::cout << "1. Striker \n";
        std::cout << "2. Grappler \n";
        std::cout << "3. Boxer \n";
        std::cout << " \n";

        getline(std::cin, fightingStyle);

        if (fightingStyle == "1") {
            std::copy(strikerStrikingAttacks, strikerStrikingAttacks + 4, playerStrikingAttacks);
            std::copy(strikerTopGroundAttacks, strikerTopGroundAttacks + 4, playerTopGroundAttacks);
            std::copy(strikerBottomGroundAttacks, strikerBottomGroundAttacks + 4, playerBottomGroundAttacks);
            fightingStyle = "Striker";
            playerStrikingDef = 35;
            styleSelected = true;
        }

        else if (fightingStyle == "2") {
            std::copy(grapplerStrikingAttacks, grapplerStrikingAttacks + 4, playerStrikingAttacks);
            std::copy(grapplerTopGroundAttacks, grapplerTopGroundAttacks + 4, playerTopGroundAttacks);
            std::copy(grapplerBottomGroundAttacks, grapplerBottomGroundAttacks + 4, playerBottomGroundAttacks);
            fightingStyle = "Grappler";
            playerTakeDown = 35;
            styleSelected = true;
        }
        else if (fightingStyle == "3") {
            std::copy(boxerStrikingAttacks, boxerStrikingAttacks + 4, playerStrikingAttacks);
            std::copy(boxerTopGroundAttacks, boxerTopGroundAttacks + 4, playerTopGroundAttacks);
            std::copy(boxerBottomGroundAttacks, boxerBottomGroundAttacks + 4, playerBottomGroundAttacks);
            fightingStyle = "Boxer";
            playerStrikingDef = 35;
            styleSelected = true;
        
        }


        else {
            std::cout << "Not an option \n";
            std::cout << " \n";
        }

        std::cout << " \n";

    }

    for (int i = 0; i < 4; i++) { //assigning the arrays for function purposes
        strikeNames[i] = playerStrikingAttacks[i].attackName;
        strikeLevels[i] = playerStrikingAttacks[i].level;
        strikeCosts[i] = grapplerStrikingAttacks[i].cost;
        topAttackNames[i] = playerTopGroundAttacks[i].attackName;
        topAttackLevels[i] = playerTopGroundAttacks[i].level;
        topAttackCosts[i] = playerTopGroundAttacks[i].cost;
        bottomAttackNames[i] = playerBottomGroundAttacks[i].attackName;
        bottomAttackLevels[i] = playerBottomGroundAttacks[i].level;
        bottomAttackCosts[i] = playerBottomGroundAttacks[i].cost;
    }



    // welcome message
    std::cout << " \n";
    std::cout << "Welcome to the UFC, " << playerName << "!\n";
    std::cout << " \n";
    std::cout << "-----------------------\n";
    std::cout << "Weight Division: " << weightClass << "\n";
    std::cout << "Fighting Style: " << fightingStyle << "\n"; 
    std::cout << "-----------------------\n";
    std::cout << " \n";
    press_any_key();


    while (!retired) {

        // finding rank of player
        for (int i = 0; i < 21; i++) {
            if (rankings[i].fighterName == playerName) {
                playerRank = i;
                break;
            }
        }

        if (highestRank > playerRank) { //finding player's highest career rank

            highestRank = playerRank;

        }



        defaultPromptChosen = false;              // sets if default prompt has been answered to false
        opponentChosen = false; // sets if opponent has been chosen to false

        // choose next opponent or retire prompt
        while (defaultPromptChosen == false) {

            if (isChampion == false) { //default prompt if player is not the champion
                playerInput = defaultPrompt(playerRank, wins, losses);
            }
            else if (isChampion == true) { //special prompt if player is the champion
                playerInput = championPrompt(wins, losses, titleDefenses);
            }

            if (playerInput == "1") { // displays rankings if 1 is chosen

                while (opponentChosen == false) {
                    for (int i = 0; i < 21; i++) { // for loop to display rankings

                        if (i == 0) {
                            std::cout << "C. " << rankings[i].fighterName << "\n";
                        }
                        else {
                            std::cout << i << ". " << rankings[i].fighterName << "\n";
                        }
                    }
                    std::cout << " \n";

                    std::cout << "Choose your next opponent (enter their rank): ";
                    std::string inputtedOpponentRank;
                    getline(std::cin, inputtedOpponentRank);
                    std::cout << " \n";

                    if (isNumber(inputtedOpponentRank)) {
                        opponentIndex = (std::stoi(inputtedOpponentRank)); // opponent's rank as integer

                        if (opponentIndex > (playerRank + 3) ||
                            opponentIndex <
                            (playerRank - 3) && isChampion == false) { // check to see if opponent's rank is
                            // within 3 ranks of player
                            std::cout << "Opponent must be within 3 ranks of you \n";
                            std::cout << "Choose a different opponent \n";
                            std::cout << " \n";
                        }

                        else if (opponentIndex > 20) { //check if opponent's rank is under 20
                            std::cout << "Opponent does not exist \n";
                            std::cout << "Choose a different opponent \n";
                            std::cout << " \n";
                        }
                        else if (opponentIndex < 1) { //check if opponent's rank is over 1
                            std::cout << "Opponent does not exist \n";
                            std::cout << "Choose a different opponent \n";
                            std::cout << " \n";
                        }

                        else if (opponentIndex == playerRank) { // check to see if player is trying to fight themselves
                            std::cout << "You cannot fight yourself\n";
                            std::cout << "Choose a different opponent\n";
                            std::cout << " \n";
                        }

                        else if ((opponentIndex < (playerRank + 3) ||
                            opponentIndex >
                            (playerRank - 3)) && isChampion == false) { // setting opponent stats if opponent's rank is valid
                            opponentStriking = rankings[opponentIndex].striking;
                            opponentGrappling = rankings[opponentIndex].grappling;
                            opponentConditioning = rankings[opponentIndex].conditioning;
                            opponentName = rankings[opponentIndex].fighterName;

                            opponentTimesFought = rankings[opponentIndex].timesFought;
                            opponentTimesFought++;
                            rankings[opponentIndex].timesFought = opponentTimesFought;
                            opponentRank = inputtedOpponentRank;

                            opponentChosen = true;
                        }

                        else if (opponentIndex <= 5 && isChampion == true) { // setting opponent stats for title defenses

                            opponentStriking = rankings[opponentIndex].striking;
                            opponentGrappling = rankings[opponentIndex].grappling;
                            opponentConditioning = rankings[opponentIndex].conditioning;
                            opponentName = rankings[opponentIndex].fighterName;

                            opponentTimesFought = rankings[opponentIndex].timesFought;
                            opponentTimesFought++;
                            rankings[opponentIndex].timesFought = opponentTimesFought;
                            opponentRank = inputtedOpponentRank;

                            opponentChosen = true;
                        }

                    }

                    else if (inputtedOpponentRank == "C" || inputtedOpponentRank == "c") { //if player chooses champion as opponent

                        if (playerRank < 6) {
                            opponentIndex = 0;
                            opponentStriking = rankings[0].striking;
                            opponentGrappling = rankings[0].grappling;
                            opponentConditioning = rankings[0].conditioning;
                            opponentName = rankings[0].fighterName;

                            opponentTimesFought = rankings[opponentIndex].timesFought;
                            opponentTimesFought++;
                            rankings[opponentIndex].timesFought = opponentTimesFought;
                            opponentRank = "Champion";
                            titleShot = true;
                            opponentChosen = true;

                        }
                        else if (playerRank == 0) {
                            std::cout << "You cannot fight yourself\n";
                            std::cout << "Choose a different opponent\n";
                            std::cout << " \n";
                        }

                        else {
                            std::cout << "You are not eligible for a title shot\n";
                            std::cout << "Choose a different opponent\n";
                            std::cout << " \n";
                        }

                    }
                    

                    else {
                        std::cout << " \n";
                        std::cout << "Opponent does not exist\n";
                        std::cout << "Choose a different opponent\n";
                        std::cout << " \n";
                    }

                }

                defaultPromptChosen = true;
            }

            else if (playerInput == "2") { // sets retired to true if 2 is chosen
                retired = true;
                defaultPromptChosen = true; //retirement prompt
                std::cout << "------------------------------------------\n";
                std::cout << " \n";
                std::cout << "You have retired from the UFC\n";
                std::cout << "Your record: " << wins << "-" << losses << "\n";
                std::cout << "Highest rank: ";
                if (highestRank == 0) {
                    std::cout << "Champion\n";
                }
                else {
                    std::cout << highestRank << "\n";
                }

                std::cout << "Total title defenses: " << totalTitleDefenses << "\n";
                std::cout << " \n";
                std::cout << "------------------------------------------\n";
                return 0;
            }

            else {
                std::cout << "Not an option, try again \n";
            }
        }

        if (opponentIndex <= 5) { //top 5 contenders and champion stats are randomized from 95-100
            opponentStriking = 95 + (rand() % 6);
            opponentGrappling = 95 + (rand() % 6);
            opponentConditioning = 95 + (rand() % 6);
        }

        displayNextOpponent(opponentName, opponentRank);

        remainingWeeks = 6;

        while (remainingWeeks > 0) { // training camp loop
            std::cout << "--------------------------------------------\n";
            std::cout << "You have " << remainingWeeks
                << " weeks of your training camp left \n";
            std::cout << "--------------------------------------------\n";

            playerInput = trainingPrompt();


            if (playerInput == "1") {

                for (int i = 0; i < 4; i++) { //upgrades each striking attack by a random number 1-5
                    rng2 = 1 + (rand() % 5);

                    trainingPoints = playerStrikingAttacks[i].level;
                    trainingPoints += rng2;
                    playerStrikingAttacks[i].level = trainingPoints;

                    if (playerStrikingAttacks[i].level > playerStrikingAttacks[i].maxLevel) {
                        trainingPoints = playerStrikingAttacks[i].maxLevel;
                        playerStrikingAttacks[i].level = trainingPoints;
                    }
                }
                for (int i = 0; i < 4; i++) { //assigning values to display arrays
                    strikeNames[i] = playerStrikingAttacks[i].attackName;
                    strikeLevels[i] = playerStrikingAttacks[i].level;
                }
                rng2 = 1 + (rand() % 5);
                playerStrikingDef += rng2; //player striking defense upgraded by random num 1-5

                if (playerStrikingDef > 100) { // max stat for striking defense
                
                    playerStrikingDef = 100;
                
                }

                displayNewStrikingStats(strikeNames, strikeLevels, playerStrikingDef);

                remainingWeeks--;
            }

            else if (playerInput == "2") {

                for (int i = 0; i < 4; i++) { //upgrades each top grappling attack by a random number 1-5
                    rng2 = 1 + (rand() % 5);
                    trainingPoints = playerTopGroundAttacks[i].level;
                    trainingPoints += rng2;
                    playerTopGroundAttacks[i].level = trainingPoints;

                    if (playerTopGroundAttacks[i].level > playerTopGroundAttacks[i].maxLevel) {
                        trainingPoints = playerTopGroundAttacks[i].maxLevel;
                        playerTopGroundAttacks[i].level = trainingPoints;
                    }
                }

                for (int i = 0; i < 4; i++) { //upgrades each bottom grappling attack by a random number 1-5
                    rng2 = 1 + (rand() % 5);
                    trainingPoints = playerBottomGroundAttacks[i].level;
                    trainingPoints += rng2;
                    playerBottomGroundAttacks[i].level = trainingPoints;

                    if (playerBottomGroundAttacks[i].level > playerBottomGroundAttacks[i].maxLevel) {
                        trainingPoints = playerBottomGroundAttacks[i].maxLevel;
                        playerBottomGroundAttacks[i].level = trainingPoints;
                    }
                }
                rng2 = 1 + (rand() % 5);
                playerTakeDown += rng2; // player takedown/ takedown defense is upgraded by random number 1-5

                if (playerTakeDown > 100) { //max playerTakeDown stat
                    playerTakeDown = 100;
                }


                for (int i = 0; i < 4; i++) { //assigning values to display arrays                        
                    topAttackNames[i] = playerTopGroundAttacks[i].attackName;
                    topAttackLevels[i] = playerTopGroundAttacks[i].level;
                    bottomAttackNames[i] = playerBottomGroundAttacks[i].attackName;
                    bottomAttackLevels[i] = playerBottomGroundAttacks[i].level;
                }

                displayNewGrapplingStats(topAttackNames, bottomAttackNames, topAttackLevels, bottomAttackLevels, playerTakeDown);

                remainingWeeks--;
            }


            else if (playerInput == "3") {
                trainingPoints = 1 + (rand() % 5);
                playerHealth += trainingPoints;
                if (playerHealth > 100) { // setting max value for conditioning to 100
                    playerHealth = 100;
                    
                }
                std::cout << " \n";
                std::cout << "-------------------------\n";
                std::cout << " \n";
                std::cout << "Your conditioning: " << playerHealth << " \n";
                std::cout << " \n";
                std::cout << "-------------------------\n";
                std::cout << "\n";
                remainingWeeks--;
            }
            else if (playerInput == "4") {
                trainingPoints = 1 + (rand() % 5);
                playerStamina += trainingPoints;
                if (playerStamina > 100) { // setting max value for conditioning to 100
                    playerStamina = 100;

                }
                std::cout << " \n";
                std::cout << "-------------------------\n";
                std::cout << " \n";
                std::cout << "Your stamina: " << playerStamina << " \n";
                std::cout << " \n";
                std::cout << "-------------------------\n";
                std::cout << "\n";
                remainingWeeks--;
            }

            else {
                std::cout << "\n";
                std::cout << "Not an option, try again\n";
                std::cout << "\n";
            }



            press_any_key();
        }

        fightCardPrompt(playerName, opponentName, opponentTimesFought, playerRank, opponentIndex, weightClass);
        std::cout << "\n";
        press_any_key();

        //fighting
        //fighting function (normal bout)
        if (titleShot == false && isChampion == false) {
            std::cout << "\n";

            fightResult = fighting(playerStrikingDef, playerTakeDown, playerHealth, opponentStriking, opponentGrappling, opponentConditioning, opponentName,
                strikeNames, strikeLevels, strikeCosts, topAttackNames, topAttackLevels, topAttackCosts, bottomAttackNames, bottomAttackLevels, bottomAttackCosts, isChampion, titleShot, playerStamina);

            std::cout << "\n";
            press_any_key();

            if (fightResult == true) { //adding wins and ranking system
                wins++;

                if (opponentIndex < playerRank) {
                    std::swap(rankings[playerRank], rankings[opponentIndex]);
                }

                else if (opponentIndex > playerRank) {
                    std::swap(rankings[playerRank], rankings[playerRank - 1]);
                }
            }

            else if (fightResult == false) { // adding losses
                losses++;

                if (playerRank == 19 && opponentIndex != 20) {
                    std::swap(rankings[playerRank], rankings[playerRank + 1]);
                    std::swap(rankings[opponentIndex], rankings[opponentIndex - 1]);
                }
                else if (playerRank == 19 && opponentIndex == 20) {
                    std::swap(rankings[playerRank], rankings[opponentIndex]);
                    std::swap(rankings[playerRank], rankings[playerRank - 1]); //opponent goes up (down) 2
                }

                else if (playerRank > opponentIndex && playerRank < 19 && opponentIndex > 3) { //for opponents not in top 3
                    std::swap(rankings[playerRank], rankings[playerRank + 1]); //player rank goes down (up) 2
                    std::swap(rankings[playerRank + 1], rankings[playerRank + 2]);
                    std::swap(rankings[opponentIndex], rankings[opponentIndex - 1]);
                    std::swap(rankings[opponentIndex - 1], rankings[opponentIndex - 2]);
                }

                else if (playerRank > opponentIndex && playerRank < 19 && opponentIndex <= 3 && opponentIndex > 1) { //for opponents in top 3 but not #1 contender
                    std::swap(rankings[playerRank], rankings[playerRank + 1]); //player rank goes down (up) 2
                    std::swap(rankings[playerRank + 1], rankings[playerRank + 2]);
                    std::swap(rankings[opponentIndex], rankings[opponentIndex - 1]);

                }

                else if (opponentIndex == 1) { //if lose to #1 contender
                    std::swap(rankings[playerRank], rankings[playerRank + 1]); //player rank goes down (up) 2
                    std::swap(rankings[playerRank + 1], rankings[playerRank + 2]);

                }

                else if (opponentIndex > playerRank) {
                    std::swap(rankings[playerRank], rankings[opponentIndex]);
                }
            }
        }

        //fighting function for title defenses
        if (titleShot == false && isChampion == true) {

            std::cout << "\n";

            fightResult = fighting(playerStrikingDef, playerTakeDown, playerHealth, opponentStriking, opponentGrappling, opponentConditioning, opponentName,
                strikeNames, strikeLevels, strikeCosts, topAttackNames, topAttackLevels, topAttackCosts, bottomAttackNames, bottomAttackLevels, bottomAttackCosts, isChampion, titleShot, playerStamina);

            if (fightResult == true) {
                wins++;
                titleDefenses++;
                totalTitleDefenses++;
                std::cout << "\n";
                std::cout << "------------------------------------------\n";
                std::cout << "\n";
                std::cout << "You have successfully defended your belt against " << opponentName << "\n";
                std::cout << "\n";
                std::cout << "------------------------------------------\n";
                std::cout << "\n";

                rng = 1 + (rand() % 10);

                if (rng <= 4) {
                    std::swap(rankings[opponentIndex], rankings[opponentIndex + 1]); //opponent's rank goes down by 3
                    std::swap(rankings[opponentIndex + 1], rankings[opponentIndex + 2]);
                    std::swap(rankings[opponentIndex + 2], rankings[opponentIndex + 3]);
                }
                else if (rng > 4 && rng <= 7) {
                    std::swap(rankings[opponentIndex], rankings[opponentIndex + 1]); //opponent's rank goes down by 4
                    std::swap(rankings[opponentIndex + 1], rankings[opponentIndex + 2]);
                    std::swap(rankings[opponentIndex + 2], rankings[opponentIndex + 3]);
                    std::swap(rankings[opponentIndex + 3], rankings[opponentIndex + 4]);
                }
                else if (rng > 7 && rng <= 10) {
                    std::swap(rankings[opponentIndex], rankings[opponentIndex + 1]); //opponent's rank goes down by 5
                    std::swap(rankings[opponentIndex + 1], rankings[opponentIndex + 2]);
                    std::swap(rankings[opponentIndex + 2], rankings[opponentIndex + 3]);
                    std::swap(rankings[opponentIndex + 3], rankings[opponentIndex + 4]);
                    std::swap(rankings[opponentIndex + 4], rankings[opponentIndex + 5]);
                }

            }
            else if (fightResult == false) {
                losses++;
                isChampion = false;
                titleDefenses = 0;
                std::cout << "\n";
                std::cout << "------------------------------------------\n";
                std::cout << "\n";
                std::cout << opponentName << " is the new undisputed " << weightClass << " champion!\n";
                std::cout << "\n";
                std::cout << "------------------------------------------\n";
                std::cout << "\n";


                std::swap(rankings[playerRank], rankings[opponentIndex]); //player rank goes down by 3
                std::swap(rankings[opponentIndex], rankings[opponentIndex + 1]);
                std::swap(rankings[opponentIndex + 1], rankings[opponentIndex + 2]);

            }
            press_any_key();

        }

        //fighting function (titleshot fight)
        if (titleShot == true && isChampion == false) {
            std::cout << "\n";

            fightResult = fighting(playerStrikingDef, playerTakeDown, playerHealth, opponentStriking, opponentGrappling, opponentConditioning, opponentName,
                strikeNames, strikeLevels, strikeCosts, topAttackNames, topAttackLevels, topAttackCosts, bottomAttackNames, bottomAttackLevels, bottomAttackCosts, isChampion, titleShot, playerStamina);

            if (fightResult == true) { //adding wins and ranking system 

                wins++;
                std::cout << "\n";
                std::cout << "------------------------------------------\n";
                std::cout << "\n";
                std::cout << "You are the new undisputed " << weightClass << " champion!\n";
                std::cout << "\n";
                std::cout << "------------------------------------------\n";
                std::cout << "\n";

                std::swap(rankings[playerRank], rankings[opponentIndex]); //opponent rank goes down by 4
                std::swap(rankings[playerRank], rankings[playerRank + 1]);
                std::swap(rankings[playerRank + 1], rankings[playerRank + 2]);
                std::swap(rankings[playerRank + 2], rankings[playerRank + 3]);

                isChampion = true;
                titleDefenses = 0;



            }

            else if (fightResult == false) { // adding losses
                losses++;

                std::cout << "\n";



                std::swap(rankings[playerRank], rankings[playerRank + 1]); //going down ranking by 2
                std::swap(rankings[playerRank + 1], rankings[playerRank + 2]);

            }
            titleShot = false;
            press_any_key();
        }

        //randomized rankings
        randomRank = false;



        while (randomRank == false) {

            rng = rand() % 20;

            if (playerRank != rng && playerRank + 1 != rng) {
                std::swap(rankings[rng], rankings[rng + 1]);
                randomRank = true;
            }

        }






    }

    }
