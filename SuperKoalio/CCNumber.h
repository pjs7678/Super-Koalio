//
//  CCNumber.h
//  SuperKoalio
//
//  Created by Park JongSu on 13. 1. 21..
//
//

#ifndef __SuperKoalio__CCNumber__
#define __SuperKoalio__CCNumber__

#include <cocos2d.h>

using namespace cocos2d;

typedef enum {
    CCNumberType_int = 1,
    CCNumberType_float,
    CCNumberType_double,
}CCNumberType;

class CCNumber : public CCObject{
    void *p_num;
    CCNumberType m_type;
    
public:
    static CCNumber* create(int num_int);
    static CCNumber* create(float num_float);
    static CCNumber* create(double num_double);
    bool initWithNumber(int num_int);
    bool initWithNumber(float num_float);
    bool initWithNumber(double num_double);
    
    int interValue();
    float floatValue();
    double doubleValue();
};

#endif /* defined(__SuperKoalio__CCNumber__) */
