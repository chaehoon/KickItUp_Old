#ifndef _KICKITUP_SONGMGR_H
#define _KICKITUP_SONGMGR_H

#include "Song.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class SongMgr
{
private:
	typedef vector<Song *>		SongList;
	typedef SongList::iterator	SongListIter;

	SongList	m_songList;

	int			m_leftSongIndex;	// ���� �ε���
	int			m_rightSongIndex;	// ������ �ε���
    Song *      m_pSongSelect;      // ���õ� �뷡.

public:
	SongMgr(void);
	~SongMgr(void);

	bool	Load( const string & dirName );

    Song *  GetLeftSong() const;
    Song *  GetRightSong() const;

    Song *  GetSelectSong() const           {   return m_pSongSelect;   }
    void    SetSelectSong( Song * pSong )   {   m_pSongSelect = pSong;    }

    void    TurnLeft();
    void    TurnRight();

private:
	bool	_readStepFile();		// Step File�� �о����.
	bool	_readStep( const ePlayMode playmode, Song * pSong );
	bool	_access( const string & filename );
};

extern SongMgr g_SongMgr;


inline Song *  SongMgr::GetLeftSong() const
{
    Song *  pRet = 0;
    if( m_leftSongIndex != -1 )
        pRet = m_songList[m_leftSongIndex];
    return pRet;
}

inline Song *  SongMgr::GetRightSong() const
{
    Song *  pRet = 0;
    if( m_rightSongIndex != -1 )
        pRet = m_songList[m_rightSongIndex];
    return pRet;
}

#endif // _KICKITUP_SONGMGR_H
