  /*
 * sheduler.c
 *
 *  Created on: Nov 21, 2021
 *      Author: Win10
 */
#include "scheduler.h"

void SCH_Update(void){
	int i;
	for (i =0; i<SCH_MAX_TASKS; i++){
		if (SCH_Tasks[i].pTask){
			if(SCH_Tasks[i].Delay==0){
				SCH_Tasks[i].Runtime+=1;
				if (SCH_Tasks[i].Period){
					SCH_Tasks[i].Delay=SCH_Tasks[i].Period;
				}
			} else {
				SCH_Tasks[i].Delay -=1;
			}
		}
	}
}
void SCH_Add_Task(void (*pFunction)(), int Delay, int Period){
	int i =0;
	while ((SCH_Tasks[i].pTask != 0x0000)&&(i <SCH_MAX_TASKS)){
		i++;
	}
	if (i==SCH_MAX_TASKS) return;
	SCH_Tasks[i].pTask = pFunction;
	SCH_Tasks[i].Delay = Delay;
	SCH_Tasks[i].Period = Period;
	SCH_Tasks[i].Runtime = 0;
}
void SCH_Dispatcher(void){
	unsigned char i;
	for (i =0; i< SCH_MAX_TASKS; i++){
		if (SCH_Tasks[i].Runtime>0){
			(*SCH_Tasks[i].pTask)();
			SCH_Tasks[i].Runtime-=1;
			if(SCH_Tasks[i].Period==0){
				SCH_Delete(i);
			}
		}
	}
}
void SCH_Delete(int index){
	SCH_Tasks[index].pTask= 0x0000;
	SCH_Tasks[index].Delay= 0;
	SCH_Tasks[index].Period= 0;
	SCH_Tasks[index].Runtime= 0;
}
