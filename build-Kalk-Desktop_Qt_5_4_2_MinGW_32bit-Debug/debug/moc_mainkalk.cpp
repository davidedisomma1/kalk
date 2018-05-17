/****************************************************************************
** Meta object code from reading C++ file 'mainkalk.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Kalk/Grafica/mainkalk.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainkalk.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainKalk_t {
    QByteArrayData data[16];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainKalk_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainKalk_t qt_meta_stringdata_MainKalk = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainKalk"
QT_MOC_LITERAL(1, 9, 9), // "creaPunto"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "creaLinea"
QT_MOC_LITERAL(4, 30, 7), // "elimina"
QT_MOC_LITERAL(5, 38, 9), // "cambiaTag"
QT_MOC_LITERAL(6, 48, 10), // "simmetriaX"
QT_MOC_LITERAL(7, 59, 10), // "simmetriaY"
QT_MOC_LITERAL(8, 70, 10), // "simmetriaO"
QT_MOC_LITERAL(9, 81, 11), // "traslazione"
QT_MOC_LITERAL(10, 93, 9), // "addizione"
QT_MOC_LITERAL(11, 103, 9), // "distanzaO"
QT_MOC_LITERAL(12, 113, 9), // "distanzaP"
QT_MOC_LITERAL(13, 123, 9), // "lunghezza"
QT_MOC_LITERAL(14, 133, 10), // "puntoMedio"
QT_MOC_LITERAL(15, 144, 15) // "sommaVettoriale"

    },
    "MainKalk\0creaPunto\0\0creaLinea\0elimina\0"
    "cambiaTag\0simmetriaX\0simmetriaY\0"
    "simmetriaO\0traslazione\0addizione\0"
    "distanzaO\0distanzaP\0lunghezza\0puntoMedio\0"
    "sommaVettoriale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainKalk[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainKalk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainKalk *_t = static_cast<MainKalk *>(_o);
        switch (_id) {
        case 0: _t->creaPunto(); break;
        case 1: _t->creaLinea(); break;
        case 2: _t->elimina(); break;
        case 3: _t->cambiaTag(); break;
        case 4: _t->simmetriaX(); break;
        case 5: _t->simmetriaY(); break;
        case 6: _t->simmetriaO(); break;
        case 7: _t->traslazione(); break;
        case 8: _t->addizione(); break;
        case 9: _t->distanzaO(); break;
        case 10: _t->distanzaP(); break;
        case 11: _t->lunghezza(); break;
        case 12: _t->puntoMedio(); break;
        case 13: _t->sommaVettoriale(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainKalk::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainKalk.data,
      qt_meta_data_MainKalk,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainKalk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainKalk::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainKalk.stringdata))
        return static_cast<void*>(const_cast< MainKalk*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainKalk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
