#include "CollisionDetector.h"

CollisionDetector::CollisionDetector(sf::RenderWindow& rw, Objects* obj, vector<Circle*>* crc)
	: window(&rw), objects(obj), circles(crc)
{

}

CollisionDetector::~CollisionDetector()
{
}

void CollisionDetector::detect()
{
	this->iter = this->circles->begin();

	while(this->iter != this->circles->end())
	{
		float y = (*this->iter)->getY();

		if(y >= 340 && y < 380)
		{
			int index = (*this->iter)->getX() / 4;
			(*this->iter)->setResistance(0.4);
			this->objects->water->splash(index, (*this->iter)->getVelocity() * (*this->iter)->getVelocity() / 4);
		}

		if(y > this->window->GetHeight())
		{
			cout << "Delete circle at: x - " << (*this->iter)->getX() << " y - " << (*this->iter)->getY() << endl;
			delete *this->iter;
			this->circles->erase(this->iter);
			this->iter = this->circles->begin();
		}
		else
			this->iter++;
	}
}