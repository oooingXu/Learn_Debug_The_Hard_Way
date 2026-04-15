# 如何科学地调试-计算机小课堂

这是一个专为大一年级设计的 **C 语言调试方法实战项目**。通过一个带 Bug 的“黑客帝国数字雨”动画程序，你将亲手体验 **进阶版 Printf 大法**、**AddressSanitizer** 和 **GDB** 三种经典调试工具。

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

在Learn_Debug_The_Hard_Way目录下，运行init.sh，来初始化安装必要的工具。
```
source init.sh
```

编译cmatrix.c文件,并尝试运行
```
gcc cmatrix.c 
./a.out
```

