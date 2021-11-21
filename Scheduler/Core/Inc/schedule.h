/*
 * schedule.h
 *
 *  Created on: Nov 21, 2021
 *      Author: Duong
 */

#ifndef INC_SCHEDULE_H_
#define INC_SCHEDULE_H_

typedef struct{
	// Pointer to the task (must be a ’void ( void ) ’ function )
	void  (*pTask) (void);
	//Delay ( ticks ) until the function will ( next ) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs .
	uint32_t Period;
	//Incremented (by scheduler) when task i s due to execute
	uint8_t RunMe;
	//This is a hint to solve the question below .
	uint32_t TaskID;
}sTask;
#define SCH_MAX_TASKS 40
#define	NO_TASK_ID 0
sTask SCH_tasks_G [SCH_MAX_TASKS];


void SCH_Init(void);
void SCH_Update(void);
void SCH_Add_Task(void(*p),int,int);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(int);
void SCH_Report_Status(void);
void SCH_Go_To_Sleep(void);
#endif /* INC_SCHEDULE_H_ */
