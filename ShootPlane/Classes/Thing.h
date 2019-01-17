/// trống trơn nè =))) nên lỗi thôi coppy như cứt =))
//rõ là copy rồi :((((
// giờ cut đi dán lại
/// cái nào trống thì xóa
#pragma once
#include "cocos2d.h"

USING_NS_CC;
struct Position
{
	float x;
	float y;
};

class Thing
{
protected:
	Position pos;
	cocos2d::Sprite *mSprite;
public:
	Thing();
	Thing(Layer * layer);
	
	virtual ~Thing();
	Thing(Thing *thing);

	void setPosition(float x, float y);

	Position getPosition();

	virtual void setSprite(Layer * layer);
};

