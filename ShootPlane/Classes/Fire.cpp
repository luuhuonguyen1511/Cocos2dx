#include "Fire.h"

Fire::Fire()
{
}

Fire::Fire(Layer * layer)
{
	setSprite(layer);
}

Fire::~Fire()
{
}

void Fire::setSprite(Layer * layer)
{
	auto screenSize = Director::getInstance()->getVisibleSize();

	mSprite = Sprite::create("fire.png");
	mSprite->setPosition(this->getPosition().x, this->getPosition().y);
	layer->addChild(mSprite, 1);
	
	if (!mSprite->isVisible()) {
		this->FireFly(this->getPosition());
	}
	//else this->~Fire;

	
}

void Fire::setPosition(float x, float y)
{
	this->pos.x = x;
	this->pos.y = y;
}

Position Fire::getPosition()
{
	return Position();
}

void Fire::FireFly(Position pos)
{
	mSprite->setPosition(pos.x, pos.y + 5);
}

