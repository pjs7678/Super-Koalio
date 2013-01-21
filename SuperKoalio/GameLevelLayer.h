//
//  GameLevelLayer.h
//  SuperKoalio
//
//  Created by JongSu Park on 13. 1. 7..
//
//

#ifndef __SuperKoalio__GameLevelLayer__
#define __SuperKoalio__GameLevelLayer__

#include <cocos2d.h>
#include "Player.h"

using namespace cocos2d;

class GameLevelLayer : public CCLayer {
    
public:
    static CCScene* scene();
    static GameLevelLayer* create();
    bool init();
    
    CCTMXTiledMap *m_Map;
    Player *m_Player;
    
    virtual void update(float dt);
    
    CCPoint tileCoordForPosition(CCPoint position);
    CCRect tileRectFromTileCoord(CCPoint tileCoords);
    CCArray* getSurroundingTilesAtPosition(CCPoint position, CCTMXLayer *layer);
};

#endif /* defined(__SuperKoalio__GameLevelLayer__) */
