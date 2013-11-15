#ifndef MYSQLCONNECT_H 
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
	bool StudentInsert(Student &stu);	// 新增学生信息
	bool StudentDelete(Student &stu);	//删除学生信息
	bool StudentChange(Student &stu);	//修改学生信息
	bool StudentSelect(const char *condition);	//检索学生信息

	void SetUser(const char *user0);
	void SetPassword(const char *pswd0);
	void SetHost(const char *host0);
	void SetDatabase(const char *database0);

	Database();
	~Database();

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
bool Database::StudentInsert(Student &stu)
{
	int age=stu.GetAge();
	const char* name=stu.GetName();
	const char* id=stu.GetID();
	const char *sentence="insert into student values(";//23,"woewangy","pb1112");
	
	/*char charAge[2]={'0'};//有问题
	itoa(age,charAge,10);
	
	char* pAge=charAge;
	
	string strAge(pAge);
	
	*/
	string strName=name;
	string strId=id;
	string strSentence=sentence;
	ostringstream os;
	os<<age;

	strSentence+=os.str();
	string strQuery=strSentence+",\""+strName+"\",\""+strId+"\");";

	cout<<strQuery<<endl;

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

//删除学生信息-delete from student where name="name"
bool Database::StudentDelete(Student &stu)
{
	int age=stu.GetAge();
	const char *sentence="delet e from student age="+age;
	res=mysql_query(myCont,sentence);
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