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

void Rock::Explosion(Scene* scene)
{
	explo = Sprite::create(EXPLO_IMG);
	explo->setScale(0.9);
	explo->setPosition(mSprite->getPosition());
	scene->addChild(explo);
	
	auto fadeIn = FadeIn::create(0.1f);
	auto fadeOut = FadeOut::create(0.1f);
	auto sequence = Sequence::create(fadeOut, fadeIn, RemoveSelf::create(), nullptr);

	explo->runAction(sequence);

	this->Init();
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

