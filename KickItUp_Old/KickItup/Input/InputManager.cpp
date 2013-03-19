#include "InputManager.h"
#include "KeyboardDevice.h"
#include <SDL/SDL.h>
InputManager	g_Input;

InputManager::InputManager(void)	:	m_pKeyBoard( 0 )
{
}

InputManager::~InputManager(void)
{
	if( m_pKeyBoard )
		delete m_pKeyBoard;
}


// �ʱ�ȭ �Լ�.
bool InputManager::Initialize()
{
	// ����̽� ����
	_createDevice();

	// Ű ���
	_registerKey();

	return true;
}

// ���� �ð� ���� ������Ʈ�� ȣ���.
void InputManager::Update( long delta )
{
	if( m_pKeyBoard )
		m_pKeyBoard->Update( delta );

	for( KeyIter i = m_registeredKeyList.begin() ; i != m_registeredKeyList.end() ; ++i ) {
		sRegisteredKey &	k = i->second;
		_sendKeyMessage( i->first, k );
	}
}

// Ű�Է��� �ʿ��� �������� ����Ѵ�.
void InputManager::RegisterObserver( const char * name, iInputHandler * pInputHandler )
{
	m_inputHandlermanager.RegisterObserver( name, pInputHandler );
}

// Ű�Է��� �ʿ��� �������� ��������Ѵ�.
void InputManager::DeleteObserver( const char * name )
{
	m_inputHandlermanager.DeleteObserver( name );
}


// �Է� ����̽�Ʈ ���� �Լ�.
bool InputManager::_createDevice()
{
	if( m_pKeyBoard )
		delete m_pKeyBoard;
	m_pKeyBoard = new KeyboardDevice;
	return true;
}

// Ű�� ����Ѵ�.
void InputManager::_registerKey()
{
	m_registeredKeyList.clear();
	_registerKey( eIN_GO, SDLK_RETURN );
	_registerKey( eIN_GO, SDLK_KP_ENTER );
	_registerKey( eIN_BACK, SDLK_ESCAPE );

	_registerKey( eIN_ARROW_1P_TOP_LEFT,	SDLK_q );
	_registerKey( eIN_ARROW_1P_TOP_RIGHT,	SDLK_e );
	_registerKey( eIN_ARROW_1P_MIDLE,		SDLK_s );
	_registerKey( eIN_ARROW_1P_BOTTOM_LEFT, SDLK_z );
	_registerKey( eIN_ARROW_1P_BOTTOM_RIGHT,SDLK_c );

	_registerKey( eIN_ARROW_2P_TOP_LEFT,	SDLK_KP7);
	_registerKey( eIN_ARROW_2P_TOP_RIGHT,	SDLK_KP9 );
	_registerKey( eIN_ARROW_2P_MIDLE,		SDLK_KP5 );
	_registerKey( eIN_ARROW_2P_BOTTOM_LEFT, SDLK_KP1 );
	_registerKey( eIN_ARROW_2P_BOTTOM_RIGHT,SDLK_KP3 );

}

// Ű���� ����� �����Ͽ� ���.
//	kind : keyboard�� �������� ������ Ű��.
void InputManager::_registerKey( eInputName name, int kind )
{
	sRegisteredKey	key;
	key.inputState = eIS_NONE;
	key.keyKind = kind;
	key.separate = false;

	for( KeyIter iter = m_registeredKeyList.begin() ;
		iter != m_registeredKeyList.end() ;
		++iter ) {
		if( iter->second.keyKind == kind ) {
			iter->second.separate = true;
			key.separate = true;
			break;
		}
	}

	m_registeredKeyList.insert( std::make_pair(name, key) );
}

// �ش� Ű�Է��� �ִ��� Ȯ���� Ű �ż����� ����
void InputManager::_sendKeyMessage( eInputName name, sRegisteredKey & key )
{
	int	prev = key.inputState;
	int	cur = eIS_NONE;
	int	state = 0;

	state = m_pKeyBoard->GetState( iInputDevice::KeyState, key.keyKind );

	if( state & eIS_MASK_STATE )
		cur = eIS_HOLD;

	key.inputState = cur;
	key.inputState |= ( (cur ^ prev) & eIS_MASK_STATE ) ? eIS_MASK_TRIGGER : eIS_NONE;

	if( key.inputState == eIS_PRESS || key.inputState == eIS_RELEASE )
		m_inputHandlermanager.SendMessage( name, static_cast<eInputState>(key.inputState) );
}