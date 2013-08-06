/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtQml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QV4JSONOBJECTS_H
#define QV4SJONOBJECTS_H

#include "qv4object_p.h"
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>

QT_BEGIN_NAMESPACE

namespace QV4 {

struct JsonObject : Object {
private:
    typedef QSet<QV4::Object *> V4ObjectSet;
public:
    JsonObject(ExecutionContext *context);

    static Value method_parse(SimpleCallContext *ctx);
    static Value method_stringify(SimpleCallContext *ctx);

    static QV4::Value fromJsonValue(ExecutionEngine *engine, const QJsonValue &value);
    static QV4::Value fromJsonObject(ExecutionEngine *engine, const QJsonObject &object);
    static QV4::Value fromJsonArray(ExecutionEngine *engine, const QJsonArray &array);

    static inline QJsonValue toJsonValue(const QV4::Value &value)
    { V4ObjectSet visitedObjects; return toJsonValue(value, visitedObjects); }
    static inline QJsonObject toJsonObject(QV4::Object *o)
    { V4ObjectSet visitedObjects; return toJsonObject(o, visitedObjects); }
    static inline QJsonArray toJsonArray(QV4::ArrayObject *a)
    { V4ObjectSet visitedObjects; return toJsonArray(a, visitedObjects); }

private:
    static QJsonValue toJsonValue(const QV4::Value &value, V4ObjectSet &visitedObjects);
    static QJsonObject toJsonObject(QV4::Object *o, V4ObjectSet &visitedObjects);
    static QJsonArray toJsonArray(QV4::ArrayObject *a, V4ObjectSet &visitedObjects);

};

}

QT_END_NAMESPACE

#endif

