#include "Ship.h"
#include "IntroScene.h"
#include "Define.h"

Ship::Ship(Scene* scene)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites.plist", "sprites.png");

	auto listFrames = getFrames("00", 5);
	mSprite = Sprite::createWithSpriteFrame(listFrames.front());
	
	scene->addChild(mSprite, 1);

	auto animation = Animation::createWithSpriteFrames(listFrames, 0.25f);
	mSprite->runAction(RepeatForever::create(Animate::create(animation)));

	for (int i = 0; i < FIRE_NUMBER_MAX; i++)
	{
		Fire *fire = new Fire(scene);
		listFire.push_back(fire);
	}

	Init();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Ship::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Ship::onTouchMoved, this);

	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, mSprite);

}

Ship::~Ship()
{
}

void Ship::Init()
{	

	this->SetAlive(true);
	mSprite->setAnchorPoint(Vec2(0.5, 0));
	mSprite->setPosition(SCREEN_W / 2, SCREEN_H / 6);
	mSprite->setScale(0.7);
	
}

void Ship::Update()
{
	if (mIsAlive)
	{
		frameCount++;
		if (frameCount % FRAME_FOR_FIRE == 0) {
			for (int i = 0; i < listFire.size(); i++) 
			{
				if (listFire.at(i)->IsAlive() == false)
					{
						listFire.at(i)->SetAlive(true);
						listFire.at(i)->SetPosition(Vec2(mSprite->getPosition().x,
							mSprite->getPosition().y + mSprite->getContentSize().height / 2));

						break;
					}
			}
		}
		
		for (int i = 0; i < listFire.size(); i++)
		{
			if (listFire.at(i)->IsAlive() == true)
			{
				listFire.at(i)->Update();
			}
		}
	}
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

bool Ship::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	if (mSprite->getBoundingBox().containsPoint(touch->getLocation()))
	{
		return true;
	}
	return false;
}

void Ship::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	mSprite->setPosition(mSprite->getPosition() + touch->getDelta());
}

std::vector<Fire*> Ship::getListFire()
{
	return listFire;
}

void Ship::Collision(std::vector<Rock*> listRock, Scene* scene)
{
	for (int i = 0; i < listRock.size(); i++)
	{
		if (listRock.at(i)->IsAlive())
		{
			//collision with ship
			if (listRock.at(i)->getRectSprite().intersectsCircle(this->mSprite->getPosition(), 13))
			{	
				auto fadeIn = FadeIn::create(0.1f);
				auto fadeOut = FadeOut::create(0.1f);
				auto sequence = Sequence::createWithTwoActions(fadeOut, fadeIn);

				this->mSprite->runAction(Repeat::create(sequence, 3));
				//Director::getInstance()->replaceScene(TransitionShrinkGrow::create(1, IntroScene::createScene()));
				
				continue;

			}

			for (int j = 0; j < this->listFire.size(); j++)
			{
				if (listRock.at(i)->getRectSprite().intersectsRect(listFire.at(j)->getRectSprite()))
					{
						listRock.at(i)->Explosion(scene);
						
						listFire.at(j)->Init();

						continue;

				}
			}
			
		}
	}
}

Rect Ship::getRectSprite()
{
	return Rect(mSprite->getBoundingBox());
}
