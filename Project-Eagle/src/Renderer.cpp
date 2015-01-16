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
	sf::WindowSettings settings;
	settings.DepthBits = 24;
	settings.StencilBits = 8;
	settings.AntialiasingLevel = 2;

	this->window.Create(sf::VideoMode(800, 600, 32), "PROJECT EAGLE", sf::Style::Close, settings);
	this->window.SetFramerateLimit(40);

	this->setBackgroundColor(135, 206, 235);
	this->renderState = Initialized;
	this->objects = new Objects(this->window);

	this->fps = new Fps(this->window);

	this->objects->addWater();

	this->cd = new CollisionDetector(this->window, this->objects, this->objects->returnCircleVector());

	return TRUE;
}

void Renderer::run()
{
	if(this->renderState == Initialized)
	{
		this->renderState = Running;
	}

	int i = 0;
	while(this->renderState == Running && this->window.IsOpened())
	{
		sf::Event Event;
		while(this->window.GetEvent(Event))
		{
			if(Event.Type == sf::Event::Closed)
				this->window.Close();
			if(Event.Type == sf::Event::MouseButtonPressed)
			{
				if(Event.MouseButton.Y < 340)
					this->objects->addCircle(Event.MouseButton.X, Event.MouseButton.Y, 15, 255, 255, 255);
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
	this->window.Clear(sf::Color(this->r, this->b, this->g));
}

void Renderer::displayScreen()
{
	this->window.Display();
}

void Renderer::render()
{
	this->fps->show();
	this->objects->render();
	this->cd->detect();
}