//
//  Player.cpp
//  SuperKoalio
//
//  Created by JongSu Park on 13. 1. 7..
//
//

#include "Player.h"

Player* Player::create(const char *fileName)
{
    Player *aRet = new Player();
    if(aRet && aRet->initWithFile(fileName)){
        aRet->autorelease();
        return aRet;
    }
    else{
        delete aRet;
        aRet = NULL;
        return aRet;
    }
}

bool Player::initWithFile(const char *fileName)
{
    if(CCSprite::initWithFile(fileName))
    {
        this->setVelocity(ccp(0.0, 0.0));
        
        return true;
    }
    {
        return false;
    }
}

#pragma mark - Player object
CCRect Player::collisionBoundingBox()
{
    CCRect boundingBoxRect = this->boundingBox();
    return CCRectMake(boundingBoxRect.getMinX() + 2, boundingBoxRect.getMinY(), boundingBoxRect.size.width - 2*2, boundingBoxRect.size.height);
}

#pragma mark - update
void Player::update(float dt)
{
    CCPoint gravity = ccp(0.0, -450.0);
    
    CCPoint gravityStep = ccpMult(gravity, dt);
    
    this->setVelocity(ccpAdd(this->getVelocity(), gravityStep));
    CCPoint stepVelocity = ccpMult(this->getVelocity(), dt);
    
    this->setPosition(ccpAdd(this->getPosition(), stepVelocity));
}