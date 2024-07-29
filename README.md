Псевдогенератор rundom символов. Обгоняет работу /dev/urandom
Анализ скорости записи рандомных чисел относительно размера буфера в секунду:
```
for i in 16 32 64 128 256 512 1024 2048 4096 8000 16000 32000 640000;do echo $i;timeout 1 ./genrand $i;ls -lh /tmp/1|awk '{print $5 " "$NF}';done
16
247M /tmp/1
32
59M /tmp/1
64
5,5M /tmp/1
128
40M /tmp/1
256
188M /tmp/1
512
256M /tmp/1
1024
300M /tmp/1
2048
344M /tmp/1
4096
368M /tmp/1
8000
372M /tmp/1
16000
399M /tmp/1
32000
395M /tmp/1
640000
406M /tmp/1
```

Run: ./genrand
or 
./genrand 256
