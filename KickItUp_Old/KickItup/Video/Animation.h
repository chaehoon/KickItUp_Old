#ifndef _KICKITUP_ANIMATION_H
#define _KICKITUP_ANIMATION_H

#include "../common.h"

class Surface;
class Animation {
private:
    unsigned long m_ticks;
    int     m_currentFrame;
    int     m_frameInc;

    int     m_frameRate; //Milliseconds
    unsigned long m_oldTime;

    int     m_maxFrames;
    bool    m_oscillate;
    bool    m_bLoop;        // �ִϸ��̼��� ��� �Ұ����� �Ǵ�.
    bool    m_bPause;       // �Ͻ� ���� ����.
    
    Surface *   m_pSurface; // �ִϸ��̼� Surface
    SDL_Rect    m_rect;     // �׸��� �Ӽ�.

    Coord       m_coord;    // ȭ�鿡 ����� ��ġ

public: // Get Set �Լ�.
    void    setFrameRate( const int rate )    {   m_frameRate = rate; }
    int     getFrameRate() const  {   return m_frameRate; }
    
    void    setCurrentFrame( const int frame );
    int     getCurrentFrame() const { return m_currentFrame;  }
    
    void    setMaxFrames( const int maxFrame ) {  m_maxFrames = maxFrame; }
    int     getMaxFrames() const   {   return m_maxFrames; }
    
    void    setOscillate( const bool oscillate ) { m_oscillate = oscillate;   }
    bool    getOscillate() const  {   return m_oscillate; }
    
    void    setLoop( const bool bLoop )   {   m_bLoop = bLoop; }
    bool    getLoop() const       {   return m_bLoop; }

    void    setSurface( Surface * pSurface )  {   m_pSurface = pSurface;  }
    Surface *   getSurface() const  {   return m_pSurface;  }

    void    setRect( const SDL_Rect & rect )    {   m_rect = rect;  }

    void    setCoord( const Coord & coord )     {   m_coord = coord;    }
    void    setCoord( const short x, const short y ) {
        m_coord.setX( x );
        m_coord.setY( y );
    }
    Coord   getCoord() const                    {   return m_coord;     }

    void    setPause( const bool bPause = true )    {   m_bPause = bPause;  }
    bool    getPause() const                    {   return m_bPause;    }

    bool    isLoopEnd() const;

public:
    Animation();
    virtual ~Animation();

    virtual void    OnAnimate( const unsigned long delta );
    virtual void    OnRender();
};

#endif // _KICKITUP_ANIMATION_H

