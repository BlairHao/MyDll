#include "mytest.h"

MyTest::MyTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

MyTest::~MyTest()
{

}

void MyTest::LoadStudentInfo(QList<Student> &qlist)
{
	foreach(const Student &s, qlist)
	{
        ui.class_lineEdit->setText(s.strClass);
		ui.name_lineEdit->setText(s.strName);
		ui.sex_lineEdit->setText(s.strSex);
		ui.no_lineEdit->setText(s.strNo);
	}
}

QList<Student> MyTest::GetAllStudentInfo()
{
	QList<Student> qlist;
	Student s;
	s.strClass = ui.class_lineEdit->text();
	s.strName = ui.name_lineEdit->text();
	s.strSex = ui.sex_lineEdit->text();
	s.strNo = ui.no_lineEdit->text();
	qlist.push_back(s);
	return qlist;
}
