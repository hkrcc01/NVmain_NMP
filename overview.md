# Update-8.1

## 一、Trace

    整体改动包括：include/NMPInst、NVMainTraceReader & TraceLine、traceMain

### （一）include/NMPInst

创建对象，该对象是对于NMP相关指令的抽象，对该指令进行封装，*counterpart of NVMRequest*

### （二）NVMainTraceReader & TraceLine

TraceLine成为读入一行NMPInst的过度对象

### （三）traceMain

修改其核心循环代码，将原本的读入常规的mem请求改成读入相应的NMPInst指令。

### Summary

    对于全局来说，该模块主要是将原本的读入常规的mem指令转换为读特殊的NMPInst指令。

## 二、MemController

### （一）transactionQueue

由于该queue是对于MemController来说的，原本该容器内部类型为NVMRequest类型，现在考虑将原本的request转换成适配NMPInst指令的request对象。

使得每一次请求提交过后，NMPInst指令进入相应的transactionQueue当中，sum相当于原本的read指令，而原本对应write指令的transactionQueue作废。

### （二）commandQueue

原本的commandQueue不变，还是对应相应的bank的事件队列

## 三、EventQueue & Global~

原本事件类型包括：

1. EventCycle：事件循环主体，将TransactionQueue当中的请求转入Command当中
2. EventCallback：请求本身触发的事件，包括clearUpCallback、CommandQueueCallback等
3. EventResponse：请求生命周期结束，计算相应开销

添加的事件分支：

1. EventCallback：该事件分支当中包含有CommandQueueCallback、clearUpCallback等，**现添加对于部分和加总、加总的最终和传送相对应的Callback事件，同时添加所对应的请求类型**

2. EventRespond：**添加相对应的计算参数开销。**
