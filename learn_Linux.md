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
    
