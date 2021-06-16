NAME         = QtGZip
TARGET       = $${NAME}
QT           = core
QT          -= gui
CONFIG(static,static|shared) {
QT          -= script
} else {
QT          += script
}

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/QtGZip

HEADERS     += $${PWD}/../../include/QtGZip/QtGZip
HEADERS     += $${PWD}/../../include/QtGZip/qtgzip.h

SOURCES     += $${PWD}/qtgzip.cpp
SOURCES     += $${PWD}/ScriptableGZip.cpp

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)
