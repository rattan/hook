#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    a.installNativeEventFilter(w.getHk());
    w.show();

//    UINT nDevices;
//    PRAWINPUTDEVICELIST pRawInputDeviceList;

//    if(!GetRawInputDeviceList(nullptr,&nDevices,sizeof(PRAWINPUTDEVICELIST))){
//        qDebug()<<"Error -- GetRawInputDeviceList ...";
//        return 1;
//    }

//    if(!(pRawInputDeviceList = (PRAWINPUTDEVICELIST)malloc(sizeof(RAWINPUTDEVICELIST) * nDevices))){
//        qDebug()<<"Initialization failed...";
//        return 1;
//    }

    RAWINPUTDEVICE Rid[2];
    // Set Keyboard RAWINPUTDEVICE struct
    Rid[0].usUsagePage = 0x01;
    Rid[0].usUsage = 0x06;
    Rid[0].dwFlags = RIDEV_INPUTSINK;
    Rid[0].hwndTarget = (HWND)w.effectiveWinId();

    // Set Mouse RAWINPUTDEVICE struct
    Rid[1].usUsagePage = 0x01;
    Rid[1].usUsage = 0x02;
    Rid[1].dwFlags = RIDEV_INPUTSINK;
    Rid[1].hwndTarget = (HWND)w.effectiveWinId();



    if(!RegisterRawInputDevices(Rid,2,sizeof(RAWINPUTDEVICE))){
        qDebug()<<"Huston Problem.:";
    }
    qDebug()<<QString::number(GetLastError());

    return a.exec();
}
