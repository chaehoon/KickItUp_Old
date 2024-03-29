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

// 사운드를 요청함.
Sound * SoundStore::Order(const std::string & name )
{
	// 생성된 값이 있는지 조사.
	Sound * pSnd  = Find( name );

	// 생성된 값이 없으면 생성.
	if( pSnd == 0 ) {
		pSnd = create();
		if( pSnd )
			m_SoundList.insert( SoundList::value_type( name, pSnd ) );
	}
	return pSnd;
}

// Sound 자원을 해제함.
void	SoundStore::Destroy()
{
	// Sound 자원을 해제함.
	// std::for_each( m_SoundList.begin(), m_SoundList.end(), std::mem_fun( &Sound::Free ) );
	for( SoundList::iterator i = m_SoundList.begin() ; i != m_SoundList.end() ; ++i ) {
		i->second->Free();
		delete i->second;
	}

	m_SoundList.clear();
}

// 해당 사운드를 찾는다.
Sound *	SoundStore::Find( const std::string & name )
{
	SoundIter	i = m_SoundList.find( name );
	if( i != m_SoundList.end() )
		return i->second;

	return 0;
}