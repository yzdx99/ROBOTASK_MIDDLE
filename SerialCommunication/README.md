利用STM32F103C8T6实现与电脑串口通信   Robomini初筛的中级任务文件

实现功能：
STM32与电脑的双向通信。     
1.STM32向电脑：字符、字符串、数字的传递 （汉字编码为UTF-8）   
2.电脑向STM32：单个字符/两位十六进制数传递，可以在OLED输出对应字符或十进制数字。

硬件介绍： 使用STM32F103C8T6、STlink、OLED、USB-TTL

软件介绍： 
1.该工程使用CubeMX生成初始化代码。   
2.使用USART实现与电脑的串口通信。     
3.Serial和OLED的函数在单独Hardware文件夹内定义。   
4.OLED使用IIC通信。   
5.串口工具使用江科大的。    


电路介绍： 
1.OLED:使用端口B6-B9。利用B8、B9的GPIO功能模拟IIC通信。    
2.USART:使用端口PA9、PA10的复用功能（USART_TX、RX）。
  USB-TTL与STM32共地。



YZDX