//
//  DMDUnitTest.hpp
//  DMDString
//
//  Created by Dezel Davis on 6/13/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef DMDUnitTest_hpp
#define DMDUnitTest_hpp

#include <iostream>

namespace dmd{
    class UnitTest{
    private:
        const char* testname = nullptr;
        long passcount;
        long failcount;
        //I got a tip to block all other constuctors except one
        UnitTest();
        UnitTest(UnitTest &);
        UnitTest operator =(UnitTest &);
        
    public:
        UnitTest(const char* name);
        
        long Passcount();
        long Failcount();
        
        void test(const char* action, int cond);
        
        void results();
    };
}
#endif /* DMDUnitTest_hpp */
