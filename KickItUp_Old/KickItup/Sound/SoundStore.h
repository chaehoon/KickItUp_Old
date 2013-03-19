#ifndef _KICKITUP_SOUNDSTORE_H
#define _KICKITUP_SOUNDSTORE_H

#include "../common.h"
#include <map>
#include <string>

class Sound;

/// @brief	Sound factory(factory pattern).
class SoundStore
{
private:
	typedef	std::map<const std::string, Sound *>	SoundList;		///< Sound List Type.
	typedef SoundList::iterator						SoundIter;		///< SoundList Iterator type.
	
	SoundList		m_SoundList;		///< Sound List.

public:
	virtual ~SoundStore(void);		///< �Ҹ���.

	virtual bool	Initialize() = 0;	///< �ʱ�ȭ.
	virtual void	Destroy();			///< ���� �۾�.

	Sound * Order( const std::string & name );					///< ���带 ��û.
	Sound *	Find( const std::string & name );					///< ���� ���带 ã��.
	
	virtual bool	Process( unsigned long )	{	return true; }	/// Sound System Update.

protected:
	SoundStore(void);				///< ������.
	virtual	Sound *	create() = 0;	/// Sound Create.
};

extern SoundStore *	g_pSoundStore;

#endif // _KICKITUP_SOUNDSTORE_H
