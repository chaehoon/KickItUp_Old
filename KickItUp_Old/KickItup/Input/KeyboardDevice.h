#ifndef _KICKITUP_KEYBOARDDEVICE_H
#define _KICKITUP_KEYBOARDDEVICE_H

#include "iInputDevice.h"

class KeyboardDevice	:	public iInputDevice
{
public:
	virtual ~KeyboardDevice(void)	{}

	virtual void	Reset()	{}
	virtual void	Update( unsigned long delta )	{}
	virtual int		GetState( const eKind kind, const uKey key );

};

#endif // _KICKITUP_KEYBOARDDEVICE_H