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
