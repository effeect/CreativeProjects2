#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include "ofMain.h"

/* PLAYER CLASS

This class contains all of the information needed for us, the player.
All of the values related to the status of the player will be found in this class

There are three main values the player needs to keep an eye on :
- Health
- Skill
- Morale

*/

class playerStats
{
public:
	float health;
	float skill;
	float morale;
	ofImage playerIcon;

	playerStats();

	//Health Related Functions
	void playerLoseHealth(float damage);
	void playerGainHealth(float health);

	//Skill related fucntions
	void playerLoseSkill(float num);
	void playerGainSkill(float num);

	//Morale functions
	void playerLoseMorale(float num);
	void playerGainMorale(float num);
};

#endif