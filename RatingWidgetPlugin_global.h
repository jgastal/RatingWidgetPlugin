/*
 *  Copyright (C) 2009 Jonas Mauricio Gastal.
 *  Contact: Jonas Mauricio Gastal (jgastal@gmail.com)
 *
 *  This file is part of RatingWidgetPlugin.
 *
 *  RatingWidgetPlugin is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License.
 *
 *  Parabola Biblioteca is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with RatingWidgetPlugin.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RATINGWIDGETPLUGIN_GLOBAL_H
#define RATINGWIDGETPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RATINGWIDGETPLUGIN_LIBRARY)
#  define RATINGWIDGETPLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RATINGWIDGETPLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RATINGWIDGETPLUGIN_GLOBAL_H
