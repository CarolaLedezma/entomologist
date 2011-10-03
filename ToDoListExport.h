#ifndef TODOLISTEXPORT_H
#define TODOLISTEXPORT_H

#include <QDialog>
#include <QMap>
#include <QStack>
#include "ToDoListView.h"

namespace Ui {
    class ToDoListExport;
}

class ToDoListExport : public QDialog
{
    Q_OBJECT

public:
    explicit ToDoListExport(QWidget *parent = 0);
    ~ToDoListExport();
    QStack<ToDoListView::serviceData_t> getData();

private:
    Ui::ToDoListExport *ui;
    void populateServices();
    void populateRecipients();
};

#endif // TODOLISTEXPORT_H
