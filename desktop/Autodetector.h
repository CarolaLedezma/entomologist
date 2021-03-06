/*
 *  Copyright (c) 2011 Novell, Inc.
 *  All Rights Reserved.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of version 2 of the GNU General Public License as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, contact Novell, Inc.
 *
 *  To contact Novell about this file by physical or electronic mail,
 *  you may find current contact information at www.novell.com
 *
 *  Author: Matt Barringer <mbarringer@suse.de>
 *
 */

#ifndef AUTODETECTOR_H
#define AUTODETECTOR_H

#include <QObject>
#include <QMap>
#include <QUrl>
#include <QStringList>

class Backend;
class NovellBugzilla;
class Bugzilla;
class Launchpad;
class Mantis;
class Trac;

class Autodetector : public QObject
{
    Q_OBJECT

public:
    enum detectionState
    {
        NOVELL_CHECK = 0,
        BUGZILLA_CHECK,
        LAUNCHPAD_CHECK,
        MANTIS_CHECK,
        TRAC_CHECK
    };

    Autodetector();
    void detect(QMap<QString, QString> data);

public slots:
    void versionChecked(QString version);
    void handleError(QString msg);

signals:
    void finishedDetecting(QMap<QString, QString> data);
    void backendError(QString msg);

private:
    void checkVersion(Backend *b);
    QMap<QString, QString> mData;
    QUrl mUrl;
    detectionState mDetectionState;
    NovellBugzilla *novellBugzilla;
    Bugzilla *genericBugzilla;
    Launchpad *launchpad;
    Mantis *mantis;
    Trac *trac;
};

#endif // AUTODETECTOR_H
