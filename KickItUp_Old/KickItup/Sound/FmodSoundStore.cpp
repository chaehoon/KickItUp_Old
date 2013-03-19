#include "FmodSoundStore.h"
#include "FmodSound.h"
#include <cassert>
#include <fmodex/fmod_errors.h>

FmodSoundStore::FmodSoundStore(void)	:	m_system( 0 )
{
}

FmodSoundStore::~FmodSoundStore(void)
{
}

/// @brief	fmod initialize.
bool	FmodSoundStore::Initialize()
{
	// Create a System object and initialize.
	if( _isErr( FMOD::System_Create(&m_system) ) )
		return false;

	unsigned int      version;
	if( _isErr( m_system->getVersion(&version) ) )
		return false;

	if (version < FMOD_VERSION)	{
		// ("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
		return false;
	}

	if( _isErr( m_system->init(10, FMOD_INIT_NORMAL, 0) ) ) 
		return false;

	return true;
}

void	FmodSoundStore::Destroy()
{
	SoundStore::Destroy();

	if( m_system == 0 )
		return;

	if( _isErr( m_system->close() ) )
		return;

	if( _isErr( m_system->release() ) )
		return;
	
	m_system = 0;
}

bool	FmodSoundStore::Process( unsigned long )
{
	m_system->update();
	return true;
}

/// @brief	create fmod sound object
Sound *	FmodSoundStore::create()
{
	Sound * pSnd = new FmodSound( m_system );
	return pSnd;
}

/// @brief	fmod error check.
bool FmodSoundStore::_isErr(const FMOD_RESULT result)
{
	if (result != FMOD_OK) {
		char	buff[1024];
		sprintf( buff, "%s", FMOD_ErrorString(result) );
		assert( 0 );
		return true;
	}
	return false;
}
