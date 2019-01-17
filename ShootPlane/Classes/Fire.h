#pragma once
#include "cocos2d.h"
#include "Thing.h"

USING_NS_CC;

class Fire : public Thing
{
private:

public:
	Fire();
	Fire(Layer * layer);
	virtual ~Fire();

	void setSprite(Layer * layer) override;
	void setPosition(float x, float y);

	Position getPosition();

	void FireFly(Position pos);
};

