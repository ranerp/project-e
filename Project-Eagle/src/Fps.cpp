#include "Fps.h"
#include <iostream>
#include <sstream>

using namespace std;

Fps::Fps(sf::RenderWindow &rw)
	: window(&rw)
{
	this->font.LoadFromFile("fonts/arial.ttf");
	this->text.SetFont(this->font);
	this->text.SetSize(12);
	this->text.Move(this->window->GetWidth() - 50, 15);
}

Fps::~Fps()
{
}

void Fps::show()
{
	this->frameRate = 1.f / this->clock.GetElapsedTime();

	ostringstream ostr;

	ostr << this->frameRate;

	string str;

	str.append("Fps: ");
	str.append(ostr.str());

	this->text.SetText(str);

	this->window->Draw(this->text);

	this->clock.Reset();
}