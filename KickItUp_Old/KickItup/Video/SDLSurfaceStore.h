#ifndef _KICKITUP_SDLSURFACESTORE_H
#define _KICKITUP_SDLSURFACESTORE_H

#include "../common.h"
#include "SurfaceStore.h"

class Surface;

/// @brief	SDLSurfaceStore class. (factory pattern)
class SDLSurfaceStore :	public SurfaceStore
{
private:
	SDL_Surface *	m_pSurface;			///< SDL surface.

public:
	SDLSurfaceStore(void);
	virtual ~SDLSurfaceStore(void);
	
	virtual bool	Initialize();		///< Initialize sdl.
	virtual void	Destroy();			///< Destroy sdl
	virtual bool	Process( unsigned long delta);	///< Update.

protected:
	virtual Surface *	create();
};

#endif // _KICKITUP_SDLSURFACESTORE_H
