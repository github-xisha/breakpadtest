Breakpad在Linux下的应用
-----------------------------------------------------------------------------------------------------------
一、主目录:
    src             存放用户编写的代码
    bin             存放可执行程序
    breakpad        breakpad开源项目源码
    symbols         保存生成的符号文件
    dump            保存运行时的崩溃信息
    CMakeLists.txt  

二、breakpad开源库的编译
1、编译安装
    cd breakpad
    ./configure
    make
    make install
2、生成的库和工具
    需要链接的静态库:libbreakpad_client.a  (路径:breakpad/src/client/linux/)
    用于生成符号文件:dump_syms  (路径:breakpad/src/tools/linux/dump_syms/)
    用于生成可读的堆栈信息:minidump_stackwalk  (路径:breakpad/src/processor/)

三、测试程序的编译:
1、cmake编译
    mkdir build
    cd build
    cmake ..
    make
2、直接编译
    g++ -g -I ./breakpad/src/ -o ./bin/crashapp ./src/main.cpp ./breakpad/src/client/linux/libbreakpad_client.a -lpthread

四、测试:
1、获取调试信息
    dump_syms crashapp > crashapp.sym
    head -n1 crashapp.sym     //会出现类似这样的字符串:C4E8DB657F2EB4C1782CD6BBC6E3DD6D0 
    mkdir ../symbols/crashapp 
    mkdir ../symbols/crashapp/C4E8DB657F2EB4C1782CD6BBC6E3DD6D0 
    mv crash.sym ../symbols/crashapp/C4E8DB657F2EB4C1782CD6BBC6E3DD6D0 
    
2、产生崩溃信息
    ./crashapp   //dump文件夹下会生成类似b2044a06-f906-4a3f-1070d68e-18eb55b3.dmp的文件 

3、生成可读的堆栈信息
    minidump_stackwalk ../dump/b2044a06-f906-4a3f-1070d68e-18eb55b3.dmp ../symbols 
    
-----------------------------------------------------------------------------------------------------------
