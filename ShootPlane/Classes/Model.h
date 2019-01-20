#pragma once
#include "cocos2d.h"

USING_NS_CC;
class Model
{
public:
	Model();
	~Model();

	virtual void Init()=0;
	virtual bool IsAlive();
	virtual void SetAlive(bool status);

	virtual void Update() = 0;

protected:
	Sprite* mSprite;
	bool mIsAlive;
};

