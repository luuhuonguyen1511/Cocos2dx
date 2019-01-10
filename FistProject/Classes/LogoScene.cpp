#include "LogoScene.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;
Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}

bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();
	auto logo = Sprite::create("babytom.png");
	logo->setScale(0.5);
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);

	auto moveBy1 = MoveBy::create(0.5, Vec2(0, 50));
	auto moveBy2 = MoveBy::create(1, Vec2(0, -100));
	auto moveBy3 = MoveBy::create(0.5, Vec2(0, 50));
	
	auto sequence = Sequence::create(moveBy1, moveBy2, moveBy3, nullptr);
	auto repeat = RepeatForever::create(sequence);

	logo->runAction(repeat);


	auto background = Sprite::create("background.png");
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(background, -1);

	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	});

	runAction(Sequence::create(DelayTime::create(7), gotoNext, nullptr));

	return true;
}