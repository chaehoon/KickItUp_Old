#ifndef _KICKITUP_TASK_H
#define _KICKITUP_TASK_H

class Task
{
public:
	virtual ~Task(void)	{}

	virtual bool Process( unsigned long delta ) = 0;
	
	virtual bool Initialize() = 0;
	virtual void Destroy() = 0;

protected:
	Task(void)	{}
};

#endif // _KICKITUP_TASK_H