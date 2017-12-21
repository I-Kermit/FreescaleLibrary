echo /* Concatenated header file */ >  freescale_driver.h
echo #ifndef _FREESCALE_DRIVER_H_ >> freescale_driver.h
echo #define _FREESCALE_DRIVER_H_ >> freescale_driver.h
cmd /c type ..\src\Interface\IF_Gpio.h ..\src\HAL\HAL_Gpio.h ..\src\Drivers\DVR_Led.h ..\src\Interrupts\SysTick\INT_SysTick.h >> freescale_driver.h
echo #endif /* _FREESCALE_DRIVER_H_ */ >> freescale_driver.h
