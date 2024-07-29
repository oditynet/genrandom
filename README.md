Псевдогенератор rundom символов. Обгоняет работу /dev/urandom

``` 
for i in 16 32 64 128 256 512 1024 2048 4096 8000 16000 32000 640000;do echo $i;timeout 1 ./genrand $i;ls -lh /tmp/1 ;done 
16
-rw-r--r-- 1 odity odity 185M июл 29 09:42 /tmp/1
32
-rw-r--r-- 1 odity odity 0 июл 29 09:42 /tmp/1
64
-rw-r--r-- 1 odity odity 5,6M июл 29 09:42 /tmp/1
128
-rw-r--r-- 1 odity odity 40M июл 29 09:42 /tmp/1
256
-rw-r--r-- 1 odity odity 189M июл 29 09:42 /tmp/1
512
-rw-r--r-- 1 odity odity 254M июл 29 09:42 /tmp/1
1024
-rw-r--r-- 1 odity odity 310M июл 29 09:42 /tmp/1
2048
-rw-r--r-- 1 odity odity 347M июл 29 09:42 /tmp/1
4096
-rw-r--r-- 1 odity odity 364M июл 29 09:42 /tmp/1
8000
-rw-r--r-- 1 odity odity 368M июл 29 09:42 /tmp/1
16000
-rw-r--r-- 1 odity odity 400M июл 29 09:42 /tmp/1
32000
-rw-r--r-- 1 odity odity 394M июл 29 09:42 /tmp/1
640000
-rw-r--r-- 1 odity odity 406M июл 29 09:42 /tmp/1
```
