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
    
    CCSprite *fondo = CCSprite::create("fondo.png");
    fondo->setPosition(VisibleRect::center());
    
    addChild(fondo, 0);
    
    int mySize = VisibleRect::center().y / 3;
    
    // Button JARRAITU
    CCTexture2D *texture3 = CCTextureCache::sharedTextureCache()->addImage("botoia_normal.png");
    SpriteButton *pButton3 = SpriteButton::create(texture3 ,this, callfuncO_selector(BukatutaScene::buttonJarraitu), 1.0f);
    pButton3->setTag(3);
    pButton3->setPosition(ccp(VisibleRect::center().x, mySize - (texture3->getContentSize().height / 2)));
    pButton3->setAnchorPoint(ccp(0.5f, 0.5f));
    CCLabelTTF *pLabel3 = CCLabelTTF::create("Jarraitu", "fonts/PT_Sans-Web-Bold.ttf", 30.0);
    pLabel3->setPosition(ccp( VisibleRect::center().x, mySize - (texture3->getContentSize().height / 2)));
    
    addChild(pButton3);
    addChild(pLabel3);
    
    std::string *name = new std::string("pack-");
    
    int kaliFiveStart = kFiveStart;
    int kaliFourStart = kFourStart;
    int kaliThreeStart = kThreeStart;
    int kaliTwoStart = kTwoStart;
    
    float bonus;
    
    switch (multzoa->zailtasuna) {
        case 1:
            name->append("erraza-");
            bonus = 1;
            break;
        case 2:
            name->append("normala-");
            bonus = 1.5;
            break;
        case 3:
            name->append("zaila-");
            bonus = 2;
            break;
            
        default:
            break;
    }
    
    int kalifikazioa = multzoa->kalifikazioa;
    
    if (multzoa->bukatuta == 1) {
        if (kalifikazioa >= kFiveStart * bonus) {
            name->append("5star.png");
        } else if(kalifikazioa >= kFourStart * bonus) {
            name->append("4star.png");
        } else if(kalifikazioa >= kThreeStart * bonus) {
            name->append("3star.png");
        } else if(kalifikazioa > kTwoStart * bonus) {
            name->append("2star.png");
        } else if(kalifikazioa <= kTwoStart * bonus){
            name->append("1star.png");
        }
    } else {
        name->append("0star.png");
    }
    
    CCLog("kaliFiveStart = %f, kFourStart = %f, kThreeStart = %f, kTwoStart = %f", (kaliFiveStart * bonus), (kaliFourStart * bonus), (kaliThreeStart * bonus), (kaliTwoStart * bonus));
    
    CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(name->c_str());
    pImage = CCSprite::createWithTexture(texture);
    pImage->setPosition(ccp(VisibleRect::center().x, VisibleRect::center().y - 20));
    addChild(pImage);

    std::stringstream ss;//create a stringstream
    ss << kalifikazioa << " puntu";
    CCLabelTTF *puntos = CCLabelTTF::create(ss.str().c_str(), "fonts/PT_Sans-Web-Bold.ttf", 20);
    puntos->setPosition(ccp(VisibleRect::center().x, VisibleRect::center().y - 90));
    puntos->setHorizontalAlignment(kCCTextAlignmentCenter);
    puntos->setVerticalAlignment(kCCVerticalTextAlignmentCenter);
    puntos->setColor(ccc3(0, 0, 0));
    addChild(puntos);
    
    CCSprite *bukatu = CCSprite::create("bukatu.png");
    bukatu->setPosition(ccp(VisibleRect::center().x, VisibleRect::center().y + (texture->getContentSize().height / 2) + 40));
    addChild(bukatu);
    
    delete name;

	return true;
}

void BukatutaScene::buttonJarraitu(CCObject* pSender)
{
    CategoryScene *scene = CategoryScene::create();
    
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCTransitionFade *tscene = CCTransitionFade::create(0.5, scene);
    pDirector->replaceScene(tscene);
}

