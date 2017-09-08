//
//  BukatutaScene.h
//  TrivialJokoa
//
//  Created by Iker Mendilibar Fernandez on 11/01/13.
//
//

#ifndef __TrivialJokoa__BukatutaScene__
#define __TrivialJokoa__BukatutaScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Models/MultzoaModel.h"

USING_NS_CC;
USING_NS_CC_EXT;

class BukatutaScene : public Scene
{
public:
    BukatutaScene();
    ~BukatutaScene();
    virtual bool init();
        
    static BukatutaScene* create(MultzoaModel *multzoa)
    {
        BukatutaScene *pRet = new BukatutaScene();
        pRet->multzoa = multzoa;
        
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    static BukatutaScene* create()
    {
        BukatutaScene *pRet = new BukatutaScene();
        
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
private:
    MultzoaModel *multzoa;
    Sprite *pImage;
    Sprite *pStars;
    void buttonJarraitu(Ref* pSender);
};


#endif /* defined(__TrivialJokoa__BukatutaScene__) */
