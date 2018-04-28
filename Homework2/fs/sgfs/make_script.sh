make clean;make -j4
insmod sgfs.ko
mount -t sgfs /dev/ /mnt/sgfs/
