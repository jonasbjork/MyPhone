#include "myphoneapi.h"
#include "lib/nokia_commands.h"

#include <QApplication>
#include <QLibrary>
int main(int argc, char** argv) {
  QApplication app(argc, argv);
  typedef MyPhoneAPI* (*pf)();
  //TODO: Fix path for library
  pf function=(pf)QLibrary::resolve(("./lib/libmyphoneapi.so"),"GetClass");
  MyPhoneAPI* mp=function();
  
  //qDebug() << mp->getMe();
  mp->openConnection();
  QString man = mp->talkToPhone(NOKIA_BRAND);
  man.remove(0,1);
  qDebug() << "Manufacturer: " << man;
  QString ser = mp->talkToPhone(NOKIA_SERIAL);
  ser.remove(0,1);
  qDebug() << "Serial no: " << ser;
  QString mod = mp->talkToPhone(NOKIA_MODEL);
  mod.remove(0,1);
  qDebug() << "Model: " << mod;
  mp->closeConnection();
  return 0;
}