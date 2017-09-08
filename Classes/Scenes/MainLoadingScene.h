//
//  MainLoadingScene.h
//  TrivialJokoa
//
//  Created by iker on 11/12/12.
//
//

#ifndef __TrivialJokoa__MainLoadingScene__
#define __TrivialJokoa__MainLoadingScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Helpers/TrivialAPI.h"
#include "../Helpers/SQLHelper.h"
#include "../Helpers/json/cJSON.h"
#include "../Models/KategoriaModel.h"
#include "../Models/MultzoaModel.h"
#include "../Models/GalderaModel.h"

using namespace cocos2d;

class MainLoadingScene : public Scene
{
public:
    MainLoadingScene();
	~MainLoadingScene();
    
	virtual bool init();
    CREATE_FUNC(MainLoadingScene);
    
private:
    TrivialAPI *_api;
    void finishLoading();
    void updateProgress();
    void apiCallSchedule();
    void parseData();
    void parseKategoriak(std::string str);
    void parseMultzoak(std::string str);
    void parseGalderak(std::string str);
    SQLHelper *_sqlHelper;
    int _previousProgress;
    int _progress;
    Sprite *loading;
};

#endif /* defined(__TrivialJokoa__MainLoadingScene__) */
