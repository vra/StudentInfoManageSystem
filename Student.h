#ifndef	STUDENT_H
#define STUDENT_H

class Student
{
public:
	void SetAge(int age0);
	void SetName(const char*name0);
	void SetID(const char*id0);
	int GetAge();
	const char* GetName();
	const char* GetID();
	Student();
	~Student();

private:
	int age;
	const char* name;
	const char* id;
};

int Student::GetAge()
{
	return age;
}
const char* Student::GetName()
{
	return name;
}
const char* Student::GetID()
{
	return id;
}
void Student::SetAge(int age0)
{
	age=age0;
}
void Student::SetName(const char* name0)
{
	name=name0;
}
void Student::SetID(const char* id0)
{
	id=id0;
}
Student::Student()
{
}

Student::~Student()
{
}
#endif