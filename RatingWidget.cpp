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
#include <QtGui/QWidget>
#include <QtGui/QIcon>
#include <QtGui/QToolButton>
#include <QtGui/QHBoxLayout>

#include "RatingWidget.h"

RatingWidget::RatingWidget(QWidget *parent, int count) : QWidget(parent)
{
	max = count;
	layout = new QHBoxLayout(this);
	layout->setMargin(0);
	emptyIcon = new QIcon(":/icons/emptystar.gif");
	fullIcon = new QIcon(":/icons/fullstar.gif");
	starButton = new QToolButton[max];

	for(int i = 0; i < max; i++)
	{
		initButton(&(starButton[i]));
		layout->addWidget(&(starButton[i]));
	}

	//size is 32x32, 32 width + 4 between each button sums up to 35 * buttons
	resize(35 * max, 32);
}

RatingWidget::~RatingWidget()
{
	delete emptyIcon;
	delete fullIcon;
	delete[] starButton;
}

int RatingWidget::getMax() const
{
	return max;
}

void RatingWidget::setMax(int count)
{
	max = count;
	delete[] starButton;
	starButton = new QToolButton[max];

	for(int i = 0; i < max; i++)
	{
		initButton(&(starButton[i]));
		layout->addWidget(&(starButton[i]));
	}

	//size is 32x32, 32 width + 4 between each button sums up to 35 * buttons
	resize(35 * max, 32);
}

int RatingWidget::getRating() const
{
	return rating;
}

void RatingWidget::setRating(int r)
{
	rating = r;
	for(int i = 0; i < max; i++)
	{
		starButton[i].blockSignals(true);
		starButton[i].setChecked(i < r);
		starButton[i].setIcon(i < r?*fullIcon:*emptyIcon);
		starButton[i].blockSignals(false);
	}
}

void RatingWidget::initButton(QToolButton *bt)
{
	bt->setParent(this);
	bt->setCheckable(true);
	bt->setIcon(*emptyIcon);
	bt->resize(32, 32);
	connect(bt, SIGNAL(toggled(bool)), this, SLOT(setRating()));
}

void RatingWidget::setRating()
{
	QToolButton *obj = (QToolButton*)sender();
	int cur;
	for(cur = 0; cur < max; cur++)
		if(obj == &(starButton[cur]))
			break;
	rating = ++cur;
	setRating(rating);
}
