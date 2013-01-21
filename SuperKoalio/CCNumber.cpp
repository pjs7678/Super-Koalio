//
//  CCNumber.cpp
//  SuperKoalio
//
//  Created by Park JongSu on 13. 1. 21..
//
//

#include "CCNumber.h"

#pragma mark - create

CCNumber* CCNumber::create(int num_int)
{
    CCNumber *pRet = new CCNumber();
    if(pRet && pRet->initWithNumber(num_int))
    {
        pRet->autorelease();
        return pRet;
    }
    else{
        delete pRet;
        pRet = NULL;
        return pRet;
    }
}

CCNumber* CCNumber::create(float num_float)
{
    CCNumber *pRet = new CCNumber();
    if(pRet && pRet->initWithNumber(num_float))
    {
        pRet->autorelease();
        return pRet;
    }
    else{
        delete pRet;
        pRet = NULL;
        return pRet;
    }
}

CCNumber* CCNumber::create(double num_double)
{
    CCNumber *pRet = new CCNumber();
    if(pRet && pRet->initWithNumber(num_double))
    {
        pRet->autorelease();
        return pRet;
    }
    else{
        delete pRet;
        pRet = NULL;
        return pRet;
    }
}

#pragma mark - init

bool CCNumber::initWithNumber(int num_int)
{
    m_type = CCNumberType_float;
    p_num = malloc(sizeof(float));
    
    return true;
}

bool CCNumber::initWithNumber(float num_float)
{
    m_type = CCNumberType_float;
    p_num = malloc(sizeof(int));
    
    return true;
}

bool CCNumber::initWithNumber(double num_double)
{
    m_type = CCNumberType_double;
    p_num = malloc(sizeof(double));
    
    return true;
}

#pragma mark - value


int CCNumber::interValue()
{
    if(m_type == CCNumberType_int){
        return *(int*)p_num;
    }
    return NULL;
}

float CCNumber::floatValue()
{
    if(m_type == CCNumberType_float){
        return *(float*)p_num;
    }
    return NULL;
}

double CCNumber::doubleValue()
{
    if(m_type == CCNumberType_double){
        return *(double*)p_num;
    }
    return NULL;
}