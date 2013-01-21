//
//  CCValue.h
//  SuperKoalio
//
//  Created by Park JongSu on 13. 1. 21..
//
//

/*
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 */

#ifndef SuperKoalio_CCValue_h
#define SuperKoalio_CCValue_h

#include "cocos2d.h"

namespace cocos2d_extensions {
    template <class _typeT>
    class CCValue : public cocos2d::CCObject
    {
    public:
        CCValue()
        : cocos2d::CCObject()
        {
            memset(&m_type, 0, sizeof(_typeT));
        }
        
        static CCValue* valueWithValue(const _typeT &value)
        {
            CCValue<_typeT> *newValue = new CCValue<_typeT>;
            if (newValue && newValue->initWithValue(value))
            {
                newValue->autorelease();
                return newValue;
            }
            else{
                CC_SAFE_RELEASE_NULL(newValue);
                return NULL;
            }
        }
        
        static CCValue* valueWithValue(const CCValue<_typeT> *rhs)
        {
            return valueWithValue(rhs->getValue());
        }
        
        inline bool initWithValue(const _typeT &value)
        {
            memcpy(&m_type, &value, sizeof(_typeT));
            return true;
        }
        
        inline int compare(const CCValue<_typeT> *rhs)
        {
            return memcmp((void *)&m_type, (void *)&rhs->m_type, sizeof(_typeT));
        }
        
        inline bool isEqualToValue(const CCValue<_typeT> *rhs)
        {
            return compare(rhs) == 0 ? 1 : 0;
        }
        
        inline bool isEqualToValue(const CCValue<_typeT> *rhs, int fpCmp(const _typeT &t1, const _typeT &t2))
        {
            return fpCmp(m_type, rhs->m_type) == 0 ? 1 : 0;
        }
        
        
        CC_SYNTHESIZE_READONLY(_typeT, m_type, Value);
     
    protected:
        ~CCValue()
        {
            
        }
        
    private:
    };
}

#endif
