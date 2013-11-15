#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h> 
#include <iostream>
#include "Student.h"
#include "Database.h"

using namespace std;

int main()
{
	Student stu1;
	stu1.SetAge(43);
	stu1.SetName("lindiaeng");
	stu1.SetID("PB112145");
    Database ustc;
	ustc.SetUser("root");
	ustc.SetPassword("");
	ustc.SetHost("localhost");
	ustc.SetDatabase("mysql");

	if(ustc.Connect())
	{
		if(ustc.Connect())
		{
			/*//插入数据
			ustc.StudentInsert(stu1);
			cout<<"插入数据成功\n";
			*/
			/*//删除数据
			ustc.StudentDelete(stu1);
			cout<<"删除数据成功\n";
			*/

		}
		else
		{
			cout<<"连接数据库错误\n";
			return 1;
		}
	}
	

	


}