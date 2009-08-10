/*
* MyPhoneAPI
* Jonas Björk, jonas@jonasbjork.net, 2009-08-10
* Licensed under EUPL
*/

#include "myphoneapi.h"
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QStringList>


MyPhoneAPI::MyPhoneAPI() {
  isConnected = false;
}

QString MyPhoneAPI::getMe() {
  return "Got me!";
}

MyPhoneAPI* GetClass() {
  MyPhoneAPI* mp = new MyPhoneAPI();
  return mp;
}

void MyPhoneAPI::openConnection() {

  const char *device = "/dev/ttyACM0";
  fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
  if(fd==-1) {
    isConnected = false;
    qDebug() << "Could not open phone";
  } else {
    isConnected = true;
    struct termios options;
    fcntl(fd, F_SETFL, 0);
    tcgetattr(fd, &options);
    options.c_cflag |= (CLOCAL | CREAD );
    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    options.c_cflag |= CS8;
    options.c_cflag |= CRTSCTS;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_iflag |= (INPCK | ISTRIP);
    options.c_oflag &= ~OPOST;
    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 10;
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);
    tcsetattr(fd, TCSANOW, &options);
    //qDebug() << "Opened phone communication";
  }
}

void MyPhoneAPI::closeConnection() {
  close(fd);
  isConnected = false;
  //qDebug() << "Closed phone communication";

}

QString MyPhoneAPI::talkToPhone(QString command) {

  if(isConnected) {
    //QString command = "ATI3";
    command += '\r';
    int commandLength = command.size();
    int n;
    char buffer[255];
    char *bufptr;
    int nbytes = 0;
    QByteArray ba = QString(command).toAscii();
    const char *c = ba.constData();
    
    n = write(fd, c, commandLength);
    if(n < 0){
      qDebug() << "Writing to cell failed!";
    }
    bufptr = buffer;
    while((nbytes = read(fd, bufptr, buffer+sizeof(buffer)-bufptr-1)) >0) {
      bufptr += nbytes;
      if(bufptr[-1] == '\n' || bufptr[-1] == '\r')
	break;
    }
    *bufptr = '\0';
    QString b = QString::fromAscii(buffer);
    QStringList list = b.split('\r', QString::SkipEmptyParts);
    QString l = list[1];
    l.trimmed();
    return l;
  } else {
    return "No phone connected";
  }
}
