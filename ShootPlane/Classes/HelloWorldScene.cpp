/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Define.h"
#include "Rock.h"
#include "Ship.h"

USING_NS_CC;


std::vector<Rock*> listRock;
Ship *ship;
int frameCount = 0;
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	setBackground();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	ship = new Ship(this);
	
	for (int i = 0; i < ROCK_NUMBER_MAX; i++)
	{
		Rock *rock = new Rock(this);
		listRock.push_back(rock);
	}
	
	scheduleUpdate();
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void HelloWorld::update(float delta)
{
	ship->Update();
	
	frameCount++;
	if (frameCount % FRAME_FOR_ROCK == 0) {
		for (int i = 0; i < ROCK_NUMBER_MAX; i++)
		{
			if (listRock.at(i)->IsAlive() == false)
			{
				listRock.at(i)->SetAlive(true);
				break;
			}
		}
	}

	for (int i = 0; i < listRock.size(); i++)
	{
		if (listRock.at(i)->IsAlive() == true)
		{
			listRock.at(i)->Update();
			
		}
	}

	ship->Collision(listRock, this);	
}

void HelloWorld::setBackground()
{
	auto background = Sprite::create(BACKGROUND);
	background->setPosition(SCREEN_W / 2, SCREEN_H / 2);
	addChild(background, -1);
	background->setScale(1.9);
}

