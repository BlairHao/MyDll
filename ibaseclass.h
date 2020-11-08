#ifndef IBASECLASS_H
#define IBASECLASS_H

#include "common.h"

class IBaseClass
{
public:
	// 加载学生信息
	virtual void LoadStudentInfo(QList<Student> &qlist) = 0;
	// 获取学生信息
	virtual QList<Student> GetAllStudentInfo() = 0;
};

/**
 * @brief  createInfoWidget接口创建了一个学生信息显示窗口的void *指针,该指针实际上是一个QWidget*的指针
 *
 * @param  parent 父窗口,默认为空
 * @return 返回学生信息显示窗口的void *类型指针
 */
extern "C" __declspec(dllexport) void * __cdecl createInfoWidget(QWidget *parent = 0);

/**
 * @brief  getInfoWidget接口将void *转换成IBaseClass *对象指针
 *
 * @param  voidPlotWidget 学生信息显示窗口的void *类型指针
 * @return 返回IBaseClass类型的指针，可以调用IBaseClass类的LoadStudentInfo，GetAllStudentInfo2个接口
 */
extern "C" __declspec(dllexport) IBaseClass *__cdecl getInfoWidget(void *voidInfoWidget);

/**
 * @brief  destroyInfoWidget接口是销毁IBaseClass *类型的学生信息显示窗口对象指针
 *
 * @param  voidInfoWidget IBaseClass *类型的学生信息显示窗口对象指针
 */
extern "C" __declspec(dllexport) void __cdecl destroyInfoWidget(void *voidInfoWidget);
#endif // IBASECLASS_H
