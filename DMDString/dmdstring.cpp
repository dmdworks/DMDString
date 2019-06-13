//
//  dmdstring.cpp
//  DMDString
//
//  Created by Dezel Davis on 5/1/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "dmdstring.hpp"

unsigned long dmd::string::GetLenght(const char* cstr){
    unsigned long counter = 0;
    while(cstr[counter] != '\0'){
        ++counter;
    }
    return counter;
}

unsigned long dmd::string::GetLenght(string & otherstr){
    unsigned long counter = 0;
    while(otherstr[counter] != '\0'){
        ++counter;
    }
    return counter;
}

char* dmd::string::alloc(size_t size){
    str = new char[size + 1];
    str[size] = '\0';
    return str;
}


dmd::string::string(){
    Reset();
}

dmd::string::string(const char* cstr){
    Reset();
    str_len = GetLenght(cstr);
    str = alloc(str_len);
    for(unsigned long i= 0; i<=str_len; ++i){
        str[i] = cstr[i];
    }
}

dmd::string::string(string & otherstr){
    Reset();
    str_len = GetLenght(otherstr);
    str = alloc(str_len);
    for(unsigned long i= 0; i<=str_len; ++i){
        str[i] = otherstr[i];
    }
}

dmd::string::string(string && otherstr) noexcept{
    Reset();
    str = std::move(otherstr.str);
    str_len = std::move(otherstr.str_len);
    otherstr.Reset();
}

dmd::string::string(std::string & otherstr){
    Reset();
    str_len = otherstr.size();
    str = alloc(str_len);
    for(unsigned long i= 0; i<=str_len; ++i){
        str[i] = otherstr[i];
    }
}

dmd::string::~string(){
    Reset();
}

void dmd::string::Reset(){
    if(str){
        delete str;
        str = nullptr;
    }else{
        str = nullptr;
    }
    str_len = 0;
}

unsigned long dmd::string::Lenght(){
    return str_len;
}

char* dmd::string::c_str(){
    return str;
}

dmd::string & dmd::string::operator =(const char* cstr){
    if(*this == cstr){
        return *this;
    }
    Reset();
    str_len = GetLenght(cstr);
    str = alloc(str_len);
    for(unsigned long i= 0; i<=str_len; ++i){
        str[i] = cstr[i];
    }
    return *this;
}
dmd::string & dmd::string::operator =(string & otherstr){
    if(*this == otherstr){
        return *this;
    }
    Reset();
    str_len = GetLenght(otherstr);
    str = alloc(str_len);
    for(unsigned long i= 0; i<=str_len; ++i){
        str[i] = otherstr[i];
    }
    return *this;
}
dmd::string & dmd::string::operator +(const char* cstr){
    unsigned long bufflenght = str_len + GetLenght(cstr);
    char* buff = new char[bufflenght+1];
    buff[bufflenght] = '\0';
    for(unsigned long i=0; i<bufflenght; ++i){
        if(i<str_len){
            buff[i] = str[i];
        }else{
            buff[i] = cstr[i-str_len];
        }
    }
    Reset();
    str = alloc(bufflenght);
    str_len = bufflenght;
    for(unsigned long i=0; i<bufflenght; ++i){
        str[i] = buff[i];
    }
    delete[] buff;
    return *this;
}
dmd::string & dmd::string::operator +(string & otherstr){
    unsigned long bufflenght = str_len + otherstr.Lenght();
    char* buff = new char[bufflenght+1];
    buff[bufflenght] = '\0';
    for(unsigned long i=0; i<bufflenght; ++i){
        if(i<str_len){
            buff[i] = str[i];
        }else{
            buff[i] = otherstr[i-str_len];
        }
    }
    Reset();
    str = alloc(bufflenght);
    str_len = bufflenght;
    for(unsigned long i=0; i<bufflenght; ++i){
        str[i] = buff[i];
    }
    delete[] buff;
    return *this;
}
dmd::string & dmd::string::operator +=(const char* cstr){
    unsigned long bufflenght = str_len + GetLenght(cstr);
    char* buff = new char[bufflenght+1];
    buff[bufflenght] = '\0';
    for(unsigned long i=0; i<bufflenght; ++i){
        if(i<str_len){
            buff[i] = str[i];
        }else{
            buff[i] = cstr[i-str_len];
        }
    }
    Reset();
    str = alloc(bufflenght);
    str_len = bufflenght;
    for(unsigned long i=0; i<bufflenght; ++i){
        str[i] = buff[i];
    }
    delete[] buff;
    return *this;
}
dmd::string & dmd::string::operator +=(string & otherstr){
    unsigned long bufflenght = str_len + otherstr.Lenght();
    char* buff = new char[bufflenght+1];
    buff[bufflenght] = '\0';
    for(unsigned long i=0; i<bufflenght; ++i){
        if(i<str_len){
            buff[i] = str[i];
        }else{
            buff[i] = otherstr[i-str_len];
        }
    }
    Reset();
    str = alloc(bufflenght);
    str_len = bufflenght;
    for(unsigned long i=0; i<bufflenght; ++i){
        str[i] = buff[i];
    }
    delete[] buff;
    return *this;
}
bool dmd::string::operator >(const char* cstr){
    if(str_len > GetLenght(cstr)){
        return true;
    }
    unsigned long Rstr = 0;
    unsigned long Lstr = 0;
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] > cstr[i]){
            Rstr++;
        }else{
            Lstr++;
        }
    }
    if(Rstr < Lstr){
        return true;
    }else{
        return false;
    }
}
bool dmd::string::operator >(string & otherstr){
    if(str_len > otherstr.Lenght()){
        return true;
    }
    unsigned long Rstr = 0;
    unsigned long Lstr = 0;
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] > otherstr[i]){
            Rstr++;
        }else{
            Lstr++;
        }
    }
    if(Rstr > Lstr){
        return true;
    }else{
        return false;
    }
}
bool dmd::string::operator <(const char* cstr){
    if(str_len < GetLenght(cstr)){
        return true;
    }
    unsigned long Rstr = 0;
    unsigned long Lstr = 0;
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] < cstr[i]){
            Rstr++;
        }else{
            Lstr++;
        }
    }
    if(Rstr < Lstr){
        return true;
    }else{
        return false;
    }
}
bool dmd::string::operator <(string & otherstr){
    if(str_len < otherstr.Lenght()){
        return true;
    }
    unsigned long Rstr = 0;
    unsigned long Lstr = 0;
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] < otherstr[i]){
            Rstr++;
        }else{
            Lstr++;
        }
    }
    if(Rstr < Lstr){
        return true;
    }else{
        return false;
    }
}
bool dmd::string::operator !=(string & otherstr){
    if(str_len != otherstr.Lenght()){
        return true;
    }
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] != otherstr[i]){
            return true;
        }
    }
    return false;
}
bool dmd::string::operator !=(const char* cstr){
    if(str_len != GetLenght(cstr)){
        return true;
    }
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] != cstr[i]){
            return true;
        }
    }
    return false;
}
bool dmd::string::operator ==(const char* cstr){
    if(str_len != GetLenght(cstr)){
        return false;
    }
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] != cstr[i]){
            return false;
        }
    }
    return true;
}
bool dmd::string::operator ==(string & otherstr){
    if(str_len != otherstr.Lenght()){
        return false;
    }
    for(unsigned long i=0; i<str_len; ++i){
        if(str[i] != otherstr[i]){
            return false;
        }
    }
    return true;
}

char dmd::string::operator [](unsigned long index){
    return str[index];
}

dmd::string::operator std::string(){
    return std::string(str);
}

dmd::string::operator const char*(){
    return str;
}

std::ostream & dmd::string::operator <<(std::ostream & o){
    o << str;
    return o;
}
