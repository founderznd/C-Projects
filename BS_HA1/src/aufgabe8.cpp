/*
 * aufgabe8.cpp
 *
 *  Created on: 2014-4-15
 *      Author: nandi
 */

/*opendir（打开目录）

 相关函数
 open，readdir，closedir，rewinddir，seekdir，telldir，scandir
 表头文件
 #include<sys/types.h>
 #include<dirent.h>
 定义函数
 DIR * opendir(const char * name);
 函数说明
 opendir()用来打开参数name指定的目录，并返回DIR*形态的目录流，和open()类似，接下来对目录的读取和搜索都要使用此返回值。
 返回值
 成功则返回DIR* 型态的目录流，打开失败则返回NULL。
 错误代码
 EACCESS 权限不足
 EMFILE 已达到进程可同时打开的文件数上限。
 ENFILE 已达到系统可同时打开的文件数上限。
 ENOTDIR 参数name非真正的目录
 ENOENT 参数name 指定的目录不存在，或是参数name 为一空字符串。
 ENOMEM 核心内存不足。

 readdir（读取目录）

 相关函数
 open，opendir，closedir，rewinddir，seekdir，telldir，scandir
 表头文件
 #include<sys/types.h>
 #include<dirent.h>
 定义函数
 struct dirent * readdir(DIR * dir);
 函数说明
 readdir()返回参数dir目录流的下个目录进入点。

 结构dirent定义如下
 struct dirent
 {
 ino_t d_ino;					//d_ino 此目录进入点的inode
 ff_t d_off;						//d_off 目录文件开头至此目录进入点的位移
 signed short int d_reclen;		//d_reclen d_name的长度，不包含NULL字符
 unsigned char d_type;			//d_type d_name 所指的文件类型
 har d_name[256;					//d_name 文件名
 };

 返回值
 成功则返回下个目录进入点。有错误发生或读取到目录文件尾则返回NULL。
 附加说明
 EBADF参数dir为无效的目录流。

 closedir（关闭目录）

 相关函数
 opendir
 表头文件
 #include<sys/types.h>
 #include<dirent.h>
 定义函数
 int closedir(DIR *dir);
 函数说明
 closedir()关闭参数dir所指的目录流。
 返回值
 关闭成功则返回0，失败返回-1，错误原因存于errno 中。
 错误代码
 EBADF 参数dir为无效的目录流
 范例
 参考readir()。*/

#include <iostream>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char **argv) {

	DIR *dirp;
	struct dirent *direntp;

	if (argc == 1) {
		cout << "there is no Directory" << endl;
		return 0;
	}

	if ((dirp = opendir(argv[1])) == NULL) {
		cout << "wrong Directory" << endl;
		return 0;
	}

	int sum = 0;
	while ((direntp = readdir(dirp)) != NULL) {
		cout << direntp->d_name << "\t" << direntp->d_reclen << endl;
		sum += direntp->d_reclen;
	}
	closedir(dirp);

	cout << "Summe = " << sum << endl;
	return 0;
}

