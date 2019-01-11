#include "GameScene.h"
#include "cocos2d.h"
//#include "HelloWorldScene.h"

USING_NS_CC;
Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();
	//day la background
	auto background = Sprite::create("under.png");
	background->setScaleY(1.3);
	background->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(background, -1);

	/*auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, HelloWorld::create()));
	});

	runAction(Sequence::create(DelayTime::create(10), gotoNext, nullptr));*/

	return true;
}