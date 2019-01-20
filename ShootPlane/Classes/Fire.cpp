#include "Fire.h"
#include "Define.h"

Fire::Fire(Scene* scene)
{
	mSprite = Sprite::create(FIRE_IMG);
	scene->addChild(mSprite);
	mSprite->setScale(1.3);
	Init();
	
}

Fire::~Fire()
{
}

void Fire::Init()
{	
	this->SetAlive(false);
}

void Fire::Update()
{
	if (mIsAlive)
	{
		frameCount++;
		if (frameCount % FrameCount == 0)
		{
			mSprite->setPosition(mSprite->getPosition().x, 
				mSprite->getPosition().y + FIRE_SPEED);
		}
		if ((mSprite->getPosition().y - mSprite->getContentSize().height/2) > SCREEN_H)
		{
			SetAlive(false);
		}
		
	}
}

void Fire::SetPosition(cocos2d::Vec2 pos)
{
	mSprite->setPosition(pos);
}

