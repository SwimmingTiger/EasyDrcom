# EasyDrcom
## Current Version: v0.8


### License
---
    Copyright (C) 2014 Shindo
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
        http://www.apache.org/licenses/LICENSE-2.0
        
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

### 民院修改版说明
---
该客户端已针对大连民族学院的网络环境进行修改，适用于民院宿舍网等仅需802.1x认证就能登陆的地区。

#### 编译&安装方法：

Ubuntu用户直接执行

    ./install

命令即可，该脚本可自动安装依赖包并进行编译。

若您使用的不是Ubuntu，请自行安装 g++ 编译器和 libpcap-dev 包，之后再执行 "./install"。若出现 apt-get 命令找不到的提示，忽略即可。

复制文件到 "/etc" 和 "/usr/local/bin" 需要root权限，固 "./install" 会调用 sudo 命令执行操作，请根据屏幕提示输入当前用户的密码。

若系统内无 sudo 命令，请切换到 root 用户并执行 "./install_root" 命令进行安装。

#### 使用说明：
    
首次使用需要配置登陆用户名和密码，用任意编辑器打开

    /etc/EasyDrcom.conf

把用户名和密码修改为自己的即可。

上线的命令为：

    drcom

下线的命令为：

    drcom off

由于网络操作需要root权限，drcom命令会使用sudo执行操作，故你可能需要输入当前用户的密码才能继续。若您是用 "./install_root" 进行的安装，请切换到root用户执行drcom命令。

#### 老虎会游泳修改于甲午年十月廿二

我的电子邮箱是：hu60.cn@gmail.com。

项目已修改，以下说明为原作者说明，仅供参考。

### What's EasyDrcom?
---
**EasyDrcom** 是 **_Shindo_** 编写的为哈尔滨工业大学（威海）量身定制的**第三方Dr.COM客户端**，可在教学区、家属区、学生区使用，可运行于_Windows, Mac OS X, Linux_（包括_OpenWrt_）。 

**EasyDrcom** 将校园网转换为无线信号，从此手机、平板上校园网无需使用学校提供的客户端、无需打开电脑共享Wifi。

有关如何使用 **EasyDrcom**, 请访问 http://bbs.ghtt.net/thread-1984091-1-1.html

### Compile Tips
---
#### 下面以向Linux平台编译为例。

编译 **EasyDrcom** 是十分简单的：

    g++ -DLINUX -Os -s -std=c++0x -o EasyDrcom md5.c main.cpp -lpcap -lpthread
    
你或许已经发现了，**EasyDrcom** 依赖于：
    
    libpcap (1.5.3)

_括号里标注的是作者使用的版本_

请注意，如果向OpenWrt编译的话，请再加上编译参数，并且把他放在-DLINUX前面：
    
    -D OPENWRT
    
这样的话，整体看起来像这样：

    g++ -DOPENWRT -DLINUX -Os -s -std=c++0x -o EasyDrcom md5.c main.cpp -lpcap -lpthread

### Special Thanks
---
**EasyDrcom** 的诞生离不开无数前辈的努力，下面列出的是参照的项目：

* jdrcom (@Google Code: http://code.google.com/p/jdrcom/)

同时，也离不开许多同学的测试，这里不再一一列举。
