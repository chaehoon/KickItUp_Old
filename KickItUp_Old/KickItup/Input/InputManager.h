#ifndef _KICKITUP_INPUTMANAGER_H
#define _KICKITUP_INPUTMANAGER_H

#include <map>
#include "InputHandlerManager.h"

class iInputDevice;

class InputManager
{
public:
	struct sRegisteredKey
	{
		int				keyKind;
		int				inputState;
		bool			separate;

		bool	isSameKeyKind( int kk )	{	return kk == keyKind;	}
	};

	typedef std::map<eInputName, sRegisteredKey>	RegisterKeyList;
	typedef RegisterKeyList::iterator		KeyIter;

private:
	iInputDevice *	m_pKeyBoard;
	RegisterKeyList	m_registeredKeyList;
	InputHandlerManager	m_inputHandlermanager;

public:
	InputManager(void);
	~InputManager(void);

	bool Initialize();
	void Update( long delta );

	void RegisterObserver( const char * name, iInputHandler * pInputHandler );	///< Ű�Է°��� �ʿ��� �������� ���
	void DeleteObserver( const char * name );									///< Ű�Է°��� �ʿ��� �������� �������

private:
	bool _createDevice();
	void _registerKey();
	void _registerKey( eInputName name, int kind );
	void _sendKeyMessage( eInputName name, sRegisteredKey & key );
};

extern	InputManager	g_Input;
#endif // _KICKITUP_INPUTMANAGER_H
