## 1. **grep**

* grep ---> get regular expression

* $ pgrep -l xxx

	根据关键词找其PID，然后可以kill


## 2. **[tar](http://www.jb51.net/LINUXjishu/43356.h)** **解压**

*  -x extract

   -z, --gzip      filter the archive through gzip

   -j, --bzip2     filter the archive through bzip2

   -v,				Produce verbose output, 显示详细信息

   -f
    
* 对于 .tar

	$ tar -xf xxx.tar
    
* 对于 .tar.gz 或者 .tgz

	$ tar -xzf xxx.tar.gz
    
	$ tar -xzf xxx.tgz
    
* 对于 .tar.bz2

	$ tar -xjf xxx.tar.bz2
    
* 其他

	$ tar --help
    
	$ man tar


## 3. 起因：ubuntu下st无法输入中文，想要重装

在terminal中输入subl [tab] 可以找到ST并运行，然而在`/usr/bin`, `/usr/share/applications`, 等处都没有发现sublime的执行文件，`~/.bashrc`中也没有sublime的路径(实在太乱了。。哪里都可以放。。)
    
最后，从 `~/.bash_history` 找到 `/etc/environment`，在里面写了`PATH`

估计是参考的[这里](http://www.2cto.com/os/201304/204819.html)

以后要统一，不要随便放
    
## 4. **command-line arguments** (in CS50-Week2, continued, 27:19)

*  int main(int argc, string argv[])

   argument vector, string argv[]表明这参数是字符串数组(数组的数组)

   argument counts, int argc指明string长度
    
*  比如 `$ mv test.c ..`的参数长度`argc`是`3`，第`0`个是`mv`, `1`是`test.c`, `2`是`..`即上一层目录 

*  实例(保存为`test.c`)
    
   ```c
   #include <stdio.h>
  
   int main(int argc, char * argv[]){
   	//c没有<string>这个类型，改用 <char **>
   	printf("Hello, %s\n", argv[1]);
   }
   ```
    
   然后
   
   ```sh
   $ make test
   $ ./test John
   ```
   就会输出 `Hello, John`, 就能输入参数了
   
   注：在`/learn_English/examples`中保存了`command-line_arguments.c`作为例程，可以`make`，不过名字太长不好打(`make`编译工程是根据文件名的)，可以用`$ clang -o test command-line_arguments.c`, 其中的test可以随便写，作为编译输出的文件，而后面要编译的文件名可以直接用`tab`
      
## 5. **some handy tools**

* `$ bc` 计算器

	`$ whatis bc`  
	`bc - An arbitrary precision calculator language`
	
* `$ ls -al ~`  	
	显示`~`目录下，所有文件及其属性
	
	ls - list directory contents

* `$ date`	显示日期和时间
	
* `$ cal`	日历


## 6. **some hot keys for `man`**

key	|	function
---|---|
[space] | page Down 
[Page Down] | page Down 
[Page Up] | page Up 
[Home] | up to home 
[End] | down to the end 
/xxx | search xxx (down) 
?xxx | search xxx (up) 
n, N | next/previous key word 
q | quit
	
## 7. 文件与目录管理

#### 7.1 目录与路径

cd ---> Change Directory
	
pwd ---> Print Working Directory
	
mkdir , 创建多层目录时  
`$ mkdir -p /test1/test2/test3`  
否则只能一层一层地创建
	
`$ rm -r test` #删除非空目录，但是无法恢复，如果用`rmdir`至少还有提示，而且无法删除非空目录
	
#### 7.2 取得路径的 文件名 与 目录名称

```
$ basename /etc/hosts
hosts
$ dirname /etc/hosts
/etc
```
#### 7.3 文件内容查阅

* cat 从第一行开始显示内容(concatenate, 连续)

* tac 也就是cat反过来，从最后一行开始(mac 没有)

* nl 显示的时候增加 行号

* **more** 一页一页地显示

* **less** 与more类似，但可以往前翻页

* head 只看开头几行

* tail 只看结尾几行

* od 以二进制读取文件

#### 7.4 修改文件时间或创建新文件: touch

`$ touch filename`

待更新

#### 7.5 查看文件类型

`$ file readme.md`

#### 7.6 命令与文件的查询

查找文件，鸟哥说通常不用`find`，因为速度很慢。经常使用的是`whereis` 和 `locate`

但是。。。mac下竟然没有。。或者说是不完全的。。。而且用法也不一样

`$ find . -name 'readme.md'`

`$ find . -name 'Lesson5*.md'`

`$ find . -name '*readme*'`

通配符 `*` `?`


## 8. **ssh**

baike: Secure Shell, SSH 为建立在应用层和传输层基础上的安全协议。SSH 是目前较可靠，专为远程登录会话和其他网络服务提供安全性的协议。利用 SSH 协议可以有效防止远程管理过程中的信息泄露问题。  
man page: ssh (SSH client) is a program for logging into a remote machine and for executing commands on a remote machine.

连接到树莓派：

`$ ssh pi@192.168.1.105`

移除hosts：

`$ ssh-keygen -R 192.168.1.105`


## 9. **vi**

:set nu		#显示行号

:set nonu	#取消行号

* **移动光标**

30↓ = 光标向下移动30行

n+<Enter> = 向下移动n行

n+<Space> = 数字n加空格，光标向右移动n个字符距离

0 = [home]

$ = [end]

G = 移到最后一行(大小写配合Caps Lock更快)

nG = 移动到第n行，可以配合 :set nu

gg = 1G = 移动到第一行

* **查找与替换**

/str = 向下查找str

?str = 向上查找str

n = 查找下一个

N = 查找上一个

:100,200s/aaa/bbb/g = 从第100行到第200行查找aaa，并替换为bbb

:1,$s/aaa/bbb/gc = 从第1行到最后一行查找aaa，并替换为bbb，c表示需要用户confirm确认

* **删除、复制、粘贴**

x = Del

X = Backspace

dd = 删除整行

ndd = 从这行开始删除n行

dgg = 从这行开始向上删除到第一行

dG = 从这行开始向上删除到最后一行

d$ = 从光标删到本行最后

d0 = 从光标删到本行开头

yy = 复制本行，nyy ygg yG y0 y$类比dd

p = 粘贴到下一行

P = 粘贴到上一行

J = 与下一行合并

. = 重复上一个操作(Word里面的F4)

u = [ctrl+z] 撤销

ctrl+r = [ctrl+y] 重做

* **Visual Block 块选**

可以加数字

v = 选中所在字符

V = 选中所在行

ctrl+v = 纵向选择




