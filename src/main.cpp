/********************************************************************
  > File Name: main.cpp
  > Author:xisha
  > Mail: 1540348087@qq.com
  > Created Time: 2018年04月11日 星期三 15时05分34秒
********************************************************************/

#include "client/linux/handler/exception_handler.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void crash()
{
    int* p=NULL;
    *p=1;//崩溃点
}

static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descr,void*context,bool succeeded)
{
   //printf("crash occurs!\n");
   return true;
}

int main()
{
    google_breakpad::MinidumpDescriptor desc("../dump");//指定崩溃信息生成的路径
    google_breakpad::ExceptionHandler SystemCrashReport(desc,NULL,dumpCallback,NULL,true,-1);
	crash();
    return 0;
}
