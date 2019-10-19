#pragma once

#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H


//#include "game.h"
#include "ECS.h"
#include "Components.h"




class KeyboardController : public Component
{

public:
	TransformComponent *transform;

	//Getting the location components to acces velocity for movement
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

	}

	//Creating custom keyControll events for the ECS for easier acces. Would have been a bit messy accesing this from ofApp.

	void keyPressed(ofKeyEventArgs & args)
	{
 
		
			switch (args.key)
			{
			case 'w':
				transform->velocity.y = -1;
				break;
			case 'a':
				transform->velocity.x = -1;
				break;
			case 'd':
				transform->velocity.x = 1;
				break;
			case 's':
				transform->velocity.y = 1;
				break;
			default:
				break;
			}
	}
	

	void keyReleased(ofKeyEventArgs & args) {
		
		switch (args.key)
		{
		case 'w':
			transform->velocity.y = 0;
			break;
		case 'a':
			transform->velocity.x = 0;
			break;
		case 'd':
			transform->velocity.x = 0;
			break;
		case 's':
			transform->velocity.y = 0;
			break;
		default:
			break;
		}
	}

	void update() override
	{
		//Adding OF listeners to send back info on keyPressed/Released
		ofAddListener(ofEvents().keyPressed, this, &KeyboardController::keyPressed);

		ofAddListener(ofEvents().keyReleased, this, &KeyboardController::keyReleased);

	}
};
#endif // !KEYBOARD_CONTROLLER_H