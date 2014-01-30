//
//  BukatutaScene.cpp
//  TrivialJokoa
//
//  Created by Iker Mendilibar Fernandez on 11/01/13.
//
//

#include "BukatutaScene.h"
#include "../Layers/BukatutaLayer.h"
#include "CCNodeLoaderLibrary.h"
#include "../Helpers/SpriteButton.h"
#include "../Helpers/VisibleRect.h"
#include "Globals.h"
#include "../Scenes/CategoryScene.h"

BukatutaScene::~BukatutaScene()
{
    
}

BukatutaScene::BukatutaScene()
{
    
}


// on "init" you need to initialize your instance
bool BukatutaScene::init()
{
    
    // Parent
    CCLayerColor *layer = CCLayerColor::create();
    layer->initWithColor(ccc4(255, 255, 255, 255), VisibleRect::right().x , VisibleRect::top().y);
    layer->setPosition(VisibleRect::center());
    layer->setAnchorPoint(ccp(0.5f, 0.5f));
    layer->ignoreAnchorPointForPosition(false);
    
    CCSprite *fondo = CCSprite::create("fondo.png");
    fondo->setPosition(VisibleRect::center());
    
    layer->addChild(fondo);
    addChild(layer, 0);
    
    // 1st Son
    CCLayerColor *upperLayer = CCLayerColor::create();
    upperLayer->setContentSize(ccp(VisibleRect::right().x , VisibleRect::top().y/2));
    upperLayer->setPosition(ccp(VisibleRect::left().x, VisibleRect::center().y - 30));
    upperLayer->setAnchorPoint(ccp(0,0));
    upperLayer->ignoreAnchorPointForPosition(false);
    layer->addChild(upperLayer, 0);

    
    // 2nd Son
    CCLayerColor *lowerLayer = CCLayerColor::create();
    lowerLayer->setContentSize(ccp(VisibleRect::right().x , VisibleRect::top().y/2));
    lowerLayer->setPosition(ccp(VisibleRect::left().x, VisibleRect::bottom().y));
    lowerLayer->setAnchorPoint(ccp(0,0));
    lowerLayer->ignoreAnchorPointForPosition(false);
    layer->addChild(lowerLayer, 0);
    
    int mySize = lowerLayer->getContentSize().height / 3;
    
    // Button JARRAITU
    CCTexture2D *texture3 = CCTextureCache::sharedTextureCache()->addImage("botoia_normal.png");
    SpriteButton *pButton3 = SpriteButton::create(texture3 ,this, callfuncO_selector(BukatutaScene::buttonJarraitu), 1.0f);
    pButton3->setTag(3);
    pButton3->setPosition(ccp(
                              lowerLayer->getContentSize().width / 2,
                              mySize - (texture3->getContentSize().height / 2)));
    pButton3->setAnchorPoint(ccp(0.5f, 0.5f));
    CCLabelTTF *pLabel3 = CCLabelTTF::create("Jarraitu", "fonts/PT_Sans-Web-Bold.ttf", 30.0);
    pLabel3->setPosition(ccp(
                             lowerLayer->getContentSize().width / 2,
                             mySize - (texture3->getContentSize().height / 2)));
    lowerLayer->addChild(pButton3);
    lowerLayer->addChild(pLabel3);
    
    std::string *name = new std::string("bukatuduzu_");
    
    switch (multzoa->zailtasuna) {
        case 1:
            name->append("erraza.png");
            break;
        case 2:
            name->append("normala.png");
            break;
        case 3:
            name->append("zaila.png");
            break;
            
        default:
            break;
    }
    
    CCTexture2D* t = CCTextureCache::sharedTextureCache()->addImage(name->c_str());
    pImage = CCSprite::createWithTexture(t);
    pImage->setPosition(ccp(layer->getPosition().x, upperLayer->getPosition().y/2));
    upperLayer->addChild(pImage);
    
    delete name;
    
    std::string *nameIzar = new std::string();
    
    int kalifikazioa = multzoa->kalifikazioa;
    
    int kaliFiveStart = kFiveStart;
    int kaliFourStart = kFourStart;
    int kaliThreeStart = kThreeStart;
    int kaliTwoStart = kTwoStart;
    
    float bonus;
    switch (multzoa->zailtasuna) {
        case 2:
            bonus = 1.5;
            break;
        case 3:
            bonus = 2;
            break;
        default:
            bonus = 1;
            break;
    }
    
    CCLog("kaliFiveStart = %f, kFourStart = %f, kThreeStart = %f, kTwoStart = %f", (kaliFiveStart * bonus), (kaliFourStart * bonus), (kaliThreeStart * bonus), (kaliTwoStart * bonus));
    
    if (kalifikazioa >= (kFiveStart * bonus)) {
        nameIzar->append("5_izar.png");
    } else if(kalifikazioa >= (kFourStart * bonus)) {
        nameIzar->append("4_izar.png");
    } else if(kalifikazioa >= (kThreeStart * bonus)) {
        nameIzar->append("3_izar.png");
    } else if(kalifikazioa > (kTwoStart * bonus)) {
        nameIzar->append("2_izar.png");
    } else if (kalifikazioa <= (kTwoStart * bonus)) {
        nameIzar->append("1_1_izar.png");
    }
    
    t = CCTextureCache::sharedTextureCache()->addImage(name->c_str());
    pStars = CCSprite::createWithTexture(t);
    pStars->setAnchorPoint(ccp(0.5, 1));
    pStars->setPosition(ccp(VisibleRect::center().x, pImage->getPosition().y - pImage->getContentSize().height / 2 - 14));
    
    upperLayer->addChild(pStars);
    
	return true;
}

void BukatutaScene::buttonJarraitu(CCObject* pSender)
{
    CategoryScene *scene = CategoryScene::create();
    
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCTransitionFade *tscene = CCTransitionFade::create(0.5, scene);
    pDirector->replaceScene(tscene);
}

