#include "myphoneapi.h"

#include <QApplication>
#include <QLibrary>
int main(int argc, char** argv) {
  QApplication app(argc, argv);
  typedef MyPhoneAPI* (*pf)();
  pf function=(pf)QLibrary::resolve(("./lib/libmyphoneapi.so"),"GetClass");
  MyPhoneAPI* mp=function();
  
  qDebug() << mp->getMe();
  return 0;
}