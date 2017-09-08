//
//  MainMenuLayer.cpp
//  TrivialJokoa
//
//  Created by iker on 11/12/12.
//
//

#include "MainMenuLayer.h"
#include "../Scenes/CategoryScene.h"
#include "../Scenes/ProfilaScene.h"
#include "SimpleAudioEngine.h"
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//#include "/Applications/cocos2d-x-2.1.5/cocos2dx/platform/android/jni/Urljni.h"
//#endif


using namespace CocosDenshion;

MainMenuLayer::MainMenuLayer()
{
    
}

MainMenuLayer::~MainMenuLayer()
{
    
}


bool MainMenuLayer::init()
{
    return true;
}

void MainMenuLayer::onNodeLoaded(Node * pNode, cocosbuilder::NodeLoader * pNodeLoader)
{

}

SEL_CallFuncN MainMenuLayer::onResolveCCBCCCallFuncSelector(Ref * pTarget, const char* pSelectorName) { return NULL; };

SEL_MenuHandler MainMenuLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char* pSelectorName)
{
    return NULL;
}

cocos2d::extension::Control::Handler MainMenuLayer::onResolveCCBCCControlSelector(Ref* pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "playClicked", MainMenuLayer::playClicked);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "profilaClicked", MainMenuLayer::profilaClicked);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buruzClicked", MainMenuLayer::buruzClicked);
    return NULL;
}

void MainMenuLayer::playClicked(Ref *pSender, cocos2d::extension::Control::EventType pCCControlEvent)
{
    SimpleAudioEngine::getInstance()->playEffect(std::string(FileUtils::getInstance()->fullPathForFilename("sounds/button.wav")).c_str());
    CategoryScene *scene = CategoryScene::create();
    
    Director *pDirector = Director::getInstance();
    TransitionFade *tscene = TransitionFade::create(0.5, scene);
    pDirector->replaceScene(tscene);
}

void MainMenuLayer::profilaClicked(Ref *pSender, cocos2d::extension::Control::EventType pCCControlEvent)
{
    SimpleAudioEngine::getInstance()->playEffect(std::string(FileUtils::getInstance()->fullPathForFilename("sounds/button.wav")).c_str());
    ProfilaScene *scene = ProfilaScene::create();
    
    Director *pDirector = Director::getInstance();
    TransitionFade *tscene = TransitionFade::create(0.5, scene);
    pDirector->replaceScene(tscene);
}

void MainMenuLayer::buruzClicked(Ref *pSender, cocos2d::extension::Control::EventType pCCControlEvent)
{
    SimpleAudioEngine::getInstance()->playEffect(std::string(FileUtils::getInstance()->fullPathForFilename("sounds/button.wav")).c_str());
//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//        openURLJNI("http://auskalo.net/honi-buruz/");
//    #else
        Application::getInstance()->openURL("http://auskalo.net/honi-buruz/");
//    #endif
    
}
