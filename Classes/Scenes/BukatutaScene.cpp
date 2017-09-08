//
//  BukatutaScene.cpp
//  TrivialJokoa
//
//  Created by Iker Mendilibar Fernandez on 11/01/13.
//
//

#include "BukatutaScene.h"
#include "../Layers/BukatutaLayer.h"
#include "../Helpers/SpriteButton.h"
#include "../Helpers/VisibleRect.h"
#include "../Helpers/Globals.h"
#include "../Scenes/CategoryScene.h"
#include "../Helpers/ImageManager.h"

BukatutaScene::~BukatutaScene()
{
    
}

BukatutaScene::BukatutaScene()
{
    
}


// on "init" you need to initialize your instance
bool BukatutaScene::init()
{
    
    Sprite *fondo = Sprite::create("fondo.png");
    fondo->setPosition(VisibleRect::center());
    
    addChild(fondo, 0);
    
    int mySize = VisibleRect::center().y / 3;
    
    // Button JARRAITU
    Texture2D *texture3 = Director::getInstance()->getTextureCache()->addImage("botoia_normal.png");
    auto pButton3 = SpriteButton::create(ImageManager::getImage("botoia_normal"), 1.0f, CC_CALLBACK_1(BukatutaScene::buttonJarraitu, this));
    pButton3->setTag(3);
    pButton3->setPosition(Vec2(VisibleRect::center().x, mySize - (texture3->getContentSize().height / 2)));
    pButton3->setAnchorPoint(Vec2(0.5f, 0.5f));
    Label *pLabel3 = Label::createWithTTF("Jarraitu", "fonts/PT_Sans-Web-Bold.ttf", 30.0);
    pLabel3->setPosition(Vec2( VisibleRect::center().x, mySize - (texture3->getContentSize().height / 2)));
    
    addChild(pButton3);
    addChild(pLabel3);
    
    std::string *name = new std::string("pack-");
    
    int kaliFiveStart = kFiveStart;
    int kaliFourStart = kFourStart;
    int kaliThreeStart = kThreeStart;
    int kaliTwoStart = kTwoStart;
    
    float bonus = 1;
    
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
    
    log("kaliFiveStart = %f, kFourStart = %f, kThreeStart = %f, kTwoStart = %f", (kaliFiveStart * bonus), (kaliFourStart * bonus), (kaliThreeStart * bonus), (kaliTwoStart * bonus));
    
    Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(name->c_str());
    pImage = Sprite::createWithTexture(texture);
    pImage->setPosition(Vec2(VisibleRect::center().x, VisibleRect::center().y - 20));
    addChild(pImage);

    std::stringstream ss;//create a stringstream
    ss << kalifikazioa << " puntu";
    Label *puntos = Label::createWithTTF(ss.str().c_str(), "fonts/PT_Sans-Web-Bold.ttf", 20);
    puntos->setPosition(Vec2(VisibleRect::center().x, VisibleRect::center().y - 90));
    puntos->setHorizontalAlignment(TextHAlignment::CENTER);
    puntos->setVerticalAlignment(TextVAlignment::CENTER);
    puntos->setColor(Color3B(0, 0, 0));
    addChild(puntos);
    
    Sprite *bukatu = Sprite::create("bukatu.png");
    bukatu->setPosition(Vec2(VisibleRect::center().x, VisibleRect::center().y + (texture->getContentSize().height / 2) + 40));
    addChild(bukatu);
    
    delete name;

	return true;
}

void BukatutaScene::buttonJarraitu(Ref* pSender)
{
    CategoryScene *scene = CategoryScene::create();
    
    Director *pDirector = Director::getInstance();
    TransitionFade *tscene = TransitionFade::create(0.5, scene);
    pDirector->replaceScene(tscene);
}

