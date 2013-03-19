#ifndef _KICKITUP_FMODSOUND_H
#define _KICKITUP_FMODSOUND_H

#include "../Common.h"
#include "Sound.h"
#include <fmodex/fmod.hpp>

class FmodSound	:	public	Sound
{
private:
	FMOD::System *	m_pSystem;
	FMOD::Sound *	m_pSound;	
	FMOD::Channel *	m_pChannel;

public:
	FmodSound( FMOD::System * pSystem);
	virtual ~FmodSound(void);

	virtual bool    Load( const std::string & musicFileName );
	virtual void    Free();

	virtual bool    IsLoaded() const    {   return m_pSound != 0;   }
	virtual bool    IsPlaying() {
		bool	playing;
		m_pChannel->isPlaying( &playing );
		return playing;
	}

	virtual bool    IsPaused()  {
		bool paused;
		m_pChannel->getPaused(&paused);
		return paused;
	}

	virtual bool    Play( const bool loop = false );
	virtual void    Resume();
	virtual void    Pause();
	virtual void    Stop();

	virtual unsigned int  GetPosition();
};

#endif // _KICKITUP_FMODSOUND_H

