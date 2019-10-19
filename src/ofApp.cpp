#include "ofApp.h"
//#include "game.cpp"

//--------------------------------------------------------------
void ofApp::setup(){
	game = new Game();
	//ofSetWindowShape(500, 500);

	game->init("Political", 100, 100, ofGetWidth(), ofGetHeight(), false);

	//Custom fonts are loaded here
	myFont.load("iron.ttf", 40);

	//Trump Enemy setup functions
	TrumpEnemy.imageLoad("img/trump.png");
	TrumpEnemy.setup();

	farageEnemy.imageLoad("img/farage.png");
	farageEnemy.setup();

	dukeEnemy.imageLoad("img/duke.png");
	dukeEnemy.setup();

	hubTextClass.process("HubWorldText.xml");

	outskirts.loadImage("Outskirts_image.png");
	warehouse.loadImage("Warehouses_image.png");

	//Menu related fucntions
	myPlayer.loadMovie("loadingscreen.mov");
	menuFont.loadFont("gameplay.ttf", 40);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (!isOnMenu)
	{
		myPlayer.update();
	}

	if (is_hitpoint == false) {
		game->update();

	}
	//FIGHTING GAME SYSTEMS
	if (enemySwitchX == false && enemyMoveX <= 150)
	{
		enemyMoveX += 1.5;
		if (enemyMoveX == 150)
		{
			enemySwitchX = true;
		}
	}
	if (enemySwitchX == true && enemyMoveX >= -150)
	{
		enemyMoveX -= 1.5;
		if (enemyMoveX == -150)
		{
			enemySwitchX = false;
		}
	}

	//Y VALUES FOR FLOATING IMAGE
	if (enemySwitchY == false && enemyMoveY <= 150)
	{
		enemyMoveY += 0.5;
		if (enemyMoveY == 150)
		{
			enemySwitchY = true;
		}
	}
	if (enemySwitchY == true && enemyMoveY >= -150)
	{
		enemyMoveY -= 0.5;
		if (enemyMoveY == -150)
		{
			enemySwitchY = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (isOnMenu) //This is just the startup menu screen
	{
		myPlayer.play();

		myPlayer.draw(0, 0, 1024, 768);

		ofSetColor(255);
		menuFont.drawString("The Political Game", 220, 100);

		//The Start Button
		if (mouseX > 200 && mouseX < 824 && mouseY > 400 && mouseY < 500)
		{
			ofSetColor(0);
			ofRect(200, 400, 624, 100);
			ofSetColor(255);
			menuFont.drawString("Start", 400, 475);

		}
		else
		{
			ofSetColor(255);
			ofRect(200, 400, 624, 100);
			ofSetColor(0);
			menuFont.drawString("Start", 400, 475);
		}

		//The How to play Button
		if (mouseX > 200 && mouseX < 824 && mouseY > 550 && mouseY < 650)
		{
			ofSetColor(0);
			ofRect(200, 550, 624, 100);
			ofSetColor(255);
			menuFont.drawString("How to play", 400, 625);

		}
		else
		{
			ofSetColor(255);
			ofRect(200, 550, 624, 100);
			ofSetColor(0);
			menuFont.drawString("How to play", 400, 625);
		}
		ofSetColor(255);
	}
	else
	{

		playerX = game->locationX;
		playerY = game->locationY;


		//cout << playerX << endl;
		/*if (playerX == 400) {
			game->isPort = true;
		}*/

		//tile->drawTile();
		/*if (game->isPort == false) {
			outskirts.draw(0,0);

		}
		if (game->isPort == true) {
			warehouse.draw(0, 0);

		}*/
		//character->draw();
		game->render();




		//
		/*for (int row = 0; row < 10; row++) {
			for (int col = 0; col < 15; col++) {

				type = tile->map[row][col];

				tileRect.x = col * 32;
				tileRect.y = row * 32;

				tileRect.width = tileRect.x + 32;
				tileRect.height = tileRect.y + 32;

				charRect.x = character->position.x;
				charRect.y = character->position.y;
				charRect.width = charRect.x + 32;
				charRect.height = charRect.y + 32;

				switch (type) {

				case 0:
					if (Collision::AABB(charRect, tileRect)) {
						cout << "hit grass" << endl;
					}
					break;
				case 1:
					if (Collision::AABB(charRect, tileRect)) {
						cout << "hit water" << endl;
					}

				}
			}
		}*/




		//game->mapName = "second";

		//FIGHTING GAME SYSTEM

		//if() //Compare player position to world position, then fight begins
		if (game->townEnemyTrigger == true && dukeEnemy.i < 100)
		{
			

			is_hitpoint = true;
			ofBackground(125, 125, 125);
			//Enemy Appearence
			dukeEnemy.imageDraw(ofGetWidth() / 2 - 250 + enemyMoveX, ofGetHeight() / 2 - 250 + enemyMoveY); //Position for the character head
			dukeEnemy.draw();

			ofSetColor(255, 255, 255);

		}
		if (dukeEnemy.i >= 99)
		{
			is_hitpoint = false;
		
		}

		if (game->warehouseEnemyTrigger == true && TrumpEnemy.i < 100) //The condition needs to be a position in the map. Maybe a texture with a chat bubble on it?
		{

			is_hitpoint = true;
			ofBackground(125, 125, 125);
			//Enemy Appearence
			TrumpEnemy.imageDraw(ofGetWidth() / 2 - 250 + enemyMoveX, ofGetHeight() / 2 - 250 + enemyMoveY); //Position for the character head
			TrumpEnemy.draw();

			//Text for boxes
			ofSetColor(255, 255, 255);
			
		}

		if (TrumpEnemy.i >= 99)
		{
			is_hitpoint = false;

		}

		if (game->docksEnemyTrigger == true && mayEnemy.i < 100) {
			is_hitpoint = true;
			ofBackground(125, 125, 125);
			//Enemy Appearence
			mayEnemy.imageDraw(ofGetWidth() / 2 - 250 + enemyMoveX, ofGetHeight() / 2 - 250 + enemyMoveY); //Position for the character head
			mayEnemy.draw();

			//Text for boxes
			ofSetColor(255, 255, 255);

		}
		if (mayEnemy.i >= 99)
		{
			is_hitpoint = false;

		}
		if (game->docksEnemyTrigger2 == true && farageEnemy.i < 100) {
			is_hitpoint = true;
			ofBackground(125, 125, 125);
			//Enemy Appearence
			farageEnemy.imageDraw(ofGetWidth() / 2 - 250 + enemyMoveX, ofGetHeight() / 2 - 250 + enemyMoveY); //Position for the character head
			farageEnemy.draw();

			//Text for boxes
			ofSetColor(255, 255, 255);

		}
		if (farageEnemy.i >= 99)
		{
			is_hitpoint = false;

		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	

	if (key == '7')
	{
		testing = true;
	}

	if (key == '9')
	{
		testing2 = true;
	}

	if (key == '8')
	{
		testing2 = false;
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (game->townEnemyTrigger == true) {
		dukeEnemy.mousePressed();
	}
	if (game->warehouseEnemyTrigger == true) {
		TrumpEnemy.mousePressed();
	}
	if (game->docksEnemyTrigger == true) {
		mayEnemy.mousePressed();
	}
	if (game->docksEnemyTrigger2 == true) {
		farageEnemy.mousePressed();
	}



	//Menu Related functions
	if (mouseX > 200 && mouseX < 824 && mouseY > 400 && mouseY < 500)
	{
		isOnMenu = false;
	}

	if (mouseX > 200 && mouseX < 824 && mouseY > 550 && mouseY < 650)
	{

	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
