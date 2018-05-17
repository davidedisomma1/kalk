/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Kalk/Grafica/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[22];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 9), // "creaPunto"
QT_MOC_LITERAL(2, 17, 6), // "Punto*"
QT_MOC_LITERAL(3, 24, 0), // ""
QT_MOC_LITERAL(4, 25, 9), // "creaLinea"
QT_MOC_LITERAL(5, 35, 14), // "creaRettangolo"
QT_MOC_LITERAL(6, 50, 7), // "elimina"
QT_MOC_LITERAL(7, 58, 9), // "cambiaTag"
QT_MOC_LITERAL(8, 68, 10), // "simmetriaX"
QT_MOC_LITERAL(9, 79, 10), // "simmetriaY"
QT_MOC_LITERAL(10, 90, 10), // "simmetriaO"
QT_MOC_LITERAL(11, 101, 11), // "traslazione"
QT_MOC_LITERAL(12, 113, 9), // "addizione"
QT_MOC_LITERAL(13, 123, 9), // "distanzaO"
QT_MOC_LITERAL(14, 133, 9), // "distanzaP"
QT_MOC_LITERAL(15, 143, 9), // "lunghezza"
QT_MOC_LITERAL(16, 153, 10), // "puntoMedio"
QT_MOC_LITERAL(17, 164, 15), // "sommaVettoriale"
QT_MOC_LITERAL(18, 180, 16), // "connettiSpezzata"
QT_MOC_LITERAL(19, 197, 4), // "area"
QT_MOC_LITERAL(20, 202, 13), // "nomeEsistente"
QT_MOC_LITERAL(21, 216, 17) // "selezionaElemento"

    },
    "Dialog\0creaPunto\0Punto*\0\0creaLinea\0"
    "creaRettangolo\0elimina\0cambiaTag\0"
    "simmetriaX\0simmetriaY\0simmetriaO\0"
    "traslazione\0addizione\0distanzaO\0"
    "distanzaP\0lunghezza\0puntoMedio\0"
    "sommaVettoriale\0connettiSpezzata\0area\0"
    "nomeEsistente\0selezionaElemento"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    3, 0x0a /* Public */,
       4,    0,  110,    3, 0x0a /* Public */,
       5,    0,  111,    3, 0x0a /* Public */,
       6,    0,  112,    3, 0x0a /* Public */,
       7,    0,  113,    3, 0x0a /* Public */,
       8,    0,  114,    3, 0x0a /* Public */,
       9,    0,  115,    3, 0x0a /* Public */,
      10,    0,  116,    3, 0x0a /* Public */,
      11,    0,  117,    3, 0x0a /* Public */,
      12,    0,  118,    3, 0x0a /* Public */,
      13,    0,  119,    3, 0x0a /* Public */,
      14,    0,  120,    3, 0x0a /* Public */,
      15,    0,  121,    3, 0x0a /* Public */,
      16,    0,  122,    3, 0x0a /* Public */,
      17,    0,  123,    3, 0x0a /* Public */,
      18,    0,  124,    3, 0x0a /* Public */,
      19,    0,  125,    3, 0x0a /* Public */,
      20,    0,  126,    3, 0x0a /* Public */,
      21,    0,  127,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        switch (_id) {
        case 0: { Punto* _r = _t->creaPunto();
            if (_a[0]) *reinterpret_cast< Punto**>(_a[0]) = _r; }  break;
        case 1: _t->creaLinea(); break;
        case 2: _t->creaRettangolo(); break;
        case 3: _t->elimina(); break;
        case 4: _t->cambiaTag(); break;
        case 5: _t->simmetriaX(); break;
        case 6: _t->simmetriaY(); break;
        case 7: _t->simmetriaO(); break;
        case 8: _t->traslazione(); break;
        case 9: _t->addizione(); break;
        case 10: _t->distanzaO(); break;
        case 11: _t->distanzaP(); break;
        case 12: _t->lunghezza(); break;
        case 13: _t->puntoMedio(); break;
        case 14: _t->sommaVettoriale(); break;
        case 15: _t->connettiSpezzata(); break;
        case 16: _t->area(); break;
        case 17: _t->nomeEsistente(); break;
        case 18: _t->selezionaElemento(); break;
        default: ;
        }
    }
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
