#include "PlayScene.h"
#include "cocos2d.h"
#include "GameScene.h"
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
	//day la background
	auto background = Sprite::create("under.png");
	background->setScaleY(1.3);
	background->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(background, -1);

	auto fishMove = Sprite::create();
	fishMove->setPosition(screenSize.width / 2, 100);
	addChild(fishMove);

	Vector<SpriteFrame*> aniFrames;
	SpriteFrame* fish1 = SpriteFrame::create("fish4.png", Rect(0, 0, 150, 150));
	//SpriteFrame* fish2 = SpriteFrame::create("fish2.png", Rect(0, 0, 150, 150));
	SpriteFrame* fish3 = SpriteFrame::create("fish5.png", Rect(0, 0, 150, 150));
	aniFrames.pushBack(fish1);
	//aniFrames.pushBack(fish2);
	aniFrames.pushBack(fish3);

	auto animation = Animation::createWithSpriteFrames(aniFrames, 1);
	auto animate = Animate::create(animation);
	fishMove->runAction(RepeatForever::create(animate));
	
	//hieu ung
	auto fly = ParticleGalaxy::create();
	addChild(fly, 1);

	//chuyển cảnh
	/*auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, GameScene::createScene()));
	});

	runAction(Sequence::create(DelayTime::create(7), gotoNext, nullptr));*/

	return true;
}