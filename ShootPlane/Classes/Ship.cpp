#include "Ship.h"



Ship::Ship()
{
}

Ship::Ship(Layer * layer)
{
	setSprite(layer);
}

Ship::~Ship()
{
}

void Ship::setPosition()
{
	/*auto screenSize = Director::getInstance()->getVisibleSize();
	
	pos.x = screenSize.width / 2;
	pos.y = screenSize.height / 2;*/
}

Position Ship::getPosition()
{
	return Position();
}

void Ship::setSprite(Layer * layer)
{
	auto screenSize = Director::getInstance()->getVisibleSize();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plist", "sprites.png");

	auto listFrames = getFrames("tile00", 5);
	mSprite = Sprite::createWithSpriteFrame(listFrames.front());
	
	mSprite->setAnchorPoint(Vec2(0.5, 0));
	mSprite->setPosition(screenSize.width / 2, screenSize.height/5);
	layer->addChild(mSprite);

	auto animation = Animation::createWithSpriteFrames(listFrames, 0.25f);
	auto animate = Animate::create(animation);
	mSprite->runAction(RepeatForever::create(animate));
}

Vector<SpriteFrame*> Ship::getFrames(std::string name, int count)
{
	Vector<SpriteFrame*> aniFrames;
	char str[100];
	for (int i = 0; i < count; i++)
	{
		sprintf(str, "%d.png", i);
		std::string _name = name + str;
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(_name);
		aniFrames.pushBack(frame);
	}

	return aniFrames;
}

bool Ship::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event)
{
	return true;
}