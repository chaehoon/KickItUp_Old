#ifndef _KICKITUP_COMMON_H
#define _KICKITUP_COMMON_H

#include <SDL/SDL.h>
#include <cassert>
#include "Video/Coord.h"
#include "Video/Dim.h"

enum	ePlayMode {
    ePM_None = 0,
    ePM_Min,
    ePM_Easy = ePM_Min,
    ePM_Hard,
    ePM_Crazy,
    ePM_Double,

    ePM_Max
};

// ��ư�� �迭�� �����Ű�� ���� enum
enum    eButtonToArray
{
    eBA_Min = 0,
    eBA_1 = eBA_Min,
    eBA_3,
    eBA_5,
    eBA_7,
    eBA_9,
    eBA_Max,
};

// ��ư�� Ű�� �����Ű�� ���� ����
static const int ARRAY_TO_BUTON[5] = {1, 7, 5, 9, 3 };

#endif // _KICKITUP_COMMON_H
