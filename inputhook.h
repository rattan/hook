#ifndef INPUTHOOK_H
#define INPUTHOOK_H

#include<QObject>
#include<QAbstractNativeEventFilter>


#include<windows.h>
#include<inputevent.h>

class InputHook :public QObject, public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    InputHook(){}
    ~InputHook(){}

    bool nativeEventFilter(const QByteArray &eventType, void *message,long *result);


signals:
    void Mouse_Event(const HE_Mouse &m);
    void Keyboard_Event(const HE_Keyboard &k);


};

#endif // INPUTHOOK_H
