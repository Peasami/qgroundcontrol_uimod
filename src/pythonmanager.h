#ifndef PYTHONMANAGER_H
#define PYTHONMANAGER_H

#include <QObject>

class PythonManager : public QObject {
    Q_OBJECT
   public:
    explicit PythonManager(QObject *parent = nullptr);

    Q_INVOKABLE void callPythonScript(int index = 0);

    static void registerQmlTypes();

   signals:
};

#endif  // PYTHONMANAGER_H
