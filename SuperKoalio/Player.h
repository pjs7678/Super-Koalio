//
//  Player.h
//  SuperKoalio
//
//  Created by JongSu Park on 13. 1. 7..
//
//

#ifndef __SuperKoalio__Player__
#define __SuperKoalio__Player__

#include <cocos2d.h>

using namespace cocos2d;

class Player : public CCSprite {
public:
    static Player* create(const char *fileName);
    virtual bool initWithFile(const char *fileName);
    virtual void update(float dt);
    
    CC_SYNTHESIZE(CCPoint, m_Velocity, Velocity);
    
    CCRect collisionBoundingBox();
};

#endif /* defined(__SuperKoalio__Player__) */
