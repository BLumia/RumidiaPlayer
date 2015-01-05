/****************************************************************************
** Meta object code from reading C++ file 'rumidiaplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RumidiaPlayer/rumidiaplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rumidiaplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RumidiaPlayer_t {
    QByteArrayData data[13];
    char stringdata[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RumidiaPlayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RumidiaPlayer_t qt_meta_stringdata_RumidiaPlayer = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 10),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 22),
QT_MOC_LITERAL(4, 49, 23),
QT_MOC_LITERAL(5, 73, 20),
QT_MOC_LITERAL(6, 94, 18),
QT_MOC_LITERAL(7, 113, 10),
QT_MOC_LITERAL(8, 124, 31),
QT_MOC_LITERAL(9, 156, 32),
QT_MOC_LITERAL(10, 189, 30),
QT_MOC_LITERAL(11, 220, 5),
QT_MOC_LITERAL(12, 226, 25)
    },
    "RumidiaPlayer\0UpdateTime\0\0"
    "on_loadFileBtn_clicked\0on_NOFXCheckBox_clicked\0"
    "on_loadSFBtn_clicked\0on_playBtn_clicked\0"
    "applyTempo\0on_progressSlider_sliderPressed\0"
    "on_progressSlider_sliderReleased\0"
    "on_progressSlider_valueChanged\0value\0"
    "on_volSlider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RumidiaPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void RumidiaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RumidiaPlayer *_t = static_cast<RumidiaPlayer *>(_o);
        switch (_id) {
        case 0: _t->UpdateTime(); break;
        case 1: _t->on_loadFileBtn_clicked(); break;
        case 2: _t->on_NOFXCheckBox_clicked(); break;
        case 3: _t->on_loadSFBtn_clicked(); break;
        case 4: _t->on_playBtn_clicked(); break;
        case 5: _t->applyTempo(); break;
        case 6: _t->on_progressSlider_sliderPressed(); break;
        case 7: _t->on_progressSlider_sliderReleased(); break;
        case 8: _t->on_progressSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_volSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RumidiaPlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RumidiaPlayer.data,
      qt_meta_data_RumidiaPlayer,  qt_static_metacall, 0, 0}
};


const QMetaObject *RumidiaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RumidiaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RumidiaPlayer.stringdata))
        return static_cast<void*>(const_cast< RumidiaPlayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RumidiaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
