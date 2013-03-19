#ifndef _KICKITUP_STAGENORMAL_H
#define _KICKITUP_STAGENORMAL_H

#include "../common.h"
#include "Stage.h"
#include "../Input/iInputHandler.h"
#include "../Video/Animation.h"
#include <deque>
#include <vector>

using std::deque;
using std::vector;

class Surface;
class Sound;
class SoundStore;
class SurfaceStore;
class InputStore;
class Input;
class Context;
class Song;

class StageNormal   :   public Stage , public iInputHandler
{
private:
    enum ePointZone {
        ePointZone_Min = 0,
        ePointZone_Perfect = ePointZone_Min,
        ePointZone_Great,
        ePointZone_Good,
        ePointZone_Bad,
        ePointZone_Miss,
        ePointZone_None,
        ePointZone_Max,
    };

    static const int    BACK_ARROW_Y    = 55;
    static const int    STEP_ARROW_SIZE = 60;
    Context &   m_context;

    Sound *     m_pBGM;         // background music.
    Surface *   m_pBG;          // background image.
    Surface *   m_pBackArrows[2];      //
    Surface *   m_pGaugeWaku;
    Surface *   m_pGauge;
    Surface *   m_pStepArrows;      // arrows.
    SDL_Rect    m_rtArrows[5][6];   // ȭ��ǥ ����.
    Song *      m_pSelectedSong;
    Animation   m_aniPushArrows[5];     // ȭ��ǥ ��ư�� ������ ��ư�� �ִϸ��̼�.
    Animation   m_AniStepArraws[5];     // Step ȭ��ǥ.
    Animation   m_aniCrashArrows[5];          // Crash ȿ�� �ִϸ��̼�.

    int         m_start[3];
    int         m_tick;
    double      m_bpm;
    double      m_stepGapTime;                  ///< 1step �ð�(ms).

    int         m_y;                            ///< ȭ��ǥ�� ����� y ����.
    int         m_playingTime;                  ///< ���� ������� ���� �ð�.
    int         m_nStepIdx;                     ///< ���� ���� index
    double      m_dStepIdx;                     ///< ���� ���� index - ������.

    double      m_stepSpeed;                    ///< ���
    double      m_distancePerStep;              ///< 1 Step�� Stepȭ��ǥ�� �����̴� �Ÿ�(Pixel)
    int         m_addedStep;                    ///< ȭ�� ������ Step Arrow�� �߰��Ǵ� step����

    vector<bool>    m_buttonState;              ///< ��ư�� ������ ����.
    int         m_judgedIdx;                    ///< ������ �Ϸ�� index
    vector<bool>    m_showStep;                 ///< ������ ȭ�鿡 �Ѹ������� �ƴ���.
    int         m_pointTimeZone[ePointZone_Max];    ///< ���� �����ð�
    int         m_judgePoint[ePointZone_Max];   ///< ������ ���� ����.

public:
    StageNormal( Context & context );
    virtual ~StageNormal(void);

    virtual bool 		Initialize();
    virtual void 		Destroy();

    virtual bool		Think( unsigned long delta );
    virtual bool		Render( unsigned long delta );

    virtual void		GetIn();	// get in the stage.
    virtual void		GetOut();	// get out the stage.

    virtual bool		InputHandleMessage( const eInputName name, const eInputState is );

    virtual void		GoPreStage();	///< goto prev stage.
    virtual void		GoNextStage();	///< goto next stage.

private:
    void    _drawBackGround( unsigned int playTime ) const;
	double	_getIndexByTime( unsigned int time ) const;
    int     _getTimeByIndex( int stepIndex ) const;
    void    _drawBackArrow( unsigned int playTime ) const;
    void    _drawGauge() const;
    void    _judge();                           // ����.
    bool    _isPress( const char * btnStr ) const;    // �ش� ��ư�� ���� ������ �˻�.
    ePointZone _getPoint( const double baseStepIndex, const int toJudgeStepIndex ) const;   // ��������
};

#endif // _KICKITUP_STAGENORMAL_H
