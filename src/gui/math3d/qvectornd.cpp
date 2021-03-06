/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Copyright (C) 2020 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Giuseppe D'Angelo <giuseppe.dangelo@kdab.com>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qvectornd.h"
#include <QtCore/qdatastream.h>
#include <QtCore/qdebug.h>
#include <QtCore/qvariant.h>
#include <QtGui/qmatrix4x4.h>

QT_BEGIN_NAMESPACE

#ifndef QT_NO_VECTOR2D

/*!
    \class QVector2D
    \brief The QVector2D class represents a vector or vertex in 2D space.
    \since 4.6
    \ingroup painting
    \ingroup painting-3D
    \inmodule QtGui

    The QVector2D class can also be used to represent vertices in 2D space.
    We therefore do not need to provide a separate vertex class.

    \sa QVector3D, QVector4D, QQuaternion
*/

/*!
    \fn QVector2D::QVector2D()

    Constructs a null vector, i.e. with coordinates (0, 0).
*/

/*!
    \fn QVector2D::QVector2D(Qt::Initialization)
    \since 5.5
    \internal

    Constructs a vector without initializing the contents.
*/

/*!
    \fn QVector2D::QVector2D(float xpos, float ypos)

    Constructs a vector with coordinates (\a xpos, \a ypos).
*/

/*!
    \fn QVector2D::QVector2D(QPoint point)

    Constructs a vector with x and y coordinates from a 2D \a point.
*/

/*!
    \fn QVector2D::QVector2D(QPointF point)

    Constructs a vector with x and y coordinates from a 2D \a point.
*/

#ifndef QT_NO_VECTOR3D

/*!
    \fn QVector2D::QVector2D(QVector3D vector)

    Constructs a vector with x and y coordinates from a 3D \a vector.
    The z coordinate of \a vector is dropped.

    \sa toVector3D()
*/

#endif

#ifndef QT_NO_VECTOR4D

/*!
    \fn QVector2D::QVector2D(QVector4D vector)

    Constructs a vector with x and y coordinates from a 3D \a vector.
    The z and w coordinates of \a vector are dropped.

    \sa toVector4D()
*/

#endif

/*!
    \fn bool QVector2D::isNull() const

    Returns \c true if the x and y coordinates are set to 0.0,
    otherwise returns \c false.
*/

/*!
    \fn float QVector2D::x() const

    Returns the x coordinate of this point.

    \sa setX(), y()
*/

/*!
    \fn float QVector2D::y() const

    Returns the y coordinate of this point.

    \sa setY(), x()
*/

/*!
    \fn void QVector2D::setX(float x)

    Sets the x coordinate of this point to the given \a x coordinate.

    \sa x(), setY()
*/

/*!
    \fn void QVector2D::setY(float y)

    Sets the y coordinate of this point to the given \a y coordinate.

    \sa y(), setX()
*/

/*! \fn float &QVector2D::operator[](int i)
    \since 5.2

    Returns the component of the vector at index position \a i
    as a modifiable reference.

    \a i must be a valid index position in the vector (i.e., 0 <= \a i
    < 2).
*/

/*! \fn float QVector2D::operator[](int i) const
    \since 5.2

    Returns the component of the vector at index position \a i.

    \a i must be a valid index position in the vector (i.e., 0 <= \a i
    < 2).
*/

/*!
    \fn float QVector2D::length() const

    Returns the length of the vector from the origin.

    \sa lengthSquared(), normalized()
*/

/*!
    \fn float QVector2D::lengthSquared() const

    Returns the squared length of the vector from the origin.
    This is equivalent to the dot product of the vector with itself.

    \sa length(), dotProduct()
*/

/*!
    \fn QVector2D QVector2D::normalized() const

    Returns the normalized unit vector form of this vector.

    If this vector is null, then a null vector is returned. If the length
    of the vector is very close to 1, then the vector will be returned as-is.
    Otherwise the normalized form of the vector of length 1 will be returned.

    \sa length(), normalize()
*/

/*!
    \fn void QVector2D::normalize()

    Normalizes the currect vector in place. Nothing happens if this
    vector is a null vector or the length of the vector is very close to 1.

    \sa length(), normalized()
*/

/*!
    \fn float QVector2D::distanceToPoint(QVector2D point) const
    \since 5.1

    Returns the distance from this vertex to a point defined by
    the vertex \a point.

    \sa distanceToLine()
*/

/*!
    \fn float QVector2D::distanceToLine(QVector2D point, QVector2D direction) const
    \since 5.1

    Returns the distance that this vertex is from a line defined
    by \a point and the unit vector \a direction.

    If \a direction is a null vector, then it does not define a line.
    In that case, the distance from \a point to this vertex is returned.

    \sa distanceToPoint()
*/

/*!
    \fn QVector2D &QVector2D::operator+=(QVector2D vector)

    Adds the given \a vector to this vector and returns a reference to
    this vector.

    \sa operator-=()
*/

/*!
    \fn QVector2D &QVector2D::operator-=(QVector2D vector)

    Subtracts the given \a vector from this vector and returns a reference to
    this vector.

    \sa operator+=()
*/

/*!
    \fn QVector2D &QVector2D::operator*=(float factor)

    Multiplies this vector's coordinates by the given \a factor, and
    returns a reference to this vector.

    \sa operator/=()
*/

/*!
    \fn QVector2D &QVector2D::operator*=(QVector2D vector)

    Multiplies the components of this vector by the corresponding
    components in \a vector.
*/

/*!
    \fn QVector2D &QVector2D::operator/=(float divisor)

    Divides this vector's coordinates by the given \a divisor, and
    returns a reference to this vector.

    \sa operator*=()
*/

/*!
    \fn QVector2D &QVector2D::operator/=(QVector2D vector)
    \since 5.5

    Divides the components of this vector by the corresponding
    components in \a vector.

    \sa operator*=()
*/

/*!
    \fn float QVector2D::dotProduct(QVector2D v1, QVector2D v2)

    Returns the dot product of \a v1 and \a v2.
*/

/*!
    \fn bool QVector2D::operator==(QVector2D v1, QVector2D v2)

    Returns \c true if \a v1 is equal to \a v2; otherwise returns \c false.
    This operator uses an exact floating-point comparison.
*/

/*!
    \fn bool QVector2D::operator!=(QVector2D v1, QVector2D v2)

    Returns \c true if \a v1 is not equal to \a v2; otherwise returns \c false.
    This operator uses an exact floating-point comparison.
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator+(QVector2D v1, QVector2D v2)

    Returns a QVector2D object that is the sum of the given vectors, \a v1
    and \a v2; each component is added separately.

    \sa QVector2D::operator+=()
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator-(QVector2D v1, QVector2D v2)

    Returns a QVector2D object that is formed by subtracting \a v2 from \a v1;
    each component is subtracted separately.

    \sa QVector2D::operator-=()
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator*(float factor, QVector2D vector)

    Returns a copy of the given \a vector,  multiplied by the given \a factor.

    \sa QVector2D::operator*=()
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator*(QVector2D vector, float factor)

    Returns a copy of the given \a vector,  multiplied by the given \a factor.

    \sa QVector2D::operator*=()
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator*(QVector2D v1, QVector2D v2)

    Multiplies the components of \a v1 by the corresponding
    components in \a v2.
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator-(QVector2D vector)
    \overload

    Returns a QVector2D object that is formed by changing the sign of
    the components of the given \a vector.

    Equivalent to \c {QVector2D(0,0) - vector}.
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator/(QVector2D vector, float divisor)

    Returns the QVector2D object formed by dividing all three components of
    the given \a vector by the given \a divisor.

    \sa QVector2D::operator/=()
*/

/*! //! friend
    \fn const QVector2D QVector2D::operator/(QVector2D vector, QVector2D divisor)
    \since 5.5

    Returns the QVector2D object formed by dividing components of the given
    \a vector by a respective components of the given \a divisor.

    \sa QVector2D::operator/=()
*/

/*! //! friend
    \fn bool QVector2D::qFuzzyCompare(QVector2D v1, QVector2D v2)

    Returns \c true if \a v1 and \a v2 are equal, allowing for a small
    fuzziness factor for floating-point comparisons; false otherwise.
*/
bool qFuzzyCompare(QVector2D v1, QVector2D v2) noexcept
{
    return qFuzzyCompare(v1.v[0], v2.v[0]) && qFuzzyCompare(v1.v[1], v2.v[1]);
}

#ifndef QT_NO_VECTOR3D
/*!
    \fn QVector3D QVector2D::toVector3D() const

    Returns the 3D form of this 2D vector, with the z coordinate set to zero.

    \sa toVector4D(), toPoint()
*/
#endif

#ifndef QT_NO_VECTOR4D
/*!
    \fn QVector4D QVector2D::toVector4D() const

    Returns the 4D form of this 2D vector, with the z and w coordinates set to zero.

    \sa toVector3D(), toPoint()
*/
#endif

/*!
    \fn QPoint QVector2D::toPoint() const

    Returns the QPoint form of this 2D vector.

    \sa toPointF(), toVector3D()
*/

/*!
    \fn QPointF QVector2D::toPointF() const

    Returns the QPointF form of this 2D vector.

    \sa toPoint(), toVector3D()
*/

/*!
    Returns the 2D vector as a QVariant.
*/
QVector2D::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

#ifndef QT_NO_DEBUG_STREAM

QDebug operator<<(QDebug dbg, QVector2D vector)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QVector2D(" << vector.x() << ", " << vector.y() << ')';
    return dbg;
}

#endif

#ifndef QT_NO_DATASTREAM

/*!
    \fn QDataStream &operator<<(QDataStream &stream, QVector2D vector)
    \relates QVector2D

    Writes the given \a vector to the given \a stream and returns a
    reference to the stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator<<(QDataStream &stream, QVector2D vector)
{
    stream << vector.x() << vector.y();
    return stream;
}

/*!
    \fn QDataStream &operator>>(QDataStream &stream, QVector2D &vector)
    \relates QVector2D

    Reads a 2D vector from the given \a stream into the given \a vector
    and returns a reference to the stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator>>(QDataStream &stream, QVector2D &vector)
{
    float x, y;
    stream >> x;
    stream >> y;
    vector.setX(x);
    vector.setY(y);
    return stream;
}

#endif // QT_NO_DATASTREAM

#endif // QT_NO_VECTOR2D



#ifndef QT_NO_VECTOR3D

/*!
    \class QVector3D
    \brief The QVector3D class represents a vector or vertex in 3D space.
    \since 4.6
    \ingroup painting-3D
    \inmodule QtGui

    Vectors are one of the main building blocks of 3D representation and
    drawing. They consist of three coordinates, traditionally called
    x, y, and z.

    The QVector3D class can also be used to represent vertices in 3D space.
    We therefore do not need to provide a separate vertex class.

    \sa QVector2D, QVector4D, QQuaternion
*/

/*!
    \fn QVector3D::QVector3D()

    Constructs a null vector, i.e. with coordinates (0, 0, 0).
*/

/*!
    \fn QVector3D::QVector3D(Qt::Initialization)
    \since 5.5
    \internal

    Constructs a vector without initializing the contents.
*/

/*!
    \fn QVector3D::QVector3D(float xpos, float ypos, float zpos)

    Constructs a vector with coordinates (\a xpos, \a ypos, \a zpos).
*/

/*!
    \fn QVector3D::QVector3D(QPoint point)

    Constructs a vector with x and y coordinates from a 2D \a point, and a
    z coordinate of 0.
*/

/*!
    \fn QVector3D::QVector3D(QPointF point)

    Constructs a vector with x and y coordinates from a 2D \a point, and a
    z coordinate of 0.
*/

#ifndef QT_NO_VECTOR2D

/*!
    \fn QVector3D::QVector3D(QVector2D vector)

    Constructs a 3D vector from the specified 2D \a vector. The z
    coordinate is set to zero.

    \sa toVector2D()
*/

/*!
    \fn QVector3D::QVector3D(QVector2D vector, float zpos)

    Constructs a 3D vector from the specified 2D \a vector. The z
    coordinate is set to \a zpos.

    \sa toVector2D()
*/
#endif

#ifndef QT_NO_VECTOR4D

/*!
    \fn QVector3D::QVector3D(QVector4D vector)

    Constructs a 3D vector from the specified 4D \a vector. The w
    coordinate is dropped.

    \sa toVector4D()
*/

#endif

/*!
    \fn bool QVector3D::isNull() const

    Returns \c true if the x, y, and z coordinates are set to 0.0,
    otherwise returns \c false.
*/

/*!
    \fn float QVector3D::x() const

    Returns the x coordinate of this point.

    \sa setX(), y(), z()
*/

/*!
    \fn float QVector3D::y() const

    Returns the y coordinate of this point.

    \sa setY(), x(), z()
*/

/*!
    \fn float QVector3D::z() const

    Returns the z coordinate of this point.

    \sa setZ(), x(), y()
*/

/*!
    \fn void QVector3D::setX(float x)

    Sets the x coordinate of this point to the given \a x coordinate.

    \sa x(), setY(), setZ()
*/

/*!
    \fn void QVector3D::setY(float y)

    Sets the y coordinate of this point to the given \a y coordinate.

    \sa y(), setX(), setZ()
*/

/*!
    \fn void QVector3D::setZ(float z)

    Sets the z coordinate of this point to the given \a z coordinate.

    \sa z(), setX(), setY()
*/

/*! \fn float &QVector3D::operator[](int i)
    \since 5.2

    Returns the component of the vector at index position \a i
    as a modifiable reference.

    \a i must be a valid index position in the vector (i.e., 0 <= \a i
    < 3).
*/

/*! \fn float QVector3D::operator[](int i) const
    \since 5.2

    Returns the component of the vector at index position \a i.

    \a i must be a valid index position in the vector (i.e., 0 <= \a i
    < 3).
*/

/*!
    \fn QVector3D QVector3D::normalized() const

    Returns the normalized unit vector form of this vector.

    If this vector is null, then a null vector is returned. If the length
    of the vector is very close to 1, then the vector will be returned as-is.
    Otherwise the normalized form of the vector of length 1 will be returned.

    \sa length(), normalize()
*/

/*!
    \fn void QVector3D::normalize()

    Normalizes the currect vector in place. Nothing happens if this
    vector is a null vector or the length of the vector is very close to 1.

    \sa length(), normalized()
*/

/*!
    \fn QVector3D &QVector3D::operator+=(QVector3D vector)

    Adds the given \a vector to this vector and returns a reference to
    this vector.

    \sa operator-=()
*/

/*!
    \fn QVector3D &QVector3D::operator-=(QVector3D vector)

    Subtracts the given \a vector from this vector and returns a reference to
    this vector.

    \sa operator+=()
*/

/*!
    \fn QVector3D &QVector3D::operator*=(float factor)

    Multiplies this vector's coordinates by the given \a factor, and
    returns a reference to this vector.

    \sa operator/=()
*/

/*!
    \fn QVector3D &QVector3D::operator*=(QVector3D vector)
    \overload

    Multiplies the components of this vector by the corresponding
    components in \a vector.

    Note: this is not the same as the crossProduct() of this
    vector and \a vector.

    \sa crossProduct()
*/

/*!
    \fn QVector3D &QVector3D::operator/=(float divisor)

    Divides this vector's coordinates by the given \a divisor, and
    returns a reference to this vector.

    \sa operator*=()
*/

/*!
    \fn QVector3D &QVector3D::operator/=(QVector3D vector)
    \since 5.5

    Divides the components of this vector by the corresponding
    components in \a vector.

    \sa operator*=()
*/

/*!
    \fn float QVector3D::dotProduct(QVector3D v1, QVector3D v2)

    Returns the dot product of \a v1 and \a v2.
*/

/*!
    \fn QVector3D QVector3D::crossProduct(QVector3D v1, QVector3D v2)

    Returns the cross-product of vectors \a v1 and \a v2, which corresponds
    to the normal vector of a plane defined by \a v1 and \a v2.

    \sa normal()
*/

/*!
    \fn QVector3D QVector3D::normal(QVector3D v1, QVector3D v2)

    Returns the normal vector of a plane defined by vectors \a v1 and \a v2,
    normalized to be a unit vector.

    Use crossProduct() to compute the cross-product of \a v1 and \a v2 if you
    do not need the result to be normalized to a unit vector.

    \sa crossProduct(), distanceToPlane()
*/

/*!
    \fn QVector3D QVector3D::normal(QVector3D v1, QVector3D v2, QVector3D v3)

    Returns the normal vector of a plane defined by vectors
    \a v2 - \a v1 and \a v3 - \a v1, normalized to be a unit vector.

    Use crossProduct() to compute the cross-product of \a v2 - \a v1 and
    \a v3 - \a v1 if you do not need the result to be normalized to a
    unit vector.

    \sa crossProduct(), distanceToPlane()
*/

/*!
    \since 5.5

    Returns the window coordinates of this vector initially in object/model
    coordinates using the model view matrix \a modelView, the projection matrix
    \a projection and the viewport dimensions \a viewport.

    When transforming from clip to normalized space, a division by the w
    component on the vector components takes place. To prevent dividing by 0 if
    w equals to 0, it is set to 1.

    \note the returned y coordinates are in OpenGL orientation. OpenGL expects
    the bottom to be 0 whereas for Qt top is 0.

    \sa unproject()
 */
QVector3D QVector3D::project(const QMatrix4x4 &modelView, const QMatrix4x4 &projection, const QRect &viewport) const
{
    QVector4D tmp(*this, 1.0f);
    tmp = projection * modelView * tmp;
    if (qFuzzyIsNull(tmp.w()))
        tmp.setW(1.0f);
    tmp /= tmp.w();

    tmp = tmp * 0.5f + QVector4D(0.5f, 0.5f, 0.5f, 0.5f);
    tmp.setX(tmp.x() * viewport.width() + viewport.x());
    tmp.setY(tmp.y() * viewport.height() + viewport.y());

    return tmp.toVector3D();
}

/*!
    \since 5.5

    Returns the object/model coordinates of this vector initially in window
    coordinates using the model view matrix \a modelView, the projection matrix
    \a projection and the viewport dimensions \a viewport.

    When transforming from clip to normalized space, a division by the w
    component of the vector components takes place. To prevent dividing by 0 if
    w equals to 0, it is set to 1.

    \note y coordinates in \a viewport should use OpenGL orientation. OpenGL
    expects the bottom to be 0 whereas for Qt top is 0.

    \sa project()
 */
QVector3D QVector3D::unproject(const QMatrix4x4 &modelView, const QMatrix4x4 &projection, const QRect &viewport) const
{
    QMatrix4x4 inverse = QMatrix4x4( projection * modelView ).inverted();

    QVector4D tmp(*this, 1.0f);
    tmp.setX((tmp.x() - float(viewport.x())) / float(viewport.width()));
    tmp.setY((tmp.y() - float(viewport.y())) / float(viewport.height()));
    tmp = tmp * 2.0f - QVector4D(1.0f, 1.0f, 1.0f, 1.0f);

    QVector4D obj = inverse * tmp;
    if (qFuzzyIsNull(obj.w()))
        obj.setW(1.0f);
    obj /= obj.w();
    return obj.toVector3D();
}

/*!
    \fn float QVector3D::distanceToPoint(QVector3D point) const

    \since 5.1

    Returns the distance from this vertex to a point defined by
    the vertex \a point.

    \sa distanceToPlane(), distanceToLine()
*/

/*!
    \fn float QVector3D::distanceToPlane(QVector3D plane, QVector3D normal) const

    Returns the distance from this vertex to a plane defined by
    the vertex \a plane and a \a normal unit vector. The \a normal
    parameter is assumed to have been normalized to a unit vector.

    The return value will be negative if the vertex is below the plane,
    or zero if it is on the plane.

    \sa normal(), distanceToLine()
*/

/*!
    \fn float QVector3D::distanceToPlane(QVector3D plane1, QVector3D plane2, QVector3D plane3) const

    Returns the distance from this vertex to a plane defined by
    the vertices \a plane1, \a plane2 and \a plane3.

    The return value will be negative if the vertex is below the plane,
    or zero if it is on the plane.

    The two vectors that define the plane are \a plane2 - \a plane1
    and \a plane3 - \a plane1.

    \sa normal(), distanceToLine()
*/

/*!
    \fn float QVector3D::distanceToLine(QVector3D point, QVector3D direction) const

    Returns the distance that this vertex is from a line defined
    by \a point and the unit vector \a direction.

    If \a direction is a null vector, then it does not define a line.
    In that case, the distance from \a point to this vertex is returned.

    \sa distanceToPlane()
*/

/*!
    \fn bool QVector3D::operator==(QVector3D v1, QVector3D v2)

    Returns \c true if \a v1 is equal to \a v2; otherwise returns \c false.
    This operator uses an exact floating-point comparison.
*/

/*!
    \fn bool QVector3D::operator!=(QVector3D v1, QVector3D v2)

    Returns \c true if \a v1 is not equal to \a v2; otherwise returns \c false.
    This operator uses an exact floating-point comparison.
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator+(QVector3D v1, QVector3D v2)

    Returns a QVector3D object that is the sum of the given vectors, \a v1
    and \a v2; each component is added separately.

    \sa QVector3D::operator+=()
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator-(QVector3D v1, QVector3D v2)

    Returns a QVector3D object that is formed by subtracting \a v2 from \a v1;
    each component is subtracted separately.

    \sa QVector3D::operator-=()
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator*(float factor, QVector3D vector)

    Returns a copy of the given \a vector,  multiplied by the given \a factor.

    \sa QVector3D::operator*=()
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator*(QVector3D vector, float factor)

    Returns a copy of the given \a vector,  multiplied by the given \a factor.

    \sa QVector3D::operator*=()
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator*(QVector3D v1, QVector3D v2)

    Multiplies the components of \a v1 by the corresponding components in \a v2.

    \note This is not the same as the crossProduct() of \a v1 and \a v2.

    \sa QVector3D::crossProduct()
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator-(QVector3D vector)
    \overload

    Returns a QVector3D object that is formed by changing the sign of
    all three components of the given \a vector.

    Equivalent to \c {QVector3D(0,0,0) - vector}.
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator/(QVector3D vector, float divisor)

    Returns the QVector3D object formed by dividing all three components of
    the given \a vector by the given \a divisor.

    \sa QVector3D::operator/=()
*/

/*! //! friend
    \fn const QVector3D QVector3D::operator/(QVector3D vector, QVector3D divisor)
    \since 5.5

    Returns the QVector3D object formed by dividing components of the given
    \a vector by a respective components of the given \a divisor.

    \sa QVector3D::operator/=()
*/

/*! //! friend
    \fn bool QVector3D::qFuzzyCompare(QVector3D v1, QVector3D v2)

    Returns \c true if \a v1 and \a v2 are equal, allowing for a small
    fuzziness factor for floating-point comparisons; false otherwise.
*/
bool qFuzzyCompare(QVector3D v1, QVector3D v2) noexcept
{
    return qFuzzyCompare(v1.v[0], v2.v[0]) &&
            qFuzzyCompare(v1.v[1], v2.v[1]) &&
            qFuzzyCompare(v1.v[2], v2.v[2]);
}

#ifndef QT_NO_VECTOR2D

/*!
    \fn QVector2D QVector3D::toVector2D() const

    Returns the 2D vector form of this 3D vector, dropping the z coordinate.

    \sa toVector4D(), toPoint()
*/

#endif

#ifndef QT_NO_VECTOR4D

/*!
    \fn QVector4D QVector3D::toVector4D() const

    Returns the 4D form of this 3D vector, with the w coordinate set to zero.

    \sa toVector2D(), toPoint()
*/

#endif

/*!
    \fn QPoint QVector3D::toPoint() const

    Returns the QPoint form of this 3D vector. The z coordinate
    is dropped.

    \sa toPointF(), toVector2D()
*/

/*!
    \fn QPointF QVector3D::toPointF() const

    Returns the QPointF form of this 3D vector. The z coordinate
    is dropped.

    \sa toPoint(), toVector2D()
*/

/*!
    Returns the 3D vector as a QVariant.
*/
QVector3D::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

/*!
    \fn float QVector3D::length() const

    Returns the length of the vector from the origin.

    \sa lengthSquared(), normalized()
*/

/*!
    \fn float QVector3D::lengthSquared() const

    Returns the squared length of the vector from the origin.
    This is equivalent to the dot product of the vector with itself.

    \sa length(), dotProduct()
*/

#ifndef QT_NO_DEBUG_STREAM

QDebug operator<<(QDebug dbg, QVector3D vector)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QVector3D("
        << vector.x() << ", " << vector.y() << ", " << vector.z() << ')';
    return dbg;
}

#endif

#ifndef QT_NO_DATASTREAM

/*!
    \fn QDataStream &operator<<(QDataStream &stream, QVector3D vector)
    \relates QVector3D

    Writes the given \a vector to the given \a stream and returns a
    reference to the stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator<<(QDataStream &stream, QVector3D vector)
{
    stream << vector.x() << vector.y() << vector.z();
    return stream;
}

/*!
    \fn QDataStream &operator>>(QDataStream &stream, QVector3D &vector)
    \relates QVector3D

    Reads a 3D vector from the given \a stream into the given \a vector
    and returns a reference to the stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator>>(QDataStream &stream, QVector3D &vector)
{
    float x, y, z;
    stream >> x;
    stream >> y;
    stream >> z;
    vector.setX(x);
    vector.setY(y);
    vector.setZ(z);
    return stream;
}

#endif // QT_NO_DATASTREAM

#endif // QT_NO_VECTOR3D



#ifndef QT_NO_VECTOR4D

/*!
    \class QVector4D
    \brief The QVector4D class represents a vector or vertex in 4D space.
    \since 4.6
    \ingroup painting-3D
    \inmodule QtGui

    The QVector4D class can also be used to represent vertices in 4D space.
    We therefore do not need to provide a separate vertex class.

    \sa QQuaternion, QVector2D, QVector3D
*/

/*!
    \fn QVector4D::QVector4D()

    Constructs a null vector, i.e. with coordinates (0, 0, 0, 0).
*/

/*!
    \fn QVector4D::QVector4D(Qt::Initialization)
    \since 5.5
    \internal

    Constructs a vector without initializing the contents.
*/

/*!
    \fn QVector4D::QVector4D(float xpos, float ypos, float zpos, float wpos)

    Constructs a vector with coordinates (\a xpos, \a ypos, \a zpos, \a wpos).
*/

/*!
    \fn QVector4D::QVector4D(QPoint point)

    Constructs a vector with x and y coordinates from a 2D \a point, and
    z and w coordinates of 0.
*/

/*!
    \fn QVector4D::QVector4D(QPointF point)

    Constructs a vector with x and y coordinates from a 2D \a point, and
    z and w coordinates of 0.
*/

#ifndef QT_NO_VECTOR2D

/*!
    \fn QVector4D::QVector4D(QVector2D vector)

    Constructs a 4D vector from the specified 2D \a vector. The z
    and w coordinates are set to zero.

    \sa toVector2D()
*/

/*!
    \fn QVector4D::QVector4D(QVector2D vector, float zpos, float wpos)

    Constructs a 4D vector from the specified 2D \a vector. The z
    and w coordinates are set to \a zpos and \a wpos respectively.

    \sa toVector2D()
*/

#endif

#ifndef QT_NO_VECTOR3D

/*!
    \fn QVector4D::QVector4D(QVector3D vector)

    Constructs a 4D vector from the specified 3D \a vector. The w
    coordinate is set to zero.

    \sa toVector3D()
*/

/*!
    \fn QVector4D::QVector4D(QVector3D vector, float wpos)

    Constructs a 4D vector from the specified 3D \a vector. The w
    coordinate is set to \a wpos.

    \sa toVector3D()
*/

#endif

/*!
    \fn bool QVector4D::isNull() const

    Returns \c true if the x, y, z, and w coordinates are set to 0.0,
    otherwise returns \c false.
*/

/*!
    \fn float QVector4D::x() const

    Returns the x coordinate of this point.

    \sa setX(), y(), z(), w()
*/

/*!
    \fn float QVector4D::y() const

    Returns the y coordinate of this point.

    \sa setY(), x(), z(), w()
*/

/*!
    \fn float QVector4D::z() const

    Returns the z coordinate of this point.

    \sa setZ(), x(), y(), w()
*/

/*!
    \fn float QVector4D::w() const

    Returns the w coordinate of this point.

    \sa setW(), x(), y(), z()
*/

/*!
    \fn void QVector4D::setX(float x)

    Sets the x coordinate of this point to the given \a x coordinate.

    \sa x(), setY(), setZ(), setW()
*/

/*!
    \fn void QVector4D::setY(float y)

    Sets the y coordinate of this point to the given \a y coordinate.

    \sa y(), setX(), setZ(), setW()
*/

/*!
    \fn void QVector4D::setZ(float z)

    Sets the z coordinate of this point to the given \a z coordinate.

    \sa z(), setX(), setY(), setW()
*/

/*!
    \fn void QVector4D::setW(float w)

    Sets the w coordinate of this point to the given \a w coordinate.

    \sa w(), setX(), setY(), setZ()
*/

/*! \fn float &QVector4D::operator[](int i)
    \since 5.2

    Returns the component of the vector at index position \a i
    as a modifiable reference.

    \a i must be a valid index position in the vector (i.e., 0 <= \a i
    < 4).
*/

/*! \fn float QVector4D::operator[](int i) const
    \since 5.2

    Returns the component of the vector at index position \a i.

    \a i must be a valid index position in the vector (i.e., 0 <= \a i
    < 4).
*/

/*!
    \fn float QVector4D::length() const

    Returns the length of the vector from the origin.

    \sa lengthSquared(), normalized()
*/

/*!
    \fn float QVector4D::lengthSquared() const

    Returns the squared length of the vector from the origin.
    This is equivalent to the dot product of the vector with itself.

    \sa length(), dotProduct()
*/

/*!
    \fn QVector4D QVector4D::normalized() const

    Returns the normalized unit vector form of this vector.

    If this vector is null, then a null vector is returned. If the length
    of the vector is very close to 1, then the vector will be returned as-is.
    Otherwise the normalized form of the vector of length 1 will be returned.

    \sa length(), normalize()
*/

/*!
    \fn void QVector4D::normalize()

    Normalizes the currect vector in place. Nothing happens if this
    vector is a null vector or the length of the vector is very close to 1.

    \sa length(), normalized()
*/


/*!
    \fn QVector4D &QVector4D::operator+=(QVector4D vector)

    Adds the given \a vector to this vector and returns a reference to
    this vector.

    \sa operator-=()
*/

/*!
    \fn QVector4D &QVector4D::operator-=(QVector4D vector)

    Subtracts the given \a vector from this vector and returns a reference to
    this vector.

    \sa operator+=()
*/

/*!
    \fn QVector4D &QVector4D::operator*=(float factor)

    Multiplies this vector's coordinates by the given \a factor, and
    returns a reference to this vector.

    \sa operator/=()
*/

/*!
    \fn QVector4D &QVector4D::operator*=(QVector4D vector)

    Multiplies the components of this vector by the corresponding
    components in \a vector.
*/

/*!
    \fn QVector4D &QVector4D::operator/=(float divisor)

    Divides this vector's coordinates by the given \a divisor, and
    returns a reference to this vector.

    \sa operator*=()
*/

/*!
    \fn QVector4D &QVector4D::operator/=(QVector4D vector)
    \since 5.5

    Divides the components of this vector by the corresponding
    components in \a vector.

    \sa operator*=()
*/

/*!
    \fn float QVector4D::dotProduct(QVector4D v1, QVector4D v2)

    Returns the dot product of \a v1 and \a v2.
*/

/*!
    \fn bool QVector4D::operator==(QVector4D v1, QVector4D v2)

    Returns \c true if \a v1 is equal to \a v2; otherwise returns \c false.
    This operator uses an exact floating-point comparison.
*/

/*!
    \fn bool QVector4D::operator!=(QVector4D v1, QVector4D v2)

    Returns \c true if \a v1 is not equal to \a v2; otherwise returns \c false.
    This operator uses an exact floating-point comparison.
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator+(QVector4D v1, QVector4D v2)

    Returns a QVector4D object that is the sum of the given vectors, \a v1
    and \a v2; each component is added separately.

    \sa QVector4D::operator+=()
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator-(QVector4D v1, QVector4D v2)

    Returns a QVector4D object that is formed by subtracting \a v2 from \a v1;
    each component is subtracted separately.

    \sa QVector4D::operator-=()
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator*(float factor, QVector4D vector)

    Returns a copy of the given \a vector,  multiplied by the given \a factor.

    \sa QVector4D::operator*=()
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator*(QVector4D vector, float factor)

    Returns a copy of the given \a vector,  multiplied by the given \a factor.

    \sa QVector4D::operator*=()
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator*(QVector4D v1, QVector4D v2)

    Returns the vector consisting of the multiplication of the
    components from \a v1 and \a v2.

    \sa QVector4D::operator*=()
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator-(QVector4D vector)
    \overload

    Returns a QVector4D object that is formed by changing the sign of
    all three components of the given \a vector.

    Equivalent to \c {QVector4D(0,0,0,0) - vector}.
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator/(QVector4D vector, float divisor)

    Returns the QVector4D object formed by dividing all four components of
    the given \a vector by the given \a divisor.

    \sa QVector4D::operator/=()
*/

/*! //! friend
    \fn const QVector4D QVector4D::operator/(QVector4D vector, QVector4D divisor)
    \since 5.5

    Returns the QVector4D object formed by dividing components of the given
    \a vector by a respective components of the given \a divisor.

    \sa QVector4D::operator/=()
*/

/*! //! friend
    \fn bool QVector4D::qFuzzyCompare(QVector4D v1, QVector4D v2)

    Returns \c true if \a v1 and \a v2 are equal, allowing for a small
    fuzziness factor for floating-point comparisons; false otherwise.
*/
bool qFuzzyCompare(QVector4D v1, QVector4D v2) noexcept
{
    return qFuzzyCompare(v1.v[0], v2.v[0]) &&
            qFuzzyCompare(v1.v[1], v2.v[1]) &&
            qFuzzyCompare(v1.v[2], v2.v[2]) &&
            qFuzzyCompare(v1.v[3], v2.v[3]);
}

#ifndef QT_NO_VECTOR2D

/*!
    \fn QVector2D QVector4D::toVector2D() const

    Returns the 2D vector form of this 4D vector, dropping the z and w coordinates.

    \sa toVector2DAffine(), toVector3D(), toPoint()
*/

/*!
    \fn QVector2D QVector4D::toVector2DAffine() const

    Returns the 2D vector form of this 4D vector, dividing the x and y
    coordinates by the w coordinate and dropping the z coordinate.
    Returns a null vector if w is zero.

    \sa toVector2D(), toVector3DAffine(), toPoint()
*/

#endif

#ifndef QT_NO_VECTOR3D

/*!
    \fn QVector3D QVector4D::toVector3D() const

    Returns the 3D vector form of this 4D vector, dropping the w coordinate.

    \sa toVector3DAffine(), toVector2D(), toPoint()
*/

/*!
    \fn QVector3D QVector4D::toVector3DAffine() const

    Returns the 3D vector form of this 4D vector, dividing the x, y, and
    z coordinates by the w coordinate. Returns a null vector if w is zero.

    \sa toVector3D(), toVector2DAffine(), toPoint()
*/

#endif

/*!
    \fn QPoint QVector4D::toPoint() const

    Returns the QPoint form of this 4D vector. The z and w coordinates
    are dropped.

    \sa toPointF(), toVector2D()
*/

/*!
    \fn QPointF QVector4D::toPointF() const

    Returns the QPointF form of this 4D vector. The z and w coordinates
    are dropped.

    \sa toPoint(), toVector2D()
*/

/*!
    Returns the 4D vector as a QVariant.
*/
QVector4D::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

#ifndef QT_NO_DEBUG_STREAM

QDebug operator<<(QDebug dbg, QVector4D vector)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QVector4D("
        << vector.x() << ", " << vector.y() << ", "
        << vector.z() << ", " << vector.w() << ')';
    return dbg;
}

#endif

#ifndef QT_NO_DATASTREAM

/*!
    \fn QDataStream &operator<<(QDataStream &stream, QVector4D vector)
    \relates QVector4D

    Writes the given \a vector to the given \a stream and returns a
    reference to the stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator<<(QDataStream &stream, QVector4D vector)
{
    stream << vector.x() << vector.y()
           << vector.z() << vector.w();
    return stream;
}

/*!
    \fn QDataStream &operator>>(QDataStream &stream, QVector4D &vector)
    \relates QVector4D

    Reads a 4D vector from the given \a stream into the given \a vector
    and returns a reference to the stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator>>(QDataStream &stream, QVector4D &vector)
{
    float x, y, z, w;
    stream >> x;
    stream >> y;
    stream >> z;
    stream >> w;
    vector.setX(x);
    vector.setY(y);
    vector.setZ(z);
    vector.setW(w);
    return stream;
}

#endif // QT_NO_DATASTREAM

#endif // QT_NO_VECTOR4D

QT_END_NAMESPACE
