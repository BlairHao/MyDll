#include <QWidget>
#include <QDebug>
#include <QMainWindow>
#include "mytest.h"
#include "ibaseclass.h"

void * __cdecl createInfoWidget(QWidget *parent)
{
	QWidget* pwidget = new MyTest(parent); //MyTest继承QWidget，所以也属于QWidget
	if (parent != NULL)
	{
		QMainWindow* pMainWindow =  dynamic_cast<QMainWindow*>(parent); //这里指定父窗口使用QMainWindow，所以加以判断
		Q_ASSERT(pMainWindow); //对pMainWindow断言，判断parent是否属于QMainWindow及其子类
		if (pMainWindow == NULL)
		{
			return NULL;
		}
		pMainWindow->setCentralWidget(pwidget);
	}
	return (void *)pwidget; //最后返回一个void *指针
}

IBaseClass *__cdecl getInfoWidget(void *voidInfoWidget)
{
	//通过createInfoWidget返回的void *指针转换成为QWidget *，
	//看似这一步有点多余，但这是比较稳的操作
	//这里注意：指针转换之前怎么转换来的，需要一步步再转换回去，例如
	//要从void *-->QWidget *-->MyTest *-->IBaseClass*
	//不能直接从void *-->IBaseClass*，这样会出错
	QWidget* pwidget = (QWidget*)voidInfoWidget;
	MyTest*pInfoWidget = dynamic_cast<MyTest*>(pwidget);
	Q_ASSERT(pInfoWidget); //对pInfoWidget断言，判断pInfoWidget是否属于MyTest及其子类
	if(pInfoWidget == NULL)
	{
		return NULL;
	}
	IBaseClass* pIBaseClass =  dynamic_cast<IBaseClass*>(pInfoWidget); //将MyTest*转换成IBaseClass*，供外部调用
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
