//
//  DMDUnitTest.cpp
//  DMDString
//
//  Created by Dezel Davis on 6/13/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "DMDUnitTest.hpp"

//This is all fairly straight forward, nothing special to note
dmd::UnitTest::UnitTest(const char* name){
    testname = name;
    passcount = 0;
    failcount = 0;
}

long dmd::UnitTest::Passcount(){return passcount;}
long dmd::UnitTest::Failcount(){return failcount;}

void dmd::UnitTest::test(const char* action, int cond){
    const char* result = nullptr;
    if(cond){
        result = "Passed.";
        ++passcount;
    }else{
        result = "Failed.";
        ++failcount;
    }
    std::cout << testname << ": " << action << " = " << result << std::endl;
}

void dmd::UnitTest::results(){
    std::cout << testname << " has ended with " << Passcount() << " pass(es) and " << \
    Failcount() << " fail(s)." << std::endl;
}
