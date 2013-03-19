#ifndef _KICKITUP_SURFACESTORE_H
#define _KICKITUP_SURFACESTORE_H

#include "../common.h"
#include <map>
#include <string>
class Surface;

/// @brief	Surface factory(factory pattern)
class SurfaceStore
{
private:
	typedef std::map<const std::string, Surface *>	SurfaceList;	///< Surface list type.
	typedef SurfaceList::iterator					SurfaceIter;	///< Surface iterator type.
	SurfaceList			m_surfaceList;		///< Surface List.

	static int			m_alpha;

	int					m_nameIndex;		// Order ȣ��� �̸��� ���� ���� ���鶧 ���.

public:
	virtual ~SurfaceStore(void);

	virtual bool		Initialize() = 0;		///< Initialize.
	virtual void		Destroy();				///< Destroy.

	Surface *			Order( const std::string & name );	///< Order New Surface.
	Surface *			Order();							///< Order NoName Surface.
	Surface *			Find( const std::string & name );	///< Find the Surface.
	virtual bool		Process( unsigned long delta);		///< Update.

	int					GetFlashAlphaValue() const	{	return m_alpha;	}

private:
	void				_updateAlpha( unsigned long delta );

protected:
	virtual	Surface *	create() = 0;						/// create Surface.

	SurfaceStore(void);
};

extern SurfaceStore *   g_pSurfaceStore;
#endif // _KICKITUP_SURFACESTORE_H
