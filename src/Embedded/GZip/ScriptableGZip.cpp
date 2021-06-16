/****************************************************************************
 *
 * Copyright (C) 2001~2016 Neutrino International Inc.
 *
 * Author   : Brian Lin ( Vladimir Lin , Vladimir Forest )
 * E-mail   : lin.foxman@gmail.com
 *          : lin.vladimir@gmail.com
 *          : wolfram_lin@yahoo.com
 *          : wolfram_lin@sina.com
 *          : wolfram_lin@163.com
 * Skype    : wolfram_lin
 * WeChat   : 153-0271-7160
 * WhatsApp : 153-0271-7160
 * QQ       : lin.vladimir@gmail.com
 * URL      : http://qtgzip.sourceforge.net/
 *
 * QtGZip acts as an interface between Qt and GNU GZip library.
 * Please keep QtGZip as simple as possible.
 *
 * Copyright 2001 ~ 2016
 *
 ****************************************************************************/

#include <qtgzip.h>

QT_BEGIN_NAMESPACE

ScriptableGZip:: ScriptableGZip ( QObject * parent )
               : QObject        (           parent )
               , QScriptable    (                  )
               , QtGZip         (                  )
{
}

ScriptableGZip::~ScriptableGZip (void)
{
}

bool ScriptableGZip::ToGZip(QString file,QString gzip,int level,int workFactor)
{
  return FileToGZip ( file , gzip , level , workFactor ) ;
}

bool ScriptableGZip::ToFile(QString gzip,QString file)
{
  return GZipToFile ( gzip , file ) ;
}

QScriptValue ScriptableGZip::Attachment(QScriptContext * context,QScriptEngine * engine)
{
  ScriptableGZip * gzip = new ScriptableGZip ( engine ) ;
  return engine -> newQObject                ( gzip   ) ;
}

QT_END_NAMESPACE
