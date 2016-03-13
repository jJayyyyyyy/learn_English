1. **grep**

 * grep ---> get regular expression

 * $ pgrep -l xxx

    根据关键词找其PID，然后可以kill


2. [tar](http://www.jb51.net/LINUXjishu/43356.h) **解压**

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


3. 起因：ubuntu下st无法输入中文，想要重装

    在terminal中输入subl [tab] 可以找到ST并运行，然而在`/usr/bin`, `/usr/share/applications`, 等处都没有发现sublime的执行文件，`~/.bashrc`中也没有sublime的路径(实在太乱了。。哪里都可以放。。)
    
    最后，从 `~/.bash_history` 找到 `/etc/environment`，在里面写了`PATH`

    估计是参考的[这里](http://www.2cto.com/os/201304/204819.html)

    以后要统一，不要随便放
    
4. command-line arguments (in CS50 Week 2, continued, 27:19)

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