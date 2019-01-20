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
	void Explosion(Scene* scene);
	void Update();
	void Delete();
	Rect getRectSprite();

private:
	Sprite* explo;
	int frameCount = 0;
};

