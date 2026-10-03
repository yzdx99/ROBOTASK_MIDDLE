利用STM32F103C8T6输出PWM   Robomini初筛的中级任务文件-PWM呼吸灯

硬件介绍： 使用STM32F103C8T6、STlink、LED

软件介绍： 1.该工程使用CubeMX生成初始化代码。
2.使用端口为PA0。TIM2的CH1。
3.频率 1000Hz     分辨率1%
4.CCR 初始化为0，修改CCR改变占空比以改变亮度。

电路介绍： LED正极接GPIO A0,负极共地。