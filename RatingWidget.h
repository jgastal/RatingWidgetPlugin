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
#ifndef RATINGWIDGET_H
#define RATINGWIDGET_H

#include <QWidget>

class QToolButton;
class QIcon;
class QHBoxLayout;

class RatingWidget : public QWidget
{
	Q_OBJECT

	Q_PROPERTY(int max READ getMax WRITE setMax DESIGNABLE true)

	public:
		RatingWidget(QWidget *parent = 0, int count = 5);
		virtual ~RatingWidget();
		int getMax() const;
		void setMax(int count);
		int getRating() const;

	public slots:
		void setRating(int r);

	private:
		void initButton(QToolButton *bt);
		QToolButton *starButton;
		QIcon *emptyIcon, *fullIcon;
		QHBoxLayout *layout;
		int max;
		int rating;

	private slots:
		void setRating();
};

#endif // RATINGWIDGET_H
