# 如何科学地调试-计算机小课堂

这是 **深圳技术大学“一生一芯”工作室**（深技术工作室）专为低年级同学设计的 **C 语言调试方法实战项目**。通过一个带 Bug 的“黑客帝国数字雨”动画程序，你将亲手体验 **进阶版 Printf 大法**、**AddressSanitizer** 和 **GDB** 三种经典调试工具。

# 快速开始

## 📥 获取项目代码

### 方式一：从工作室网站下载（适合新手）
1. 访问工作室资源站：[http://10.104.7.240/index.php/2024/12/23/164/](http://10.104.7.240/index.php/2024/12/23/164/)  
2. 找到 **“小课堂第六讲：如何科学地调试”**，下载 `工作室小课堂-第六讲资料资料包`。

### 方式二：通过 Git 克隆（推荐有 Git 基础的同学）
```
git clone git@github.com:oooingXu/Learn_Debug_The_Hard_Way.git
cd Learn_Debug_The_Hard_Way
```

## 运行初始化脚本，安装必要的工具
在Learn_Debug_The_Hard_Way(LDTHW)目录下，运行init.sh，来初始化安装必要的工具。
```
source init.sh
```

## 编译程序并运行
编译cmatrix.c文件,并尝试运行
```
gcc cmatrix.c 
./a.out
```

# 目录结构概览
```
$(LDTHW_HOME)               # Learn Debug The Hard Way 项目根目录
├── cmatrix.c               # cmatrix.c 黑客帝国C程序
├── cmatrix_error.c         # cmatrix_error.c 故意注入BUG的黑客帝国C程序
├── init.sh                 # 初始化脚本
├── Makefile                # Makefile文件
├── README.md               # README文件
├── setup-path.sh           # 设置路径脚本
└── 如何科学的调试.pptx     # PPT课件
```

# 背景
本项目基于“一生一芯”24.07讲义 C3 调试技巧简化来创作的，通过深技术工作室在日常或者寒暑期训练营时，观察学员调试BUG时只会用printf，旨在分享一些更好的调试工具，帮助同学们调试。想要更深入的学习调试技巧的话，推荐大家去看[“一生一芯”24.07 讲义 C3 调试技巧](https://ysyx.oscc.cc/docs/2407/c/3.html)
