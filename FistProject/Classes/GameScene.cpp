#include "GameScene.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "SettingScene.h"
#include "PlayScene.h"

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

	//menu
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		[](Ref* render) 
			{
				exit(0); 
			});

	closeItem->setAnchorPoint(Vec2(1, 0));
	closeItem->setPosition(screenSize.width/2, - screenSize.height / 2);

	auto itemPlay = MenuItemFont::create("Play", 
		[&](Ref* play) {
		auto gotoNext = CallFunc::create([]() {
			Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(1, PlayScene::createScene()));
		});

		runAction(Sequence::create(DelayTime::create(0), gotoNext, nullptr));
	});

	auto itemSetting = MenuItemFont::create("Setting", 
		[&](Ref* setting) {
		auto gotoNext = CallFunc::create([]() {
			Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(1, SettingScene::createScene()));
		});

		runAction(Sequence::create(DelayTime::create(0), gotoNext, nullptr));
	});
	auto itemAbout = MenuItemFont::create("About", nullptr);
	auto itemPlayer = MenuItemFont::create("Player", 
		[&](Ref* player) {
			auto gotoNext = CallFunc::create([]() {
				Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(1, HelloWorld::create()));
			});
				
			runAction(Sequence::create(DelayTime::create(0), gotoNext, nullptr));
		});

	itemPlay->setPosition(0, 0);
	itemPlayer->setPosition(0, 30);
	itemSetting->setPosition(0, 60);
	itemAbout->setPosition(0, 90);
	itemPlay->setFontSizeObj(20);
	itemSetting->setFontSizeObj(20);
	itemAbout->setFontSizeObj(20);
	itemPlayer->setFontSizeObj(20);

	auto menuLabel = Menu::create(itemAbout, itemSetting, itemPlayer, itemPlay, nullptr);
	menuLabel->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(menuLabel, 1);

	auto myMenu = Menu::create(closeItem, nullptr);
	myMenu->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(myMenu);

	//test label
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	TTFConfig labelConfig;
	labelConfig.fontFilePath = "fonts/chewy_regular.ttf";
	labelConfig.fontSize = 30;
	labelConfig.glyphs = GlyphCollection::DYNAMIC;
	labelConfig.outlineSize = 2;
	labelConfig.customGlyphs = nullptr;
	labelConfig.distanceFieldEnabled = false;

	auto myLabel = Label::createWithTTF(labelConfig, "UNDER THE SEA");
	
	myLabel->setPosition(Vec2(origin.x + screenSize.width / 2,
		origin.y + screenSize.height - myLabel->getContentSize().height));
	myLabel->enableGlow(Color4B::ORANGE);

	addChild(myLabel, 2);



	return true;
}
