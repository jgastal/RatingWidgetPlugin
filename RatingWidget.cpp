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

	resize(8 + 32 * max, 32 + 8);
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

	resize(8 + 32 * max, 32 + 8);
}

int RatingWidget::getValue() const
{
	//max is number of buttons, but array indexes start at 0
	for(int cur = max - 1; cur >= 0; cur--)
		if(starButton[cur].isDown())
			return cur++;
	return 0;
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
	cur++;
	for(int i = 0; i < max; i++)
	{
		starButton[i].blockSignals(true);
		starButton[i].setChecked(i < cur);
		starButton[i].setIcon(i < cur?*fullIcon:*emptyIcon);
		starButton[i].blockSignals(false);
	}
}
