/*
* MyPhoneAPI
* Jonas Björk, jonas@jonasbjork.net, 2009-08-10
* Licensed under EUPL
*/

#include "myphoneapi.h"


QString MyPhoneAPI::getMe() {
  return "Got me!";
}

MyPhoneAPI* GetClass() {
  MyPhoneAPI* mp = new MyPhoneAPI();
  return mp;
}