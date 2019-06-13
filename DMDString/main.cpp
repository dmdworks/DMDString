//
//  main.cpp
//  DMDString
//
//  Created by Dezel Davis on 5/1/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "dmdstring.hpp"
#include "DMDUnitTest.hpp"
using namespace dmd;

int main(int argc, const char * argv[]) {
    /* This is a series of tests to introduce the dmd::string, my own
     string class. It's not at all fancy nor should be used in serious
     projects. I created it as I needed a string class whose boolean operators
     I understood to compare data, std::string booleans were beyond me. Anyway,
     this was really cool to do hope to make more things in the dmd namespace.
     */
    
    UnitTest UT("DMDString Test");
    
    string name = "Jacob";
    UT.test("Assignment op", (name == "Jacob"));
    
    UT.test("Lenght func", (name.Lenght() == 5));
    
    string lastname = " Steveson";
    string fullname = name + lastname;
    UT.test("Addition op", (fullname == "Jacob Steveson"));
    
    fullname += " Hendrix";
    UT.test("Addition/Assignment op", (fullname == "Jacob Steveson Hendrix"));
    
    UT.test("Greater than op", (fullname > name));
    
    UT.test("Less than op", (name < fullname));
    
    UT.test("Not equal to op", (name != fullname));
    
    string namecopy = fullname;
    UT.test("Equal to op", (namecopy == fullname));
    
    UT.test("Index op", (name[2] == 'c'));
    
    lastname.Reset();
    UT.test("Reset func", (!lastname));
    
    name = std::move(fullname);
    UT.test("Move constructor", (name == "Jacob Steveson Hendrix"));
    
    UT.results();
    return 0;
}
