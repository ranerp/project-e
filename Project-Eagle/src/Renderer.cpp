#include "Renderer.h"
#include <iostream>
#include <string>

using namespace std;

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

bool Renderer::initialize()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 2;

	this->window.create(sf::VideoMode(800, 600, 32), "PROJECT EAGLE", sf::Style::Close, settings);
	this->window.setFramerateLimit(40);

	this->setBackgroundColor(135, 206, 235);
	this->renderState = Initialized;
	this->objects = new Objects(this->window);

	this->fps = new Fps(this->window);

	this->objects->addWater();

	this->cd = new CollisionDetector(this->window, this->objects, this->objects->returnCircleVector());

	return true;
}

void Renderer::run()
{
	if(this->renderState == Initialized)
	{
		this->renderState = Running;
	}

	int i = 0;
	while(this->renderState == Running && this->window.isOpen())
	{
		sf::Event event;
		while(this->window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				this->window.close();
			if(event.type == sf::Event::MouseButtonPressed)
			{
				if(event.mouseButton.y < 340)
					this->objects->addCircle(event.mouseButton.x, event.mouseButton.y, 15, 50, 50, 150);
			}
		}

		this->clearScreen();

		this->render();

		this->displayScreen();
	}
}

void Renderer::setBackgroundColor(int red, int blue, int green)
{
	this->r = red;
	this->b = blue;
	this->g = green;
}

void Renderer::clearScreen()
{
	this->window.clear(sf::Color(this->r, this->b, this->g));
}

void Renderer::displayScreen()
{
	this->window.display();
}

void Renderer::render()
{
	this->fps->show();
	this->objects->render();
	this->cd->detect();
}