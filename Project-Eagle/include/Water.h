#pragma once
#include <SFML/Graphics.hpp>
#include "WaterColumn.h"
#include <vector>

using namespace std;

class Water
{
public:
	Water(sf::RenderWindow* rw);
	~Water();
	void setColumns(int colNmbr);
	void render();
	void update();
	void splash(int index, float speed);
private:
	sf::RenderWindow* window;

	vector<WaterColumn*> columns;
	vector<WaterColumn*>::iterator it;

	float tension;
	float dampening;
	float spread;
	float scale;


	int colNumbers;
};