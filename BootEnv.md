# Boot env settings #
  * bootcmd=cp.b 0xC0042000 0x20400000 0x300000; bootm 0x20400000
  * bootargs=mem=64M console=ttyS0,115200 root=/dev/mtdblock1 rw rootfstype=yaffs2
  * bootdelay=0
  * baudrate=115200
  * ipaddr=192.168.77.61
  * serverip=192.168.77.66
  * ethaddr=46:52:69:69:0:X

# U-boot setup cmd #

```
setenv bootcmd cp.b 0xC0042000 0x20400000 0x300000\; bootm 0x20400000
setenv bootargs mem=64M console=ttyS0,115200 root=/dev/mtdblock1 rw rootfstype=yaffs2
setenv bootdelay 0
saveenv
```