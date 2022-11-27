# x86asmErrata
《x86汇编语言：从实模式到保护模式》勘误表

## 作者网站
[作者网站 http://www.lizhongc.com/](http://www.lizhongc.com/)  

## 工具使用
### 引导扇区写入
可以使用dd命令
比如编译后的程序是asm.bin, 虚拟硬盘是sys.vhd  
```
dd if=asm.bin of=sys.vhd bs=512 count=1 conv=notrunc
```
