QT             = core
QT            -= gui
QT            += QtGZip

CONFIG(debug, debug|release) {
TARGET         = gziptoold
} else {
TARGET         = gziptool
}

CONFIG        += console

TEMPLATE       = app

SOURCES       += $${PWD}/gziptool.cpp

win32 {
RC_FILE        = $${PWD}/gziptool.rc
OTHER_FILES   += $${PWD}/gziptool.rc
OTHER_FILES   += $${PWD}/*.js
}
