#include "SoundStore.h"
#include "Sound.h"
#include <algorithm>
#include <functional>

SoundStore *	g_pSoundStore = 0;

SoundStore::SoundStore(void)
{
}

SoundStore::~SoundStore(void)
{
	Destroy();
}

// ���带 ��û��.
Sound * SoundStore::Order(const std::string & name )
{
	// ������ ���� �ִ��� ����.
	Sound * pSnd  = Find( name );

	// ������ ���� ������ ����.
	if( pSnd == 0 ) {
		pSnd = create();
		if( pSnd )
			m_SoundList.insert( SoundList::value_type( name, pSnd ) );
	}
	return pSnd;
}

// Sound �ڿ��� ������.
void	SoundStore::Destroy()
{
	// Sound �ڿ��� ������.
	// std::for_each( m_SoundList.begin(), m_SoundList.end(), std::mem_fun( &Sound::Free ) );
	for( SoundList::iterator i = m_SoundList.begin() ; i != m_SoundList.end() ; ++i ) {
		i->second->Free();
		delete i->second;
	}

	m_SoundList.clear();
}

// �ش� ���带 ã�´�.
Sound *	SoundStore::Find( const std::string & name )
{
	SoundIter	i = m_SoundList.find( name );
	if( i != m_SoundList.end() )
		return i->second;

	return 0;
}