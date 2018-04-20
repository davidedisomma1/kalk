#ifndef TAG_H
#define TAG_H
#include<Qstring>

class Tag
{
private:
    QString tag;
public:
    Tag(QString="A");
    QString getTag()const;
    void setTag(QString);
    bool operator==(const Tag&)const;
    virtual ~Tag()=0;
};

#endif // TAG_H
