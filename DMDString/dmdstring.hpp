//
//  dmdstring.hpp
//  DMDString
//
//  Created by Dezel Davis on 5/1/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef dmdstring_hpp
#define dmdstring_hpp

#include <iostream>
namespace dmd{
    class string{
    private:
        char* str = nullptr;
        unsigned long str_len = 0;
        
        unsigned long GetLenght(const char* cstr);
        unsigned long GetLenght(string & otherstr);
        //This is where the array is actually made
        char* alloc(size_t size);
    
    public:
        string();
        
        string(const char* cstr);
        
        string(string & otherstr);
        
        string(string && otherstr) noexcept;
        //I added this for construction but for the rest of the funcs, convert the
        //std::string into a c-style string
        string(std::string & otherstr);
        
        ~string();
        
        void Reset();
        
        unsigned long Lenght();
        
        char* c_str();
        
        //Arthmethic operators I wanted so far
        string & operator =(const char* cstr);
        string & operator =(string & otherstr);
        string & operator +(const char* cstr);
        string & operator +(string & otherstr);
        string & operator +=(const char* cstr);
        string & operator +=(string & otherstr);
        
        //The booleans
        bool operator >(const char* cstr);
        bool operator >(string & otherstr);
        bool operator <(const char* cstr);
        bool operator <(string & otherstr);
        bool operator !=(string & otherstr);
        bool operator !=(const char* cstr);
        bool operator ==(const char* cstr);
        bool operator ==(string & otherstr);
        
        char operator [](unsigned long index);
        
        operator std::string();
        
        operator const char*();
        
        std::ostream & operator <<(std::ostream & o);
    };
}
#endif /* dmdstring_hpp */
