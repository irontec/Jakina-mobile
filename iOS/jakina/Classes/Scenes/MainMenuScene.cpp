//
//  MainMenuScene.cpp
//  TrivialJokoa
//
//  Created by iker on 12/12/12.
//
//

#include "MainMenuScene.h"
#include "../Layers/MainMenuLayer.h"
#include "CCNodeLoaderLibrary.h"
#include "../Helpers/VisibleRect.h"
#include "../Helpers/SpriteButton.h"
#include "../Scenes/CategoryScene.h"
#include "../Scenes/ProfilaScene.h"

MainMenuScene::~MainMenuScene()
{
    
}

MainMenuScene::MainMenuScene()
{
    
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    // Parent
    CCLayerColor *layer = CCLayerColor::create();
    layer->initWithColor(ccc4(255, 255, 255, 255), VisibleRect::right().x , VisibleRect::top().y);
    layer->setPosition(VisibleRect::center());
    layer->setAnchorPoint(ccp(0.5f, 0.5f));
    layer->ignoreAnchorPointForPosition(false);
    addChild(layer, 0);
    
    CCSprite *fondo = CCSprite::create("fondo.png");
    fondo->setPosition(VisibleRect::center());
    layer->addChild(fondo);
    
    // 1st Son
    CCLayerColor *upperLayer = CCLayerColor::create();
    upperLayer->setContentSize(ccp(VisibleRect::right().x , VisibleRect::top().y/2));
    //upperLayer->initWithColor(ccc4(120, 120, 120, 120), VisibleRect::right().x , VisibleRect::top().y/2);
    upperLayer->setPosition(ccp(VisibleRect::left().x, VisibleRect::center().y));
    upperLayer->setAnchorPoint(ccp(0,0));
    upperLayer->ignoreAnchorPointForPosition(false);
    layer->addChild(upperLayer, 0);
    
    CCSprite *spriteLogo = CCSprite::create("logo_opciones.png");
    spriteLogo->setPosition(ccp(layer->getPosition().x, layer->getPosition().y/2));
    upperLayer->addChild(spriteLogo);
    
    // 2nd Son
    CCLayerColor *lowerLayer = CCLayerColor::create();
    lowerLayer->setContentSize(ccp(VisibleRect::right().x , VisibleRect::top().y/2));
    //lowerLayer->initWithColor(ccc4(200, 200, 200, 200), VisibleRect::right().x , VisibleRect::top().y/2);
    lowerLayer->setPosition(ccp(VisibleRect::left().x, VisibleRect::bottom().y));
    lowerLayer->setAnchorPoint(ccp(0,0));
    lowerLayer->ignoreAnchorPointForPosition(false);
    layer->addChild(lowerLayer, 0);
    
    int mySize = lowerLayer->getContentSize().height / 3;
    
    // Button SAILKAPENA
    CCTexture2D *texture1 = CCTextureCache::sharedTextureCache()->addImage("botoia_normal.png");
    SpriteButton *pButton1 = SpriteButton::create(texture1 ,this, callfuncO_selector(MainMenuScene::menuSelector), 1.0f);
    pButton1->setTag(2);
    pButton1->setPosition(ccp(
                              lowerLayer->getContentSize().width / 2,
                              lowerLayer->getContentSize().height / 2));
    pButton1->setAnchorPoint(ccp(0.5f, 0.5f));
    CCLabelTTF *pLabel1 = CCLabelTTF::create("Sailkapena", "fonts/PT_Sans-Web-Bold.ttf", 30.0);
    pLabel1->setPosition(ccp(
                             lowerLayer->getContentSize().width / 2,
                             lowerLayer->getContentSize().height / 2));
    lowerLayer->addChild(pButton1);
    lowerLayer->addChild(pLabel1);
    
    // Button JOKATU
    CCTexture2D *texture2 = CCTextureCache::sharedTextureCache()->addImage("botoia_normal.png");
    SpriteButton *pButton2 = SpriteButton::create(texture2 ,this, callfuncO_selector(MainMenuScene::menuSelector), 1.0f);
    pButton2->setTag(1);
    pButton2->setPosition(ccp(
                              lowerLayer->getContentSize().width / 2,
                              (mySize * 3) - texture2->getContentSize().height));
    pButton2->setAnchorPoint(ccp(0.5f, 0.5f));
    CCLabelTTF *pLabel2 = CCLabelTTF::create("Jokatu", "fonts/PT_Sans-Web-Bold.ttf", 30.0);
    pLabel2->setPosition(ccp(
                             lowerLayer->getContentSize().width / 2,
                             (mySize * 3) - texture2->getContentSize().height));
    lowerLayer->addChild(pButton2);
    lowerLayer->addChild(pLabel2);
    
    // Button HONI BURUZ
    CCTexture2D *texture3 = CCTextureCache::sharedTextureCache()->addImage("botoia_normal.png");
    SpriteButton *pButton3 = SpriteButton::create(texture3 ,this, callfuncO_selector(MainMenuScene::menuSelector), 1.0f);
    pButton3->setTag(3);
    pButton3->setPosition(ccp(
                              lowerLayer->getContentSize().width / 2,
                              mySize - (texture2->getContentSize().height / 2)));
    pButton3->setAnchorPoint(ccp(0.5f, 0.5f));
    CCLabelTTF *pLabel3 = CCLabelTTF::create("Honi buruz", "fonts/PT_Sans-Web-Bold.ttf", 30.0);
    pLabel3->setPosition(ccp(
                             lowerLayer->getContentSize().width / 2,
                             mySize - (texture2->getContentSize().height / 2)));
    lowerLayer->addChild(pButton3);
    lowerLayer->addChild(pLabel3);
    
	return true;
}

void MainMenuScene::menuSelector(CCObject* pSender)
{
    SpriteButton *selectedOpt = (SpriteButton*) pSender;
    CCScene *scene;
    switch (selectedOpt->getTag()) {
        case 1:
            scene = CategoryScene::create();
            break;
        case 2:
            scene = ProfilaScene::create();
            break;
        case 3:
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
                openURLJNI("http://jakina.eu/");
            #else
                CCApplication::sharedApplication()->openURL("http://jakina.eu/");
            #endif
            break;
        default:
            break;
    }
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCTransitionFade *tscene = CCTransitionFade::create(0.5, scene);
    pDirector->replaceScene(tscene);
}
