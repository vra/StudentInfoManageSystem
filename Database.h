﻿#ifndef MYSQLCONNECT_H 
#define MYSQLCONNECT_H

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h> 
#include <iostream>
#include "Student.h"
#include "../../Header/std_lib_facilities.h"
class Database
{
public:
	bool Connect();						//连接数据库,返回bool表示连接成功与否，类名就是数据库名字
	void SetUser(const char *user0);
	void SetPassword(const char *pswd0);
	void SetHost(const char *host0);
	void SetDatabase(const char *database0);

	Database();
	~Database();

	//学生
	bool StudentInsert(Student &stu);				// 新增学生信息
	bool StudentDelete(Student &stu);				//删除学生信息
	bool StudentChange(Student &stu);				//修改学生信息
	bool StudentSelect(const char *condition);		//检索学生信息

	//课表
	bool ClassTableInsert(Student &stu);			//新增学生课表
	bool ClassTableDelete(Student &stu);			//删除学生课表
	bool ClassTableChange(Student &stu);			//修改学生课表信息
	bool ClassTableSelect(const char* condition);	//检索学生信息





	

private:
	const char* user;			//username
    const char* pswd;			//password
    const char* host;			//or"127.0.0.1"
    const char* database;			//database  
	MYSQL *myCont;
    MYSQL_RES *result;
    MYSQL_ROW sql_row;
    MYSQL_FIELD *fd;
    char column[32][32];
    int res;
};

//连接数据库并课表初始化并创建,返回bool表示连接成功与否，类名就是数据库名字
bool Database::Connect()
{
	try
	{
		myCont=mysql_init((MYSQL*)0);
	}
	catch(...)
	{
		//std::cout<<"数据库初始化错误\n";在主程序中不应该有弹窗信息
		return false;
	}

	try
	{
		if(mysql_real_connect(myCont,host,user,pswd,database,3306,NULL,0))
		{
			//初始化学生表和课表
			
		}
		else
			return false;
	}catch(...)
	{
		//std::cout<<"数据库连接错误";在主程序中不应该有弹窗信息
		return false;
	}
}

// 新增学生信息-insert into student values("name"...);
//待完善：1.学号正确性检查2.学号为主键，避免重复输入
bool Database::StudentInsert(Student &stu)
{
	int age=stu.GetAge();
	string strName=stu.GetName();
	string strId=stu.GetID();

	string strSentence="insert into student values(";

	//int转化为string的方法
	ostringstream os;
	os<<age;
	strSentence+=os.str();
	
	//将string转化为const char*
	string strQuery=strSentence+",\""+strName+"\",\""+strId+"\");";
	const char* query=strQuery.c_str();

	res=mysql_query(myCont,query);
	if (!res)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//删除学生信息-delete from student where id="PB..."
//待完善：1.库中无此学生的处理
bool Database::StudentDelete(Student &stu)
{
	string id=stu.GetID();
	string sentence="delete from student where id=\""+id+"\";";
	const char* query=sentence.c_str();
	cout<<query<<endl;
	res=mysql_query(myCont,query);
	if (!res)
	{
		return true;
	}
	else
	{
		return false;
	}
}	

//修改学生信息-先删除原来信息再插入
bool Database::StudentChange(Student &stu)
{
	return true;
}

//检索学生信息-应该根据所给条件检索，故用char* condition
bool Database::StudentSelect(const char *condition)
{
	return true;
}


Database::Database()
{
}

Database::~Database()
{
}

void Database::SetUser(const char *user0)
{
	user=user0;
}

void Database::SetPassword(const char *pswd0)
{
	pswd=pswd0;
}
void Database::SetHost(const char *host0)
{
	host=host0;
}
void Database::SetDatabase(const char *database0)
{
	database=database0;
}

#endif