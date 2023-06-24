
# 一个极简的系统引导

## 加电启动

BIOS -- MBR --- KERNEL

计算机在刚加电启动时，RAM 中是空的，没有可执行的程序。那第一步要做什么呢？
运行BIOS

## BIOS
### BIOS 是如何被运行的？
x86 CPU 加电后首先进入16位实模式，16位模式下的寻址方式：

在实模式下，可以访问 1M 的内存空间，但这 1M 的空间，并不是全部都是 DRAM, 以下是空间分布：
![实模式下内存空间分布, 显示缓冲区]()

在 x86 系统中，将 1M 空间最上面的 0xF0000 到 0xFFFFF 这 64K 映射给 ROM， ROM 中固化了初始化程序，就是平时说的 BIOS。计算机在加电后，CS 的值是 0xF000， IP 的值为 0xFFF0, 

在 F000:FFF0 这里保存的是什么？
指令地址会增加，但 大于F000:FFFF 时，就会溢出，所以这里保存了一条跳转指令

### BIOS 做了什么？
初始化、检查硬件：如检查内存  
创建中断向量表和中断服务例程：键盘、鼠标  
选择引导设备，加载 MBR


BIOS 被加载到哪里  


BIOS 加载中断向量表和中断程序

## MBR （bootloader）
BIOS 完成硬件自检后，会根据配置的启动顺序来选择引导设备，通常是硬盘或可移动设备。MBR(Master boot record) 是主引导记录，BIOS 会将 MBR 加载到内存中来运行。保存 MBR 的扇区叫做主引导扇区，是存储设备的第一个扇区。
![磁盘扇区]()

如何校验 MBR?  

### MBR 如何运行起来

我们的系统，一般是存储在硬盘上，当计算机被配置为从磁盘启动时，BIOS 会将磁盘的第一个扇区的内容加载到 0x0000:0x7c00， 然后 jmp
![图。。。。]()


### 为什么是 0x7c00



### 实验加载 MBR
```
mov ax,0xb800
mov ds,ax
mov byte [0x00],'a'
mov byte [0x02],'s'
mov byte [0x04],'m'
jmp $
times 510-($-$$) db 0
db 0x55,0xaa
```

## 中断
### BIOS 是如何加载 MBR 的？
引出中断， 通过介绍中断来解释问题， 如何读硬盘


### 硬中断和软中断


#### BIOS 中断
中断向量表： 256 个， 每个 4 字节，共 1k
中断服务程序

BIOS 中断向量表
![中断执行跳转过程]()


在 MBR 上读磁盘？ 



### 系统调用的执行过程
系统调用是基于软中断的， `int 0x80`  

### 实验使用中断来调用BIOS 的中断服务程序
```
main.c
```

## 加载系统

* 如何加载？
* 加载多大？
* 如何执行加载后的程序？


---

[从零开始写 OS 内核 -](https://segmentfault.com/a/1190000040131294)  
[使用 C 语言编写运行于16位实模式下的代码](https://kviccn.github.io/posts/%E4%BD%BF%E7%94%A8c%E8%AF%AD%E8%A8%80%E7%BC%96%E5%86%99%E8%BF%90%E8%A1%8C%E4%BA%8E16%E4%BD%8D%E5%AE%9E%E6%A8%A1%E5%BC%8F%E4%B8%8B%E7%9A%84%E4%BB%A3%E7%A0%81.html)   
[实模式C语言MBR程序](https://i-m.dev/posts/20180124-234628.html)  
[Writing a boot loader in Assembly and C - Part 1](https://www.codeproject.com/articles/664165/writing-a-boot-loader-in-assembly-and-c-part)  
以下两个可用，但 mingw 不能编译  
[BootLoaderHelloWorld](https://github.com/darkautism/BootloaderHelloWorld)  
[MBRHelloWorld](https://github.com/darkautism/MBRHelloWorld)


[使用GCC和GNU Binutils编写能在x86实模式运行的16位代码](https://linux.cn/article-3873-1.html)  


假设磁盘上保存了一个操作系统，如何加载这个系统呢？
### 在实模式下加载程序并运行


### 在保护模式下加载程序并运行







---
## 问题引出
段错误的原理？  
系统调用的实现？  
swap 相关的内存管理  
硬中断、软中断？
应用程序（用户态）如何调用内核的代码？ 
mbr 调用 BIOS 的代码