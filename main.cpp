//#include <SFML/Graphics.hpp>
#include "Thing.h"
#include "Globals.h"
#include "Tile.h"
#include "Map.h"
#include "Player.h"

sf::Vector2i playerPos = sf::Vector2i(0,0);


void Update();
void MapCreate(int screenX, int screenY);

//Tile map[10][10];
Map map;
Player player;
std::vector<Thing> things;

sf::Texture texture;
sf::Texture spriteSheet;


int main() {
	int screenX = 1920;
	int screenY = 1080;
	playerPos.x = screenX / 2;
	playerPos.y = screenY / 2;
	
	//Load Resources
	MapCreate(screenX, screenY);
	if (!texture.loadFromFile("G:/Thumbnails/1.1Tree-Fitty.png")) {
		std::printf("Failed to load texture! ");
	}
	texture.setSmooth(true);
	
	if (!spriteSheet.loadFromFile("G:/Thumbnails/Sketches/MySprite.png")) {
		std::printf("Failed to load texture! ");
	}
	spriteSheet.setSmooth(true);


	sf::Vector2i obPos = sf::Vector2i(5,100);
	sf::Sprite ob;
	ob.setTexture(texture);
	
	//ob.setOrigin(texture.getSize().x/2, texture.getSize().y / 2);
	//ob.setScale(.5f, .5f);
	//ob.setPosition(obPos.x - playerPos.x, obPos.y - playerPos.y);
	sf::Vector2i mousePos;

	sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Top Down Engine");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock clock;
	sf::Time timeBetweenFrames = sf::milliseconds(16);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			player.PlayerInput(event, mousePos, window);


			if (event.type == sf::Event::Closed)
				window.close();

			
			
			
		}
		if (clock.getElapsedTime() >= timeBetweenFrames) {
			clock.restart();
			Update();
		}

		
		
		//ob.setPosition(obPos.x - playerPos.x, obPos.y - playerPos.y);

		window.clear();
		
		printf("%d", player.gridX);
		for (int backgroundX = player.gridX - 5; backgroundX < player.gridX + 5; backgroundX++) {
			for (int backgroundY = player.gridY - 5; backgroundY < player.gridY + 5; backgroundY++) {
				if (backgroundX >= 0 && backgroundY >= 0 && backgroundX < 10 && backgroundY < 10) {
					try {
						//map.AccessIndex(backgroundX, backgroundY).background->ThingUpdate(player.worldX, player.worldY, playerPos);
					}
					catch (_exception e) {
						
					}
				}
			}
		}
		
		for (int i = 0; i < things.size(); i++) {
			things[i].ThingUpdate(player.worldX, player.worldY, playerPos);
			window.draw(things[i].GetSprite());
		}
		window.draw(player.GetSprite());
		window.display();
	}

	return 0;

}



void Update() {
	player.PlanMoveDirection(map);
	player.PlayerUpdate();
	
}

void MapCreate(int screenX, int screenY) {

	map = Map(10, 10);

	player.PlayerSetup(400, 500, Thing::circle, spriteSheet, map, screenX, screenY, AnimationSystem::person);
	//Create Thing & add to heirarchy
	things.push_back(Thing(500, 300, Thing::circle, texture, map, AnimationSystem::wall));
	things.push_back(Thing(80, 80, Thing::circle, texture, map, AnimationSystem::wall));

	sf::Vector2i t1Loc = things[0].NormalizeWorldSpaceToGridSpace();
	//map.SetOccupant(things[0], t1Loc.x, t1Loc.y);
	//map[3][0].occupant->Print();
	//things[0].RequestMove(map, 10, 10);

}