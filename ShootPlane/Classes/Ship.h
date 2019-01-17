#pragma once
#include "cocos2d.h"
#include "Thing.h"

USING_NS_CC;

class Ship : public Thing
{
private:

public:
	Ship();
	Ship(Layer * layer);
	virtual ~Ship();

	void setPosition();

	Position getPosition();

	void setSprite(Layer * layer) override;
	Vector<SpriteFrame*> getFrames(std::string name, int count);

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
};

