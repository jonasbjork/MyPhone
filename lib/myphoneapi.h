/*
* MyPhoneAPI
* Jonas Björk, jonas@jonasbjork.net, 2009-08-10
* Licensed under EUPL
*/

#ifndef MY_PHONE_API
#define MY_PHONE_API

#include <QString>
#include <QDebug>

class MyPhoneAPI {

  public:
    QString getMe();
    
};

extern "C" {
  MyPhoneAPI* GetClass();
}


#endif