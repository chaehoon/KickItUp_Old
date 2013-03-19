#ifndef _KICKITUP_INPUTENUM_H
#define _KICKITUP_INPUTENUM_H

enum eInputName
{
	eIN_NONE    = -1,

	eIN_ARROW_1P_MIN = 0,
    eIN_ARROW_1P_BOTTOM_LEFT = eIN_ARROW_1P_MIN,    // ¢×
	eIN_ARROW_1P_TOP_LEFT,      // ¢Ø
    eIN_ARROW_1P_MIDLE,			// ¡¤
	eIN_ARROW_1P_TOP_RIGHT,		// ¢Ö
	eIN_ARROW_1P_BOTTOM_RIGHT,	// ¢Ù
	eIN_ARROW_1P_MAX,

	eIN_ARROW_2P_MIN = eIN_ARROW_1P_MAX,
    eIN_ARROW_2P_BOTTOM_LEFT= eIN_ARROW_2P_MIN, // ¢×
	eIN_ARROW_2P_TOP_LEFT,	    // ¢Ø
    eIN_ARROW_2P_MIDLE,			// ¡¤
	eIN_ARROW_2P_TOP_RIGHT,		// ¢Ö
	eIN_ARROW_2P_BOTTOM_RIGHT,	// ¢Ù
	eIN_ARROW_2P_MAX,

	eIN_BACK = 100,
	eIN_GO,
};

enum eInputState
{ 
	eIS_NONE     = 0x0, 
	eIS_HOLD     = 0x1, 
	eIS_RELEASE  = 0x2, 
	eIS_PRESS    = 0x3, 
	eIS_DBLCLK   = 0x7, 

	eIS_MASK_STATE   = 0x1, 
	eIS_MASK_TRIGGER = 0x2, 
	eIS_MASK_CLK     = 0x3, 
	eIS_MASK_DBLCLK  = 0x4,
};

#endif // _KICKITUP_INPUTENUM_H
