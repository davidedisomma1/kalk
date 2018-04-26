#ifndef TAG_H
#define TAG_H
#include<QString>

class Tag{
private:
    QString tag;
public:
    Tag(QString="A");
    QString getTag()const;
    bool operator==(const Tag&)const;
    virtual void setTag(QString);
    virtual QString output()const=0;
    virtual ~Tag()=0;
};

#endif // TAG_H
