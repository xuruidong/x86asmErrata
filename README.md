# x86asmErrata
《x86汇编语言：从实模式到保护模式》 第一版 勘误表

## 作者网站
[作者网站 http://www.lizhongc.com/](http://www.lizhongc.com/)  

## 工具使用
### 引导扇区写入
可以使用dd命令
比如编译后的程序是asm.bin, 虚拟硬盘是sys.vhd  
```
dd if=asm.bin of=sys.vhd bs=512 count=1 conv=notrunc
```

### 显示磁盘参数 DiskGeometry
使用工具[Azure VHD utilities https://github.com/Microsoft/azure-vhd-utils](https://github.com/Microsoft/azure-vhd-utils)  

```
./azure-vhd-utils.exe inspect footer --path ../asm2.vhd
Cookie            : conectix
Features          : Reserved
FileFormatVersion : 65536
HeaderOffset      : -1
TimeStamp         : 2023-02-02 13:02:58 +0000 UTC
CreatorApplication: vbox
CreatorVersion    : 393217
CreatorHostOsType : Windows
PhysicalSize      : 8388608 bytes
VirtualSize       : 8388608 bytes
DiskGeometry      : Cylinder:240 Heads:4 Sectors:17
DiskType          : Fixed
CheckSum          : 4294960929
UniqueID          : 2e24b2b2-2bb0-4874-84b5-5d11ac92938b
SavedState        : false
```

## Intel® 64 and IA-32 Architectures Software Developer Manuals
[Intel® 64 and IA-32 Architectures Software Developer Manuals](https://www.intel.cn/content/www/cn/zh/developer/articles/technical/intel-sdm.html)  
