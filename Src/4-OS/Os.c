/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Ebrahim Hamouda
 *
 * For any inquiries: ebrahim.hamouda25@gmail.com
 *
 */
 
#include "Os.h"
#include <util/delay.h>


static EventMaskType AppTsk_CurrentEvents = 0;

void Os_ActivateTask(TaskType taskId)
{
	switch(taskId)
	{
		case OsTaskId_CyclicTask:
			CyclicTask();
			break;
			
		case OsTaskId_AppTsk:
			AppTsk();
			break;
			
		default:
			break;
	}
}

void Os_TerminateTask()
{
}

void Os_SetRelAlarm(AlarmType alarmID, TickType offset, TickType cycle)
{
	while (1)
	{
		CyclicTask();
		_delay_ms(100);
	}
}

void Os_CancelAlarm(AlarmType alarmID)
{
}

void Os_SetEvent(TaskType taskId, EventMaskType osEvent)
{
	switch(taskId)
	{
		case OsTaskId_AppTsk:
			AppTsk_CurrentEvents |= osEvent;
			Os_ActivateTask(taskId);
			break;
			
		default:
			break;
	}
}

void Os_ClearEvent(EventMaskType osEvent)
{
	AppTsk_CurrentEvents &= (~osEvent);
}

void Os_GetEvent(TaskType taskId, EventMaskType* osEvent)
{
	switch(taskId)
	{
		case OsTaskId_AppTsk:
			*osEvent = AppTsk_CurrentEvents;
			break;
			
		default:
			break;
	}
}

void Os_WaitEvent(EventMaskType osEvent)
{
}

void Os_SuspendAllInterrupts()
{
}

void Os_ResumeAllInterrupts()
{
}
