#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>


std::string defaultPrompt(int rank, int wins, int losses);
std::string trainingPrompt();
void press_any_key();
void displayNewStats(int playerStriking, int playerGrappling, int playerConditioning);
void displayNextOpponent(std::string opponentName,  std::string opponentRank);
std::string championPrompt(int wins, int losses, int defenses);
void fightCardPrompt(std::string playerName, std::string opponentName, int timesFought, int playerRank, int opponentIndex, std::string weightClass);
void displayNewStrikingStats(std::string attackName[], int level[], int defense);
void displayNewGrapplingStats(std::string topAttackName[], std::string bottomAttackName[], int topLevel[], int bottomLevel[], int takedown);
std::string firstFightPrompt();
int healthCheck(int health);
