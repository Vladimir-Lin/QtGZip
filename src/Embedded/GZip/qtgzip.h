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
 * QQ       : lin.vladimir@gmail.com (2107437784)
 * URL      : http://qtgzip.sourceforge.net/
 *
 * QtGZip acts as an interface between Qt and GNU GZip library.
 * Please keep QtGZip as simple as possible.
 *
 * Copyright 2001 ~ 2016
 *
 ****************************************************************************/

#ifndef QT_GZIP_H
#define QT_GZIP_H

#include <QtCore>
#include <QtScript>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#    if defined(QT_BUILD_QTGZIP_LIB)
#      define Q_GZIP_EXPORT  Q_DECL_EXPORT
#    else
#      define Q_GZIP_EXPORT  Q_DECL_IMPORT
#    endif
#else
#      define Q_GZIP_EXPORT
#endif

#define QT_GZIP_LIB 1

class Q_GZIP_EXPORT QtGZip         ;
class Q_GZIP_EXPORT ScriptableGZip ;

class Q_GZIP_EXPORT QtGZip
{
  public:

    explicit        QtGZip         (void) ;
    virtual        ~QtGZip         (void) ;

    static  QString Version         (void) ;

    virtual bool    isGZip          (QByteArray & header) ;

    virtual void    CleanUp         (void) ;

    virtual bool    IsCorrect       (int returnCode) ;
    virtual bool    IsEnd           (int returnCode) ;
    virtual bool    IsFault         (int returnCode) ;

    // Compression functions

    virtual int     BeginCompress   (int level = 9,int workFactor = 30) ;
    virtual int     BeginCompress   (QVariantList arguments = QVariantList() ) ;
    virtual int     doCompress      (const QByteArray & Source      ,
                                           QByteArray & Compressed) ;
    virtual int     doSection       (      QByteArray & Source      ,
                                           QByteArray & Compressed) ;
    virtual int     CompressDone    (QByteArray & Compressed) ;

    // Decompression functions

    virtual int     BeginDecompress (void) ;
    virtual int     doDecompress    (const QByteArray & Source        ,
                                           QByteArray & Decompressed) ;
    virtual int     undoSection     (      QByteArray & Source        ,
                                           QByteArray & Decompressed) ;
    virtual int     DecompressDone  (void) ;

    virtual bool    IsTail          (QByteArray & header) ;

  protected:

    QMap < QString , QVariant > DebugInfo ;
    void                      * gzPacket  ;

    virtual bool    CompressHeader  (QByteArray & Compressed) ;
    virtual bool    CompressTail    (QByteArray & Compressed) ;

  private:

} ;

class Q_GZIP_EXPORT ScriptableGZip : public QObject
                                   , public QScriptable
                                   , public QtGZip
{
  Q_OBJECT
  public:

    static QScriptValue Attachment     (QScriptContext * context,QScriptEngine * engine) ;

    explicit            ScriptableGZip (QObject * parent) ;
    virtual            ~ScriptableGZip (void) ;

  protected:

  private:

  public slots:

    virtual bool        ToGZip         (QString file,QString gzip,int level = 9,int workFactor = 30) ;
    virtual bool        ToFile         (QString gzip,QString file) ;

  protected slots:

  private slots:

  signals:

} ;

Q_GZIP_EXPORT QByteArray GZipCompress   (const QByteArray & data              ,
                                         int                level = 9       ) ;
Q_GZIP_EXPORT QByteArray GZipUncompress (const QByteArray & data            ) ;
Q_GZIP_EXPORT bool       ToGZip         (const QByteArray & data              ,
                                               QByteArray & gzip              ,
                                         int                level      = 9    ,
                                         int                workFactor = 30 ) ;
Q_GZIP_EXPORT bool       FromGZip       (const QByteArray & gzip              ,
                                               QByteArray & data            ) ;
Q_GZIP_EXPORT bool       SaveGZip       (QString            filename          ,
                                         QByteArray       & data              ,
                                         int                level      = 9    ,
                                         int                workFactor = 30 ) ;
Q_GZIP_EXPORT bool       LoadGZip       (QString            filename          ,
                                         QByteArray       & data            ) ;
Q_GZIP_EXPORT bool       FileToGZip     (QString            filename          ,
                                         QString            gzip              ,
                                         int                level      = 9    ,
                                         int                workFactor = 30 ) ;
Q_GZIP_EXPORT bool       GZipToFile     (QString            gzip              ,
                                         QString            filename        ) ;


QT_END_NAMESPACE

#endif
