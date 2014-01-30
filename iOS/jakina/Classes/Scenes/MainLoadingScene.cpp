//
//  MainLoadingScene.cpp
//  TrivialJokoa
//
//  Created by iker on 11/12/12.
//
//

#include "MainLoadingScene.h"
#include "MainMenuScene.h"
#include "LoginScene.h"
#include "MainMenuScene.h"
#include "CCNodeLoaderLibrary.h"
#include "../Helpers/VisibleRect.h"

USING_NS_CC;
USING_NS_CC_EXT;

MainLoadingScene::~MainLoadingScene()
{
    if (_api) {
        _api->release();
        _api = NULL;
    }
}

MainLoadingScene::MainLoadingScene()
{
    _api = new TrivialAPI();
    CCCallFunc *pCallback = CCCallFunc::create(this, callfunc_selector(MainLoadingScene::finishLoading));
    _api->setCallback(pCallback);
    _api->updateData();
}


// on "init" you need to initialize your instance
bool MainLoadingScene::init()
{
    if ( !CCScene::init() )
    {
        return false;
    }
    
    CCLayerColor *layer = CCLayerColor::create();
    layer->initWithColor(ccc4(255, 255, 255, 255), VisibleRect::right().x , VisibleRect::top().y);
    layer->setPosition(VisibleRect::center());
    layer->setAnchorPoint(ccp(0.5f, 0.5f));
    layer->ignoreAnchorPointForPosition(false);
    this->addChild(layer, 0);
    
    CCSprite *fondo = CCSprite::create("fondo.png");
    fondo->setPosition(VisibleRect::center());
    this->addChild(fondo);

    
    CCSprite *sprite = CCSprite::create("logo.png");
    sprite->setPosition(VisibleRect::center());
    this->addChild(sprite);
    
	return true;
}

void MainLoadingScene::finishLoading()
{
    CCScene *scene = MainMenuScene::create();

    CCDirector *pDirector = CCDirector::sharedDirector();
    CCTransitionFade *tscene = CCTransitionFade::create(0.5, scene);
    pDirector->replaceScene(tscene);
}
