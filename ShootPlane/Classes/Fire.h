#pragma once
#include "cocos2d.h"
#include "Model.h"

USING_NS_CC;
class Fire : public Model
{
public:
	Fire(Scene* scene);
	~Fire();

	void Init();
	
	void Update();
	void SetPosition(cocos2d::Vec2 pos);
	
private:
	int frameCount = 0;
};

