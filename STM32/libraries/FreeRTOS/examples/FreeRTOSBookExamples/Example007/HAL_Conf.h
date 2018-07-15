/*   ARDUINO HAL special config file, overriden default define
     config arduino/hal/os/priority/......
      ARDUINO HAL 项目配置文件， 改写 系统、库、缺省定义，配置改变系统的缺省参数/中断优先级等
     !!! Don't rename this file, 请不要改变文件名和扩展名!!!

     ---------------------------------------------------------------------------------------
      for FreeRTOS search FreeRTOSConfig.h:
        1 this sketch project path if has
        2 {variant}/config/   if has
        3 FreeRTOS/default
        This file defined can overload above.

      2017.12 by huaweiwx@sina.com
*/

#ifndef __HALSPECELCONFIG_H__
#define __HALSPECELCONFIG_H__

#define FREERTOS    1

//---------------------------------------- for FreeRTOS overload ---------------------------------------------------------

#ifdef  configUSE_COUNTING_SEMAPHORES
# undef  configUSE_COUNTING_SEMAPHORES
# define configUSE_COUNTING_SEMAPHORES      1
#endif

#ifdef  configUSE_IDLE_HOOK
# undef  configUSE_IDLE_HOOK  /*undef it move warning*/
# define configUSE_IDLE_HOOK   1
#endif

#if 0

#ifdef  INCLUDE_vTaskDelayUntil
#undef  INCLUDE_vTaskDelayUntil
#define INCLUDE_vTaskDelayUntil      	1
#endif

#ifdef   configUSE_TICK_HOOK
# undef  configUSE_TICK_HOOK
# define configUSE_TICK_HOOK            1
#endif

#endif

#endif
