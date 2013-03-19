#include "../common.h"
#include "SDLSurfaceStore.h"
#include "SDLSurface.h"

SDLSurfaceStore::SDLSurfaceStore(void)	:	m_pSurface( 0 )
{
}

SDLSurfaceStore::~SDLSurfaceStore(void)
{
}

// initilze sdl.
bool	SDLSurfaceStore::Initialize()
{
	// SDL_FULLSCREEN
	m_pSurface = SDL_SetVideoMode( 640, 480, SDL_GetVideoInfo()->vfmt->BitsPerPixel, SDL_HWSURFACE | SDL_DOUBLEBUF );

	if( m_pSurface == 0 )
		return false;

	// Set title Name
	SDL_WM_SetCaption( "KickItUp ver 0.9", NULL );

	return true;
}

// Destroy sdl.
void	SDLSurfaceStore::Destroy()
{
	SurfaceStore::Destroy();

	if( m_pSurface == 0 )
		return;

	SDL_FreeSurface( m_pSurface );
	m_pSurface = 0;
}

// create sdl surface.
Surface *	SDLSurfaceStore::create()
{
	Surface * pSurface = new SDLSurface( m_pSurface );
	return pSurface;
}

// flip the main surface.
bool	SDLSurfaceStore::Process( unsigned long delta )
{
	SurfaceStore::Process( delta );
	SDL_Flip( m_pSurface );
	return true;
}
