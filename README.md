## PHPprobe
This is a php probe for windows.It is written in C language and it can monitor your system.

compile on the gcc/g++,might be work on visual studio.
#if it can't.check the __int64

it has been tested on the windows 10 1709.

it just can get the cpu useage and the memory useage.

## how to use

1.put it into someplace where you find,which means
<program_dir>

notice:you can put it into some PATH place like "C:\Windows\System32\" that can use everywhere

2.compile the program with gcc/g++/vc++ whatever you like.which means
<program_name> maybe 'probe.exe'

3.run it.

sample:
probe

output:
cpu:xx.xx%
memory:xx.xx%

just cpu:
probe cpu
output:
xx.xx

just memory:
probe memory
output:
xx.xx

## 这是一个PHP的探针，用C语言写的控制台程序

采用GCC编译，理论上支持visual c++，不行的话去看__int64那里

在windows 10 1709版本通过测试。

它只能获得cpu使用率和内存使用率。

## 如何使用
