#pragma once

#include <SFML/Graphics.hpp>
#include "Objects.h"
#include "Circle.h"
#include "WaterColumn.h"
#include <vector>

using namespace std;

class CollisionDetector
{
public:
	CollisionDetector(sf::RenderWindow& rw, Objects* objs, vector<Circle*>* circles);
	~CollisionDetector();

	void detect();
private:
	Objects* objects;

	vector<Circle*>* circles;
	vector<Circle*>::iterator iter;

	int colNumbers;

	sf::RenderWindow* window;
};