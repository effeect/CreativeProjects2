#include "playerStats.h"

//This class serves as a placeholder, we have generic health values plus morale/skill if we wish to add them

playerStats::playerStats() {
	health = 5; //Player Health Values
	skill = 1; //Skill check, ranges from 0 to 10
	morale = 0;
}

//HEALTH FUNCTIONS-------------------------------
void playerStats::playerLoseHealth(float damage) {
	health = health - damage;
}

void playerStats::playerGainHealth(float healthGain) {
	health = health + healthGain;
}

//SKILL FUNCTIONS-------------------------------------
void playerStats::playerLoseSkill(float num) {
	skill = skill - num;
}

void playerStats::playerGainSkill(float num) {
	skill = skill + num;
}

//MORALE FUNCTIONS--------------------------------------

void playerStats::playerLoseMorale(float num) {
	morale = morale - num;
}

void playerStats::playerGainMorale(float num) {
	morale = morale - num;
}