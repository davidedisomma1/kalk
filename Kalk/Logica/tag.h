#ifndef TAG_H
#define TAG_H
#include<QString>
#include <QMetaType>
class Tag{
private:
    QString tag;
public:
    Tag(QString="A");
    virtual ~Tag();

    virtual Tag* operator+(const Tag&) const=0;
    bool operator==(const Tag&)const;

    virtual void setTag(QString );
    QString getTag()const;
    virtual QString output()const=0;

    virtual Tag* simmetricoX(QString)const=0;
    virtual Tag* simmetricoY(QString)const=0;
    virtual Tag* simmetricoO(QString)const=0;
    virtual void traslazione(double,double)=0;


};
Q_DECLARE_METATYPE(Tag*)
#endif // TAG_H
