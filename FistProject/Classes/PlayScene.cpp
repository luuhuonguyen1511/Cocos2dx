#include "PlayScene.h"
#include "cocos2d.h"
#include "GameScene.h"
#include "ui/CocosGUI.h"
#include "string.h"

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
	/*auto fly = ParticleGalaxy::create();
	addChild(fly, 1);*/

	//listen
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PlayScene::onTouchEnded, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,fishMove);

	//chuyển cảnh
	/*auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, GameScene::createScene()));
	});

	runAction(Sequence::create(DelayTime::create(7), gotoNext, nullptr));*/

	return true;
}

//void PlayScene::onMouseMove(Event* event) {
//	EventMouse* e = (EventMouse*)event;
//	String str = "";
//	str = std::to_string(e->getCursorX()) + " Y:" + std::to_string(e->getCursorY());
//}

bool PlayScene::onTouchBegan(Touch* touch, Event* event) {
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, GameScene::createScene()));
	});

	runAction(Sequence::create(DelayTime::create(0), gotoNext, nullptr));
	//log("touched");
	return true;
	
}

void PlayScene::onTouchMoved(Touch* touch, Event *event) {

}

void PlayScene::onTouchEnded(Touch* touch, Event *event) {

}