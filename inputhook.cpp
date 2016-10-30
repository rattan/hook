#include "inputhook.h"

bool InputHook::nativeEventFilter(const QByteArray &eventType, void *message, long *result) {

    if(eventType == "windows_generic_MSG")
    {
        MSG *msg = reinterpret_cast<MSG*>(message);
        if(msg->message == WM_INPUT)
        {
            UINT dwSize = 40;
            static BYTE lpb[40];
            if(!GetRawInputData((HRAWINPUT)msg->lParam, RID_INPUT,lpb, &dwSize, sizeof(RAWINPUTHEADER))){}
//                qDebug()<<"Error GetRawInputData";
            else
            {
                RAWINPUT* raw = (RAWINPUT*)lpb;


                switch(raw->header.dwType){
                case RIM_TYPEMOUSE:
                    HE_Mouse m;
                    m.button = raw->data.mouse.usButtonFlags;
                    m.delta = raw->data.mouse.usButtonData;
                    m.posx = msg->pt.x;
                    m.posy = msg->pt.y;
                    m.movex = raw->data.mouse.lLastX;
                    m.movey = raw->data.mouse.lLastY;
                    emit Mouse_Event(m);
                    break;

                case RIM_TYPEKEYBOARD:
                    HE_Keyboard k;
                    k.key = raw->data.keyboard.VKey;
                    k.state = raw->data.keyboard.Flags;
                    emit Keyboard_Event(k);
                    break;
                }
                return true;
            }

        }
    }
    return false;
}
