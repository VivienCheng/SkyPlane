# SkyPlane

### 一.游戏背景概述

   该游戏基于c++，以Visual Studio 2015为环境，使用了MFC框架。
   
   创建时间：2017年6月到2017年8月。
      
### 二.角色介绍

  玩家战机：具有直线飞行的导弹和追踪型导弹，可补充血量和加速。
   
  僚机天使：当吃星星到150积分时会出现僚机天使，会在玩家战机左右两侧出现僚机。
   
  敌机：具有多种不同的敌机飞行方式和导弹飞行方式，厚薄不均的云层可供敌机藏身。
   
  道具：吃到星星来积分，吃到红心可补充血量，吃到蓝币可使玩家战机加速，吃到盒子爆出随机道具。
   
### 三.功能介绍

  上帝模式／无敌模式：G键
  
  控制战机飞行：上下左右方向键或者WASD键
  
  控制战机发射直线飞行子弹／控制战机发射追踪导弹：空格键／Q键
  
  让僚机直线飞到玩家身边／让僚机在各自区域内飞行：Z键／X键
  
  结束游戏：Esc键
  
### 四.图解游戏设计

**1.游戏流程**

![Aaron Swartz](https://raw.githubusercontent.com/VivienCheng/SkyPlane/master/%E5%9B%BE%E7%89%87/%E9%A3%9E%E6%9C%BA%E5%A4%A7%E6%88%9801.jpg)

**2.游戏框架设计**

![Aaron Swartz](https://raw.githubusercontent.com/VivienCheng/SkyPlane/master/%E5%9B%BE%E7%89%87/%E9%A3%9E%E6%9C%BA%E5%A4%A7%E6%88%9802.jpg)

**3.飞行方式设计**

![Aaron Swartz](https://raw.githubusercontent.com/VivienCheng/SkyPlane/master/%E5%9B%BE%E7%89%87/%E9%A3%9E%E6%9C%BA%E5%A4%A7%E6%88%9803.jpg)
  
### 五.涉及的技术

● 运用工厂模式，模板模式，策略模式等多种设计模式。

● 二次贝塞尔曲线技术

● 追踪导弹技术

● 僚机天使飞行变换技术

● 链表存储技术

● 定时器技术

● 随机产生道具技术
