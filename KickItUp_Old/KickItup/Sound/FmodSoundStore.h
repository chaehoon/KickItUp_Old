#ifndef _KICKITUP_FMODSOUNDSTORE_H
#define _KICKITUP_FMODSOUNDSTORE_H

#include "../common.h"
#include <fmodex/fmod.hpp>
#include "SoundStore.h"

class FmodSoundStore	: public SoundStore
{
private:
	FMOD::System *	m_system;

public:
	FmodSoundStore(void);
	virtual ~FmodSoundStore(void);

	virtual bool	Process( unsigned long );
	virtual bool	Initialize();
	virtual void	Destroy();

protected:
	virtual Sound *	create();
	

private:
	bool _isErr(const FMOD_RESULT result);
};

#endif // _KICKITUP_FMODSOUNDSTORE_H

