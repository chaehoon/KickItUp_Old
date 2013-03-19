#include "FmodSound.h"

FmodSound::FmodSound( FMOD::System * pSystem)  : m_pSystem( pSystem ),
	m_pSound( 0 ),
	m_pChannel( 0 )
{
}

FmodSound::~FmodSound(void)
{
	Free();
}

bool    FmodSound::Load( const std::string & musicFileName )
{
	if( IsLoaded() )
		Free();

	FMOD_RESULT ret;
	ret = m_pSystem->createStream( musicFileName.c_str(), FMOD_HARDWARE | FMOD_2D | FMOD_LOOP_NORMAL, 0, &m_pSound);

	assert( ret == FMOD_OK );

	return ret == FMOD_OK;
}

void    FmodSound::Free()
{
	if( IsLoaded() ) {
		m_pSound->release();
		m_pSound = 0;
		m_pChannel = 0;
	}
}

bool    FmodSound::Play( const bool loop /* = false */ )
{
	if( IsLoaded() ) {
		FMOD_RESULT ret;
		m_pSound->setMode( loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF );
		ret = m_pSystem->playSound(FMOD_CHANNEL_FREE, m_pSound, false, &m_pChannel);
		return ret == FMOD_OK;
	}
	return false;	
}

void    FmodSound::Resume()    {
	if( IsPaused() ) {
		m_pChannel->setPaused( false );
	}
}

void    FmodSound::Pause()     {
	m_pChannel->setPaused( true );
}

void FmodSound::Stop()
{
	if( m_pChannel )
		m_pChannel->stop();
}

unsigned int  FmodSound::GetPosition()
{
	unsigned int ms;
	FMOD_RESULT	ret;
	ret = m_pChannel->getPosition( &ms, FMOD_TIMEUNIT_MS );
	if( ret != FMOD_OK )
		return -1;

	return ms;
}
