#include "pythonmanager.h"
#include <QtQml/qqml.h>

PythonManager::PythonManager(QObject *parent) : QObject{parent} {}

void PythonManager::callPythonScript(int index)
{
    qDebug() << "Calling system script";
    system("dir");
}

void PythonManager::registerQmlTypes()
{
    qDebug() << "PythonManager qml registered";
    (void) qmlRegisterType<PythonManager>("PythonManager", 1, 0, "PythonManager");
}
