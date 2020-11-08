#include <QWidget>
#include <QDebug>
#include <QMainWindow>
#include "mytest.h"
#include "ibaseclass.h"

void * __cdecl createInfoWidget(QWidget *parent)
{
	QWidget* pwidget = new MyTest(parent); //MyTest�̳�QWidget������Ҳ����QWidget
	if (parent != NULL)
	{
		QMainWindow* pMainWindow =  dynamic_cast<QMainWindow*>(parent); //����ָ��������ʹ��QMainWindow�����Լ����ж�
		Q_ASSERT(pMainWindow); //��pMainWindow���ԣ��ж�parent�Ƿ�����QMainWindow��������
		if (pMainWindow == NULL)
		{
			return NULL;
		}
		pMainWindow->setCentralWidget(pwidget);
	}
	return (void *)pwidget; //��󷵻�һ��void *ָ��
}

IBaseClass *__cdecl getInfoWidget(void *voidInfoWidget)
{
	//ͨ��createInfoWidget���ص�void *ָ��ת����ΪQWidget *��
	//������һ���е���࣬�����ǱȽ��ȵĲ���
	//����ע�⣺ָ��ת��֮ǰ��ôת�����ģ���Ҫһ������ת����ȥ������
	//Ҫ��void *-->QWidget *-->MyTest *-->IBaseClass*
	//����ֱ�Ӵ�void *-->IBaseClass*�����������
	QWidget* pwidget = (QWidget*)voidInfoWidget;
	MyTest*pInfoWidget = dynamic_cast<MyTest*>(pwidget);
	Q_ASSERT(pInfoWidget); //��pInfoWidget���ԣ��ж�pInfoWidget�Ƿ�����MyTest��������
	if(pInfoWidget == NULL)
	{
		return NULL;
	}
	IBaseClass* pIBaseClass =  dynamic_cast<IBaseClass*>(pInfoWidget); //��MyTest*ת����IBaseClass*�����ⲿ����
	return pIBaseClass;
}

void __cdecl destroyInfoWidget(void *voidInfoWidget)
{
	if (voidInfoWidget != NULL)
	{
		delete voidInfoWidget;
	}
	voidInfoWidget = NULL;
}
