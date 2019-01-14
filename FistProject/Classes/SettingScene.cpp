#include "SettingScene.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;
Scene* SettingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingScene::create();
	scene->addChild(layer);
	return scene;
}

bool SettingScene::init()
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

	//menu
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		[](Ref* render)
	{
		exit(0);
	});

	closeItem->setAnchorPoint(Vec2(1, 0));
	closeItem->setPosition(screenSize.width / 2, -screenSize.height / 2);

	auto myMenu = Menu::create(closeItem, nullptr);
	myMenu->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(myMenu);

	////test label
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto myLabel = Label::createWithTTF("SETTING", "fonts/chewy_regular.ttf", 30);

	myLabel->setPosition(Vec2(origin.x + screenSize.width / 2,
		origin.y + screenSize.height - myLabel->getContentSize().height));

	addChild(myLabel, 2);

	return true;
}
