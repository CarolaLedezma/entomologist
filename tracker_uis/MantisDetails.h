#ifndef MANTISDETAILS_H
#define MANTISDETAILS_H

#include <QWidget>
#include "BackendDetails.h"

namespace Ui {
    class MantisDetails;
}

class MantisDetails : public BackendDetails
{
    Q_OBJECT

public:
    explicit MantisDetails(QWidget *parent = 0);
    ~MantisDetails();
    void setProject(const QString &project);
    void setCategory(const QString &category);
    void setVersion(const QString &version);

    void setSeverities(const QString &selected, QStringList severities);
    void setPriorities(const QString &selected, QStringList priorities);
    void setStatuses(const QString &selected, QStringList statuses);
    void setResolutions(const QString &selected, QStringList resolutions);
    void setReproducibility(const QString &selected, QStringList reproducibilities);
    QMap<QString, QString> fieldDetails();

private:
    Ui::MantisDetails *ui;
    // These are used to see if a combo box is set to a new value
    QString mSeverity, mPriority, mReproducibility, mStatus, mResolution;
};

#endif // MANTISDETAILS_H
