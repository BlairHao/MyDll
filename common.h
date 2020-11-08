#ifndef COMMON_H
#define COMMON_H

#include <QMetaType>
#include <QString>

struct Student
{
	QString strClass;
	QString strName;
	QString strSex;
	QString strNo;
};
Q_DECLARE_METATYPE(Student);

#endif //COMMON_H