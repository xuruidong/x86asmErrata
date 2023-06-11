
all:
	rm -f boot.MBR
	#wget http://192.168.56.101:8000/boot.MBR
	cp /e/MBRHelloWorld-master/boot.MBR .
	dd if=boot.MBR of=asm2.vhd bs=512 count=1 conv=notrunc