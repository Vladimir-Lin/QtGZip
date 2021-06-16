/****************************************************************************
 *
 * Copyright (C) 2015 Neutrino International Inc.
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

//////////////////////////////////////////////////////////////////////////////

QtGZip:: QtGZip   (void)
       : gzPacket (NULL)
{
}

QtGZip::~QtGZip(void)
{
  CleanUp ( ) ;
}

QString QtGZip::Version(void)
{
  return QString ( "1.7.0" ) ;
}

bool QtGZip::isGZip(QByteArray & header)
{
  return true ;
}

void QtGZip::CleanUp(void)
{
}

bool QtGZip::IsCorrect(int returnCode)
{
  return false ;
}

bool QtGZip::IsEnd(int returnCode)
{
  return false ;
}

bool QtGZip::IsFault(int returnCode)
{
  return false ;
}

int QtGZip::BeginCompress(int blockSize100k,int workFactor)
{
  return 0 ;
}

int QtGZip::BeginCompress(QVariantList arguments)
{
  return 0 ;
}

int QtGZip::doCompress(const QByteArray & Source,QByteArray & Compressed)
{
  return 0 ;
}

int QtGZip::doSection(QByteArray & Source,QByteArray & Compressed)
{
  return 0 ;
}

int QtGZip::CompressDone(QByteArray & Compressed)
{
  return 0 ;
}

int QtGZip::BeginDecompress(void)
{
  return 0 ;
}

int QtGZip::doDecompress(const QByteArray & Source,QByteArray & Decompressed)
{
  return 0 ;
}

int QtGZip::undoSection(QByteArray & Source,QByteArray & Decompressed)
{
  return 0 ;
}

int QtGZip::DecompressDone(void)
{
  return 0 ;
}

bool QtGZip::IsTail(QByteArray & header)
{
  return false ;
}

bool QtGZip::CompressHeader(QByteArray & header)
{
  return true                                 ;
}

bool QtGZip::CompressTail(QByteArray & header)
{
  return true ;
}

//////////////////////////////////////////////////////////////////////////////

QByteArray GZipCompress(const QByteArray & data,int level)
{
  QByteArray Body ;
  return     Body ;
}

//////////////////////////////////////////////////////////////////////////////

QByteArray GZipUncompress(const QByteArray & data)
{
  QByteArray Body ;
  return     Body ;
}

//////////////////////////////////////////////////////////////////////////////

bool ToGZip(const QByteArray & data,QByteArray & gzip,int level,int workFactor)
{
  if ( data . size ( ) <= 0 ) return false ;
  //////////////////////////////////////////
  QtGZip       L                           ;
  int          r                           ;
  QVariantList v                           ;
  v << level                               ;
  v << workFactor                          ;
  r = L . BeginCompress ( v )              ;
  if ( L . IsCorrect ( r ) )               {
    L . doCompress   ( data , gzip )       ;
    L . CompressDone (        gzip )       ;
  }                                        ;
  //////////////////////////////////////////
  return ( gzip . size ( ) > 0 )           ;
}

//////////////////////////////////////////////////////////////////////////////

bool FromGZip(const QByteArray & gzip,QByteArray & data)
{
  if ( gzip . size ( ) <= 0 ) return false ;
  //////////////////////////////////////////
  QtGZip L                                 ;
  int    r                                 ;
  r = L . BeginDecompress ( )              ;
  if ( L . IsCorrect ( r ) )               {
    L . doDecompress   ( gzip , data )     ;
    L . DecompressDone (             )     ;
  }                                        ;
  //////////////////////////////////////////
  return ( data . size ( ) > 0 )           ;
}

//////////////////////////////////////////////////////////////////////////////

bool SaveGZip (QString filename,QByteArray & data,int level,int workFactor)
{
  if ( data . size ( ) <= 0 ) return false                          ;
  QByteArray gzip                                                   ;
  if ( level < 0 ) level = 9                                        ;
  if ( ! ToGZip ( data , gzip , level , workFactor ) ) return false ;
  if ( gzip . size ( ) <= 0                          ) return false ;
  QFile F ( filename )                                              ;
  if ( ! F . open ( QIODevice::WriteOnly | QIODevice::Truncate ) )  {
    return false                                                    ;
  }                                                                 ;
  F . write ( gzip )                                                ;
  F . close (      )                                                ;
  return true                                                       ;
}

//////////////////////////////////////////////////////////////////////////////

bool LoadGZip (QString filename,QByteArray & data)
{
  QFile F ( filename )                                   ;
  if ( ! F . open ( QIODevice::ReadOnly ) ) return false ;
  QByteArray gzip                                        ;
  gzip = F . readAll ( )                                 ;
  F . close         ( )                                  ;
  if ( gzip . size ( ) <= 0 ) return false               ;
  if ( ! FromGZip ( gzip , data ) ) return false         ;
  return ( data . size ( ) > 0 )                         ;
}

//////////////////////////////////////////////////////////////////////////////

bool FileToGZip(QString filename,QString gzip,int level,int workFactor)
{
  QFile F ( filename )                                   ;
  if ( ! F . open ( QIODevice::ReadOnly ) ) return false ;
  QByteArray data                                        ;
  data = F . readAll ( )                                 ;
  F . close ( )                                          ;
  if ( data . size ( ) <= 0 ) return false               ;
  return SaveGZip ( gzip , data , level , workFactor )   ;
}

//////////////////////////////////////////////////////////////////////////////

bool GZipToFile(QString gzip,QString filename)
{
  QByteArray data                                        ;
  if ( ! LoadGZip ( gzip , data ) ) return false         ;
  if ( data . size ( ) <=0        ) return false         ;
  QFile F ( filename )                                   ;
  if ( ! F . open ( QIODevice::WriteOnly                 |
                    QIODevice::Truncate ) ) return false ;
  F . write ( data )                                     ;
  F . close (      )                                     ;
  return true                                            ;
}

///////////////////////////////////////////////////////////////////////////////

QT_END_NAMESPACE
