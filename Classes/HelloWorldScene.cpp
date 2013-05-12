#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
/*    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);*/
    this->draw("HelloWorld.png", size.width/2, size.height/2, 0);
    
    this->move("guil_face01.png", size.width/2, size.height, size.width/2, 0, 10, 1);

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/**
 *　描画する
 *　@param imageName 描画する画像名
 *　@param drawCenterX 描画する画像の中心座標(X）
 *　@param drawCenterY 描画する画像の中心座標(Y)
 *　@param layer 描画レイヤー位置
 */
CCSprite* HelloWorld::draw(const char* imageName, int drawCenterX, int drawCenterY, int layer)
{
	if(imageName == NULL)
	{
		return NULL;
	}

	CCSprite* pSprite = CCSprite::create(imageName);
	pSprite->setPosition(ccp(drawCenterX, drawCenterY));
	this->addChild(pSprite, layer);

	return pSprite;
}

/**
 * 画像を移動させる
 * @param imageName 描画する画像名
 * @param moveStartX 移動開始X位置
 * @param moveStartY 移動開始Y位置
 * @param moveEndX 移動終了X位置
 * @param moveEndY 移動終了Y位置
 * @param duration 移動時間
 * @param layer 描画レイヤ位置
 */
void HelloWorld::move(const char* imageName,
		              int moveStartX, int moveStartY,
		              int moveEndX, int moveEndY,
		              int duration, int layer)
{
	CCSprite* pSprite = this->draw(imageName, moveStartX, moveStartY, layer);
	CCMoveTo* pMoveTo = CCMoveTo::create(duration, ccp(moveEndX, moveEndY));
	pSprite->runAction(pMoveTo);
}
