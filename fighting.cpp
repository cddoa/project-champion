#include "fighting.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "prompts.h"

bool fighting(int playerStriking, int playerGrappling, int playerConditioning, int opponentStriking, int opponentGrappling, int opponentConditioning, std::string opponentName,
    std::string strikeNames[], int strikeLevels[], int strikeCosts[], std::string topAttackNames[], int topAttackLevels[], int topAttackCosts[], std::string bottomAttackNames[], int bottomAttackLevels[], int bottomAttackCosts[],
    bool isChampion, bool titleShot, int playerStamina) {

    int rng;
    int rng2;
    int damageDone;
    std::string playerInput;
    bool standing;
    bool onGroundTop ;
    bool onGroundBottom ;
    bool attackTurnUsed ;
    bool opponentAttackTurnUsed ;
    int playerHealth = playerConditioning;
    int opponentHealth = opponentConditioning;
    int rounds;
    int attackChosen;
    bool selectionValid = false;
    int opponentAttackChosen;
    bool firstPromptSelected;
    std::string temp;
    int maxStamina = playerStamina;
    int wrongSelectCounter;
    bool wrongSelection;

    std::string opponentStrikes[6] = {"Right Hook", "Left Hook", "Liver Hook", "Head Kick", "Right Overhand", "Body Kick"};
    std::string opponentSubmissionsTop[3] = {"Arm Bar", "Arm Triangle", "Rear Naked Choke"};
    std::string opponentSubmissionsBottom[3] = {"Arm Bar", "Triangle Choke", "Guillotine Choke"};

    srand(time(nullptr));

    if (isChampion == true || titleShot == true) {
        rounds = 5;
    }
    else {
        rounds = 3;
    }
    

        for (int i = 1; i <= rounds; i++) { //3 or 5 rounds depends on what type of bout it is 
                
            standing = true; //round always starts standing
            onGroundTop = false;
            onGroundBottom = false;

            wrongSelectCounter = 0;
            wrongSelection = false;

            if (i > 1) { // player can recover up to 20 stamina at the beginning of each round after the 1st
                rng = 1 + (rand() % 20);

                playerStamina += rng;

                if (playerStamina > maxStamina) {
                    playerStamina = maxStamina;
                }
            }


            std::cout << "\n";
            std::cout << "--------\n";
            std::cout << "ROUND " << i << "\n";
            std::cout << "--------\n";
            std::cout << "\n";
            std::cout << opponentName << "'s" << " Health: " << opponentHealth << "\n";
            std::cout << "\n";
            std::cout << "Your Health: " << playerHealth << "\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "Your Stamina: " << playerStamina<< "\n";
            
            attackTurnUsed = false;

            //first phase
            firstPromptSelected = false;

            while (firstPromptSelected == false) {
                playerInput = firstFightPrompt(); //standing/takedown prompt at the beginning of each round

                std::cout << "\n";

                if (playerInput == "1") { //keep fight standing

                    standing = true;
                    onGroundBottom = false;
                    onGroundTop = false;

                    firstPromptSelected = true;

                }
                else if (playerInput == "2") { //player shoots takedown

                    std::cout << "You shot a takedown\n";
                    std::cout << "\n";

                    if (playerGrappling > opponentGrappling) { //if player grappling is better
                        rng = 1 + (rand() % 100);

                        if (rng <= 45) { // lands takedown, position switch
                            std::cout << "\n";
                            std::cout << "You took down " << opponentName << " with a double leg \n";
                            std::cout << "\n";
                            standing = false;
                            onGroundBottom = false;
                            onGroundTop = true;
                            rng2 = 1 + (rand() % 5);
                            opponentHealth -= rng2;
                            std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                            std::cout << "\n";
                            firstPromptSelected = true;
                        }
                        else if (rng > 45 && rng <= 85) { // lands takedown, position switch
                            std::cout << "\n";
                            std::cout << "You took down " << opponentName << " with a single leg \n";
                            std::cout << "\n";
                            standing = false;
                            onGroundBottom = false;
                            onGroundTop = true;
                            rng2 = 1 + (rand() % 5);
                            opponentHealth -= rng2;
                            std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                            std::cout << "\n";
                            firstPromptSelected = true;
                        }
                        else if (rng > 85 && rng <= 100) { // opponent defends takedown takedown
                            std::cout << "\n";
                            std::cout << opponentName << " defended your takedown \n";
                            std::cout << "\n";
                            standing = true;
                            onGroundBottom = false;
                            onGroundTop = false;
                            rng2 = 1 + (rand() % 5);
                            playerHealth -= rng2;
                            std::cout << "Your Health: " << playerHealth << "\n";
                            std::cout << "\n";
                            firstPromptSelected = true;
                        }


                    }


                    if (playerGrappling <= opponentGrappling) { //if opponent grappling is better
                        rng = 1 + (rand() % 100);

                        if (rng <= 30) { // lands takedown, position switch
                            std::cout << "You took down " << opponentName << " with a double leg \n";
                            std::cout << "\n";
                            standing = false;
                            onGroundBottom = false;
                            onGroundTop = true;
                            rng2 = 1 + (rand() % 5);
                            opponentHealth -= rng2;
                            std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                            firstPromptSelected = true;
                        }
                        else if (rng > 30 && rng <= 70) { // does not land takedown
                            std::cout << opponentName << " defended your takedown \n";
                            std::cout << "\n";
                            standing = true;
                            onGroundBottom = false;
                            onGroundTop = false;
                            rng2 = 1 + (rand() % 5);
                            playerHealth -= rng2;
                            std::cout << "Your Health: " << playerHealth << "\n";
                            std::cout << "\n";
                            firstPromptSelected = true;
                        }
                        else if (rng > 70 && rng <= 100) { // opponent defends takedown and is on top of you, position switch
                            std::cout << opponentName << " defended your takedown and has gotten on top of you\n";
                            std::cout << "\n";
                            standing = false;
                            onGroundBottom = true;
                            onGroundTop = false;
                            rng2 = 1 + (rand() % 5);
                            playerHealth -= rng2;
                            std::cout << "Your Health: " << playerHealth << "\n";
                            std::cout << "\n";
                            firstPromptSelected = true;
                        }


                    }

                }
                else {

                    std::cout << "\n";
                    std::cout << "Not an option\n";
                    std::cout << "\n";

                }
            }

                //opponent takedown phase
                if (standing == true) {

                    if (playerGrappling < opponentGrappling + 6 ) { //opponent won't shoot takedown if grappling is significantly worse
                    
                        rng = 1 + (rand() % 100);

                        if (rng <= 60) { //they shoot a takedown
                            std::cout << opponentName << " shoots a takedown\n";
                            std::cout << "\n";

                            rng2 = 1 + (rand() % 100);

                            if (playerGrappling < rng2) { //opponent lands takedown if player takedown defense is less than the random number
                                std::cout << opponentName << " has taken you down and is on top of you\n";
                                std::cout << "\n";
                                standing = false;
                                onGroundBottom = true;
                                onGroundTop = false;
                            }
                            else if (playerGrappling > rng2) { //opponent takedown does not land
                                std::cout << " You defend the takedown\n";
                                std::cout << "\n";
                                standing = true;
                                onGroundBottom = false;
                                onGroundTop = false;
                            }
                        
                        }
                        else if (rng > 60 && rng <= 100) { //does not shoot takedown
                            standing = true;
                            onGroundBottom = false;
                            onGroundTop = false;
                                               
                        }                   
                    }
                }

                // player attack phase

                while (attackTurnUsed == false) {
                
                    selectionValid = false;

                    if (standing == true) { //standing combat
                    
                        onGroundBottom = false;
                        onGroundTop = false;

                        while (selectionValid == false) {

                            std::cout << "\n";
                            std::cout << "Your Stamina: " << playerStamina << "\n";
                            std::cout << "\n";
                            std::cout << "---------------------------\n";
                            std::cout << "Attack - Cost \n";
                            std::cout << "\n";
                            for (int i = 1; i <= 4; i++) { //displays attacks and their costs

                                if (strikeNames[i-1] == " ") {
                                    std::cout << "\n";
                                }
                                else {
                                    std::cout << i << ". " << strikeNames[i - 1] << " - " << strikeCosts[i - 1] << "\n";
                                }
                            }
                            std::cout << "\n";
                            std::cout << "---------------------------\n";
                            std::cout << "\n";
                            getline(std::cin, playerInput);

                            if (playerInput == "1" || playerInput == "2" || playerInput == "3" || playerInput == "4") {     //if player selection is valid                   
                                attackChosen = (std::stoi(playerInput));
                                attackChosen --;

                                if (strikeNames[attackChosen] == " " || strikeCosts[attackChosen] > playerStamina) {
                                
                                    std::cout << "\n";
                                    std::cout << "Not an option\n";
                                    std::cout << "\n";
                                    wrongSelectCounter ++;

                                    if (wrongSelectCounter > 1){ //player chooses invalid option twice

                                        wrongSelection = true;
                                        selectionValid = true;
                                        attackTurnUsed = true;

                                       // break;
                                 }
                                
                                } 
                                else {
                                    selectionValid = true;
                                }
                                                                                                
                            }
                            else {
                                std::cout << "\n";
                                std::cout << "Not an option\n";
                                std::cout << "\n";
                            }

                        }

                        
                   
                        if (wrongSelection == false){
                           if (strikeLevels[attackChosen] > opponentStriking) { //if the attack's level is greater than the opponent's striking
                               rng = 1 + (rand() % 100);

                               if (rng <= 25) {
                                   std::cout << "\n";
                                   std::cout << "Your " << strikeNames[attackChosen] <<  " wobbled " << opponentName <<"!\n";
                                   std::cout << "\n";
                                   rng2 = rand() % (strikeLevels[attackChosen] / 2); 
                                   damageDone = strikeLevels[attackChosen] - rng2; //critical hit
                                   opponentHealth -= damageDone;
                                   opponentHealth = healthCheck(opponentHealth);
                                   std::cout << "You did " << damageDone <<" damage\n";
                                   std::cout << "\n";
                                   std::cout << opponentName <<"'s Health: " << opponentHealth << "\n";
                                   std::cout << "\n";
                                   onGroundTop = false;
                                   onGroundBottom = false;
                                   standing = true;
                                   break;
                                  // attackTurnUsed = true;

                               }

                               else if (rng > 25 && rng <= 75) {
                                   std::cout << "\n";
                                   std::cout << "Your " << strikeNames[attackChosen] << " landed clean!\n";
                                   std::cout << "\n";                                    
                                   damageDone = rand() % 1 + (strikeLevels[attackChosen] / 2);
                                   opponentHealth -= damageDone;
                                   opponentHealth = healthCheck(opponentHealth);
                                   std::cout << "You did " << damageDone << " damage\n";
                                   std::cout << "\n";
                                   std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                                   std::cout << "\n";
                                   onGroundTop = false;
                                   onGroundBottom = false;
                                   standing = true;
                                   break;
                                  // attackTurnUsed = true;
                               }

                               else if (rng > 75 && rng <= 100) {
                                   std::cout << "\n";
                                   std::cout << "Your " << strikeNames[attackChosen] << " was dodged!\n";
                                   std::cout << "\n";
                                   damageDone = 1 + (rand() % 5);
                                   playerHealth -= damageDone;
                                   std::cout << "Your Health: " << playerHealth << "\n";
                                   std::cout << "\n";
                                   onGroundTop = false;
                                   onGroundBottom = false;
                                   standing = true;
                                   break;
                                   //attackTurnUsed = true;
                               
 
                               }


                           }
                           else if(strikeLevels[attackChosen] <= opponentStriking) {//if the attack's level is less than the opponent's striking
                               rng = 1 + (rand() % 100);

                               if (rng <= 30) {
                                   std::cout << "\n";
                                   std::cout << "Your " << strikeNames[attackChosen] << " landed clean!\n";
                                   std::cout << "\n";                                                                      
                                   damageDone = rand() % 1 + (strikeLevels[attackChosen] / 2);
                                   opponentHealth -= damageDone;
                                   opponentHealth = healthCheck(opponentHealth);
                                   std::cout << "You did " << damageDone << " damage\n";
                                   std::cout << "\n";
                                   std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                                   std::cout << "\n";
                                   onGroundTop = false;
                                   onGroundBottom = false;
                                   standing = true;
                                   break;
                                   //attackTurnUsed = true;
                               }
                               else if (rng > 30 && rng <= 65) {
                                   std::cout << "\n";
                                   std::cout << "Your " << strikeNames[attackChosen] << " was mostly blocked!\n";
                                   std::cout << "\n";
                                   damageDone = (strikeLevels[attackChosen] / 4);
                                   opponentHealth -= damageDone;
                                   opponentHealth = healthCheck(opponentHealth);
                                   std::cout << "You did " << damageDone << " damage\n";
                                   std::cout << "\n";
                                   std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                                   std::cout << "\n";
                                   onGroundTop = false;
                                   onGroundBottom = false;
                                   standing = true;
                                   break; 
                                   //attackTurnUsed = true;
                               }
                               else if (rng > 65 && rng <= 70) {
                                   std::cout << "\n";
                                   std::cout << "Your " << strikeNames[attackChosen] << " wobbled " << opponentName << "!\n";
                                   std::cout << "\n";
                                   rng2 = rand() % (strikeLevels[attackChosen] / 2);
                                   damageDone = strikeLevels[attackChosen] - rng2; //critical hit
                                   opponentHealth -= damageDone;
                                   opponentHealth = healthCheck(opponentHealth);
                                   std::cout << "You did " << damageDone << " damage\n";
                                   std::cout << "\n";
                                   std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                                   std::cout << "\n";
                                   onGroundTop = false;
                                   onGroundBottom = false;
                                   standing = true;
                                   break;
                                  // attackTurnUsed = true;                                                                                             
                               }
                               else if (rng > 70 && rng <= 100) {
                                   std::cout << "\n";
                                   std::cout << "Your " << strikeNames[attackChosen] << " was dodged!\n";
                                   std::cout << "\n";
                                   rng2 = 1 + (rand() % 5);
                                   playerHealth -= rng2;
                                   std::cout << "Your Health: " << playerHealth << "\n";
                                   std::cout << "\n";
                                   onGroundTop = false;
                                   onGroundBottom = false;
                                   standing = true;
                                   break;
                                   //attackTurnUsed = true;
                               }                                                     
                           }

                        }
                    }
                                                           

                    else if (onGroundTop == true) { //ground combat (top)

                        selectionValid = false;

                       
                        while (selectionValid == false) {

                            std::cout << "\n";
                            std::cout << "Your Stamina: " << playerStamina << "\n";
                            std::cout << "\n";
                            std::cout << "---------------------------\n";
                            std::cout << "Attack - Cost\n";
                            std::cout << "\n";

                            for (int i = 1; i <= 4; i++) { //displays attacks
                                if (topAttackNames[i - 1] == " ") {
                                    std::cout << "\n";
                                }
                                else {
                                    std::cout << i << ". " << topAttackNames[i - 1] << " - " << topAttackCosts[i - 1] << "\n";
                                }

                            }
                            std::cout << "\n";
                            std::cout << "---------------------------\n";
                            std::cout << "\n";

                            getline(std::cin, playerInput);

                            if (playerInput == "1" || playerInput == "2" || playerInput == "3" || playerInput == "4") {     //if player selection is valid                   
                                attackChosen = (std::stoi(playerInput));
                                attackChosen--;
                            
                                if (topAttackNames[attackChosen] == " " || topAttackCosts[attackChosen] > playerStamina) {

                                    std::cout << "\n";
                                    std::cout << "Not an option\n";
                                    std::cout << "\n";
                                    wrongSelectCounter ++;

                                    if (wrongSelectCounter > 1){ //player chooses invalid option twice

                                        wrongSelection = true;
                                        selectionValid = true;
                                        attackTurnUsed = true;

                                       // break;
                                 }

                                }

                                else {
                                    selectionValid = true;
                                }

                            }
                            else {
                                std::cout << "\n";
                                std::cout << "Not an option\n";
                                std::cout << "\n";
                            }

                        }

                    if (wrongSelection == false){
                        if (topAttackLevels[attackChosen] > opponentGrappling) { //if level of attack is greater than the opponent's grappling
                        
                            if (attackChosen == 0) { //ground and pound

                                rng = 1 + (rand() % 100);

                                if (rng <= 40) { // damage done is greater than half of the attack's level

                                    rng2 = rand() % (topAttackLevels[attackChosen] / 2);
                                    damageDone = topAttackLevels[attackChosen] - rng2;
                                    opponentHealth -= damageDone;
                                    opponentHealth = healthCheck(opponentHealth);
                                    std::cout << "\n";
                                    std::cout << "You ground and pounded " << opponentName << "\n";
                                    std::cout << "\n";
                                    std::cout << "You did " << damageDone << " damage\n";
                                    std::cout << "\n";
                                    std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                                    std::cout << "\n";
                                    onGroundTop = true;
                                    onGroundBottom = false;
                                    standing = false;
                                    break;
                                    //attackTurnUsed = true;
                                }
                                else if (rng > 40 && rng <= 100) { //damage done is less than half of the attack's level
                                    damageDone = rand() % (topAttackLevels[attackChosen] / 2);                                    
                                    opponentHealth -= damageDone;
                                    opponentHealth = healthCheck(opponentHealth);
                                    std::cout << "\n";
                                    std::cout << "You ground and pounded " << opponentName << "\n";
                                    std::cout << "\n";
                                    std::cout << "You did " << damageDone << " damage\n";
                                    std::cout << "\n";
                                    std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                                    std::cout << "\n";
                                    onGroundTop = true;
                                    onGroundBottom = false;
                                    standing = false;
                                    break;
                                    //attackTurnUsed = true;
                                
                                }
                            }
                            else { // submissions
                                std::cout << "\n";
                                rng = 1 + (rand() % 100);
                                
                                if (rng <= 70) { //submits opponent
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    std::cout << "You Won against " << opponentName <<" via Round " << i << " " << topAttackNames[attackChosen] << "\n";
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    return true; //returns win
                                }
                                else if (rng > 70 && rng <= 100) { //opponent escapes, position swtich
                                    std::cout << "\n";
                                    std::cout << opponentName << " escapes your " << topAttackNames[attackChosen] <<  " attempt\n";
                                    std::cout << "\n";
                                    std::cout << "You are now back on your feet\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";

                                    

                                    onGroundTop = false;
                                    onGroundBottom = false;
                                    standing = true;

                                    break;
                                }
                            
                            
                            }
                        }
                        else if (topAttackLevels[attackChosen] <= opponentGrappling) { //if level of attack is less than the opponent's grappling

                            if (attackChosen == 0) { //ground and pound                                
                                damageDone = rand() % 1 + (topAttackLevels[attackChosen] / 2);
                                opponentHealth -= damageDone;
                                opponentHealth = healthCheck(opponentHealth);
                                std::cout << "\n";
                                std::cout << "You ground and pounded " << opponentName << "\n";
                                std::cout << "\n";
                                std::cout << "You did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << opponentName << "'s Health: " << opponentHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = true;
                                onGroundBottom = false;
                                standing = false;
                                break;
                                //attackTurnUsed = true;
                            }
                            else {

                                std::cout << "\n";
                                rng = 1 + (rand() % 100);

                                if (rng <= 20) { //submits opponent
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    std::cout << "You Won against " << opponentName << " via Round " << i << " " << topAttackNames[attackChosen] << "\n";
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    return true; //returns win
                                }
                                else if (rng > 20 && rng <= 70) { // position switch
                                    std::cout << "\n";
                                    std::cout << opponentName << " escapes your " << topAttackNames[attackChosen] << " attempt \n";
                                    std::cout << "\n";
                                    std::cout << opponentName << " is now on top of you in full mount\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 10);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    onGroundBottom = true;
                                    onGroundTop = false;
                                    standing = false;
                                    break;
                                    //attackTurnUsed = true;   
                                }
                                else if (rng > 70 && rng <= 100) { // position switch
                                    std::cout << "\n";
                                    std::cout << opponentName << " escapes your " << topAttackNames[attackChosen] << " attempt \n";
                                    std::cout << "\n";
                                    std::cout << "You are now back on your feet\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    onGroundBottom = false;
                                    onGroundTop = false;
                                    standing = true;
                                    break;
                                    //attackTurnUsed = true;

                                    
                                }
                            }
                        }
                    }
                    }

                    if (onGroundBottom == true) { //ground combat (bottom)
                  
                        while (selectionValid == false) {
                            std::cout << "\n";
                            std::cout << "Your Stamina: " << playerStamina<< "\n";
                            std::cout << "\n";
                            std::cout << "---------------------------\n";
                            std::cout << "Attack - Cost\n";
                            std::cout << "\n";
                            for (int i = 1; i <= 4; i++) { //displays attacks

                                if (bottomAttackNames[i - 1] == " ") {
                                    std::cout << "\n";
                                }
                                else {
                                    std::cout << i << ". " << bottomAttackNames[i - 1] << " - " << bottomAttackCosts[i - 1] << "\n";
                                }

                            }
                            std::cout << "\n";
                            std::cout << "---------------------------\n";
                            std::cout << "\n";

                            getline(std::cin, playerInput);
                            std::cout << "\n";
                            if (playerInput == "1" || playerInput == "2" || playerInput == "3" || playerInput == "4") {     //if player selection is valid                   
                                attackChosen = (std::stoi(playerInput));
                                attackChosen--;

                                if (bottomAttackNames[attackChosen] == " " || bottomAttackCosts[attackChosen] > playerStamina) {

                                    std::cout << "\n";
                                    std::cout << "Not an option\n";
                                    std::cout << "\n";
                                    wrongSelectCounter ++;

                                    if (wrongSelectCounter > 1){ //player chooses invalid option twice

                                        wrongSelection = true;
                                        selectionValid = true;
                                        attackTurnUsed = true;

                                       // break;
                                 }

                                }
                                else {
                                    selectionValid = true;
                                }

                            }
                            else {
                                std::cout << "\n";
                                std::cout << "Not an option\n";
                                std::cout << "\n";
                            }

                        }


                    if (wrongSelection == false){
                        if (bottomAttackLevels[attackChosen] > opponentGrappling ) { //if attack level is greater than opponent's grappling
                        
                            if (bottomAttackNames[attackChosen] == "Get Up") { //if player tries to get up
                            
                                rng = 1 + (rand() % 100);
                                if (rng <= 85) { //position switch
                                    std::cout << "\n";
                                    std::cout << "You were able to get up\n";
                                    std::cout << "\n";
                                    std::cout << "You are now back on your feet\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth <<"\n";
                                    standing = true;
                                    onGroundBottom = false;
                                    onGroundTop = false;
                                }
                                else if (rng > 85 && rng <= 100) {
                                    std::cout << "\n";
                                    std::cout << "You were not able to get up\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 10);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    std::cout << "\n";
                                    standing = false;
                                    onGroundBottom = true;
                                    onGroundTop = false;
                                    break;
                                   // attackTurnUsed = true; //failing get up attempt uses attack turn
                                }
                            
                            }
                            else if(bottomAttackNames[attackChosen] == "Get On Top") { //if player tries to get on top
                            
                                rng = 1 + (rand() % 100);
                                if (rng <= 80) { //position switch
                                    std::cout << "\n";
                                    std::cout << "You were able to sweep " << opponentName << " off of you\n";
                                    std::cout << "\n";
                                    std::cout << "You are now on top of " << opponentName << " in full mount\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    standing = false;
                                    onGroundBottom = false;
                                    onGroundTop = true;
                                }
                                else if (rng > 80 && rng <= 100) {
                                    std::cout << "\n";
                                    std::cout << "You were not able to get on top\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 10);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    std::cout << "\n";
                                    standing = false;
                                    onGroundBottom = true;
                                    onGroundTop = false;
                                    break;
                                    //attackTurnUsed = true; //failing get on top attempt uses attack turn
                                }                            
                            }

                            else { //not "get on top" or "get up" (submissions)
                                std::cout << "\n";
                                rng = 1 + (rand() % 100);

                                if (rng <= 70) { //submits opponent
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    std::cout << "You Won against " << opponentName << " via Round " << i << " " << bottomAttackNames[attackChosen] << "\n";
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    return true; //returns win
                                }
                                else if (rng > 70 && rng <= 100) { //opponent escapes, position swtich
                                    std::cout << "\n";
                                    std::cout << opponentName << " escapes your " << bottomAttackNames[attackChosen] << " attempt\n";
                                    std::cout << "\n";
                                    std::cout << "You are now back on your feet\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";

                                    onGroundTop = false;
                                    onGroundBottom = false;
                                    standing = true;
                                    break;
                                    //attackTurnUsed = true;

                                    
                                }
                            
                            }                        
                        }

                        else if (bottomAttackLevels[attackChosen] <= opponentGrappling) { //if attack's level is less than opponent's grappling
                        
                            if (bottomAttackNames[attackChosen] == "Get Up") { //if player tries to get up

                                rng = 1 + (rand() % 100);
                                if (rng <= 30) { //position switch
                                    std::cout << "\n";
                                    std::cout << "You were able to get up\n";
                                    std::cout << "\n";
                                    std::cout << "You are now back on your feet\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    standing = true;
                                    onGroundBottom = false;
                                    onGroundTop = false;
                                }
                                else if (rng > 30 && rng <= 100) {
                                    std::cout << "\n";
                                    std::cout << "You were not able to get up\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 10);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    std::cout << "\n";
                                    standing = false;
                                    onGroundBottom = true;
                                    onGroundTop = false;
                                    break;
                                   // attackTurnUsed = true; //failing get up attempt uses attack turn
                                }

                            }
                            else if (bottomAttackNames[attackChosen] == "Get On Top") { //if player tries to get on top

                                rng = 1 + (rand() % 100);
                                if (rng <= 20) { //position switch
                                    std::cout << "\n";
                                    std::cout << "You were able to sweep " << opponentName << " off of you\n";
                                    std::cout << "\n";
                                    std::cout << "You are now on top of " << opponentName << " in full mount\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    std::cout << "\n";
                                    standing = false;
                                    onGroundBottom = false;
                                    onGroundTop = true;
                                }
                                else if (rng > 20 && rng <= 100) {
                                    std::cout << "\n";
                                    std::cout << "You were not able to get on top\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 10);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    std::cout << "\n";
                                    standing = false;
                                    onGroundBottom = true;
                                    onGroundTop = false;
                                    break;
                                    //attackTurnUsed = true; //failing get on top attempt uses attack turn
                                }
                            }

                            else { //submissions
                            
                                std::cout << "\n";
                                rng = 1 + (rand() % 100);

                                if (rng <= 20) { //submits opponent
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    std::cout << "You Won against " << opponentName << " via Round " << i << " " << bottomAttackNames[attackChosen] << "\n";
                                    std::cout << "\n";
                                    std::cout << "----------------------------------------------------------------------------\n";
                                    std::cout << "\n";
                                    return true; //returns win
                                }
                                else if (rng > 20 && rng <= 100) { //opponent escapes
                                    std::cout << "\n";
                                    std::cout << opponentName << " escapes your " << bottomAttackNames[attackChosen] << " attempt\n";
                                    std::cout << "\n";
                                    std::cout << opponentName <<" is still on top of you\n";
                                    std::cout << "\n";
                                    rng2 = 1 + (rand() % 5);
                                    playerHealth -= rng2;
                                    std::cout << "Your Health: " << playerHealth << "\n";
                                    std::cout << "\n";
                                    onGroundTop = false;
                                    onGroundBottom = true;
                                    standing = false;
                                    break;
                                   // attackTurnUsed = true; 
                                }                            
                            }
                       
                        }                                                                                
                     }
                }
            }

                  press_any_key();
               //  

                  //error check
                  if (standing == false && onGroundTop == false && onGroundBottom == false) {
                      std::cout << "\n";
                      std::cout << "You are back on your feet\n";
                      std::cout << "\n";
                      standing = true;
                      onGroundBottom = false;
                      onGroundTop = false;                                 
                  }

                //opponent health check

                if (opponentHealth <= 0) {

                    rng = 1 + (rand() % 100);
                
                    if (rng > (opponentConditioning / 2)) {

                        rng2 = 1 + (rand() % 100);

                        if (rng2 <= 55) {
                            std::cout << "\n";
                            std::cout << "----------------------------------------------------------------------------\n";
                            std::cout << "\n";
                            std::cout << "You Won against " << opponentName << " via Round " << i << " KO\n";
                            std::cout << "\n";
                            std::cout << "----------------------------------------------------------------------------\n";
                            std::cout << "\n";
                            return true;
                        }
                        else if (rng2 > 55) {
                            std::cout << "\n";
                            std::cout << "----------------------------------------------------------------------------\n";
                            std::cout << "\n";
                            std::cout << "You Won against " << opponentName << " via Round " << i << " TKO\n";
                            std::cout << "\n";
                            std::cout << "----------------------------------------------------------------------------\n";
                            std::cout << "\n";
                            return true;
                        }
                    }

                    else { //recovery
                        std::cout << "\n";
                        std::cout << "You knocked down " << opponentName << " but they recovered!\n";
                        std::cout << "\n";
                        opponentHealth = 1 + (rand() % 20);
                        std::cout << opponentName <<  "'s health: " << opponentHealth <<"\n";
                        std::cout << "\n";

                    
                    }

                }
                

            //opponent attack phase
                opponentAttackTurnUsed = false;


                while (opponentAttackTurnUsed == false) {

                    if (standing == true) { //standing combat - opponent turn

                        opponentAttackChosen = rand() % 6;

                        if (opponentStriking > playerStriking) {

                            rng = 1 + (rand() % 100);

                            if (rng <= 40) {
                                std::cout << "\n";
                                std::cout << opponentName << " threw a " << opponentStrikes[opponentAttackChosen] << " which wobbled you!\n";
                                std::cout << "\n";
                                rng2 = rand() % (opponentStriking / 2); //critical hit
                                damageDone = opponentStriking - rng2;
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = false;
                                standing = true;
                                break;
                                //opponentAttackTurnUsed = true;
                            }
                            else if (rng > 40 && rng <= 100) {
                                std::cout << "\n";
                                std::cout << opponentName << " threw a " << opponentStrikes[opponentAttackChosen] << " which landed clean!\n";
                                std::cout << "\n";
                                damageDone = rand() % 1 + (opponentStriking / 2);
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = false;
                                standing = true;
                                break;
                               // opponentAttackTurnUsed = true;
                            }
                        }
                        else if (opponentStriking <= playerStriking) {

                            rng = 1 + (rand() % 100);

                            if (rng <= 20) {
                                std::cout << "\n";
                                std::cout << opponentName << " threw a " << opponentStrikes[opponentAttackChosen] << " which wobbled you!\n";
                                std::cout << "\n";
                                rng2 = rand() % (opponentStriking / 2); //critical hit
                                damageDone = opponentStriking - rng2;
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = false;
                                standing = true;
                                break;
                                //opponentAttackTurnUsed = true;
                            }
                            else if (rng > 20 && rng <= 40) {
                                std::cout << "\n";
                                std::cout << opponentName << " threw a " << opponentStrikes[opponentAttackChosen] << " which you mostly blocked\n";
                                std::cout << "\n";
                                damageDone = 1 + (rand() % (opponentStriking / 4));
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = false;
                                standing = true;
                                break;
                               // opponentAttackTurnUsed = true;
                            }
                            else if (rng > 40 && rng <= 70) {
                                std::cout << "\n";
                                std::cout << opponentName << " threw a " << opponentStrikes[opponentAttackChosen] << " which landed clean!\n";
                                std::cout << "\n";
                                damageDone = rand() % 1 + (opponentStriking / 2);
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = false;
                                standing = true;
                                break;
                                //opponentAttackTurnUsed = true;
                            }
                            else if (rng > 70 && rng <= 100) {
                                std::cout << "\n";
                                std::cout << opponentName << " threw a " << opponentStrikes[opponentAttackChosen] << " which you dodged!\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = false;
                                standing = true;
                                break;
                               // opponentAttackTurnUsed = true;
                            }
                        }
                    }

                    else if (onGroundBottom == true) { //ground combat(player on bottom) - opponent turn
                    
                        opponentAttackChosen = rand() % 3;

                        if (opponentGrappling > playerGrappling) {
                        
                            rng = 1 + (rand() % 100);

                            if (rng <= 20) {
                                std::cout << "\n";
                                std::cout << opponentName << " ground and pounded you! \n";
                                std::cout << "\n";
                                rng2 = rand() % 1 + (opponentGrappling / 2);
                                damageDone = opponentGrappling - rng2;
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = true;
                                standing = false;
                                break;
                                //opponentAttackTurnUsed = true;                            
                            }
                            else if (rng > 20 && rng <= 40) {
                                std::cout << "\n";
                                std::cout << opponentName << " ground and pounded you! \n";
                                std::cout << "\n";
                                damageDone = rand() % 1 + (opponentGrappling / 2);                                
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = true;
                                standing = false;
                                break;
                                //opponentAttackTurnUsed = true;
                            
                            }
                            else if (rng > 40 && rng <= 60) { //submission attempt 
                                std::cout << "\n";
                                std::cout << opponentName << " attempted an " << opponentSubmissionsTop[opponentAttackChosen] << " which you escaped!\n";
                                std::cout << "\n";                                
                                damageDone = 1 + (rand() % 5);
                                playerHealth -= damageDone;
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                break;
                                //opponentAttackTurnUsed = true;
                            }
                            else if (rng > 60 && rng <= 100) { //player gets submitted
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                std::cout << "You Lost against " << opponentName << " via Round " << i << " " << opponentSubmissionsTop[opponentAttackChosen] <<"\n";
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                return false;                                                        
                            }
                        
                        }

                        else if (opponentGrappling <= playerGrappling) { 
                        
                            rng = 1 + (rand() % 100);

                            if (rng <= 30 ) {
                                std::cout << "\n";
                                std::cout << opponentName << " ground and pounded you! \n";
                                std::cout << "\n";
                                damageDone = rand() % 1 + (opponentGrappling / 2);
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = true;
                                standing = false;
                                break;
                               // opponentAttackTurnUsed = true;

                            }
                            else if (rng > 30 && rng <= 60) {
                                std::cout << "\n";
                                std::cout << opponentName << " ground and pounded you! \n";
                                std::cout << "\n";
                                damageDone = rand() % 1 + (opponentGrappling / 4);
                                playerHealth -= damageDone;
                                playerHealth = healthCheck(playerHealth);
                                std::cout << "It did " << damageDone << " damage\n";
                                std::cout << "\n";
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                onGroundTop = false;
                                onGroundBottom = true;
                                standing = false;
                                break;
                                //opponentAttackTurnUsed = true;                                                        
                            }

                            else if (rng > 60 && rng <= 75) {
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                std::cout << "You Lost against " << opponentName << " via Round " << i << " " << opponentSubmissionsTop[opponentAttackChosen] << "\n";
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                return false;
                            
                            }
                            else if (rng > 75 && rng <= 100) {
                                std::cout << "\n";
                                std::cout << opponentName << " attempted an " << opponentSubmissionsTop[opponentAttackChosen] << " which you escaped!\n";
                                std::cout << "\n";
                                damageDone = 1 + (rand() % 5);
                                playerHealth -= damageDone;
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                break;
                               // opponentAttackTurnUsed = true;                                                       
                            }                                                   
                        }                    
                    }


                    if (onGroundTop == true) { //ground combat(player on top)
                    
                        opponentAttackChosen = rand() % 3;

                        if (opponentGrappling > playerGrappling) {
                        
                            rng = 1 + (rand() % 100);

                            if (rng <= 30) { // position switch 
                                std::cout << "\n";
                                std::cout << opponentName << " swept you off of them\n";
                                std::cout << "\n";
                                standing = true;
                                onGroundBottom = false;
                                onGroundTop = false;
                        }
                            else if (rng > 30 && rng <= 60) { // position switch 
                                std::cout << "\n";
                                std::cout << opponentName << " swept you off of them and is now on top of you\n";
                                std::cout << "\n";
                                standing = false;
                                onGroundBottom = true;
                                onGroundTop = false;
                        }
                            else if (rng > 60 && rng <= 90) { //player gets submitted
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                std::cout << "You Lost against " << opponentName << " via Round " << i << " " << opponentSubmissionsBottom[opponentAttackChosen] << "\n";
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                return false;

                            }
                            else if (rng > 90 && rng <= 100) {
                                std::cout << "\n";
                                std::cout << opponentName << " attempted an " << opponentSubmissionsBottom[opponentAttackChosen] << " which you escaped!\n";
                                std::cout << "\n";
                                damageDone = 1 + (rand() % 5);
                                playerHealth -= damageDone;
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                break;
                                //opponentAttackTurnUsed = true;
                                                     
                            }
                    }
                        else if (opponentGrappling <= playerGrappling) {

                            rng = 1 + (rand() % 100);

                            if (rng <= 40) { // position switch 
                                std::cout << "\n";
                                std::cout << opponentName << " swept you off of them\n";
                                std::cout << "\n";
                                standing = true;
                                onGroundBottom = false;
                                onGroundTop = false;
                            }
                            else if (rng > 40 && rng <= 50) { // position switch 
                                std::cout << "\n";
                                std::cout << opponentName << " swept you off of them and is now on top of you\n";
                                std::cout << "\n";
                                standing = false;
                                onGroundBottom = true;
                                onGroundTop = false;
                            }
                            else if (rng > 50 && rng <= 60) { //player gets submitted
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                std::cout << "You Lost against " << opponentName << " via Round " << i << " " << opponentSubmissionsBottom[opponentAttackChosen] << "\n";
                                std::cout << "\n";
                                std::cout << "----------------------------------------------------------------------------\n";
                                std::cout << "\n";
                                return false;

                            }
                            else if (rng > 60 && rng <= 100) {
                                std::cout << "\n";
                                std::cout << opponentName << " attempted an " << opponentSubmissionsBottom[opponentAttackChosen] << " which you escaped!\n";
                                std::cout << "\n";
                                damageDone = 1 + (rand() % 5);
                                playerHealth -= damageDone;
                                std::cout << "Your Health: " << playerHealth << "\n";
                                std::cout << "\n";
                                break;
                                //opponentAttackTurnUsed = true;

                            }
                        }
                }                
                }
                std::cout << "\n";
                press_any_key();
                std::cout << "\n";

                //player health check 

                if (playerHealth <= 0) {
                    rng = 1 + (rand() % 100);

                    if (rng <= 55) {
                        std::cout << "\n";
                        std::cout << "----------------------------------------------------------------------------\n";
                        std::cout << "\n";
                        std::cout << "You Lost against " << opponentName << " via Round " << i << " KO\n";
                        std::cout << "\n";
                        std::cout << "----------------------------------------------------------------------------\n";
                        std::cout << "\n";
                        return false;
                    }
                    else if (rng > 55) {
                        std::cout << "\n";
                        std::cout << "----------------------------------------------------------------------------\n";
                        std::cout << "\n";
                        std::cout << "You Lost against " << opponentName << " via Round " << i << " TKO\n";
                        std::cout << "\n";
                        std::cout << "----------------------------------------------------------------------------\n";
                        std::cout << "\n";
                        return false;
                    }
                
                
                }

        }

        //decisions

        if (playerHealth > opponentHealth + 6) {
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            std::cout << "You Won against " << opponentName << " via Unanimous Decision\n";
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            return true;               
        }
        else if (playerHealth > opponentHealth + 3 && playerHealth < opponentHealth + 6) {
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            std::cout << "You Won against " << opponentName << " via Majority Decision\n";
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            return true;
        
        }
        else if (playerHealth > opponentHealth && playerHealth < opponentHealth + 3) {
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            std::cout << "You Won against " << opponentName << " via Split Decision\n";
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            return true;
        
        
        }
        else if (opponentHealth > playerHealth + 6) {
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            std::cout << "You Lost against " << opponentName << " via Unanimous Decision\n";
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            return false;
        
        } 
        else if (opponentHealth > playerHealth + 3 && opponentHealth < playerHealth + 6) {
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            std::cout << "You Lost against " << opponentName << " via Majority Decision\n";
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            return false;

        }
        else if (opponentHealth > playerHealth && opponentHealth < playerHealth + 3) {
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            std::cout << "You Lost against " << opponentName << " via Split Decision\n";
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------------------\n";
            std::cout << "\n";
            return false;


        }
        else if (opponentHealth == playerHealth) {
        
            rng = 1 + (rand() % 100);

            if (rng <= 50) {
                std::cout << "\n";
                std::cout << "----------------------------------------------------------------------------\n";
                std::cout << "\n";
                std::cout << "You Won against " << opponentName << " via Split Decision\n";
                std::cout << "\n";
                std::cout << "----------------------------------------------------------------------------\n";
                std::cout << "\n";
                return true; 
            
            
            }
            else if (rng > 50) {
                std::cout << "\n";
                std::cout << "----------------------------------------------------------------------------\n";
                std::cout << "\n";
                std::cout << "You Lost against " << opponentName << " via Split Decision\n";
                std::cout << "\n";
                std::cout << "----------------------------------------------------------------------------\n";
                std::cout << "\n";
                return false;
            
            }
        
        
        }

        return false;

        }
    



    
