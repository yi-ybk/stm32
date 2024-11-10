[TOC]

# 常用函数

- 配置清除

```
void XXX_DeInit
```

- 初始化

```
void XXX_Init
```

- 将传递的结构体赋一个默认值

```
void XXX_StructInit
```

# 定时器

## 定时

计数器溢出频率：

CK_CNT_OV = CK_CNT / （ARR + 1）

​                      = CK_PSC / （PSC + 1） / （ARR + 1）

时基单元中:

**PCS**（预分频器） ： 对基准时钟进行预分频，即**每多少频**CNT计数器计数 +1 （从0开始）

**CNT计数器** ： 计数器在计数时不断自增，直至到达目标值

**ARR**(自动重装载寄存器) ： 储存目标值，当CNT计数器到达目标值时，触发中 断，并将CNT计数器清零

定时中断的区分

![{275F31C3-2910-481F-8307-A265562A6CE1}](C:\Users\tianxuan\AppData\Local\Packages\MicrosoftWindows.Client.CBS_cw5n1h2txyewy\TempState\ScreenClip\{275F31C3-2910-481F-8307-A265562A6CE1}.png)

- 代表**更新中断**，触发中断函数

![{1F472F3E-A6BE-4F97-A7A9-D7936BDB5D56}](C:\Users\tianxuan\AppData\Local\Packages\MicrosoftWindows.Client.CBS_cw5n1h2txyewy\TempState\ScreenClip\{1F472F3E-A6BE-4F97-A7A9-D7936BDB5D56}.png)

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

- 定时中断基本结构

![image-20241109232033565](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241109232033565.png)

1. RCC开启时钟
2. 选择时基单元的时钟源:内部时钟源
3. 配置时基单元
4. 配置中断输出控制，允许更新中断输出到NVIC
5. 配置NVIC，打开定时器中断的通道，配置优先级
6. 使能计数器
7. 中断函数

# 函数

- 初始化时基单元

```
void TIM_TimeBaseInit
```

- 使能计数器

```
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState)
```

- 使能外设的中断输出

```
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState)
```

- 选择内部时钟

```
void TIM_InternalClockConfig(TIM_TypeDef* TIMx)
```

- 选择ITRx其他定时器

```
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
```

- 选择TIx捕获通道的时钟

```
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource, uint16_t TIM_ICPolarity, uint16_t ICFilter)
```

- ETR外部时钟模式1时钟

```
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter)
```

- ETR外部时钟模式2时钟

```
void TIM_ETRClockMode2Config()
```

- 配置ETR引脚的参数

```
void TIM_ETRConfig()
```

## 中断

- 中断函数*位于Start文件夹中的startup...*

配置

中断函数中，需要检测**中断标志位**，防止误触发

中断函数执行完后需要清除标志位

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



- PWM(Pulse Width MOdulation) 脉冲宽度调制

在具有惯性的系统中，可以通过对一系列脉冲的宽度进行调制，来等效地获得所需要的模拟参量，常应用于电机控速等领域

**注：**只能用于惯性系统

  PWM参数：   

  频率 = 1 / T~S~         占空比 = T~ON~ / T~S~       分辨率 = 占空比变化步距

 （T~S~：变化周期   T~ON~：高电平时长  T~OFF~：低电平时长）

![image-20241110160833762](C:\Users\tianxuan\AppData\Roaming\Typora\typora-user-images\image-20241110160833762.png)

PWM频率：	Freq = CK_PSC / (PSC + 1) / (ARR + 1)

PWM占空比：	Duty = CCR / (ARR + 1)

PWM分辨率：	Reso = 1 / (ARR + 1)