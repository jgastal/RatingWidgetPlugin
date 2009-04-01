#include <QtGui/QWidget>
#include <QtGui/QIcon>
#include <QtGui/QToolButton>
#include <QtGui/QHBoxLayout>

#include "RatingWidget.h"

RatingWidget::RatingWidget(QWidget *parent, int count) : QWidget(parent)
{
	max = count;
	QHBoxLayout *layout = new QHBoxLayout(this);
	emptyIcon = new QIcon(":/icons/emptystar.gif");
	fullIcon = new QIcon(":/icons/fullstar.gif");
	starButton = new QToolButton[max];

	for(int i = 0; i < max; i++)
	{
		starButton[i].setParent(this);
		starButton[i].setCheckable(true);
		starButton[i].setIcon(*emptyIcon);
		starButton[i].resize(32, 32);
		connect(&(starButton[i]), SIGNAL(toggled(bool)), this, SLOT(setRating()));

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
