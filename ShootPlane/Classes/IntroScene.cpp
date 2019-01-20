#include "IntroScene.h"
#include "Define.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;
Scene* IntroScene::createScene()
{
	auto scene = Scene::create();
	auto layer = IntroScene::create();
	scene->addChild(layer);
	return scene;
}

bool IntroScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();
	auto background = Sprite::create(BACKGROUND);
	background->setPosition(SCREEN_W / 2, SCREEN_H / 2);
	addChild(background, -1);
	background->setScale(1.9);

	auto audio = SimpleAudioEngine::getInstance();

	audio->playBackgroundMusic(MUSIC, true);

	auto itemPlay = MenuItemFont::create("Play", 
		[&](Ref* play) {
		auto gotoNext = CallFunc::create([]() {
			Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(1, HelloWorld::createScene()));
		});

		runAction(Sequence::create(DelayTime::create(0), gotoNext, nullptr));
	});
	
	auto itemAbout = MenuItemFont::create("About", nullptr);
	itemPlay->setFontName(FONT);
	itemAbout->setFontName(FONT);
	itemPlay->setPosition(0, 50);
	itemAbout->setPosition(0, 0);
	itemPlay->setFontSizeObj(30);
	itemAbout->setFontSizeObj(30);
	

	auto menuLabel = Menu::create(itemPlay, itemAbout, nullptr);
	menuLabel->setPosition(SCREEN_W / 2, SCREEN_H / 2);
	addChild(menuLabel, 1);

	//test label
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	TTFConfig labelConfig;
	labelConfig.fontFilePath = FONT;
	labelConfig.fontSize = 50;
	labelConfig.glyphs = GlyphCollection::DYNAMIC;
	labelConfig.outlineSize = 2;
	labelConfig.customGlyphs = nullptr;
	labelConfig.distanceFieldEnabled = false;

	auto myLabel = Label::createWithTTF(labelConfig, "I DONT KNOW");
	
	myLabel->setPosition(Vec2(origin.x + screenSize.width / 2,
		origin.y + screenSize.height - myLabel->getContentSize().height));
	//myLabel->enableGlow(Color4B::ORANGE);

	addChild(myLabel, 2);

	return true;
}
