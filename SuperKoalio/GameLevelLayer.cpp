//
//  GameLevelLayer.cpp
//  SuperKoalio
//
//  Created by JongSu Park on 13. 1. 7..
//
//

#include "GameLevelLayer.h"
#include "CCNumber.h"

CCScene* GameLevelLayer::scene()
{
    CCScene *scene = CCScene::create();
    
    GameLevelLayer *layer = GameLevelLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

GameLevelLayer* GameLevelLayer::create()
{
    GameLevelLayer *aRet = new GameLevelLayer();
    if(aRet && aRet->init())
    {
        aRet->autorelease();
        return aRet;
    }
    else{
        delete aRet;
        aRet = NULL;
        return aRet;
    }
}

bool GameLevelLayer::init()
{
    if(CCLayer::init())
    {
        CCLayerColor *blueSky = CCLayerColor::create(ccc4(100, 100, 250, 255));
        this->addChild(blueSky);
        
        m_Map = CCTMXTiledMap::create("level1.tmx");
        this->addChild(m_Map);
        
        m_Player = Player::create("koalio_stand.png");
        m_Player->setPosition(ccp(100, 50));
        m_Map->addChild(m_Player, 15);
        
        
        this->scheduleUpdate();
        
        return true;
    }
    
    return false;
}

#pragma markr - helper methods
CCPoint GameLevelLayer::tileCoordForPosition(CCPoint position)
{
    float x = floor(getPositionX() / m_Map->getTileSize().width);
    float levelHeightInPixels = m_Map->getMapSize().height * m_Map->getTileSize().height;
    float y = floor(levelHeightInPixels - getPositionY()) / m_Map->getTileSize().height;
    
    return ccp(x, y);
}

CCRect GameLevelLayer::tileRectFromTileCoord(CCPoint tileCoords)
{
    float levelHeightInPixels = m_Map->getMapSize().height * m_Map->getTileSize().height;
    CCPoint origin = ccp(tileCoords.x * m_Map->getTileSize().width, levelHeightInPixels - ((tileCoords.y + 1) * m_Map->getTileSize().height));
    
    return CCRectMake(origin.x, origin.y, m_Map->getTileSize().width, m_Map->getTileSize().height);
}

CCArray* GameLevelLayer::getSurroundingTilesAtPosition(CCPoint position, CCTMXLayer *layer)
{
    CCPoint plPos = this->tileCoordForPosition(position);
    
    CCArray *gids = CCArray::create();
    
    for(int i=0 ; i<9 ; i++){
        int c = i%3;
        int r = (int)(i/3);
        CCPoint tilePos = ccp(plPos.x + (c - 1), plPos.y + (r - 1));
        
        int tgid = layer->tileGIDAt(tilePos);
        
        CCRect tileRect = this->tileRectFromTileCoord(tilePos);

        CCDictionary *tileDict = CCDictionary::create();
        tileDict->setObject(CCNumber::create(tgid), std::string("gid"));
        tileDict->setObject(CCNumber::create(tileRect.origin.x), std::string("x"));
        tileDict->setObject(CCNumber::create(tileRect.origin.y), std::string("y"));
        tileDict
    }
}


#pragma mark - update
void GameLevelLayer::update(float dt)
{
    m_Player->update(dt);
}