sudo apt-get install libtool

~~用 C 的原因:~~  
- ~~小~~
- ~~底层~~
- 其他语言的问题:
  - Java 操作console不方便,而且依赖JVM.
  - ~~Python 不利于移动和封装~~

这个程序的交互式部分用 C 确实合适.但是在语句解析的部分继续用C只会徒增痛苦.  
但是真理也往往在不经意间明白的. 如果带有强烈主观色彩, 是不愿意放下的.  

所以目前我只能忍痛抛弃C, 换用Python重新实现.  
但是C是真的好玩.终于一日我要继续踏上C的旅程.  

功能:  
- [ ] what need I do now
- [ ] now I do: xxxx 
- [ ] I will do xxx in HH:MM (plan)
- [ ] show today history (real)
- [ ] show today/[someday] plan/real
- [ ] i want to watch bilibili/youtube.  
      response: no. YOU CAN NOT
- [ ] today: sport
- [ ] today: food
- [ ] today: sleep 
- [ ] free talk

```
I : 我现在要做什么
Su: 睡觉

I : 我现在要做什么
Su: 现在是吃饭时间段, 预计用时 20m, 要开始吃饭吗

I : 我今天的计划
Su: 1. xxx 2.xxx

I : 突发恶疾
Su: 应急措施: 1.xxx 2.xxxxx

Su: 可能存在久坐情况, 要执行活动指令吗
I : y
Su: 站起来, 去喝水(2m), 脖子运动4*8(5m). 开始执行清告我
I : y

I : 我要去喝水了
Su: 已记录, 我相信你
I : 我真的去睡觉了
Su: 已记录, 我相信你
I : 我去做运动
Su: 已记录, 我相信你
```

```bash
sudo apt-get install libedit-dev
cmake -G 'CodeBlocks - Unix Makefiles' -B cmake-build-debug
cmake --build cmake-build-debug --target LifeConsole -- -j 9
```

```bash
git clone --recurse-submodules
 
git submodule add git@github.com:troglobit/editline.git lib/editlinegit submodule update --remote
git submodule update --remote
```

https://www.jianshu.com/p/54292d374584

我对 editline 的理解
输入输出通过linux的文件描述符0,1 来进行. 
默认 unistd.read 来读取输入的一个字符 (src/editline.c:rl_getc)
然后会经过 emacs 来判断是否为特殊输入,这个Map可以在一开始进行按键注册
之后会进行相应输出,或者只是输出我们的输入
至此一次按键相应全过程结束
linux太强了

