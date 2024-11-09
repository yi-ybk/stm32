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

= CK_PSC / （PSC + 1） / （ARR + 1）

时基单元中:

PCS（预分频器） ： 对基准时钟进行预分频，即**每多少频**CNT计数器计数 +1 （从0开始）

CNT计数器 ： 计数器在计数时不断自增，直至到达目标值

自动重装载寄存器 ： 储存目标值，当CNT计数器到达目标值时，触发中 断，并将CNT计数器清零

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