#ifndef MYTEST_H
#define MYTEST_H

#include <QtWidgets/QWidget>
#include "ui_mytest.h"
#include "common.h"
#include "ibaseclass.h"
class MyTest : public QWidget, public IBaseClass
{
	Q_OBJECT

public:
	MyTest(QWidget *parent = 0);
	~MyTest();

protected://IBaseClass
	virtual void LoadStudentInfo(QList<Student> &qlist);
	virtual QList<Student> GetAllStudentInfo();

private:
	Ui::MyTestClass ui;
};

#endif // MYTEST_H
