[TOC]

# 基础知识

## 与门

![与门](D:\textbook\图片\与门.png)



| 输入A | 输入B | 输出 |
| :---: | :---: | :--: |
|   1   |   1   |  1   |
|   1   |   0   |  0   |
|   0   |   1   |  0   |
|   0   |   0   |  0   |

- 只有当所有输入端都为高电平）时，输出才为高电平1。如果任何一个输入端为低电平0，输出就为低电平0



## 或门

​						![或门](D:\textbook\图片\或门.png)											

| 输入A | 输入B | 输出 |
| :---: | :---: | :--: |
|   1   |   1   |  1   |
|   1   |   0   |  1   |
|   0   |   1   |  1   |
|   0   |   0   |  0   |

- 只要有一个或多个输入端为高电平1，输出就为高电平1。只有当所有输入端都为低电平0时，输出才为低电平0



## 非门

![非门](D:\textbook\图片\非门.png)

| 输入 | 输出 |
| :--: | :--: |
|  1   |  0   |
|  0   |  1   |

- 输出是输入的反相。如果输入为高电平1，输出就为低电平0；如果输入为低电平0，输出就为高电平1



## 异或门

![异或门](D:\textbook\图片\异或门.png)

| 输入A | 输入B | 输出 |
| :---: | :---: | :--: |
|   1   |   1   |  0   |
|   0   |   0   |  0   |
|   1   |   0   |  1   |
|   0   |   1   |  1   |

- 若两个输入的电平相异，则输出为高电平1；若两个输入的电平相同，则输出为低电平0



# 时钟源与时钟树

[时钟信号的讲解](https://www.bilibili.com/video/BV1ph4y1e7Ey/?spm_id_from=333.337.search-card.all.click&vd_source=675c025be7e8b947d00b503859eb0971)

## 边沿触发器

边沿触发器是一种数字电路元件，它在**时钟脉冲的特定边沿**（**上升沿**或**下降沿**）到来时接收输入数据，并在该跳变瞬间触发翻转，以**确保电路数据的准确接收**



![时钟信号](D:\textbook\图片\时钟信号.png)

- **上升沿触发** ：在上升沿触发方式中，边沿触发器在时钟脉冲CP**从低电平变为高电平的瞬间接收输入数据**，并触发翻转。这种触发方式能够确保在时钟信号的稳定上升沿时刻捕获输入数据，避免在时钟信号不稳定时接收数据可能导致的错误。
- **下降沿触发** ：在下降沿触发方式中，边沿触发器在时钟脉冲CP**从高电平变为低电平的瞬间接收输入数据**，并触发翻转。

<center>(向边沿触发器发送的,以供其识别的方波信号,即为时钟信号/时钟脉冲)

时钟信号由时钟源产生 , 由时钟树传播到全局



## 分频器

分频器相当于对时钟信号的频率做除法 , **改变对应硬件识别到的时钟频率**

# 基础内容

![image-20241113191715431](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241113191715431.png)



## 常用函数命名规则

- 配置清除

```c
void XXX_DeInit()
```

- 初始化

```c
void XXX_Init()
```

- 将传递的结构体赋一个默认值

```c
void XXX_StructInit()
```

- 使能或者失能外设xxx

```c
void xxx_Cmd()
```

- 使能或者失能来自外设xxx某中断源

```c
void xxx_ITConfig()
```

- 使能或者失能外设xxx的DMA接口

```c
void xxx_DMAConfig()
```

- 用以配置外设功能

```c
void XXX_XXXConfig()
```

- 检查外设xxx某标志位被设置与否(获取标志位状态)

```c
FlagStatus xxx_GetFlagStatus()
```

- 清除外设xxx标志位

```c
void xxx_ClearFlag()
```

- 判断来自外设xxx的中断发生与否

```c
FlagStatus xxx_GetITStatus()
```

- 清除外设xxx中断待处理标志位

```c
void xxx_ClearITPendingBit()
```



## 常见寄存器

1. **累加器（Accumulator）** - `A`
   - 用于存储运算结果，是算术和逻辑运算的主要寄存器。
2. **数据寄存器（Data Register）** - `D` 或 **`DR`**
   - 用于存储数据，有时也用于间接寻址。
     - **TDR（发送数据寄存器）**
     - **RDR（接收数据寄存器）**
3. **程序计数器（Program Counter）** - `PC`
   - 存储下一条要执行的指令的地址。
4. **堆栈指针（Stack Pointer）** - `SP`
   - 指向当前栈顶的内存地址，用于管理程序的调用和返回。
5. **状态寄存器（Status Register）** 或 **标志寄存器（Flag Register）** - `SR` 或 `PSW`
   - 包含各种状态标志，如进位标志（C）、零标志（Z）、溢出标志（V）等。
     - **RXNE（Receive *Not Empty*）**：接收缓冲器非空标志。**当RXNE标志位为1时**，表示UART的接收缓冲区中有新的数据可以被读取。这意味着数据已经接收完毕并存储在接收数据寄存器中，等待软件读取。读取数据后，RXNE标志位会被自动置为0。
     - **TXE（Transmit Data Register *Empty*）**：发送数据寄存器空标志。**当TXE标志位为1时**，表示UART的发送缓冲区为空，可以向其中写入新的数据进行发送。当数据被写入缓冲区后，TXE标志位会被自动置为0。
6. **指令寄存器（Instruction Register）** - `IR`
   - 存储当前正在执行的指令。
7. **输入/输出寄存器（I/O Register）**
   - 用于控制和监视单片机的I/O端口。
8. **定时器/计数器寄存器（Timer/Counter Register）**
   - 用于定时和计数功能。
9. **中断使能寄存器（Interrupt Enable Register）** - `IER`
   - 控制中断的使能状态。
10. **中断标志寄存器（Interrupt Flag Register）** - `IFR`
    - 指示哪些中断已经发生。
11. **控制寄存器（Control Register）**
    - 用于控制单片机的各种功能。
12. **地址寄存器（Address Register）** - `AR`
    - 存储内存地址，用于间接寻址。
13. **基址寄存器（Base Address Register）**
    - 用于存储内存的基地址。
14. **扩展寄存器（Extended Register）**
    - 用于扩展单片机的功能。
15. **看门狗定时器寄存器（Watchdog Timer Register）**
    - 用于系统监控和复位。



# 中断

- 中断函数*位于Start文件夹中的**startup**...*

配置

中断函数中，需要检测**中断标志位**，防止误触发

中断函数执行完后需要清除标志位

![image-20241113192004026](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241113192004026.png)

- 优先级分组

| **分组方式** | **抢占优先级**  | **响应优先级**  |
| ------------ | --------------- | --------------- |
| 分组0        | 0位，取值为0    | 4位，取值为0~15 |
| 分组1        | 1位，取值为0~1  | 3位，取值为0~7  |
| 分组2        | 2位，取值为0~3  | 2位，取值为0~3  |
| 分组3        | 3位，取值为0~7  | 1位，取值为0~1  |
| 分组4        | 4位，取值为0~15 | 0位，取值为0    |



# EXTI外部中断

支持的触发方式：上升沿/下降沿/双边沿/软件触发

支持的GPIO口：所有GPIO口，但相同的Pin不能同时触发中断

![image-20241113192014173](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241113192014173.png)



## AFIO

- AFIO主要用于引脚复用功能的选择和重定义
- 在STM32中，AFIO主要完成两个任务：复用功能引脚重映射、中断引脚选择

![image-20241113192656050](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241113192656050.png)

# 定时器

## 定时

计数器溢出频率：

CK_CNT_OV = CK_CNT / （ARR + 1）

​                      = CK_PSC / （PSC + 1） / （ARR + 1）

时基单元中:

**PCS**（预分频器） ： 对基准时钟进行预分频，即**每多少频**CNT计数器计数 +1 （从0开始）

**CNT计数器** ： 计数器在计数时不断自增，直至到达目标值

**ARR**(自动重装载寄存器) ： 储存目标值，当CNT计数器到达目标值时，触发中 断，并将CNT计数器清零



- 定时中断的区分:

![更新中断](D:\textbook\图片\更新中断.png)

- 代表**更新中断**，触发中断函数

![更新事件](D:\textbook\图片\更新事件.png)

- 代表**更新事件**，触发另一外设



## 计数模式

*基本定时器* 支持向上计数模式 ， *通用定时器* 和 *高级定时器* 支持向上计数 ， 向下计数 ， 中央对齐模式

向上计数 ：CNT计数 从0 到重装值，申请中断

向下计数 ：CNT计数 从重装值到0，申请中断

中央对齐： CNT计数 从0到重装值在到0，申请2次中断

**主要用向上计数**



## 基本操作

- 基本定时器

![image-20241109232021390](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241109232021390.png)

- 通用定时器

![image-20241109232042871](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241109232042871.png)

- 高级定时器

![image-20241113192904895](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241113192904895.png)

- 定时中断基本结构

![image-20241109232033565](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241109232033565.png)

1. RCC开启时钟
2. 选择时基单元的时钟源:内部时钟源
3. 配置时基单元
4. 配置中断输出控制，允许更新中断输出到NVIC
5. 配置NVIC，打开定时器中断的通道，配置优先级
6. 使能计数器
7. 中断函数



# TIM相关函数

- 初始化时基单元

```c
void TIM_TimeBaseInit()
```

- 使能计数器

```c
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState)
```

- 使能外设的中断输出

```c
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState)
```

- 选择内部时钟

```c
void TIM_InternalClockConfig(TIM_TypeDef* TIMx)
```

- 选择ITRx其他定时器

```c
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
```

- 选择TIx捕获通道的时钟

```c
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource, uint16_t TIM_ICPolarity, uint16_t ICFilter)
```

- ETR外部时钟模式1时钟

```c
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter)
```

- ETR外部时钟模式2时钟

```c
void TIM_ETRClockMode2Config()
```

- 配置ETR引脚的参数

```c
void TIM_ETRConfig()
```



## TIM输出比较

***OC (输出比较)***

- CCR(Captur/Compare Register) **捕获/比较寄存器**

通过比较 CCR 和 CNT 值的关系(小于,等于,大于), 输出对应的置1, 置0, 置1... 输出一个电平不断跳动的pwn波 

![image-20241110155706182](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241110155706182.png)

- 输出比较模式

| **模式**         | **描述**                                                     |
| ---------------- | ------------------------------------------------------------ |
| 冻结             | CNT=CCR时，REF保持为原状态                                   |
| 匹配时置有效电平 | CNT=CCR时，REF置有效电平                                     |
| 匹配时置无效电平 | CNT=CCR时，REF置无效电平                                     |
| 匹配时电平翻转   | CNT=CCR时，REF电平翻转                                       |
| 强制为无效电平   | CNT与CCR无效，REF强制为无效电平                              |
| 强制为有效电平   | CNT与CCR无效，REF强制为有效电平                              |
| PWM模式1         | 向上计数：CNT<CCR时，REF置有效电平，CNT≥CCR时，REF置无效电平向下计数：CNT>CCR时，REF置无效电平，CNT≤CCR时，REF置有效电平 |
| PWM模式2         | 向上计数：CNT<CCR时，REF置无效电平，CNT≥CCR时，REF置有效电平向下计数：CNT>CCR时，REF置有效电平，CNT≤CCR时，REF置无效电平 |



### PWM(Pulse Width MOdulation) 脉冲宽度调制

在具有惯性的系统中，可以通过对一系列脉冲的宽度进行调制，来等效地获得所需要的模拟参量，常应用于电机控速等领域

**注：**只能用于惯性系统

  PWM参数：   

  频率 = 1 / T~S~         占空比 = T~ON~ / T~S~       分辨率 = 占空比变化步距

 （T~S~：变化周期   T~ON~：高电平时长  T~OFF~：低电平时长）

![image-20241110160833762](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241110160833762.png)

PWM频率：	Freq = CK_PSC / (PSC + 1) / (ARR + 1)

PWM占空比：	Duty = CCR / (ARR + 1)

PWM分辨率：	Reso = 1 / (ARR + 1)



### OC(输出比较)相关函数

```c
void TIM_OCxInit();
/*x = 1~4 */
```

```c
void TIM_SetComparex(TIM_TypeDef* TIMx, uint16_t Compare1);
/*x = 1 ~ 4*/
/*修改CCR寄存器的值*/
```

```c
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
/*使用高级定时器时需要调用该函数 使能主输出 ,否则PWM不能正常输出*/
```

- OC初始化时,若使用通用定时器,可以只为 *结构体中所需参数* 进行初始化 , 再单独赋值 (*在将高级定时器作为通用定时器使用时, 若不为每一个成员赋值 , 则可能出错*)



# ADC模数转化器

- ADC（Analog-Digital Converter）模拟-数字转换器
- ADC可以将引脚上连续变化的模拟电压转换为内存中存储的数字变量，建立模拟电路到数字电路的桥梁
- 输入电压范围：0~3.3V ，转换结果范围：0~4095
- 规则组和注入组两个转换单元
- 模拟看门狗自动监测输入电压范围

![image-20241114234623406](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241114234623406.png)

![image-20241115094754718](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241115094754718.png)



- ADC有一个内置自校准模式。校准可大幅减小因内部电容器组的变化而造成的准精度误差
- 建议在每次上电后执行一次校准启动
- 校准前， ADC必须处于关电状态超过至少两个ADC时钟周期



## 转换模式

单次转换/多次转换  , 非扫描模式/扫描模式 , <u>两两组合</u>

单次转换 : ADC触发一次后即停止

多次转化 : ADC可多次触发,不会停止

非扫描模式 : 只能配置一个通道

扫描模式 : 可配置多个通道 , 但每个通道转换完成后不会产生任何    标志位或者中断 , 只有在一次触发中,所有通道都转换完成后才会产生标志位或者中断**(注 : 每个通道转换完成后 , 都会触发DMA请求 , 可用DMA将数据传出,防止被覆盖)** 



## 函数

```c
void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);
/*配置ADCCLA分频器(在rcc.h)*/
```

```c
void ADC_RegularChannelConfig();
/*选择规则组的输入通道*/
```

```c
void ADC_ResetCalibration(ADC_TypeDef* ADCx);
/*复位校准*/
```

```c
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
/*等待复位校准完成*/
```

```c
void ADC_StartCalibration(ADC_TypeDef* ADCx);
/*开始校准*/
```

```c
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
/*等待校准完成*/
```



# DMA

**DMA（Direct Memory Access）直接存储器存取**

## 存储器映像

![image-20241115161928132](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241115161928132.png)

![image-20241115201933116](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241115201933116.png)

- 传输计数器 **(自减计数器)** **:** 写入一个值后, DMA每传输一次,传输计数器的值减一, 直至0之后, DMA不会再转运,且自增的地址恢复到起始地址的位置
- 自动重装器 : 当传输计数器归0后, 使传输计数器恢复到初值   (决定了转运的模式 **单次模式** 或 **循环模式**)

- M2M (Memory to Memory) : 置0为硬件触发,置1为软件触发
- 软件触发 : 以最快的速度,连续触发DMA, 将传输计数器归0,一般<u>用于存储器到存储器的转运</u> **(不能与循环模式同时使用)**

​                  **(注: 写传输寄存器时,DMA必须处于关闭状态)**



# SPI通信协议

- SPI（Serial Peripheral Interface）是由Motorola公司开发的一种通用数据总线
- 四根通信线：
  - SCK（Serial Clock）时钟
  - MOSI（Master Output Slave Input）主机输出数据脚
  - MISO（Master Input Slave Output）主机输入数据脚
  - SS/CS（Slave Select）片选,用于指定通信的对象

- 同步，**全双工**
- 支持总线挂载多设备（一主多从）
- 电平特性 : 单端 -> 引脚的高低电平是相对GND的电压差 -> 需要接GND**(共地)**

## 硬件电路

- 所有SPI设备的SCK、MOSI、MISO**分别连在一起**
- 主机另外引出多条SS控制线，分别接到各从机的SS引脚
- **输出引脚**配置为**推挽输出**，**输入引脚**配置为**浮空或上拉输入**

## 移位

![image-20241116155744668](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241116155744668.png)

<center>先移高位



![image-20241117233826181](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241117233826181.png)

**SPI时序基本单元**

- 起始条件：SS/CS 从高电平切换到低电平
- 终止条件：SS/CS 从低电平切换到高电平

​	**(低电平表示选中 , 高电平表示空闲)**

选中过程中，SS需始终保持为低电平

![image-20241116162550701](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241116162550701.png)



1. **CPOL（Clock Polarity）**：定义了时钟信号在空闲（idle）状态下的电平。
   - CPOL=0：时钟空闲时输出低电平（0），有效时钟边沿为高电平（1），称为active-high。
   - CPOL=1：时钟空闲时输出高电平（1），有效时钟边沿为低电平（0），称为active-low。
2. **CPHA（Clock Phase）**：定义了数据采样的时钟边沿。
   - CPHA=0：在时钟的第一个边沿（leading edge）处采样数据
   - CPHA=1：在时钟的第二个边沿（trailing edge）处采样数据

## W25Qxx(存储模块)

![image-20241117150546809](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241117150546809.png)

## Flash操作注意事项

- 写入操作时：
  - 写入操作前，必须**先进行写使能**
  - 每个数据位**只能由1改写为0**，不能由0改写为1
  - 写入数据前**必须先擦除**，擦除后，所有数据位变为1
  - 擦除必须按最小擦除单元**(扇区)**进行
  - 连续写入多字节时，**最多写入一页的数据**，超过页尾位置的数据，会回到页首**覆盖写入**
  - 写入操作结束后，芯片进入忙状态，**不响应**新的读写操作

- 读取操作时：
  - 直接调用读取时序，**无需使能**，无需额外操作，**没有页的限制**，读取操作结束后不会进入忙状态，但**不能在忙状态时读取**



# 串口通信(USART)

- TX(Transmit Exchange) 数据发送脚

- RX(Receive Exchange) 数据接收脚

- 点对点通信, 只能实现两个设备之间的通信,通信时无需寻址 



## 电平标准

电平标准是数据1和数据0的表达方式，是传输线缆中人为规定的电压与数据的对应关系，**串口常用的电平标准**有如下三种：

- TTL电平：+3.3V 或 +5V 表示1，0V 表示0
- RS232电平：-3 ~ -15V 表示1，+3~+15V 表示0
- RS485电平：两线压差 +2 ~ +6V 表示1，-2 ~ -6V 表示0（差分信号)



## 串口参数及时序

- 波特率：串口通信的速率
- 起始位：标志一个数据帧的开始，**固定为低电平**
- 数据位：数据帧的有效载荷，1为高电平，0为低电平，**低位先行**
- 校验位：用于数据验证，根据数据位计算得来
- 停止位：用于数据帧间隔，**固定为高电平**

​       (空闲状态时置高电平)

![串口1](D:\textbook\图片\串口1.png)

![串口2](D:\textbook\图片\串口2.png)



- 自带波特率发生器，最高达4.5Mbits/s **(实际上为分频器)**

- 支持同步模式、硬件流控制 、DMA、智能卡、IrDA、LIN

​	(  硬件流控制 : **(多出一条接线 , 通过这条接线读取高低电平, 来判断是否发送数据,防止因为数据处理过慢导致数据丢失, 类似于标志位) ** )



## USART基本结构

![USART基本结构](D:\textbook\图片\USART基本结构.png)
