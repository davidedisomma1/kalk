#include "tag.h"

Tag::Tag(QString s):tag(s){}
Tag::~Tag(){}

QString Tag::getTag()const{
    return tag;
}

void Tag::setTag(QString s){
    tag=s;
}

bool Tag::operator==(const Tag& t)const{
    return tag==t.getTag();
}
