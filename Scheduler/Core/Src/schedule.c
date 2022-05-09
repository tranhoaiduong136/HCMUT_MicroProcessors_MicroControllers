/*
 * schedule.c
 *
 *  Created on: Nov 21, 2021
 *      Author: Duong
 */
#include"main.h"
#include"schedule.h"
#include"task.h"
uint8_t Error_code_G = 0;

void SCH_Init(void){
	for(int i =0;i < SCH_MAX_TASKS;i++){
		SCH_Delete_Task(i);
	}
	Error_code_G = 0;
	Timer_init();
}
void SCH_Update(void){
	for(int i =0 ;i <SCH_MAX_TASKS;i++){
		if(SCH_tasks_G[i].pTask){
			if(SCH_tasks_G[i].Delay == 0){
				SCH_tasks_G[i].RunMe += 1;
				if(SCH_tasks_G[i].Period){
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				}else{
					SCH_tasks_G[i].Delay -=1;
				}
			}
		}
	}
}
void SCH_Add_Task(void(*p),int delay,int period){

}
void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < SCH_MAX_TASKS;i++){
		if(SCH_tasks_G[i].RunMe >0){
			(*SCH_tasks_G[i].pTasks)();
			SCH_tasks_G[i].RunMe -= 1;
			if(SCH_tasks_G[i].Period == 0){
				SCH_Delete_Task(i);
			}
		}
	}
	SCH_Report_Status();
	SCH_Go_To_Sleep();
}
void SCH_Delete_Task(int index){

}
void SCH_Report_Status(void);
void SCH_Go_To_Sleep(void);
