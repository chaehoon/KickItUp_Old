#include "InputHandlerManager.h"
#include "iInputHandler.h"

using std::string;

InputHandlerManager::InputHandlerManager(void)
{
}

InputHandlerManager::~InputHandlerManager(void)
{
}


// �������� Ű �Է°��� �����Ѵ�.
bool InputHandlerManager::SendMessage( const eInputName name, const eInputState state )
{
	for( InputHandlerListIter h = m_inputHandlerList.begin() ; h != m_inputHandlerList.end() ; ++h ) {
		iInputHandler * pInputhandler = h->second;
		if( pInputhandler->InputHandleMessage( name, state ) )
			return true;
	}

	return false;
}

// ������ ���.
void InputHandlerManager::RegisterObserver( const char * name, iInputHandler * pInputHandler )
{
	m_inputHandlerList.insert( std::make_pair(string(name), pInputHandler) );
}

// ������ ����.
void InputHandlerManager::DeleteObserver( const char * name )
{
	InputHandlerListIter i = m_inputHandlerList.find( string(name) );
	if( i != m_inputHandlerList.end() )
		m_inputHandlerList.erase( i );
}