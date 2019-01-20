#pragma once
#include "cocos2d.h"
#include "Model.h"

USING_NS_CC;
class Rock : public Model
{
public:
	Rock(Scene* scene);
	~Rock();

	void Init();

	void Update();

	Rect getRectSprite();

private:
	
	int frameCount = 0;
};

