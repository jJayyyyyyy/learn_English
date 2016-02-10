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
