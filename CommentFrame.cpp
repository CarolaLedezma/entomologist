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

#include "CommentFrame.h"
#include "ui_CommentFrame.h"

CommentFrame::CommentFrame(QWidget *parent, bool isNewComment)
    : QFrame(parent), ui(new Ui::CommentFrame)
{
    ui->setupUi(this);
    if (isNewComment)
    {
        ui->infoWidget->setStyleSheet("background: #E9112E");
        ui->commentLabel->hide();
        ui->replyButton->hide();
        connect(ui->saveButton, SIGNAL(clicked()),
                this, SLOT(saveButtonClicked()));
    }
    else
    {
        ui->infoWidget->setStyleSheet("background: #96B8CA");
        ui->saveButton->hide();
        ui->commentTextEdit->hide();
    }

    setStyleSheet("background: white");

}

CommentFrame::~CommentFrame()
{
    delete ui;
}

void
CommentFrame::setRedHeader()
{
    ui->infoWidget->setStyleSheet("background: #E9112E");
}

void
CommentFrame::toggleEdit()
{
    ui->commentLabel->setText(ui->commentTextEdit->toPlainText());
    ui->commentLabel->show();
    ui->commentTextEdit->hide();
    ui->replyButton->show();
    ui->saveButton->hide();
}

QString
CommentFrame::commentText()
{
    return ui->commentTextEdit->toPlainText();
}

QString
CommentFrame::timestamp()
{
    return ui->dateLabel->text();
}

void
CommentFrame::saveButtonClicked()
{
    emit saveCommentClicked();
}

void
CommentFrame::setName(const QString &name)
{
    ui->nameLabel->setText(name);
}

void
CommentFrame::setDate(const QString &date)
{
    ui->dateLabel->setText(date);
}

void
CommentFrame::setPrivate(bool checked)
{
    ui->privateCheckbox->setChecked(checked);
}

void
CommentFrame::setComment(const QString &comment)
{
    ui->commentLabel->setText(comment);
}

void CommentFrame::changeEvent(QEvent *e)
{
    QFrame::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
