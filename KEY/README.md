利用STM32F103C8T6实现按键消抖点亮LED   Robomini初筛的中级任务文件

实现功能：阻塞式实现按键消抖，实现两个案件对两个LED一对一的控制

硬件介绍： 使用STM32F103C8T6、STlink、LED、按键

软件介绍： 1.该工程使用CubeMX生成初始化代码。   
2.判断按键是否按下的函数（KEY_Scan），使用HAL库的Delay函数，每20ms判断一次电平是否稳定   
3.while循环里重复调用KEY_Scan，判断按键是否按下并翻转LED状态。   

电路介绍： 1.按键在B0、B10，另一端接地。   
2.LED：高电平点亮。


YZDX