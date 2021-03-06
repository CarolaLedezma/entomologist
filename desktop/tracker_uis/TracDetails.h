#ifndef TRACDETAILS_H
#define TRACDETAILS_H

#include <QWidget>
#include "BackendDetails.h"

namespace Ui {
    class TracDetails;
}

class TracDetails : public BackendDetails
{
    Q_OBJECT

public:
    explicit TracDetails(const QString &bugId, QWidget *parent = 0);
    ~TracDetails();
    void setSeverities(const QString &selected, QStringList severities);
    void setPriorities(const QString &selected, QStringList priorities);
    void setComponents(const QString &selected, QStringList components);
    void setVersions(const QString &selected, QStringList versions);
    void setStatuses(const QString &selected, QStringList statuses);
    void setResolutions(const QString &selected, QStringList resolutions);
    void setAssigneds(const QString &assigned, QStringList assignedVals);

    QMap<QString, QString> fieldDetails();

public slots:
    void statusIndexChanged(const QString &value);

private:
    Ui::TracDetails *ui;
    QString mBugId;
    // These are used to see if a combo box is set to a new value
    QString mSeverity, mPriority, mComponent, mVersion, mStatus, mResolution, mAssigned;
};

#endif // TRACDETAILS_H
