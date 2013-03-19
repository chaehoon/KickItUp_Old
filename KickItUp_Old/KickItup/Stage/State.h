#ifndef _KICKITUP_STATE_H
#define _KICKITUP_STATE_H

#include "../Util/Task.h"

/// @brief	State pattern
class State
{
public:
	State(void)	{}
	virtual ~State(void)	{}

	virtual void GoPreStage()		{}	///< goto prev stage.
	virtual void GoNextStage()		{}	///< goto next stage.
	virtual void SelectSingle()		{}	///< goto Single stage.
	virtual void SelectCouple()		{}	///< goto Couple stage.
	virtual void SelectDouble()		{}	///< goto double stage.
};

#endif // _KICKITUP_STATE_H
