#include "Rock.h"
#include "Define.h"

Rock::Rock(Scene* scene)
{
	mSprite = Sprite::create(METEOR_IMG);
	mSprite->setScale(0.55);
	scene->addChild(mSprite);
	Init();
}

Rock::~Rock()
{
}

void Rock::Init()
{ 
	float posX = random(1, 480);
	mSprite->setPosition(posX, SCREEN_H + 70);
	this->SetAlive(false);
}

void Rock::Update()
{
	if (mIsAlive)
	{
		
		if (frameCount % FrameCount == 0)
		{
			srand(time(NULL));
			mSprite->setPosition(mSprite->getPosition().x,
				mSprite->getPosition().y - random(ROCK_FALL_SPEED_MIN, ROCK_FALL_SPEED_MAX));
		}
		if ((mSprite->getPosition().y + mSprite->getContentSize().height / 2)<0)
		{
			SetAlive(false);
			Init();
		}

	}
}

Rect Rock::getRectSprite()
{
	return Rect(mSprite->getBoundingBox());
}


