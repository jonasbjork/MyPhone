/*
* MyPhoneAPI
* Jonas Björk, jonas@jonasbjork.net, 2009-08-10
* Licensed under EUPL
*/

#ifndef MY_PHONE_API
#define MY_PHONE_API

#include <termios.h>
#include <unistd.h>

#include <QString>
#include <QFile>
#include <QDebug>

class MyPhoneAPI {

  private:
    QFile conn;
    //FILE* fd;
    int fd;
    bool isConnected;
    enum Baud{
      BAUD_50		= B50,
      BAUD_75		= B75,
      BAUD_110		= B110,
      BAUD_134		= B134,
      BAUD_150		= B150,
      BAUD_200		= B200,
      BAUD_300		= B300,
      BAUD_600		= B600,
      BAUD_1200		= B1200,
      BAUD_1800		= B1800,
      BAUD_2400		= B2400,
      BAUD_4800		= B4800,
      BAUD_9600		= B9600,
      BAUD_19200	= B19200,
      BAUD_38400	= B38400,
      BAUD_57600	= B57600,
      BAUD_115200	= B115200,
      BAUD_230400	= B230400,
      BAUD_DEFAULT	= BAUD_57600
    };
    enum Parity {
      PARITY_NONE = 0x0,
      PARITY_ODD = 0x1,
      PARITY_EVEN = 0x2,
      PARITY_MARK = 0x3,
      PARITY_SPACE = 0x4,
      PARITY_DEFAULT = PARITY_NONE
    };
    enum DataBits {
      DATABITS_5=5,
      DATABITS_6=6,
      DATABITS_7=7,
      DATABITS_8=8,
      DATABITS_DEFAULT=DATABITS_8
    };
    enum StopBits {
      STOP_BITS_1=0x1,
      STOP_BITS_2=0x2,
      STOP_BITS_DEFAULT = STOP_BITS_1
    };
    enum FlowControl {
        /**
         * Enable RTS/CTS (hardware) flow control.
         */
        FLOW_CONTROL_HARD=0x1,
        /**
         * Enable XON/XOFF flow control.
         */
        FLOW_CONTROL_XONXOFF=0x2,
        /**
         * No flow control.
         */
        FLOW_CONTROL_NONE=0x0,
        /**
         * Default flow control value (hardware)
         */
        FLOW_CONTROL_DEFAULT = FLOW_CONTROL_HARD
    };
    


    
  public:
    MyPhoneAPI();
    QString getMe();
    void openConnection();
    void closeConnection();
    QString talkToPhone(QString command);
    
};

extern "C" {
  MyPhoneAPI* GetClass();
}


#endif