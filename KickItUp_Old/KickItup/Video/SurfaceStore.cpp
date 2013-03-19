#include "SurfaceStore.h"
#include "Surface.h"
#include <sstream>

using std::ostringstream;

SurfaceStore *   g_pSurfaceStore = 0;

int	SurfaceStore::m_alpha = 0;

SurfaceStore::SurfaceStore(void)	:	m_nameIndex( 0 )
{
}

SurfaceStore::~SurfaceStore(void)
{
	Destroy();
}

// Order NoName Surface.
Surface * SurfaceStore::Order()
{
	ostringstream	o;
	o << m_nameIndex;
	++m_nameIndex;

	return Order( o.str() );
}
// Order New Surface.
Surface * SurfaceStore::Order( const std::string & name )
{
	// Find old Surface.
	Surface * pSurface  = Find( name );

	if( pSurface == 0 ) {
		// crate new Surface.
		pSurface = create();
		
		assert( pSurface != 0 );

		if( pSurface )
			m_surfaceList.insert( SurfaceList::value_type( name, pSurface ) );
	}
	return pSurface;
}

// Destroy.
void	SurfaceStore::Destroy()
{
	// std::for_each( m_surfaceList.begin(), m_surfaceList.end(), std::mem_fun( &Surface::Free ) );
	for( SurfaceList::iterator i = m_surfaceList.begin() ; i != m_surfaceList.end() ; ++i ) {
		Surface * pSurface = i->second;
		pSurface->Free();
		delete pSurface;
	}

	m_surfaceList.clear();
}

// find the surface.
Surface *	SurfaceStore::Find( const std::string & name )
{
	SurfaceIter	i = m_surfaceList.find( name );
	if( i != m_surfaceList.end() )
		return i->second;

	return 0;
}

bool SurfaceStore::Process( unsigned long delta )
{
	_updateAlpha( delta );
	return true;
}


void SurfaceStore::_updateAlpha( unsigned long delta )
{
	static unsigned long	s_timer = 0;
	static int	alphaInc = 10;

	s_timer += delta;

	if( 5 < s_timer ) {
		s_timer = 0;
		m_alpha += alphaInc;
		if( m_alpha < 0 ) {
			m_alpha = 0;
			alphaInc = 5;
		}

		if( 255 < m_alpha ) {
			m_alpha = 255;
			alphaInc = -5;
		}
	}
}