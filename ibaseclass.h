#ifndef IBASECLASS_H
#define IBASECLASS_H

#include "common.h"

class IBaseClass
{
public:
	// ����ѧ����Ϣ
	virtual void LoadStudentInfo(QList<Student> &qlist) = 0;
	// ��ȡѧ����Ϣ
	virtual QList<Student> GetAllStudentInfo() = 0;
};

/**
 * @brief  createInfoWidget�ӿڴ�����һ��ѧ����Ϣ��ʾ���ڵ�void *ָ��,��ָ��ʵ������һ��QWidget*��ָ��
 *
 * @param  parent ������,Ĭ��Ϊ��
 * @return ����ѧ����Ϣ��ʾ���ڵ�void *����ָ��
 */
extern "C" __declspec(dllexport) void * __cdecl createInfoWidget(QWidget *parent = 0);

/**
 * @brief  getInfoWidget�ӿڽ�void *ת����IBaseClass *����ָ��
 *
 * @param  voidPlotWidget ѧ����Ϣ��ʾ���ڵ�void *����ָ��
 * @return ����IBaseClass���͵�ָ�룬���Ե���IBaseClass���LoadStudentInfo��GetAllStudentInfo2���ӿ�
 */
extern "C" __declspec(dllexport) IBaseClass *__cdecl getInfoWidget(void *voidInfoWidget);

/**
 * @brief  destroyInfoWidget�ӿ�������IBaseClass *���͵�ѧ����Ϣ��ʾ���ڶ���ָ��
 *
 * @param  voidInfoWidget IBaseClass *���͵�ѧ����Ϣ��ʾ���ڶ���ָ��
 */
extern "C" __declspec(dllexport) void __cdecl destroyInfoWidget(void *voidInfoWidget);
#endif // IBASECLASS_H
