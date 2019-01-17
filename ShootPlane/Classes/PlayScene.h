#pragma once
#include "cocos2d.h"

USING_NS_CC;
class PlayScene : public cocos2d::Layer
{
private:
	
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void PlayScene::setBackground();
	
	//virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event *event);
	//virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event *event);
	//virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *event);

	CREATE_FUNC(PlayScene);
};
#pragma once
