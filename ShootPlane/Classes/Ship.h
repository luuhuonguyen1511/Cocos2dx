#pragma once
#include "cocos2d.h"
#include "Model.h"
#include <vector>
#include "Fire.h"
#include "Rock.h"

USING_NS_CC;
class Ship : public Model
{
public:
	Ship(Scene* scene);
	~Ship();

	void Init();
	
	void Update();
	void Collision(std::vector<Rock*> listRock, Scene* scene);
	Rect getRectSprite();

	Vector<SpriteFrame*> Ship::getFrames(std::string name, int count);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);

	std::vector<Fire*> getListFire();

private:
	std::vector<Fire*> listFire;
	int frameCount = 0;
};

