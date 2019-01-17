#include "PlayScene.h"
#include "cocos2d.h"
#include "Ship.h"
#include "Fire.h"
#include "Thing.h"

#include "ui/CocosGUI.h"


USING_NS_CC;
Scene* PlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(layer);
	return scene;
}

bool PlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();
	setBackground();
	
	Ship *_ship = new Ship(this);  
	Fire *_fire = new Fire(this);
	return true;
}

void PlayScene::setBackground()
{
	auto background = Sprite::create("background.png");
	background->setPosition(160, 240);
	addChild(background, -1);
	background->setScale(2.5);
}




