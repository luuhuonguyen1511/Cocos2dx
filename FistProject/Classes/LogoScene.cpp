#include "LogoScene.h"
#include "cocos2d.h"
#include "GameScene.h"

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
	//day la baby tom
	auto logo = Sprite::create("babytom.png");
	logo->setScale(0.4);
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);

	auto moveBy1 = MoveBy::create(0.5, Vec2(0, 50));
	auto moveBy2 = MoveBy::create(1, Vec2(0, -100));
	auto moveBy3 = MoveBy::create(0.5, Vec2(0, 50));
	
	auto sequence = Sequence::create(moveBy1, moveBy2, moveBy3, nullptr);
	auto repeat = RepeatForever::create(sequence);

	logo->runAction(repeat);

	//đây là background
	auto background = Sprite::create("background.png");
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(background, -2);

	//đây là chữ loading
	auto loading = Sprite::create("loading.png");
	loading->setScale(0.15);
	loading->setPosition(screenSize.width / 2, 30);
	addChild(loading, -1);

	auto fadeIn = FadeIn::create(1.0f);
	auto fadeOut = FadeOut::create(1.0f);
	auto sequence1 = Sequence::create(fadeIn, fadeOut, nullptr);
	auto repeat1 = RepeatForever::create(sequence1);
	loading->runAction(repeat1);

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
	//auto myLabel = Label::createWithTTF("under", "fonts/....ttf", 23);
	myLabel->setPosition(Vec2(origin.x + screenSize.width / 2,
		origin.y + screenSize.height - myLabel->getContentSize().height));
	myLabel->enableGlow(Color4B::ORANGE);
	
	addChild(myLabel, 1);

	//chuyển cảnh
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, GameScene::createScene()));
	});

	runAction(Sequence::create(DelayTime::create(7), gotoNext, nullptr));

	return true;
}