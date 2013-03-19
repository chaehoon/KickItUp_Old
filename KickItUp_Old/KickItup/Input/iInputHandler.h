#ifndef _KICKITUP_IINPUTHANDLER_H
#define _KICKITUP_IINPUTHANDLER_H

#include "InputEnum.h"

class iInputHandler
{
public:
	virtual ~iInputHandler(void) {}

	virtual bool	InputHandleMessage( const eInputName name, const eInputState is ) = 0;
};

#endif // _KICKITUP_IINPUTHANDLER_H
