#ifndef _KICKITUP_STAGE_H
#define _KICKITUP_STAGE_H

#include "State.h"

class Stage	:	public State
{
private:
    bool    m_bQuitStage;

protected:
    Stage() : m_bQuitStage( false ) {}

    void    SetQuitStage( const bool bQuit )    {   m_bQuitStage = bQuit;   }
    bool    GetQuitStage() const                {   return m_bQuitStage;    }

public:
	virtual ~Stage()	{}

	virtual bool 		Initialize()		{return true;}
	virtual void 		Destroy()	{}
	virtual bool 		Process( unsigned long delta );
	
	virtual bool		Think( unsigned long delta )		{	return true;	}	// 화면에 출력하기전 어떤 내용을 계산하는 함수.
	virtual bool		Render( unsigned long delta )	{	return true;	}	// 화면에 출력.

	virtual void		GetIn() = 0;	// get in the stage.
	virtual void		GetOut() = 0;	// get out the stage.
};

// 처리함수.
inline bool Stage::Process(unsigned long delta )
{
    if( GetQuitStage() ) {
        GoNextStage();
        return true;
    }

	// 선 작업 후
	if( Think( delta ) == false )
		return false;

	// 화면에 출력
	if( Render( delta ) == false )
		return false;
	
	return true;
}
#endif // _KICKITUP_STAGE_H
