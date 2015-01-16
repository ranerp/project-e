#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Circle.h"
#include "Water.h"
#include <vector>
#include <iostream>

using namespace std;

class Objects
{
public:
	Objects(sf::RenderWindow& rw);
	~Objects();
	void render();
	Circle* addCircle(float x, float y, float radius, int r, int g, int b);
	void addWater();
	int returnColumns();
	vector<Circle*>* returnCircleVector();

	Water* water;
private:
	vector<Circle*> circles;
	vector<Circle*>::iterator iter;

	sf::RenderWindow* window;

	int interval;
	int columnsNumber;

	sf::Clock clock;
};