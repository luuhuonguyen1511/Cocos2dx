#include "Thing.h"

Thing::Thing()
{
}

Thing::Thing(Layer * layer)
{
	setSprite(layer);
}


Thing::~Thing()
{
}

Thing::Thing(Thing *thing)
{
	this->setPosition(thing->pos.x, thing->pos.y);
	this->mSprite;
}

void Thing::setPosition(float x, float y)
{
	this->pos.x = x;
	this->pos.y = y;
}

Position Thing::getPosition()
{
	return pos;
}

void Thing::setSprite(Layer * layer)
{
	mSprite = Sprite::create();
}

